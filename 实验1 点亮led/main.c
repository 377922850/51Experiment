#include <reg52.h>
#define N 2  //��������
#define T 700  //�趨T��ֵ��

sbit LED=P2^0;
int t=0;
char sign=0; //������־

void delay(int time)   //��ʱ
{
while(time>0)
   time--;
}

void designed() //���ƺ���
{
if(sign==0)
   t+=(N+1);  //������ʱ��Ͽ�
    else
  t-=N;   //�����ʱ��   ����
}

void wake() //�жϺ���
{
  if(t>T)//���t����������ֵT
  {
     t=T;
     sign =  1;//���Ʊ���
  }
  else if(t<0)
  {
     t=0;
     sign = 0; 
  }
}

void main ()//������
{
  while(1)
    {
      designed();
      wake();
      LED = 0; //����
      delay(t);
      LED = 1;//����
      delay(T-t);
    }
}