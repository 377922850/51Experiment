#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;		//对数据类型进行声明定义

sbit beer=P1^5;		   //	 将P1^5口定义于beer

void delay (u16 i)
       {
	   
	   while (i--);
		   
	    }				  //延时函数，i=1时，大约延时10us


void main()
   {
	   while(1)
        {
		
		beer=~beer;
		delay (10);		   //延时	1ms
		
	
		}
	}