#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "dht11.h" 
 #include "adc.h"
 #include "timer.h"
 #include "voice.h"
 #include "ds18b20.h"
	short temperature;  	    
	u8 humidity,flag=1;  
		u16 adcx=0,adcx1=0,adcx2=0;
		float temp,temp1;
//ALIENTEKս��STM32������ʵ��31
//DHT11������ʪ�ȴ����� ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾  
 int main(void)
 {	 

	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
 	LED_Init();			     //LED�˿ڳ�ʼ��
init_12864();	
	 Adc_Init();
TIM3_Int_Init(49,7199); 
	KEY_Init();	 	
voice_IOint();
		
 	while(DS18B20_Init())	//DS18B20��ʼ��	
	{

	 display12864_string(0X80,"DS18B20 Error"); 
	}
 	while(DHT11_Init())	//DHT11��ʼ��	
	{
		 display12864_string(0X80,"DHT11 Error");  //û�м���DHT11��ʾ����

	}								   
 com_12864(0x01);  //ˢ��
	while(1)
	{	

feng=temp1;    
	laya();   //����ģ��
voice_chese();//�¶�ʪ
jiemian()   ;  //������

}


}
