/*****延时函数
*
*** us ms s
**
**/
#ifndef _DELAY_H_
#define _DELAY_H_

#include <stm32f10x.h>

/*****delay_init（u8 SYSCLK） 
初始化系统时钟的定时器
InPUT SYSCLCK（MHZ）
OutPUT NULL 
*/
void delay_init(u8 SYSCLCK);
/******us**/
void _delay_us(u32 us);
/*********ms*/
void _delay_ms(u32 ms);
/** s ** */
void _delay_s_(double s);

#endif
 

