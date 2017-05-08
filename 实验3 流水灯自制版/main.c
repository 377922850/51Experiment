#include "reg52.h"
typedef unsigned char u8;
typedef unsigned int u16;
sbit D1=P2^0;
sbit D2=P2^1;
sbit D3=P2^2;
sbit D4=P2^3;
sbit D5=P2^4;
sbit D6=P2^5;
sbit D7=P2^6;
sbit D8=P2^7;

void delay(u16 i)
     { 
		while (i--);
   		 
    
	     }    
	void main()

	{
		while (1)
		   {
		       D1=0;
			   delay (50000);
			    
			   D1=1;
			   delay (50000); //1иак╦
			  
			   D2=0;
			   delay (50000); 
			   
			   D2=1;
			   delay (50000); //2иак╦
			 
			    D3=0;
			   delay (50000);
			  
			   D3=1;
			   delay (50000);  //3иак╦
			  
			    D4=0;
			   delay (50000);
			   
			   D4=1;
			   delay (50000);  //4иак╦
			  
			    D5=0;
			   delay (50000);
			 
			   D5=1;
			   delay (50000);	//5иак╦
			    
				D6=0;
			   delay (50000);
			 
			   D6=1;
			   delay (50000);  //6иак╦
			    
				D7=0;
			   delay (50000);
			 
			   D7=1;
			   delay (50000);  //7иак╦
			    
				D8=0;
			   delay (50000);
			 
			   D8=1;
			   delay (50000);  //8иак╦
			  

			   
			 
			   
			   
			   }


	                 }