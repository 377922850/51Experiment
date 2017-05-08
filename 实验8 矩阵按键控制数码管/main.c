#include "reg52.h"		  //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���

typedef unsigned char u8;
typedef unsigned int u16;	  //���������ͽ�������

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

#define GPIO_key  P1		//����
#define GPIO_dig  P0		//�����

u8 keyvalue;

u8 code shumaguan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};       //��ʾ0~F	 0x3f 0011 1111 �ߵ�ƽ��

void delay (u16 i)
   {
	  while (i--);
   }				   //��ʱ����

void keydown()		  //�����жϺ���
   {   
       
	   GPIO_key=0x0f;   //��λΪ�͵�ƽ ��λΪ�ߵ�ƽ   0000 1111  p1^7~p1^0   
	   if (GPIO_key!=0x0f)
	      {	   
		      delay(1000);   //��ʱ10ms  ����
				if (GPIO_key!=0x0f)
				 {
				   //������
						 GPIO_key=0x0f;

						 switch(GPIO_key)
							{
								case(0x07):keyvalue=0;break;	   //	 0000 0111	  ��һ��
								case(0x0b):keyvalue=1;break;	   //	 0000 1011	  �ڶ���
								case(0x0d):keyvalue=2;break;	   //	 0000 1101	  ������
								case(0x0e):keyvalue=3;break;	   //	 0000 1110	  ������
				   			 }
				   //������
				   GPIO_key=0xf0;

						 switch(GPIO_key)
							{
								case(0x70):keyvalue=keyvalue   ;break;	       // 0111 0000    �ڵ�һ��
								case(0xb0):keyvalue=keyvalue+4 ;break;      // 1011 0000	   �ڵڶ���
								case(0xd0):keyvalue=keyvalue+8 ;break;	   // 1101 0000	   �ڵ�����
								case(0xe0):keyvalue=keyvalue+12;break;	   // 1110 1111    �ڵ�����	
				   
				            }
				 
				  while(GPIO_key!=0xf0)	 //��ⰴ�����ּ��
				  {
			       	delay(1000);
			      }
				
			}

		  }
	}
	  
				   																				
		  

   
      
void main()
	  {
		   LSA=0;
		   LSB=0;
		   LSC=0;	  //����138��������Y0����͵�ƽ
		   
		   
		   while(1)
		   {
		      keydown();			//�����жϺ���
		      GPIO_dig=shumaguan[keyvalue];
		   }
	  	  
	  }






