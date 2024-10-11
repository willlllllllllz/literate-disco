#include <reg52.h>
#include <intrins.h>
#define unit unsigned int 
#define uchar unsigned char 
sbit beep = P2^5;
unit t,e,a,i,b;
uchar tt;
void delay(unit d)
{

  for(a=d;a>0;a--)
   for(i=114;i>0;i--); 
}

void beef1()
{
      e=1000;
      while(e>0)
      {
      beep = 0;
         for(a=1;a>0;a--)
       for(i=10;i>0;i--);   
      beep = 1;
           for(a=1;a>0;a--)
       for(i=10;i>0;i--);
       e--; 
      }     
}
        

                         void main()
            {
             EA=1;
             EX0=1;
             EX1=1;
             IT0=0;
             IT1=0;
             while(1);
          
              
            }
void timer0() interrupt 1
{

for(b=3;b>0;b--)
{  
beef1();
P2=0xff;
delay(100);
P2=~P2;
delay(100);
}  
}
void timer1() interrupt 2
{

 t=0xfe;
  for(b=16;b--;b>=0)
  {
  delay(200);
   P2=t;
t=_crol_(t,1);
  }

}