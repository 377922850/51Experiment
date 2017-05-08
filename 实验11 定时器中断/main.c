#include <reg52.h>

sbit led=P2^0;

typedef unsigned char u8;
typedef unsigned int u16;

void time0init 	()
{
   TMOD|=0x01;    //  GATE=0 c/t=0 定时  m1m0=01   工作方式
   TH0=0xfc;
   TL0=0x18;	  //fc18   65536-1000=64536    1ms的初值   1ms=1000us   计算1000个数
   ET0=1;
   EA=1;
   TR0=1;
}

void  main ()          //主函数
{
	   time0init 	();
	   while (1);
}

void time0()    interrupt 1
{
	  static u16 i;
	  TH0=0xfc;
      TL0=0x18;
	  i++;
	  if (i==10000)
	  {
		 led=~led;
		 i=0;
	  }
}
