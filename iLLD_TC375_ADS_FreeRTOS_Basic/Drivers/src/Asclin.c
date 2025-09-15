/**********************************************************************************************************************
 * file asclin_bsp.c
 * copyright Copyright (C) Infineon Technologies AG 2019
 * Boost Software License - Version 1.0 - August 17th, 2003
 *********************************************************************************************************************/
#include <Drivers/include/Asclin.h>

#define BUFSIZE     128
#define KB_BS '\x7F'
#define KB_CR '\r'

IFX_INTERRUPT(Asclin0RxIsrHandler, 0, ISR_PRIORITY_ASCLIN0_RX);

void Asclin0RxIsrHandler(void){
    char c = Asclin0_InUart();
    Asclin0_OutUart(c);
}

void Asclin0_InitUart(void){
    //CLC enable
    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());//DISR비트가 보호되고 있어서 watch dog time를 꺼야함.
    MODULE_ASCLIN0.CLC.U = 0; //DISR enable설정
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getGlobalEndinitPassword());
    (void)MODULE_ASCLIN0.CLC.U; //cpu클락때문에 너무 빨라서 저장이 안될 수 있는데 한번 읽음으로써 저장될때가지 기다렸다 읽게 됨.

    //IOCR ALTI set Alternate Input A selected
    MODULE_ASCLIN0.IOCR.B.ALTI = 0x0;

    //TX pin p14.0 set
    MODULE_P14.IOCR0.B.PC0 = 0x12; // P14.0 = tx = output
    MODULE_P14.OUT.B.P0 = 1;
    /*
    Rx pin p14.1 set
    MODULE_P14.IOCR0.B.PC1 = 0x10; //P14.1 rx = input = 0x10 = default
    */

    //config baud rate 115200
    MODULE_ASCLIN0.BITCON.U = (9 << 0) //prescaler 10
                            | (15 << 16) // oversampling 16
                            | (9 << 24) // samplepoint; position at 9
                            | (1u << 31); // 3 samples per bit => sampling at 7, 8, 9

    //Baud Rate set 115200 = 100MHz/(prescaler) / (oversampling) * (numerator / denominator);
    unsigned int numerator = 576;
    unsigned int denominator = 3125;
    MODULE_ASCLIN0.BRG.U = (denominator << 0) | (numerator << 16); // dominator | numerator

    /*
    baud rate 921600
    MODULE_ASCLIN0.BITCON.U = (4 << 0) //prescaler 5
                            | (7 << 16) // oversampling 8
                            | (4 << 24) // samplepoint; position at 4
                            | (1u << 31); // 3 samples per bit => sampling at

    //Baud Rate set 921600 = 100MHz/(prescaler) / (oversampling) * (numerator / denominator);
    unsigned int numerator = 1152;
    unsigned int denominator = 3125;
    MODULE_ASCLIN0.BRG.U = (denominator << 0) | (numerator << 16); // dominator | numerator
    */

    MODULE_ASCLIN0.CSR.U = 0; // setting 전에 0한 다음 세팅 다 하고 킬려고 일단 끔.

    //TXFIFO set
    MODULE_ASCLIN0.TXFIFOCON.U = (1 << 6) //INW: 1byte
                               | (1 << 1) //ENO
                               | (1 << 0); //FLUSH

    //configure TX and RX FIFOs
    MODULE_ASCLIN0.RXFIFOCON.U = (1 << 31) //BUF;1
                               | (1 << 6) //OUTW
                               | (1 << 1) //ENI
                               | (1 << 0); //FLUSH

    //data format 8N1
    MODULE_ASCLIN0.FRAMECON.U = (1 << 9 ) //stop
                               |(0 << 16) // MODE: Init
                               |(0 << 30); //pen : no parity;

    //pairty set (you must set putty too.)
    /*
    MODULE_ASCLIN0.FRAMECON.U = (1 << 9 ) //stop
                               |(0 << 16) // MODE: Init
                               |(1 << 30) //yes parity
                               |(1 << 31); //odd parity;
    */

    //bit length per data
    MODULE_ASCLIN0.DATCON.U = (7 <<0); //DATLEN= 8bit


    //UART 통신 프레임 설정 레지스터
    MODULE_ASCLIN0.FRAMECON.B.MODE = 1; //set init mode

    MODULE_ASCLIN0.CSR.U = 1; // setting is end. turn on the clock.

    MODULE_ASCLIN0.FLAGSSET.U = (IFX_ASCLIN_FLAGSSET_TFLS_MSK << IFX_ASCLIN_FLAGSSET_TFLS_OFF);
                                //0x1u << 31u;
                                //TFFS 1 => TFL ON
    //txfifo에 데이터가 차있으면 0, 비면 1을 쓰는 인터럽트를 사용하겠다는 뜻.
    //fifo queue가 가득 찼으면 0, 하나라도 비면 1로 인터럽트.

    //ASCLIN0 RX interrupt Initialization
    volatile Ifx_SRC_SRCR *src;
    src = (volatile Ifx_SRC_SRCR *)(&MODULE_SRC.ASCLIN.ASCLIN[0].RX);

    /*
    MODULE_SRC.ASCLIN.ASCLIN[0].RX.B.SRPN = ISR_PRIORITY_ASCLIN0_RX;
    */

    //or this way
    src -> B.SRPN = ISR_PRIORITY_ASCLIN0_RX; //priority
    src -> B.TOS = 0; //cpu number to request
    src -> B.CLRR = 1; //clear request
    MODULE_ASCLIN0.FLAGSENABLE.B.RFLE = 1; //enable RXFIFO fill level flag;
    src -> B.SRE = 1; //interrupt enable
}

