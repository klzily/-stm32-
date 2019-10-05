#ifndef __VOICE_H
#define __LVOICE_H	 
#include "sys.h"


#define VOICE0 PDout(3)// PB5
#define shidu PDout(0)// PB5
#define wendu PDout(1)// PB5
#define feng PCout(13)// PB5

void voice_chese(void);
void voice_IOint(void);
extern u8 humidity;  	   
extern short temperature;
extern	u16 adcx,adcx1;
extern float temp1;
#endif

