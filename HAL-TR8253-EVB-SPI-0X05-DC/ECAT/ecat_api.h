#ifndef _ECAT_API_H_
#define _ECAT_API_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ═══════════════════════════════════════════════════════════════
 *  EtherCAT 从站库 — 单头文件接口
 *  改 PDO 大小只改 PDO_TX/RX_UINT16，其他自动适配
 * ═══════════════════════════════════════════════════════════════ */

/* ── PDO 大小 (按需修改) ── */
#define PDO_TX_UINT16   510
#define PDO_RX_UINT16   510

/* ── PDO 上限 (不必改) ── */
#define PDO_TX_MAX      0x400
#define PDO_RX_MAX      0x400

/* ── 自动计算 ── */
#define PDO_TX_BYTES    ((PDO_TX_UINT16) * 2U)
#define PDO_RX_BYTES    ((PDO_RX_UINT16) * 2U)

/* ═══════════════════════════════════════════════════════════════
 *  统一 PDO 访问 — DI(n) / DO(n)
 *  2 个 ARRAY × 255 UINT16 拼接成连续 0~509 逻辑索引
 * ═══════════════════════════════════════════════════════════════ */
#define _DI_BASE  ((uint16_t*)(&DIUnit10x6000.u16SubIndex0 + 1))
#define _DO_BASE  ((uint16_t*)(&DOUnit20x7000.u16SubIndex0 + 1))
#define DI(n)     (_DI_BASE[(n)])
#define DO(n)     (_DO_BASE[(n)])

/* ═══════════════════════════════════════════════════════════════
 *  PDO 变量命名 — 在这里给每个偏移起名字
 * ═══════════════════════════════════════════════════════════════ */

/* ── TxPDO (设备→PLC) ── */
#define T_STATE      0
#define T_ALARM      1
#define T_VERSION    2

/* ── RxPDO (PLC→设备) ── */
#define R_CTRL       0
#define R_SPEED      1

/* ═══════════════════════════════════════════════════════════════
 *  持久化参数
 * ═══════════════════════════════════════════════════════════════ */
typedef struct {
    float    sonar_zero_offset;
    float    sonar_scale_factor;
    uint16_t modbus_slave_addr;
    uint16_t baudrate_code;
    uint32_t reserved[8];
    uint32_t checksum;
} PersistentParams_t;

extern PersistentParams_t g_PersistentParams;

/* ═══════════════════════════════════════════════════════════════
 *  API
 * ═══════════════════════════════════════════════════════════════ */
void ECAT_Stack_Init(void);
void ECAT_Stack_MainLoop(void);

typedef void (*ecat_periodic_cb_t)(void);
void ECAT_RegisterPeriodicTask(ecat_periodic_cb_t cb);

typedef void (*ecat_safe_output_cb_t)(void);
void ECAT_RegisterSafeOutput(ecat_safe_output_cb_t cb);

uint32_t ECAT_GetParamSize(void);
void*    ECAT_GetParamPtr(void);
void     ECAT_SetParamDirty(void);

uint8_t ECAT_IsOpRunning(void);
uint8_t ECAT_GetAlState(void);

#ifdef __cplusplus
}
#endif

#endif /* _ECAT_API_H_ */
