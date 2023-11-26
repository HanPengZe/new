#ifndef __ENCODER_H
#define __ENCODER_H
#include "sys.h"
#include "pwm.h"
extern int Encoder_TIM;
void Encoder_Init_TIM2(void);
void Encoder_Init_TIM3(void);
void Encoder_Init_TIM4(void);
void Encoder_Init_TIM5(void);
void Encoder_Init_TIM(void);
int Read_Encoder(u8 TIMX);
#endif

