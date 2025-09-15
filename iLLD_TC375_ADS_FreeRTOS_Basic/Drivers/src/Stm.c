/**********************************************************************************************************************
 * file stm_bsp.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include <Stm.h>

uint64 Stm_Get_Tick(void) {
    uint64 result = MODULE_STM0.TIM0.U | ((uint64)MODULE_STM0.CAP.U << 32);
    return result;
}

uint64 Stm_Get_Time_Us(void) {
    uint64 result = MODULE_STM0.TIM0.U | ((uint64)MODULE_STM0.CAP.U << 32);
    return result / CPU_CLOCK_MHZ;
}

uint64 Stm_Get_Time_Ms(void) {
    uint64 result = MODULE_STM0.TIM0.U | ((uint64)MODULE_STM0.CAP.U << 32);
    return result / (CPU_CLOCK_MHZ*1000);
}
