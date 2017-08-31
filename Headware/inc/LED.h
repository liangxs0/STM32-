//LED灯 P-C 0 1 2

#ifndef _LED_H_
#define _LWD_H_
#include <stm32f10x.h>

//灯的颜色
#define LED_R 	(1<<2)
#define LED_G 	(1<<1)
#define LED_B 	(1<<0)
#define	LED_ALL (0x07)

#define LED_Pink (LED_ALL|LED_R)
#define LED_C (LED_G|LED_B)
#define LED_Y (LED_R|LED_G)
#define LED_PO (LED_B|LED_B)
#define LED_O (LED_R|LED_Y)
#define LED_GY (LED_O|LED_Y)

//初始化LED灯
void LED_Init(void);
//点亮LED灯
void Set_Led(u8 LED);
//熄灭LED灯
void Reset_Led(u8 LED);
//花样流水
void Blink(void);

#endif

