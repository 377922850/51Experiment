#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;	  //对数据类型进行声明定义

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;		 //将p22 p23 p24 定义为LSA LSB LSC 

u8 code shumaguan[]={0x39,0x67,0x66, 0x6d,0x3f};	 //0x39  0011 1001  .gfedcba   cqy520
 

void main()
    
	  {
	  LSA=0;
	  LSB=0;
	  LSC=0;	 	//控制38译码器的Y0输出低电平

	  P0=shumaguan[0];
	  
	  while(1);

	  }