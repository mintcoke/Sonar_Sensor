# PDO 数据交互协议文档

## 1. 概述

本文档定义了从站设备与 EtherCAT 主站之间的 PDO 数据交互协议。

### 1.1 架构

```
SSC Tool（最后一次生成，永久不动）
    |
    +-- SSC-DeviceObjects.h -- TOBJ6000 / TOBJ7000（1024 字节缓冲区）
    |
    +-- ESI 文件（.xml）-- 主站加载用（已固定）
    |
    +-- 你的代码（联合体覆盖）
             |
             +-- struct TxData  <- 输入（从站->主站）
             +-- struct RxData  <- 输出（主站->从站）
```

### 1.2 核心原理

- SSC Tool 生成 **256 个 UDINT（1024 字节）** 的大缓冲区
- 通过 **联合体** 将你的 TxData / RxData 覆盖在同一个内存地址上
- 协议栈通过 sizeof(TxData) / sizeof(RxData) 决定 **实际传输的字节数**
- 未使用的缓冲区空间 **不会传输**，不影响带宽

---

## 2. 数据结构定义

### 2.1 输入数据（从站 -> 主站）

**结构体：struct TxData**

| 偏移量 | 大小 | 类型 | 变量名 | 说明 |
|--------|------|------|--------|------|
| 0 | 1 字节 | UINT8 | DI_bits | 数字量输入（bit0=DI_1 ... bit7=DI_8） |
| 1 | 1 字节 | -- | *(自动填充)* | 字对齐填充 |
| 2 | 2 字节 | UINT16 | sensor_value | 传感器值 |
| 4 | 2 字节 | UINT16 | temperature | 温度 |
| 6 | 4 字节 | UDINT | status_code | 状态码 |
| 10 | 4 字节 | UDINT | uptime_counter | 运行时间计数（秒） |

**总大小：14 字节**

### 2.2 输出数据（主站 -> 从站）

**结构体：struct RxData**

| 偏移量 | 大小 | 类型 | 变量名 | 说明 |
|--------|------|------|--------|------|
| 0 | 1 字节 | UINT8 | DO_bits | 数字量输出（bit0=DO_1 ... bit7=DO_8） |
| 1 | 1 字节 | UINT8 | control_mode | 控制模式 |
| 2 | 2 字节 | UINT16 | target_speed | 目标速度 |
| 4 | 4 字节 | UDINT | config_param | 配置参数 |

**总大小：8 字节**

---

## 3. 新项目操作流程

### 3.1 需要修改的文件

| 文件 | 修改内容 | 耗时 |
|------|---------|------|
| HARDWARE/Application.h | 修改 struct TxData 和 struct RxData | 10 分钟 |
| HARDWARE/Application.c | 修改 App_Periodic_Task() 和 App_Safe_Output_State() | 视功能而定 |
| 无需修改 | SSC/* 所有文件 | 0 分钟 |
| 无需修改 | ECAT/ecat_api.h / ecat_api.c | 0 分钟 |

### 3.2 操作步骤

```
// Step 1: 在 Application.h 中定义数据布局
struct TxData {
    // BOOL / UINT8 放前面
    uint8_t     DI_bits;            // DI_1~DI_8
    
    // UINT16 / UDINT 放后面（自动字对齐）
    uint16_t    sensor_value;
    uint32_t    status_code;
};

struct RxData {
    uint8_t     DO_bits;
    uint8_t     control_mode;
    uint16_t    target_speed;
    uint32_t    config_param;
};

// Step 2: 在 Application.c 中读写数据
void App_Periodic_Task(void)
{
    // 写输入（从站->主站）
    ECAT_INPUT.tx.sensor_value = read_adc(0);
    ECAT_INPUT.tx.status_code  = get_status();
    
    // 读输出（主站->从站）
    motor_set_speed(ECAT_OUTPUT.rx.target_speed);
}
```

### 3.3 主站侧操作

主站工程师只需知道本协议文档中的**偏移量表**，在 TwinCAT 或其他主站中按字节偏移读取/写入即可。

> **不需要 ESI 文件也能通信**，纯字节偏移约定即可。

---

## 4. BIT 访问宏

| 宏 | 说明 | 示例 |
|----|------|------|
| DI_Read(n) | 读取第 n 个 DI | if (DI_Read(1)) { ... } |
| DI_Set(n) | 置位第 n 个 DI | DI_Set(3); |
| DI_Clr(n) | 清零第 n 个 DI | DI_Clr(3); |
| DI_Write(n, v) | 写入第 n 个 DI | DI_Write(5, 1); |
| DO_Read(n) | 读取第 n 个 DO | if (DO_Read(1)) { ... } |
| DO_Set(n) | 置位第 n 个 DO | DO_Set(2); |
| DO_Clr(n) | 清零第 n 个 DO | DO_Clr(2); |
| DO_Write(n, v) | 写入第 n 个 DO | DO_Write(4, 0); |

---

## 5. 安全输出协议

当 EtherCAT 通信丢失或超时时，从站自动执行安全输出：

```c
void App_Safe_Output_State(void)
{
    memset(&ECAT_OUTPUT.rx, 0, sizeof(struct RxData));
    DO_WriteAll(0);
    motor_stop();
}
```

**安全状态定义：**
- 所有 DO 输出 = 0（OFF）
- 目标速度 = 0（停止）
- 控制模式 = 0（空闲）

---

## 6. 带宽与性能

| 项目 | 值 |
|------|-----|
| 最大预留缓冲区 | 1024 字节 |
| 本项目实际使用（输入） | 14 字节 |
| 本项目实际使用（输出） | 8 字节 |
| 未传输的浪费 | 0 字节 |

> **协议栈只传输 sizeof(TxData) + sizeof(RxData) 的实际大小**，不会有带宽浪费。

---

## 7. 向后兼容说明

当需要新增变量时：
1. 在 struct TxData 或 struct RxData **末尾**添加新字段
2. 重新编译下载
3. 旧主站仍然能通信（只读到旧大小）
4. 新主站更新 ESI 后能读到新字段

> **警告：新字段只能追加在结构体末尾，不能插入中间或修改已有字段的偏移！**

---

## 8. 常见问题

**Q: 需要修改 SSC 配置吗？**
A: 不需要。SSC 配置一次性生成 256 UDINT 后永久不动。

**Q: 需要修改 ESI 文件吗？**
A: 不需要。ESI 一次生成后永久不动。主站按偏移量约定解析数据即可。

**Q: 最多能定义多少变量？**
A: TxData + RxData 总计不超过 2048 字节，即各不超过 1024 字节。

**Q: 加新变量需要改什么？**
A: 只在 Application.h 的结构体中追加一行，然后改 Application.c 的业务逻辑。

---

## 9. 文档版本

| 版本 | 日期 | 修改内容 | 作者 |
|------|------|---------|------|
| 1.0 | - | 初始版本 | - |
