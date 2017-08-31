//五向按键GPIOG 6S 7D 9L 11U  GPIOC 4R
#ifndef _KEY_H_
#define _KEY_H_
#include <stm32f10x.h>
#include "Delay.h"
//GPIOG
#define KEY_S (1<<6)
#define KEY_D (1<<7)
#define KEY_L (1<<9)
#define KEY_U (1<<11)
//GPIOC
#define KEY_R (1<<4)

////GPIOG
#define KEY_S_V  'S'
#define KEY_D_V  'D'
#define KEY_L_V  'L'
#define KEY_U_V  'U'
//GPIOC
#define KEY_R_V  'R'
//初始化按键 IO口时钟使能 设置IO口的模式为输入模式，默认拉高有效
void Key_Init(void);
//按键操作
char SetKey(void);

#endif
