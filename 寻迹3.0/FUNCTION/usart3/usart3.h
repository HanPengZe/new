#ifndef __USART3_H
#define __USART3_H	 
#include "sys.h"  
#include "track.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32������
//����3��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2015/3/29
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

#define USART3_MAX_RECV_LEN		600					//�����ջ����ֽ���
#define USART3_MAX_SEND_LEN		600					//����ͻ����ֽ���
#define USART3_RX_EN 			1					//0,������;1,����.



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


extern u8  USART3_RX_BUF[USART3_MAX_RECV_LEN]; 		//���ջ���,���USART3_MAX_RECV_LEN�ֽ�
extern u8  USART3_TX_BUF[USART3_MAX_SEND_LEN]; 		//���ͻ���,���USART3_MAX_SEND_LEN�ֽ�
extern vu16 USART3_RX_STA;   						//��������״̬

void usart3_init(u32 bound);				//����3��ʼ�� 
#endif

