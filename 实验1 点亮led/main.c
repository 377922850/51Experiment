#include <reg52.h>
#define N 2  //控制速率
#define T 700  //设定T的值，

sbit LED=P2^0;
int t=0;
char sign=0; //亮暗标志

void delay(int time)   //延时
{
while(time>0)
   time--;
}

void designed() //控制函数
{
if(sign==0)
   t+=(N+1);  //灯亮的时间较快
    else
  t-=N;   //灯灭的时间   较慢
}

void wake() //判断函数
{
  if(t>T)//如果t超过了做大值T
  {
     t=T;
     sign =  1;//控制变量
  }
  else if(t<0)
  {
     t=0;
     sign = 0; 
  }
}

void main ()//主函数
{
  while(1)
    {
      designed();
      wake();
      LED = 0; //灯亮
      delay(t);
      LED = 1;//灯灭
      delay(T-t);
    }
}