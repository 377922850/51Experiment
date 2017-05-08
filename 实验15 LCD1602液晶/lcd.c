#include "lcd.h"


void LCD1602_delay1ms(uint c)   //��� 0us
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


void LCDwritecommand(uchar command)	  //д������
{
	LCD1602_E = 0;     //ʹ��
	LCD1602_RS = 0;	   //ѡ��������
	LCD1602_RW = 0;	   //ѡ��д��
	
	LCD1602_dataline = command;     //��������
	LCD1602_delay1ms(1);		//�ȴ������ȶ�

	LCD1602_E = 1;	          //д��ʱ��
	LCD1602_delay1ms(5);	  //����ʱ��
	LCD1602_E = 0;
}

		   
		   
void LCDwritedata(uchar dat)			//д������
{
	LCD1602_E = 0;	//ʹ������
	LCD1602_RS = 1;	//ѡ����������
	LCD1602_RW = 0;	//ѡ��д��

	LCD1602_dataline = dat; //д������
	LCD1602_delay1ms(1);

	LCD1602_E = 1;   //д��ʱ��
	LCD1602_delay1ms(5);   //����ʱ��
	LCD1602_E = 0;
}
	   

void LCDstart()						  //LCD��ʼ���ӳ���
{
	LCDwritecommand(0x06);            //ģʽ����		 0000 01 i/d s
									  //i/d : 0=д�������ݺ�������     1=д�������ݺ�������
									  //s   : 0=д�������ݺ���ʾ�����ƶ� 1=д�������ݺ���ʾ��������

 	LCDwritecommand(0x38);            //��ʾ���ع���     0000 1DCB
	                                  //D : 0=��ʾ���ܹ�     1=��ʾ���ܿ�
									  //C : 0=�޹��         1=�й��
									  //B : 0=�����˸       1=��겻��˸

	LCDwritecommand(0x0c);            //�����趨         001 DL NFXX
	                                  //DL : 0=��������Ϊ 4 λ     1=��������Ϊ 8 λ
									  //N  : 0=��ʾ 1 ��           1=��ʾ 2 ��
									  //F  : 0=5��7 ����/ÿ�ַ�     1=5��10 ����/ÿ�ַ�

	LCDwritecommand(0x01);            //����ָ��

	
}

