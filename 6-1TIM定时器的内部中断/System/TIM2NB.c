#include "stm32f10x.h"                  // Device header

void TIM2NB_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	TIM_InternalClockConfig(TIM2);

	TIM_TimeBaseInitTypeDef TIM2_InitStruct;
	TIM2_InitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM2_InitStruct.TIM_Period=10000-1;
	TIM2_InitStruct.TIM_Prescaler=7200-1;
	TIM2_InitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM2_InitStruct.TIM_RepetitionCounter=0;
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	TIM_TimeBaseInit(TIM2,&TIM2_InitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM2, ENABLE);
}
