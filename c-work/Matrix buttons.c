#include <reg52.h>
#include <intrins.h>
#define unit unsigned int 
#define uchar unsigned char 
unit num,a,i;
unsigned char code table[]={
	  0x3f,0x06,0x5b,0x4f,
		0x66,0x6d,0x7d,0x07,
		0x7f,0x6f,0x77,0x7c,
		0x39,0x5e,0x79,0x71};
void delay(unit d)
{

  for(a=d;a>0;a--)
   for(i=114;i>0;i--); 
}
void display(uchar num)
{
P0=table[num];
delay(1);
}
char mensurekey()
{
uchar temp,key;
P1=0xfe;
temp=P1;
temp=temp&0xf0;
if(temp!=0xf0)
{	
	delay(10);
	temp=P1;
	temp=temp&0xf0;
if(temp!=0xf0)
{
	temp=P1;
	switch(temp)
	{
	  case 0xee:
		key=0;
		break;
		case 0xde:
		key=1;
		break;
		case 0xbe:
		key=2;
		break;
		case 0x7e:
		key=3;
		break;
	}
	while(temp!=0xf0)
	{
	temp=P1;
		temp=temp&0xf0;
	}

}
}


P1=0xfd;
temp=P1;
temp=temp&0xf0;
if(temp!=0xf0)
{	
	delay(10);
	temp=P1;
	temp=temp&0xf0;
if(temp!=0xf0)
{
	temp=P1;
	switch(temp)
	{
	  case 0xed:
		key=4;
		break;
		case 0xdd:
		key=5;
		break;
		case 0xbd:
		key=6;
		break;
		case 0x7d:
		key=7;
		break;
	}
	while(temp!=0xf0)
	{
	temp=P1;
		temp=temp&0xf0;
	}

}
}

P1=0xfb;
temp=P1;
temp=temp&0xf0;
if(temp!=0xf0)
{	
	delay(10);
	temp=P1;
	temp=temp&0xf0;
if(temp!=0xf0)
{
	temp=P1;
	switch(temp)
	{
	  case 0xeb:
		key=8;
		break;
		case 0xdb:
		key=9;
		break;
		case 0xbb:
		key=10;
		break;
		case 0x7b:
		key=11;
		break;
	}
	while(temp!=0xf0)
	{
	temp=P1;
		temp=temp&0xf0;
	}

}
}


P1=0xf7;
temp=P1;
temp=temp&0xf0;
if(temp!=0xf0)
{	
	delay(10);
	temp=P1;
	temp=temp&0xf0;
if(temp!=0xf0)
{
	temp=P1;
	switch(temp)
	{
	  case 0xe7:
		key=12;
		break;
		case 0xd7:
		key=13;
		break;
		case 0xb7:
		key=14;
		break;
		case 0x77:
		key=15;
		break;
	}
	while(temp!=0xf0)
	{
	temp=P1;
		temp=temp&0xf0;
	}


}
}


return key;
}

                       void  main()
            {
					   char key;
					   key=0;
							while(1)
              {
					    mensurekey();		
							key=mensurekey();
        			display(key);

				      }
            }
