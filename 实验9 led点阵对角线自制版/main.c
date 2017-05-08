		   //led点阵     又D口和P0口   竖着从上到下为D7~D1   横着从左到右为P07~P00

#include "reg52.h"
#include "intrins.h"		 //调用_nop_   空循环一个机器指令的时间

sbit rclk=P3^5;			 //		 存贮寄存器时钟
sbit srclk=P3^6;		 //		 移位寄存器时钟 
sbit ser=P3^4;			 //		 串行输入

typedef unsigned char u8;
typedef unsigned int u16;	   //对数据类型进行声明




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
  {     while(1)
	{	   
	      u8 i;
	      for (i=0;i<8;i++)			//循环八次
	        {    switch (i)
		     {
			    case(0): HC595(0x80);P0=0x7f;break;	 //	  1000 0000    0111 1111
				case(1): HC595(0x40);P0=0xbf;break;	 //	  0100 0000    1011 1111
				case(2): HC595(0x20);P0=0xdf;break;	 //	  0010 0000    1101 1111
				case(3): HC595(0x10);P0=0xef;break;	 //	  0001 0000    1110 1111
				case(4): HC595(0x08);P0=0xf7;break;	 //	  0000 1000    1111 0111			
				case(5): HC595(0x04);P0=0xfb;break;	 //	  0000 0100    1111 1011				
				case(6): HC595(0x02);P0=0xfd;break;	 //	  0000 0010    1111 1101				
				case(7): HC595(0x01);P0=0xfe;break;	 //	  0000 0001    1111 1110				
             	
			 }
			    P0=0xff;		//消影
			}
	 }
  }