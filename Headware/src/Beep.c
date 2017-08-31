/*
******蜂鸣器 GPIOG14 高电平有效
*/
#include "Beep.h"
//初始化GPIOG，使能对应得时钟
void Beep_Init ()
{
	//使能时钟并且设置IO口模式为推挽输出50MHz
	RCC->APB2ENR |= (1<<8);
	
	GPIOG->CRH &= ~(0xF<<24);
	GPIOG->CRH |= 0x3<<24;
}
//蜂鸣器S停 W响
void SetBeep(char Beep)
{
	GPIOG->ODR = Beep;
}

