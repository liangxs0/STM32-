#ifndef _NVIC_H_
#define _NVIC_H_
#include <stm32f10x.h>
typedef enum {
	GPIO_A,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_F,
	GPIO_G,
	
}GPIO_x;
//NVIC≥ı ºªØ ◊¢“‚£¨∏√∫Ø ˝÷ªƒ‹÷¥––“ª¥Œ
void briupNVICGroupInit(u8 group);
//NVIC”≈œ»º∂…Ë÷√
void briupNVICPriorityConfig (u8 preempttionPriority,u8 subPriority,u8 channel);
//GPIOÕ‚≤ø÷–∂œ“˝Ω≈≈‰÷ √
//                      ∂Àø⁄     Œª     ±ﬂ—ÿ
void briupExNVICInit(u8 GPIOx, u8 Bitx,u8 TRIM);
#endif
