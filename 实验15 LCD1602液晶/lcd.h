#ifndef __LCD_H_
#define __LCD_H_



/********************
       ����ͷ�ļ�
*********************/
#include<reg52.h>

/*********************
      �ض���ؼ���
**********************/
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/*********************
       PIN�ڶ���
**********************/
#define LCD1602_dataline P0


sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;

/*****************
    ��������
******************/
void LCD1602_delay1ms(uint c);                  //��� 0us	��ʱ����
				
void LCDwritecommand(uchar com);				//LCD1602д��8λ�����
					
void LCDwritedata(uchar dat)	;				//LCD1602д��8λ���ݺ���
	
void LCDstart();						  		//LCD1602��ʼ���ӳ���

#endif
