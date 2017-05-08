#include "reg52.h"		  //此文件中定义了单片机的一些特殊功能寄存器

typedef unsigned char u8;
typedef unsigned int u16;	  //对数据类型进行声明

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

#define GPIO_key  P1		//按键
#define GPIO_dig  P0		//数码管

u8 keyvalue;

u8 code shumaguan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};       //显示0~F	 0x3f 0011 1111 高电平亮

void delay (u16 i)
   {
	  while (i--);
   }				   //延时函数

void keydown()		  //按键判断函数
   {   
       
	   GPIO_key=0x0f;   //高位为低电平 低位为高电平   0000 1111  p1^7~p1^0   
	   if (GPIO_key!=0x0f)
	      {	   
		      delay(1000);   //延时10ms  消抖
				if (GPIO_key!=0x0f)
				 {
				   //测试列
						 GPIO_key=0x0f;

						 switch(GPIO_key)
							{
								case(0x07):keyvalue=0;break;	   //	 0000 0111	  第一列
								case(0x0b):keyvalue=1;break;	   //	 0000 1011	  第二列
								case(0x0d):keyvalue=2;break;	   //	 0000 1101	  第三列
								case(0x0e):keyvalue=3;break;	   //	 0000 1110	  第四列
				   			 }
				   //测试行
				   GPIO_key=0xf0;

						 switch(GPIO_key)
							{
								case(0x70):keyvalue=keyvalue   ;break;	       // 0111 0000    在第一行
								case(0xb0):keyvalue=keyvalue+4 ;break;      // 1011 0000	   在第二行
								case(0xd0):keyvalue=keyvalue+8 ;break;	   // 1101 0000	   在第三行
								case(0xe0):keyvalue=keyvalue+12;break;	   // 1110 1111    在第四行	
				   
				            }
				 
				  while(GPIO_key!=0xf0)	 //检测按键松手检测
				  {
			       	delay(1000);
			      }
				
			}

		  }
	}
	  
				   																				
		  

   
      
void main()
	  {
		   LSA=0;
		   LSB=0;
		   LSC=0;	  //控制138译码器的Y0输出低电平
		   
		   
		   while(1)
		   {
		      keydown();			//按键判断函数
		      GPIO_dig=shumaguan[keyvalue];
		   }
	  	  
	  }






