#include "stm32f10x.h"                  // Device header
#include "TWMLED.h"

void DUOJI_Init(void)
{
	TWMLED_Init();
}

void DUOJI_XZ(float i)
{
	TIM_SetCompare2(TIM2,i/180*2000+500);
}
