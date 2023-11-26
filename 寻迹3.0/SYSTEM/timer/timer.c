#include "timer.h"
//#include "Device/Include/stm32f10x.h"   // Device header
#include "pwm.h"
#include "encoder.h"
#include "pid.h"




void  TIM6_Init(u16 arr, u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   
	/* ����ʱ���ṹ�� */
	NVIC_InitTypeDef NVIC_InitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);//ʹ�ܶ�ʱ��ʱ��
	
	TIM_TimeBaseStructure.TIM_Prescaler = psc;   	//���ö�ʱ��ʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_Period = arr;       //�����Զ���װ�ؼĴ�����ֵ  
	TIM_TimeBaseStructure.TIM_ClockDivision =0; //ʱ�ӷָ�
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);	//��ʼ��TIM6ʱ�������λ

	TIM_ClearFlag(TIM6, TIM_FLAG_Update);	//��������жϣ���ֹһ���ж���������ж�
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);	//�򿪶�ʱ�������ж�
/*�����ж����ȼ�*/
	NVIC_InitStruct.NVIC_IRQChannel = TIM6_IRQn;   //ʹ���ⲿ�ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;   //ʹ���ⲿ�ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1; //��ռ���ȼ�1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;    //��Ӧ���ȼ�3
	NVIC_Init(&NVIC_InitStruct);
	TIM_Cmd(TIM6, ENABLE);	//ʹ�ܶ�ʱ��
	
}
void TIM6_IRQHandler(void)
{
	if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)==SET)
 {
   TIM_ClearITPendingBit(TIM6,TIM_IT_Update);   //===�����ʱ��1�жϱ�־λ
	 Encoder1=Read_Encoder(2);                     //ȡ��ʱ��2��������ֵ
	 Encoder2=Read_Encoder(3);                     //ȡ��ʱ��4��������ֵ  
	 Encoder3=Read_Encoder(4); 
	 Encoder4=Read_Encoder(5); 
	 Motor1=Incremental_PID1(Encoder1,Target1);    //===λ��PID������
	 Motor2=Incremental_PID2(Encoder2,Target2);
	 Motor3=Incremental_PID3(Encoder3,Target3);
	 Motor4=Incremental_PID4(Encoder4,Target4);
   Set_Pwm1(Motor1);
	 Set_Pwm2(Motor2);
	 Set_Pwm3(Motor3);
	 Set_Pwm4(Motor4);
 } 
}
