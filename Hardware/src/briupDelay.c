/*****延时函数
*
*** us ms s
**
**/
#include "briupDelay.h"

static u32 fac_us,fac_ms;
/*****delay_init（u8 SYSCLK） 
初始化系统时钟的定时器
InPUT SYSCLCK（MHZ）
OutPUT NULL 
*/
void delay_init(u8 SYSCLK)
{
	SysTick->CTRL = 0;
	fac_us = SYSCLK / 8;//1 hz = 1s  72Mhz 72Mhz/8 
	fac_ms = fac_us * 1000;
}
/******us**/
void _delay_us(u32 us)
{
	u32 temp; //检测倒计时是否结束
	SysTick->LOAD = fac_us*us;
	SysTick->VAL = 0;
	SysTick->CTRL |= 0x01;
	do 
	{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&!(temp & (1<<16)));
	SysTick->CTRL &= ~0x01;
}
/*********ms*最大不可超过1864ms*/
void _delay_ms(u32 ms)
{
	u32 temp; //检测倒计时是否结束
	SysTick->LOAD = fac_ms*ms;
	SysTick->VAL = 0;
	SysTick->CTRL |= 0x01;
	do 
	{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&!(temp & (1<<16)));
	SysTick->CTRL &= ~0x01;
}
/** s ***/
void _delay_s_(double s)
{
	u32 ms = (u32) (s*1000);
	do 
	{
		if(ms>1000)
		{
			_delay_ms(1000);
			ms-=1000;
		}
		else
		{
			_delay_ms(ms);
			ms = 0; 
		}
	}while(ms > 0);
}


