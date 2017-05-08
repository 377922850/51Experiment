#ifndef _I2C_H_
#define _I2C_H_

#include "reg52.h"

sbit SDA=P2^0;
sbit SCL=P2^1;


void  i2cstartsignal ();															 //��ʼ�ź�
void i2cstopsignal ();																//��ֹ�ź�
unsigned char i2csendbyte (unsigned char dat);									   //����һ������
unsigned char i2creadbyte ();													  //��ȡһ������
void At24c02write (unsigned char address,unsigned char dat);					 //д��һ������
unsigned char  At24c02read (unsigned char address);			//��ȡһ������



#endif
