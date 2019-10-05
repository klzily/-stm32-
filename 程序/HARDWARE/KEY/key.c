#include "key.h"
#include "lcd.h"
#include "usart.h"	  
#include "voice.h"
  #include "delay.h"  
unsigned char key[4][4];     //定义数组用来扫描键盘
char flag1=0,flag2=0,flag3=0,times=0,times_last=0,times1=0,times_last1=0;  //定义标志位
int temperature_0=10,temperature_1=27,humidity_1=30,humidity_0=10,liumination_1=3500;
int anqi=2200,anqi_0=0,youhai=1200,youhai_0=0,flag_13=0;
  unsigned char data2[]="设定目标:";   //定义字符串

 char tin=0,kai=1;    //定义标志位
char table[]={0,1,2,3,4,5,6,7,8,9};    //定义数组
int sum,sum2=0,sum3;    //累加值
int falg_z=0;
struct io_port           // IO口结构体
	{         
     GPIO_TypeDef *GPIO_x;             
     unsigned short GPIO_pin; 
  }; 		
	
static struct io_port key_output[4]  //低四位定义为输出结构体成员
	= 
	{ 

{GPIOE, GPIO_Pin_12}, 
{GPIOE, GPIO_Pin_14}, 
{GPIOB, GPIO_Pin_10}, 
{GPIOB, GPIO_Pin_12}  
}; 
 
static struct io_port key_input[4] //高四位定义为输入结构体成员
=
 {
{GPIOB, GPIO_Pin_14}, 
{GPIOD, GPIO_Pin_8},
 {GPIOD, GPIO_Pin_10}, 
{GPIOD, GPIO_Pin_12}

};
 
void KEY_Init(void)   //矩阵键盘初始化
{

 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_14;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOE, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_SetBits(GPIOE,GPIO_Pin_12|GPIO_Pin_14);						 //PB.5 输出高

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_12;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_SetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_10);						 //PB.5 输出高

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_SetBits(GPIOB,GPIO_Pin_14);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_12|GPIO_Pin_8;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOD, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
GPIO_SetBits(GPIOD,GPIO_Pin_12|GPIO_Pin_10|GPIO_Pin_8);		

	}
	
void update_key(void)    //更新键盘，扫描按键值
	
{
	unsigned char i,j;

   times_last=times;
	times_last1=times1;
for(i = 0; i < 4; i++)             //
	
	{
   GPIO_ResetBits(key_output[i].GPIO_x, key_output[i].GPIO_pin);  //高四位输出低电平，当按键按下时检测高四位电平
			for(j=0;j<4;j++)

		{
		
					if(GPIO_ReadInputDataBit(key_input[j].GPIO_x,key_input[j].GPIO_pin)==0)  //GPIO_ReadInputDataBit是判断某个IO口的某位的电平值得调用库函数
						
					{
							key[i][j]=1;
						   switch(i)
						
						{
							case 0:
						 {
              switch(j)
							 
							 {
								case 0: flag2=10;break;
								case 1: flag2=11;break;
                case 2: flag2=12;break;
								case 3: flag2=13,flag_13=1;break;
               }
             }
						 	while(GPIO_ReadInputDataBit(key_input[j].GPIO_x,key_input[j].GPIO_pin)==0) ; //G		 
            {
							if(flag2==10)
							{
								
								times=0;
								times1++;
								flag_13=0;
								
							}
							else
						 times++; 
						}
						 break;
						 
			
			
				case 1:
						 {
              switch(j)
							 
							 {
								case 0: kai=1,tin=0,times1=0,falg_z=0;break;
								case 1: flag1=9;break;
                case 2: flag1=6;break;
								case 3: flag1=3;;break;
               }
             }
						 			 	while(GPIO_ReadInputDataBit(key_input[j].GPIO_x,key_input[j].GPIO_pin)==0) ; //G		 
            times++; 
						 break;
             case 2:
						 {   
							 switch(j)
							 {
                case 0: flag1=0;break;
             		case 1: flag1=8;break;
                case 2: flag1=5;break;
								case 3: flag1=2;break;


               }
							  
             }
						 			 	while(GPIO_ReadInputDataBit(key_input[j].GPIO_x,key_input[j].GPIO_pin)==0) ; //G		 
            times++; 
						 break;
              case 3:
						 {   
							 switch(j)
							 {
                case 0: tin=1,kai=0;break;
             		case 1: flag1=7;break;
                case 2: flag1=4;break;
								case 3: flag1=1;break;


               }
							  
             }
						 			 	while(GPIO_ReadInputDataBit(key_input[j].GPIO_x,key_input[j].GPIO_pin)==0) ; //G		 
            times++; 
						 break;
             
            }
							
						   // if(i==1&&j==2)
				    // flag1=1;
          }
					
				else
					{
					 
					key[i][j] =0;	
						
					}
					
		}	
GPIO_SetBits(key_output[i].GPIO_x, key_output[i].GPIO_pin);  		
  }

}
void dispaly0()
{
	display12864_string( 0X80,"上限温度：");	
	display12864_string( 0X90,"下限温度：");		
	display12864_string( 0X88,"上限湿度：");	
	display12864_string( 0X98,"下限湿度：");
	display12864_umn3(0X85,temperature_1);
	display12864_umn3(0X87,add());
		display12864_string( 0X86,"C");
	display12864_umn3( 0X95,temperature_0); 
			display12864_string( 0X96,"C");
		display12864_umn3( 0X97,times1); 
	display12864_umn3( 0X8d,humidity_1); 
				display12864_string( 0X8e,"%");
	display12864_umn3( 0X9d,humidity_0); 
				display12864_string( 0X9e,"%");
}

