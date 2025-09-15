/**********************************************************************************************************************
 * file encoder_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef ENCODER_BSP_H_
#define ENCODER_BSP_H_

#include <can_bsp.h>
#include <Isr_Priority.h>
#include <Stm.h>
#include "IfxPort_reg.h"
#include "IfxScu_reg.h"
#include "IfxSrc_reg.h"
#include "IfxCpu.h"
#include "Platform_Types.h"

// Function Prototypes
int Encoder_Get_Rpm0_Left(void);
int Encoder_Get_Rpm1_Right(void);

void Encoder_Init(void);
//void Encoder_Init_Stm_100ms(void);

#endif /* ENCODER_BSP_H_ */
