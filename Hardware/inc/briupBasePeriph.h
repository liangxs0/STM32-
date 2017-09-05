/***
*FileName: briupBasePeriph.h
*GreatteDate: 2017 8 24
*Author: Lamos
*Description: 用于声明基础外设初始化接口及其相关宏定义，操作接口
*Update
*/

#ifndef _BASEPERIPH_H_




#define _BASEPERIPH_H_

#include <stm32f10x.h>

#define  LED_R	(1<<2)
#define  LED_G  (1<<1)
#define  LED_B	(1<<0)
#define  LED_ALL (0x07)

// 混合颜色
#define  LED_Y	(LED_R|LED_G)
#define  LED_P	(LED_R|LED_B)
#define  LED_C	(LED_B|LED_G)
#define  LED_W	(LED_ALL)
//蜂鸣器
#define Beep (1<<14)

//继电器
#define Relay1 (1<<13)//G
#define Relay2 (1<<3)//C

/*******
*FileName: basePeriphInit(); 
*Description : 初始化外设函数接口
*InPut: NULL
*OutPut : NULL
*/
void basePeriphInit(void);
/*******
*FileName: setLed(U8 LedStat)
*Description : 根据LedStat点亮对应LED
*InPut: 			LedStat  用低三位对应3个LED灯的状态
*OutPut : NULL
*/
void setLed(u8 LedStat);
//根据LedStat熄灭对应的灯
void resetLed(u8 LedStat);	
//蜂鸣器开启 0 关 1开
void setBeep (void);
void resetBeep (void);


//继电器
void setRelay1(void);
void setRelay2(void);
void resetRelay1(void);
void resetRelay2(void);

#endif

