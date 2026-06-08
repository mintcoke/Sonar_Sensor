/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
\addtogroup TR8253 EVB Platform (Serial ESC Access)
@{
*/

/**
\file    TR8253Evb.c
\author EthercatSSC@beckhoff.com
\brief Implementation

\version 5.12
*/


/*--------------------------------------------------------------------------------------
------
------    Includes
------
--------------------------------------------------------------------------------------*/
#include "ecat_def.h"

#include "ecatslv.h"


#define    _TR8253EVB_ 1
#include "TR8253Evb.h"
#undef    _TR8253EVB_
/*remove definition of _TR8253EVB_ (#ifdef is used in TR8253Evb.h)*/

#include "ecatappl.h"
#include "ecat_api.h"
#include "stm32f4xx_hal.h"
#include "spi.h"
#include "tim.h"

/*--------------------------------------------------------------------------------------
------
------    internal Types and Defines
------
--------------------------------------------------------------------------------------*/

typedef union
{
    unsigned short    Word;
    unsigned char    Byte[2];
} UBYTETOWORD;

typedef union 
{
    UINT8           Byte[2];
    UINT16          Word;
}
UALEVENT;

/*-----------------------------------------------------------------------------------------
------
------    SPI defines/macros
------
-----------------------------------------------------------------------------------------*/
#define SELECT_SPI          HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET)//{SPI1_CS_L();}
#define DESELECT_SPI        HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET);//{SPI1_CS_H();}
#define SPI_Init()          MX_SPI1_Init()

/*-----------------------------------------------------------------------------------------
------
------    Global Interrupt setting
------
-----------------------------------------------------------------------------------------*/

#define DISABLE_GLOBAL_INT            __disable_irq()
#define ENABLE_GLOBAL_INT            __enable_irq()

#define    DISABLE_AL_EVENT_INT        DISABLE_GLOBAL_INT
#define    ENABLE_AL_EVENT_INT            ENABLE_GLOBAL_INT


/*-----------------------------------------------------------------------------------------
------
------    ESC Interrupt
------
-----------------------------------------------------------------------------------------*/

#define    INIT_ESC_INT               {ESC_INT_Init();} //highest priority
//#define    EscIsr                    EXTI2_IRQHandler // primary interrupt vector name
#define    ACK_ESC_INT         __HAL_GPIO_EXTI_CLEAR_IT(ESC_INT_Pin)//{EXTI_ClearITPendingBit(INT_EXTI_X);}//clear LINE0 interrupt flag


/*-----------------------------------------------------------------------------------------
------
------    SYNC0 Interrupt
------
-----------------------------------------------------------------------------------------*/

#ifdef DC_SUPPORTED
//ESC_SYNC0

#define    INIT_SYNC0_INT                   {SYNC0_INT_Init();} //highest priority
#define    Sync0Isr                        EXTI0_IRQHandler // primary interrupt vector name
#define    SYNC0_IRQn      	    EXTI0_IRQn
#define    DISABLE_SYNC0_INT                {NVIC_DisableIRQ(SYNC0_IRQn);}//disable interrupt source INT3
#define    ENABLE_SYNC0_INT                {NVIC_EnableIRQ(SYNC0_IRQn);} //enable interrupt source INT3
#define    ACK_SYNC0_INT         __HAL_GPIO_EXTI_CLEAR_IT(ESC_SYNC0_Pin)//{EXTI_ClearITPendingBit(SYNC0_EXTI_X);}// clear LINE0 interrupt flag  

 
//ESC_SYNC1  
#define    INIT_SYNC1_INT                   {SYNC1_INT_Init();} //highest priority
#define    Sync1Isr                         // primary interrupt vector name
#define    SYNC1_IRQn      	  EXTI1_IRQn
#define    DISABLE_SYNC1_INT                {NVIC_DisableIRQ(SYNC1_IRQn);}//disable interrupt source INT3
#define    ENABLE_SYNC1_INT                {NVIC_EnableIRQ(SYNC1_IRQn);} //enable interrupt source INT3
#define    ACK_SYNC1_INT       //{exti_flag_clear(SYNC1_EXTI_X);}
#endif // DC_SUPPORTED


/*-----------------------------------------------------------------------------------------
------
------    Hardware timer
------
-----------------------------------------------------------------------------------------*/


#define TIMER_INTERVAL      1 // ms

#define INIT_ECAT_TIMER     MX_TIM3_Init()

#define STOP_ECAT_TIMER     HAL_TIM_Base_Stop(&htim3); /*disable timer*/

#define START_ECAT_TIMER    HAL_TIM_Base_Start(&htim3); /*enable timer*/

/*******************************************************************************
    Function:
        UINT16 PDI_GetTimer(void)

    Summary:
        Get the 1ms current timer value
    Description:
        This routine gets the 1ms current timer value.
*******************************************************************************/
UINT16 PDI_GetTimer()
{
  return (__HAL_TIM_GET_COUNTER(&htim3));
}

/*******************************************************************************
    Function:
        void PDI_ClearTimer(void)

    Summary:
        Clear the 1ms current timer value
    Description:
        This routine clears the 1ms current timer value.
*******************************************************************************/
void PDI_ClearTimer(void)
{
  __HAL_TIM_SET_COUNTER(&htim3, 0);
}

/*-----------------------------------------------------------------------------------------
------
------    Configuration Bits
------
-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------
------
------    LED defines
------
-----------------------------------------------------------------------------------------*/
// EtherCAT Status LEDs -> StateMachine
// #define LED_ECATGREEN                 LATFbits.LATF1
// #define LED_ECATRED                    LATFbits.LATF0

/*--------------------------------------------------------------------------------------
------
------    internal Variables
------
--------------------------------------------------------------------------------------*/
UALEVENT         EscALEvent;            //contains the content of the ALEvent register (0x220), this variable is updated on each Access to the Esc
/*--------------------------------------------------------------------------------------
------
------    internal functions
------
--------------------------------------------------------------------------------------*/

// External interrupt initialization
void ESC_INT_Init(void)
{
	// This interrupt has already defined in function MX_GPIO_Init()
	
//  GPIO_InitTypeDef GPIO_InitStruct = {0};

//  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOA_CLK_ENABLE();

//  /*Configure GPIO pins : ESC_SYNC0_Pin ESC_INT_Pin */
//  GPIO_InitStruct.Pin = ESC_INT_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
//  GPIO_InitStruct.Pull = GPIO_PULLUP;
//  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


//  /* EXTI interrupt init*/
//  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
//  HAL_NVIC_EnableIRQ(EXTI0_IRQn);	
}

#ifdef DC_SUPPORTED


// External interrupt initialization
void SYNC0_INT_Init(void)
{
	// This interrupt has already defined in function MX_GPIO_Init()
		
//  GPIO_InitTypeDef GPIO_InitStruct = {0};

//  /* GPIO Ports Clock Enable */
//  __HAL_RCC_GPIOA_CLK_ENABLE();

//  /*Configure GPIO pins : ESC_SYNC0_Pin ESC_INT_Pin */
//  GPIO_InitStruct.Pin = ESC_SYNC0_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
//  GPIO_InitStruct.Pull = GPIO_PULLUP;
//  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


//  /* EXTI interrupt init*/
//  HAL_NVIC_SetPriority(EXTI2_IRQn, 1, 0);
//  HAL_NVIC_EnableIRQ(EXTI2_IRQn);		
}

void SYNC1_INT_Init(void)
{
	;
}
#endif

/*ECATCHANGE_START(V5.12) TR8253Evb 1*/
static UINT8 RxTxSpiData(UINT8 MosiByte)
{
    uint32_t timeout;

    /* 确保SPI已启用: HAL_SPI_Init不设SPE位, 直接操作寄存器需手动启用 */
    if ((SPI1->CR1 & SPI_CR1_SPE) == 0)
    {
        SPI1->CR1 |= SPI_CR1_SPE;
    }

    timeout = 100000;
    while ((SPI1->SR & SPI_FLAG_TXE) == RESET)
    {
        if (--timeout == 0) return 0; /* SPI硬件异常, 超时退出 */
    }
    SPI1->DR = MosiByte;

    timeout = 100000;
    while ((SPI1->SR & SPI_FLAG_RXNE) == RESET)
    {
        if (--timeout == 0) return 0; /* ESC未响应, 超时退出 */
    }
    return SPI1->DR;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Command    ESC_WR performs a write access; ESC_RD performs a read access.

 \brief The function addresses the EtherCAT ASIC via SPI for a following SPI access.
*////////////////////////////////////////////////////////////////////////////////////////
static void AddressingEsc( UINT16 Address, UINT8 Command )
{
    VARVOLATILE UBYTETOWORD tmp;
    tmp.Word = ( Address << 3 ) | Command;



    /* select the SPI */
    SELECT_SPI;

    /* send the first address/command byte to the ESC 
       receive the first AL Event Byte*/
    EscALEvent.Byte[0] = RxTxSpiData(tmp.Byte[1]);

    EscALEvent.Byte[1] = RxTxSpiData(tmp.Byte[0]);
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief  The function operates a SPI access without addressing.

        The first two bytes of an access to the EtherCAT ASIC always deliver the AL_Event register (0x220).
        It will be saved in the global "EscALEvent"
*////////////////////////////////////////////////////////////////////////////////////////
static void GetInterruptRegister(void)
{
    VARVOLATILE UINT8            dummy;
    HW_EscRead((MEM_ADDR *)&dummy, 0, 1);
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief  The function operates a SPI access without addressing.
        Shall be implemented if interrupts are supported else this function is equal to "GetInterruptRegsiter()"

        The first two bytes of an access to the EtherCAT ASIC always deliver the AL_Event register (0x220).
        It will be saved in the global "EscALEvent"
*////////////////////////////////////////////////////////////////////////////////////////
static void ISR_GetInterruptRegister(void)
{
    VARVOLATILE UINT8 dummy;
    HW_EscReadIsr((MEM_ADDR *)&dummy, 0, 1);
}
/*ECATCHANGE_END(V5.12) EL9800 1*/

/*--------------------------------------------------------------------------------------
------
------    exported hardware access functions
------
--------------------------------------------------------------------------------------*/


/////////////////////////////////////////////////////////////////////////////////////////
/**
\return     0 if initialization was successful

 \brief    This function intialize the Process Data Interface (PDI) and the host controller.
*////////////////////////////////////////////////////////////////////////////////////////
UINT8 HW_Init(void)
{
    UINT32 intMask;

    SPI_Init();
    DESELECT_SPI;   // 确保片选初始为高

    {
        int retry = 0;
        do
        {
            intMask = 0x93;
            HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);
            intMask = 0;
            HW_EscReadDWord(intMask, ESC_AL_EVENTMASK_OFFSET);
            if (++retry > 1000) return 1;   // 超时退出, 不卡死
        } while (intMask != 0x93);
    }

    intMask = 0x00;

    HW_EscWriteDWord(intMask, ESC_AL_EVENTMASK_OFFSET);
		
    INIT_ESC_INT
    ENABLE_ESC_INT();

    INIT_SYNC0_INT
    INIT_SYNC1_INT

    ENABLE_SYNC0_INT;
    ENABLE_SYNC1_INT;

    INIT_ECAT_TIMER;
    START_ECAT_TIMER;

    /* enable all interrupts */
    ENABLE_GLOBAL_INT;

    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    This function shall be implemented if hardware resources need to be release
        when the sample application stops
*////////////////////////////////////////////////////////////////////////////////////////
void HW_Release(void)
{
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    first two Bytes of ALEvent register (0x220)

 \brief  This function gets the current content of ALEvent register
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 HW_GetALEventRegister(void)
{
    GetInterruptRegister();
    return EscALEvent.Word;
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \return    first two Bytes of ALEvent register (0x220)

 \brief  The SPI PDI requires an extra ESC read access functions from interrupts service routines.
        The behaviour is equal to "HW_GetALEventRegister()"
*////////////////////////////////////////////////////////////////////////////////////////
UINT16 HW_GetALEventRegister_Isr(void)
{
     ISR_GetInterruptRegister();
    return EscALEvent.Word;
}


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param RunLed            desired EtherCAT Run led state
 \param ErrLed            desired EtherCAT Error led state

  \brief    This function updates the EtherCAT run and error led
*////////////////////////////////////////////////////////////////////////////////////////
// void HW_SetLed(UINT8 RunLed,UINT8 ErrLed)
// {
      // LED_ECATGREEN = RunLed;
      // LED_ECATRED   = ErrLed;
// }

/*ECATCHANGE_START(V5.12) EL9800 1*/
/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param pData        Pointer to a byte array which holds data to write or saves read data.
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Len            Access size in Bytes.

 \brief  This function operates the SPI read access to the EtherCAT ASIC.
*////////////////////////////////////////////////////////////////////////////////////////
void HW_EscRead( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
    /* HBu 24.01.06: if the SPI will be read by an interrupt routine too the
                     mailbox reading may be interrupted but an interrupted
                     reading will remain in a SPI transmission fault that will
                     reset the internal Sync Manager status. Therefore the reading
                     will be divided in 1-byte reads with disabled interrupt */
    UINT16 i = Len;
    UINT8 *pTmpData = (UINT8 *)pData;

    /* loop for all bytes to be read */
    while ( i-- > 0 )
    {
/*ECATCHANGE_START(V5.12) EL9800 1*/
        /* the reading of data from the ESC can be interrupted by the
           AL Event ISR, in that case the address has to be reinitialized,
           in that case the status flag will indicate an error because
           the reading operation was interrupted without setting the last
           sent byte to 0xFF */
        DISABLE_GLOBAL_INT;
/*ECATCHANGE_END(V5.12) EL9800 1*/

         AddressingEsc( Address, ESC_RD );

         /*Each Byte will be read with a new addressing phase so the out data is 0xFF*/
         *pTmpData = RxTxSpiData(0xFF);
         
         pTmpData++;


/*ECATCHANGE_START(V5.12) EL9800 1*/        

        /* there has to be at least 15 ns + CLK/2 after the transmission is finished
           before the SPI1_SEL signal shall be 1 */
        DESELECT_SPI

        ENABLE_GLOBAL_INT;
/*ECATCHANGE_END(V5.12) EL9800 1*/

        /* next address */
        Address++;

    }
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param pData        Pointer to a byte array which holds data to write or saves read data.
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Len            Access size in Bytes.

\brief  The SPI PDI requires an extra ESC read access functions from interrupts service routines.
        The behaviour is equal to "HW_EscRead()"
*////////////////////////////////////////////////////////////////////////////////////////
void HW_EscReadIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
    UINT16 i = Len;
    UINT8 data = 0;

   UINT8 *pTmpData = (UINT8 *)pData;

    /* send the address and command to the ESC */
     AddressingEsc( Address, ESC_RD );

    /* loop for all bytes to be read */
    while ( i-- > 0 )
    {
        if ( i == 0 )
        {
            /* when reading the last byte the DI pin shall be 1 */
            data = 0xFF;
        }

        *pTmpData = RxTxSpiData(data);

        pTmpData++;
    }
    
    /* there has to be at least 15 ns + CLK/2 after the transmission is finished
       before the SPI1_SEL signal shall be 1 */
    DESELECT_SPI
}

/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param pData        Pointer to a byte array which holds data to write or saves write data.
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Len            Access size in Bytes.

  \brief  This function operates the SPI write access to the EtherCAT ASIC.
*////////////////////////////////////////////////////////////////////////////////////////
void HW_EscWrite( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
    UINT16 i = Len;
    VARVOLATILE UINT8 dummy;

    UINT8 *pTmpData = (UINT8 *)pData;

    /* loop for all bytes to be written */
    while ( i-- > 0 )
    {
/*ECATCHANGE_START(V5.12) EL9800 1*/
        /* the reading of data from the ESC can be interrupted by the
           AL Event ISR, so every byte will be written separate */
        DISABLE_GLOBAL_INT;
/*ECATCHANGE_END(V5.12) EL9800 1*/

        /* HBu 24.01.06: wrong parameter ESC_RD */
         AddressingEsc( Address, ESC_WR );

         dummy = RxTxSpiData(*pTmpData);
         pTmpData++;

/*ECATCHANGE_START(V5.12) EL9800 1*/

        /* there has to be at least 15 ns + CLK/2 after the transmission is finished
           before the SPI1_SEL signal shall be 1 */

        DESELECT_SPI


        ENABLE_GLOBAL_INT;
/*ECATCHANGE_END(V5.12) EL9800 1*/

        /* next address */
        Address++;


    }
}


/////////////////////////////////////////////////////////////////////////////////////////
/**
 \param pData        Pointer to a byte array which holds data to write or saves write data.
 \param Address     EtherCAT ASIC address ( upper limit is 0x1FFF )    for access.
 \param Len            Access size in Bytes.

 \brief  The SPI PDI requires an extra ESC write access functions from interrupts service routines.
        The behaviour is equal to "HW_EscWrite()"
*////////////////////////////////////////////////////////////////////////////////////////
void HW_EscWriteIsr( MEM_ADDR *pData, UINT16 Address, UINT16 Len )
{
    UINT16 i = Len;
    VARVOLATILE UINT16 dummy;
    UINT8 *pTmpData = (UINT8 *)pData;

    /* send the address and command to the ESC */
     AddressingEsc( Address, ESC_WR );
     /* loop for all bytes to be written */
    while ( i-- > 0 )
    {

         dummy = RxTxSpiData(*pTmpData);
         pTmpData++;
    }

    /* there has to be at least 15 ns + CLK/2 after the transmission is finished
       before the SPI1_SEL signal shall be 1 */
    DESELECT_SPI
}
/*ECATCHANGE_END(V5.12) EL9800 1*/




/////////////////////////////////////////////////////////////////////////////////////////
/**
 \brief    Interrupt service routine for the PDI interrupt from the EtherCAT Slave Controller
*////////////////////////////////////////////////////////////////////////////////////////
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin==ESC_INT_Pin)
  {		
     PDI_Isr();
     /* reset the interrupt flag */
		 ACK_ESC_INT; 		
		 return;
	}
  else if(GPIO_Pin==ESC_SYNC0_Pin)
  {	
     Sync0_Isr();
     /* reset the interrupt flag */

     ACK_SYNC0_INT;		
		 return;
	}	
}
/** @} */
