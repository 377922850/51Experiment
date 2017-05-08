#include "i2c.h"

void delay10us()							  //延时 10us   误差为0
{
	    unsigned char a,b;
	    for(b=1;b>0;b--)
		for(a=2;a>0;a--);

}								  

void  i2cstartsignal ()					  //起始信号
{										 //在SCL时钟信号在高电平期间SDA信号产生一个下降沿
	  SDA=1;							 //拉高数据线
	  delay10us ();
	  SCL=1;							 //拉高时钟线
	  delay10us ();
	  SDA=0;							 //拉低数据线，产生下降沿
	  delay10us ();
	  SCL=0;							 //拉低时钟线
	  delay10us ();
}		


void i2cstopsignal ()			  //终止信号：在SCL时钟信号高电平期间SDA信号产生一个上升沿
{
	  SDA=0;					  //拉低数据线
	  delay10us ();
	  SCL=1;					  //拉高时钟线
	  delay10us ();
	  SDA=1;					  //拉高数据线 产生上升沿
	  delay10us ();	
}							

/***********************   
   通过I2C发送一个字节
***********************/
unsigned char i2csendbyte (unsigned char dat)    //起始之后SDA和SCL都为0
{
	  unsigned char a,b=0;
	  for (a=0;a<8;a++)						   //发送八个字节
	   {	  	   
		   delay10us ();
		   SDA=dat>>7;
		   dat<<=1;
		   SCL=1;
		   delay10us ();
		   SCL=0;
		   delay10us ();
	   }					  
	  SDA=1;
	  delay10us ();
	  SCL=1;
	  delay10us ();
	  while(SDA)			 //等待应答，从设备把SDA拉低
	   {
	   	   b++;
		   if(b>200)       //如果超过2000us没有应答发送失败，或者为非应答，表示接收结束
		    {
		   	   SCL=0;
			   delay10us ();
			   return 0;		   
		    }
	   }
	  SCL=0;
	  delay10us ();	  
	  return 1; 
}	


/***********************   
   通过I2C读取一个字节
***********************/
unsigned char i2creadbyte ()
{	 
	 unsigned char a,dat=0;
	 SDA=1;
	 for(a=0;a<8;a++)			  //接收8个字节
	  {
	  	dat<<=1;
		dat=dat|SDA;
		SCL=1;
		delay10us ();	
		SCL=0;
		delay10us ();	
	  }
	 return dat;
}	


/***********************   
 往At24c02里写一个数据
***********************/
void At24c02write (unsigned char address,unsigned char dat)
{
	i2cstartsignal ();			 //开始信号
	i2csendbyte (0xa0);			//发送器件地址
	i2csendbyte (address);	   //发送要写入内存地址
	i2csendbyte (dat);		  //发送数据
	i2cstopsignal ();        //结束信号
}				  


/************************   
 读取At24c02里的一个数据
************************/
unsigned char  At24c02read (unsigned char address)
{
    unsigned char number;
	i2cstartsignal ();			 //开始信号
	i2csendbyte (0xa0);			//发送写器件地址
	i2csendbyte (address);	   //发送要读取的器件地址
	i2cstartsignal ();		  //开始信号
	i2csendbyte (0xa1);		 //发送读器件地址
	number=i2creadbyte ();	
	i2cstopsignal ();        //结束信号
	return number;
}