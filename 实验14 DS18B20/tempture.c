#include "tempture.h"


/******************* 
      ��ʱ����       
*******************/
uchar tempturelimit[2]={25,5};

void delay10us()   //��� 0us  ��ʱ10us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=2;a>0;a--);
}

void delay15us()   //��� 0us	��ʱ15us
{
    unsigned char a;
    for(a=6;a>0;a--);
}


void delay45us()   //��� 0us	 ��ʱ45us
{
    unsigned char a;
    for(a=21;a>0;a--);
}

void delay80us()   //��� 0us	 ��ʱ80us
{
    unsigned char a,b;
    for(b=11;b>0;b--)
        for(a=2;a>0;a--);
}

void delay600us()   //��� 0us	  ��ʱ600us
{
    unsigned char a,b;
    for(b=3;b>0;b--)
        for(a=98;a>0;a--);
}


void delay1ms(uint y)	  //y=1Ϊ1ms
{
	uint x;
	for( ; y>0; y--)
	  {
		for(x=110; x>0; x--);
	  }
}

/******************* 
   DS18B20��ʼ��       
*******************/
uchar DS18B20start ()		  //��ʼ���ɹ�����1��ʧ�ܷ���0
{
	  dataline=0;			  //����������
	  delay600us();			  //��ʱ600us
	  dataline=1;			  //����������
	  delay80us;			  //�ȴ�80us
	  while(dataline)		  //�ȴ����صĵ͵�ƽ
	   {
	   	 delay600us();		  //���г�ʱ�ж�
		 return 0;			  //����0
	   }
	  return 1;				  //����1
	  delay600us();	  		  //��ʱ600us
}

 
/******************* 
   DS18B20д����       
*******************/
void DS18B20writebyte (uchar dat)	 //��DS18B20д��һ���ֽ�
{
   uchar i,j;
   for(j=0;j<8;j++)
    {
      dataline = 0;		             //������������
      delay15us();					         //��ʱ1us
      dataline = dat & 0x01;	     //��λ��   ��0��0      ����dat=1010 1010 & 0000 0001 =1010 1010     
	  delay80us();					 //��ʱ80us
	  dataline = 1;			         //����������	  
	  dat >>= 1;				     //����һλ				    dat=0101 0101  �ε�λ��Ϊ���λ   	 
    }
}


/******************* 
   DS18B20������       
*******************/
uchar DS18B20readbyte ()				 //��DS18B20�ж�ȡһ������
{
   uchar bi,byte,i,j;
   for (i=0;i<8;i++)
   {
     dataline = 0;						 //����������
     j++;                                //��ʱ1us 
   	 dataline = 1;                       //�����������ߣ��ͷ�����׼��������
	 delay10us();                        //��ʱ6us
	 bi = dataline;
	 byte = (byte >> 1)|(bi << 7);       //��byte����һλ��Ȼ����������7λ���bi��ע���ƶ�֮���Ƶ���λ��0
	 delay45us ();
   }
   return byte;
}

/******************* 
  DS18B20�¶ȱ���       
*******************/
void DS18B20tempturealarm()
{
   DS18B20start ();							 //��ʼ��
   DS18B20writebyte (0xcc);					 //����ROM�������� �����ڵ�Ƭ����
   DS18B20writebyte (0x4e);					 //�������ڲ�RAM3��4�ֽ�д�����޺����޵��¶���������
   DS18B20writebyte (tempturelimit[0]);		 //����Ϊ25
   DS18B20writebyte	(tempturelimit[1]);		 //����Ϊ5
   DS18B20start ();							 //��ʼ��
   DS18B20writebyte (0xcc);					 //����ROM�������� �����ڵ�Ƭ����
   DS18B20writebyte (0x48);					 //��RAM��3.4�ֽ�����д��EEPROM
    
   	
}


/******************* 
  DS18B20�¶ȱ任       
*******************/
void DS18B20changetempture ()
{
  DS18B20start ();						  //��ʼ��
  delay1ms(1);							  //��ʱ1ms
  DS18B20writebyte (0xcc);				  //дһ���ֽ� 0xcc ����ROM�������� �����ڵ�Ƭ����
  DS18B20writebyte (0x44);				  //�����¶�ת�� 12λ �������9ΪRAM��
  
}


/********************* 
 DS18B20��ȡ�¶�����       
*********************/
void DS18B20readempture ()				  //���Ͷ�ȡ�¶�����
{
  DS18B20start ();						  //��ʼ��
  delay1ms(1);							  //��ʱ1ms
  DS18B20writebyte (0xcc);				  //дһ���ֽ� 0xcc ����ROM�������� �����ڵ�Ƭ����
  DS18B20writebyte (0xbe);				  //дһ���ֽ� oxeh  ���ڲ�RAM�е�9
}


/********************* 
    DS18B20��ȡ�¶�       
*********************/
int DS18B20tempture ()					  //��ȡ�¶�
{
  int temp=0;
  uchar temph,templ;					  //temphΪ��8λ  templΪ�Ͱ�λ
  DS18B20changetempture ();				  //�¶�ת��
  DS18B20readempture ();				  //��ȡ�¶�ָ��
  templ = DS18B20readbyte ();			  //��ȡ�¶�ֵ��16λ���ȶ����ֽ�
  temph = DS18B20readbyte ();	    	  //�ٶ����ֽ�
  temp = temph;
  temp <<= 8;
  temp |= templ;
  return temp;
}