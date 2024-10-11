#include <reg52.h>
#include <intrins.h>
#define unit unsigned int 
#define uchar unsigned char 
sbit beep = P2^5;
unit a,i,b,d,e,f;
uchar LED;
sbit P22=P2^2;
sbit P23=P2^3;
sbit P24=P2^4;
unsigned char code table[]={
	  0x3f,0x06,0x5b,0x4f,
		0x66,0x6d,0x7d,0x07,
		0x7f,0x6f,0x77,0x7c,
		0x39,0x5e,0x79,0x71};
void delay1(unit d)
{

  for(a=d;a>0;a--)
   for(i=114;i>0;i--); 
}
void dfg(unit d,f,g)
{


	P22=d;
	P23=f;
	P24=g;

}
void beef1()
{
unit a,i,e;
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
													LED=0xfe;
													b=16;
													while(b>0)
													{
													P2=LED;
														delay1(100);
														LED=_crol_(LED,1);
													b--;
													}
													
													f=55;
													while(f>0)
													{
														f--;
													dfg(1,1,1);
													P0=0x76;
														delay1(3);
													dfg(0,1,1);
													P0=table[14];
														delay1(3);
													dfg(1,0,1);
													P0=0x38;
														delay1(3);
													dfg(0,0,1);
													P0=0x38;
														delay1(3);
													dfg(1,1,0);
													P0=table[0];
														delay1(3);

													}	

													P0=0xff;
													delay1(500);
														


													
													
												}