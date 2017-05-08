#include <reg52.h>


sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

typedef unsigned char u8;
typedef unsigned int u16;

u8 code shumaguan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				     0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};  //��ʾ0~f
u8 n=0;

void time1init 	()
{
   TMOD|=0x10;    //  GATE=0 c/t=0 ��ʱ  m1m0   ������ʽ	0001 0000  ѡ��Ϊ��ʱ��1����ģʽ    
   TH1=0xfc;
   TL1=0x18;	  //  ����ֵfc18   65536-1000=64536    1ms�ĳ�ֵ   1ms=1000us   ����1000����
   ET1=1;		  //  �򿪶�ʱ��1�ж�����
   EA=1;		  //   �����ж�
   TR1=1;		  //	������ʱ��1
}

void  main ()          //������
{	   LSA=0;
       LSB=0;
	   LSC=0;	// ����ܵ�һλ��
	   time1init 	();		//��ʱ��1��ʼ��
	   while (1);
}

void time1()    interrupt 3
{	  
	  static u16 i;
	  TH1=0xfc;
      TL1=0x18;
	  i++;
	  if (i==1000)
	  {	 i=0;
		 P0=shumaguan[n];
		 n++;
		 if(n==16)
		 n=0;
	  }
}
