//�̵��� pG13 relay1    pc3 relay2 �ߵ�ƽ��Ч
#ifndef _RELAY_H_
#define _RELAY_H_
#include <stm32f10x.h>

#define Relay1 1<<14
#define Relay2 1<<3;

//��ʼ��G C��ʱ�Ӻ����ö�Ӧ��IO��������� 50MHz
void Relay_Init (void);
//�̵����Ĺ������� 1 2 
void Set_Relay(u8 Relay);
void Reset_Relay(u8 Relay);

#endif


