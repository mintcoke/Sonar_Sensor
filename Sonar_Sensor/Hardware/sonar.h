#ifndef __SONAR_H
#define __SONAR_H

#include "gd32f10x.h"

/* 寄存器地址*/
#define broadcast         		0xff	//广播地址
#define REG_PROCESS_VAL_H 		0x01  	// 处理值高位(滤波后)
#define REG_PROCESS_VAL_L 		0x00  	// 处理值低位
#define REG_REALTIME_VAL_H 		0x01 	// 实时值高位
#define REG_REALTIME_VAL_L 		0x01 	// 实时值低位
#define blind_spot 				80		// 传感器最小量程(mm)	
#define diameter            	2000	// 鱼池直径(mm)
#define error					65533	// 传感器数据错误

/* 定义总线上的声纳传感器数量 */
#define SONAR_NUM 5

extern uint8_t sonar_addrs[SONAR_NUM];
extern int32_t sonar_distances[SONAR_NUM];

/* 函数声明 */
uint16_t Modbus_CRC16(uint8_t *puchMsg, uint16_t usDataLen);
void Sonar_Send_Read_Cmd(uint8_t addr);
int32_t Sonar_Parse_Data(uint8_t *buf, uint16_t len, uint8_t expect_addr);

#endif /* __SONAR_H */
