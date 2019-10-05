
#include "lcd.h"

  #include "delay.h"       
 #define uchar unsigned char        
/*****????????*****/
void send_dat(uchar temp)
{
      uchar i;
	  for(i=0;i<8;i++)
	  {
	    if((temp<<i)&0x80)
		   RW_H;   //SID=RW_H
		  else 
		   RW_L;
       EN_L;       // sclk=EN_L
		   EN_H;
	  }
}
/*****???*****/
void com_12864(uchar com)
{	  
    RS_H;
    send_dat(0xf8);
	  send_dat(com&0xf0);//??? 
	  send_dat((com<<4)&0xf0);//???(???<<)
	  delay_ms(2);
}
/*****???*****/
void dat_12864(uchar data)
{	  
   RS_H;             //CS=RS
    send_dat(0xfa);
	  send_dat(data&0xf0);
	  send_dat((data<<4)&0xf0);
	  delay_ms(2);
}
/*****???LCD*****/
void init_12864()
{
   

	  delay_us(120);   
	  com_12864(0x30);
	  delay_us(40); 
	  com_12864(0x0c);
	  delay_us(120);  
	  com_12864(0x01);
	  delay_ms(12);  
}
/*****LCD?????*****/
void display12864_string(uchar pos,uchar *data)
{
  com_12864(pos);
while(*data!='\0') 
{
   dat_12864(*data);
    data++;
}

}

void display12864_umn(uchar pos,int data)
{
	char ge,shi,bai,qian;
  com_12864(pos);
 ge=data/1000;
	shi=data%1000/100;
	bai=data%1000%100/10;
	qian=data%10;
	 dat_12864(0x30+ge);
	 dat_12864(0x30+shi);
	 dat_12864(0x30+bai);
	 dat_12864(0x30+qian);
}

void display12864_umn1(uchar pos,int data)
{

  com_12864(pos);
	 dat_12864(0x30+data);

}
void display12864_umn2(uchar pos,float data)
{ 
	int data1=0;
	char ge,shi,bai,qian;
  com_12864(pos);
	data1=10*data;
 ge=data1/1000;
	shi=data1%1000/100;
	bai=data1%1000%100/10;
	qian=data1%10;
	 dat_12864(0x30+ge);
	 dat_12864(0x30+shi);
	dat_12864(0x2e);
	 dat_12864(0x30+bai);
}
void display12864_umn3(unsigned char pos,int data)
{
	char ge,shi;
  com_12864(pos);
 ge=data/10;
	shi=data%10;

	 dat_12864(0x30+ge);
	 dat_12864(0x30+shi);

}

