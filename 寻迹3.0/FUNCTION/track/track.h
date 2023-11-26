#ifndef __TRACK_H
#define __TRACK_H
#include "sys.h"

#define LED1 GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_11)
#define LED2 GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_12)
#define LED3 GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_13)
#define LED4 GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_14)
#define LED5 GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_15)


void Track(void);
void Track_Init(void);
#endif
