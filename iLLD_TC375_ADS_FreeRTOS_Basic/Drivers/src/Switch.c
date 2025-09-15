/**********************************************************************************************************************
 * file switch_bsp.c
 *********************************************************************************************************************/
#include <Switch.h>
#include "IfxPort_PinMap.h" // 핀맵 정의를 위해 추가
#include "IfxPort.h"

// 이지 모듈 쉴드의 스위치 핀 정의 (TC375 Lite Kit 핀맵 기준)
#define SW1_PIN IfxPort_P02_0 // Arduino D2
#define SW2_PIN IfxPort_P02_1 // Arduino D3

void Switch_Init(void)
{
    // 스위치 핀들을 풀업 저항이 있는 입력으로 설정합니다.
    IfxPort_setPinModeInput(SW1_PIN.port, SW1_PIN.pinIndex, IfxPort_InputMode_pullUp);
    IfxPort_setPinModeInput(SW2_PIN.port, SW2_PIN.pinIndex, IfxPort_InputMode_pullUp);
}

// 스위치가 눌렸을 때 LOW(0)를 반환하므로, ! 연산자를 사용하여 눌렸을 때 TRUE(1)를 반환하도록 합니다.
boolean Switch_Get_SW1_Status(void)
{
    return !IfxPort_getPinState(SW1_PIN.port, SW1_PIN.pinIndex);
}

boolean Switch_Get_SW2_Status(void)
{
    return !IfxPort_getPinState(SW2_PIN.port, SW2_PIN.pinIndex);
}
