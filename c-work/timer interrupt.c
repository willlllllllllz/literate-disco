#include <reg52.h>
#include <intrins.h>
#define unit unsigned int 
#define uchar unsigned char 
sbit dula = P2^6;
sbit wela=P2^7;
sbit P2_0=P2^0;
unit a,i;
uchar tt;

void delay(unit d)
{

  for(a=d;a>0;a--)
   for(i=114;i>0;i--); 
}

                         void main()
												{
														TMOD=0x01;
													TH0=(65535-50000)/256;
													TL0=(65535-50000)%256;
													EA=1;
													ET0=1;
													TR0=1;
													while(1);
										
											
													
													
												}
void timer() interrupt 1
{
TH0=(65535-50000)/256;
TL0=(65535-50000)%256;
	tt++;
	if(tt==20)
	{
	tt=0;
		P2_0=~P2_0;
	}
	
}