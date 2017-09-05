/***
*FileName: briupUsart.h
*GreatteDate: 2017 8 25
*Author: Lamos
*Description: 串口
*Update
*/
#ifndef _USART_H_
#define _USART_H_
#include <stm32f10x.h>
#include <stdio.h>

#define CTS USART1->SR |= 0<<9;
/*briupUsart1Init ( u32 bound)
	bount 设置串口波特率
*/
void briupUsart1Init(u32 bount);
//发送函数 按字节
void usart1PutStr(u8* str);
void usart1Putchar(u8 ch);
//接受函数 按字节
u8 usart1Getstr(void);

#endif

