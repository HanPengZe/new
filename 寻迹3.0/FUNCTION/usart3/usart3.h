#ifndef __USART3_H
#define __USART3_H	 
#include "sys.h"  
#include "track.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板
//串口3驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2015/3/29
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

#define USART3_MAX_RECV_LEN		600					//最大接收缓存字节数
#define USART3_MAX_SEND_LEN		600					//最大发送缓存字节数
#define USART3_RX_EN 			1					//0,不接收;1,接收.



void ControlSpeed(float a,float b,float c,float d);
void GoAhead(void);
void Back(void);
void Left(void);
void Right(void);
void Stop(void);
void LeftSpin(void);
void RightSpin(void);
void Bluetooth(void);
void up(void);
void down(void);
void off(void);
void release(void);
void clamp(void);
void UpRight(void);
void DownRight(void);
void UpLeft(void);
void DownLeft(void);
void Stop(void);


extern u8  USART3_RX_BUF[USART3_MAX_RECV_LEN]; 		//接收缓冲,最大USART3_MAX_RECV_LEN字节
extern u8  USART3_TX_BUF[USART3_MAX_SEND_LEN]; 		//发送缓冲,最大USART3_MAX_SEND_LEN字节
extern vu16 USART3_RX_STA;   						//接收数据状态

void usart3_init(u32 bound);				//串口3初始化 
#endif

