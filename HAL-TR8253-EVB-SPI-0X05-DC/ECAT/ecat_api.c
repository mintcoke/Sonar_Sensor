#include "ecat_api.h"
#include "applInterface.h"
#include "SSC-Device.h"
#include "TR8253Evb.h"
#include "App_Flash.h"
#include "stm32f4xx_hal.h"

ECAT_Input_t g_EcatInput;
ECAT_Output_t g_EcatOutput;

void (*g_pfnPeriodicTask)(void)          = 0;
void (*g_pfnSafeOutput)(void)            = 0;
void (*g_pfnTxPdoMapping)(UINT16* pData) = 0;
void (*g_pfnRxPdoMapping)(UINT16* pData) = 0;

static ecat_periodic_cb_t    s_pfnUserPeriodic = 0;
static ecat_safe_output_cb_t s_pfnUserSafeOut  = 0;

static void PDO_TxMapping(UINT16* pData)
{
    uint8_t *dst = (uint8_t *)pData;
    memset(dst, 0, MAX_PD_INPUT_SIZE);

    dst[0] = (uint8_t)(ECAT_INPUT.tx.DI_bits & 0xFFU);
    dst[1] = (uint8_t)((ECAT_INPUT.tx.DI_bits >> 8) & 0xFFU);
}

static void PDO_RxMapping(UINT16* pData)
{
    uint8_t *src = (uint8_t *)pData;

    ECAT_OUTPUT.rx.DO_bits = (uint16_t)src[0];
    if (MAX_PD_OUTPUT_SIZE > 1) {
        ECAT_OUTPUT.rx.DO_bits |= (uint16_t)((uint16_t)src[1] << 8);
    }
}

static void Bridge_PeriodicTask(void)
{
    if (s_pfnUserPeriodic) {
        s_pfnUserPeriodic();
    }
}

static void Bridge_SafeOutput(void)
{
    if (s_pfnUserSafeOut) {
        s_pfnUserSafeOut();
    }
}

void ECAT_RegisterPeriodicTask(ecat_periodic_cb_t cb)
{
    s_pfnUserPeriodic = cb;
}

void ECAT_RegisterSafeOutput(ecat_safe_output_cb_t cb)
{
    s_pfnUserSafeOut = cb;
}

void ECAT_Stack_Init(void)
{
    int retry = 0;

    memset(&g_EcatInput, 0, sizeof(g_EcatInput));
    memset(&g_EcatOutput, 0, sizeof(g_EcatOutput));

    g_pfnPeriodicTask = Bridge_PeriodicTask;
    g_pfnSafeOutput = Bridge_SafeOutput;
    g_pfnTxPdoMapping = PDO_TxMapping;
    g_pfnRxPdoMapping = PDO_RxMapping;

    while (HW_Init() != 0U) {
        retry++;
        if (retry >= 3) {
            while (1) {
            }
        }
        HAL_Delay(100U);
    }

    App_Load_Params_From_Flash();
    MainInit();
}

void ECAT_Stack_MainLoop(void)
{
#if ECAT_WD_TIMEOUT_MS > 0
    static uint32_t s_WatchdogTimer = 0U;
#endif

    MainLoop();

#if ECAT_WD_TIMEOUT_MS > 0
    if (bEcatOutputUpdateRunning) {
        s_WatchdogTimer = 0U;
    } else {
        s_WatchdogTimer++;
        if (s_WatchdogTimer >= ECAT_WD_TIMEOUT_MS) {
            if (g_pfnSafeOutput) {
                g_pfnSafeOutput();
            }
            s_WatchdogTimer = 0U;
        }
    }
#endif

    if (g_bConfigDirty) {
        App_Save_Params_To_Flash();
    }
}

PersistentParams_t g_PersistentParams;

uint32_t ECAT_GetParamSize(void)
{
    return sizeof(g_PersistentParams);
}

void* ECAT_GetParamPtr(void)
{
    return &g_PersistentParams;
}

void ECAT_SetParamDirty(void)
{
    g_bConfigDirty = 1U;
}

uint8_t ECAT_IsOpRunning(void)
{
    return bEcatOutputUpdateRunning ? 1U : 0U;
}

uint8_t ECAT_GetAlState(void)
{
    return nAlStatus;
}
