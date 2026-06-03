/*
 * usart.h — 传感器串口 (USART6: PC6=TX, PC7=RX)
 *
 * GPIO 配置在 gpio.c, 中断在 stm32f4xx_it.c。
 * 使用方法:
 *   App_Hardware_Init() 中调用 Sensor_UART_Init(115200);
 *   App_Periodic_Task() 中用 Sensor_UART_Available()/Read() 轮询读取。
 */

#ifndef __USART_H
#define __USART_H

#include <stdint.h>

#define SENSOR_UART_BAUD   115200
#define SENSOR_RX_BUF_SIZE 256

void     Sensor_UART_Init(uint32_t baud);
void     Sensor_UART_Write(uint8_t* data, uint16_t len);
uint16_t Sensor_UART_Available(void);
uint8_t  Sensor_UART_Read(void);

#endif /* __USART_H */
