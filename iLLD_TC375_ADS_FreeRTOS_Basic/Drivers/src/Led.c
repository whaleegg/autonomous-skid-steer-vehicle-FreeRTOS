/**********************************************************************************************************************
 * file led_bsp.c
 *********************************************************************************************************************/
#include <Led.h>
#include "IfxPort_PinMap.h"
#include "IfxPort.h"

// 이지 모듈 쉴드의 LED 핀 정의 (TC375 Lite Kit 핀맵 기준)
#define LED1_PIN IfxPort_P10_2
#define LED2_PIN IfxPort_P10_1

void Led_Init(void)
{
    // LED 핀들을 출력으로 설정합니다.
    IfxPort_setPinModeOutput(LED1_PIN.port, LED1_PIN.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeOutput(LED2_PIN.port, LED2_PIN.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    // LED를 끈 상태로 초기화
    IfxPort_setPinState(LED1_PIN.port, LED1_PIN.pinIndex, IfxPort_State_high);
    IfxPort_setPinState(LED2_PIN.port, LED2_PIN.pinIndex, IfxPort_State_high);
}

void Led_Set(unsigned char num_LED, unsigned char onOff)
{
    if (num_LED == 1)
    {
        IfxPort_setPinState(LED1_PIN.port, LED1_PIN.pinIndex, onOff ? IfxPort_State_high : IfxPort_State_low);
    }
    else if (num_LED == 2)
    {
        IfxPort_setPinState(LED2_PIN.port, LED2_PIN.pinIndex, onOff ? IfxPort_State_high : IfxPort_State_low);
    }
}

void Led_Toggle(unsigned char num_LED)
{
    if (num_LED == 1)
    {
        IfxPort_togglePin(LED1_PIN.port, LED1_PIN.pinIndex);
    }
    else if (num_LED == 2)
    {
        IfxPort_togglePin(LED2_PIN.port, LED2_PIN.pinIndex);
    }
}
