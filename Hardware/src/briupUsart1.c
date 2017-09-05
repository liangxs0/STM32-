/***
*FileName: briupUsart.c
*GreatteDate: 2017 8 25
*Author: Lamos
*Description: ����
*Update
*/

/*briupUsart1Init ( u32 bound)
	bount ���ô��ڲ�����
*/

#include "briupUsart.h"
#include "briuoNVIC.h"

//���ڿ������߹ر�printf����ض�����
#if 1
//ʹ�ð�����ģʽ
#pragma import( __use_no_semihosting)

struct __FILE{
		int handle;
};

FILE __stdout;

_sys_exit(int x)
{
	x =  x;
}
//����ض������
//ch Ҫ���͵��ַ�
//FILE * f stdout ��׼�����
int fputc(int ch,FILE * f)
{
	while(!(USART1->SR & 1<<6));
	USART1->DR = ch;
	return ch;
}

#endif
void briupUsart1Init(u32 bount)
{
	//������ֵ������ 
	
	double temp = 72000000.0/(16.0*bount);
	u16 Mantissa = (u16)temp;
	u16 fraction = (temp - Mantissa);
	Mantissa = (Mantissa<<4)+fraction;
	//�Ĵ������ò���
	//GPIOA ��USART1��ʱ�ӿ���
	//IO�˿ڵ�����
	RCC->APB2ENR |= 1<<2| 1<<14;
	//tx->a9 ���츴�����
	GPIOA->CRH &= 0xfffff00f;//�� 10 9 
	GPIOA->CRH |= 0x0B<<4;//1011
	//rx->a10 ��������
	//GPIOA->CRH &= 0xfffff0ff;
	GPIOA->CRH |= 0x08<<8;
	GPIOA->ODR |= 1<<10;
	//USART1 �ļĴ�������
	USART1->BRR = Mantissa;
	USART1->CR1 |= 1<<13| 1<<3| 1<<2; 
	//USART1�ж�����
	USART1->CR1 |= 1<<5;//ʹ�ܽ��ջ������ǿ��ж�
	briupNVICPriorityConfig(3,3,USART1_IRQn );
}
//���ͺ��� ���ֽ�
void usart1Putchar(u8 ch)
{

	//ͨ��״̬λ��Ҫ���ǰһ���Ƿ������
	while(!(USART1->SR & (1<<6)));
	//�������͵����ݷ��봮�����ݼĴ���
	USART1->DR = ch;

}

void usart1PutStr (u8 *str)
{
	u8 *temp = str;
	while(*temp != 0 )
	{
		usart1Putchar (*temp);
		temp++;
	}
}
//���ܺ��� ���ֽ�
u8 usart1Getstr(void)
{
	 while(!(USART1->SR & 1<<5));
	 return USART1->DR;
}
//���ڽ����жϴ�����
void USART1_IRQHandler ()
{
	//�ж��Ƿ� �ǽ���������ǿ��������ж�
	if(USART1->SR & 1<<5)//���Ĵ����ǿ�
	{
		printf("From Computer:%c\n",usart1Getstr());
	}
}


