#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED4 PCout(9)// PB5
#define LED3 PCout(8)// PB5
#define LED2 PCout(7)// PE5	
#define LED1 PCout(6)// PE5	
#define LED0 PAout(8)// PE5	
void LED_Init(void);//��ʼ��
void zoo(void);
void one(void);
void two(void);	
void three(void);
void four(void);
void five(void);
#endif
