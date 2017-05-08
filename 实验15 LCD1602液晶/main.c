#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "lcd.h"

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

u8 word1[]=" long ago there was a girl named cqy  !";
u8 word2[]=" she is butterful,as a result,she died .";

void delay(u16 i)
{
  while(i--);
}

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main(void)
{
	u8 i,j=0;
	while(1)
	{
	 LCDstart();
	 LCDwritecommand(0x80);            //设置数据指针起点
	 for(i=0;i<40;i++)
	 {
	   LCDwritedata(word1[i]);
	   delay(50000);
	   if(i==14)
		{
		  LCDwritecommand(0x07);	
		}
	 }
	 i=0;	
	}			
}
