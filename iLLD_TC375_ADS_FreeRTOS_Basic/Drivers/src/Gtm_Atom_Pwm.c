/**********************************************************************************************************************
 * file gtm_atom_pwm_bsp.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include <Gtm_Atom_Pwm.h>

IfxGtm_Atom_Pwm_Config g_atomConfig_PwmA;
IfxGtm_Atom_Pwm_Config g_atomConfig_PwmB;
IfxGtm_Atom_Pwm_Driver g_atomDriver_PwmA;
IfxGtm_Atom_Pwm_Driver g_atomDriver_PwmB;

IfxGtm_Atom_Pwm_Config g_atomConfig;                            /* Timer configuration structure                    */
IfxGtm_Atom_Pwm_Driver g_atomDriver;                            /* Timer Driver structure                           */

void Gtm_Atom_Pwm_Init(void)
{
    /* Enable GTM */
    uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(psw);
    MODULE_GTM.CLC.B.DISR = 0;
                                         /* Enable GTM                           */

    IfxGtm_Cmu_setClkFrequency(&MODULE_GTM, IfxGtm_Cmu_Clk_0, CLK_FREQ);    /* Set the CMU clock 0 frequency        */
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKEN_CLK0);            /* Enable the CMU clock 0               */

    IfxGtm_Atom_Pwm_initConfig(&g_atomConfig_PwmA, &MODULE_GTM);

    g_atomConfig_PwmA.atom = PWM_A.atom;
    g_atomConfig_PwmA.atomChannel = PWM_A.channel;
    g_atomConfig_PwmA.period = PWM_PERIOD;
    g_atomConfig_PwmA.pin.outputPin = &PWM_A;
    g_atomConfig_PwmA.synchronousUpdateEnabled = TRUE;

    IfxGtm_Atom_Pwm_init(&g_atomDriver_PwmA, &g_atomConfig_PwmA);
    IfxGtm_Atom_Pwm_start(&g_atomDriver_PwmA, TRUE);

    IfxGtm_Cmu_setClkFrequency(&MODULE_GTM, IfxGtm_Cmu_Clk_1, CLK_FREQ);
    IfxGtm_Cmu_enableClocks(&MODULE_GTM, IFXGTM_CMU_CLKEN_CLK1);

    IfxGtm_Atom_Pwm_initConfig(&g_atomConfig_PwmB, &MODULE_GTM);

    g_atomConfig_PwmB.atom = PWM_B.atom;                                       /* Select the ATOM depending on the LED     */
    g_atomConfig_PwmB.atomChannel = PWM_B.channel;                             /* Select the channel depending on the LED  */
    g_atomConfig_PwmB.period = PWM_PERIOD;                                   /* Set timer period                         */
    g_atomConfig_PwmB.pin.outputPin = &PWM_B;                                  /* Set LED as output                        */
    g_atomConfig_PwmB.synchronousUpdateEnabled = TRUE;                       /* Enable synchronous update                */

    IfxGtm_Atom_Pwm_init(&g_atomDriver_PwmB, &g_atomConfig_PwmB);                 /* Initialize the PWM                       */
    IfxGtm_Atom_Pwm_start(&g_atomDriver_PwmB, TRUE);                         /* Start the PWM                            */

    IfxScuWdt_setCpuEndinit(psw);
}

void Gtm_Atom_Pwm_Set_Duty_Cycle_A(uint32 dutyCycle)
{
    g_atomConfig_PwmA.dutyCycle = dutyCycle;                 /* Set duty cycle                                           */
    IfxGtm_Atom_Pwm_init(&g_atomDriver_PwmA, &g_atomConfig_PwmA); /* Re-initialize the PWM                                    */
}

void Gtm_Atom_Pwm_Set_Duty_Cycle_B(uint32 dutyCycle)
{
    g_atomConfig_PwmB.dutyCycle = dutyCycle;                 /* Set duty cycle                                           */
    IfxGtm_Atom_Pwm_init(&g_atomDriver_PwmB, &g_atomConfig_PwmB); /* Re-initialize the PWM                                    */
}
