#include "reg52.h"
#include <intrins.h>


typedef unsigned char u8;
typedef unsigned int  u16;	  //对数据类型进行声明定义


#define led P2    //宏定义,将p2口设置为led
	  

    void delay(u16 i)

	  {
	       while(i--);
		                  }//延时函数
		   		 
	void main()
	 {
	 	  u8 i;
		  led=0xfe;
		  delay (50000) ; //	   延时450ms
		  while(1)
		  {
		     for(i=0;i<7;i++)
		       {      led=_crol_(led,1);      //1111 1110变为  1111 1101   实现左移
			          delay (50000);  //	   延时450ms   
	 		   }
	 		 for(i=0;i<7;i++)
			   {     led=_cror_(led,1);
				      delay (50000);
			   }
	 					 }
	    	               }   //延时函数

