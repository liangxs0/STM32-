//�ж�
#include "briuoNVIC.h"
static volatile u8 NVIC_group;
//NVIC��ʼ�� ע�⣬�ú���ֻ��ִ��һ��
void briupNVICGroupInit(u8 group)
{

	//SCB->AIRCR
	//System Control Block ϵͳ���ƿ�
	u32 temp;
	NVIC_group = group;
	//ͨ��STM32��Ż�ȡCM3�ں��еķ����
	group = ~group & 0x07;
	
	temp = SCB->AIRCR;
	temp &= 0x0000F8FF;
	temp |= group<<8;
	temp |= 0x05FA0000;
	SCB->AIRCR = temp;
	
}
//NVIC���ȼ�����
void briupNVICPriorityConfig (u8 preempttionPriority,u8 subPriority,u8 channel)
{
	//NVIC->IP �Ĵ�����
	//�����жϷ���ָ��4λ��Чλ����ռ���ȼ�λ���͡���
	u8 temp;
	//ָ����Чλ����ʱ����
	u8 tempptr,tempsub;
	tempptr = 0x04 - NVIC_group;//
	tempsub = 0x0F >> NVIC_group;
	
	temp = preempttionPriority <<tempptr ;
	temp |= subPriority & tempsub;
	temp<<=4;
	NVIC -> IP[channel] = temp;
	NVIC -> ISER[channel>>0x05] |= 1 << (channel & 0x1F); 
}
//GPIO�ⲿ�ж���������
//                      �˿�     λ     ����
void briupExNVICInit(u8 GPIOx, u8 Bitx,u8 TRIM)
{
	//����AFIO->EXTICR�Ĵ������λ��
	u8 exAddr,exOffset;
	exAddr = Bitx/4;
	exOffset = (Bitx%4)*4;
	//����AFIOʱ��
	RCC->APB2ENR |= 0x01;
	//�������IO����ӳ�䵽��Ӧ��EXTI����
	AFIO->EXTICR[exAddr] |= GPIOx<<exOffset;
	//����IO���Ŷ�Ӧ�ⲿ�ж����ϵ��ж�����
	EXTI->IMR |= 1<<Bitx;
	EXTI->EMR |= 1<<Bitx;

	if(TRIM & 0x01)
		EXTI->RTSR |= 1<<Bitx;
	if(TRIM & 0x02)
		EXTI->FTSR |= 1<<Bitx;
	

}



