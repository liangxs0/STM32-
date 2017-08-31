/*
***USART1 串口 串口1 USART1 GPIOA9 TXD GPIOA10 RXD
*/
#include "USART1.h" 
//比特率的设置和寄存器的部分设置
void USART1_Init (u32 bount)
{
	//波特率的准备设置
	double temp = 72000000.0/(16.0 * bount);
	u16 Mantissa = (u16)temp;
	u16 fraction = temp - Mantissa;
	Mantissa = ((Mantissa<<4) + fraction);//在寄存器BRR中前12位为整数，后4位为小数位
	//IO的使能和初始化 模式配置
	RCC->APB2ENR |= 1<<2 | 1<<14;
	//a9->复用推挽输出模式
	GPIOA->CRH &= ~0x000000F0;
	GPIOA->CRH |= 0xB<<4;
	//a10输入模式上拉模式
	GPIOA->CRH &= ~0x00000F00;
	GPIOA->CRH |= 0x08<<8;
	GPIOA->ODR |= 1<<10;
	//USART1 的寄存器配置
	USART1->BRR = Mantissa;
	USART1->CR1 |= 1<<13| 1<<3| 1<<2; 
	
}


void USART1_Char(u8 ch)
{
	//通过状态位需要检测前一次是否发送完成
	while(!(USART1->SR & (1<<6)));
	//将待发送的数据放入串口数据寄存器
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



