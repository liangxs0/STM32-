/*
***USART1 ���� ����1 USART1 GPIOA9 TXD GPIOA10 RXD
*/
#include "USART1.h" 
//�����ʵ����úͼĴ����Ĳ�������
void USART1_Init (u32 bount)
{
	//�����ʵ�׼������
	double temp = 72000000.0/(16.0 * bount);
	u16 Mantissa = (u16)temp;
	u16 fraction = temp - Mantissa;
	Mantissa = ((Mantissa<<4) + fraction);//�ڼĴ���BRR��ǰ12λΪ��������4λΪС��λ
	//IO��ʹ�ܺͳ�ʼ�� ģʽ����
	RCC->APB2ENR |= 1<<2 | 1<<14;
	//a9->�����������ģʽ
	GPIOA->CRH &= ~0x000000F0;
	GPIOA->CRH |= 0xB<<4;
	//a10����ģʽ����ģʽ
	GPIOA->CRH &= ~0x00000F00;
	GPIOA->CRH |= 0x08<<8;
	GPIOA->ODR |= 1<<10;
	//USART1 �ļĴ�������
	USART1->BRR = Mantissa;
	USART1->CR1 |= 1<<13| 1<<3| 1<<2; 
	
}


void USART1_Char(u8 ch)
{
	//ͨ��״̬λ��Ҫ���ǰһ���Ƿ������
	while(!(USART1->SR & (1<<6)));
	//�������͵����ݷ��봮�����ݼĴ���
	USART1->DR = ch;

}

void UASET1_Str(u8* str)
{
u8 *temp = str;
	while(*temp != 0 )
	{
		USART1_Char (*temp);
		temp++;
	}

}

u8 Getdat(void)
{

	while(!(USART1->SR & 1<<5));
	return USART1->DR;
	
}



