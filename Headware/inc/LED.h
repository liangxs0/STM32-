//LED�� P-C 0 1 2

#ifndef _LED_H_
#define _LWD_H_
#include <stm32f10x.h>

//�Ƶ���ɫ
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

//��ʼ��LED��
void LED_Init(void);
//����LED��
void Set_Led(u8 LED);
//Ϩ��LED��
void Reset_Led(u8 LED);
//������ˮ
void Blink(void);

#endif

