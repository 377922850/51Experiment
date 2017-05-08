//led点阵     又D口和P0口   竖着从上到下为D7~D1   横着从左到右为P07~P00

#include "reg52.h"
#include "intrins.h"		 //调用_nop_   空循环一个机器指令的时间

sbit rclk=P3^5;			 //		 存贮寄存器时钟
sbit srclk=P3^6;		 //		 移位寄存器时钟 
sbit ser=P3^4;			 //		 串行输入

typedef unsigned char u8;
typedef unsigned int u16;	   //对数据类型进行声明

u8 ledhang[]={0x18,0x24,0x22,0x11,0x11,0x22,0x24,0x18};	   //行
u8 ledlie[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};	   //列


void delay(u16 i)
    {
	   	while(i--);
		}

void  HC595 (u8 led)	       //74hc595芯片
     {
		 u8 a;
		 srclk=0;
		 rclk=0;

		 for (a=0;a<8;a++)
		     {
			 	ser=led>>7;		   //输入最高位
				led<<=1;		   //将次高位变为最高位
                srclk=1;		   //出现一个上升沿  位移一个
				_nop_;
				_nop_;
				srclk=0;
			 }    

		  rclk=1;
		  _nop_;
		  _nop_;
		  rclk=0;

	 }


void main ()
  {    u8 i;
       while(1)
	{	  
	      for(i=0;i<8;i++)
	         { 
			   HC595 (ledhang[i]);	//0x18,0x24,0x22,0x11,0x11,0x22,0x24,0x18
			   P0=ledlie[i];	 //0x7f（0111 1111）,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe
			   
			   delay (100);
			   P0=0xff;	//1111 1111
			 } 
	     
	 }
  }