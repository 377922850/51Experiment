#ifndef _I2C_H_
#define _I2C_H_

#include "reg52.h"

sbit SDA=P2^0;
sbit SCL=P2^1;


void  i2cstartsignal ();															 //起始信号
void i2cstopsignal ();																//终止信号
unsigned char i2csendbyte (unsigned char dat);									   //发送一个数据
unsigned char i2creadbyte ();													  //读取一个数据
void At24c02write (unsigned char address,unsigned char dat);					 //写入一个数据
unsigned char  At24c02read (unsigned char address);			//读取一个数据



#endif
