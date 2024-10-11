#include <reg52.h>
#include <intrins.h>
#define unit unsigned int 
#define uchar unsigned char
uchar aa;
unit a,i,b,e,LED;
sbit beep = P2^5;
void delay1(unit);
void delay1(unit b)
{
 
  for(a=b;a>0;a--)
   for(i=114;i>0;i--); 
}
void beef1()
{
      e=500;
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
	
	b=8;
			while(b>0)
		  {
				b--;
			
				if(LED>=8)
					LED=0;
				P2=~(0x01<<LED);
				beef1();
				
				P2=0xff;
			
				delay1(500);
				LED++;
				
			}
	b=8;
			while(b>0)
		  {
				b--;
			
				if(LED>=8)
					LED=0;
				P2=~(0x80>>LED);
				beef1();
				
				P2=0xff;
				
				delay1(500);
				LED++;
			  
			}
		


     
			

}
