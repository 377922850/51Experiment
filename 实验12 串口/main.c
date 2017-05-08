#include <reg52.h>


typedef unsigned char u8;
typedef unsigned int u16;

sbit led=P2^0;

void Ustartinit ()
{
   TMOD=0X20; //0001 0000
   TH1=0xf3;
   TL1=0xf3;
   PCON=0x80;
   SCON=0X50;
   
   ES=1;
   EA=1;
   TR1=1;


}
void  main ()          //Ö÷º¯Êý
{
	 Ustartinit ();
	 while(1);
}


void Ustart ()  interrupt 4
{
	u8 receivedata;
	receivedata=SBUF;
	if(receivedata==0x31)
	   {
			   led=~led;
	   }
	RI=0;
	SBUF=receivedata;
	while(!TI);
	TI=0;


}