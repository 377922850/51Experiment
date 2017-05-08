//   续一秒 每60s少一秒
#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16; //对数据类型进行声明

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;		  //138  
sbit k1=P3^1;		  //按下时  秒表开始计时
sbit k2=P3^0;

u8 n=0;
u8 m=0;
u8 o=0;
u8 p=0;


void delay (u8 i)
{

	while (i--);
}				   //延时函数    1大约为10us  

void time0init ()
{
   TMOD=0x01;    //GATE=0  为定时模式 01 方式一 16位
   TH0=0xfc;
   TL0=0x18;	//设置初值  为1ms=1000us
   ET0=1;		//打开定时器0中断允许
   EA=1;		//打开中断总控制
   TR0=1;		//开启中断
}


u8 code shumaguansecond1[]={0x3f,0x06,0x5b,0x4f,0x66,
                            0x6d,0x7d,0x07,0x7f,0x6f};               //显示0~9
u8 code shumaguansecond2[]={0x06,0x5b,0x4f,0x66,0x6d};   			//显示1~5
u8 code shumaguansecond3[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d};		   //显示0~6
u8 code shumaguanminute1[]={0x06,0x5b,0x4f,0x66,
                            0x6d,0x7d,0x07,0x7f,0x6f};			   // 显示1~9

void main ()
{	   	 
         
	   if(k1==0)	                          //按下开关k1
	   {
	   delay (100);	                         //消抖
	   time0init ();
	   while(1);
	   }
	   
}


void time0 ()  interrupt 1
{

    static u16 a;				  // a=0
	static u16 b;				 //	 b=0
	TH0=0xfc;
    TL0=0x18;
	a++;
   
	if(b>59)
	{
	  switch(b)
		{ 
		  case(60):p=0;break;
		  case(70):p=1;break;
		  case(80):p=2;break;
		  case(90):p=3;break;
		  case(100):p=4;break;
		  case(110):p=5;break;
		  case(120):p=0;o=1;break;		  		  
		}
	  P0=0x00;
	  LSA=0;
	  LSB=0;
	  LSC=0;							   //第一个数码管亮
	  P0=shumaguansecond1[n];	
	  delay(100);                          //延时1000us=1ms
	  P0=0x00;							   //消影
	  
	  LSA=1;
	  LSB=0;
	  LSC=0;							   //第二个数码管亮
	  P0=shumaguansecond3[p];	    	                    
	  delay(100);						   //延时1000us=1ms
	  P0=0x00;							   //消影
	  
	  LSA=0;
	  LSB=1;
	  LSC=0;							   //第三个数码管亮
	  P0=0x40;							   
	  delay(100);						   //延时1000us=1ms
	  P0=0x00;							   //消影
	  
	  LSA=1;
	  LSB=1;
	  LSC=0;							   //第四个数码管亮
	  P0=shumaguanminute1[o];	
	}

	if(b>9&&b<60)
	{ 	  
	  switch(b)
		{
		  case(20):m=1;break;
		  case(30):m=2;break;
		  case(40):m=3;break;
		  case(50):m=4;break;		  		  		  
		}
	  P0=0x00;
	  LSA=0;
	  LSB=0;
	  LSC=0;							   //第一个数码管亮
	  P0=shumaguansecond1[n];	
	  delay(100);                          //延时1000us=1ms
	  P0=0x00;							   //消影
	  LSA=1;
	  LSB=0;
	  LSC=0;							   //第二个数码管亮
	  P0=shumaguansecond2[m];	    	                                  
	}

	if(a==1000)
	{ 
	  b++;	  
	  LSA=0;
	  LSB=0;
	  LSC=0;
	  a=0;
	  P0=shumaguansecond1[n];	  
	  n++;
	  if (n==10)	   
      n=0;	   	  	  
	}
			
}