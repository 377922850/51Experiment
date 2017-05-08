//led����     ��D�ں�P0��   ���Ŵ��ϵ���ΪD7~D1   ���Ŵ�����ΪP07~P00

#include "reg52.h"
#include "intrins.h"		 //����_nop_   ��ѭ��һ������ָ���ʱ��

sbit rclk=P3^5;			 //		 �����Ĵ���ʱ��
sbit srclk=P3^6;		 //		 ��λ�Ĵ���ʱ�� 
sbit ser=P3^4;			 //		 ��������

typedef unsigned char u8;
typedef unsigned int u16;	   //���������ͽ�������




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
    {	   
	       HC595 (0x80)  ;
	       P0=0x7f;
		   while(1);
    }