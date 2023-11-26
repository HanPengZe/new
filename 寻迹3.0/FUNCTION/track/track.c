#include "track.h"
#include "usart3.h"
int led1,led2,led3,led4,led5;//记录上一次电平
void Track_Init(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD ,ENABLE);
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//IO管脚模式配置为浮空输入，这样就能获取传感器传回来的数字信号(高低电平)
	  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14 |GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	  GPIO_Init(GPIOD,&GPIO_InitStructure);

	
	
}

void Track(void)
{

//		//直走 			00011000 
//	if(LED1==0&&LED2==0&&LED3==1&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)
//	{
//		GoAhead();
////		break;
//	}
//	//左拐1				00110000
//	else if(LED1==0&&LED2==0&&LED3==1&&LED4==1&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//	}
//	//左拐2				01110000
//	else if(LED1==0&&LED2==1&&LED3==1&&LED4==1&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//	}
//	//左拐3				01100000
//	else if(LED1==0&&LED2==1&&LED3==1&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//	}//左拐4（直角弯）			11100000
//	else if(LED1==1&&LED2==1&&LED3==1&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//		{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//		}
//	}
//	//左拐5				11000000
//	else if(LED1==1&&LED2==1&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//	}
//	//左拐5（直角弯）			11110000
//		else if(LED1==1&&LED2==1&&LED3==1&&LED4==1&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//		{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//		}
//	}
//		
//		//右拐对称
//			//右拐1				0000 1100
//	else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==1&&LED6==1&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//	}
//	//右拐2				0000 1110
//	else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==1&&LED6==1&&LED7==1&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//	}
//	//右拐3				0000 0110
//	else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==1&&LED7==1&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//	}//右拐4（直角弯）			0000 0111
//	else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==1&&LED7==1&&LED8==1)
//	{
//		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//		{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//		}
//	}
//	//右拐5				0000 0011
//	else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==1&&LED8==1)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//	}
//	//右拐5（直角弯）			0000 1111
//		else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==1&&LED6==1&&LED7==1&&LED8==1)
//	{
//		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//		{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//		}

//	}
//		else if(LED1==1&&LED2==1&&LED3==1&&LED4==1&&LED5==1&&LED6==1&&LED7==1&&LED8==1)
//		{
//			
//			if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//			{
//				Stop();
//			}

//		}
//	}		
//		

//}
//	


////寻迹升级版


//	if(LED1==0&&LED8==0)
//	{
//				GoAhead();break;
//		if(LED1==1)//左拐
//		{
//		if(LED1==0&&LED4==0&&LED5==0&&LED8==0)
//			{
//				while((LED4==1&&LED5==1)!=1)
//				{
//						LeftSpin();
//				}
//			}
//		
//		}
//		else if(LED1==0&&LED8==1)//右拐
//		{	
//									RightSpin();
//			break;

//		
//		}
//		else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==1)//右拐
//		{
//		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//			{
//				while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//				{
//						RightSpin();
//				}
//			}
//		}
//		else if(LED1==1&&LED2==1&&LED3==1&&LED4==1&&LED5==1&&LED6==1&&LED7==1&&LED8==1)//停止
//		{
//		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//			{
//			while(1)
//			{
//				Stop();
//			}
//			}
//		}
//	}	


/*********************************
*********************************/
//左  <-- 1 2 3 4 5 -->  右
LED1;
LED2;
LED3;
LED4;
LED5;
//*检测到  黑线灯灭输出  0*/
//if((LED1&&LED5==1)&&((LED2==0&&LED3==0)||(LED3==0&&LED4==0)||(LED2==1&&LED3==0&&LED4==1)||(LED2==0&&LED3==0&&LED4==0)))
//{
//	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
//	GoAhead();
//}
if(LED1==1&&LED3==0&&LED5==1)
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
	GoAhead();

}
//左转00011||00111||01111||10011||10111
else if((LED5==1&&LED4==1)&&((LED1==0&&LED2==0&&LED3==0)||(LED1==0&&LED2==0&&LED3==1)||(LED1==0&&LED2==1&&LED3==1)||(LED1==1&&LED2==0&&LED3==0)))
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
//		while((LED3==0)!=1)
//	{
//	LeftS	pin();
//	}	
}
else if((LED5==1&&LED4==1)&&(LED1==1&&LED2==0&&LED3==1))//  10111	
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
	
		while((LED3==0&&LED1==1)!=1)
	{
	LeftSpin();
	}	
		
}
else if((LED1==1&&LED2==1)&&(LED3==1&&LED4==0&&LED5==1))//  11101
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
	
		while(((LED5==1&&LED3==0))!=1)
	{
	RightSpin();//1 2 3 4 5
	}	
		
}

