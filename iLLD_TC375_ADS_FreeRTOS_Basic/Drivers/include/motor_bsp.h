/**********************************************************************************************************************
 * file motor_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef MOTOR_BSP_H_
#define MOTOR_BSP_H_

#include <can_bsp.h>
#include <Gtm_Atom_Pwm.h>
#include <Isr_Priority.h>
#include <Stm.h>
#include "IfxCpu.h"
#include "Ifx_Types.h"
#include "Libraries/iLLD/TC37A/Tricore/Cpu/Std/Platform_Types.h"

// Function Prototypes
void Motor_Init(void);

void Motor_Set_Left(uint8 dir, uint8 duty);
void Motor_Stop_Left(void);

void Motor_Set_Right(uint8 dir, uint8 duty);
void Motor_Stop_Right(void);

#endif /* MOTOR_BSP_H_ */
