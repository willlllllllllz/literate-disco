#include "stm32f10x.h"  
#define MOD1_PIN     GPIO_Pin_8 
#define MOD2_PIN     GPIO_Pin_9
#define MOD3_PIN     GPIO_Pin_10
#define LED_PIN     GPIO_Pin_1 
int ButtonIsPressed(); 
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);		
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);					
	GPIO_SetBits(GPIOC, GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_1);		
}
void Delay_ms(uint32_t time);  
typedef enum {STOP,MANUAL,AUTO} State;
					int Button1_IsPressed() 
					{
						if (GPIO_ReadInputDataBit(GPIOC, MOD1_PIN) == 0) 
						{
								Delay_ms(10);  
								if (GPIO_ReadInputDataBit(GPIOC, MOD1_PIN) == 0) 
								{
										return 0;  
								}
						}
						return 1;  
					}
										int Button2_IsPressed() 
					{
						if (GPIO_ReadInputDataBit(GPIOC, MOD2_PIN) == 0) 
						{
								Delay_ms(10);  
								if (GPIO_ReadInputDataBit(GPIOC, MOD2_PIN) == 0) 
								{
										return 0;  
								}
						}
						return 1;  
					}
										int Button3_IsPressed() 
					{
						if (GPIO_ReadInputDataBit(GPIOC, MOD3_PIN) == 0) 
						{
								Delay_ms(10);  
								if (GPIO_ReadInputDataBit(GPIOC, MOD3_PIN) == 0) 
								{
										return 0;  
								}
						}
						return 1;  
					}





State currentState = STOP; 


void StateMachine_Update(void) 
{
 
    if (Button1_IsPressed()) 
		{
        currentState = STOP;
    }


    else if (Button2_IsPressed()) 
		{
        currentState = MANUAL;
    }


    else if (Button3_IsPressed()) 
		{
        currentState = AUTO;
    }


}

void performStateAction() 
{
    switch (currentState) 
		{
        case STOP:
            GPIO_ResetBits(GPIOC, LED_PIN);
            break;
        case MANUAL:
            GPIO_SetBits(GPIOC, LED