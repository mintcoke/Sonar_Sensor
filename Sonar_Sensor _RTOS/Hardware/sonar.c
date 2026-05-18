#include "sonar.h"
#include "uart.h"

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


/**
 * @brief  解析声呐 Modbus 帧并进行侧装逻辑过滤
 * @param  buf: 接收缓冲区
 * @param  len: 缓冲区长度
 * @param  expect_addr: 期待的设备地址
 * @return 最终过滤后的距离(mm)。解析失败返回 -1，盲区返回 0，空旷返回 1600
 */
int32_t Sonar_Parse_Data(uint8_t *buf, uint16_t len, uint8_t expect_addr)
{
    if(buf == NULL || len < 7) return -1;

    /* 滑动窗口扫描 */
    for(uint16_t i = 0; i <= len - 7; i++) {
        
        /* 匹配帧头：地址 + 功能码(0x03) + 字节数(0x02) */
        if(buf[i] == expect_addr && buf[i+1] == 0x03 && buf[i+2] == 0x02) {
            
            uint16_t recv_crc = (buf[i+6] << 8) | buf[i+5];
            uint16_t calc_crc = Modbus_CRC16(&buf[i], 5);
            
            if(recv_crc == calc_crc) {
                /* 提取原始距离数据 */
                uint16_t distance = (buf[i+3] << 8) | buf[i+4];

                /* --- 侧装阵列核心过滤逻辑 --- */
                
                // 1. 过滤 80mm 盲区及传感器异常码
                if (distance < 80 || distance == 65533 || distance == 0) {
                    return 0; // 0 代表“无效/太近”，Python 收到后不画点
                }

                // 2. 过滤对岸池壁 (直径约1.6米)
                // 如果测得 1550mm 以上，基本是撞到了对面的 PVC 管或池壁
                if (distance > 1550) {
                    return 1600; // 1600 代表“前方空旷”，Python 收到后不画点
                }

                return (int32_t)distance; // 正常有效数据
            }
        }
    }
    return -1; // 彻底解析失败
}

