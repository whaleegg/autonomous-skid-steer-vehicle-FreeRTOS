#ifndef PARKING_TASK_H_
#define PARKING_TASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

// 주차 시작 신호 세마포어 핸들
extern SemaphoreHandle_t xParkingStartSemaphore;

// 자동 주차 태스크 함수 프로토타입
void vAutonomousParkingTask(void *pvParameters);

#endif /* PARKING_TASK_H_ */