/***
*FileName: briupKeyboard.h
*GreatteDate: 2017 8 22
*Author: Lamos
*Description: ÓÃÓÚÉùÃ÷»ù´¡ÍâÉè³õÊ¼»¯½Ó¿Ú¼°ÆäÏà¹Øºê¶¨Òå£¬²Ù×÷½Ó¿ °´¼üÚ
*Update
*/
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <stm32f10x.h>
//Ã¶¾ÙÀàĞÍ¶¨Òå
typedef enum{
							KEY_NONE = 0,
							KEY_SEL = 1<<6,
							KEY_RGT = 1<<4,
							KEY_DOW = 1<<7,
							KEY_LEF = 1<<9,
							KEY_UP = 1<<11
							
}KEY_VALUE;
/*******ÎåÏò°´¼ü³õÊ¼»¯*/
void briupKeyInit(void);
//¼ì²â°´¼ü£¬²¢·µ»Ø°´¼ü¼üÖµ
KEY_VALUE getKeyValue(void);
#endif
