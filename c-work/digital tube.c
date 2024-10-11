#include <reg52.h>
#define unit unsigned int 
unit a,i,b,e;
sbit P22=P2^2;
sbit P23=P2^3;
sbit P24=P2^4;
unsigned char code table[]={
	  0x3f,0x06,0x5b,0x4f,
		0x66,0x6d,0x7d,0x07,
		0x7f,0x6f,0x77,0x7c,
		0x39,0x5e,0x79,0x71};
void delay1(unit b)
{
 
  for(a=b;a>0;a--)
   for(i=114;i>0;i--); 
}

void main()
{
	
	while(1)
	{
		unit d,f,g;
	P0=table[e];
	e++;
if(d==2)
{
	f++;
  d=0;
}
if(f==2)
{
	g++;
  f=0;
}
if(g==2)
{
	g++;
  g=0;
}
	P22=d;
	P23=f;
	P24=g;
d++;
delay1(500);
	}
}