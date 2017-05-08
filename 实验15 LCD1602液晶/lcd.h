#ifndef __LCD_H_
#define __LCD_H_



/********************
       包含头文件
*********************/
#include<reg52.h>

/*********************
      重定义关键词
**********************/
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/*********************
       PIN口定义
**********************/
#define LCD1602_dataline P0


sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;

/*****************
    函数声明
******************/
void LCD1602_delay1ms(uint c);                  //误差 0us	延时函数
				
void LCDwritecommand(uchar com);				//LCD1602写入8位命令函数
					
void LCDwritedata(uchar dat)	;				//LCD1602写入8位数据函数
	
void LCDstart();						  		//LCD1602初始化子程序

#endif