int Asclin0_PollUart(unsigned char *chr){
    unsigned char ret;
    int res= 0;

    if (MODULE_ASCLIN0.FLAGS.B.RFL == 1) { //receive했다면
        //receive message
        ret = (unsigned char)MODULE_ASCLIN0.RXDATA.U;

        //RX clear
        MODULE_ASCLIN0.FLAGSCLEAR.U = (IFX_ASCLIN_FLAGSCLEAR_RFLC_MSK << IFX_ASCLIN_FLAGSCLEAR_RFLC_OFF);

        //check for error condition
        if ((MODULE_ASCLIN0.FLAGS.U) & ((IFX_ASCLIN_FLAGS_PE_MSK << IFX_ASCLIN_FLAGS_PE_OFF) |//parity error
                                        (IFX_ASCLIN_FLAGS_FE_MSK << IFX_ASCLIN_FLAGS_FE_OFF) | //framing error
                                        (IFX_ASCLIN_FLAGS_RFO_MSK << IFX_ASCLIN_FLAGS_RFO_OFF))) // FIFO overflow
        {
            //reset error flags;
            MODULE_ASCLIN0.FLAGSCLEAR.U = ((IFX_ASCLIN_FLAGSCLEAR_PEC_MSK << IFX_ASCLIN_FLAGSCLEAR_PEC_OFF) | \
                                           (IFX_ASCLIN_FLAGSCLEAR_FEC_MSK << IFX_ASCLIN_FLAGSCLEAR_FEC_OFF) | \
                                           (IFX_ASCLIN_FLAGSCLEAR_RFOC_MSK << IFX_ASCLIN_FLAGSCLEAR_RFOC_OFF));
        }
        else{
            *chr = ret;
            res = 1;
        }
    }
    return res;
}

unsigned char Asclin0_InUart(void){
    /*
    while ( MODULE_ASCLIN0.FLAGS.B.RFL != 0 ){};
    MODULE_ASCLIN0.FLAGSCLEAR.U = (IFX_ASCLIN_FLAGSCLEAR_RFLC_MSK << IFX_ASCLIN_FLAGSCLEAR_RFLC_OFF);

    unsigned char chr = MODULE_ASCLIN0.RXDATA.U;
    return chr;
    */

    unsigned char ch;
    while (Asclin0_PollUart(&ch)==0);
    return ch;
}

unsigned char Asclin0_InUartNonBlock(void){
    unsigned char ch=0;
    int res= Asclin0_PollUart(&ch);
    return res == 1 ? ch : -1;
}

void Asclin0_OutUart(const unsigned char chr){
    while (!(MODULE_ASCLIN0.FLAGS.B.TFL != 0)); //txdata에 빈 공간이 남으면 1을 반환하면서 탈출.

    //TX CLEAR => 해당 flag를 확인했으므로 내림.
    MODULE_ASCLIN0.FLAGSCLEAR.U = (IFX_ASCLIN_FLAGSCLEAR_TFLC_MSK << IFX_ASCLIN_FLAGSCLEAR_TFLC_OFF);
                                   //0x1u << 31u;

    //Send the character 해당 자리에 글짜 쓰기.
    MODULE_ASCLIN0.TXDATA.U = chr;
    //이럼 clock에 따라 txdata에 있는 데이터를 전송하고 삭제함. => TFL이 1이 되게 됨. => 데이터 더 받을 수 있음. 반복.
}

