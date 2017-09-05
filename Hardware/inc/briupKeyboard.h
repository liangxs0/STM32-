/***
*FileName: briupKeyboard.h
*GreatteDate: 2017 8 22
*Author: Lamos
*Description: �����������������ʼ���ӿڼ�����غ궨�壬�����ӿ �����
*Update
*/
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <stm32f10x.h>
//ö�����Ͷ���
typedef enum{
							KEY_NONE = 0,
							KEY_SEL = 1<<6,
							KEY_RGT = 1<<4,
							KEY_DOW = 1<<7,
							KEY_LEF = 1<<9,
							KEY_UP = 1<<11
							
}KEY_VALUE;
/*******���򰴼���ʼ��*/
void briupKeyInit(void);
//��ⰴ���������ذ�����ֵ
KEY_VALUE getKeyValue(void);
#endif
