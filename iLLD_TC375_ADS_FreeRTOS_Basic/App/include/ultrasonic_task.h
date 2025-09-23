#ifndef ULTRASONIC_TASK_H_
#define ULTRASONIC_TASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "Ifx_Types.h"

// 초음파 센서 ID 정의
typedef enum
{
    SENSOR_BACK,
    SENSOR_LEFT,
    SENSOR_RIGHT
} UltrasonicSensor_t;

// 큐로 전달될 메시지 구조체
typedef struct
{
    UltrasonicSensor_t sensor; // 어느 센서인지
    uint64 timestamp;          // 언제 echo 신호가 왔는지 (raw ticks)
    uint8 pin_state;           // echo 핀의 상태 (Rising or Falling)
} UltrasonicMessage_t;

// 초음파 메시지 큐 핸들
extern QueueHandle_t xUltrasonicQueue;

// 초음파 트리거 세마포어 핸들
extern SemaphoreHandle_t xUltrasonicTriggerSemaphore;

// 초음파 처리 태스크 함수 프로토타입
void vUltrasonicProcessingTask(void *pvParameters);

// 초음파 트리거 태스크 함수 프로토타입
void vUltrasonicTriggerTask(void *pvParameters);

#endif /* ULTRASONIC_TASK_H_ */
