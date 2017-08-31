//继电器 pG13 relay1    pc3 relay2 高电平有效
#ifndef _RELAY_H_
#define _RELAY_H_
#include <stm32f10x.h>

#define Relay1 1<<14
#define Relay2 1<<3;

//初始化G C的时钟和设置对应得IO的推挽输出 50MHz
void Relay_Init (void);
//继电器的工作设置 1 2 
void Set_Relay(u8 Relay);
void Reset_Relay(u8 Relay);

#endif


