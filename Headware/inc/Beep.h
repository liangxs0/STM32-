//蜂鸣器 GPIOG14 高电平有效
#ifndef _BEEP_H_
#define _BEEP_H_
#include <stm32f10x.h>

#define S (0<<14)
#define W (1<<14)
//初始化GPIOG，使能对应得时钟
void Beep_Init (void);
//蜂鸣器S停 W响
void SetBeep(char Beep);

#endif
