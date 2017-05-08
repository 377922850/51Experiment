#include <reg52.h>


sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

typedef unsigned char u8;
typedef unsigned int u16;

u8 code shumaguan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				     0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};  //显示0~f
u8 n=0;

void time1init 	()
{
   TMOD|=0x10;    //  GATE=0 c/t=0 定时  m1m0   工作方式	0001 0000  选择为定时器1工作模式    
   TH1=0xfc;
   TL1=0x18;	  //  赋初值fc18   65536-1000=64536    1ms的初值   1ms=1000us   计算1000个数
   ET1=1;		  //  打开定时器1中断允许
   EA=1;		  //   打开总中断
   TR1=1;		  //	启动定时器1
}

void  main ()          //主函数
{	   LSA=0;
       LSB=0;
	   LSC=0;	// 数码管第一位亮
	   time1init 	();		//定时器1初始化
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
