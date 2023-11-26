#include "pwm.h"
//#include "Device/Include/stm32f10x.h"   // Device header

void PWM_Init_TIM1(u16 arr, u16 psc)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;	 //����һ�����ų�ʼ���Ľṹ��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; //����һ����ʱ�жϵĽṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure; //����һ�� PWM ����Ľṹ
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1|RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO, ENABLE);//PB/E���Ƶ��IO,TIM8����pwm�������
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM1, ENABLE);//��ӳ��
	//pwm����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	//��ʼ���߼���ʱ��TIM1
	TIM_TimeBaseInitStrue.TIM_Period=arr;													//�Զ���װ��ֵ
	TIM_TimeBaseInitStrue.TIM_Prescaler=psc;											//Ԥ��Ƶϵ��
	TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1;					//
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up;			//���ϼ���
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStrue);
	//��ʼ��Pwmͨ��TIM8_CH_OC1/2/3/4
 TIM_OCInitStructure.TIM_Pulse = 0;                         //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  //ʹ������Ƚ�״̬   //ʹ��������˿�
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//ʹ������Ƚ�N״̬
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//�� MOE=0 ���� TIM1 ����ȽϿ���״̬
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//�� MOE=0 ���� TIM1 ����Ƚ� N ����״̬
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 ����Ƚ�N���Ը�
	TIM_OC1Init(TIM1,&TIM_OCInitStructure);  
	TIM_OC2Init(TIM1,&TIM_OCInitStructure);

	//ʹ��TIM8��CCR1�ϵ�Ԥװ�ؼĴ���
//	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
//	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);

	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);//�߼���ʱ����ʹ�ܺ���
	TIM_ARRPreloadConfig(TIM1,ENABLE);//ʹ��TIM8 ARR�ϵ�Ԥװ�ؼĴ���
	TIM_Cmd(TIM1, ENABLE);//ʹ��TIM8  
//TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Disable); 
//TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Disable); 
}

void PWM_Init_TIM8(u16 arr, u16 psc)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;	 //����һ�����ų�ʼ���Ľṹ��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; //����һ����ʱ�жϵĽṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure; //����һ�� PWM ����Ľṹ
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_TIM8|RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOB, ENABLE);//PB/E���Ƶ��IO,TIM8����pwm�������
	//���Ʒ�������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //�����������ģʽΪ�������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //��������ٶ�Ϊ 50MHZ
	GPIO_Init(GPIOB, &GPIO_InitStructure); //�����������úõ�GPIO_InitStructure ��������ʼ������
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //�����������ģʽΪ�������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //��������ٶ�Ϊ 50MHZ
	GPIO_Init(GPIOE, &GPIO_InitStructure); //�����������úõ�GPIO_InitStructure ��������ʼ������
	//pwm����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	//��ʼ���߼���ʱ��TIM8
	TIM_TimeBaseInitStrue.TIM_Period=arr;													//�Զ���װ��ֵ
	TIM_TimeBaseInitStrue.TIM_Prescaler=psc;											//Ԥ��Ƶϵ��
	TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1;					//
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up;			//���ϼ���
	TIM_TimeBaseInit(TIM8,&TIM_TimeBaseInitStrue);
	//��ʼ��Pwmͨ��TIM8_CH_OC1/2/3/4
 TIM_OCInitStructure.TIM_Pulse = 0;                         //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  //ʹ������Ƚ�״̬   //ʹ��������˿�
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//ʹ������Ƚ�N״̬
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//�� MOE=0 ���� TIM1 ����ȽϿ���״̬
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//�� MOE=0 ���� TIM1 ����Ƚ� N ����״̬
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 ����Ƚ�N���Ը�
	TIM_OC1Init(TIM8,&TIM_OCInitStructure);  
  TIM_OC2Init(TIM8,&TIM_OCInitStructure);
	TIM_OC3Init(TIM8,&TIM_OCInitStructure);  
  TIM_OC4Init(TIM8,&TIM_OCInitStructure);
	
	//ʹ��TIM8��CCR1�ϵ�Ԥװ�ؼĴ���
	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable); 
	TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable); 
	TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable); 
	TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable);
	
	TIM_CtrlPWMOutputs(TIM8,ENABLE);//�߼���ʱ����ʹ�ܺ���
	TIM_ARRPreloadConfig(TIM8,ENABLE);//ʹ��TIM8 ARR�ϵ�Ԥװ�ؼĴ���
	TIM_Cmd(TIM8, ENABLE);//ʹ��TIM8  

}

void change_pwm(u16 i)
{
	TIM_SetCompare1(TIM8,i);
	TIM_SetCompare2(TIM8,i);
	TIM_SetCompare3(TIM8,i);
	TIM_SetCompare4(TIM8,i);
	
}
void angle(float angle)
{
	TIM_SetCompare2(TIM1,angle / 180 * 20 + 5);
	
}
