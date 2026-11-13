#include "stm32f10x.h"                  // Device header

#ifndef __AD_H__
#define __AD_H__

extern uint16_t DataS[4];

void AD_Init(void);
//uint16_t AD_GetValue(uint8_t ADC_Channel);

#endif
