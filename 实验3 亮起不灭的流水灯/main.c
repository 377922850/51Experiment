#include "reg52.h"
#include <intrins.h>		 //��ΪҪ�õ������ƺ��������Լ������ͷ�ļ�


typedef unsigned char u8;
typedef unsigned int  u16;	  //���������ͽ�����������


#define led P2    //�궨��,��p2������Ϊled	 

u8 code LED[]={0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00,
               0x00,0x80,0xc0,0xe0,0xf0,0xf8,0xfc,0xfe,0xff,};   //
	  

void delay(u16 i)

	  {
	       while(i--);
	  }                        //��ʱ����
		   		 
void main()
	 {
			while (1)
	 	  	 {
			 u8 i;
			 for (i=0;i<18;i++)
			   {
				 led=LED[i];
				 delay(50000)	;
			   }
	 		 }		 
	 }   
