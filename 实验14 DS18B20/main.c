#include "reg52.h"
#include "tempture.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;


u8 code zero_nine[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};    //显示0~9
u8 digdata[6];

void delay(u16 i)
{
   while(i--);
}




/********************** 
  温度读取处理转换函数       
**********************/
void tempturedispose(int temp)							//温度读取处理转换
{  
   float tempture;										//浮点型变量   								
   if(temp<0)											//如果温度小于0
    {
	  digdata[5]=0x40;									//符号位显示-
	  temp=temp-1;										//因为读取的温度是实际温度的补码，所以减1
	  temp=~temp;										//再取反求出原码
	  tempture=temp;									//将temp赋值到浮点型变量
	  temp=tempture*0.0625*100+0.5;						//留两个小数点就*100，+0.5是四舍五入
	}
   else 
	{	
	  digdata[5]=0x00;                  				//符号位不显示
	  tempture=temp;									//有小数点所以将温度赋给一个浮点型变量
	  temp=tempture*0.0625*100+0.5;						//留两个小数点就*100，+0.5是四舍五入
	}
   digdata[0]=zero_nine[temp%10];			            //小数点后第二位
   digdata[1]=zero_nine[temp%100/10];			        //小数点后第一位
   digdata[2]=zero_nine[temp%1000/100]|0x80;	     	//个位 要显示小数点	 或上1000 0000 
   digdata[3]=zero_nine[temp%10000/1000];			    //十位
   digdata[4]=zero_nine[temp/10000];                    //百位
}




/******************* 
   数码管动态扫描       
*******************/
void digdisplay()
{
	 u8 i;
	 for(i=0;i<6;i++)
	  {
	    switch(i)
		 {
		   case(0):LSA=0;LSB=0;LSC=0;break;		  //显示第一位   小数点后两位
		   case(1):LSA=1;LSB=0;LSC=0;break;		  //先是第二位   小数点后一位
		   case(2):LSA=0;LSB=1;LSC=0;break;		  //显示第三位   个位
		   case(3):LSA=1;LSB=1;LSC=0;break;		  //显示第四位	 十位
		   case(4):LSA=0;LSB=0;LSC=1;break;		  //显示第五位   百位
		   case(5):LSA=1;LSB=0;LSC=1;break;       //显示第六位   符号位		  
		 }
	  	P0=digdata[i];
		delay(100);								  //延时1ms
		P0=0x00;	  							  //消影
	  }
}


/******************* 
      主函数       
*******************/
void main ()
{


   	 while(1)
	 { 
	   	   
	   tempturedispose(DS18B20tempture ());
	   digdisplay();
	   
			 
		   
			     
     }	 
}