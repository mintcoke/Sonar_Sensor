/*
 * usart.c — 传感器串口驱动 (USART6, PC6=TX PC7=RX)
 *
 * DMA 循环接收, 硬件自动搬数, CPU 零参与
 */
#include "usart.h"
#include "stm32f4xx_hal.h"
#include "Application.h"

static UART_HandleTypeDef huart6;
static DMA_HandleTypeDef  hdma_usart6_rx;
#define DMA_BUF_SIZE  64
static uint8_t s_DmaBuf[DMA_BUF_SIZE] __attribute__((aligned(4)));

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

    // DMA2 Stream1 Ch5 → USART6_RX, 循环模式, 不开中断
    __HAL_RCC_DMA2_CLK_ENABLE();
    hdma_usart6_rx.Instance                 = DMA2_Stream1;
    hdma_usart6_rx.Init.Channel             = DMA_CHANNEL_5;
    hdma_usart6_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_usart6_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_usart6_rx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_usart6_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart6_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_usart6_rx.Init.Mode                = DMA_CIRCULAR;
    hdma_usart6_rx.Init.Priority            = DMA_PRIORITY_LOW;
    HAL_DMA_Init(&hdma_usart6_rx);
    __HAL_LINKDMA(&huart6, hdmarx, hdma_usart6_rx);

    // 启动 DMA 循环接收, 不开 DMA 中断
    __HAL_DMA_DISABLE_IT(&hdma_usart6_rx, DMA_IT_TC | DMA_IT_HT | DMA_IT_TE);
    HAL_UART_Receive_DMA(&huart6, s_DmaBuf, DMA_BUF_SIZE);
}

void Sensor_Trigger(void)
{
    USART6->CR1 |= USART_CR1_SBK;
}

void Sonar_RecvTick(void)
{
    // DMA 自动搬数, 这里读 DMA 缓冲
    static uint8_t  s_Buf[4];
    static uint32_t s_Pos = 0;
    uint32_t pos = DMA_BUF_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart6_rx);
    while (s_Pos != pos) {
        uint8_t ch = s_DmaBuf[s_Pos];
        s_Pos = (s_Pos + 1) & (DMA_BUF_SIZE - 1);
        s_Buf[0] = s_Buf[1]; s_Buf[1] = s_Buf[2]; s_Buf[2] = s_Buf[3]; s_Buf[3] = ch;
        g_SonarBuf[0]=s_Buf[0]; g_SonarBuf[1]=s_Buf[1];
        g_SonarBuf[2]=s_Buf[2]; g_SonarBuf[3]=s_Buf[3];
        if (s_Buf[0]==0xFF && ((s_Buf[0]+s_Buf[1]+s_Buf[2])&0xFF)==s_Buf[3]) {
            g_SonarDist = ((uint16_t)s_Buf[1]<<8) | s_Buf[2];
            DOCH15 = !DOCH15;
        }
    }
}

void USART6_IRQHandler(void) { HAL_UART_IRQHandler(&huart6); }
