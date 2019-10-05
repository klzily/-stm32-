#ifndef __LCD_H
#define __LCD_H		
#include "sys.h"	 

#define RS_H GPIO_SetBits(GPIOB,GPIO_Pin_8) //RS=1   4PIN
#define RS_L GPIO_ResetBits(GPIOB,GPIO_Pin_8) //RS=0

#define RW_H GPIO_SetBits(GPIOB,GPIO_Pin_7) //RW=1    5PIN
#define RW_L GPIO_ResetBits(GPIOB,GPIO_Pin_7);  //RW = 0

#define EN_H GPIO_SetBits(GPIOB,GPIO_Pin_6);    //EN = 1   6PIN
#define EN_L GPIO_ResetBits(GPIOB,GPIO_Pin_6);  //EN = 0
void display12864_string(unsigned char pos,unsigned char *data);
void init_12864(void);
void dat_12864(unsigned char data);
void com_12864(unsigned char com);
void send_dat(unsigned char temp);
void display12864_umn(unsigned char pos,int data);
void display12864_umn1(unsigned char  pos,int data);
void display12864_umn2(unsigned char  pos,float data);
void display12864_umn3(unsigned char pos,int data);
#endif
