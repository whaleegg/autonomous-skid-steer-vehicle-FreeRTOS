/**********************************************************************************************************************
 * file Drivers.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef DRIVERS_H_
#define DRIVERS_H_

/*==================================================================*/
/* 1. Public Includes                         */
/* (App 계층에서 사용할 모든 드라이버의 헤더 파일을 포함)         */
/*==================================================================*/
#include "Asclin.h"
#include "Buzzer.h"
#include "can_bsp.h"
#include "Encoder.h"
#include "Gpt12.h"
#include "Gtm_Atom_Pwm.h"
#include "Isr_Priority.h"
#include "Led.h"
#include "motor_bsp.h"
#include "Stm.h"
#include "Button.h"
#include "ultrasonic_bsp.h"
// 기존 bsp.h의 내용(CPU_CLOCK_MHZ 등)도 여기에 포함

#include "App_Config.h"


/*==================================================================*/
/* 2. Public Functions                         */
/* (시스템 전체에서 사용할 공용 함수 선언)                */
/*==================================================================*/

/**
 * @brief 시스템의 모든 하드웨어 드라이버를 초기화하는 중앙 함수
 */
void System_Init(void);


#endif /* DRIVERS_H_ */