void my_puts(const char *str){
    /*
    char buffer[BUFSIZE];
    char *ptr;

    sprintf(buffer, "%s\r\n", str);

    for (ptr = buffer; *ptr; ++ptr)
        Asclin0_OutUart((const unsigned char)*ptr);
    */

    while (*str)
        Asclin0_OutUart((const unsigned char)*str++);
}

void my_printf(const char *fmt, ...)
{
    char buffer[128];
    char buffer2[128]; // add \r before \n
    sint16 len = 0;
    va_list ap;

    va_start(ap, fmt);
    vsprintf(buffer, fmt, ap);
    va_end(ap);
    int j = 0;
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\n') {
            buffer2[j++] = '\r';
            buffer2[j++] = buffer[i];
        } else {
            buffer2[j++] = buffer[i];
        }
        len += 1;
    }
    buffer2[j] = '\0';
    len += 1;

    for (int i = 0; buffer2[i] != '\0'; i++)
        Asclin0_OutUart((const unsigned char)buffer2[i]);
}

void my_scanf(const char *fmt, ...)
{
    uint8 c = 0;
    char buf[128];
    int idx = 0, i;
    char *pstr, *pidx;

    memset(buf, 0, 128);
    while (c != '\r')
    {
        c = Asclin0_InUart();
        if (c == KB_BS || c == 0x8)
        {
            if (idx > 0) {
                buf[idx - 1] = 0;
                idx--;
                my_printf("%c %c", 8,8);
            }
            continue;
        }
        else
        {
            if (c == KB_CR) {
                idx += 1;
                buf[idx] = '\0';
            } else {
                buf[idx] = c;
                idx += 1;
            }
        }
        my_printf("%c", c);
    }
    my_printf("\n");

    va_list ap;
    va_start(ap, fmt);
    while ((c = *fmt++) != 0)
    {
        if (c == '%')
        {
            uint8 c1;
            c = *fmt++;
            switch (c)
            {
                case 'c':
                    *va_arg(ap, char *) = buf[0];
                    buf[0] = '\0';
                    break;
                case 'd':
                    *va_arg(ap, int *) = atoi(buf);
                    pidx = strchr(buf, ' ');
                    if (pidx != NULL) { *pidx = '\0'; }
                    for (i = 0; ; i++)
                    {
                        if (buf[i] == '\0' || buf[i] == ' ') { buf[i] = '\0'; break; }
                        buf[i] = '\0';
                    }
                    break;
                case 's':
                    pstr = va_arg(ap, char *);
                    for (i = 0; buf[i] != '\0'; i++)
                    {
                        *pstr++ = buf[i];
                        buf[i] = '\0';
                    }
                    *pstr = '\0';
                    break;
                case 'l':
                    c1 = *fmt++;
                    if (c1 == 'd') {
                        *va_arg(ap, long long *) = atoll(buf);
                        pidx = strchr(buf, ' ');
                        if (pidx != NULL) { *pidx = '\0'; }
                        for (i = 0; ; i++)
                        {
                            if (buf[i] == '\0' || buf[i] == ' ') { buf[i] = '\0'; break; }
                            buf[i] = '\0';
                        }
                    } else if (c1 == 'f') {
                        *va_arg(ap, double *) = atof(buf);
                        pidx = strchr(buf, ' ');
                        if (pidx != NULL) { *pidx = '\0'; }
                        for (int i = 0; ; i++)
                        {
                            if (buf[i] == '\0' || buf[i] == ' ') { buf[i] = '\0'; break; }
                            buf[i] = '\0';
                        }
                    }
                    break;
                case 'f':
                    *va_arg(ap, float *) = (float)(atof(buf));
                    pidx = strchr(buf, ' ');
                    if (pidx != NULL) { *pidx = '\0'; }
                    for (i = 0; ; i++)
                    {
                        if (buf[i] == '\0' || buf[i] == ' ') { buf[i] = '\0'; break; }
                        buf[i] = '\0';
                    }
                    break;
                default:
                    break;
            }
            remove_null(buf);
        }
    }
    va_end(ap);
}

void remove_null(char *s)
{
    int i, start_idx;
    char buf[128];

    start_idx = 0;
    while (*(s + start_idx++) == '\0');
    memset(buf, 0, 128);
    strcpy(buf, (s + (start_idx - 1)));

    memset(s, 0, 128);
    i = 0;
    while (buf[i] != '\0')
    {
        *(s + i) = buf[i];
        ++i;
    }
    *(s + i) = '\0';
}
