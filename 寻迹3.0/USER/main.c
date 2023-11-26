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

//unsigned char i;          //��������
//unsigned char Send_Count; //������Ҫ���͵����ݸ���
//static float a;
/************************************************
 ALIENTEK ��ӢSTM32F103������ʵ��0
 ����ģ��
 ע�⣬�����ֲ��е��½������½�ʹ�õ�main�ļ� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
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
	 	SystemInit();  //ϵͳʱ�ӵĳ�ʼ��
		PWM_Init_TIM1(199, 7199);
		delay_init();//��ʱ������ʼ��	
//		uart_init(115200);           //��ʼ������1
		usart3_init(9600);
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�ж����ȼ�����	 
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
