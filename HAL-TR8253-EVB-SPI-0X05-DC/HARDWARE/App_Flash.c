/*
 * App_Flash.c — Flash 参数存储实现
 *
 * === 业务工程师使用说明 ===
 *
 * 你只需要:
 *   1. 在 ecat_api.h 的 PersistentParams_t 里加新字段
 *   2. 在业务代码里直接读写 g_PersistentParams
 *
 *   存: g_PersistentParams.sonar_zero_offset = 1.5f;
 *       ECAT_SetParamDirty();
 *       // 下个 ECAT_Stack_MainLoop 循环自动保存
 *
 *   读: float val = g_PersistentParams.sonar_zero_offset;
 *       // 上电时已自动从 Flash 恢复, 直接读即可
 *
 * 新增参数只需改 ecat_api.h 里的 PersistentParams_t 结构体,
 * 本文件不用动。
 */

#include "App_Flash.h"
#include "stm32f4xx_hal.h"
#include "ecat_api.h"
#include <string.h>

uint8_t g_bConfigDirty = 0;

/* ==========================================================
 * 第2步: 校验和算法 (XOR 所有 uint32_t, 不含 checksum 字段)
 *        业务工程师无需关心此函数。
 * ========================================================== */
static uint32_t ComputeChecksum(const PersistentParams_t *p)
{
    uint32_t sum = 0;
    uint32_t wordCnt = (sizeof(PersistentParams_t) - sizeof(p->checksum)) / 4;
    const uint32_t *pWords = (const uint32_t *)p;
    uint32_t i;
    for (i = 0; i < wordCnt; i++) {
        sum ^= pWords[i];
    }
    return sum;
}

/* ==========================================================
 * 第3步: 保存到 Flash
 *        STM32F407ZE 512KB: Sector 4, 0x08010000, 64KB
 *        自动校验是否变化, 不变化跳过(减少擦写磨损)
 *        业务工程师无需关心此函数。
 * ========================================================== */
#define FLASH_ADDR  0x08010000
#define FLASH_SECT  FLASH_SECTOR_4

void App_Save_Params_To_Flash(void)
{
    FLASH_EraseInitTypeDef erase_cfg = {0};
    uint32_t sector_err = 0;
    uint32_t size = sizeof(g_PersistentParams);

    /* 先算校验和再比较 */
    g_PersistentParams.checksum = ComputeChecksum(&g_PersistentParams);

    /* 和 Flash 里已有内容一样 → 跳过, 不擦写 */
    if (memcmp(&g_PersistentParams, (void*)FLASH_ADDR, size) == 0) {
        g_bConfigDirty = 0;
        return;
    }

    HAL_FLASH_Unlock();

    erase_cfg.TypeErase    = FLASH_TYPEERASE_SECTORS;
    erase_cfg.VoltageRange = FLASH_VOLTAGE_RANGE_3;
    erase_cfg.Sector       = FLASH_SECT;
    erase_cfg.NbSectors    = 1;

    if (HAL_FLASHEx_Erase(&erase_cfg, &sector_err) == HAL_OK) {
        uint32_t addr  = FLASH_ADDR;
        uint32_t cnt   = (size + 3) / 4;
        uint32_t *p    = (uint32_t *)&g_PersistentParams;
        uint32_t i;
        HAL_StatusTypeDef prog_ok = HAL_OK;
        for (i = 0; i < cnt; i++) {
            if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, addr, p[i]) != HAL_OK)
                { prog_ok = HAL_ERROR; break; }
            addr += 4;
        }
        if (prog_ok == HAL_OK) g_bConfigDirty = 0;  // 成功才清脏位
    }
    HAL_FLASH_Lock();
}

/* ==========================================================
 * 第4步: 从 Flash 加载
 *        上电时自动调用, 校验失败 → 恢复全0安全默认值
 *        业务工程师无需关心此函数。
 * ========================================================== */
void App_Load_Params_From_Flash(void)
{
    /* Flash 空白 (新芯片/全擦除后), 保持默认值 */
    if (*(__IO uint32_t*)FLASH_ADDR == 0xFFFFFFFF) {
        return;
    }

    memcpy(&g_PersistentParams, (void*)FLASH_ADDR, sizeof(g_PersistentParams));

    if (g_PersistentParams.checksum == ComputeChecksum(&g_PersistentParams)) {
        /* 校验通过, 参数已恢复到 g_PersistentParams, 业务代码直接用 */
    } else {
        /* 校验失败 (Flash 损坏/第一次用新结构体), 全部清零 */
        memset(&g_PersistentParams, 0, sizeof(g_PersistentParams));
    }
}

/* ==========================================================
 * 第5步: 业务代码使用示例
 *
 * 在 Application.c 或其他业务文件中这样用:
 *
 * // --- 读参数 (上电后随时读, 已自动从 Flash 恢复) ---
 * float offset = g_PersistentParams.sonar_zero_offset;
 * uint16_t addr = g_PersistentParams.modbus_slave_addr;
 *
 * // --- 改参数并保存 ---
 * g_PersistentParams.modbus_slave_addr = 5;
 * ECAT_SetParamDirty();
 * // 下个循环 ECAT_Stack_MainLoop 自动调 App_Save_Params_To_Flash()
 *
 * // --- 如果想通过 EtherCAT SDO 改参数 ---
 * // 主站通过 CoE 写 0xF008 对象, SSC 协议栈会触发 g_bConfigDirty,
 * // Flash 自动存储, 无需额外代码。
 * ========================================================== */
