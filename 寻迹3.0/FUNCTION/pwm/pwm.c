#include "pwm.h"
//#include "Device/Include/stm32f10x.h"   // Device header

void PWM_Init_TIM1(u16 arr, u16 psc)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;	 //定义一个引脚初始化的结构体
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; //定义一个定时中断的结构体
	TIM_OCInitTypeDef TIM_OCInitStructure; //定义一个 PWM 输出的结构
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1|RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO, ENABLE);//PB/E控制电机IO,TIM8控制pwm输出引脚
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM1, ENABLE);//重映射
	//pwm引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	//初始化高级定时器TIM1
	TIM_TimeBaseInitStrue.TIM_Period=arr;													//自动重装载值
	TIM_TimeBaseInitStrue.TIM_Prescaler=psc;											//预分频系数
	TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1;					//
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up;			//向上计数
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStrue);
	//初始化Pwm通道TIM8_CH_OC1/2/3/4
 TIM_OCInitStructure.TIM_Pulse = 0;                         //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  //使能输出比较状态   //使能输出到端口
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//使能输出比较N状态
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较空闲状态
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较 N 空闲状态
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 输出比较N极性高
	TIM_OC1Init(TIM1,&TIM_OCInitStructure);  
	TIM_OC2Init(TIM1,&TIM_OCInitStructure);

	//使能TIM8在CCR1上的预装载寄存器
//	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); 
//	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);

	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);//高级定时器的使能函数
	TIM_ARRPreloadConfig(TIM1,ENABLE);//使能TIM8 ARR上的预装载寄存器
	TIM_Cmd(TIM1, ENABLE);//使能TIM8  
//TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Disable); 
//TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Disable); 
}

void PWM_Init_TIM8(u16 arr, u16 psc)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;	 //定义一个引脚初始化的结构体
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue; //定义一个定时中断的结构体
	TIM_OCInitTypeDef TIM_OCInitStructure; //定义一个 PWM 输出的结构
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_TIM8|RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOB, ENABLE);//PB/E控制电机IO,TIM8控制pwm输出引脚
	//控制方向引脚
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //引脚输入输出模式为推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //引脚输出速度为 50MHZ
	GPIO_Init(GPIOB, &GPIO_InitStructure); //根据上面设置好的GPIO_InitStructure 参数，初始化引脚
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //引脚输入输出模式为推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //引脚输出速度为 50MHZ
	GPIO_Init(GPIOE, &GPIO_InitStructure); //根据上面设置好的GPIO_InitStructure 参数，初始化引脚
	//pwm引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	//初始化高级定时器TIM8
	TIM_TimeBaseInitStrue.TIM_Period=arr;													//自动重装载值
	TIM_TimeBaseInitStrue.TIM_Prescaler=psc;											//预分频系数
	TIM_TimeBaseInitStrue.TIM_ClockDivision=TIM_CKD_DIV1;					//
	TIM_TimeBaseInitStrue.TIM_CounterMode=TIM_CounterMode_Up;			//向上计数
	TIM_TimeBaseInit(TIM8,&TIM_TimeBaseInitStrue);
	//初始化Pwm通道TIM8_CH_OC1/2/3/4
 TIM_OCInitStructure.TIM_Pulse = 0;                         //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  //使能输出比较状态   //使能输出到端口
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;//使能输出比较N状态
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较空闲状态
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;//当 MOE=0 重置 TIM1 输出比较 N 空闲状态
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;//TIM1 输出比较N极性高
	TIM_OC1Init(TIM8,&TIM_OCInitStructure);  
  TIM_OC2Init(TIM8,&TIM_OCInitStructure);
	TIM_OC3Init(TIM8,&TIM_OCInitStructure);  
  TIM_OC4Init(TIM8,&TIM_OCInitStructure);
	
	//使能TIM8在CCR1上的预装载寄存器
	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable); 
	TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable); 
	TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable); 
	TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable);
	
	TIM_CtrlPWMOutputs(TIM8,ENABLE);//高级定时器的使能函数
	TIM_ARRPreloadConfig(TIM8,ENABLE);//使能TIM8 ARR上的预装载寄存器
	TIM_Cmd(TIM8, ENABLE);//使能TIM8  

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
