//������ GPIOG14 �ߵ�ƽ��Ч
#ifndef _BEEP_H_
#define _BEEP_H_
#include <stm32f10x.h>

#define S (0<<14)
#define W (1<<14)
//��ʼ��GPIOG��ʹ�ܶ�Ӧ��ʱ��
void Beep_Init (void);
//������Sͣ W��
void SetBeep(char Beep);

#endif
