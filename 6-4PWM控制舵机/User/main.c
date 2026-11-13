#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "DUOJI.h"
#include "Key.h"

float i;
uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	DUOJI_Init();
	Key_Init();	
	
	OLED_ShowString(1, 1, "Angle:");
	while(1)
	{
		KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
			i+=30;
			if(i>180)
			{
				i=0;
			}
		}
		DUOJI_XZ(i);
		OLED_ShowNum(1, 7, i, 3);
	}
}
