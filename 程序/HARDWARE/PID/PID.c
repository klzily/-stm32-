#include "pid.h"
#include "timer.h"

#define uchar unsigned char
u8 start=0,flag_moter_start=0,LED_F=0;
u16 pwm1=1200,pwm2=1200;
float P0=0,I0=0,D0=0,error=0,error1=0; //����ֲ�����
struct
{
  float current_error0; //��ǰ��ֵ
  float last_error0; //�ϴβ�ֵ
  float prev_error0; //���ϴβ�ֵ
}PID_M; //����һ����Ϊ PID_M �Ľṹ��

float PID_M_Kp0 =0.05,PID_M_Ki0 = 0.005,PID_M_Kd0 =0.001;   
//       0.1                  0.015         0.
float PID_m_add0=0 ; //PID ���������
//////////////////////////////////////////////////////////////////////////////////end ��������////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////start PID �����ı�д////////////////////////////////////////////////////////////////////////
void MOtor_init()				  //pid��ʼ��
{
 PID_M.current_error0=0.0;		  
 PID_M.last_error0=0.0;
 PID_M.prev_error0=0.0;
 PID_m_add0=1400;
}
void Motor_ctl0(uchar mubiao,uchar shishi)
{


	if(shishi>=0)
	{
	
  PID_M.prev_error0=PID_M.last_error0; //����ÿ�εĲ�ֵ
  PID_M.last_error0=PID_M.current_error0; //����ÿ�εĲ�ֵ
  PID_M.current_error0=shishi-mubiao; //����ÿ�εĲ�ֵ	
	}
	else
	{
		
  PID_M.prev_error0=PID_M.last_error0; //����ÿ�εĲ�ֵ
  PID_M.last_error0=PID_M.current_error0; //����ÿ�εĲ�ֵ
  PID_M.current_error0=mubiao-shishi; //����ÿ�εĲ�ֵ

  }
  P0=PID_M_Kp0*(PID_M.current_error0-PID_M.last_error0); //���� P �����ʽ
  I0=PID_M_Ki0*PID_M.current_error0; //���� I �����ʽ
  D0=PID_M_Kd0*(PID_M.current_error0-2*PID_M.last_error0+PID_M.prev_error0); //΢�� D �����ʽ

if(P0+I0+D0>(int)(P0+I0+D0)+0.5)
PID_m_add0=P0+I0+D0+PID_m_add0+1; //����� PID ����ֵ���
else 
PID_m_add0=P0+I0+D0+PID_m_add0;


	
}
