//����1 USART1 GPIOA9 TXD GPIOA10 RXD
#ifndef _USART1_H_
#define _USART1_H_
#include <stm32f10x.h>
//USART �ĳ�ʼ���Ĵ��ڲ���������
//GPIO�ڵ���ʹ�ܣ���USART1��ʹ�ܣ�����IO�ڵ�ģʽ
//д�벨���ʱȣ�ʹ�ܴ��ڣ����ڵĽ��ܷ���

void USART1_Init (u32 bount);

void USART1_Char(u8 ch);

void UASET1_Str(u8* str);

u8 Getdat(void);

#endif

