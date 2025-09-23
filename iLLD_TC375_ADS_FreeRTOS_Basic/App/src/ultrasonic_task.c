#include "ultrasonic_task.h"
#include "Stm.h" // For CPU_CLOCK_MHZ
#include "IfxPort.h" // For direct pin manipulation

// 큐 핸들 정의
QueueHandle_t xUltrasonicQueue;

// 세마포어 핸들 정의
SemaphoreHandle_t xUltrasonicTriggerSemaphore;

// 각 센서의 echo 시작 시간을 저장하기 위한 static 변수
static uint64 start_back = 0;
static uint64 start_left = 0;
static uint64 start_right = 0;

// 다른 파일에서 정의된 거리 변수들을 사용하기 위해 extern으로 선언
// 추후 이 변수들을 ultrasonic_task.c로 옮기는 것이 더 좋은 구조입니다.
extern volatile float dist_back;
extern volatile float dist_left;
extern volatile float dist_right;

void vUltrasonicProcessingTask(void *pvParameters)
{
    UltrasonicMessage_t xReceivedMessage;

    // 초음파 메시지를 처리하기 위한 큐 생성
    xUltrasonicQueue = xQueueCreate(20, sizeof(UltrasonicMessage_t));

    if (xUltrasonicQueue == NULL)
    {
        // 큐 생성 실패 처리
        while(1);
    }

    while (1)
    {
        // 큐에서 메시지를 기다림
        if (xQueueReceive(xUltrasonicQueue, &xReceivedMessage, portMAX_DELAY) == pdPASS)
        {
            uint64 timestamp = xReceivedMessage.timestamp;

            switch (xReceivedMessage.sensor)
            {
                case SENSOR_BACK:
                    if (xReceivedMessage.pin_state == 1) // Rising edge
                    {
                        start_back = timestamp;
                    }
                    else // Falling edge
                    {
                        uint64 diff = timestamp - start_back;
                        dist_back = (float)(diff * 0.0343) / (2.0 * CPU_CLOCK_MHZ);
                    }
                    break;

                case SENSOR_LEFT:
                    if (xReceivedMessage.pin_state == 1) // Rising edge
                    {
                        start_left = timestamp;
                    }
                    else // Falling edge
                    {
                        uint64 diff = timestamp - start_left;
                        dist_left = (float)(diff * 0.0343) / (2.0 * CPU_CLOCK_MHZ);
                    }
                    break;

                case SENSOR_RIGHT:
                    if (xReceivedMessage.pin_state == 1) // Rising edge
                    {
                        start_right = timestamp;
                    }
                    else // Falling edge
                    {
                        uint64 diff = timestamp - start_right;
                        dist_right = (float)(diff * 0.0343) / (2.0 * CPU_CLOCK_MHZ);
                    }
                    break;
            }
        }
    }
}

void vUltrasonicTriggerTask(void *pvParameters)
{
    static unsigned int stm0_cnt = 0;

    // 트리거 신호를 위한 바이너리 세마포어 생성
    xUltrasonicTriggerSemaphore = xSemaphoreCreateBinary();

    if (xUltrasonicTriggerSemaphore == NULL)
    {
        // 세마포어 생성 실패 처리
        while(1);
    }

    while(1)
    {
        // ISR로부터 신호가 올 때까지 대기
        if (xSemaphoreTake(xUltrasonicTriggerSemaphore, portMAX_DELAY) == pdPASS)
        {
            // This logic is now executed in a task context
            stm0_cnt++;
            if (stm0_cnt == 1) {
                MODULE_P10.OUT.B.P4 = 0;    // Back trig off
                MODULE_P15.OUT.B.P7 = 1;    // Left trig on
            } else if (stm0_cnt == 2) {
                MODULE_P15.OUT.B.P7 = 0;    // Left trig off
                MODULE_P15.OUT.B.P0 = 1;    // Right trig on
            } else if (stm0_cnt == 3) {
                MODULE_P15.OUT.B.P0 = 0;    // Right trig off
            } else if (stm0_cnt == 2000) {
                MODULE_P10.OUT.B.P4 = 1;    // Back trig on
                stm0_cnt = 0;
            }
        }
    }
}
