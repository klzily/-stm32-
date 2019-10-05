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
//ALIENTEK战舰STM32开发板实验31
//DHT11数字温湿度传感器 实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司  
 int main(void)
 {	 

	delay_init();	    	 //延时函数初始化	  
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	 	//串口初始化为9600
 	LED_Init();			     //LED端口初始化
init_12864();	
	 Adc_Init();
TIM3_Int_Init(49,7199); 
	KEY_Init();	 	
voice_IOint();
		
 	while(DS18B20_Init())	//DS18B20初始化	
	{

	 display12864_string(0X80,"DS18B20 Error"); 
	}
 	while(DHT11_Init())	//DHT11初始化	
	{
		 display12864_string(0X80,"DHT11 Error");  //没有检测的DHT11提示错误

	}								   
 com_12864(0x01);  //刷屏
	while(1)
	{	

feng=temp1;    
	laya();   //蓝牙模块
voice_chese();//温度湿
jiemian()   ;  //主界面

}


}
