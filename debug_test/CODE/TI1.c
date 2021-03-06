/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : TI1.c
**     Project   : debug_test
**     Processor : MC9S12XEP100MAL
**     Component : TimerInt
**     Version   : Component 02.159, Driver 01.21, CPU db: 3.00.035
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 08/01/2019, 10:00
**     Abstract  :
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings  :
**         Timer name                  : ECT_Counter (16-bit)
**         Compare name                : ECTTC0
**         Counter shared              : Yes
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 375000 Hz
**           Initial period/frequency
**             Xtal ticks              : 1600000
**             microseconds            : 100000
**             milliseconds            : 100
**             seconds (real)          : 0.1
**             Hz                      : 10
**
**         Runtime setting             : none
**
**         Initialization:
**              Timer                  : Disabled
**              Events                 : Enabled
**
**         Timer registers
**              Counter                : ECT_TCNT  [$0044]
**              Mode                   : ECT_TIOS  [$0040]
**              Run                    : ECT_TSCR1 [$0046]
**              Prescaler              : ECT_TSCR2 [$004D]
**
**         Compare registers
**              Compare                : ECT_TC0   [$0050]
**
**         Flip-flop registers
**              Mode                   : ECT_TCTL2 [$0049]
**     Contents  :
**         Enable  - byte TI1_Enable(void);
**         Disable - byte TI1_Disable(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE TI1. */

#include "Events.h"
#include "TI1.h"

#pragma DATA_SEG TI1_DATA              /* Select data segment "TI1_DATA" */
#pragma CODE_SEG TI1_CODE
#pragma CONST_SEG DEFAULT              /* Use default segment for constants */



/* Internal method prototypes */


/* End of Internal methods declarations */

/*
** ===================================================================
**     Method      :  TI1_Enable (component TimerInt)
**
**     Description :
**         This method enables the component - it starts the timer.
**         Events may be generated (<DisableEvent>/<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte TI1_Enable(void)
{
  ECT_TC0 = ECT_TCNT + 0x927CU;        /* Store new value to the compare register */ 
  ECT_TFLG1 = 0x01U;                   /* Reset interrupt request flag */ 
  ECT_TIE_C0I = 1U;                    /* Enable interrupt */ 
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  TI1_Disable (component TimerInt)
**
**     Description :
**         This method disables the component - it stops the timer. No
**         events will be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte TI1_Disable(void)

**      This method is implemented as a macro. See header module. **
*/

/*
** ===================================================================
**     Method      :  TI1_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED
ISR(TI1_Interrupt)
{
  ECT_TC0 += 0x927CU;                  /* Add value corresponding with period */
  ECT_TFLG1 = 0x01U;                   /* Reset interrupt request flag */
  TI1_OnInterrupt();                   /* Invoke user event */
}

#pragma CODE_SEG TI1_CODE

/* END TI1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
