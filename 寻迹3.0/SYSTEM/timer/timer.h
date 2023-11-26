#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"


void  TIM6_Init(u16 arr, u16 psc);
void TIM6_IRQHandler(void);

//void  TIM7_CounterMode(u16 arr, u16 psc);
#endif

