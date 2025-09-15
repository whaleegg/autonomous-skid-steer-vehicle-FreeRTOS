/**********************************************************************************************************************
 * file isr_priority_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef ISR_PRIORITY_BSP_H_
#define ISR_PRIORITY_BSP_H_

// for sensor
#define ISR_PRIORITY_ERU0 10 //Encoder
#define ISR_PRIORITY_ERU1 11 //Encoder
#define ISR_PRIORITY_ERU2 12 //Ultrasonic

// for timer
#define ISR_PRIORITY_STM0 20
#define ISR_PRIORITY_STM1 21
#define ISR_PRIORITY_GPT1T3_TIMER 22
#define ISR_PRIORITY_GPT2T6_TIMER 23

// for can (remote control)
#define ISR_PRIORITY_CAN_RX 30
#define ISR_PRIORITY_CAN_TX 31

// for debug
#define ISR_PRIORITY_ASCLIN0_TX 90
#define ISR_PRIORITY_ASCLIN0_RX 91

#endif /* ISR_PRIORITY_BSP_H_ */