void dispaly_0()
{
if(falg_z==0)
{
	  com_12864(0x01);
	  delay_ms(20);  
falg_z=1;
}
	
	display12864_string( 0X80,"上限烟雾：");	
	display12864_string( 0X90,"上限氨气：");	
	display12864_umn(0X85,youhai);
	display12864_umn( 0X95,anqi); 
		display12864_umn3( 0X98,times1); 
display12864_umn(0X88,add());



}
int add()    //根据按键值得出，目标值

{
	update_key() ;   //更新键盘，扫描按键值
	if(times_last!=times&&kai==0&&flag_13==0)
	{
switch(times)
	{
	 case 1:sum=table[flag1]; break;
	 case 2:sum=sum*10+table[flag1]; break;
    case 3:sum=sum*10+table[flag1]; break;
		 case 4:sum=sum*10+table[flag1]; break;
  }  
	
}
return sum;
}
void jiemian1()    //界面设计
{
	
		display12864_string( 0X98,"光照强度:");	
		display12864_umn(0x9d,adcx1);			
		display12864_string( 0X88,"氨气气体：");	
		display12864_umn(0x8d,adcx2);			  	    
		display12864_string( 0X90,"烟雾气体：");	
		display12864_umn(0x95,adcx);		
	
	
display12864_string(0X80,"温度"); 
display12864_umn2( 0X82,temperature);			
display12864_string( 0X84,"湿度");		
display12864_umn3( 0X86,humidity);                
display12864_string(0X87,"%");    
	
	

if(Res==1)
{
Res=0;
		printf("temperature:");   //温度
	printf("%d",temperature);   //温度
}
if(Res==2)
{
Res=0;
	printf("humidity:");   //湿度
	printf("%d",humidity);   //湿度
}
if(Res==3)
{
Res=0;
		printf("smog:");     //烟雾
	printf("%d",adcx);     //烟雾
}
if(Res==4)
{
Res=0;
		printf("liumination:");   //光照
	printf("%d",adcx1);   //光照
}

}
void jiemian()    //界面设计
{
add() ;//读物键盘值
	if(tin==0)
	{
		if(flag3==1)
		{
	flag3=0;	
				com_12864(0x01);
  }
jiemian1();

	}
	else
	{
	
  if(flag3==0)
	{
		flag3=1;
	com_12864(0x01);
	}


	  if(times1<=3)
	dispaly0();
	switch(times1)
	{
case 1:if(times1==1)
{
	if(flag_13==1)
	temperature_1=add();
	dispaly0();
	
}
break;//温度读物键盘值
case 2:
{
	if(flag_13==1)
temperature_0=add();
	dispaly0();
	
}break;
case 3:
{
	if(flag_13==1)
humidity_1=add();
	dispaly0(); //湿度读物键盘值
	
}break;//温度读物键盘值
case 4:
{
	if(flag_13==1)
humidity_0=add();
	dispaly0();
	
}
break;//湿度读物键盘值
case 5:
{
	if(flag_13==1)
youhai=add();
	dispaly_0();
	
}
break;//湿度读物键盘值
case 6:
{
	if(flag_13==1)
anqi=add();
	dispaly_0();
	
}break;//湿度读物键盘值



default:break;	
  }

  }

}
