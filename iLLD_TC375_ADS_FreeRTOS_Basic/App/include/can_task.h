#ifndef CAN_TASK_H_
#define CAN_TASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

// CAN 메시지 구조체 정의
typedef struct
{
    unsigned int id;
    uint8_t data[8];
    int len;
} CanMessage_t;

// CAN 메시지 큐 핸들
extern QueueHandle_t xCanRxQueue;

// CAN 메시지 핸들러 태스크 함수 프로토타입
void vCanMessageHandlerTask(void *pvParameters);

#endif /* CAN_TASK_H_ */