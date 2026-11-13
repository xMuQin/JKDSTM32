#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Bazzer.h"
#include "LightSensor.h"
#include "OLED.h"

uint8_t KeyNum;

int main(void)
{
	Bazzer_Init();
	LightSensor_Init();
	OLED_Init();
	OLED_ShowString(2,1,"sadaw");
	while(1)
	{
		if(LightSensor_Get()==1)
		{
			Bazzer_ON();
		}
		else
		{
			Bazzer_OFF();
		}
	}
}
