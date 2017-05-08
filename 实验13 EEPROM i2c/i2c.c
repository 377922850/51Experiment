#include "i2c.h"

void delay10us()							  //��ʱ 10us   ���Ϊ0
{
	    unsigned char a,b;
	    for(b=1;b>0;b--)
		for(a=2;a>0;a--);

}								  

void  i2cstartsignal ()					  //��ʼ�ź�
{										 //��SCLʱ���ź��ڸߵ�ƽ�ڼ�SDA�źŲ���һ���½���
	  SDA=1;							 //����������
	  delay10us ();
	  SCL=1;							 //����ʱ����
	  delay10us ();
	  SDA=0;							 //���������ߣ������½���
	  delay10us ();
	  SCL=0;							 //����ʱ����
	  delay10us ();
}		


void i2cstopsignal ()			  //��ֹ�źţ���SCLʱ���źŸߵ�ƽ�ڼ�SDA�źŲ���һ��������
{
	  SDA=0;					  //����������
	  delay10us ();
	  SCL=1;					  //����ʱ����
	  delay10us ();
	  SDA=1;					  //���������� ����������
	  delay10us ();	
}							

/***********************   
   ͨ��I2C����һ���ֽ�
***********************/
unsigned char i2csendbyte (unsigned char dat)    //��ʼ֮��SDA��SCL��Ϊ0
{
	  unsigned char a,b=0;
	  for (a=0;a<8;a++)						   //���Ͱ˸��ֽ�
	   {	  	   
		   delay10us ();
		   SDA=dat>>7;
		   dat<<=1;
		   SCL=1;
		   delay10us ();
		   SCL=0;
		   delay10us ();
	   }					  
	  SDA=1;
	  delay10us ();
	  SCL=1;
	  delay10us ();
	  while(SDA)			 //�ȴ�Ӧ�𣬴��豸��SDA����
	   {
	   	   b++;
		   if(b>200)       //�������2000usû��Ӧ����ʧ�ܣ�����Ϊ��Ӧ�𣬱�ʾ���ս���
		    {
		   	   SCL=0;
			   delay10us ();
			   return 0;		   
		    }
	   }
	  SCL=0;
	  delay10us ();	  
	  return 1; 
}	


/***********************   
   ͨ��I2C��ȡһ���ֽ�
***********************/
unsigned char i2creadbyte ()
{	 
	 unsigned char a,dat=0;
	 SDA=1;
	 for(a=0;a<8;a++)			  //����8���ֽ�
	  {
	  	dat<<=1;
		dat=dat|SDA;
		SCL=1;
		delay10us ();	
		SCL=0;
		delay10us ();	
	  }
	 return dat;
}	


/***********************   
 ��At24c02��дһ������
***********************/
void At24c02write (unsigned char address,unsigned char dat)
{
	i2cstartsignal ();			 //��ʼ�ź�
	i2csendbyte (0xa0);			//����������ַ
	i2csendbyte (address);	   //����Ҫд���ڴ��ַ
	i2csendbyte (dat);		  //��������
	i2cstopsignal ();        //�����ź�
}				  


/************************   
 ��ȡAt24c02���һ������
************************/
unsigned char  At24c02read (unsigned char address)
{
    unsigned char number;
	i2cstartsignal ();			 //��ʼ�ź�
	i2csendbyte (0xa0);			//����д������ַ
	i2csendbyte (address);	   //����Ҫ��ȡ��������ַ
	i2cstartsignal ();		  //��ʼ�ź�
	i2csendbyte (0xa1);		 //���Ͷ�������ַ
	number=i2creadbyte ();	
	i2cstopsignal ();        //�����ź�
	return number;
}