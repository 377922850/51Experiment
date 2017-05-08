#include "reg52.h"
#include "tempture.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;


u8 code zero_nine[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};    //��ʾ0~9
u8 digdata[6];

void delay(u16 i)
{
   while(i--);
}




/********************** 
  �¶ȶ�ȡ����ת������       
**********************/
void tempturedispose(int temp)							//�¶ȶ�ȡ����ת��
{  
   float tempture;										//�����ͱ���   								
   if(temp<0)											//����¶�С��0
    {
	  digdata[5]=0x40;									//����λ��ʾ-
	  temp=temp-1;										//��Ϊ��ȡ���¶���ʵ���¶ȵĲ��룬���Լ�1
	  temp=~temp;										//��ȡ�����ԭ��
	  tempture=temp;									//��temp��ֵ�������ͱ���
	  temp=tempture*0.0625*100+0.5;						//������С�����*100��+0.5����������
	}
   else 
	{	
	  digdata[5]=0x00;                  				//����λ����ʾ
	  tempture=temp;									//��С�������Խ��¶ȸ���һ�������ͱ���
	  temp=tempture*0.0625*100+0.5;						//������С�����*100��+0.5����������
	}
   digdata[0]=zero_nine[temp%10];			            //С�����ڶ�λ
   digdata[1]=zero_nine[temp%100/10];			        //С������һλ
   digdata[2]=zero_nine[temp%1000/100]|0x80;	     	//��λ Ҫ��ʾС����	 ����1000 0000 
   digdata[3]=zero_nine[temp%10000/1000];			    //ʮλ
   digdata[4]=zero_nine[temp/10000];                    //��λ
}




/******************* 
   ����ܶ�̬ɨ��       
*******************/
void digdisplay()
{
	 u8 i;
	 for(i=0;i<6;i++)
	  {
	    switch(i)
		 {
		   case(0):LSA=0;LSB=0;LSC=0;break;		  //��ʾ��һλ   С�������λ
		   case(1):LSA=1;LSB=0;LSC=0;break;		  //���ǵڶ�λ   С�����һλ
		   case(2):LSA=0;LSB=1;LSC=0;break;		  //��ʾ����λ   ��λ
		   case(3):LSA=1;LSB=1;LSC=0;break;		  //��ʾ����λ	 ʮλ
		   case(4):LSA=0;LSB=0;LSC=1;break;		  //��ʾ����λ   ��λ
		   case(5):LSA=1;LSB=0;LSC=1;break;       //��ʾ����λ   ����λ		  
		 }
	  	P0=digdata[i];
		delay(100);								  //��ʱ1ms
		P0=0x00;	  							  //��Ӱ
	  }
}


/******************* 
      ������       
*******************/
void main ()
{


   	 while(1)
	 { 
	   	   
	   tempturedispose(DS18B20tempture ());
	   digdisplay();
	   
			 
		   
			     
     }	 
}