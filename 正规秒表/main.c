#include  "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;		//���������ͽ�������

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit k1=P3^1;
sbit k2=P3^0;

u8 second,minute,hour,ssecond;

u8 code shumaguan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					 0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//��ʾ0~F��ֵ
u8 smguan[8];

void delay (u16 i)
{
  while (i--);
}					  //��ʱ����   1=10us

void  digdisplay ()
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)
		{
		   case(0):LSA=0;LSB=0;LSC=0;break;
		   case(1):LSA=1;LSB=0;LSC=0;break;
		   case(2):LSA=0;LSB=1;LSC=0;break;
		   case(3):LSA=1;LSB=1;LSC=0;break;
		   case(4):LSA=0;LSB=0;LSC=1;break;
		   case(5):LSA=1;LSB=0;LSC=1;break;
		   case(6):LSA=0;LSB=1;LSC=1;break;
		   case(7):LSA=1;LSB=1;LSC=1;break;		
		
		}
			P0=smguan[i];						   //�����������ʾ����
        	delay(100);							  //���һ��ʱ��ɨ��	   1ms
	        P0=0x00; 							 //����
	}
   

}												   //�����ɨ�躯��

void xianshishuju ()
{
     smguan[0]=shumaguan[second%10];
	 smguan[1]=shumaguan[second/10];
	 smguan[2]=0x40;
	 smguan[3]=shumaguan[minute%10];
	 smguan[4]=shumaguan[minute/10];
	 smguan[5]=0x40;
	 smguan[6]=shumaguan[hour%10];
	 smguan[7]=shumaguan[hour/10];							   
}

void time0init ()
{
  TMOD=0x01;		   //���ù�����ʽ   GATE=0   c/t=0 timeģʽ   01 16λģʽ
  TH0=0Xd8;			  //
  TL0=0xf0;			 //���ó�ֵΪ10ms
  ET0=1;			//�򿪶�ʱ��0�ж�����
  EA=1;			   //�����ж�
  TR0=1;		  //�򿪶�ʱ��0
}


void main ()
{
	   if(k1==0)
	   {	
	        delay(100);
			if(k1==0)
			{
			   time0init ();
			   while(1)
			   {
			      xianshishuju();
			      digdisplay ();			
			   }
			}
	   }
}


void time0 ()  interrupt 1
{  
   ssecond++;
   TH0=0Xd8;			  //
   TL0=0xf0;			 //���ó�ֵΪ10ms
   if(ssecond==100)		// 100ssecond=1s    1ssecond=10ms    
   {
   	  ssecond=0;
	  second++;
	  if(second==60)
	  {
	  	  second=0;
		  minute++;
		  if(minute==60)
		  {
		   minute=0;
		   hour++;
		   if(hour==24)
		   {
		   	  hour=0;
		   }
		  }
	  }   
   }




}