#include "tempture.h"


/******************* 
      延时函数       
*******************/
uchar tempturelimit[2]={25,5};

void delay10us()   //误差 0us  延时10us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=2;a>0;a--);
}

void delay15us()   //误差 0us	延时15us
{
    unsigned char a;
    for(a=6;a>0;a--);
}


void delay45us()   //误差 0us	 延时45us
{
    unsigned char a;
    for(a=21;a>0;a--);
}

void delay80us()   //误差 0us	 延时80us
{
    unsigned char a,b;
    for(b=11;b>0;b--)
        for(a=2;a>0;a--);
}

void delay600us()   //误差 0us	  延时600us
{
    unsigned char a,b;
    for(b=3;b>0;b--)
        for(a=98;a>0;a--);
}


void delay1ms(uint y)	  //y=1为1ms
{
	uint x;
	for( ; y>0; y--)
	  {
		for(x=110; x>0; x--);
	  }
}

/******************* 
   DS18B20初始化       
*******************/
uchar DS18B20start ()		  //初始化成功返回1，失败返回0
{
	  dataline=0;			  //拉低数据线
	  delay600us();			  //延时600us
	  dataline=1;			  //拉高数据线
	  delay80us;			  //等待80us
	  while(dataline)		  //等待返回的低电平
	   {
	   	 delay600us();		  //进行超时判断
		 return 0;			  //返回0
	   }
	  return 1;				  //返回1
	  delay600us();	  		  //延时600us
}

 
/******************* 
   DS18B20写函数       
*******************/
void DS18B20writebyte (uchar dat)	 //向DS18B20写入一个字节
{
   uchar i,j;
   for(j=0;j<8;j++)
    {
      dataline = 0;		             //将数据线拉低
      delay15us();					         //延时1us
      dataline = dat & 0x01;	     //按位与   有0出0      假设dat=1010 1010 & 0000 0001 =1010 1010     
	  delay80us();					 //延时80us
	  dataline = 1;			         //拉高数据线	  
	  dat >>= 1;				     //右移一位				    dat=0101 0101  次低位变为最低位   	 
    }
}


/******************* 
   DS18B20读函数       
*******************/
uchar DS18B20readbyte ()				 //在DS18B20中读取一个数据
{
   uchar bi,byte,i,j;
   for (i=0;i<8;i++)
   {
     dataline = 0;						 //拉低数据线
     j++;                                //延时1us 
   	 dataline = 1;                       //将数据线拉高，释放总线准备读数据
	 delay10us();                        //延时6us
	 bi = dataline;
	 byte = (byte >> 1)|(bi << 7);       //将byte左移一位，然后与上右移7位后的bi，注意移动之后移掉那位补0
	 delay45us ();
   }
   return byte;
}

/******************* 
  DS18B20温度报警       
*******************/
void DS18B20tempturealarm()
{
   DS18B20start ();							 //初始化
   DS18B20writebyte (0xcc);					 //跳过ROM操作命令 适用于单片工作
   DS18B20writebyte (0x4e);					 //发出向内部RAM3‘4字节写上上限和下限的温度数据命令
   DS18B20writebyte (tempturelimit[0]);		 //上限为25
   DS18B20writebyte	(tempturelimit[1]);		 //下限为5
   DS18B20start ();							 //初始化
   DS18B20writebyte (0xcc);					 //跳过ROM操作命令 适用于单片工作
   DS18B20writebyte (0x48);					 //将RAM第3.4字节内容写入EEPROM
    
   	
}


/******************* 
  DS18B20温度变换       
*******************/
void DS18B20changetempture ()
{
  DS18B20start ();						  //初始化
  delay1ms(1);							  //延时1ms
  DS18B20writebyte (0xcc);				  //写一个字节 0xcc 跳过ROM操作命令 适用于单片工作
  DS18B20writebyte (0x44);				  //启动温度转换 12位 结果存入9为RAM中
  
}


/********************* 
 DS18B20读取温度命令       
*********************/
void DS18B20readempture ()				  //发送读取温度命令
{
  DS18B20start ();						  //初始化
  delay1ms(1);							  //延时1ms
  DS18B20writebyte (0xcc);				  //写一个字节 0xcc 跳过ROM操作命令 适用于单片工作
  DS18B20writebyte (0xbe);				  //写一个字节 oxeh  读内部RAM中的9
}


/********************* 
    DS18B20读取温度       
*********************/
int DS18B20tempture ()					  //读取温度
{
  int temp=0;
  uchar temph,templ;					  //temph为高8位  templ为低八位
  DS18B20changetempture ();				  //温度转换
  DS18B20readempture ();				  //读取温度指令
  templ = DS18B20readbyte ();			  //读取温度值共16位，先读低字节
  temph = DS18B20readbyte ();	    	  //再读高字节
  temp = temph;
  temp <<= 8;
  temp |= templ;
  return temp;
}