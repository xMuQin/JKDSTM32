#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "TIM2NB.h"

uint16_t Num;

int main(void)
{
	OLED_Init();
	TIM2NB_Init();
	OLED_ShowString(2,1,"NUM:");
	while(1)
	{
		OLED_ShowNum(2,5,Num,4);
	}
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)		
	{
		Num ++;												
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);			
	}															
}
