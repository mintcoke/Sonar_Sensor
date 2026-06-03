# EtherCAT Slave SDK 使用指南

> **版本**: 1.0  
> **适用平台**: STM32F407 + TR8253 EVB (SPI 接口)  
> **协议栈**: Beckhoff SSC V5.12  

---

## 目录

1. [SDK 概述](#1-sdk-概述)
2. [目录结构](#2-目录结构)
3. [快速上手（3 步）](#3-快速上手3-步)
4. [API 参考](#4-api-参考)
5. [新增 PDO 对象](#5-新增-pdo-对象)
6. [GPIO 引脚配置](#6-gpio-引脚配置)
7. [Flash 持久化参数](#7-flash-持久化参数)
8. [看门狗与安全输出](#8-看门狗与安全输出)
9. [常见问题](#9-常见问题)

---

## 1. SDK 概述

本 SDK 将 Beckhoff SSC (Slave Stack Code) EtherCAT 协议栈封装为**极简 API**，
业务工程师**无需了解**以下 EtherCAT 细节即可开发：

- CoE (CANopen over EtherCAT) 协议
- SDO (Service Data Object) 通信
- PDO (Process Data Object) 映射
- AL 状态机 (Init -> PreOP -> SafeOP -> OP)
- 分布式时钟 (DC)
- ESC (EtherCAT Slave Controller) 寄存器操作

### 核心设计原则

| 原则 | 说明 |
|------|------|
| **零协议知识** | 无需了解 EtherCAT 协议即可开发业务 |
| **查表法配置** | 修改 GPIO 引脚只需改数组，无需改业务逻辑 |
| **宏表驱动** | 新增 PDO 对象只需在宏列表里加一行 |
| **编译期检查** | ECAT_Set/Get 宏在编译时检查类型大小匹配 |
| **一键初始化** | 单函数完成协议栈全部初始化 |

---

## 2. 目录结构

```
工程根目录/
│
├── Core/              <- STM32 HAL 外设初始化 (CubeMX 生成)
│   ├── Inc/           <- 头文件
│   └── Src/           <- 源代码
│       ├── main.c         <- 主函数 (用户入口)
│       ├── gpio.c         <- GPIO 初始化
│       ├── spi.c          <- SPI 初始化
│       ├── tim.c          <- 定时器初始化
│       └── usart.c        <- 串口初始化
│
├── ECAT/              <- SDK 核心 (用户主要关注)
│   ├── ecat_api.h         <- 唯一需要 include 的头文件
│   ├── ecat_api.c         <- API 实现
│   ├── ecat_hw_if.h       <- 硬件抽象接口
│   ├── ecat_debug.h       <- 调试与日志接口
│   ├── Ecat_Sdk_Guide.md  <- 本指南
│   └── user_code_template.c <- 用户代码模板
│
├── HARDWARE/          <- 业务代码 (用户工作区)
│   ├── Application.c      <- 业务回调实现
│   ├── Application.h      <- GPIO 引脚映射 + 函数声明
│   ├── App_Flash.c        <- Flash 存储实现
│   └── App_Flash.h        <- Flash 存储接口
│
├── SSC/               <- EtherCAT 协议栈 (内部，无需修改)
│   ├── ecatslv.c/h         <- 从站核心
│   ├── ecatappl.c/h        <- 应用层
│   ├── ecatcoe.c/h         <- CoE 协议
│   ├── coeappl.c/h         <- CoE 应用
│   ├── mailbox.c/h         <- 邮箱通信
│   ├── objdef.c/h          <- 对象字典定义
│   ├── sdoserv.c/h         <- SDO 服务
│   ├── SSC-Device.c/h      <- SSC 设备配置
│   ├── SSC-DeviceObjects.h <- SSC 对象字典
│   ├── applInterface.h     <- 应用接口
│   ├── ecat_def.h          <- 协议栈配置宏
│   └── TR8253Evb.c/h       <- 板级支持包
│
├── Drivers/            <- STM32 HAL 驱动库
└── MDK-ARM/            <- Keil MDK 工程文件
```

---

## 3. 快速上手（3 步）

### 第 1 步: 编写 main.c

```c
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"
#include "ecat_api.h"
#include "Application.h"

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_SPI1_Init();
    MX_TIM3_Init();

    HAL_Delay(100);  // 等待外设稳定

    // 注册业务回调
    ECAT_RegisterPeriodicTask(App_Periodic_Task);
    ECAT_RegisterSafeOutput(App_Safe_Output_State);

    // 用户自定义外设初始化
    App_Hardware_Init();

    // 一键启动 EtherCAT 协议栈
    ECAT_Stack_Init();

    while (1)
    {
        ECAT_Stack_MainLoop();
    }
}
```

### 第 2 步: 实现业务逻辑 (Application.c)

```c
#include "Application.h"

void App_Periodic_Task(void)
{
    // DI 读取 -> 写入 TxPDO (位域直接赋值)
    ECAT_DI_VAR.DI1 = DI_Read(0);
    ECAT_DI_VAR.DI2 = DI_Read(1);
    ECAT_DI_VAR.DI3 = DI_Read(2);
    ECAT_DI_VAR.DI4 = DI_Read(3);

    // RxPDO 读取 -> DO 输出 (位域直接读取)
    DO_Write(0, ECAT_DO_VAR.DO1);
    DO_Write(1, ECAT_DO_VAR.DO2);
    DO_Write(2, ECAT_DO_VAR.DO3);
    DO_Write(3, ECAT_DO_VAR.DO4);

    // 数值类型示例 (用 ECAT_Set/Get)
    // uint16_t distance = read_sonar_sensor();
    // ECAT_Set(ECAT_SONAR_VAR.Distance, distance);
    //
    // int32_t target_speed;
    // ECAT_Get(ECAT_MOTOR_VAR.Speed, target_speed);
    // set_motor_speed(target_speed);
}

void App_Safe_Output_State(void)
{
    DO_WriteAll(0);  // 所有 DO 输出置 0
}

void App_Hardware_Init(void)
{
    // 在此添加用户外设初始化代码
}
```

### 第 3 步: 修改 GPIO 引脚映射 (Application.h)

```c
static const GpioPin_t s_DO_Pins[APP_DO_COUNT] = {
    {GPIOD_ODR_Addr, 14}, /* CH0  -> PD14 */
    {GPIOD_ODR_Addr, 15}, /* CH1  -> PD15 */
    {GPIOD_ODR_Addr,  0}, /* CH2  -> PD0  */
    // ... 修改为你需要的引脚
};

static const GpioPin_t s_DI_Pins[APP_DI_COUNT] = {
    {GPIOG_IDR_Addr, 15}, /* CH0 -> PG15 */
    {GPIOB_IDR_Addr,  3}, /* CH1 -> PB3  */
    // ... 修改为你需要的引脚
};
```

---

## 4. API 参考

### 4.1 初始化与主循环

| 函数 | 说明 | 调用时机 |
|------|------|----------|
| ECAT_Stack_Init() | 一键启动协议栈 (SPI/ESC/Flash恢复) | main 初始化时调用一次 |
| ECAT_Stack_MainLoop() | 驱动协议栈运行 (含看门狗) | while(1) 中循环调用 |

### 4.2 回调注册

| 函数 | 说明 | 参数 |
|------|------|------|
| ECAT_RegisterPeriodicTask(cb) | 注册周期性业务回调 | void (*cb)(void) |
| ECAT_RegisterSafeOutput(cb) | 注册安全输出回调 | void (*cb)(void) |

必须在 ECAT_Stack_Init() 之前调用。

### 4.3 PDO 数据访问

| 宏/变量 | 说明 | 使用场景 |
|---------|------|----------|
| ECAT_DI_VAR.DI1~DI16 | DI 位域变量 (BOOLEAN) | 直接读写数字量输入 |
| ECAT_DO_VAR.DO1~DO16 | DO 位域变量 (BOOLEAN) | 直接读写数字量输出 |
| ECAT_Set(field, value) | 写入数值类型到对象字典 | 写入模拟量/数值型 TxPDO |
| ECAT_Get(field, dst) | 从对象字典读取数值类型 | 读取模拟量/数值型 RxPDO |

### 4.4 状态查询

| 函数 | 返回值 | 说明 |
|------|--------|------|
| ECAT_IsOpRunning() | 0/1 | 是否处于 OP (运行) 状态 |
| ECAT_GetAlState() | 1/2/3/4/8 | AL 状态: 1=Init, 2=PreOP, 3=Boot, 4=SafeOP, 8=OP |

### 4.5 持久化参数

| 函数/变量 | 说明 |
|-----------|------|
| g_PersistentParams | 全局持久化参数结构体 |
| ECAT_SetParamDirty() | 标记参数已修改 (将自动写入 Flash) |

### 4.6 看门狗配置

| 宏 | 默认值 | 说明 |
|----|--------|------|
| ECAT_WD_TIMEOUT_MS | 100 | 看门狗超时 (ms)，设为 0 禁用 |

---

## 5. 新增 PDO 对象

### 背景

PDO (Process Data Object) 是 EtherCAT 主站和从站之间周期性交换的数据。
当前 SDK 默认提供:
- TxPDO (从站->主站): 16 路 DI (数字量输入)
- RxPDO (主站->从站): 16 路 DO (数字量输出)

### 新增步骤

假设要新增一个模拟量输入 (TxPDO) 和一个 PWM 频率控制 (RxPDO)：

#### 第 1 步: 使用 SSC Tool 更新对象字典

打开 SSC Tool，在对象字典中添加新对象 (如 0x6001 模拟量输入, 0x7001 PWM 控制)，
重新生成 SSC-DeviceObjects.h。

#### 第 2 步: 在 ecat_api.h 中添加映射

```c
// 1) 添加变量宏别名
#define ECAT_SONAR_VAR   SonarSensor0x6001    // 模拟量输入 (TxPDO)
#define ECAT_MOTOR_VAR   MotorSpeed0x7001     // PWM 控制 (RxPDO)

// 2) 在 TxPDO 列表中添加
#define ECAT_PDO_TX_LIST \
    ECAT_PDO_TX_ENTRY(ECAT_DI_VAR)    \
    ECAT_PDO_TX_ENTRY(ECAT_SONAR_VAR)  // <- 新增

// 3) 在 RxPDO 列表中添加
#define ECAT_PDO_RX_LIST \
    ECAT_PDO_RX_ENTRY(ECAT_DO_VAR)    \
    ECAT_PDO_RX_ENTRY(ECAT_MOTOR_VAR)  // <- 新增
```

#### 第 3 步: 在业务代码中使用

```c
void App_Periodic_Task(void)
{
    // 写入模拟量输入
    uint16_t adc_val = read_adc_channel(0);
    ECAT_Set(ECAT_SONAR_VAR.SI1, adc_val);

    // 读取 PWM 控制值
    uint16_t pwm_freq;
    ECAT_Get(ECAT_MOTOR_VAR.SI1, pwm_freq);
    set_pwm_frequency(pwm_freq);
}
```

---

## 6. GPIO 引脚配置

使用查表法管理 GPIO，修改引脚只需改数组。

### 修改 DO 引脚

```c
// 修改 Application.h 中的 s_DO_Pins 数组
static const GpioPin_t s_DO_Pins[APP_DO_COUNT] = {
    {GPIOD_ODR_Addr, 14}, /* CH0  -> PD14 */
    {GPIOD_ODR_Addr, 15}, /* CH1  -> PD15 */
    // ... 替换为实际需要的引脚
};
```

### 修改 DI 引脚

```c
static const GpioPin_t s_DI_Pins[APP_DI_COUNT] = {
    {GPIOG_IDR_Addr, 15}, /* CH0 -> PG15 */
    {GPIOB_IDR_Addr,  3}, /* CH1 -> PB3  */
    // ... 替换为实际需要的引脚
};
```

---

## 7. Flash 持久化参数

### 新增持久化参数

```c
// 在 ecat_api.h 的 PersistentParams_t 结构体中添加字段
typedef struct {
    uint16_t    my_calibration_value;   // 新校准参数
    float       my_gain;                // 新增益系数
    float    sonar_zero_offset;
    float    sonar_scale_factor;
    uint16_t modbus_slave_addr;
    uint16_t baudrate_code;
    uint32_t reserved[8];
    uint32_t checksum;    // 自动计算，勿修改
} PersistentParams_t;
```

### 读写参数

```c
// 读取
uint16_t val = g_PersistentParams.my_calibration_value;

// 写入并保存
g_PersistentParams.my_calibration_value = 1234;
ECAT_SetParamDirty();  // 标记脏页
```

---

## 8. 看门狗与安全输出

通信正常时看门狗计数器清零。通信中断时计数器递增，
超过 ECAT_WD_TIMEOUT_MS 后自动触发安全输出回调。

```c
void App_Safe_Output_State(void)
{
    DO_WriteAll(0);  // 所有 DO 置 0
    // motor_stop();
    // valve_close();
}
```

---

## 9. 常见问题

### Q1: 如何确认 EtherCAT 通信是否已建立？

```c
if (ECAT_IsOpRunning()) {
    // 已处于 OP 状态
} else {
    uint8_t state = ECAT_GetAlState();
    // 1=Init, 2=PreOP, 4=SafeOP, 8=OP
}
```

### Q2: 为什么 ECAT_Set/Get 编译报错？

检查 field 和 value/dst 的类型大小是否一致。

```c
// 错误: uint16_t 和 uint32_t 大小不匹配
uint32_t big_val = 100;
ECAT_Set(ECAT_SONAR_VAR.Distance, big_val);

// 正确: 类型大小一致
uint16_t val = 100;
ECAT_Set(ECAT_SONAR_VAR.Distance, val);
```

### Q3: 如何修改设备名称/厂商 ID？

```c
// 在 ecat_def.h 中修改，或外部 Define
#define VENDOR_ID       0x00006500
#define PRODUCT_CODE    0x00036500
#define DEVICE_NAME     "MY_DEVICE_NAME"

// 运行时修改
sIdentity.u32Serialnumber = 0x12345678;
strncpy(acDevicename, "MyDevice", sizeof(acDevicename));
```

### Q4: 为什么我的 DO 输出不动作？

1. 检查 EtherCAT 主站是否已切换到 OP 状态
2. 检查 Application.h 中 DO 引脚映射是否正确
3. 检查 GPIO 初始化是否在 MX_GPIO_Init() 中完成
4. 检查引脚模式是否配置为 GPIO_MODE_OUTPUT_PP

---

## 附录: 状态码速查

### AL 状态码

| 值 | 状态 | 说明 |
|----|------|------|
| 1 | Init | 初始化状态 |
| 2 | PreOP | 预运行，邮箱通信可用 |
| 3 | Boot | Bootstrap 模式 (Firmware 更新) |
| 4 | SafeOP | 安全运行，输出为安全状态 |
| 8 | OP | 运行状态，正常数据交换 |

### PDO 方向

| 缩写 | 方向 | 说明 |
|------|------|------|
| TxPDO | 从站 -> 主站 | 从站发送数据 (输入) |
| RxPDO | 主站 -> 从站 | 从站接收数据 (输出) |

---

> **文档版本**: v1.0 | **最后更新**: 2025年  