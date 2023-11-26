#include "encoder.h"
//#include "Device/Include/stm32f10x.h"   // Device header

void Encoder_Init_TIM2(void)//PA15/PB3
{
//	GPIO_InitTypeDef GPIO_InitStructure;//初始化GPIO-->PA0/PA1
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
//	TIM_ICInitTypeDef TIM_ICInitStruct;
	

//	
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使能GPIOA时钟
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//使能TIM2_CH1/2-->PA0/1
//	
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM2 ,ENABLE );
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);

	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

	
	//初始化TIM2
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//TIM向上计数模式
	TIM_TimeBaseInitStruct.TIM_Period = 65534;//配置自动重装载寄存器的值
	TIM_TimeBaseInitStruct.TIM_Prescaler = 0;//配置定时器时钟分频
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;	//时钟分频
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter=0;	//重复计数器无效0
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	//配置输入通道一
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;	//输入器不分频
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;	//映射到IC1
	TIM_ICInitStruct.TIM_ICFilter = 0;	//不滤波
	TIM_ICInit(TIM2, &TIM_ICInitStruct);
	//初始化通道二
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICFilter = 0;
	TIM_ICInit(TIM2, &TIM_ICInitStruct);
	
	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);	//使用编码器模式 3：CH1、CH2 同时计数，为四分频
	
  TIM_ClearFlag(TIM2, TIM_FLAG_Update);			//清理更新标志位
  //TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//使能更新中断

	
	TIM_SetCounter(TIM2,0);										//将CNT置零
	
	TIM_Cmd(TIM2, ENABLE);										//使能TIM2
}

//TIM3_CH1/2-->PA6/PA7
void Encoder_Init_TIM3(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6|GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	//配置时基
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	//TIM向上计数模式
	TIM_TimeBaseInitStruct.TIM_Period = 65534;
	//配置自动重装载寄存器的值
	TIM_TimeBaseInitStruct.TIM_Prescaler = 0x0;
	//配置定时器时钟分频
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	//时钟分频
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter=0;
	//重复计数器无效0
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);
	
	//配置输入
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;	//输入器不分频
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;	//映射到IC1
	TIM_ICInitStruct.TIM_ICFilter = 0;	//不滤波
	TIM_ICInit(TIM3, &TIM_ICInitStruct);
	
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICFilter = 0;
	TIM_ICInit(TIM3, &TIM_ICInitStruct);
	
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使能编码器模式3 0x0003
	
	
  TIM_ClearFlag(TIM3, TIM_FLAG_Update);	
	
	TIM_SetCounter(TIM3,0);
	
	TIM_Cmd(TIM3, ENABLE);
}


void Encoder_Init_TIM4(void)// PB6 PB7
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//配置时基
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	//TIM向上计数模式
	TIM_TimeBaseInitStruct.TIM_Period = 65534;
	//配置自动重装载寄存器的值
	TIM_TimeBaseInitStruct.TIM_Prescaler = 0x0;
	//配置定时器时钟分频
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	//时钟分频
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter=0;
	//重复计数器无效0
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStruct);
	
	//配置输入
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	//输入器不分频
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	//上升沿捕获
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	//映射到IC1
	TIM_ICInitStruct.TIM_ICFilter = 0;
	//不滤波
	TIM_ICInit(TIM4, &TIM_ICInitStruct);
	
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICFilter = 0;
	TIM_ICInit(TIM4, &TIM_ICInitStruct);
	
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	//使能编码器模式3 0x0003
	
  TIM_ClearFlag(TIM4, TIM_FLAG_Update);	
	
	TIM_SetCounter(TIM4,0);
	
	TIM_Cmd(TIM4, ENABLE);
}


void Encoder_Init_TIM5(void)//PA0 PA1
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//配置时基
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	//TIM向上计数模式
	TIM_TimeBaseInitStruct.TIM_Period = 65534;
	//配置自动重装载寄存器的值
	TIM_TimeBaseInitStruct.TIM_Prescaler = 0x0;
	//配置定时器时钟分频
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	//时钟分频
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter=0;
	//重复计数器无效0
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseInitStruct);
	
	//配置输入
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_1;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	//输入器不分频
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	//上升沿捕获
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	//映射到IC1
	TIM_ICInitStruct.TIM_ICFilter = 0;
	//不滤波
	TIM_ICInit(TIM5, &TIM_ICInitStruct);
	
	TIM_ICInitStruct.TIM_Channel = TIM_Channel_2;
	TIM_ICInitStruct.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitStruct.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitStruct.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInitStruct.TIM_ICFilter = 0;
	TIM_ICInit(TIM5, &TIM_ICInitStruct);
	
	TIM_EncoderInterfaceConfig(TIM5, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//使能编码器模式3 0x0003
	
	
  TIM_ClearFlag(TIM5, TIM_FLAG_Update);	
	
	TIM_SetCounter(TIM5,0);
	
	TIM_Cmd(TIM5, ENABLE);
}
//编码器初始化
void Encoder_Init_TIM(void)
{
	Encoder_Init_TIM2();
	Encoder_Init_TIM3();
	Encoder_Init_TIM4();
	Encoder_Init_TIM5();
}
//int Encoder_TIM;
//读取不同定时器编码器的CNT值
int Read_Encoder(u8 TIMX)
{
   int Encoder_TIM;
   switch(TIMX)
	 {
		 case 1:  Encoder_TIM= (short)TIM1 -> CNT;  TIM1 -> CNT=0;break;
	   case 2:  Encoder_TIM= (short)TIM2 -> CNT;  TIM2 -> CNT=0;break;
		 case 3:  Encoder_TIM= (short)TIM3 -> CNT;  TIM3 -> CNT=0;break;
		 case 4:  Encoder_TIM= (short)TIM4 -> CNT;  TIM4 -> CNT=0;break;
		 case 5:  Encoder_TIM= (short)TIM5 -> CNT;  TIM5 -> CNT=0;break;
		 case 8:  Encoder_TIM= (short)TIM8 -> CNT;  TIM8 -> CNT=0;break;
		 default: Encoder_TIM=0;
	 }
		return Encoder_TIM;    /*CNT清零*/
}



