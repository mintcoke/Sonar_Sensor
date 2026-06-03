/*
 * ecat_cb.h — SSC ↔ 用户代码桥接指针
 *
 * 此文件不会被 SSC Tool 覆盖。
 * SSC Tool 更新后, 在 SSC-Device.h 末尾加一行:  #include "ecat_cb.h"
 */

#ifndef __ECAT_CB_H
#define __ECAT_CB_H

#include "ecat_def.h"

/* 由 ecat_api.c 注册, SSC-Device.c 通过 APPL_Application 等函数调用 */
extern void (*g_pfnPeriodicTask)(void);
extern void (*g_pfnSafeOutput)(void);
extern void (*g_pfnTxPdoMapping)(UINT16* pData);
extern void (*g_pfnRxPdoMapping)(UINT16* pData);

#endif
