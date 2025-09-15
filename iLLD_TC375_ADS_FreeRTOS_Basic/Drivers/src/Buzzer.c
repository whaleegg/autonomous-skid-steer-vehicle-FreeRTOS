/**********************************************************************************************************************
 * file buzzer_bsp.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include <Buzzer.h>
#include <Gpt12.h> // 경로 변경

void Buzzer_Init ()
{
    MODULE_P23.IOCR4.B.PC5 = 0x10;
    MODULE_P23.OUT.B.P5 = 0; // off
}

static unsigned int BeepCnt = 0;
void Buzzer_Set_Cycle_Ms (int cycle)
{
    BeepCnt = cycle * 100;
}

void Buzzer_Always_On(void)
{
    MODULE_P23.OUT.B.P5 = 1;
}

void Buzzer_On (void)
{
     Gpt12_Run_Gpt1_T3();
}

void Buzzer_Off (void)
{
    Gpt12_Stop_Gpt1_T3();
    MODULE_P23.OUT.B.P5 = 0;
    BeepCnt = 0;
}

static volatile unsigned int g_Cnt10us = 0;

IFX_INTERRUPT(Buzzer_Gpt1_T3_Handler_Beep, 0, ISR_PRIORITY_GPT1T3_TIMER);
void Buzzer_Gpt1_T3_Handler_Beep (void) {
    g_Cnt10us++;
    if (g_Cnt10us >= BeepCnt) { //cycle = BeepCnt*10us
        MODULE_P23.OUT.B.P5 ^= 1;
        g_Cnt10us = 0;
    }
}
