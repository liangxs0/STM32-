/***
*FileName: briupBasePeriph.h
*GreatteDate: 2017 8 24
*Author: Lamos
*Description: �Ի��������ʵ���ļ�
*Update
*/

#include "briupBasePeriph.h"

/*******
*FileName: basePeriphInit(); 
*Description : ��ʼ�����躯���ӿ�
*InPut: NULL
*OutPut : NULL
*/
void basePeriphInit(void)
{
	//����GPIOC��ʱ��
	RCC->APB2ENR |= 1<<4;
	//����GPIOG
	RCC->APB2ENR |= 1<<8;
	//����GPIOC P0 1 2 3����Ϊ����50Mhz���
	GPIOC->CRL &= ~0xFFFF;
	GPIOC->CRL |= 0x3333;
	resetLed(LED_ALL);
	//����GPIOG P14  13Ϊ����50MHz���
	GPIOG->CRH &= 0xF00FFFFF;
	GPIOG->CRH |= 0x03300000;
	//GPIOG->CRH |= 0x3<<24;
	
	GPIOG->CRH &= 0<<20;
	GPIOG->CRH |= 0x03300000;
	//GPIOG->CRH |= 0x3<<20;
	//resetBeep();
}
/*******
*FileName: setLed(U8 LedStat)
*Description : ����LedStat������ӦLED
*InPut: 			LedStat  �õ���λ��Ӧ3��LED�Ƶ�״̬
*OutPut : NULL
*/

void setLed(u8 LedStat)
{
	//ʹGPIOC pin  0 1 2
	GPIOC->ODR &= ~LedStat;
}
//����LedStatϨ���Ӧ�ĵ�
void resetLed(u8 LedStat)
{
	GPIOC->ODR |= LedStat;
}

//����������
void setBeep()
{

	GPIOG->ODR |= Beep;
	
}
void resetBeep()
{

	GPIOG->ODR &= ~Beep;
}
//�̵���2
void setRelay2()
{
	GPIOC->ODR |= Relay2;
}
void resetRelay2()
{
	GPIOC->ODR &= ~Relay2;
}
//�̵���1
void setRelay1()
{
	GPIOG->ODR |= Relay1;
	
}
void resetRelay1()
{
	GPIOG->ODR &= ~Relay1;
}

