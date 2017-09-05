//中断
#include "briuoNVIC.h"
static volatile u8 NVIC_group;
//NVIC初始化 注意，该函数只能执行一次
void briupNVICGroupInit(u8 group)
{

	//SCB->AIRCR
	//System Control Block 系统控制块
	u32 temp;
	NVIC_group = group;
	//通过STM32组号获取CM3内核中的分组号
	group = ~group & 0x07;
	
	temp = SCB->AIRCR;
	temp &= 0x0000F8FF;
	temp |= group<<8;
	temp |= 0x05FA0000;
	SCB->AIRCR = temp;
	
}
//NVIC优先级设置
void briupNVICPriorityConfig (u8 preempttionPriority,u8 subPriority,u8 channel)
{
	//NVIC->IP 寄存器组
	//根据中断分组指定4位有效位的抢占优先级位数和。。
	u8 temp;
	//指定有效位的临时变量
	u8 tempptr,tempsub;
	tempptr = 0x04 - NVIC_group;//
	tempsub = 0x0F >> NVIC_group;
	
	temp = preempttionPriority <<tempptr ;
	temp |= subPriority & tempsub;
	temp<<=4;
	NVIC -> IP[channel] = temp;
	NVIC -> ISER[channel>>0x05] |= 1 << (channel & 0x1F); 
}
//GPIO外部中断引脚配置
//                      端口     位     边沿
void briupExNVICInit(u8 GPIOx, u8 Bitx,u8 TRIM)
{
	//计算AFIO->EXTICR寄存器组的位置
	u8 exAddr,exOffset;
	exAddr = Bitx/4;
	exOffset = (Bitx%4)*4;
	//开启AFIO时钟
	RCC->APB2ENR |= 0x01;
	//将传入的IO引脚映射到对应的EXTI线上
	AFIO->EXTICR[exAddr] |= GPIOx<<exOffset;
	//开放IO引脚对应外部中断线上的中断屏蔽
	EXTI->IMR |= 1<<Bitx;
	EXTI->EMR |= 1<<Bitx;

	if(TRIM & 0x01)
		EXTI->RTSR |= 1<<Bitx;
	if(TRIM & 0x02)
		EXTI->FTSR |= 1<<Bitx;
	

}



