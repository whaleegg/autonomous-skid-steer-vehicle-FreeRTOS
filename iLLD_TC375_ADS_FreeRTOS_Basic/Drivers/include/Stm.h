/**********************************************************************************************************************
 * file stm_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef STM_BSP_H_
#define STM_BSP_H_

#include "Ifx_Types.h"
#include "IfxCpu.h"

#define CPU_CLOCK_MHZ 100

uint64 Stm_Get_Tick(void);
uint64 Stm_Get_Time_Us(void);
uint64 Stm_Get_Time_Ms(void);

#endif /* STM_BSP_H_ */