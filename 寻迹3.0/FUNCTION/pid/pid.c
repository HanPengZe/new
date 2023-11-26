#include "pid.h"
//#include "Device/Include/stm32f10x.h"   // Device header


incrementalpid_t pid[4];
float Kp1=9, Ki1=3,Kd1=0;				        //Kp, Ki,Kd����ϵ��
float Kp2=9, Ki2=3,Kd2=0;				        //Kp, Ki,Kd����ϵ��
float Kp3=9, Ki3=3,Kd3=0;				        //Kp, Ki,Kd����ϵ��
float Kp4=9, Ki4=3,Kd4=0;		 		        //Kp, Ki,Kd����ϵ��
int Motor1;
int Encoder1;
int Motor2;
int Encoder2;
int Motor3;
int Encoder3;
int Motor4;
int Encoder4;
int Target1;
int Target2;
int Target3;
int Target4;

/**************************************************************************
�������ܣ�����PI������
��ڲ���������������ֵ��Ŀ���ٶ�
����  ֵ�����PWM
��������ʽ��ɢPID��ʽ 
pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)+Kd[e(k)-2e(k-1)+e(k-2)]
e(k)������ƫ�� 
e(k-1)������һ�ε�ƫ��  �Դ����� 
pwm�����������
�����ǵ��ٶȿ��Ʊջ�ϵͳ���棬ֻʹ��PI����
pwm+=Kp[e��k��-e(k-1)]+Ki*e(k)
**************************************************************************/
int Incremental_PID1(int Encoder1,int Target1)
{ 	
		pid[0].err=Target1-Encoder1;                //����ƫ��
	pid[0].pwm+=Kp1*(pid[0].err-pid[0].err_last)+Ki1*pid[0].err+Kd1*(pid[0].err-2*pid[0].err_last+pid[0].err_beforeLast);   //����ʽPID������
         //===PWM������7200 ������7100
	 if(pid[0].pwm<-7100)  
		 pid[0].pwm = -7100;
	 else if(pid[0].pwm>7100)   
		 pid[0].pwm =  7100;
	 pid[0].err_beforeLast=pid[0].err_last;
		pid[0].err_last=pid[0].err;	                   //������һ��ƫ�� 
	return pid[0].pwm;                         //�������
}
int Incremental_PID2(int Encoder2,int Target2)
{ 	
	pid[1].err=Target2-Encoder2;                //����ƫ��
	pid[1].pwm+=Kp2*(pid[1].err-pid[1].err_last)+Ki2*pid[1].err+Kd2*(pid[1].err-2*pid[1].err_last+pid[1].err_beforeLast);   //����ʽPID������
         //===PWM������7200 ������7100
	 if(pid[1].pwm<-7100)  
		 pid[1].pwm = -7100;
	 else if(pid[1].pwm>7100)   
		 pid[1].pwm =  7100;
	 pid[1].err_beforeLast=pid[1].err_last;
		pid[1].err_last=pid[1].err;	                   //������һ��ƫ�� 
	return pid[1].pwm;                         //�������
}
int Incremental_PID3(int Encoder3,int Target3)
{ 	
	pid[2].err=Target3-Encoder3;                //����ƫ��
	pid[2].pwm+=Kp3*(pid[2].err-pid[2].err_last)+Ki3*pid[2].err+Kd3*(pid[2].err-2*pid[2].err_last+pid[2].err_beforeLast);   //����ʽPID������
         //===PWM������7200 ������7100
	 if(pid[2].pwm<-7100)  
		 pid[2].pwm = -7100;
	 else if(pid[2].pwm>7100)   
		 pid[2].pwm =  7100;
	 pid[2].err_beforeLast=pid[2].err_last;
		pid[2].err_last=pid[2].err;	                   //������һ��ƫ�� 
	return pid[2].pwm;                         //�������
}
int Incremental_PID4(int Encoder4,int Target4)
{ 	
	pid[3].err=Target4-Encoder4;                //����ƫ��
	pid[3].pwm+=Kp4*(pid[3].err-pid[3].err_last)+Ki4*pid[3].err+Kd4*(pid[3].err-2*pid[3].err_last+pid[3].err_beforeLast);   //����ʽPID������
         //===PWM������7200 ������7100
	 if(pid[3].pwm<-7100)  
		 pid[3].pwm = -7100;
	 else if(pid[3].pwm>7100)   
		 pid[3].pwm =  7100;
	 pid[3].err_beforeLast=pid[3].err_last;
		pid[3].err_last=pid[3].err;	                   //������һ��ƫ�� 
	return pid[3].pwm;                         //�������
}


void Set_Pwm1(int moto1)//��ֵ��PWM�Ĵ���
{
 if(moto1>0) AIN1=0,   AIN2=1;
	else      AIN1=1,   AIN2=0;
	TIM8->CCR1=myabs(moto1);
}
void Set_Pwm2(int moto2)//��ֵ��PWM�Ĵ���
{
 if(moto2>0) ain1=1,   ain2=0;
	else      ain1=0,   ain2=1;
	TIM8->CCR2=myabs(moto2);
}
void Set_Pwm3(int moto3)//��ֵ��PWM�Ĵ���
{
 if(moto3>0) bin1=1,   bin2=0;
	else      bin1=0,   bin2=1;
	TIM8->CCR3=myabs(moto3);
}
void Set_Pwm4(int moto4)//��ֵ��PWM�Ĵ���
{
 if(moto4>0) BIN1=0,   BIN2=1;
	else      BIN1=1,   BIN2=0;
	TIM8->CCR4=myabs(moto4);
}
int myabs(int a) //ȡ����ֵ
{ 		   
	 int temp;
	 if(a<0)  temp=-a;  
	 else temp=a;
	 return temp;
}

