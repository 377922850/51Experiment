#include  "reg52.h"
#include  "i2c.h"					  //����ͷ�ļ�


typedef unsigned char u8;			  //���������ͽ�������
typedef unsigned int u16;			 

sbit LSA=P2^2;						 //����138������ַ����
sbit LSB=P2^3;
sbit LSC=P2^4;						  

sbit k1=P3^1;						 //����
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;						 

u8 number=0;
u8 digdata[4];
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};	 //��ʾ0~9


void delay (u16 i)	                       //��ʱ����
{
   while(i--);
}


/************************   
     ����������
************************/
void keydisprose ()						   
{
	 if(k1==0)							   //д��һ������
	  {
	  	delay(100);
		 if(k1==0)
		  {
		  	At24c02write(1,number);          //(address,number)
		  }
		 while(!k1);
	  }

	 if(k2==0)							   //��ȡһ������
	  {
	  	delay(100);
		 if(k2==0)
		  {
		  	number=At24c02read (1);         //��address�� 
		  }
		 while(!k2);
	  }

	 if(k3==0)							   //�ۼ�
	  {
	  	delay(100);
		 if(k3==0)
		  {
		  	number++;
			if(number==256)
			number=0;          
		  }
		 while(!k3);
	  }

	 if(k4==0)							   //����
	  {
	  	delay(100);
		 if(k4==0)
		  {
		  	number=0;          
		  }
		 while(!k4);
	  }
}


/************************   
     ��̬����ܺ���
************************/
void digdisplay ()
{
   u8 i;
   for(i=0;i<4;i++)
    {
	  switch(i)
	   {
	   	 case(0):LSA=0;LSB=0;LSC=0;break;		 //��ʾ��һλ
		 case(1):LSA=1;LSB=0;LSC=0;break;		 //��ʾ�ڶ�λ
		 case(2):LSA=0;LSB=1;LSC=0;break;	   	 //��ʾ����λ
		 case(3):LSA=1;LSB=1;LSC=0;break;	   	 //��ʾ����λ
	   }
	  
	  P0=digdata[i];							 //���Ͷ�ѡ����
	  delay (100);								 //1ms  ���һ��ʱ��ɨ��
	  P0=0x00;                                   //��Ӱ
	
	}	 

}


/************************   
  �������λ���ݴ�����
************************/
void datadispose()
{
	digdata[0]=smgduan[number%1000%100%10];	 //��λ
	digdata[1]=smgduan[number%1000%100/10];	 //ʮλ
	digdata[2]=smgduan[number%1000/100];		 //��λ
	digdata[3]=smgduan[number/1000];			 //ǧλ
}


/************************   
         ������
************************/
void main()
{
  while(1)
   {
	  keydisprose ();
	  datadispose();
	  digdisplay ();
   }
}