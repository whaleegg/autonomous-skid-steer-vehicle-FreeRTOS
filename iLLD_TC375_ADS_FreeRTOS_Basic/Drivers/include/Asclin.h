/**********************************************************************************************************************
 * file asclin_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef ASCLIN_BSP_H_
#define ASCLIN_BSP_H_

#include <Isr_Priority.h> // 경로 변경
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Ifx_reg.h"
#include "IfxAsclin_bf.h"
#include "IfxScuWdt.h"
#include "Libraries/Infra/Platform/Tricore/Compilers/CompilerTasking.h" // 올바른 경로로 수정

// Function Prototypes
void Asclin0_InitUart(void);
void Asclin0RxIsrHandler(void);

int Asclin0_PollUart(unsigned char *chr);
unsigned char Asclin0_InUart(void);
unsigned char Asclin0_InUartNonBlock(void);
void Asclin0_OutUart(const unsigned char chr);

void remove_null(char *s);
void my_puts(const char *str);
void my_printf(const char *fmt, ...);
void my_scanf(const char *fmt, ...);

#endif /* ASCLIN_BSP_H_ */
