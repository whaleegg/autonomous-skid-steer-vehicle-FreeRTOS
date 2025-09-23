/**********************************************************************************************************************
 * file can_bsp.h
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#ifndef CAN_BSP_H_
#define CAN_BSP_H_

#include <Encoder.h>
#include <Led.h>
#include <Isr_Priority.h>
#include <motor_bsp.h>
#include "IfxCan_Can.h"
#include "IfxCan.h"
#include "Ifx_Types.h"
#include "IfxCpu_Irq.h"
#include "IfxPort.h"
#include "Libraries/iLLD/TC37A/Tricore/Cpu/Std/Platform_Types.h"

#define CAN_MESSAGE_ID              (uint32)0x777           /* Message ID that will be used in arbitration phase    */
#define MAXIMUM_CAN_DATA_PAYLOAD    2                       /* Define maximum classical CAN payload in 4-byte words */

typedef struct{
    IfxCan_Can_Config canConfig;                            /* CAN module configuration structure                   */
    IfxCan_Can canModule;                                   /* CAN module handle                                    */
    IfxCan_Can_Node canSrcNode;                             /* CAN source node handle data structure                */
    IfxCan_Can_Node canDstNode;                             /* CAN destination node handle data structure           */
    IfxCan_Can_NodeConfig canNodeConfig;                    /* CAN node configuration structure                     */
    IfxCan_Filter canFilter;                                /* CAN filter configuration structure                   */
    IfxCan_Message txMsg;                                   /* Transmitted CAN message structure                    */
    IfxCan_Message rxMsg;                                   /* Received CAN message structure                       */
    uint8 txData[8];                                        /* Transmitted CAN data array                           */
    uint8 rxData[8];                                        /* Received CAN data array                              */
} McmcanType;

typedef enum{
    BD_NOUSE = 0,
    BD_500K = 1,
    BD_1M = 2
} CAN_BAUDRATES;

typedef enum{
    CAN_NODE0 = 0, /* CAN Node 0 for lite kit */
    CAN_NODE2 = 2  /* CAN Node 2 for mikrobus */
} CAN_NODE;

// Function Prototypes
void Can_Init(CAN_BAUDRATES ls_baudrate, CAN_NODE CAN_Node);

void Can_Set_Filter_Range(uint32 start, uint32 end);
void Can_Set_Filter_Mask(uint32 id, uint32 mask);

void Can_Send_Msg(unsigned int id, const uint8 *txData, int len);
int Can_Recv_Msg(unsigned int *id, uint8 *rxData, int *len);

int Can_Get_Aeb(void);
int Can_Get_Parking(void);
int Can_Get_Turn_Left(void);
int Can_Get_Turn_Right(void);
int Can_Get_Front_Dist(void);
void Can_Set_Front_Dist(unsigned int dist);


void Can_Let_Parking(int state);

void Can_Aeb_On(void);
void Can_Aeb_Off(void);

#endif /* CAN_BSP_H_ */
