/**
 * ==================================================================
 *  ecat_pdo_user.h  —  业务 PDO 结构体 (自动适配 ecat_pdo_config.h)
 * ==================================================================
 *
 * 不要直接改这个文件！
 * 变量增删:  改 ecat_pdo_config.h 的 _USED 宏
 * 字段命名:  改下面 struct 里的字段名
 *
 * SSC Tool 固定 3+3 个 ARRAY 对象:
 *   TxPDO: 0x6000(BOOL) → 0x6001(UINT) → 0x6002(UDINT)
 *   RxPDO: 0x7000(BOOL) → 0x7001(UINT) → 0x7002(UDINT)
 */

#ifndef _ECAT_PDO_USER_H_
#define _ECAT_PDO_USER_H_

#include <stdint.h>
#include "ecat_pdo_config.h"

/* ==================================================================
 * 编译期工具宏
 * ================================================================== */
#define ECAT_ROUND_UP8(n)   (((n) + 7U) / 8U)
#define ECAT_BYTES(n)       (ECAT_ROUND_UP8(n))           /* bool: bit→byte */
#define ECAT_U16BYTES(n)    ((n) * 2U)                    /* uint16: count→byte */
#define ECAT_U32BYTES(n)    ((n) * 4U)                    /* uint32: count→byte */

/* ==================================================================
 * 结构体展开宏: 生成 N 个命名字段 + padding
 * 原理: 利用 C 的宏展开逐字段声明，对齐到 raw 数组边界
 * ================================================================== */

#pragma pack(push, 1)

/* ------------------------------------------------------------------
 * Tx Bools (bitfield 打包)
 * 每个 bool 1 bit, _USED 个聚合在 uint32_t 位域中
 * ------------------------------------------------------------------ */
typedef struct {
    union {
        uint8_t raw[ECAT_BYTES(SSC_BOOL_ELEMENTS)];
        struct {
            /* ---- 用户 bool 字段区 ---- */
            uint32_t
#if (TX_BOOL_USED >= 1)
                emergency_stop : 1,
#endif
#if (TX_BOOL_USED >= 2)
                running       : 1,
#endif
#if (TX_BOOL_USED >= 3)
                error         : 1,
#endif
#if (TX_BOOL_USED >= 4)
                warning       : 1,
#endif
#if (TX_BOOL_USED >= 5)
                limit_pos     : 1,
#endif
#if (TX_BOOL_USED >= 6)
                limit_neg     : 1,
#endif
#if (TX_BOOL_USED >= 7)
                home_done     : 1,
#endif
#if (TX_BOOL_USED >= 8)
                servo_ready   : 1,
#endif
#if (TX_BOOL_USED >= 9)
                b9            : 1,
#endif
#if (TX_BOOL_USED >= 10)
                b10           : 1,
#endif
#if (TX_BOOL_USED >= 11)
                b11           : 1,
#endif
#if (TX_BOOL_USED >= 12)
                b12           : 1,
#endif
#if (TX_BOOL_USED >= 13)
                b13           : 1,
#endif
#if (TX_BOOL_USED >= 14)
                b14           : 1,
#endif
#if (TX_BOOL_USED >= 15)
                b15           : 1,
#endif
#if (TX_BOOL_USED >= 16)
                b16           : 1,
#endif

                /* 超过 16 个 bool 时补齐下一个 word */
                _pad1         : (32 - ((TX_BOOL_USED) < 16 ? (TX_BOOL_USED) : ((TX_BOOL_USED) > 16 ? (TX_BOOL_USED) % 16 : 0)));

            uint32_t _extra_words[(ECAT_BYTES(SSC_BOOL_ELEMENTS) > 4 ? (ECAT_BYTES(SSC_BOOL_ELEMENTS) - 4) / 4 : 0)];
        } bits;
    };
    /* 编译期校验 */
    typedef char _check_tx_bools_size[sizeof(raw) == ECAT_BYTES(SSC_BOOL_ELEMENTS) ? 1 : -1];
} TxBools_t;

