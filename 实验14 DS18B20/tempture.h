#ifndef _tempture_h
#define _tempture_h

#include <reg52.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif


sbit dataline=P3^7;



int DS18B20tempture ();
void DS18B20treadempture ();
void DS18B20changetempture ();
uchar DS18B20readbyte ();
void DS18B20writebyte (uchar dat);
uchar DS18B20start ();
void delay1ms (uint y);
void delay600us ();
void delay80us ();
void delay45us ();
void delay15us();
void DS18B20tempturealarm();






#endif