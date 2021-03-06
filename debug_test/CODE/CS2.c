/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : CS2.c
**     Project   : debug_test
**     Processor : MC9S12XEP100MAL
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.14, CPU db: 3.00.035
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 11/01/2019, 14:17
**     Abstract  :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       96            |  PS7_SS0
**             ----------------------------------------------------
**
**         Port name                   : S
**
**         Bit number (in port)        : 7
**         Bit mask of the port        : $0080
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 1
**         Initial pull option         : off
**
**         Port data register          : PTS       [$0248]
**         Port control register       : DDRS      [$024A]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool CS2_GetVal(void);
**         PutVal - void CS2_PutVal(bool Val);
**         ClrVal - void CS2_ClrVal(void);
**         SetVal - void CS2_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE CS2. */

#include "CS2.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG CS2_DATA              /* Select data segment "CS2_DATA" */
#pragma CODE_SEG CS2_CODE
#pragma CONST_SEG CS2_CONST            /* Constant section for this module */
/*
** ===================================================================
**     Method      :  CS2_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool CS2_GetVal(void)

**  This method is implemented as a macro. See CS2.h file.  **
*/

/*
** ===================================================================
**     Method      :  CS2_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void CS2_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PTS, 0x80U);           /* PTS7=0x01U */
  } else { /* !Val */
    clrReg8Bits(PTS, 0x80U);           /* PTS7=0x00U */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  CS2_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void CS2_ClrVal(void)

**  This method is implemented as a macro. See CS2.h file.  **
*/

/*
** ===================================================================
**     Method      :  CS2_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void CS2_SetVal(void)

**  This method is implemented as a macro. See CS2.h file.  **
*/


/* END CS2. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
