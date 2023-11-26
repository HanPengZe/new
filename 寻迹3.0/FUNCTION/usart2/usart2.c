#include "usart2.h"
u8 Res;
void usart2_init(u32 bound)
{
		GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
     
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//ʹ��GPIOAʱ��
	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);//ʹ��USART2ʱ��
  
    //USART2_TX   GPIOA.2
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; //PA.2
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;    //�����������
		GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.2
   
		//USART2_RX      GPIOA.10��ʼ��
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//P3
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
		GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.3  
 
		//Usart1 NVIC ����
		NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2 ;//��ռ���ȼ�3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //�����ȼ�3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;            //IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);    //����ָ���Ĳ�����ʼ��VIC�Ĵ���
  
    //USART ��ʼ������
 
    USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;    //�շ�ģʽ
 
		USART_Init(USART2, &USART_InitStructure); //��ʼ������2
		USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
		USART_Cmd(USART2, ENABLE);                    //ʹ�ܴ���2
}

int test=0;
void USART2_IRQHandler()
{
	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)  //�����ж�
        {
        Res =USART_ReceiveData(USART2);    //��ȡ���յ�������			
							test++;
				}
		USART_ClearITPendingBit(USART2,USART_IT_RXNE);
				
}
