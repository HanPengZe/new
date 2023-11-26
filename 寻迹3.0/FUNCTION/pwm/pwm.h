#ifndef __PWM_H
#define __PWM_H
#include "sys.h"
void PWM_Init_TIM8(u16 arr, u16 psc);
void change_pwm(u16 i);
void PWM_Init_TIM1(u16 arr, u16 psc);
void angle(float angle);
#define AIN1   PBout(12)
#define AIN2   PBout(13)
#define BIN1   PBout(14)
#define BIN2   PBout(15)
#define ain1   PEout(12)
#define ain2   PEout(13)
#define bin1   PEout(14)
#define bin2   PEout(15)


#endif

