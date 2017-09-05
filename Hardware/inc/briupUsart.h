/***
*FileName: briupUsart.h
*GreatteDate: 2017 8 25
*Author: Lamos
*Description: ����
*Update
*/
#ifndef _USART_H_
#define _USART_H_
#include <stm32f10x.h>
#include <stdio.h>

#define CTS USART1->SR |= 0<<9;
/*briupUsart1Init ( u32 bound)
	bount ���ô��ڲ�����
*/
void briupUsart1Init(u32 bount);
//���ͺ��� ���ֽ�
void usart1PutStr(u8* str);
void usart1Putchar(u8 ch);
//���ܺ��� ���ֽ�
u8 usart1Getstr(void);

#endif

