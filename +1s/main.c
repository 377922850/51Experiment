//   ��һ�� ÿ60s��һ��
#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16; //���������ͽ�������

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;		  //138  
sbit k1=P3^1;		  //����ʱ  ���ʼ��ʱ
sbit k2=P3^0;

u8 n=0;
u8 m=0;
u8 o=0;
u8 p=0;


void delay (u8 i)
{

	while (i--);
}				   //��ʱ����    1��ԼΪ10us  

void time0init ()
{
   TMOD=0x01;    //GATE=0  Ϊ��ʱģʽ 01 ��ʽһ 16λ
   TH0=0xfc;
   TL0=0x18;	//���ó�ֵ  Ϊ1ms=1000us
   ET0=1;		//�򿪶�ʱ��0�ж�����
   EA=1;		//���ж��ܿ���
   TR0=1;		//�����ж�
}


u8 code shumaguansecond1[]={0x3f,0x06,0x5b,0x4f,0x66,
                            0x6d,0x7d,0x07,0x7f,0x6f};               //��ʾ0~9
u8 code shumaguansecond2[]={0x06,0x5b,0x4f,0x66,0x6d};   			//��ʾ1~5
u8 code shumaguansecond3[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d};		   //��ʾ0~6
u8 code shumaguanminute1[]={0x06,0x5b,0x4f,0x66,
                            0x6d,0x7d,0x07,0x7f,0x6f};			   // ��ʾ1~9

void main ()
{	   	 
         
	   if(k1==0)	                          //���¿���k1
	   {
	   delay (100);	                         //����
	   time0init ();
	   while(1);
	   }
	   
}


void time0 ()  interrupt 1
{

    static u16 a;				  // a=0
	static u16 b;				 //	 b=0
	TH0=0xfc;
    TL0=0x18;
	a++;
   
	if(b>59)
	{
	  switch(b)
		{ 
		  case(60):p=0;break;
		  case(70):p=1;break;
		  case(80):p=2;break;
		  case(90):p=3;break;
		  case(100):p=4;break;
		  case(110):p=5;break;
		  case(120):p=0;o=1;break;		  		  
		}
	  P0=0x00;
	  LSA=0;
	  LSB=0;
	  LSC=0;							   //��һ���������
	  P0=shumaguansecond1[n];	
	  delay(100);                          //��ʱ1000us=1ms
	  P0=0x00;							   //��Ӱ
	  
	  LSA=1;
	  LSB=0;
	  LSC=0;							   //�ڶ����������
	  P0=shumaguansecond3[p];	    	                    
	  delay(100);						   //��ʱ1000us=1ms
	  P0=0x00;							   //��Ӱ
	  
	  LSA=0;
	  LSB=1;
	  LSC=0;							   //�������������
	  P0=0x40;							   
	  delay(100);						   //��ʱ1000us=1ms
	  P0=0x00;							   //��Ӱ
	  
	  LSA=1;
	  LSB=1;
	  LSC=0;							   //���ĸ��������
	  P0=shumaguanminute1[o];	
	}

	if(b>9&&b<60)
	{ 	  
	  switch(b)
		{
		  case(20):m=1;break;
		  case(30):m=2;break;
		  case(40):m=3;break;
		  case(50):m=4;break;		  		  		  
		}
	  P0=0x00;
	  LSA=0;
	  LSB=0;
	  LSC=0;							   //��һ���������
	  P0=shumaguansecond1[n];	
	  delay(100);                          //��ʱ1000us=1ms
	  P0=0x00;							   //��Ӱ
	  LSA=1;
	  LSB=0;
	  LSC=0;							   //�ڶ����������
	  P0=shumaguansecond2[m];	    	                                  
	}

	if(a==1000)
	{ 
	  b++;	  
	  LSA=0;
	  LSB=0;
	  LSC=0;
	  a=0;
	  P0=shumaguansecond1[n];	  
	  n++;
	  if (n==10)	   
      n=0;	   	  	  
	}
			
}