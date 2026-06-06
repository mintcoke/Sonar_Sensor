#define _Application_ 1
#include <string.h>
#include "ecat_api.h"
#include "Application.h"
#include "usart.h"
#undef _Application_
#include "SSC-Device.h"
#include "TR8253Evb.h"

uint16_t g_SonarDist = 0xFFFF;
uint8_t  g_SonarBuf[4] = {0};

void Sonar_Task(void)
{
    // 触发状态机
    static uint32_t s_Tick = 0;
    static uint8_t  s_State = 0;
    switch (s_State) {
    case 0: USART6->CR1 |= USART_CR1_SBK;  s_Tick = HAL_GetTick(); s_State = 1; break;
    case 1: if (HAL_GetTick() - s_Tick < 1) break;
            USART6->CR1 &= ~USART_CR1_SBK; (void)USART6->SR; (void)USART6->DR;
            s_State = 2; break;
    case 2: if (HAL_GetTick() - s_Tick >= 50) s_State = 0; break;
    }
    Sonar_RecvTick();   // DMA 缓冲读+解析
}

uint16_t Sonar_Poll(void)
{
    return g_SonarDist;
}

void DO_LED_Ctrl()
{
	DI(T_DISTANCE) = Sonar_Poll();

	UINT16 v = DO(R_LED);
	DOCH0=(v>>0)&1; DOCH1=(v>>1)&1; DOCH2=(v>>2)&1; DOCH3=(v>>3)&1;
	DOCH4=(v>>4)&1; DOCH5=(v>>5)&1; DOCH6=(v>>6)&1; DOCH7=(v>>7)&1;
	DOCH8=(v>>8)&1; DOCH9=(v>>9)&1; DOCH10=(v>>10)&1; DOCH11=(v>>11)&1;
	DOCH12=(v>>12)&1; DOCH13=(v>>13)&1; DOCH14=(v>>14)&1;
}

void DO_LED_Off()
{
	DOCH0 = 0; DOCH1 = 0; DOCH2 = 0; DOCH3 = 0;
	DOCH4 = 0; DOCH5 = 0; DOCH6 = 0; DOCH7 = 0;
	DOCH8 = 0; DOCH9 = 0; DOCH10 = 0; DOCH11 = 0;
	DOCH12 = 0; DOCH13 = 0; DOCH14 = 0; /* DOCH15 声纳专用 */
}
