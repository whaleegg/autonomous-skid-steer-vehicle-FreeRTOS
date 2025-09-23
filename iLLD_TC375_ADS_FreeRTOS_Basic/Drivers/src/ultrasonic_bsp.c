/**********************************************************************************************************************
 * file ultrasonic_bsp.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 ***********************************************************************************************************************/
#include <Drivers.h> // CPU_CLOCK_MHZ 사용을 위해 추가
#include <Stm.h> // Stm_Get_Time_Us() 사용을 위해 추가
#include <ultrasonic_bsp.h>
#include "App/include/ultrasonic_task.h"

void Ultrasonic_Echo_Init(void);
void Ultrasonic_Stm_Init_10us(void);

// static volatile unsigned int stm0_cnt = 0; // This is now local to vUltrasonicTriggerTask
// The start_... variables are moved to the processing task.
// The dist_... variables are now owned by the processing task, but declared here
// so other modules can access them via the getter functions.
volatile float dist_back = (float)0;
volatile float dist_left = (float)0;
volatile float dist_right = (float)0;

float Ultrasonic_Get_Back_Dist(void) {
    return dist_back;
}

float Ultrasonic_Get_Left_Dist(void) {
    return dist_left;
}

float Ultrasonic_Get_Right_Dist(void) {
    return dist_right;
}

void Ultrasonic_Init(void) {
    // Back
    MODULE_P10.IOCR4.B.PC4 = 0x10;  // trig
    MODULE_P02.IOCR0.B.PC0 = 0x02;  // echo: EICR1.EXIS1.2

    // Left
    MODULE_P15.IOCR4.B.PC7 = 0x10;  // trig
    MODULE_P15.IOCR8.B.PC8 = 0x02;  // echo: EICR2.EXIS1.0

    // Right
    MODULE_P15.IOCR0.B.PC0 = 0x10;  // trig
    MODULE_P15.IOCR0.B.PC1 = 0x02;  // echo: EICR3.EXIS1.2

    Ultrasonic_Echo_Init();

    MODULE_P10.OUT.B.P4 = 1;        // Back trig on

    Ultrasonic_Stm_Init_10us();
}

void Ultrasonic_Echo_Init(void) {
    uint16 pw = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(pw);

    // EICR1.EXIS1.2 -> OGU2 (Back sensor on P02.0)
    MODULE_SCU.EICR[1].B.EXIS1 = 2;
    MODULE_SCU.EICR[1].B.REN1 = 1;
    MODULE_SCU.EICR[1].B.FEN1 = 1;
    MODULE_SCU.EICR[1].B.EIEN1 = 1;
    MODULE_SCU.EICR[1].B.INP1 = 2;

    // EICR2.EXIS1.0 -> OGU2 (Left sensor on P15.8)
    MODULE_SCU.EICR[2].B.EXIS1 = 0;
    MODULE_SCU.EICR[2].B.REN1 = 1;
    MODULE_SCU.EICR[2].B.FEN1 = 1;
    MODULE_SCU.EICR[2].B.EIEN1 = 1;
    MODULE_SCU.EICR[2].B.INP1 = 2;

    // EICR3.EXIS1.2 -> OGU2 (Right sensor on P15.1)
    MODULE_SCU.EICR[3].B.EXIS1 = 2;
    MODULE_SCU.EICR[3].B.REN1 = 1;
    MODULE_SCU.EICR[3].B.FEN1 = 1;
    MODULE_SCU.EICR[3].B.EIEN1 = 1;
    MODULE_SCU.EICR[3].B.INP1 = 2;

    MODULE_SCU.IGCR[1].B.IGP0 = 1;  // OGU2 -> SCUERU2

    // set SCUERU2
    MODULE_SRC.SCU.SCUERU[2].B.SRPN = ISR_PRIORITY_ERU2;
    MODULE_SRC.SCU.SCUERU[2].B.TOS = 0;
    MODULE_SRC.SCU.SCUERU[2].B.CLRR = 1;
    MODULE_SRC.SCU.SCUERU[2].B.SRE = 1;

    IfxScuWdt_setSafetyEndinitInline(pw);
}

void Ultrasonic_Stm_Init_10us(void) {
    MODULE_STM0.CMCON.B.MSIZE0 = 31;
    MODULE_STM0.CMCON.B.MSTART0 = 0;
    MODULE_STM0.ICR.B.CMP0OS = 0;

    MODULE_SRC.STM.STM[0].SR[0].B.TOS = 0;
    MODULE_SRC.STM.STM[0].SR[0].B.SRPN = ISR_PRIORITY_STM0;
    MODULE_STM0.CMP[0].U = (unsigned int)((MODULE_STM0.TIM0.U | ((uint64)MODULE_STM0.CAP.U << 32)) + 10*CPU_CLOCK_MHZ);
}

IFX_INTERRUPT(Ultrasonic_Stm0_Isr_Handler, 0, ISR_PRIORITY_STM0);
IFX_INTERRUPT(Ultrasonic_Eru2_Isr_Handler, 0, ISR_PRIORITY_ERU2);

void Ultrasonic_Stm0_Isr_Handler(void) {
    // Reset the timer for the next interrupt
    MODULE_STM0.CMP[0].U = (unsigned int)((MODULE_STM0.TIM0.U | ((uint64)MODULE_STM0.CAP.U << 32)) + 10*CPU_CLOCK_MHZ);

    // Give the semaphore to unblock the trigger task
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(xUltrasonicTriggerSemaphore, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void Ultrasonic_Eru2_Isr_Handler(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    UltrasonicMessage_t msg;
    msg.timestamp = Stm_Get_Tick();

    // Check which sensor triggered the interrupt and send a message
    if (MODULE_SCU.EIFR.B.INTF3) { // Back sensor
        msg.sensor = SENSOR_BACK;
        msg.pin_state = MODULE_P02.IN.B.P0;
        xQueueSendFromISR(xUltrasonicQueue, &msg, &xHigherPriorityTaskWoken);
        MODULE_SCU.FMR.B.FC3 = 1; // Clear interrupt flag
    } else if (MODULE_SCU.EIFR.B.INTF5) { // Left sensor
        msg.sensor = SENSOR_LEFT;
        msg.pin_state = MODULE_P15.IN.B.P8;
        xQueueSendFromISR(xUltrasonicQueue, &msg, &xHigherPriorityTaskWoken);
        MODULE_SCU.FMR.B.FC5 = 1; // Clear interrupt flag
    } else if (MODULE_SCU.EIFR.B.INTF7) { // Right sensor
        msg.sensor = SENSOR_RIGHT;
        msg.pin_state = MODULE_P15.IN.B.P1;
        xQueueSendFromISR(xUltrasonicQueue, &msg, &xHigherPriorityTaskWoken);
        MODULE_SCU.FMR.B.FC7 = 1; // Clear interrupt flag
    }

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}