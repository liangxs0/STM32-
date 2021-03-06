/***
*FileName: briupKeyboard.h
*GreatteDate: 2017 8 22
*Author: Lamos
*Description: 用于声明基础外设初始化接口及其相关宏定义，操作接� 按键�
*Update
*/
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <stm32f10x.h>
//枚举类型定义
typedef enum{
							KEY_NONE = 0,
							KEY_SEL = 1<<6,
							KEY_RGT = 1<<4,
							KEY_DOW = 1<<7,
							KEY_LEF = 1<<9,
							KEY_UP = 1<<11
							
}KEY_VALUE;
/*******五向按键初始化*/
void briupKeyInit(void);
//检测按键，并返回按键键值
KEY_VALUE getKeyValue(void);
#endif
