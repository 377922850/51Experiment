#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit out=P3^2;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 code shumaguan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
                     0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0X76};	  //显示0~f
u8 receive[4];
u8 Digdisplay[3];
u8 time;

void delay(u16 i)
{
	while(i--);
}

void receivedata()
{
   Digdisplay[0]=shumaguan[receive[2]/16];
   Digdisplay[1]=shumaguan[receive[2]%16];
   Digdisplay[2]=shumaguan[16];
}


void dig()
{
   u8 i;
   for(i=0;i<3;i--)
     {
	   switch(i)
	    {
		  case(0):LSA=0;LSB=0;LSC=0;break;
		  case(1):LSA=1;LSB=0;LSC=0;break;
		  case(2):LSA=0;LSB=1;LSC=0;break;
		}
	   P0=Digdisplay[i];
	   delay(100);
	   P0=0x00;	 
	 }
}

void int0break ()
{
  EA=1;						  //打开总中断
  IT0=1;					  //选择为下降沿触发
  EX0=1;					  //打开中断允许
  out=1;
}


void main()
{
	int0break();
	while(1)
	 {
	   receivedata();
	   dig();
	 }
}

void int0() interrupt 0
{
   u16 err;
   u8 j,i;
   delay(700);
   if(out==0)
    {  
	   time=0;
	   err=0;
	   while((out==0)&&err<100)
		 {
		   delay(10);           //10x10us=100us=0.1ms   需要9ms
		   err++;
		 }
	   if(out==1)
	    {
		  err=0;
		  while((out==1)&&err<50)
		   {
			 delay(10);
			 err++;
		   }
		   err=0;
		   for(j=0;j<4;j++)
		    {
			  for(i=0;i<8;i++)
			   {			   	 
				  while((out==0) && err<6)		 //延时0.6ms
					{
					  delay(10); //延时0.1ms
					  err++;
					}
				   while(out==1)
				    {
					   delay(10);  //0.1ms
					   time++;
					   if(time>30)
					   return;
					}
			   	   receive[j]>>=1;
				   if(time>8)
				    {
					  receive[j]|=0x80;
					}
				   
			   }
			}
		   if(receive[2]!=~receive[3])
		   return;
		}
	}

}
