#include "track.h"
#include "usart3.h"
int led1,led2,led3,led4,led5;//��¼��һ�ε�ƽ
void Track_Init(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD ,ENABLE);
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//IO�ܽ�ģʽ����Ϊ�������룬�������ܻ�ȡ�������������������ź�(�ߵ͵�ƽ)
	  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14 |GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	  GPIO_Init(GPIOD,&GPIO_InitStructure);

	
	
}

void Track(void)
{

//		//ֱ�� 			00011000 
//	if(LED1==0&&LED2==0&&LED3==1&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)
//	{
//		GoAhead();
////		break;
//	}
//	//���1				00110000
//	else if(LED1==0&&LED2==0&&LED3==1&&LED4==1&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//	}
//	//���2				01110000
//	else if(LED1==0&&LED2==1&&LED3==1&&LED4==1&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//	}
//	//���3				01100000
//	else if(LED1==0&&LED2==1&&LED3==1&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//	}//���4��ֱ���䣩			11100000
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
//	//���5				11000000
//	else if(LED1==1&&LED2==1&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			LeftSpin();
////			break;
//		}
//	}
//	//���5��ֱ���䣩			11110000
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
//		//�ҹնԳ�
//			//�ҹ�1				0000 1100
//	else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==1&&LED6==1&&LED7==0&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//	}
//	//�ҹ�2				0000 1110
//	else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==1&&LED6==1&&LED7==1&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//	}
//	//�ҹ�3				0000 0110
//	else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==1&&LED7==1&&LED8==0)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//	}//�ҹ�4��ֱ���䣩			0000 0111
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
//	//�ҹ�5				0000 0011
//	else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==1&&LED8==1)
//	{
//		while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//		{
//			RightSpin();
////			break;
//		}
//	}
//	//�ҹ�5��ֱ���䣩			0000 1111
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


////Ѱ��������


//	if(LED1==0&&LED8==0)
//	{
//				GoAhead();break;
//		if(LED1==1)//���
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
//		else if(LED1==0&&LED8==1)//�ҹ�
//		{	
//									RightSpin();
//			break;

//		
//		}
//		else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==1)//�ҹ�
//		{
//		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//			{
//				while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//				{
//						RightSpin();
//				}
//			}
//		}
//		else if(LED1==1&&LED2==1&&LED3==1&&LED4==1&&LED5==1&&LED6==1&&LED7==1&&LED8==1)//ֹͣ
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
//��  <-- 1 2 3 4 5 -->  ��
LED1;
LED2;
LED3;
LED4;
LED5;
//*��⵽  ���ߵ������  0*/
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
//��ת00011||00111||01111||10011||10111
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

else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==1)//��ת00001�������ߺ�
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
	
//		while(((LED3==0&&LED1==1))!=1)
//	{
//	LeftSpin();
//	}	
	
}
else if(LED1==1&&LED2==0&&LED3==0&&LED4==0&&LED5==0)//��ת10000�������ߺ�
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
	
//		while(((LED5==1&&LED3==0))!=1)
//	{
//	RightSpin();//1 2 3 4 5
//	}	
		
}

//��ת11100||11110||11001||11000||11101
else if((LED1==1&&LED2==1)&&((LED3==1&&LED4==0&&LED5==0)||(LED3==1&&LED4==1&&LED5==0)||(LED3==0&&LED4==0&&LED5==1)||(LED3==1&&LED4==0&&LED5==1)))
{
	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;	
//		while((LED3==0)!=1)
//	{
//	RightSpin();
//	}	
}
//��ת11100||11110||11000
//else if((LED1==1&&LED2==1)&&((LED3==1&&LED4==0&&LED5==0)||(LED1==1&&LED4==1&&LED5==0)))
//{
//	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;	
//		while((LED3==0)!=1)
//	{
//	RightSpin();
//	}	
//}

//else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0)//ֹͣλ
//{
//	led1=LED1;led2=LED2;led3=LED3;led4=LED4;led5=LED5;
//	Stop();
//}
else if(LED1==1&&LED2==1&&LED3==1&&LED4==1&&LED5==1)//���ȥ֮���ж���һ�εĵ�ƽ�����ж�
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
//Ѱ��������  ////*��⵽  ���� ���� ���  0*/

//	if(LED1==1&&LED5==1)
//	{
//				GoAhead();
//		if(LED1==0)//���(��ȴ���Ѱ��ģ��)
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
//		else if(LED5==0)//�ҹ�(��ȴ���Ѱ��ģ��)
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

		
//		else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0)//�ҹ�
//		{
//		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0&&LED6==0&&LED7==0&&LED8==0)
//			{
//				while((LED1==0&&LED2==0&&LED3==0&&LED4==1&&LED5==1&&LED6==0&&LED7==0&&LED8==0)!=1)
//				{
//						RightSpin();
//				}
//			}
//		}
//		else if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0)//ֹͣ
//		{
////		if(LED1==0&&LED2==0&&LED3==0&&LED4==0&&LED5==0)
////			{

//				Stop();
//			
////			}
//		}
/*******************************************
********************************************///Ѱ���������԰�
//if (LED1 == 1 && LED5 == 1)
//{
//	GoAhead();
//	led1 = LED1; led2= LED2; led3= LED3; led4 = LED4; led5 = LED5;
//	if (LED1 == 0 && LED2 == 0 && LED3 == 0 && LED4 == 0 && LED5 == 0)
//	{
//		if (led1 == 0)//��ת
//		{
//			while((LED1==1&&LED3==0&&LED5==1)!=1)
//			{ 
//				LeftSpin();
//			}	
//		}

//		else if (led5==0)//��ת
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

