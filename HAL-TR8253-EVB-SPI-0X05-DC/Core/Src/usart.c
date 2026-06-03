/*
 * usart.c — 传感器串口驱动 (USART6, PC6=TX PC7=RX)
 *
 * 中断接收 + 环形缓冲, 业务层调用 Sensor_UART_Read() 即可。
 */

#include "usart.h"
#include "stm32f4xx_hal.h"

static UART_HandleTypeDef huart6;
static volatile uint8_t  s_RxBuf[SENSOR_RX_BUF_SIZE];
static volatile uint16_t s_RxHead = 0;
static volatile uint16_t s_RxTail = 0;
static uint8_t s_RxByte;

void Sensor_UART_Init(uint32_t baud)
{
    huart6.Instance          = USART6;
    huart6.Init.BaudRate     = baud;
    huart6.Init.WordLength   = UART_WORDLENGTH_8B;
    huart6.Init.StopBits     = UART_STOPBITS_1;
    huart6.Init.Parity       = UART_PARITY_NONE;
    huart6.Init.Mode         = UART_MODE_TX_RX;
    huart6.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    huart6.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&huart6);
    HAL_UART_Receive_IT(&huart6, &s_RxByte, 1);
}

void Sensor_UART_Write(uint8_t* data, uint16_t len)
{
    HAL_UART_Transmit(&huart6, data, len, 100);
}

uint16_t Sensor_UART_Available(void)
{
    return (s_RxHead - s_RxTail) & (SENSOR_RX_BUF_SIZE - 1);
}

uint8_t Sensor_UART_Read(void)
{
    if (Sensor_UART_Available() == 0) return 0;
    uint8_t ch = s_RxBuf[s_RxTail];
    s_RxTail = (s_RxTail + 1) & (SENSOR_RX_BUF_SIZE - 1);
    return ch;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART6) {
        s_RxBuf[s_RxHead] = s_RxByte;
        s_RxHead = (s_RxHead + 1) & (SENSOR_RX_BUF_SIZE - 1);
        HAL_UART_Receive_IT(&huart6, &s_RxByte, 1);
    }
}

void USART6_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart6);
}
