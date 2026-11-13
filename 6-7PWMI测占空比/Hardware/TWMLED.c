#include "stm32f10x.h"                  // Device header

void TWMLED_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM2);
																
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;				
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720 - 1;	//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIMLED_InitStruct;
	TIM_OCStructInit(&TIMLED_InitStruct);
	
	TIMLED_InitStruct.TIM_OCMode=TIM_OCMode_PWM1;
	TIMLED_InitStruct.TIM_OCPolarity=TIM_OCPolarity_High;
	TIMLED_InitStruct.TIM_OutputState=TIM_OutputState_Enable;
	TIMLED_InitStruct.TIM_Pulse=0;
	TIM_OC1Init(TIM2,&TIMLED_InitStruct);
	
	TIM_Cmd(TIM2,ENABLE);
}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2,Compare);
}

void PWM_SetPrescalar(uint16_t Prescalar)
{
	TIM_PrescalerConfig(TIM2,Prescalar,TIM_PSCReloadMode_Immediate);

}