/* 简化版: bool 直接用 uint8 位域, 放弃宏展开 */

/* ------------------------------------------------------------------
 * Tx UINT16 (uint16 + uint8 共享)
 * ------------------------------------------------------------------ */
typedef struct {
    union {
        uint8_t  raw[ECAT_U16BYTES(SSC_UINT16_ELEMENTS)];
        uint16_t arr[SSC_UINT16_ELEMENTS];
        struct {
#if (TX_UINT16_USED >= 1)
            uint16_t w0;
#endif
#if (TX_UINT16_USED >= 2)
            uint16_t w1;
#endif
#if (TX_UINT16_USED >= 3)
            uint16_t w2;
#endif
#if (TX_UINT16_USED >= 4)
            uint16_t w3;
#endif
#if (TX_UINT16_USED >= 5)
            uint16_t w4;
#endif
#if (TX_UINT16_USED >= 6)
            uint16_t w5;
#endif
#if (TX_UINT16_USED >= 7)
            uint16_t w6;
#endif
#if (TX_UINT16_USED >= 8)
            uint16_t w7;
#endif
#if (TX_UINT16_USED >= 9)
            uint16_t w8;
#endif
#if (TX_UINT16_USED >= 10)
            uint16_t w9;
#endif
            uint16_t _pad[(SSC_UINT16_ELEMENTS) - (TX_UINT16_USED)];
        } fields;
    };
    typedef char _check_tx_u16_size[sizeof(raw) == ECAT_U16BYTES(SSC_UINT16_ELEMENTS) ? 1 : -1];
} TxU16_t;

/* ------------------------------------------------------------------
 * Tx UINT32
 * ------------------------------------------------------------------ */
typedef struct {
    union {
        uint8_t  raw[ECAT_U32BYTES(SSC_UINT32_ELEMENTS)];
        uint32_t arr[SSC_UINT32_ELEMENTS];
        struct {
#if (TX_UINT32_USED >= 1)
            uint32_t dw0;
#endif
#if (TX_UINT32_USED >= 2)
            uint32_t dw1;
#endif
#if (TX_UINT32_USED >= 3)
            uint32_t dw2;
#endif
#if (TX_UINT32_USED >= 4)
            uint32_t dw3;
#endif
#if (TX_UINT32_USED >= 5)
            uint32_t dw4;
#endif
#if (TX_UINT32_USED >= 6)
            uint32_t dw5;
#endif
#if (TX_UINT32_USED >= 7)
            uint32_t dw6;
#endif
#if (TX_UINT32_USED >= 8)
            uint32_t dw7;
#endif
            uint32_t _pad[(SSC_UINT32_ELEMENTS) - (TX_UINT32_USED)];
        } fields;
    };
    typedef char _check_tx_u32_size[sizeof(raw) == ECAT_U32BYTES(SSC_UINT32_ELEMENTS) ? 1 : -1];
} TxU32_t;

/* ------------------------------------------------------------------
 * Rx Bools
 * ------------------------------------------------------------------ */
typedef struct {
    union {
        uint8_t raw[ECAT_BYTES(SSC_BOOL_ELEMENTS)];
        struct {
            uint32_t
#if (RX_BOOL_USED >= 1)
                enable        : 1,
#endif
#if (RX_BOOL_USED >= 2)
                reset         : 1,
#endif
#if (RX_BOOL_USED >= 3)
                start         : 1,
#endif
#if (RX_BOOL_USED >= 4)
                stop          : 1,
#endif
#if (RX_BOOL_USED >= 5)
                jog_fwd       : 1,
#endif
#if (RX_BOOL_USED >= 6)
                jog_rev       : 1,
#endif
#if (RX_BOOL_USED >= 7)
                home_start    : 1,
#endif
#if (RX_BOOL_USED >= 8)
                quick_stop    : 1,
#endif
#if (RX_BOOL_USED >= 9)
                r9            : 1,
#endif
#if (RX_BOOL_USED >= 10)
                r10           : 1,
#endif
#if (RX_BOOL_USED >= 11)
                r11           : 1,
#endif
#if (RX_BOOL_USED >= 12)
                r12           : 1,
#endif
#if (RX_BOOL_USED >= 13)
                r13           : 1,
#endif
#if (RX_BOOL_USED >= 14)
                r14           : 1,
#endif
#if (RX_BOOL_USED >= 15)
                r15           : 1,
#endif
#if (RX_BOOL_USED >= 16)
                r16           : 1,
#endif
                _pad1         : 0;

            uint32_t _extra_words[(ECAT_BYTES(SSC_BOOL_ELEMENTS) > 4 ? (ECAT_BYTES(SSC_BOOL_ELEMENTS) - 4) / 4 : 0)];
        } bits;
    };
    typedef char _check_rx_bools_size[sizeof(raw) == ECAT_BYTES(SSC_BOOL_ELEMENTS) ? 1 : -1];
} RxBools_t;

