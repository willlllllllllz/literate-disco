#include <reg52.h>
#include <intrins.h>
#define unit unsigned int 
#define uchar unsigned char 
sbit d1=P2^0;
sbit key1=P3^1;
sbit key2=P3^2;
sbit key3=P3^3;
sbit key4=P3^0;
sbit beep = P2^5;
sbit P22=P2^2;
sbit P23=P2^3;
sbit P24=P2^4;
unit e,a1,a2,b,a,i,num,num1,t1,t2,t;
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
													P3=0xff;
													while(1)
													{
														if(key1==0)
													{
														delay(5);
														if(key1==0)
														{
															beef1();
														
														}
											while(!key1);
												delay(5);
													while(!key1);
													}	
														if(key2==0)
													{
														delay(5);
														if(key2==0)
														{
															for(a1=2;a1>0;a1--)
															{
															t1=0xfe;
															t2=0x7f;
															for(a2=4;a2>0;a2--)
															{
															t=t1&t2;
															P2=t;
															delay(200);
															t1=_crol_(t1,1);
                              t2=_cror_(t2,1);
                              delay(200);																
															}
														  }
														
														}
											while(!key2);
												delay(5);
													while(!key2);
													}	
													if(key4==0)
													{
														delay(5);
														if(key4==0)
														{
															d1=~d1;
															b=20;
															while(b>0)
                              {
																b--;
															delay(100);
															num++;
															if(num==10)
															{
															num=0;
															num1++;
															}
															if(num1==2&&num==1)
								              {
															num1=0;                                                                                                        
									            num=0;
															}
													
													  P22=1;
														P23=0;
														P24=0;
													P0=table[num1];	
													 	delay(3); 	
														P22=0;
														P23=0;
														P24=0;
													P0=table[num];
														delay(3); 
															}
														P0=0x00;
														}
											while(!key4);
												delay(5);
													while(!key4);
													}   
													
													if(key3==0)
													{
														delay(5);
														if(key3==0)
														{
															d1=~d1;
															b=200;
															while(b>0)
															{
																b--;
														P22=1;
														P23=1;
														P24=1;
													 P0=table[0];
														delay(3);
													  P22=0;
														P23=1;
														P24=1;
													P0=table[15];
													 	delay(3); 
													  P22=1;
														P23=0;
														P24=1;
													P0=table[15];
													 	delay(3); 
															}
															P0=0x00;
														}
											while(!key3);
												delay(5);
													while(!key3);
													}                                                                                                            ;
									    
													}
												}
