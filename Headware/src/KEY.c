/*
****五向按键GPIOG 6S 7D 9L 11U  GPIOC 4R
*/
//初始化按键 IO口时钟使能 设置IO口的模式为输入模式，默认拉高有效
#include "KEY.h"
void Key_Init()
{
	//打开C G的时钟
	RCC->APB2ENR |= (1<<4)|(1<<8);
	//设置IO口的模式为输入模式 
	GPIOG->CRL &= 0xFFFFFFFF;
	GPIOG->CRH &= 0xFFFFFFFF;
	GPIOG->CRL |= 0x8800000000;
	GPIOG->CRH |= 0x00008080;
	GPIOG->ODR |= 1<<6 | 1<<7 | 1<<9 | 1<<11;
	
	GPIOC->CRL &= 0xF<<8;
	GPIOC->CRL |= 0x8<<8;
	GPIOC->ODR |= 1<<4;
}
//按键操作
char SetKey ()
{
		if (!(GPIOG->IDR & KEY_S))//~(1&0)=1  
			{
					return KEY_S_V ;
			}
		else if (!(GPIOG->IDR & KEY_R))
			{
					return KEY_R_V ;
			}
		else if (!(GPIOG->IDR & KEY_L))
			{
					return KEY_L_V ;
			}
		else if (!(GPIOG->IDR & KEY_U))
			{
					return KEY_U_V ;
			}
		else if (!(GPIOG->IDR & KEY_D))
			{
					return KEY_D_V ;
			}
}

