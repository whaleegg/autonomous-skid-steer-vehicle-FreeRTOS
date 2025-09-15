/**********************************************************************************************************************
 * file System_Init.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include <Drivers.h>
#include "IfxCpu.h"        // IfxCpu 함수를 사용하기 위해 필요
#include "IfxScuWdt.h"     // Watchdog 및 Safety ENDINIT 함수를 사용하기 위해 필요

IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0; // CPU 동기화 이벤트 변수

/**
 * @brief Initializes all microcontroller peripherals and board-specific hardware.
 */
void System_Init(void)
{
    /* =====================================================================================
     * Step 1: Core System Initialization
     * ================================================================================== */
    IfxCpu_enableInterrupts();

    /* Watchdog 비활성화 (개발 단계에서는 비활성화하는 것이 편리함) */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

    /* 멀티코어 CPU 동기화 */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

    /* =====================================================================================
     * Step 2: Disable Safety ENDINIT Protection
     * All critical initializations that write to protected registers must be
     * placed between the clear and set calls of the Safety ENDINIT.
     * ================================================================================== */
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);

    /* =====================================================================================
     * Step 3: Call all individual MCAL driver initialization functions
     * Enable them one by one for incremental testing.
     * ================================================================================== */

    /* Basic I/O */
    Led_Init();
    Buzzer_Init();
    Switch_Init();

    /* Timers */
//    Stm_Init(); // STM 타이머가 다른 기능(예: 초음파)에 필요할 수 있으므로 먼저 초기화
    Gpt12_Gpt1_Init();
    Gpt12_Gpt2_Init();
//    Gtm_Atom_Pwm_Init();

    /* Sensors */
    Encoder_Init();
    Ultrasonic_Init();
    // ToF_Sensor_Init(); // ToF 센서가 있다면 여기에 추가

    /* Actuators */
    Motor_Init();

    /* Communication */
    Asclin0_InitUart(); // UART
    Can_Init(BD_1M, CAN_NODE0);    // CAN

    /* =====================================================================================
     * Step 4: Re-enable Safety ENDINIT Protection
     * Once all initializations are complete, the protection is re-enabled.
     * ================================================================================== */
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}
