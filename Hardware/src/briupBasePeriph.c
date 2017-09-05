/***
*FileName: briupBasePeriph.h
*GreatteDate: 2017 8 24
*Author: Lamos
*Description: 对基础外设的实现文件
*Update
*/

#include "briupBasePeriph.h"

/*******
*FileName: basePeriphInit(); 
*Description : 初始化外设函数接口
*InPut: NULL
*OutPut : NULL
*/
void basePeriphInit(void)
{
	//开启GPIOC的时钟
	RCC->APB2ENR |= 1<<4;
	//开启GPIOG
	RCC->APB2ENR |= 1<<8;
	//设置GPIOC P0 1 2 3引脚为推挽50Mhz输出
	GPIOC->CRL &= ~0xFFFF;
	GPIOC->CRL |= 0x3333;
	resetLed(LED_ALL);
	//设置GPIOG P14  13为推挽50MHz输出
	GPIOG->CRH &= 0xF00FFFFF;
	GPIOG->CRH |= 0x03300000;
	//GPIOG->CRH |= 0x3<<24;
	
	GPIOG->CRH &= 0<<20;
	GPIOG->CRH |= 0x03300000;
	//GPIOG->CRH |= 0x3<<20;
	//resetBeep();
}
/*******
*FileName: setLed(U8 LedStat)
*Description : 根据LedStat点亮对应LED
*InPut: 			LedStat  用低三位对应3个LED灯的状态
*OutPut : NULL
*/

void setLed(u8 LedStat)
{
	//使GPIOC pin  0 1 2
	GPIOC->ODR &= ~LedStat;
}
//根据LedStat熄灭对应的灯
void resetLed(u8 LedStat)
{
	GPIOC->ODR |= LedStat;
}

//开启蜂鸣器
void setBeep()
{

	GPIOG->ODR |= Beep;
	
}
void resetBeep()
{

	GPIOG->ODR &= ~Beep;
}
//继电器2
void setRelay2()
{
	GPIOC->ODR |= Relay2;
}
void resetRelay2()
{
	GPIOC->ODR &= ~Relay2;
}
//继电器1
void setRelay1()
{
	GPIOG->ODR |= Relay1;
	
}
void resetRelay1()
{
	GPIOG->ODR &= ~Relay1;
}

