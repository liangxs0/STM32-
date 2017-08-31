/*

******LED灯 P-C 0 1 2
*/
#include "LED.h"
#include "Delay.h"
//初始化LED灯
void LED_Init()
{

	//打开对应IO口的的时钟使能
	RCC->APB2ENR |= (1<<4);
	//设置GPIOC 0 1 2 为推挽输出 50MHz
	GPIOC->CRL &= ~(0xFFF);//选择0 1 2 IO口
	GPIOC->CRL |= 0x333;///模式的设置  0011 0011 0011
	Reset_Led(LED_ALL);
}
//点亮LED灯
void Set_Led(u8 LED)
{
		GPIOC->ODR &= ~LED;
}
//熄灭LED灯
void Reset_Led(u8 LED)
{
		GPIOC->ODR |= LED;
}
void Blink(void)
{
	u16 i=0;
	u16 j=0;
	for(i = 0;i<200; i++)
	{
		for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_B);
					delay_us(j);
					Reset_Led(LED_B);
					delay_us(1001-j);
			}
			delay_ms_(500);
		for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_Y);
					delay_us(j);
					Reset_Led(LED_Y);
					delay_us(1001-j);
			}
			delay_ms_(500);
			for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_C);
					delay_us(j);
					Reset_Led(LED_C);
					delay_us(1001-j);
			}
			delay_ms_(500);
			for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_R);
					delay_us(j);
					Reset_Led(LED_R);
					delay_us(1001-j);
			}
			delay_ms_(500);
			for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_G);
					delay_us(j);
					Reset_Led(LED_G);
					delay_us(1001-j);
			}
			delay_ms_(500);
			
		}


}
