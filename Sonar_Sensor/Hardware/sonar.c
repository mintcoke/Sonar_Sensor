#include "sonar.h"
#include "uart.h"
#include <stddef.h>
#include <string.h>
#include "systick.h"

/* 5个传感器的Modbus地址 */
uint8_t sonar_addrs[SONAR_NUM] = {0x01, 0x02, 0x03, 0x04, 0x05};

/* 用于存储5个传感器的最新测量距离 (单位: mm) */
int32_t sonar_distances[SONAR_NUM] = {0};

/*!
    \brief      计算 Modbus CRC16 校验码
*/
uint16_t Modbus_CRC16(uint8_t *puchMsg, uint16_t usDataLen)
{
    uint16_t crc = 0xFFFF;
    for (uint16_t i = 0; i < usDataLen; i++) {
        crc ^= puchMsg[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 1) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

/*!
    \brief      轮询所有声纳传感器，并将结果存入 sonar_distances 数组
*/
void Sonar_Poll_All(void)
{
    for(uint8_t i = 0; i < SONAR_NUM; i++) {          

        usart_interrupt_disable(USART2, USART_INT_RBNE);
        rs485_rx_len = 0;
        memset(rs485_rx_buf, 0, sizeof(rs485_rx_buf));
        usart_interrupt_enable(USART2, USART_INT_RBNE);
        
        Sonar_Send_Read_Cmd(sonar_addrs[i]);
        
        delay_1ms(150);
        
        int32_t dist = Sonar_Parse_Data(rs485_rx_buf, rs485_rx_len, sonar_addrs[i]);
        
        sonar_distances[i] = dist; 
    }
}

/*!
    \brief      发送读取声纳距离的 Modbus 指令
*/
void Sonar_Send_Read_Cmd(uint8_t addr)
{
    uint8_t cmd[8];
    cmd[0] = addr;          // 设备地址
    cmd[1] = 0x03;          // 功能码 (读保持寄存器)
    cmd[2] = REG_PROCESS_VAL_H;          // 寄存器地址高位 (0x0100)
    cmd[3] = REG_PROCESS_VAL_L;          // 寄存器地址低位
    cmd[4] = 0x00;          // 读取数量高位
    cmd[5] = 0x01;          // 读取数量低位 (读1个寄存器)
    
    uint16_t crc = Modbus_CRC16(cmd, 6);
    cmd[6] = crc & 0xFF;    // CRC低位在前
    cmd[7] = crc >> 8;      // CRC高位在后
    
    RS485_SendData(cmd, 8);
}

/*!
    \brief      解析接收到的声纳数据并进行侧装逻辑过滤
    \retval     返回测量的距离值(mm)，解析失败返回 -1，盲区返回0，空旷返回2000
*/
int32_t Sonar_Parse_Data(uint8_t *buf, uint16_t len, uint8_t expect_addr)
{
    if(buf == NULL || len < 7) return -1;

    /* 使用滑动窗口扫描整个缓冲区，防范前面的垃圾乱码字节 */
    for(uint16_t i = 0; i <= len - 7; i++) {
        
        /* 匹配帧头：地址 + 功能码(0x03) + 字节数(0x02) */
        if(buf[i] == expect_addr && buf[i+1] == 0x03 && buf[i+2] == 0x02) {
            
            uint16_t recv_crc = (buf[i+6] << 8) | buf[i+5];
            uint16_t calc_crc = Modbus_CRC16(&buf[i], 5);
            
            if(recv_crc == calc_crc) {
                /* 提取原始距离数据 */
                uint16_t distance = (buf[i+3] << 8) | buf[i+4];
                // 1. 过滤传感器异常码 (65533)
                if (distance == error) {
                    return 0; // 0 代表“error”
                }

                // 2. 过滤对岸池壁 (直径约2米)
                if (distance > diameter) {
                    return 2000; // 2000 代表“前方空旷”
                }

                return (int32_t)distance; // 正常有效数据
            }
        }
    }
    return -1; // 彻底解析失败
}
