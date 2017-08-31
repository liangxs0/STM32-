//串口1 USART1 GPIOA9 TXD GPIOA10 RXD
#ifndef _USART1_H_
#define _USART1_H_
#include <stm32f10x.h>
//USART 的初始化的串口波特率设置
//GPIO口的是使能，和USART1的使能，设置IO口的模式
//写入波特率比，使能串口，串口的接受发送

void USART1_Init (u32 bount);

void USART1_Char(u8 ch);

void UASET1_Str(u8* str);

u8 Getdat(void);

#endif

