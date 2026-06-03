/**
 * @file    ecat_debug.h
 * @brief   EtherCAT 调试与日志接口 (可选)
 *
 * 提供可选的调试输出功能，便于开发阶段排查问题。
 * 正式发布时可通过宏关闭所有调试输出。
 *
 * 使用方法:
 *   1. 在 Keil MDK Define 中添加 ECAT_DEBUG_ENABLE=1
 *   2. 实现 ECAT_DebugPutChar(ch) 宏用于字符输出
 *      (例如: 重定向到串口、SWO、或 RTT)
 *   3. 在代码中调用 ECAT_DEBUG(...) 输出调试信息
 *
 * 默认实现:
 *   如果未定义 ECAT_DebugPutChar，则所有调试宏展开为空。
 */

#ifndef _ECAT_DEBUG_H_
#define _ECAT_DEBUG_H_

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================
 * 调试开关
 *
 * 在 Keil MDK 的 Define 中设置：
 *   ECAT_DEBUG_ENABLE=1
 *
 * 或者在编译选项中添加 -DECAT_DEBUG_ENABLE=1
 * ============================================================ */
#ifndef ECAT_DEBUG_ENABLE
#define ECAT_DEBUG_ENABLE   0   /* 默认关闭调试输出 */
#endif

/* ============================================================
 * 调试输出接口定义
 *
 * 用户需要在项目中实现字符输出函数。
 * 常用选项:
 *
 *   选项 1: 串口输出 (UART)
 *     #define ECAT_DebugPutChar(ch)  USART_SendChar(ch)
 *
 *   选项 2: ITM/SWO (需调试器支持)
 *     #define ECAT_DebugPutChar(ch)  ITM_SendChar(ch)
 *
 *   选项 3: SEGGER RTT
 *     #define ECAT_DebugPutChar(ch)  SEGGER_RTT_WriteChar(0, ch)
 *
 *   选项 4: 直接使用 printf (需重定向)
 *     #define ECAT_DebugPutChar(ch)  putchar(ch)
 * ============================================================ */
#ifndef ECAT_DebugPutChar
/* 如果没有定义输出函数，所有调试宏将为空操作 */
#define ECAT_DebugPutChar(ch)   ((void)0)
#endif

/* ============================================================
 * 内部: 字符串输出 (逐字符调用 ECAT_DebugPutChar)
 * ============================================================ */
#if ECAT_DEBUG_ENABLE
static inline void ECAT_Debug_Puts(const char *str)
{
    while (*str) {
        ECAT_DebugPutChar(*str++);
    }
}

static inline void ECAT_Debug_PutHex8(uint8_t val)
{
    const char hex[] = "0123456789ABCDEF";
    ECAT_DebugPutChar(hex[(val >> 4) & 0x0F]);
    ECAT_DebugPutChar(hex[val & 0x0F]);
}

static inline void ECAT_Debug_PutHex16(uint16_t val)
{
    ECAT_Debug_PutHex8((uint8_t)(val >> 8));
    ECAT_Debug_PutHex8((uint8_t)(val & 0xFF));
}

static inline void ECAT_Debug_PutHex32(uint32_t val)
{
    ECAT_Debug_PutHex16((uint16_t)(val >> 16));
    ECAT_Debug_PutHex16((uint16_t)(val & 0xFFFF));
}

static inline void ECAT_Debug_PutDec(uint32_t val)
{
    char buf[12];
    int i = 0;
    if (val == 0) {
        ECAT_DebugPutChar('0');
        return;
    }
    while (val > 0) {
        buf[i++] = (char)('0' + (val % 10));
        val /= 10;
    }
    while (i > 0) {
        ECAT_DebugPutChar(buf[--i]);
    }
}
#else
#define ECAT_Debug_Puts(s)           ((void)0)
#define ECAT_Debug_PutHex8(v)        ((void)0)
#define ECAT_Debug_PutHex16(v)       ((void)0)
#define ECAT_Debug_PutHex32(v)       ((void)0)
#define ECAT_Debug_PutDec(v)         ((void)0)
#endif /* ECAT_DEBUG_ENABLE */

/* ============================================================
 * 用户调试宏
 *
 * ECAT_DEBUG(fmt, ...)        -- 格式化调试输出
 * ECAT_DEBUG_WARN(fmt)        -- 警告信息
 * ECAT_DEBUG_ERR(fmt)         -- 错误信息
 * ECAT_DEBUG_HEX(label,data,len) -- 十六进制数据转储
 * ============================================================ */

#if ECAT_DEBUG_ENABLE
#include <stdarg.h>

#define ECAT_DEBUG(fmt, ...) do { \
    ECAT_Debug_Puts("[ECAT] "); \
    ECAT_Debug_Puts(fmt); \
    ECAT_DebugPutChar('\n'); \
} while(0)

#define ECAT_DEBUG_WARN(msg) do { \
    ECAT_Debug_Puts("[ECAT WARN] "); \
    ECAT_Debug_Puts(msg); \
    ECAT_DebugPutChar('\n'); \
} while(0)

#define ECAT_DEBUG_ERR(msg) do { \
    ECAT_Debug_Puts("[ECAT ERR]  "); \
    ECAT_Debug_Puts(msg); \
    ECAT_DebugPutChar('\n'); \
} while(0)

#define ECAT_DEBUG_HEX(label, data, len) do { \
    ECAT_Debug_Puts("[ECAT] "); \
    ECAT_Debug_Puts(label); \
    ECAT_Debug_Puts(": "); \
    for (uint32_t _i = 0; _i < (len); _i++) { \
        ECAT_Debug_PutHex8(((const uint8_t*)(data))[_i]); \
        ECAT_DebugPutChar(' '); \
    } \
    ECAT_DebugPutChar('\n'); \
} while(0)

/* 状态变化调试 */
#define ECAT_DEBUG_ALSTATE(old_state, new_state) do { \
    static const char * const _al_names[] = { \
        "", "INIT", "PREOP", "BOOT", "SAFEOP", "", "", "", "OP" }; \
    ECAT_Debug_Puts("[ECAT] AL state: "); \
    if ((old_state) <= 8 && _al_names[old_state][0]) \
        { ECAT_Debug_Puts(_al_names[old_state]); } \
    else \
        { ECAT_Debug_PutDec(old_state); } \
    ECAT_Debug_Puts(" -> "); \
    if ((new_state) <= 8 && _al_names[new_state][0]) \
        { ECAT_Debug_Puts(_al_names[new_state]); } \
    else \
        { ECAT_Debug_PutDec(new_state); } \
    ECAT_DebugPutChar('\n'); \
} while(0)

#else
#define ECAT_DEBUG(fmt, ...)        ((void)0)
#define ECAT_DEBUG_WARN(msg)        ((void)0)
#define ECAT_DEBUG_ERR(msg)         ((void)0)
#define ECAT_DEBUG_HEX(l, d, n)     ((void)0)
#define ECAT_DEBUG_ALSTATE(o, n)    ((void)0)
#endif /* ECAT_DEBUG_ENABLE */

#ifdef __cplusplus
}
#endif

#endif /* _ECAT_DEBUG_H_ */
