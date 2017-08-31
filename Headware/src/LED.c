/*

******LED�� P-C 0 1 2
*/
#include "LED.h"
#include "Delay.h"
//��ʼ��LED��
void LED_Init()
{

	//�򿪶�ӦIO�ڵĵ�ʱ��ʹ��
	RCC->APB2ENR |= (1<<4);
	//����GPIOC 0 1 2 Ϊ������� 50MHz
	GPIOC->CRL &= ~(0xFFF);//ѡ��0 1 2 IO��
	GPIOC->CRL |= 0x333;///ģʽ������  0011 0011 0011
	Reset_Led(LED_ALL);
}
//����LED��
void Set_Led(u8 LED)
{
		GPIOC->ODR &= ~LED;
}
//Ϩ��LED��
void Reset_Led(u8 LED)
{
		GPIOC->ODR |= LED;
}
void Blink(void)
{
	u16 i=0;
	u16 j=0;
	for(i = 0;i<200; i++)
	{
		for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_B);
					delay_us(j);
					Reset_Led(LED_B);
					delay_us(1001-j);
			}
			delay_ms_(500);
		for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_Y);
					delay_us(j);
					Reset_Led(LED_Y);
					delay_us(1001-j);
			}
			delay_ms_(500);
			for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_C);
					delay_us(j);
					Reset_Led(LED_C);
					delay_us(1001-j);
			}
			delay_ms_(500);
			for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_R);
					delay_us(j);
					Reset_Led(LED_R);
					delay_us(1001-j);
			}
			delay_ms_(500);
			for(j=1; j<1000 ; j++)
			{
					Set_Led(LED_G);
					delay_us(j);
					Reset_Led(LED_G);
					delay_us(1001-j);
			}
			delay_ms_(500);
			
		}


}
