#include <reg52.h>
#define unit unsigned int 
#define uchar unsigned char 
//sbit lcden=P3^4;
//sbit lcdrs=P3^5;
sbit lcdrs=P2^6;
sbit lcden=P2^7;
sbit wr=P2^5;

char num;
char code table[]="zzs LOVE U";
char code table1[]="Li qing";
void delay(unit d)
{
unit a,i;
  for(a=d;a>0;a--)
   for(i=114;i>0;i--); 
}
void write_com(char com)
{
lcdrs=0;
wr=0;	
P0=com;
delay(5);
lcden=1;
delay(5);
lcden=0;	
}
void write_date(char date)
{
	
lcdrs=1;
wr=0;	
P0=date;
delay(5);
lcden=1;
delay(5);
lcden=0;	
}
void init()
{

lcden=0;
write_com(0x38);
write_com(0x0c);
write_com(0x06);
write_com(0x01);
}
                     void    main()
            {

             num
							while(1);
            }
