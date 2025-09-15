#include <Drivers/include/can_bsp.h>
#include <Drivers/include/motor_bsp.h>
#include <Drivers/include/ultrasonic_bsp.h>
#include <Drivers.h>
#include "App/include/parking_task.h"
#include "App/include/can_task.h"

// 주차 시작 신호 세마포어 생성
SemaphoreHandle_t xParkingStartSemaphore;

// 기존 Parking.c의 Parking_On 함수 로직을 여기에 통합
void vAutonomousParkingTask(void *pvParameters)
{
    // 주차 시작 신호 세마포어 생성 (바이너리 세마포어)
    xParkingStartSemaphore = xSemaphoreCreateBinary();

    if (xParkingStartSemaphore == NULL)
    {
        // 세마포어 생성 실패 처리
        while(1);
    }

    while (1)
    {
        // CAN 핸들러 태스크로부터 주차 시작 신호가 올 때까지 대기
        if (xSemaphoreTake(xParkingStartSemaphore, portMAX_DELAY) == pdPASS)
        {
            // 주차 시작 신호를 받으면 Parking_On() 로직 실행
            int state = 0;

            uint64 start_time = 0;
            uint64 end_time = 0;
            uint64 space_duration_us = 0;
            int measuring_space = 0;
            unsigned int Buzzer_Flag = 1;

            float space_detect_threshold = 35.0;
            float rear_stop_threshold = 7.0;

            while (state != 5) // 주차 완료 상태 (state == 5)가 될 때까지 반복
            {
                float left_dist = Ultrasonic_Get_Left_Dist();
                float rear_dist = Ultrasonic_Get_Back_Dist();

                if (state == 0) // 공간 탐색 및 시간 측정
                {
                    Motor_Set_Left(1, 80);
                    Motor_Set_Right(1, 80);

                    if (left_dist > space_detect_threshold)
                    {
                        if (measuring_space == 0)
                        {
                            start_time = Stm_Get_Time_Us(); // 측정 시작
                            measuring_space = 1;
                        }
                    }
                    else // 다시 15cm 이내가 된 경우 → 빈공간 종료
                    {
                        if (measuring_space == 1)
                        {
                            end_time = Stm_Get_Time_Us();
                            space_duration_us = end_time - start_time;
                            measuring_space = 0;

                            if (space_duration_us >= 400000)  // 0.5초 이상 빈 공간이면
                            {
                                Motor_Stop_Left();
                                Motor_Stop_Right();
                                vTaskDelay(pdMS_TO_TICKS(500));  // delay_ms 대체

                                uint64 half_duration_ms = 1450;

                                Motor_Set_Left(0, 90);
                                Motor_Set_Right(0, 90);
                                vTaskDelay(pdMS_TO_TICKS((int)half_duration_ms)); // delay_ms 대체
                                Motor_Stop_Left();
                                Motor_Stop_Right();

                                state = 1;
                            }
                            // else 공간이 너무 짧으면 continue scanning
                        }
                    }
                }

                else if (state == 1) // 정지 후 대기
                {
                    vTaskDelay(pdMS_TO_TICKS(500)); // delay_ms 대체
                    state = 2;
                }

                else if (state == 2) // 전진 + 우회전
                {
                    Motor_Set_Left(1, 255);
                    Motor_Set_Right(1, 80);

                    vTaskDelay(pdMS_TO_TICKS(800)); // delay_ms 대체
                    Motor_Stop_Left();
                    Motor_Stop_Right();
                    vTaskDelay(pdMS_TO_TICKS(500)); // delay_ms 대체
                    state = 3;
                }

                else if (state == 3)  // 후진 + 좌회전
                {
                    Motor_Set_Left(0, 80);
                    Motor_Set_Right(0, 255);

                    vTaskDelay(pdMS_TO_TICKS(555)); // delay_ms 대체

                    Motor_Stop_Left();
                    Motor_Stop_Right();
                    vTaskDelay(pdMS_TO_TICKS(500)); // delay_ms 대체

                    Motor_Set_Left(0, 100);
                    Motor_Set_Right(0, 100);
                    vTaskDelay(pdMS_TO_TICKS(50)); // delay_ms 대체
                    state = 4;
                }

                else if (state == 4) // 후진 직선 주차
                {
                    Motor_Set_Left(0, 60);
                    Motor_Set_Right(0, 60);

                    if(rear_dist >= 60){
                        Buzzer_Off(); // Buzzer_Off()는 bsp.h에 정의되어야 함
                        Buzzer_Flag = 1;
                    }
                    else if(rear_dist > 45){
                        Buzzer_Set_Cycle_Ms(300); // Buzzer_Set_Cycle_Ms()는 bsp.h에 정의되어야 함
                        if(Buzzer_Flag) {
                            Buzzer_On(); // Buzzer_On()는 bsp.h에 정의되어야 함
                            Buzzer_Flag = 0;
                        }
                    }
                    else if(rear_dist > 30) {
                        Buzzer_Set_Cycle_Ms(150);
                    }
                    else if (rear_dist >= 15) {
                        Buzzer_Set_Cycle_Ms(50);
                    }

                    if (rear_dist <= rear_stop_threshold)
                    {
                        Motor_Stop_Left();
                        Motor_Stop_Right();
                        state = 5;
                    }
                }

                // 태스크가 다른 태스크에게 CPU를 양보할 수 있도록 짧은 지연 추가
                vTaskDelay(pdMS_TO_TICKS(10));
            }

            // 주차 완료 후 처리
            Led_Set(1, 1); // Led_Set()은 bsp.h에 정의되어야 함
            Led_Set(2, 1);
            Buzzer_Off();
            Buzzer_Always_On(); // Buzzer_Always_On()은 bsp.h에 정의되어야 함

            vTaskDelay(pdMS_TO_TICKS(2000)); // delay_ms 대체
            Led_Set(1, 0);
            Led_Set(2, 0);
            Buzzer_Off();

            Can_Let_Parking(0); // 주차 완료 후 parking 플래그 리셋 및 응답
        }
    }
}
