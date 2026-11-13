#ifndef __SERIAL_H__
#define __SERIAL_H__

void Serial_Init(void);
void Serial_SendData(uint8_t Byte);
void Serial_SendString(char* string);
void Serial_Arrey(uint8_t* Arr,uint8_t Size);
void Serial_SendNum(uint32_t Num,uint8_t length);

#endif
