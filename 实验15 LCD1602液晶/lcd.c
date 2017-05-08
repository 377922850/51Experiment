#include "lcd.h"


void LCD1602_delay1ms(uint c)   //误差 0us
{
    uchar a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
    	
}


void LCDwritecommand(uchar command)	  //写入命令
{
	LCD1602_E = 0;     //使能
	LCD1602_RS = 0;	   //选择发送命令
	LCD1602_RW = 0;	   //选择写入
	
	LCD1602_dataline = command;     //放入命令
	LCD1602_delay1ms(1);		//等待数据稳定

	LCD1602_E = 1;	          //写入时序
	LCD1602_delay1ms(5);	  //保持时间
	LCD1602_E = 0;
}

		   
		   
void LCDwritedata(uchar dat)			//写入数据
{
	LCD1602_E = 0;	//使能清零
	LCD1602_RS = 1;	//选择输入数据
	LCD1602_RW = 0;	//选择写入

	LCD1602_dataline = dat; //写入数据
	LCD1602_delay1ms(1);

	LCD1602_E = 1;   //写入时序
	LCD1602_delay1ms(5);   //保持时间
	LCD1602_E = 0;
}
	   

void LCDstart()						  //LCD初始化子程序
{
	LCDwritecommand(0x06);            //模式设置		 0000 01 i/d s
									  //i/d : 0=写入新数据后光标左移     1=写入新数据后光标右移
									  //s   : 0=写入新数据后显示屏不移动 1=写入新数据后显示屏整体右

 	LCDwritecommand(0x38);            //显示开关功能     0000 1DCB
	                                  //D : 0=显示功能关     1=显示功能开
									  //C : 0=无光标         1=有光标
									  //B : 0=光标闪烁       1=光标不闪烁

	LCDwritecommand(0x0c);            //功能设定         001 DL NFXX
	                                  //DL : 0=数据总线为 4 位     1=数据总线为 8 位
									  //N  : 0=显示 1 行           1=显示 2 行
									  //F  : 0=5×7 点阵/每字符     1=5×10 点阵/每字符

	LCDwritecommand(0x01);            //清屏指令

	
}

