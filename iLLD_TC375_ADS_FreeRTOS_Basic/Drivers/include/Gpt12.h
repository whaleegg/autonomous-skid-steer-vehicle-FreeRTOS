/**********************************************************************************************************************
 * file gpt12_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef GPT12_BSP_H_
#define GPT12_BSP_H_

#include <Led.h>
#include <Isr_Priority.h>
#include "IfxGpt12_reg.h"
#include "IfxGpt12_regdef.h"
#include "IfxSrc_regdef.h"
#include "IfxSrc_reg.h"
#include "CompilerTasking.h"
#include "Ifx_Types.h"
#include "IfxAsclin_reg.h"

// Function Prototypes
void Gpt12_Gpt1_Init(void);
void Gpt12_Gpt2_Init(void);
void Gpt12_Run_Gpt1_T3(void);
void Gpt12_Stop_Gpt1_T3(void);
void Gpt12_Run_Gpt2_T6(void);
void Gpt12_Stop_Gpt2_T6(void);

#endif /* GPT12_BSP_H_ */
