#ifndef _ECAT_API_H_
#define _ECAT_API_H_

#include <stdint.h>
#include <string.h>
#include "ecat_def.h"
#include "ecatappl.h"
#include "coeappl.h"
#include "ecat_cb.h"
#include "SSC-DeviceObjects.h"
#include "ecat_pdo_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ECAT_PD_IN_MAX
#define ECAT_PD_IN_MAX    0x400
#endif

#ifndef ECAT_PD_OUT_MAX
#define ECAT_PD_OUT_MAX   0x400
#endif

#ifndef MAX_PD_INPUT_SIZE
#define MAX_PD_INPUT_SIZE   ECAT_PD_IN_MAX
#endif

#ifndef MAX_PD_OUTPUT_SIZE
#define MAX_PD_OUTPUT_SIZE  ECAT_PD_OUT_MAX
#endif

typedef struct {
    struct TxData tx;
} ECAT_Input_t;

typedef struct {
    struct RxData rx;
} ECAT_Output_t;

extern ECAT_Input_t g_EcatInput;
extern ECAT_Output_t g_EcatOutput;

#define ECAT_INPUT   (g_EcatInput)
#define ECAT_OUTPUT  (g_EcatOutput)

void ECAT_Stack_Init(void);
void ECAT_Stack_MainLoop(void);

typedef void (*ecat_periodic_cb_t)(void);
void ECAT_RegisterPeriodicTask(ecat_periodic_cb_t cb);

typedef void (*ecat_safe_output_cb_t)(void);
void ECAT_RegisterSafeOutput(ecat_safe_output_cb_t cb);

typedef struct {
    float    sonar_zero_offset;
    float    sonar_scale_factor;
    uint16_t modbus_slave_addr;
    uint16_t baudrate_code;
    uint32_t reserved[8];
    uint32_t checksum;
} PersistentParams_t;

extern PersistentParams_t g_PersistentParams;

uint32_t ECAT_GetParamSize(void);
void*    ECAT_GetParamPtr(void);
void     ECAT_SetParamDirty(void);

#define ECAT_WD_TIMEOUT_MS  100

uint8_t ECAT_IsOpRunning(void);
uint8_t ECAT_GetAlState(void);

extern CHAR        acDevicename[];
extern CHAR        acHardwareversion[];
extern CHAR        acSoftwareversion[];
extern TOBJ1018    sIdentity;

#ifdef __cplusplus
}
#endif

#endif /* _ECAT_API_H_ */
