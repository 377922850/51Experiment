#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit k1=P3^1;
sbit led=P2^0;

void delay (u16 i)
   	  {
	     while(i--);
		 }


void keydeal()
     {
	    if (k1==0)
		  {   
		      delay (1000);   //Ïû¶¶  1000x1us=10ms
			    if (k1==0)
			  	{
			       led=~led;
				}
		  }
			  while (!k1);
	 }

void main ()
    {
	      while(1)
	  {
	     keydeal();
	  }
	}
		