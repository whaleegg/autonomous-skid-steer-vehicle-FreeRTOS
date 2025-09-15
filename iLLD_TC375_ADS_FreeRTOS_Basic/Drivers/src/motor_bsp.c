/**********************************************************************************************************************
 * file motor_bsp.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include <can_bsp.h> // Can_Get_Aeb() 사용을 위해 추가
#include <Gtm_Atom_Pwm.h> // Gtm_Atom_Pwm_Init(), Gtm_Atom_Pwm_Set_Duty_Cycle_A/B() 사용을 위해 추가
#include <motor_bsp.h>

/*
chA → Left Motor Control
chB → Right Motor Control
 */

void Motor_Init(void) {
    MODULE_P10.IOCR0.B.PC1 = 0x10;  // chA: initialize direction
    MODULE_P02.IOCR4.B.PC7 = 0x10;  // chA: initialize brake

    MODULE_P10.IOCR0.B.PC2 = 0x10;  // chB: initialize direction
    MODULE_P02.IOCR4.B.PC6 = 0x10;  // chB: initialize brake

    MODULE_P02.OUT.B.P7 = 1;        // chA: set brake
    MODULE_P02.OUT.B.P6 = 1;        // chB: set brake

    MODULE_P10.OUT.B.P1 = 1;        // chA: set direction
    MODULE_P10.OUT.B.P2 = 1;        // chB: set direction

    Gtm_Atom_Pwm_Init();

    Gtm_Atom_Pwm_Set_Duty_Cycle_A(0); //duty rate 0~255
    Gtm_Atom_Pwm_Set_Duty_Cycle_B(0);
}

void Motor_Set_Left(uint8 dir, uint8 duty) {
    if (Can_Get_Aeb() && dir) {
            return;
    }

    if (MODULE_P02.OUT.B.P7 == 0) {
        if (MODULE_P10.OUT.B.P1 != dir) {
            Motor_Stop_Left();
            MODULE_P10.OUT.B.P1 = dir;
            MODULE_P02.OUT.B.P7 = 0;
        }
    } else {
        MODULE_P10.OUT.B.P1 = dir;
        MODULE_P02.OUT.B.P7 = 0;
    }
    Gtm_Atom_Pwm_Set_Duty_Cycle_A((uint32)(duty*3.92157));
}

void Motor_Stop_Left(void) {
    MODULE_P02.OUT.B.P7 = 1;
    MODULE_P10.OUT.B.P1 = 1;
}

void Motor_Set_Right(uint8 dir, uint8 duty) {
    if (Can_Get_Aeb() && dir) {
            return;
    }

    if (MODULE_P02.OUT.B.P6 == 0) {
        if (MODULE_P10.OUT.B.P2 != dir) {
            Motor_Stop_Right();
            MODULE_P10.OUT.B.P2 = dir;
            MODULE_P02.OUT.B.P6 = 0;
        }
    } else {
        MODULE_P10.OUT.B.P2 = dir;
        MODULE_P02.OUT.B.P6 = 0;
    }
    Gtm_Atom_Pwm_Set_Duty_Cycle_B((uint32)(duty*3.92157));
}

void Motor_Stop_Right(void) {
    MODULE_P02.OUT.B.P6 = 1;
    MODULE_P10.OUT.B.P2 = 1;
}
