/**
 * @file    user_code_template.c
 * @brief   EtherCAT Slave SDK - User Code Template
 * @details Copy this file to HARDWARE/ directory, fill in your
 *          business logic following the comments.
 *
 * Instructions:
 *   1. Copy this file as HARDWARE/MyApplication.c
 *   2. Modify function names to avoid conflicts with Application.c
 *   3. Register your callbacks in main.c
 *   4. Start writing your business logic!
 */

#include "ecat_api.h"

/* ============================================================
 * Step 1: User-defined peripheral initialization
 *
 * Initialize your peripherals here (ADC, I2C, PWM, extra GPIO, etc.)
 * This function is called before ECAT_Stack_Init().
 * ============================================================ */
void MyApp_Hardware_Init(void)
{
    /* TODO: Add your peripheral initialization code here */
    /* Example:
    MX_ADC1_Init();
    MX_I2C1_Init();
    MySensor_Init();
    PWM_Init();
    */
}

/* ============================================================
 * Step 2: Periodic business callback
 *
 * This function is called periodically when EtherCAT is in OP state.
 * Read/write PDO data and hardware I/O here.
 *
 * Bitfield rules:
 *   ECAT_DI_VAR.DI1 ~ DI16  -> Digital Input (BOOLEAN bitfield)
 *   ECAT_DO_VAR.DO1 ~ DO16  -> Digital Output (BOOLEAN bitfield)
 *
 *   Bitfields use direct = assignment:
 *     ECAT_DI_VAR.DI1 = DI_Read(0);       // OK
 *     DO_Write(0, ECAT_DO_VAR.DO1);        // OK
 *     ECAT_Set(ECAT_DI_VAR.DI1, val);      // WRONG!
 *     ECAT_Get(ECAT_DO_VAR.DO1, val);      // WRONG!
 *
 * Numeric type rules (uint8/16/32, int, float):
 *   Use ECAT_Set/Get macros (compile-time type check):
 *     ECAT_Set(ECAT_SONAR_VAR.Distance, distance_mm); // OK
 *     ECAT_Get(ECAT_MOTOR_VAR.Speed, target_speed);   // OK
 * ============================================================ */
void MyApp_Periodic_Task(void)
{
    /* ---- Read DI -> Write to TxPDO (Slave -> Master) ---- */
    ECAT_DI_VAR.DI1  = DI_Read(0);   /* DI channel 0 */
    ECAT_DI_VAR.DI2  = DI_Read(1);   /* DI channel 1 */
    ECAT_DI_VAR.DI3  = DI_Read(2);
    ECAT_DI_VAR.DI4  = DI_Read(3);
    ECAT_DI_VAR.DI5  = DI_Read(4);
    ECAT_DI_VAR.DI6  = DI_Read(5);
    ECAT_DI_VAR.DI7  = DI_Read(6);
    ECAT_DI_VAR.DI8  = DI_Read(7);
    /* Uncomment for more channels:
    ECAT_DI_VAR.DI9  = DI_Read(8);
    ECAT_DI_VAR.DI10 = DI_Read(9);
    ECAT_DI_VAR.DI11 = DI_Read(10);
    ECAT_DI_VAR.DI12 = DI_Read(11);
    ECAT_DI_VAR.DI13 = DI_Read(12);
    ECAT_DI_VAR.DI14 = DI_Read(13);
    ECAT_DI_VAR.DI15 = DI_Read(14);
    ECAT_DI_VAR.DI16 = DI_Read(15);
    */

    /* ---- Read RxPDO (Master -> Slave) -> Drive DO ---- */
    DO_Write(0,  ECAT_DO_VAR.DO1);   /* DO channel 0 */
    DO_Write(1,  ECAT_DO_VAR.DO2);   /* DO channel 1 */
    DO_Write(2,  ECAT_DO_VAR.DO3);
    DO_Write(3,  ECAT_DO_VAR.DO4);
    DO_Write(4,  ECAT_DO_VAR.DO5);
    DO_Write(5,  ECAT_DO_VAR.DO6);
    DO_Write(6,  ECAT_DO_VAR.DO7);
    DO_Write(7,  ECAT_DO_VAR.DO8);
    DO_Write(8,  ECAT_DO_VAR.DO9);
    DO_Write(9,  ECAT_DO_VAR.DO10);
    DO_Write(10, ECAT_DO_VAR.DO11);
    DO_Write(11, ECAT_DO_VAR.DO12);
    DO_Write(12, ECAT_DO_VAR.DO13);
    DO_Write(13, ECAT_DO_VAR.DO14);
    DO_Write(14, ECAT_DO_VAR.DO15);
    DO_Write(15, ECAT_DO_VAR.DO16);

    /* ---- Batch read/write example (for backplane bus) ---- */
    /*
    uint16_t di_bits = DI_ReadAll();
    memcpy((uint16_t*)(&ECAT_DI_VAR.u16SubIndex0 + 1), &di_bits, sizeof(di_bits));
    */

    /* ---- Numeric type PDO example ---- */
    /*
    uint16_t adc_value = read_adc(0);
    ECAT_Set(ECAT_SONAR_VAR.Distance, adc_value);

    int32_t target_pos;
    ECAT_Get(ECAT_MOTOR_VAR.Position, target_pos);
    motor_move_to(target_pos);
    */

    /* ---- Flash persistent parameter example ---- */
    /*
    uint16_t slave_addr = g_PersistentParams.modbus_slave_addr;
    g_PersistentParams.baudrate_code = 2;
    ECAT_SetParamDirty();
    */
}

/* ============================================================
 * Step 3: Safe output callback (auto-triggered on comm loss)
 *
 * Set all output devices to safe state when EtherCAT
 * communication is lost/timed out.
 * ============================================================ */
void MyApp_Safe_Output_State(void)
{
    DO_WriteAll(0);  /* All DO outputs OFF */

    /* Add other safety actions:
     motor_stop();
     valve_close();
     alarm_led_on();
    */
}

/* ============================================================
 * Step 4: Register in main.c (reference code)
 *
 * Put this in your main.c USER CODE section:
 *
 *   int main(void) {
 *       // ... standard init ...
 *
 *       ECAT_RegisterPeriodicTask(MyApp_Periodic_Task);
 *       ECAT_RegisterSafeOutput(MyApp_Safe_Output_State);
 *
 *       MyApp_Hardware_Init();
 *       ECAT_Stack_Init();
 *
 *       while (1) {
 *           ECAT_Stack_MainLoop();
 *       }
 *   }
 * ============================================================ */