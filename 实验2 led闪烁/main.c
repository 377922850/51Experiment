#include "reg52.h"
typedef unsigned char u8;
typedef unsigned int u16;	  //对数据类型进行声明

sbit D1=P2^0;
sbit D2=P2^1;
sbit D3=P2^2;
sbit D4=P2^3;
sbit D5=P2^4;
sbit D6=P2^5;			  //定义端口

void delay(u16 i)
     { 
		while (i--);   		     
	     }    		//延时函数
	
	
	void main()

	{
		while (1)
		   {
		       D1=0;			 //D1亮
			   delay (50000);	 //50000x10us=0.5s
			   D1=0;			 //D1灭
			   delay (50000); 	 //0.5s
			   D1=1;
			   delay (50000);
			   D1=1;
			   delay (50000);
			   D2=0;
			   delay (50000);
			   D2=0;
			   delay (50000); 
			   D2=1;
			   delay (50000);
			   D2=1;
			   delay (50000);
			    D5=0;
			   delay (50000);
			   D5=0;
			   delay (50000); 
			   D5=1;
			   delay (50000);
			   D5=1;
			   delay (50000);
			    D3=0;
			   delay (50000);
			   D3=0;
			   delay (50000); 
			   D3=1;
			   delay (50000);
			   D3=1;
			   delay (50000);
			    D1=0;
			   delay (50000);
			   D1=0;
			   delay (50000); 
			   D1=1;
			   delay (50000);
			   D1=1;
			   delay (50000);

			   
			 
			   
			   
			   }


	                 }