#ifndef __PID_H
#define __PID_H
#include "sys.h"
#include "pwm.h"
#include "encoder.h"
//����һ��pid����������
typedef struct
{
	float Target; 			        //�趨Ŀ��ֵ
	float Measured; 				    //����ֵ
	float err; 									//����ƫ��ֵ
	float err_last; 			  	  //��һ��ƫ��
	float err_beforeLast;
	float pwm; 									//pwm���
}incrementalpid_t;

extern incrementalpid_t pid[4];
extern int Encoder1;
extern int Target1;
extern int Motor1;

extern int Encoder2;
extern int Target2;
extern int Motor2;

extern int Encoder3;
extern int Target3;
extern int Motor3;

extern int Encoder4;
extern int Target4;
extern int Motor4;
int Incremental_PID1(int Encoder1,int Target1);
int Incremental_PID2(int Encoder2,int Target2);
int Incremental_PID3(int Encoder3,int Target3);
int Incremental_PID4(int Encoder4,int Target4);
void Set_Pwm1(int moto1);
void Set_Pwm2(int moto2);
void Set_Pwm3(int moto3);
void Set_Pwm4(int moto4);
int myabs(int a); //ȡ����ֵ






#endif
