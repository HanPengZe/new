#include "stm32f10x.h"
#include "encoder.h"
#include "pwm.h"
#include "pid.h"
#include "timer.h"
#include "sys.h"
#include "usart3.h"
#include "usart.h"
#include "delay.h"
#include "Debug_DataScope.h"
#include "track.h"
#include "usart2.h"

//unsigned char i;          //计数变量
//unsigned char Send_Count; //串口需要发送的数据个数
//static float a;
/************************************************
 ALIENTEK 精英STM32F103开发板实验0
 工程模板
 注意，这是手册中的新建工程章节使用的main文件 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
extern int Encoder1;
extern int Encoder2;
extern int Encoder3;
extern int Encoder4;
extern u8 Mark;
extern u8 res;
int step=0;
extern u8 Res;
//extern u8 Up;
 int main(void)
 {	
	 	SystemInit();  //系统时钟的初始化
		PWM_Init_TIM1(199, 7199);
		delay_init();//延时函数初始化	
//		uart_init(115200);           //初始化串口1
		usart3_init(9600);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //中断优先级分组	 
		PWM_Init_TIM8(7199,0);	 
		Encoder_Init_TIM();
		TIM6_Init(99,7199);
  	Track_Init();
	 usart2_init(115200);
    while(1)
	  {
			Bluetooth();
			if(res=='T'&&Mark=='K')
			{Track();
			}
			if((Res=='A'||Res=='B')&&step==0)
			{
				GoAhead();
				delay_ms(500);
				step=1;
			}
//						if(Res=='A'&&step==1)
//			{
//				GoAhead();
//				delay_ms(900);
//				RightSpin();
//				delay_ms(300);
//				step++;
//			}
//									if(Res=='B'&&step==1)
//			{
//				GoAhead();
//				delay_ms(900);
//				LeftSpin();
//				delay_ms(300);
//				step++;
//			}

			

			if(step!=0)
			{
				Track();
			}
			
			
//			Debug_addData(Encoder1,1);
//			Debug_addData(Target1,2);
//			Debug_addData(Encoder2,3);	
//			Debug_addData(Target2,4);	
//			Debug_addData(Encoder3,5);
//			Debug_addData(Target3,6);
//			Debug_addData(Encoder4,7);	
//			Debug_addData(Target4,8);	
//			Debug_show(8);  
//			delay_ms(50);

	  }
 }
