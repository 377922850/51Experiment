#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;		//���������ͽ�����������

sbit beer=P1^5;		   //	 ��P1^5�ڶ�����beer

void delay (u16 i)
       {
	   
	   while (i--);
		   
	    }				  //��ʱ������i=1ʱ����Լ��ʱ10us


void main()
   {
	   while(1)
        {
		
		beer=~beer;
		delay (10);		   //��ʱ	1ms
		
	
		}
	}