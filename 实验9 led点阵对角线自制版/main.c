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
  {     while(1)
	{	   
	      u8 i;
	      for (i=0;i<8;i++)			//ѭ���˴�
	        {    switch (i)
		     {
			    case(0): HC595(0x80);P0=0x7f;break;	 //	  1000 0000    0111 1111
				case(1): HC595(0x40);P0=0xbf;break;	 //	  0100 0000    1011 1111
				case(2): HC595(0x20);P0=0xdf;break;	 //	  0010 0000    1101 1111
				case(3): HC595(0x10);P0=0xef;break;	 //	  0001 0000    1110 1111
				case(4): HC595(0x08);P0=0xf7;break;	 //	  0000 1000    1111 0111			
				case(5): HC595(0x04);P0=0xfb;break;	 //	  0000 0100    1111 1011				
				case(6): HC595(0x02);P0=0xfd;break;	 //	  0000 0010    1111 1101				
				case(7): HC595(0x01);P0=0xfe;break;	 //	  0000 0001    1111 1110				
             	
			 }
			    P0=0xff;		//��Ӱ
			}
	 }
  }