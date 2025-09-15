/**********************************************************************************************************************
 * file led_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef LED_BSP_H_
#define LED_BSP_H_

#include <Drivers.h> // 경로 변경
#include <Gpt12.h> // 경로 변경
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"

// Function Prototypes
void Led_Init(void);
void Led_Set(unsigned char num_LED, unsigned char onOff);
void Led_Toggle(unsigned char num_LED);

#endif /* LED_BSP_H_ */
