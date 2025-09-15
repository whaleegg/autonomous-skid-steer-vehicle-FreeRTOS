#include <Drivers/include/can_bsp.h>
#include <Drivers/include/motor_bsp.h>
#include <Drivers.h>
#include "App/include/can_task.h"

// CAN 메시지 큐 생성
QueueHandle_t xCanRxQueue;

void vCanMessageHandlerTask(void *pvParameters)
{
    CanMessage_t xReceivedMessage;

    // CAN 메시지 큐 생성 (10개 메시지 저장 가능)
    xCanRxQueue = xQueueCreate(10, sizeof(CanMessage_t));

    if (xCanRxQueue == NULL)
    {
        // 큐 생성 실패 처리 (예: 오류 LED 켜기)
        while(1);
    }

    while (1)
    {
        // 큐에서 CAN 메시지가 수신될 때까지 무한정 대기
        if (xQueueReceive(xCanRxQueue, &xReceivedMessage, portMAX_DELAY) == pdPASS)
        {
            // 수신된 메시지 ID에 따라 처리
            if (xReceivedMessage.id == 0x100) // 원격 주행 명령
            {
                // 주차 모드 중이 아닐 때만 모터 제어
                if (Can_Get_Parking() == 0) // Can_Get_Parking()은 Bsp/can_bsp.h에 정의되어야 함
                {
                    Motor_Set_Left(xReceivedMessage.data[0], xReceivedMessage.data[1]);
                    Motor_Set_Right(xReceivedMessage.data[2], xReceivedMessage.data[3]);
                }
            }
            else if (xReceivedMessage.id == 0x102) // 모드 변경 (주차 시작/종료, 방향 지시등)
            {
                // 기존 Can_Rx_Isr_Handler의 0x102 처리 로직을 여기에 구현
                // parking 플래그 토글 및 autonomous_parking_task에게 신호 보내기 등
            }
            else if (xReceivedMessage.id == 522) // TOF 센서 + AEB
            {
                // 기존 Can_Rx_Isr_Handler의 522 처리 로직을 여기에 구현
                // AEB 로직은 별도 태스크로 분리하는 것을 고려
            }
        }
    }
}
