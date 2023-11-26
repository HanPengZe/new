#include "timer.h"
//#include "Device/Include/stm32f10x.h"   // Device header
#include "pwm.h"
#include "encoder.h"
#include "pid.h"




void  TIM6_Init(u16 arr, u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;   
	/* 配置时基结构体 */
	NVIC_InitTypeDef NVIC_InitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);//使能定时器时钟
	
	TIM_TimeBaseStructure.TIM_Prescaler = psc;   	//配置定时器时钟分频
	TIM_TimeBaseStructure.TIM_Period = arr;       //配置自动重装载寄存器的值  
	TIM_TimeBaseStructure.TIM_ClockDivision =0; //时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM向上计数模式
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);	//初始化TIM6时间基数单位

	TIM_ClearFlag(TIM6, TIM_FLAG_Update);	//清除更新中断，防止一打开中断立马产生中断
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);	//打开定时器更新中断
/*配置中断优先级*/
	NVIC_InitStruct.NVIC_IRQChannel = TIM6_IRQn;   //使能外部中断通道
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;   //使能外部中断通道
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1; //抢占优先级1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;    //响应优先级3
	NVIC_Init(&NVIC_InitStruct);
	TIM_Cmd(TIM6, ENABLE);	//使能定时器
	
}
void TIM6_IRQHandler(void)
{
	if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)==SET)
 {
   TIM_ClearITPendingBit(TIM6,TIM_IT_Update);   //===清除定时器1中断标志位
	 Encoder1=Read_Encoder(2);                     //取定时器2计数器的值
	 Encoder2=Read_Encoder(3);                     //取定时器4计数器的值  
	 Encoder3=Read_Encoder(4); 
	 Encoder4=Read_Encoder(5); 
	 Motor1=Incremental_PID1(Encoder1,Target1);    //===位置PID控制器
	 Motor2=Incremental_PID2(Encoder2,Target2);
	 Motor3=Incremental_PID3(Encoder3,Target3);
	 Motor4=Incremental_PID4(Encoder4,Target4);
   Set_Pwm1(Motor1);
	 Set_Pwm2(Motor2);
	 Set_Pwm3(Motor3);
	 Set_Pwm4(Motor4);
 } 
}
