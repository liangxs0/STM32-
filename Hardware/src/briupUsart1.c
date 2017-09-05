/***
*FileName: briupUsart.c
*GreatteDate: 2017 8 25
*Author: Lamos
*Description: 串口
*Update
*/

/*briupUsart1Init ( u32 bound)
	bount 设置串口波特率
*/

#include "briupUsart.h"
#include "briuoNVIC.h"

//用于开启或者关闭printf输出重定向功能
#if 1
//使用半主机模式
#pragma import( __use_no_semihosting)

struct __FILE{
		int handle;
};

FILE __stdout;

_sys_exit(int x)
{
	x =  x;
}
//输出重定向操作
//ch 要发送的字符
//FILE * f stdout 标准输出流
int fputc(int ch,FILE * f)
{
	while(!(USART1->SR & 1<<6));
	USART1->DR = ch;
	return ch;
}

#endif
void briupUsart1Init(u32 bount)
{
	//波特率值的设置 
	
	double temp = 72000000.0/(16.0*bount);
	u16 Mantissa = (u16)temp;
	u16 fraction = (temp - Mantissa);
	Mantissa = (Mantissa<<4)+fraction;
	//寄存器配置部分
	//GPIOA 和USART1的时钟开启
	//IO端口的设置
	RCC->APB2ENR |= 1<<2| 1<<14;
	//tx->a9 推挽复用输出
	GPIOA->CRH &= 0xfffff00f;//打开 10 9 
	GPIOA->CRH |= 0x0B<<4;//1011
	//rx->a10 上拉输入
	//GPIOA->CRH &= 0xfffff0ff;
	GPIOA->CRH |= 0x08<<8;
	GPIOA->ODR |= 1<<10;
	//USART1 的寄存器配置
	USART1->BRR = Mantissa;
	USART1->CR1 |= 1<<13| 1<<3| 1<<2; 
	//USART1中断配置
	USART1->CR1 |= 1<<5;//使能接收缓冲区非空中断
	briupNVICPriorityConfig(3,3,USART1_IRQn );
}
//发送函数 按字节
void usart1Putchar(u8 ch)
{

	//通过状态位需要检测前一次是否发送完成
	while(!(USART1->SR & (1<<6)));
	//将待发送的数据放入串口数据寄存器
	USART1->DR = ch;

}

void usart1PutStr (u8 *str)
{
	u8 *temp = str;
	while(*temp != 0 )
	{
		usart1Putchar (*temp);
		temp++;
	}
}
//接受函数 按字节
u8 usart1Getstr(void)
{
	 while(!(USART1->SR & 1<<5));
	 return USART1->DR;
}
//串口接收中断处理函数
void USART1_IRQHandler ()
{
	//判断是否 是接收器缓冲非空引发的中断
	if(USART1->SR & 1<<5)//读寄存器非空
	{
		printf("From Computer:%c\n",usart1Getstr());
	}
}


