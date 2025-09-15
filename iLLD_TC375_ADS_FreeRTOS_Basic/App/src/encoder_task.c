/*
 * encoder_task.c
 *
 *  Created on: 2025. 9. 14.
 *      Author: user
 */

#include "encoder_task.h"
#include "FreeRTOS.h"
#include "task.h"

// BSW/MCAL 계층의 기능을 사용하기 위한 헤더 파일들
#include "Drivers.h" // RPM 계산에 필요한 변수 및 CAN 함수를 위해 포함

extern volatile int rpm0;
extern volatile int rpm1;
extern volatile uint64 intCnt_enc0;
extern volatile uint64 diffSum_enc0;
extern volatile uint64 intCnt_enc1;
extern volatile uint64 diffSum_enc1;


void vEncoderProcessingTask(void *pvParameters)
{
    while (1)
    {
        // 1. 100ms 대기 (STM 타이머 인터럽트를 대체)
        vTaskDelay(pdMS_TO_TICKS(100));

        // 2. RPM 계산 및 CAN 전송 (기존 ISR 로직)
        uint8 txData[8] = {0, };
        int local_rpm0 = 0;
        int local_rpm1 = 0;

        // --- 공유 변수 접근 시작 (Critical Section) ---
        taskENTER_CRITICAL();

        if (intCnt_enc0 > 0) {
            rpm0 = 1500000 / (int)(diffSum_enc0 / intCnt_enc0);
        } else {
            rpm0 = 0;
        }
        intCnt_enc0 = 0;
        diffSum_enc0 = 0;
        local_rpm0 = rpm0; // 지역 변수에 복사

        if (intCnt_enc1 > 0) {
            rpm1 = 1500000 / (int)(diffSum_enc1 / intCnt_enc1);
        } else {
            rpm1 = 0;
        }
        intCnt_enc1 = 0;
        diffSum_enc1 = 0;
        local_rpm1 = rpm1; // 지역 변수에 복사

        taskEXIT_CRITICAL();
        // --- 공유 변수 접근 종료 ---

        // 방향 결정 로직은 Critical Section 밖으로 빼는 것이 좋습니다.
        // 이 로직은 GPIO 핀을 읽는 것이므로, 동기화가 꼭 필요하지는 않습니다.
        if (!MODULE_P10.OUT.B.P1)
            local_rpm0 *= -1;
        if (!MODULE_P10.OUT.B.P2)
            local_rpm1 *= -1;

        txData[0] = (uint8)(local_rpm0 & 0xFF);
        txData[1] = (uint8)((local_rpm0 >> 8) & 0xFF);
        txData[2] = (uint8)((local_rpm0 >> 16) & 0xFF);
        txData[3] = (uint8)((local_rpm0 >> 24) & 0xFF);
        txData[4] = (uint8)(local_rpm1 & 0xFF);
        txData[5] = (uint8)((local_rpm1 >> 8) & 0xFF);
        txData[6] = (uint8)((local_rpm1 >> 16) & 0xFF);
        txData[7] = (uint8)((local_rpm1 >> 24) & 0xFF);

        Can_Send_Msg(0x201, txData, 8);
    }
}
