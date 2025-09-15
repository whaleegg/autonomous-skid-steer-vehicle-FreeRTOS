/**********************************************************************************************************************
 * file switch_motor_task.h
 *********************************************************************************************************************/
#ifndef SWITCH_MOTOR_TASK_H_
#define SWITCH_MOTOR_TASK_H_

#include "FreeRTOS.h"
#include "task.h"

// 스위치 및 모터 제어 태스크 함수 프로토타입
void vSwitchMotorControlTask(void *pvParameters);

#endif /* SWITCH_MOTOR_TASK_H_ */
