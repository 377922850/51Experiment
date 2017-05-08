//led����     ��D�ں�P0��   ���Ŵ��ϵ���ΪD7~D1   ���Ŵ�����ΪP07~P00

#include "reg52.h"
#include "intrins.h"		 //����_nop_   ��ѭ��һ������ָ���ʱ��

sbit rclk=P3^5;			 //		 �����Ĵ���ʱ��
sbit srclk=P3^6;		 //		 ��λ�Ĵ���ʱ�� 
sbit ser=P3^4;			 //		 ��������

typedef unsigned char u8;
typedef unsigned int u16;	   //���������ͽ�������

u8 ledhang[]={0x18,0x24,0x22,0x11,0x11,0x22,0x24,0x18};	   //��
u8 ledlie[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};	   //��


void delay(u16 i)
    {
	   	while(i--);
		}

void  HC595 (u8 led)	       //74hc595оƬ
     {
		 u8 a;
		 srclk=0;
		 rclk=0;

		 for (a=0;a<8;a++)
		     {
			 	ser=led>>7;		   //�������λ
				led<<=1;		   //���θ�λ��Ϊ���λ
                srclk=1;		   //����һ��������  λ��һ��
				_nop_;
				_nop_;
				srclk=0;
			 }    

		  rclk=1;
		  _nop_;
		  _nop_;
		  rclk=0;

	 }


void main ()
  {    u8 i;
       while(1)
	{	  
	      for(i=0;i<8;i++)
	         { 
			   HC595 (ledhang[i]);	//0x18,0x24,0x22,0x11,0x11,0x22,0x24,0x18
			   P0=ledlie[i];	 //0x7f��0111 1111��,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe
			   
			   delay (100);
			   P0=0xff;	//1111 1111
			 } 
	     
	 }
  }