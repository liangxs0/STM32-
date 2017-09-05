/***
*FileName: briupKeyboard.c
*GreatteDate: 2017 8 25
*Author: Lamos
*Description: 用实现基础外设初始化接口及其相关宏定义，操作接口的值
*Update
*/
#include "briupKeyboard.h"
#include "briuoNVIC.h"
#include "briupBasePeriph.h"
#include "briupDelay.h"
#include "briupTIM2.h"
extern u16 beepFreq[7];
//按键初始化
void briupKeyInit(void)
{
	RCC->APB2ENR |= 1<<4 | 1<<8;
	//G 6 7 9 11   C 4
	GPIOG->CRL &= 0x00ffffff;
	GPIOC->CRH &= 0xffff0f0f;
	
	GPIOG->CRL |= 0x88000000;
	GPIOG->CRH |= 0x00008080;
	GPIOG->ODR |= 1<<6 | 1<<7 | 1<<9 |1<<11;
	
	GPIOC->CRL &= ~(0xf<<16);
	GPIOC->CRL |= 0x08<<16;
	GPIOC->ODR |= 1<<4;
	
	
	//调用GPIO映射接口确定对应引脚和外部中断映射
	briupExNVICInit(GPIO_G,6,0x02);
	//DOW
	briupExNVICInit(GPIO_G,7,0x02);
	//LEF
	briupExNVICInit(GPIO_G,9,0x02);
	//设置外部中断线6的优级和中断源
	briupNVICPriorityConfig(3,1,EXTI9_5_IRQn);
	
	//up按键
	briupExNVICInit(GPIO_G,11,0x02);
	
	briupNVICPriorityConfig(3,1,EXTI15_10_IRQn);
	
	//right
	briupExNVICInit(GPIO_C,4,0x02);
	briupNVICPriorityConfig(3,1,EXTI4_IRQn);
	
}
//检测按键，并返回按键键值
KEY_VALUE getKeyValue (void)
{

		KEY_VALUE key = KEY_NONE;
		if(!(GPIOG->IDR & KEY_SEL))
				key |= KEY_SEL;
		if(!(GPIOG->IDR & KEY_UP))
				key |= KEY_UP;
		if(!(GPIOG->IDR & KEY_DOW))
				key |= KEY_DOW;
		if(!(GPIOG->IDR & KEY_LEF))
				key |= KEY_SEL;
		if(!(GPIOC->IDR & KEY_RGT))
				key |= KEY_RGT;
			
		return key;

}

//select 中断服务函数
void EXTI9_5_IRQHandler()
{
	//端口引脚输入寄存器判断
	if(!(GPIOG->IDR & KEY_SEL))
	{
//		briupTIM2Start(beepFreq[6]);
//		while(!(GPIOG->IDR & (1<<6)));
//		briupTIM2Stop();
//		resetBeep();
////		//挂起外部中断
//		EXTI->PR |= 1<<6;
		}
		if(!(GPIOG->IDR & KEY_DOW))
		{
		//挂起外部中断
		EXTI->PR |= 1<<7;
		}		
	if(!(GPIOG->IDR & KEY_LEF))
		{
		//挂起外部中断
		EXTI->PR |= 1<<9;
		}	
	
	
}
void EXTI15_10_IRQHandler()
{
	if(!(GPIOG->IDR & KEY_UP))
		{
		//挂起外部中断
		EXTI->PR |= 1<<11;
		}	
}
void EXTI4_IRQHandler()
{
		if(!(GPIOC->IDR & KEY_RGT))
		{
			//挂起外部中断
		EXTI->PR |= 1<<4;
		}
}
