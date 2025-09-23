/**********************************************************************************************************************
 * file button_bsp.h
 *********************************************************************************************************************/
#ifndef BUTTON_BSP_H_
#define BUTTON_BSP_H_

#include "Ifx_Types.h"

// Function Prototypes
void Button_Init(void);
boolean Button_Get_SW1_Status(void);
boolean Button_Get_SW2_Status(void);

#endif /* BUTTON_BSP_H_ */
