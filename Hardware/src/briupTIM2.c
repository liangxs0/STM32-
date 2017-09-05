//TIM2 ʵ���ļ�
#include "briupTIM2.h"

//�ӿڳ�ʼ��
//����Ͳ��� Ԥ��Ƶϵ��
void briupTIM2Init(u16 psc)
{
	RCC->APB1ENR |= 0x01;
	TIM2->PSC = psc-1;
	//�������¼���
	TIM2->CR1 |= 1<<4;
	//ʹ�ܶ�ʱ�������ж�
	TIM2->DIER |= 0x01;
	//ע�ᶨʱ��2�ж�����
	briupNVICPriorityConfig(2,1,TIM2_IRQn);
}

//������ʱ������
void briupTIM2Start(u16 arr)
{
	TIM2->ARR = arr;
	TIM2->CR1 |= 0x01;
}

//�رն�ʱ��
void briupTIM2Stop()
{
		TIM2->CR1 &= ~0x01;
}

//�жϷ�����
static volatile u8 BeepFlag;
void TIM2_IRQHandler()
{

		if(BeepFlag)
		{
			setBeep();
			BeepFlag = 0;
			
		}
		else
		{
			resetBeep();
			BeepFlag = 1;
		}
		//����ʱ��2�ĸ����ж�
		TIM2->SR &= ~0x01;
}
