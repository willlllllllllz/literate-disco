#include <reg52.h>
#include <intrins.h>
#define unit unsigned int 
#define uchar unsigned char 
sbit lcdrs=P2^6;
sbit lcden=P2^7;
sbit wr=P2^5;
sbit beep = P2^5;
unit ocod=1234,cod,ncod,numk,a,i,e;
uchar key,num;
unsigned char code table[]={
	  0x3f,0x06,0x5b,0x4f,
		0x66,0x6d,0x7d,0x07,
		0x7f,0x6f,0x77,0x7c,
		0x39,0x5e,0x79,0x71,
    0x00,0x40,0x80,0x39};

char code tab1[]="input code";
char code tab2[]="OK or reset";
char data tab3[]="  _ _ _ _";
char code tab4[]="  * * * *";
char code tab5[]="code corret";
char code tab6[]="   UNLOCK";
char code tab7[]="  E R R O R";
char code tab8[]="err time:";
char code tab9[]="  _ _ _ _";
char code taba[]="please wait";
char code tabb[]="     60s";
char code tabc[]="reseting....";
char code tabd[]="input new code";
char code tabe[]=" SUCCESSFULLY";
char code tabf[]="change";	
char code tabg[]="remember your";	
char code tabh[]="new code:";	
void delay(unit d)
{
  for(a=d;a>0;a--)
   for(i=114;i>0;i--); 
}
void beef1()
{
unit b;
      b=1000;
      while(b>0)
      {
      beep = 0;
         for(a=1;a>0;a--)
       for(i=10;i>0;i--);   
      beep = 1;
           for(a=1;a>0;a--)
       for(i=10;i>0;i--);
       b--; 
      }     
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
void display(uchar numk)
{
P0=table[numk];
delay(1);
}
int lcd_pow(int X,int Y)
{
uchar i;
int result=1;
for(i=0;i<Y;i++)
{
result*=X;
}	
return result;
}
void lcd_inpt(int i)
{
init();
	tab3[2*i]=tab4[2*i];
							write_com(0x80);
							for(num=0;num<=9;num++)
							{
							   write_date(tab1[num]);
//								 delay(5);
							}
							write_com(0x80+0x40);
							for(num=0;num<=8;num++)
							{
							   write_date(tab3[num]);
//								 delay(5);
							}						
}
void lcd_load(int cod)
{
init();
							write_com(0x80);
							for(num=0;num<=10;num++)
							{
							   write_date(tab2[num]);
//								 delay(5);
							}
							write_com(0x80+0x40);
							for(num=4;num>0;num--)
							{
							   write_date(cod/lcd_pow(10,num-1)%10+'0');
//								 delay(5);
							}							
}
void lcd_corret()
{
init();
							write_com(0x80);
							for(num=0;num<=10;num++)
							{
							   write_date(tab5[num]);
								 delay(5);
							}
							write_com(0x80+0x40);
							for(num=0;num<=8;num++)
							{
							   write_date(tab6[num]);
								 delay(5);
							}							
}
void lcd_err(int e)
{
init();
							write_com(0x80);
							for(num=0;num<=10;num++)
							{
							   write_date(tab7[num]);
								 delay(5);
							}
							write_com(0x80+0x40);
							for(num=0;num<=9;num++)
							{
							   write_date(tab8[num]);
								 delay(5);
							}	
							write_com(0x80+0x49);

							   write_date(e+'0');
								 delay(5);														
}
void lcd_wait()
{
init();
							write_com(0x80);
							for(num=0;num<=10;num++)
							{
							   write_date(taba[num]);
								 delay(5);
							}
							write_com(0x80+0x40);
							for(num=0;num<=7;num++)
							{
							   write_date(tabb[num]);
								 delay(5);
							}							
}
void lcd_reset()
{
init();
							write_com(0x80);
							for(num=0;num<=10;num++)
							{
							   write_date(taba[num]);
								 delay(50);
							}
							write_com(0x80+0x40);
							for(num=0;num<=10;num++)
							{
							   write_date(tabc[num]);
								 delay(50);
							}							
}
void reset_code(int i)
{
init();
		tab3[2*i]=tab4[2*i];
							write_com(0x80);
							for(num=0;num<=12;num++)
							{
							   write_date(tabd[num]);
								 delay(5);
							}
							write_com(0x80+0x40);
							for(num=0;num<=8;num++)
							{
							   write_date(tab3[num]);
								 delay(5);
							}							
}
void lcd_reset_succ()
{
init();
							write_com(0x80);
							for(num=0;num<=5;num++)
							{
							   write_date(tabf[num]);
								 delay(50);
							}
							write_com(0x80+0x40);
							for(num=0;num<=12;num++)
							{
							   write_date(tabe[num]);
								 delay(50);
							}							
}
void rem_ncod(int cod)
{
init();
							write_com(0x80);
							for(num=0;num<=12;num++)
							{
							   write_date(tabg[num]);
								 delay(50);
							}
							write_com(0x80+0x40);
							for(num=0;num<=8;num++)
							{
							   write_date(tabh[num]);
								 delay(50);
							}
							write_com(0x80+0x49);
							for(num=4;num>0;num--)
							{
							   write_date(cod/lcd_pow(10,num-1)%10+'0');
								 delay(50);
							}							
}
char mensurekey()
{
uchar temp;
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
		key=17;
		break;
		case 0xde:
		key=9;
		break;
		case 0xbe:
		key=6;
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
		key=0;
		break;
		case 0xdd:
		key=8;
		break;
		case 0xbd:
		key=5;
		break;
		case 0x7d:
		key=2;
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
	delay(3);
	temp=P1;
	temp=temp&0xf0;
if(temp!=0xf0)
{
	temp=P1;
	switch(temp)
	{
	  case 0xeb:
		key=19;
		break;
		case 0xdb:
		key=7;
		break;
		case 0xbb:
		key=4;
		break;
		case 0x7b:
		key=1;
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
		key=16;
		break;
		case 0xd7:
		key=16;
		break;
		case 0xb7:
		key=16;
		break;
		case 0x77:
		key=16;
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

void led()
{
unit b,LED;
	b=16;
			while(b>0)
		  {
				b--;
			
				if(LED>=8)
					LED=0;
				P2=~(0x01<<LED);

				delay(50);			
				P2=0xff;
				
				LED++;				
			}
	b=16;
			while(b>0)
		  {
				b--;
			
				if(LED>=8)
					LED=0;
				P2=~(0x80>>LED);

					delay(50);		
				P2=0xff;
				
				LED++;			  
			}
}
int resetcod()
{
	char key0;	
	int ncod1,ncod2,ncod3,ncod4,e=0,i;													
								for(i=8;i>=0;i--)
								{
								   tab3[2*i]=tab9[2*i];
								}
												reset_code(0);
													delay(1000);		
                 		  key=999;
											key0=999;
											display(18); 

											while(1)
											{					    
											mensurekey();	
											if(key != 17&&key != 19&&key != 16&&key0 != key)
											 {break;}		            
										 key0=key;					   				 
											}
											ncod1=key; i=1; reset_code(i);;
											display(ncod1);
				delay(200);	display(18);						
											key=999;
											key0=999;
											while(1)
											{													
											mensurekey();	
											if(key != 17&&key != 19&&key != 16&&key0 != key)
											 {break;}		            
										 key0=key;					   				 
											}
											ncod2=key; i=2;reset_code(i);
											display(ncod2);
				delay(200);  display(18); 
											key=999;
											key0=999;
											while(1)
											{												
											mensurekey();	
											if(key != 17&&key != 19&&key != 16&&key0 != key)
											 {break;}		            
										 key0=key;					   				 
											}
											ncod3=key; i=3;reset_code(i);
											display(ncod3);
				delay(200);  display(18);
											key=999;
											key0=999;
											while(1)
											{					
											mensurekey();	
											if(key != 17&&key != 19&&key != 16&&key0 != key)
											 {break;}		            
										 key0=key;					   				 
											}
											ncod4=key; i=4;reset_code(i);
											display(ncod4);
				delay(200); 											
											ncod=ncod1*1000+ncod2*100+ncod3*10+ncod4;
											rem_ncod(ncod);
                      key=999;											
											return ncod;
}       
int keycod()
{
							char key0;							
							int cod1,cod2,cod3,cod4,i;
	
								for(i=8;i>=0;i--)
								{
								   tab3[2*i]=tab9[2*i];
								}
                 		  key=999;
											key0=999;
										 lcd_inpt(i);	
											display(18); 

											while(1)
											{					    
											mensurekey();	
											if(key != 17&&key != 19&&key != 16&&key0 != key)
											 {break;}		            
										 key0=key;					   				 
											}
											cod1=key; i=1; lcd_inpt(i);
											display(cod1);
				delay(200);	display(18);						
											key=999;
											key0=999;
											while(1)
											{													
											mensurekey();	
											if(key != 17&&key != 19&&key != 16&&key0 != key)
											 {break;}		            
										 key0=key;					   				 
											}
											cod2=key; i=2;lcd_inpt(i);
											display(cod2);
				delay(200);  display(18); 
											key=999;
											key0=999;
											while(1)
											{											
											mensurekey();	
											if(key != 17&&key != 19&&key != 16&&key0 != key)
											 {break;}		            
										 key0=key;					   				 
											}
											cod3=key; i=3;lcd_inpt(i);
											display(cod3);
				delay(200);  display(18);
											key=999;
											key0=999;
											while(1)
											{				
											mensurekey();	
											if(key != 17&&key != 19&&key != 16&&key0 != key)
											 {break;}		            
										 key0=key;					   				 
											}
											cod4=key; i=4;lcd_inpt(i);
											display(cod4);
				delay(200);  key=999;	 
											cod=cod1*1000+cod2*100+cod3*10+cod4;
											lcd_load(cod);

											return cod;
}
                                                      void  main()
{       


	 while(1)
				{	e=0;	
					mensurekey();	
					if(key == 0)	
					{   
					P0=0x00;
					}
          else
	      break;
	      }

	      while(1)
				{	
            keycod();
						while(1)
						{					
											mensurekey();	
								if(key != 16&&key == 17)	
								{									
													lcd_reset();
													delay(3000);
									key=999;
						break;													
								}	
								      mensurekey();
								if(key != 16&&key == 19)
								{
											key=999;									
									if(cod==ocod)
									{
													lcd_corret();

													led();
							      while(1)
										{			

											  mensurekey();	
											if(key != 16 && key == 17)	
												{
											 													
                          resetcod();
													delay(5000);
													ocod=ncod;
                          lcd_reset_succ();													
													delay(2000);
									        key=999;	
													lcd_corret();
													delay(50);
												}
												mensurekey();
													if(key != 16 && key == 19)
											  {
								
                    break;
											  }												 
										}		
			                         											
									}
									else
									{	
										        e++;														
										        beef1();
														lcd_err(e);
														delay(2000);
														if(e >= 3)
														{
														e=0;
														lcd_wait();
														delay(60000);															
														}
														else
														{
						break;								
														}
						
								  }
            break;
								}		            
						}
				}	
}
