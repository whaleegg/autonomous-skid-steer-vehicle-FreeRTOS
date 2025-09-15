/**********************************************************************************************************************
 * file gpt12_bsp.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include <Gpt12.h>

/* Buzzer */
void Gpt12_Gpt1_Init(void){
    //use CPU1 !!!! can't use CPU0;
    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());//DISR비트가 보호되고 있어서 watch dog time를 꺼야함.
    MODULE_GPT120.CLC.U = 0; //DISR enable설정
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());

    //T3 Timer
    MODULE_GPT120.T3CON.B.T3M = 0x0; //set timer mode
    MODULE_GPT120.T3CON.B.T3I = 0x0; //prescaler 4
    MODULE_GPT120.T3CON.B.BPS1 = 0x1;
    MODULE_GPT120.T3CON.B.T3UD = 0x1; //direction : count down
    MODULE_GPT120.T3.U = 250u; //25MHz이므로 10us마다 발생할 것.

    //T2 Timer
    MODULE_GPT120.T2CON.B.T2M = 0x4; //set reload mode. //Part2M, p30-15
    MODULE_GPT120.T2CON.B.T2I = 0x7; //reload input mode ; Any(rising/falling) edge T3OTL; Table220
    MODULE_GPT120.T2.U = 250u;

    /* Interrupt Initialization */
    MODULE_SRC.GPT12.GPT12[0].T3.B.SRPN = ISR_PRIORITY_GPT1T3_TIMER; //interrupt priority set
    MODULE_SRC.GPT12.GPT12[0].T3.B.CLRR = 1; //clear request
    MODULE_SRC.GPT12.GPT12[0].T3.B.TOS = 0; //cpu1 (from part1 M p16-5)
    MODULE_SRC.GPT12.GPT12[0].T3.B.SRE = 1; //interrupt enable
}

void Gpt12_Run_Gpt1_T3(void){
    MODULE_GPT120.T3.U =  250u;
    MODULE_GPT120.T3CON.B.T3R = 1;
}
void Gpt12_Stop_Gpt1_T3(void){
    MODULE_GPT120.T3CON.B.T3R = 0;
}

/* LED */
void Gpt12_Gpt2_Init(void){

    //part2 p30-58 default값이 003으로 초기화되서 0으로 설정해야 gpt12 모듈에 클럭 들어가고 동작을 시작함.
    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());//DISR비트가 보호되고 있어서 watch dog time를 꺼야함.
    MODULE_GPT120.CLC.U = 0; //DISR enable설정
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());

    MODULE_GPT120.T6CON.B.T6M = 0x0; //set timer mode (p30-48)
    //prescaler set 4 (ref Table 227, part2 M p30-52) ==> CPU 100MHz일떄 타이머 입력클럭 100/4=25MHz
    MODULE_GPT120.T6CON.B.BPS2= 0x0; //prescaler parameter
    MODULE_GPT120.T6CON.B.T6I = 0x0; //prescaler parameter
    MODULE_GPT120.T6CON.B.T6UD = 0x1; //config: count down
    //아마 T6CON.B.T6UDE =0인듯? t6UD에 따라 방향 결정하고 EUD는 연결안됨.

    MODULE_GPT120.T6CON.B.T6OE = 0x1; //overflow/under flow output enable
    MODULE_GPT120.T6CON.B.T6SR = 0x1; //reload from register CAPREL enabled

    MODULE_GPT120.T6.U = 250u; //25MHz이므로 10us마다 발생할 것.

    MODULE_GPT120.CAPREL.U = 250u; //set CAPREL reload value

    /* Interrupt Initialization */
    MODULE_SRC.GPT12.GPT12[0].T6.B.SRPN = ISR_PRIORITY_GPT2T6_TIMER;
    MODULE_SRC.GPT12.GPT12[0].T6.B.TOS = 0;
    MODULE_SRC.GPT12.GPT12[0].T6.B.CLRR = 1;
    MODULE_SRC.GPT12.GPT12[0].T6.B.SRE  = 1;
}

void Gpt12_Run_Gpt2_T6(void){
    MODULE_GPT120.T6.U = 250u;
    MODULE_GPT120.T6CON.B.T6R = 1;
}
void Gpt12_Stop_Gpt2_T6(void){
    MODULE_GPT120.T6CON.B.T6R = 0;
}
