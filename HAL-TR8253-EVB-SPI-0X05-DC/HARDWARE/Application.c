#define _Application_ 1
#include <string.h>
#include "ecat_api.h"
#include "Application.h"
#undef _Application_
#include "SSC-Device.h"
#include "TR8253Evb.h"

/*******************************************************************************
* @Function Name	: DO_LED_Ctrl
* @Description  	: Main application function, called periodically
*******************************************************************************/
void DO_LED_Ctrl()
{
	UINT16 v = DO(0);
	DOCH0=(v>>0)&1; DOCH1=(v>>1)&1; DOCH2=(v>>2)&1; DOCH3=(v>>3)&1;
	DOCH4=(v>>4)&1; DOCH5=(v>>5)&1; DOCH6=(v>>6)&1; DOCH7=(v>>7)&1;
	DOCH8=(v>>8)&1; DOCH9=(v>>9)&1; DOCH10=(v>>10)&1; DOCH11=(v>>11)&1;
	DOCH12=(v>>12)&1; DOCH13=(v>>13)&1; DOCH14=(v>>14)&1; DOCH15=(v>>15)&1;

	memcpy(&DIUnit10x6000, &DOUnit20x7000, sizeof(DIUnit10x6000));
	memcpy(&DIUnit30x6001, &DOUnit40x7001, sizeof(DIUnit30x6001));
}

void DO_LED_Off()
{
	DOCH0 = 0; DOCH1 = 0; DOCH2 = 0; DOCH3 = 0;
	DOCH4 = 0; DOCH5 = 0; DOCH6 = 0; DOCH7 = 0;
	DOCH8 = 0; DOCH9 = 0; DOCH10 = 0; DOCH11 = 0;
	DOCH12 = 0; DOCH13 = 0; DOCH14 = 0; DOCH15 = 0;
}
