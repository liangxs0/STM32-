/**
*****继电器 pG13 relay1    pc3 relay2 高电平有效
*/
#include "Relay.h"
//初始化G C的时钟和设置对应得IO的推挽输出 50MHz
void Relay_Init ()
{
	//使能对应得时钟
	RCC->APB2ENR |= 1<<4 | 1<<8;
	//设置IO口
	GPIOC->CRL &= ~(0xF<<6);
	GPIOC->CRL |= 0x3<<6;
	
	GPIOG->CRH &= ~(0xF<<20);
	GPIOG->CRH |= 0x3<<20;
}
//继电器的工作设置 1 2 输入继电器的编号
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
	
	