#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED4 PCout(9)// PB5
#define LED3 PCout(8)// PB5
#define LED2 PCout(7)// PE5	
#define LED1 PCout(6)// PE5	
#define LED0 PAout(8)// PE5	
void LED_Init(void);//初始化
void zoo(void);
void one(void);
void two(void);	
void three(void);
void four(void);
void five(void);
#endif
