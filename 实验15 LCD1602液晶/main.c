#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
#include "lcd.h"

typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;

u8 word1[]=" long ago there was a girl named cqy  !";
u8 word2[]=" she is butterful,as a result,she died .";

void delay(u16 i)
{
  while(i--);
}

/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main(void)
{
	u8 i,j=0;
	while(1)
	{
	 LCDstart();
	 LCDwritecommand(0x80);            //��������ָ�����
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
