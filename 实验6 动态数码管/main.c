#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;	//���������ͽ�����������


sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;		 //��p22 p23 p24 ����Ϊ LSA LSB LSC 

u8 code shumaguan[]={0x3f,0x5b,0x6d,0x00,0x6e,0x67,0x39};	  	// cqy520

void delay (u16 i)
     {
	   while(i--);
     }				  //i=1ʱ����Լ��ʱ10us

void digdisplay()
     {
	   	 u8 i;
	     for (i=0;i<7;i++)	   //ѭ��7��
		   {
		   switch(i)	 //λѡ��ѡ������������
		         {
			        case (0): LSA=0;LSB=0;LSC=0;break;	 //��ʾ��0λ	��138����y0����͵�ƽ
			        case (1): LSA=1;LSB=0;LSC=0;break;   //��ʾ��1λ
			        case (2): LSA=0;LSB=1;LSC=0;break;	 //��ʾ��2λ
			        case (3): LSA=1;LSB=1;LSC=0;break;	 //��ʾ��3λ
			        case (4): LSA=0;LSB=0;LSC=1;break;	 //��ʾ��4λ
					case (5): LSA=1;LSB=0;LSC=1;break;	 //��ʾ��5λ
					case (6): LSA=0;LSB=1;LSC=1;break;	 //��ʾ��6λ

                 }
		   	 P0=shumaguan[i];	//���Ͷ���
			 delay (100);		//���һ��ʱ��ɨ��
			 P0=0x00;			//����
		    }
	 }



void main ()
 		{   while(1)
		   {  
		   		    digdisplay();  //�������ʾ����
			}
		}	 










