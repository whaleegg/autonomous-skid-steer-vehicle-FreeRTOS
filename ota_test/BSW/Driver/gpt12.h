#ifndef BSW_DRIVER_GPT12_H_
#define BSW_DRIVER_GPT12_H_

unsigned int getcntDelay(void);
void setcntDelay(unsigned int n);

void gpt12_Init(void);

void runGpt12_T3(void);
void stopGpt12_T3(void);
void runGpt12_T6(void);
void stopGpt12_T6(void);

void Task_100ms(void);
void Task_200ms(void);
void Task_500ms(void);

#endif /* BSW_DRIVER_GPT12_H_ */
