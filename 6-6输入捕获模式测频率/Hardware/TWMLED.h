#include "stm32f10x.h"                  // Device header

#ifndef __TWMLED_H__
#define __TWMLED_H__

void TWMLED_Init(void);
void PWM_SetCompare1(uint16_t Compare);
void PWM_SetPrescalar(uint16_t Prescalar);

#endif
