#include "reg52.h"
#include <intrins.h>		 //因为要用到左右移函数，所以加入这个头文件


typedef unsigned char u8;
typedef unsigned int  u16;	  //对数据类型进行声明定义


#define led P2    //宏定义,将p2口设置为led	 

u8 code LED[]={0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00,
               0x00,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff,};   //
	  

void delay(u16 i)

	  {
	       while(i--);
	  }                        //延时函数
		   		 
void main()
	 {
			while (1)
	 	  	 {
			 u8 i;
			 for (i=0;i<18;i++)
			   {
				 led=LED[i];
				 delay(50000)	;
			   }
	 		 }		 
	 }   