else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==1)//左转00001（干扰线后）
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
	
//		while(((LED3==0&&LED1==1))!=1)
//	{
//	LeftSpin();
//	}	
	
}
else if(LED1==1&&LED2==0&&LED3==0&&LED4==0&&LED5==0)//右转10000（干扰线后）
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
	
//		while(((LED5==1&&LED3==0))!=1)
//	{
//	RightSpin();//1 2 3 4 5
//	}	
		
}

//右转11100||11110||11001||11000||11101
else if((LED1==1&&LED2==1)&&((LED3==1&&LED4==0&&LED5==0)||(LED3==1&&LED4==1&&LED5==0)||(LED3==0&&LED4==0&&LED5==1)||(LED3==1&&LED4==0&&LED5==1)))
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;	
//		while((LED3==0)!=1)
//	{
//	RightSpin();
//	}	
}
//右转11100||11110||11000
//else if((LED1==1&&LED2==1)&&((LED3==1&&LED4==0&&LED5==0)||(LED1==1&&LED4==1&&LED5==0)))
//{
//	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;	
//		while((LED3==0)!=1)
//	{
//	RightSpin();
//	}	
//}

//else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0)//停止位
//{
//	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
//	Stop();
//}
else if(LED1==1&&LED2==1&&LED3==1&&LED4==1&&LED5==1)//冲出去之后判断上一次的电平做出判断
{
	if((led5==0)||(led4==0)||(led4==0&&led5==0)||(led3==0&&led4==0&&led5==0)||(led2==0&&led3==0&&led4==0&&led5==0)||(LED3==0&&LED4==0))//1 2 3 4 5
	{
		while(((LED5==1&&LED3==0))!=1)
	{
	RightSpin();//1 2 3 4 5
	}	
	}
	else if((led1==0)||(led2==0)||(led1==0&&led2==0)||(led1==0&&led2==0&&led3==0)||(led1==0&&led2==0&&led3==0&&led4==0)||(LED2==0&&LED3==0))
	{
		while(((LED3==0&&LED1==1))!=1)
	{
	LeftSpin();
	}	
	}
	else if(led1==0&&led2==0&&led3==0&&led4==0&&led5==0)
	{
		Stop();
	}
}
/***************************************************	
*//////////////////////////////////////////////////
//寻迹升级版  ////*检测到  黑线 灯灭 输出  0*/

//	if(LED1==1&&LED5==1)
//	{
//				GoAhead();
//		if(LED1==0)//左拐(弯度大于寻迹模块)
//		{
//		if(LED1==1)
//			{
//				while((LED3==0)!=1)
//				{
//						LeftSpin();
//				}
//			}
//		
//		}
//		else if(LED5==0)//右拐(弯度大于寻迹模块)
//		{
//		if(LED1==1&&LED2==1&&LED3==1&&LED4==1&&LED5==1)
//			{
//				while((LED3==0)!=1)
//				{
//						RightSpin();
//				}
//			}
//		
//		}

		
//		else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0)//右拐
//		{
//		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//			{
//				while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//				{
//						RightSpin();
//				}
//			}
//		}
//		else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0)//停止
//		{
////		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0)
////			{

//				Stop();
//			
////			}
//		}
/*******************************************
********************************************///寻迹升级测试版
//if (LED1 == 1 && LED5 == 1)
//{
//	GoAhead();
//	led1 = LED1; led2= LED2; led3= LED3; led4 = LED4; led5 = LED5;
//	if (LED1 == 0 && LED2 == 0 && LED3 == 0 && LED4 == 0 && LED5 == 0)
//	{
//		if (led1 == 0)//左转
//		{
//			while((LED1==1&&LED3==0&&LED5==1)!=1)
//			{ 
//				LeftSpin();
//			}	
//		}

//		else if (led5==0)//右转
//		{
//			while ((LED1 == 1 && LED3 == 0 && LED5 == 1) != 1)
//			{
//				RightSpin();
//			}
//		}
//		else if (led1==0&&led2==0&&led3==0&&led4==0&&led5==0)
//		{
//			Stop();
//		}

//	}

//	}	


}

