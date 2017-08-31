/*****��ʱ����
*
*** us ms s
**	SysTick->CTRL, ���ƺ�״̬̫�Ĵ���       	

    SysTick->LOAD,  ��װ�ؼĴ���

    SysTick->VAL,    ��ǰֵ�Ĵ���

		SysTick->CALIB,  У׼ֵ�Ĵ���    
**/
#include "Delay.h"
/*****delay_init��u8 SYSCLK�� 
��ʼ��ϵͳʱ�ӵĶ�ʱ��
InPUT SYSCLCK��MHZ��
OutPUT NULL 
*/
static u32 fac_ms ,fac_us;
void delay_init(u8 SYSCLCK)
{
	SysTick->CTRL = 0;
	fac_us = SYSCLCK / 8;// 79M/8
	fac_ms = fac_us * 1000;
}
/******us**/
void delay_us(u32 us)
{
	u32 temp;
	SysTick->LOAD = fac_us * us;
	SysTick->VAL = 0;
	SysTick->CTRL |= 0x01;
		{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&!(temp & (1<<16)));
	SysTick->CTRL &= ~0x01;
}
/*********ms*/
void delay_ms_(u32 ms)
{
	u32 temp; //��⵹��ʱ�Ƿ����
	SysTick->LOAD = fac_ms*ms;
	SysTick->VAL = 0;
	SysTick->CTRL |= 0x01;
	do 
	{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&!(temp & (1<<16)));
		SysTick->CTRL &= ~0x01;
}
/** s ** */
void delay_s_(double s)
{
u32 ms = (u32) (s*1000);
	do 
	{
		if(ms>1000)
		{
			delay_ms_(1000);
			ms-=1000;
		}
		else
		{
			delay_ms_(ms);
			ms = 0; 
		}
	}while(ms > 0);
}

