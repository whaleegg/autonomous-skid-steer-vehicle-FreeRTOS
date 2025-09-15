/**********************************************************************************************************************
 * file buzzer_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef BUZZER_BSP_H_
#define BUZZER_BSP_H_

#include <Gpt12.h>
#include <Isr_Priority.h>
#include "Ifx_reg.h"
#include "CompilerTasking.h"

#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 783
#define NOTE_A5 880
#define NOTE_B5 987
#define NOTE_C6 1046
#define NOTE_D6 1175
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_G6 1568
#define NOTE_A6 1760
#define NOTE_B6 1865

// Function Prototypes
void Buzzer_Init(void);
void Buzzer_Set_Cycle_Ms (int cycle);
void Buzzer_Always_On(void);
void Buzzer_On(void);
void Buzzer_Off(void);

#endif /* BUZZER_BSP_H_ */
