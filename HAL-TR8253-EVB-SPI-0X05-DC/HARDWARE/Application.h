#ifndef Application_H
#define Application_H
#include "ecat_api.h"     // PDO 统一接口 DI()/DO() + 栈 API
#include "sys.h"

/* ── LED GPIO (硬件相关) ── */
#define DOCH0    PDout(14)
#define DOCH1    PDout(15)
#define DOCH2    PDout(0)
#define DOCH3    PDout(1)
#define DOCH4    PEout(7)
#define DOCH5    PEout(8)
#define DOCH6    PEout(9)
#define DOCH7    PEout(10)
#define DOCH8    PEout(11)
#define DOCH9    PEout(12)
#define DOCH10   PEout(13)
#define DOCH11   PEout(14)
#define DOCH12   PEout(15)
#define DOCH13   PDout(8)
#define DOCH14   PDout(9)
#define DOCH15   PDout(10)

#define DICH0()   PGin(15)
#define DICH1()   PBin(3)
#define DICH2()   PBin(4)
#define DICH3()   PBin(5)
#define DICH4()   PBin(6)
#define DICH5()   PBin(7)
#define DICH6()   PBin(8)
#define DICH7()   PBin(9)

extern uint16_t g_SonarDist;
extern uint8_t  g_SonarBuf[4];
void     Sonar_Task(void);
uint16_t Sonar_Poll(void);
void DO_LED_Ctrl(void);
void DO_LED_Off(void);

#endif
