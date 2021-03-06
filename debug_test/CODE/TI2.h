/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : TI2.h
**     Project   : debug_test
**     Processor : MC9S12XEP100MAL
**     Component : TimerInt
**     Version   : Component 02.159, Driver 01.21, CPU db: 3.00.035
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 07/01/2019, 16:19
**     Abstract  :
**         This component "TimerInt" implements a periodic interrupt.
**         When the component and its events are enabled, the "OnInterrupt"
**         event is called periodically with the period that you specify.
**         TimerInt supports also changing the period in runtime.
**         The source of periodic interrupt can be timer compare or reload
**         register or timer-overflow interrupt (of free running counter).
**     Settings  :
**         Timer name                  : ECT_Counter (16-bit)
**         Compare name                : ECTTC1
**         Counter shared              : Yes
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 375000 Hz
**           Initial period/frequency
**             Xtal ticks              : 80000
**             microseconds            : 5000
**             milliseconds            : 5
**             seconds (real)          : 0.005
**             Hz                      : 200
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
**              Compare                : ECT_TC1   [$0052]
**
**         Flip-flop registers
**              Mode                   : ECT_TCTL2 [$0049]
**     Contents  :
**         Enable  - byte TI2_Enable(void);
**         Disable - byte TI2_Disable(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __TI2
#define __TI2

/* MODULE TI2. */

#include "Cpu.h"

#pragma CODE_SEG TI2_CODE


byte TI2_Enable(void);
/*
** ===================================================================
**     Method      :  TI2_Enable (component TimerInt)
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

#define TI2_Disable() ( \
  (ECT_TIE_C1I = 0U),                  /* Disable interrupt */ \
  ERR_OK                               /* Return result */ \
)
/*
** ===================================================================
**     Method      :  TI2_Disable (component TimerInt)
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

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void TI2_Interrupt(void);
/*
** ===================================================================
**     Method      :  TI2_Interrupt (component TimerInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END TI2. */

#endif /* ifndef __TI2 */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
