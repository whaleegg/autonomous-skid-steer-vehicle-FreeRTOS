/**********************************************************************************************************************
 * file ultrasonic_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef ULTRASONIC_BSP_H_
#define ULTRASONIC_BSP_H_

#include <Isr_Priority.h> // 경로 변경
#include <Stm.h> // 경로 변경
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h" // 추가
#include "IfxPort.h" // 추가
#include "IfxCan.h" // 추가 (다른 BSP 파일에서 필요할 수 있으므로 포함)

// Function Prototypes
void Ultrasonic_Init(void);
void Ultrasonic_Echo_Init(void); // 추가
void Ultrasonic_Stm_Init_10us(void); // 추가
float Ultrasonic_Get_Back_Dist(void);
float Ultrasonic_Get_Left_Dist(void);
float Ultrasonic_Get_Right_Dist(void);

#endif /* ULTRASONIC_BSP_H_ */
