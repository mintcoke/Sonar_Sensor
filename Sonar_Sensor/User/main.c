#include "gd32f10x.h"
#include <stdio.h>
#include <string.h>
#include "systick.h"
#include "uart.h"
#include "sonar.h"

/*!
    \brief 初始化独立看门狗 (超时时间约 6.5 秒)
*/
void FWDGT_Init(void)
{
    /* 1. 开启内部 40KHz 低速时钟并等待稳定 */
    rcu_osci_on(RCU_IRC40K); 
    while(ERROR == rcu_osci_stab_wait(RCU_IRC40K));
    
    /* 2. 配置并启动看门狗 */
    fwdgt_write_enable();
    fwdgt_config(0xFFF, FWDGT_PSC_DIV64); // 分频64，计数值4095
    fwdgt_enable(); 
}

int main(void)
{
    /* ================= 系统初始化 ================= */
	
    nvic_priority_group_set(NVIC_PRIGROUP_PRE4_SUB0);
    systick_config();       // 初始化滴答定时器
    UART_Init();            // 初始化串口 (RS232/RS485)
    FWDGT_Init();           // 启动看门狗 (6.5秒)
    /* ============================================== */
    
    delay_1ms(1000); //等待传感器工作稳定
	printf("start");
    while(1){
        /* 1. 喂狗防死机 */
        fwdgt_counter_reload();		
       
        /* 2. 轮询所有传感器 */
        Sonar_Poll_All();
        
        /* 3. 串口打印 */
        printf("$SONAR,%d,%d,%d,%d,%d\r\n",
               sonar_distances[0],
               sonar_distances[1],
               sonar_distances[2],
               sonar_distances[3],
               sonar_distances[4]); 
    }
}
