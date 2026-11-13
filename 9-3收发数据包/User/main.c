#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include <stdio.h>

uint8_t KeyNum;

int main(void)
{
	//uint8_t Arr[4]={0x22,0x55,0x69,0x45};
	OLED_Init();
	Serial_Init();
	
	//Serial_SendData(0x45);
	//Serial_SendString(Hello World!);
	//Serial_Arrey(Arr,4);
	Serial_SendNum(12345,5);
	//printf("123456");
	OLED_ShowString(1,1,"RxData:");
	
	while(1)
	{
		//Serial_SendData(0x45);
		//Delay_ms(500);
		OLED_ShowHexNum(1,8,REData,2);
		Serial_SendData(REData);
	}
}
