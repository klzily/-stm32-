#include "voice.h"
#include "delay.h"
#include "key.h"
#include "led.h"
void voice_IOint()
{
  GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOD ,ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_1|GPIO_Pin_0;				 //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOD, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
 GPIO_ResetBits(GPIOD,GPIO_Pin_3|GPIO_Pin_1|GPIO_Pin_0);	

	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;				 //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
 GPIO_ResetBits(GPIOC,GPIO_Pin_13);	

}
void voice_chese()
{ 

if((temperature/10<temperature_0)&&kai==1)  //�¶Ȳ����
{
	
wendu=0;           //����Ƭ

}
else
{
	
wendu=1;
	
}
if((humidity<humidity_0)&&kai==1)   //ʪ�ȹ���
{
shidu=1;	       //��ʪ��

}
else
	shidu=0;	
       //�¶ȸߡ�ʪ�ȹ��ߡ�����������
if(kai==1&&(humidity<humidity_0||(temperature/10)<temperature_0||(temperature/10)>=temperature_1||humidity>=humidity_1||adcx2>=anqi||adcx>=youhai))
{
VOICE0=0;       //������
delay_ms(10);
VOICE0=1;
delay_ms(10);
temp1=1;           //����������־


}
else
{
VOICE0=1;
temp1=0;
}

if(adcx1<=300)
{
 five();
}
else if(adcx1<=800)
{
four();
}
else if(adcx1<=1000)
{
three();
}
else if(adcx1<=1300)
{
two();
}
else if(adcx1<=1800)
{
one();
}
else
{

 zoo();
}	

}

