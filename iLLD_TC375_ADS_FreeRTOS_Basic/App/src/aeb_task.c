#include "aeb_task.h"
#include "Drivers.h"

#define AEB_DANGER_THRESHOLD    200  // mm
#define AEB_SAFE_THRESHOLD      400  // mm

void vAebTask(void *pvParameters)
{
    const TickType_t xDelay = pdMS_TO_TICKS(20); // 20ms 주기

    while(1)
    {
        vTaskDelay(xDelay);

        int front_dist = Can_Get_Front_Dist();

        // AEB 발동 조건 검사
        if ((front_dist < AEB_DANGER_THRESHOLD) && (Can_Get_Aeb() == 0))
        {
            Can_Aeb_On();
            my_printf("ABE activated!!\n");
        }
        // AEB 해제 조건 검사
        else if ((front_dist > AEB_SAFE_THRESHOLD) && (Can_Get_Aeb() == 1))
        {
            Can_Aeb_Off();
            my_printf("ABE deactivated!!\n");
        }
    }
}
