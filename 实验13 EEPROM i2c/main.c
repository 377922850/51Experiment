#include  "reg52.h"
#include  "i2c.h"					  //调用头文件


typedef unsigned char u8;			  //对数据类型进行声明
typedef unsigned int u16;			 

sbit LSA=P2^2;						 //定义138三个地址输入
sbit LSB=P2^3;
sbit LSC=P2^4;						  

sbit k1=P3^1;						 //开关
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;						 

u8 number=0;
u8 digdata[4];
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};	 //显示0~9


void delay (u16 i)	                       //延时函数
{
   while(i--);
}


/************************   
     按键处理函数
************************/
void keydisprose ()						   
{
	 if(k1==0)							   //写入一个数据
	  {
	  	delay(100);
		 if(k1==0)
		  {
		  	At24c02write(1,number);          //(address,number)
		  }
		 while(!k1);
	  }

	 if(k2==0)							   //读取一个数据
	  {
	  	delay(100);
		 if(k2==0)
		  {
		  	number=At24c02read (1);         //（address） 
		  }
		 while(!k2);
	  }

	 if(k3==0)							   //累加
	  {
	  	delay(100);
		 if(k3==0)
		  {
		  	number++;
			if(number==256)
			number=0;          
		  }
		 while(!k3);
	  }

	 if(k4==0)							   //清零
	  {
	  	delay(100);
		 if(k4==0)
		  {
		  	number=0;          
		  }
		 while(!k4);
	  }
}


/************************   
     动态数码管函数
************************/
void digdisplay ()
{
   u8 i;
   for(i=0;i<4;i++)
    {
	  switch(i)
	   {
	   	 case(0):LSA=0;LSB=0;LSC=0;break;		 //显示第一位
		 case(1):LSA=1;LSB=0;LSC=0;break;		 //显示第二位
		 case(2):LSA=0;LSB=1;LSC=0;break;	   	 //显示第三位
		 case(3):LSA=1;LSB=1;LSC=0;break;	   	 //显示第四位
	   }
	  
	  P0=digdata[i];							 //发送段选数据
	  delay (100);								 //1ms  间隔一段时间扫描
	  P0=0x00;                                   //消影
	
	}	 

}


/************************   
  数码管四位数据处理函数
************************/
void datadispose()
{
	digdata[0]=smgduan[number%1000%100%10];	 //个位
	digdata[1]=smgduan[number%1000%100/10];	 //十位
	digdata[2]=smgduan[number%1000/100];		 //百位
	digdata[3]=smgduan[number/1000];			 //千位
}


/************************   
         主函数
************************/
void main()
{
  while(1)
   {
	  keydisprose ();
	  datadispose();
	  digdisplay ();
   }
}