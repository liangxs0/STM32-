/*
******������ GPIOG14 �ߵ�ƽ��Ч
*/
#include "Beep.h"
//��ʼ��GPIOG��ʹ�ܶ�Ӧ��ʱ��
void Beep_Init ()
{
	//ʹ��ʱ�Ӳ�������IO��ģʽΪ�������50MHz
	RCC->APB2ENR |= (1<<8);
	
	GPIOG->CRH &= ~(0xF<<24);
	GPIOG->CRH |= 0x3<<24;
}
//������Sͣ W��
void SetBeep(char Beep)
{
	GPIOG->ODR = Beep;
}

