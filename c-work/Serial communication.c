#include <reg52.h>
#define unit unsigned int 
#define uchar unsigned char 
void delay(unit d)
{
unit a,i;
  for(a=d;a>0;a--)
   for(i=114;i>0;i--); 
}
void init()
{
							SCON=0x50;
							PCON |=0x80;
					    TMOD &=0x0f;
							TMOD |=0x20;
							TL1=0xf3;
							TH1=0xf3;
							ET1=0;							
							TR1=1;
							EA=1;
							ES=1;


							
}
                     void    main()
            {
              init();
						
							while(1);
							{

							}
            }
void tled() interrupt 4
{
								if(RI==1)
								{								
								P2=SBUF;
                RI=0;
								}
}
