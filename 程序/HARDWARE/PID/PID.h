#ifndef __MOTOR_H
#define __MOTOR_H		
#include "sys.h"	 
#define uchar unsigned char
extern u8 flag_moter_start;
void qidon(void);
void Motor_ctl0(uchar mubiao,uchar shishi);
void MOtor_init(void);				  //pid≥ı ºªØ
extern u16 pwm1,pwm2;

#endif