/* ------------------------------------------------------------------
 * Rx UINT16
 * ------------------------------------------------------------------ */
typedef struct {
    union {
        uint8_t  raw[ECAT_U16BYTES(SSC_UINT16_ELEMENTS)];
        uint16_t arr[SSC_UINT16_ELEMENTS];
        struct {
#if (RX_UINT16_USED >= 1)
            uint16_t w0;
#endif
#if (RX_UINT16_USED >= 2)
            uint16_t w1;
#endif
#if (RX_UINT16_USED >= 3)
            uint16_t w2;
#endif
#if (RX_UINT16_USED >= 4)
            uint16_t w3;
#endif
#if (RX_UINT16_USED >= 5)
            uint16_t w4;
#endif
#if (RX_UINT16_USED >= 6)
            uint16_t w5;
#endif
#if (RX_UINT16_USED >= 7)
            uint16_t w6;
#endif
#if (RX_UINT16_USED >= 8)
            uint16_t w7;
#endif
            uint16_t _pad[(SSC_UINT16_ELEMENTS) - (RX_UINT16_USED)];
        } fields;
    };
    typedef char _check_rx_u16_size[sizeof(raw) == ECAT_U16BYTES(SSC_UINT16_ELEMENTS) ? 1 : -1];
} RxU16_t;

/* ------------------------------------------------------------------
 * Rx UINT32
 * ------------------------------------------------------------------ */
typedef struct {
    union {
        uint8_t  raw[ECAT_U32BYTES(SSC_UINT32_ELEMENTS)];
        uint32_t arr[SSC_UINT32_ELEMENTS];
        struct {
#if (RX_UINT32_USED >= 1)
            uint32_t dw0;
#endif
#if (RX_UINT32_USED >= 2)
            uint32_t dw1;
#endif
#if (RX_UINT32_USED >= 3)
            uint32_t dw2;
#endif
#if (RX_UINT32_USED >= 4)
            uint32_t dw3;
#endif
#if (RX_UINT32_USED >= 5)
            uint32_t dw4;
#endif
#if (RX_UINT32_USED >= 6)
            uint32_t dw5;
#endif
#if (RX_UINT32_USED >= 7)
            uint32_t dw6;
#endif
#if (RX_UINT32_USED >= 8)
            uint32_t dw7;
#endif
            uint32_t _pad[(SSC_UINT32_ELEMENTS) - (RX_UINT32_USED)];
        } fields;
    };
    typedef char _check_rx_u32_size[sizeof(raw) == ECAT_U32BYTES(SSC_UINT32_ELEMENTS) ? 1 : -1];
} RxU32_t;

#pragma pack(pop)

/* ==================================================================
 * 全局变量声明
 * ================================================================== */
extern TxBools_t  g_TxBools;
extern TxU16_t    g_TxU16;
extern TxU32_t    g_TxU32;
extern RxBools_t  g_RxBools;
extern RxU16_t    g_RxU16;
extern RxU32_t    g_RxU32;

#endif /* _ECAT_PDO_USER_H_ */
