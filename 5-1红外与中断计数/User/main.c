#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "EXTI14ZD.h"

uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	EXTI14ZD_Init();
	
	OLED_ShowString(1,1,"Count");
	while(1)
	{
		OLED_ShowNum(1,7,Countsensor_get(),4);
	}
}
