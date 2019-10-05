#include "pid.h"
#include "timer.h"

#define uchar unsigned char
u8 start=0,flag_moter_start=0,LED_F=0;
u16 pwm1=1200,pwm2=1200;
float P0=0,I0=0,D0=0,error=0,error1=0; //定义局部变量
struct
{
  float current_error0; //当前差值
  float last_error0; //上次差值
  float prev_error0; //上上次差值
}PID_M; //定义一个名为 PID_M 的结构体

float PID_M_Kp0 =0.05,PID_M_Ki0 = 0.005,PID_M_Kd0 =0.001;   
//       0.1                  0.015         0.
float PID_m_add0=0 ; //PID 的增量输出
//////////////////////////////////////////////////////////////////////////////////end 变量定义////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////start PID 函数的编写////////////////////////////////////////////////////////////////////////
void MOtor_init()				  //pid初始化
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
	
  PID_M.prev_error0=PID_M.last_error0; //更新每次的差值
  PID_M.last_error0=PID_M.current_error0; //更新每次的差值
  PID_M.current_error0=shishi-mubiao; //更新每次的差值	
	}
	else
	{
		
  PID_M.prev_error0=PID_M.last_error0; //更新每次的差值
  PID_M.last_error0=PID_M.current_error0; //更新每次的差值
  PID_M.current_error0=mubiao-shishi; //更新每次的差值

  }
  P0=PID_M_Kp0*(PID_M.current_error0-PID_M.last_error0); //比例 P 输出公式
  I0=PID_M_Ki0*PID_M.current_error0; //积分 I 输出公式
  D0=PID_M_Kd0*(PID_M.current_error0-2*PID_M.last_error0+PID_M.prev_error0); //微分 D 输出公式

if(P0+I0+D0>(int)(P0+I0+D0)+0.5)
PID_m_add0=P0+I0+D0+PID_m_add0+1; //电机的 PID 增量值输出
else 
PID_m_add0=P0+I0+D0+PID_m_add0;


	
}
