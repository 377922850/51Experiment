#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit led=P2^0;
sbit k1=P3^1;
sbit k2=P3^0;

u8 m=1;
u8 n=0;
u8 o=0;

u8 code shumaguansecond1[]={0x3f,0x06,0x5b,0x4f,0x66,
                           0x6d,0x7d,0x07,0x7f,0x6f};	  //显示 0~9
u8 code shumaguansecond2[]={0x06,0x5b,0x4f,
                            0x66,0x6d,0x7d};              //显示1~6

void delay (u16 i)
{
   while (i--);
}

void time0init ()
{
	 TMOD=0x01;					  //  设置工作方式   GATE=0   计时模式    m1m0=01  16位
	 TH0=0xfc;					 //
	 TL0=0x18;					//	  设置初值
	 ET0=1;					   //	  打开定时器0中断允许
	 EA=1;					  //	  打开总中断
	 TR0=1;					 //		  打开定时器0
}

void main ()
{
	   if(k1==0)
	   {
	   	  delay(100);
		  if(k1==0)
			{
			  time0init ();
			  while(1);
			}
	   }
}

void time0 ()  interrupt 1
{
	
	static u16 b;
	static u16 a;
	TH0=0xfc;
    TL0=0x18;        //设置初值
	a++;

	if(a==1000)
	{ 
	  b++;	  
	  LSA=0;
	  LSB=0;
	  LSC=0;
	  a=0;
	  P0=shumaguansecond1[m];	  
	  m++;
	  if (m==10)	   
      m=0;
	  o++;
	  if (o==10)
	  o=0;	   	  	  
	}

	if(b>10||b==10)
	{ 
	  switch(b)
		{
		  case(20):n=1;break;
		  case(30):n=2;break;
		  case(40):n=3;break;
		  case(50):n=4;break;
		  		  		  		  
		}
	  P0=0x00;
	  LSA=0;
	  LSB=0;
	  LSC=0;						//显示数码管第一位
	  P0=shumaguansecond1[o];
	  delay(100);
	  P0=0x00;
	  LSA=1;
	  LSB=0;
	  LSC=0;						//显示数码管第二位
	  P0=shumaguansecond2[n];	
	}
	if (b>)
}