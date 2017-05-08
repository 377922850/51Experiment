#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;	//对数据类型进行声明定义


sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;		 //将p22 p23 p24 定义为 LSA LSB LSC 

u8 code shumaguan[]={0x3f,0x5b,0x6d,0x00,0x6e,0x67,0x39};	  	// cqy520

void delay (u16 i)
     {
	   while(i--);
     }				  //i=1时，大约延时10us

void digdisplay()
     {
	   	 u8 i;
	     for (i=0;i<7;i++)	   //循环7次
		   {
		   switch(i)	 //位选，选择点亮的数码管
		         {
			        case (0): LSA=0;LSB=0;LSC=0;break;	 //显示第0位	由138控制y0输出低电平
			        case (1): LSA=1;LSB=0;LSC=0;break;   //显示第1位
			        case (2): LSA=0;LSB=1;LSC=0;break;	 //显示第2位
			        case (3): LSA=1;LSB=1;LSC=0;break;	 //显示第3位
			        case (4): LSA=0;LSB=0;LSC=1;break;	 //显示第4位
					case (5): LSA=1;LSB=0;LSC=1;break;	 //显示第5位
					case (6): LSA=0;LSB=1;LSC=1;break;	 //显示第6位

                 }
		   	 P0=shumaguan[i];	//发送段码
			 delay (100);		//间隔一段时间扫描
			 P0=0x00;			//消隐
		    }
	 }



void main ()
 		{   while(1)
		   {  
		   		    digdisplay();  //数码管显示函数
			}
		}	 










