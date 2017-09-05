/***
*FileName: briupKeyboard.c
*GreatteDate: 2017 8 25
*Author: Lamos
*Description: ��ʵ�ֻ��������ʼ���ӿڼ�����غ궨�壬�����ӿڵ�ֵ
*Update
*/
#include "briupKeyboard.h"
#include "briuoNVIC.h"
#include "briupBasePeriph.h"
#include "briupDelay.h"
#include "briupTIM2.h"
extern u16 beepFreq[7];
//������ʼ��
void briupKeyInit(void)
{
	RCC->APB2ENR |= 1<<4 | 1<<8;
	//G 6 7 9 11   C 4
	GPIOG->CRL &= 0x00ffffff;
	GPIOC->CRH &= 0xffff0f0f;
	
	GPIOG->CRL |= 0x88000000;
	GPIOG->CRH |= 0x00008080;
	GPIOG->ODR |= 1<<6 | 1<<7 | 1<<9 |1<<11;
	
	GPIOC->CRL &= ~(0xf<<16);
	GPIOC->CRL |= 0x08<<16;
	GPIOC->ODR |= 1<<4;
	
	
	//����GPIOӳ��ӿ�ȷ����Ӧ���ź��ⲿ�ж�ӳ��
	briupExNVICInit(GPIO_G,6,0x02);
	//DOW
	briupExNVICInit(GPIO_G,7,0x02);
	//LEF
	briupExNVICInit(GPIO_G,9,0x02);
	//�����ⲿ�ж���6���ż����ж�Դ
	briupNVICPriorityConfig(3,1,EXTI9_5_IRQn);
	
	//up����
	briupExNVICInit(GPIO_G,11,0x02);
	
	briupNVICPriorityConfig(3,1,EXTI15_10_IRQn);
	
	//right
	briupExNVICInit(GPIO_C,4,0x02);
	briupNVICPriorityConfig(3,1,EXTI4_IRQn);
	
}
//��ⰴ���������ذ�����ֵ
KEY_VALUE getKeyValue (void)
{

		KEY_VALUE key = KEY_NONE;
		if(!(GPIOG->IDR & KEY_SEL))
				key |= KEY_SEL;
		if(!(GPIOG->IDR & KEY_UP))
				key |= KEY_UP;
		if(!(GPIOG->IDR & KEY_DOW))
				key |= KEY_DOW;
		if(!(GPIOG->IDR & KEY_LEF))
				key |= KEY_SEL;
		if(!(GPIOC->IDR & KEY_RGT))
				key |= KEY_RGT;
			
		return key;

}

//select �жϷ�����
void EXTI9_5_IRQHandler()
{
	//�˿���������Ĵ����ж�
	if(!(GPIOG->IDR & KEY_SEL))
	{
//		briupTIM2Start(beepFreq[6]);
//		while(!(GPIOG->IDR & (1<<6)));
//		briupTIM2Stop();
//		resetBeep();
////		//�����ⲿ�ж�
//		EXTI->PR |= 1<<6;
		}
		if(!(GPIOG->IDR & KEY_DOW))
		{
		//�����ⲿ�ж�
		EXTI->PR |= 1<<7;
		}		
	if(!(GPIOG->IDR & KEY_LEF))
		{
		//�����ⲿ�ж�
		EXTI->PR |= 1<<9;
		}	
	
	
}
void EXTI15_10_IRQHandler()
{
	if(!(GPIOG->IDR & KEY_UP))
		{
		//�����ⲿ�ж�
		EXTI->PR |= 1<<11;
		}	
}
void EXTI4_IRQHandler()
{
		if(!(GPIOC->IDR & KEY_RGT))
		{
			//�����ⲿ�ж�
		EXTI->PR |= 1<<4;
		}
}
