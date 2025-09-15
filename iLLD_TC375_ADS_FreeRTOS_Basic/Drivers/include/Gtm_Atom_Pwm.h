/**********************************************************************************************************************
 * file gtm_atom_pwm_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef GTM_ATOM_PWM_BSP_H_
#define GTM_ATOM_PWM_BSP_H_

#include "IfxGtm_reg.h"
#include "IfxGtm_cfg.h"
#include "IfxGtm_Atom_Pwm.h"

#define ISR_PRIORITY_ATOM   20                                  /* Interrupt priority number                        */
#define LED                 IfxGtm_ATOM0_4_TOUT14_P00_5_OUT     /* LED which will be driven by the PWM              */
#define PWM_A               IfxGtm_ATOM0_1_TOUT1_P02_1_OUT
#define PWM_B               IfxGtm_ATOM1_3_TOUT105_P10_3_OUT

#define CLK_FREQ            1000000.0f                          /* CMU clock frequency, in Hertz                    */
#define PWM_PERIOD          1000                                /* PWM period for the ATOM, in ticks                */

// Function Prototypes
void Gtm_Atom_Pwm_Init(void);
void Gtm_Atom_Pwm_Set_Duty_Cycle_A(uint32 dutyCycle);
void Gtm_Atom_Pwm_Set_Duty_Cycle_B(uint32 dutyCycle);

#endif /* GTM_ATOM_PWM_BSP_H_ */