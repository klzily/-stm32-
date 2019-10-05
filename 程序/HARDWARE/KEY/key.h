#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
extern unsigned char key[4][4]; 
extern char flag1,times;
extern char tin,kai;
void KEY_Init(void);		 
void update_key(void);
int add(void) ;
void jiemian(void) ;
extern u8 humidity;  	   
extern short temperature;
extern	u16 adcx,adcx1,adcx2;
extern int temperature_1,humidity_1,liumination_1,temperature_0,humidity_0;
extern int anqi,anqi_0,youhai,youhai_0;
void jiemian1(void);    //界面设计
#endif

