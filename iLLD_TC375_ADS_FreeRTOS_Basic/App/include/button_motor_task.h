/**********************************************************************************************************************
 * file button_motor_task.h
 *********************************************************************************************************************/
#ifndef BUTTON_MOTOR_TASK_H_
#define BUTTON_MOTOR_TASK_H_

#include "FreeRTOS.h"
#include "task.h"

// 버튼 및 모터 제어 태스크 함수 프로토타입
void vButtonMotorControlTask(void *pvParameters);

#endif /* BUTTON_MOTOR_TASK_H_ */
