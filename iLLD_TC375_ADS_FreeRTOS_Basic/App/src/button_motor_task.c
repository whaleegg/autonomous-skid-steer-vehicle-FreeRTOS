/**********************************************************************************************************************
 * file button_motor_task.c
 *********************************************************************************************************************/
//#include <Drivers/include/Led.h> // LED 제어를 위해 추가
//#include <Drivers/include/Button.h>
//#include <Drivers/include/motor_bsp.h>
#include "Drivers.h"
#include "App/include/button_motor_task.h"

void vButtonMotorControlTask(void *pvParameters)
{
    const TickType_t xDelay = pdMS_TO_TICKS(50); // 50ms 마다 버튼 상태 확인
//    int counter = 0;

    while (1)
    {
//        // 10 * 50ms = 500ms 마다 LED 토글 (태스크 실행 확인용)
//        if (++counter >= 10)
//        {
//            Led_Toggle(2); // LED1 토글
//            counter = 0;
//        }

        if (Button_Get_SW1_Status())
        {
            // 버튼 1: 정방향 회전
            Motor_Set_Left(1, 100); // 방향 1, 속도 100
        }
        else if (Button_Get_SW2_Status())
        {
            // 버튼 2: 정지
//            Motor_Stop_Left();
            Motor_Set_Left(0, 100);
        }
        else
        {
            Motor_Stop_Left();
        }

        vTaskDelay(xDelay);
    }
}
