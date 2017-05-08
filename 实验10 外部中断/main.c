#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;


sbit led=P2^0; 
sbit k3=P3^2;

void delay (u16 i)
    {

	   while(i--);

	}

void Int0breakoff ()
    {
	     IT0=1;
		 EX0=1;
		 EA=1;
	 }


void main ()
{
	Int0breakoff();
	while(1);
}




void int0()  interrupt 0
{
	delay(1000);  //Ïû¶¶   1000x10us=10ms
	if(k3==0)
	   {
	   	 led=~led;
	   
	   }


}