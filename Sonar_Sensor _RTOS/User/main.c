#include "gd32f10x.h"
#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "sonar.h"

/* 引入 FreeRTOS 头文件 */
#include "FreeRTOS.h"
#include "task.h"

#define SONAR_NUM 5
uint8_t sonar_addrs[SONAR_NUM] = {0x01, 0x02, 0x03, 0x04, 0x05};
int32_t sonar_distances[SONAR_NUM] = {0};

/* ====================================================
 * 任务：声纳轮询任务
 * ==================================================== */
void vSonarPollingTask(void *pvParameters)
{
		vTaskDelay(pdMS_TO_TICKS(1000));   
    /* 在正式开始前，清空一次串口接收缓冲区，防止上电时的电平抖动产生垃圾字节 */
    rs485_rx_len = 0;
    memset(rs485_rx_buf, 0, sizeof(rs485_rx_buf));
    while(1) {
        for(uint8_t i = 0; i < SONAR_NUM; i++) {
            rs485_rx_len = 0;
            Sonar_Send_Read_Cmd(sonar_addrs[i]);           
            vTaskDelay(pdMS_TO_TICKS(150)); // 等待传感器回复          
            int32_t dist = Sonar_Parse_Data(rs485_rx_buf, rs485_rx_len, sonar_addrs[i]);
            sonar_distances[i] = dist; // 如果出错或没收到，这里会存入 -1
        }      
        printf("$SONAR,%d,%d,%d,%d,%d\r\n", 
               sonar_distances[0], 
               sonar_distances[1], 
               sonar_distances[2], 
               sonar_distances[3], 
               sonar_distances[4]);
    }
}

/* ====================================================
 * Main 函数
 * ==================================================== */
int main(void)
{
    // 系统底层初始化
    nvic_priority_group_set(NVIC_PRIGROUP_PRE4_SUB0);
		UART_Init();

    printf("System Init OK! Starting FreeRTOS...\r\n");

    xTaskCreate(vSonarPollingTask, "SonarTask", 512, NULL, 2, NULL);

    // 启动任务调度器
    vTaskStartScheduler();
		
    // 正常情况下永远不会执行到这里
    while(1) {
    }
}
