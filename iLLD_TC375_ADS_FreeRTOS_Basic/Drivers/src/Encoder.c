/**********************************************************************************************************************
 * file encoder_bsp.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include <can_bsp.h> // Can_Send_Msg() 사용을 위해 추가
#include <Drivers.h> // CPU_CLOCK_MHZ 사용을 위해 추가
#include <Encoder.h>
#include <Stm.h> // Stm_Get_Time_Us() 사용을 위해 추가
#include "IfxSrc.h"
#include "IfxSrc_reg.h"


volatile uint8 lastStatus_enc0 = 0;
volatile uint64 prev_enc0 = 0;
volatile uint64 intCnt_enc0 = 0;
volatile uint64 diffSum_enc0 = 0;

volatile uint8 lastStatus_enc1 = 0;
volatile uint64 prev_enc1 = 0;
volatile uint64 intCnt_enc1 = 0;
volatile uint64 diffSum_enc1 = 0;

volatile int rpm0 = 0;
volatile int rpm1 = 0;

int Encoder_Get_Rpm0_Left(void) {
    return rpm0;
}

int Encoder_Get_Rpm1_Right(void) {
    return rpm1;
}

void Encoder_Init(void) {
    MODULE_P15.IOCR4.B.PC4 = 0x02;  // input: EICR0.EXIS0.0
    MODULE_P33.IOCR4.B.PC7 = 0x02;  // input: EICR2.EXIS0.0
    uint16 pw = IfxScuWdt_getSafetyWatchdogPasswordInline();
    IfxScuWdt_clearSafetyEndinitInline(pw);

    // EICR0.EXIS0.0 -> OGU0
    MODULE_SCU.EICR[0].B.EXIS0 = 0;
    MODULE_SCU.EICR[0].B.REN0 = 1;
    MODULE_SCU.EICR[0].B.FEN0 = 1;
    MODULE_SCU.EICR[0].B.EIEN0 = 1;
    MODULE_SCU.EICR[0].B.INP0 = 0;

    MODULE_SCU.IGCR[0].B.IGP0 = 1;  // OGU0 -> SCUERU0

    // set SCUERU0
    MODULE_SRC.SCU.SCUERU[0].B.SRPN = ISR_PRIORITY_ERU0;
    MODULE_SRC.SCU.SCUERU[0].B.TOS = 0;
    MODULE_SRC.SCU.SCUERU[0].B.CLRR = 1;
    MODULE_SRC.SCU.SCUERU[0].B.SRE = 1;

    // EICR2.EXIS0.0 -> OGU1
    MODULE_SCU.EICR[2].B.EXIS0 = 0;
    MODULE_SCU.EICR[2].B.REN0 = 1;
    MODULE_SCU.EICR[2].B.FEN0 = 1;
    MODULE_SCU.EICR[2].B.EIEN0 = 1;
    MODULE_SCU.EICR[2].B.INP0 = 1;

    MODULE_SCU.IGCR[0].B.IGP1 = 1;  // OGU1 -> SCUERU1

    // set SCUERU1
    MODULE_SRC.SCU.SCUERU[1].B.SRPN = ISR_PRIORITY_ERU1;
    MODULE_SRC.SCU.SCUERU[1].B.TOS = 0;
    MODULE_SRC.SCU.SCUERU[1].B.CLRR = 1;
    MODULE_SRC.SCU.SCUERU[1].B.SRE = 1;

    // set Glitch Filter
    MODULE_SCU.EIFILT.B.FILRQ0A = 1;
    MODULE_SCU.EIFILT.B.FILRQ4A = 1;
    MODULE_SCU.EIFILT.B.FILTDIV = 15;
    MODULE_SCU.EIFILT.B.DEPTH = 15;

    IfxScuWdt_setSafetyEndinitInline(pw);

//    Encoder_Init_Stm_100ms();
}

//void Encoder_Init_Stm_100ms(void) {
//    MODULE_STM1.CMCON.B.MSIZE0 = 31;
//    MODULE_STM1.CMCON.B.MSTART0 = 0;
//    MODULE_STM1.ICR.B.CMP0OS = 0;
//
//    MODULE_SRC.STM.STM[1].SR[0].B.TOS = 0;
//    MODULE_SRC.STM.STM[1].SR[0].B.SRPN = ISR_PRIORITY_STM1;
//    MODULE_SRC.STM.STM[1].SR[0].B.CLRR = 1;
//    MODULE_SRC.STM.STM[1].SR[0].B.SRE = 1;
//
//    MODULE_STM1.ISCR.B.CMP0IRR = 1U;
//    MODULE_STM1.ICR.B.CMP0EN = 1U;
//
//    MODULE_STM1.CMP[0].U = (unsigned int)((MODULE_STM1.TIM0.U | ((uint64)MODULE_STM1.CAP.U << 32)) + 100000*CPU_CLOCK_MHZ);
//}

IFX_INTERRUPT(Encoder_Enc0_Isr_Handler, 0, ISR_PRIORITY_ERU0);
IFX_INTERRUPT(Encoder_Enc1_Isr_Handler, 0, ISR_PRIORITY_ERU1);
//IFX_INTERRUPT(Encoder_Stm1_Isr_Handler, 0, ISR_PRIORITY_STM1);

void Encoder_Enc0_Isr_Handler(void) {
    uint64 now = Stm_Get_Time_Us();
    uint64 diff = now - prev_enc0;
    uint8 status = MODULE_P15.IN.B.P4;
    if (diff < 500 || status == lastStatus_enc0)
        return;
    intCnt_enc0++;
    diffSum_enc0 += diff;
    prev_enc0 = now;
    lastStatus_enc0 = status;
}

void Encoder_Enc1_Isr_Handler(void) {
    uint64 now = Stm_Get_Time_Us();
    uint64 diff = now - prev_enc1;
    uint8 status = MODULE_P33.IN.B.P7;
    if (diff < 500 || status == lastStatus_enc1)
        return;
    intCnt_enc1++;
    diffSum_enc1 += diff;
    prev_enc1 = now;
    lastStatus_enc1 = status;
}

//void Encoder_Stm1_Isr_Handler(void) {
//    MODULE_STM1.CMP[0].U = (unsigned int)((MODULE_STM1.TIM0.U | ((uint64)MODULE_STM1.CAP.U << 32)) + 100000*CPU_CLOCK_MHZ);
//    uint8 txData[8] = {0, };
//
//    if (intCnt_enc0 > 0) {
//        rpm0 = 1500000/(int)(diffSum_enc0/intCnt_enc0);
//        if (!MODULE_P10.OUT.B.P1)
//            rpm0 *= -1;
//    } else
//        rpm0 = 0;
//
//    if (intCnt_enc1 > 0) {
//        rpm1 = 1500000/(int)(diffSum_enc1/intCnt_enc1);
//        if (!MODULE_P10.OUT.B.P2)
//            rpm1 *= -1;
//    } else
//        rpm1 = 0;
//
//    intCnt_enc0 = 0;
//    diffSum_enc0 = 0;
//
//    intCnt_enc1 = 0;
//    diffSum_enc1 = 0;
//
//    txData[0] = (uint8)(rpm0 & 0xFF);
//    txData[1] = (uint8)((rpm0 >> 8) & 0xFF);
//    txData[2] = (uint8)((rpm0 >> 16) & 0xFF);
//    txData[3] = (uint8)((rpm0 >> 24) & 0xFF);
//    txData[4] = (uint8)(rpm1 & 0xFF);
//    txData[5] = (uint8)((rpm1 >> 8) & 0xFF);
//    txData[6] = (uint8)((rpm1 >> 16) & 0xFF);
//    txData[7] = (uint8)((rpm1 >> 24) & 0xFF);
//
//    Can_Send_Msg(0x201, txData, 8);
//}
