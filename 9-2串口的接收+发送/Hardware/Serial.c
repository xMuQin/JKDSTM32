#include "stm32f10x.h"                  // Device header
#include <stdio.h>

uint16_t REData;

void Serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate=9600;
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Init(USART1,&USART_InitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);
	USART_Cmd(USART1,ENABLE);
}

void Serial_SendData(uint8_t Byte)
{
	USART_SendData(USART1,Byte);
	while (USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
}

void Serial_Arrey(uint8_t* Arr,uint8_t Size)
{
	uint8_t i;
	for(i=0;i<Size;i++)
	{
		Serial_SendData(Arr[i]);
	}
	while (USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
}

void Serial_SendString(char* string)
{
	uint8_t i;
	for(i=0;string[i]!='\0';i++)
	{
		Serial_SendData(string[i]);
	}
	while (USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
}

uint32_t Serial_Pow(uint32_t X,uint32_t Y)
{
	uint32_t Result = 1;
	while(Y--)
	{
		Result*=X;
	}
	return Result;
}

void Serial_SendNum(uint32_t Num,uint8_t length)
{
	uint8_t i;
	for(i=0;i<length;i++)
	{
		Serial_SendData(Num/Serial_Pow(10,length-i-1)%10+'0');
	}
}

int fputc(int ch,FILE *f)
{
	Serial_SendData(ch);
	return ch;
}

void USART1_IRQHandler(void)
{
	if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==SET)
	{
		REData=USART_ReceiveData(USART1);
	}
}









