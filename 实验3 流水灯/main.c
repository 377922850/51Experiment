#include "reg52.h"
#include <intrins.h>		 //��ΪҪ�õ������ƺ��������Լ������ͷ�ļ�


typedef unsigned char u8;
typedef unsigned int  u16;	  //���������ͽ�����������


#define led P2    //�궨��,��p2������Ϊled
	  

    void delay(u16 i)

	  {
	       while(i--);
		                  }//��ʱ����
		   		 
	 void main()
	 {
	 	  u8 i;
		  led=0xfe;		 //1111 1110  	  P2^7~P2^0   P2^0��
		  delay (50000) ; //	   ��ʱ450ms
		  while(1)
		  {
		     for(i=0;i<7;i++)
		       {      led=_crol_(led,1);   //1111 1110��Ϊ  1111 1101   ʵ������
			          delay (50000);      //��ʱ450ms   
	 		   }						 //forѭ��
	 		 for(i=0;i<7;i++)
			   {     led=_cror_(led,1);
				      delay (50000);
			   }
	 					 }
	    	               }   //��ʱ����

