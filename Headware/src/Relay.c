/**
*****�̵��� pG13 relay1    pc3 relay2 �ߵ�ƽ��Ч
*/
#include "Relay.h"
//��ʼ��G C��ʱ�Ӻ����ö�Ӧ��IO��������� 50MHz
void Relay_Init ()
{
	//ʹ�ܶ�Ӧ��ʱ��
	RCC->APB2ENR |= 1<<4 | 1<<8;
	//����IO��
	GPIOC->CRL &= ~(0xF<<6);
	GPIOC->CRL |= 0x3<<6;
	
	GPIOG->CRH &= ~(0xF<<20);
	GPIOG->CRH |= 0x3<<20;
}
//�̵����Ĺ������� 1 2 ����̵����ı��
void Set_Relay(u8 Relay)
{
	if(Relay == 1)
	{
		GPIOG->ODR |= Relay1;
	}
	if(Relay == 2 )
	{
		GPIOC->ODR |= Relay2;
	}
}
void Reset_Relay(u8 Relay)
{
	if(Relay == 1)
	{
		GPIOG->ODR |= ~Relay1;
	}
	if(Relay == 2 )
	{
		GPIOC->ODR |= ~Relay2;
	}
}
	
	