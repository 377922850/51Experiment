#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;	  //对数据类型进行声明定义

sbit k1=P3^1;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

sbit a=P0^7;

void delay (u16 i)
   	  {
	     while(i--);
		 }


void keydeal()
     {
	    if(k1==0)
		  {
			  delay(1000);
			   if(k1==0)
			      {
				   LSA=0;
				   LSB=0;
				   LSC=0;
				   a=~a;
				  }
				 
		  }  
		while(!k1); 
	 }

void main ()
    {
	      while(1)
	  {
	     keydeal();
	
	  }
	}
		