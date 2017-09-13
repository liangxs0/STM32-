//独立看门狗，当检测到硬件异常时复位CPU
//分频数0~7  自动重装载值0~0XFFF
//分频因子 = 4*2^prer  Time_OUt = ((4*2^prer)*rlr)/32(ms)

#include "IWDG.h"
//初始化
void IWDG_Init(u8 prer,u16 rlr)
{

	IWDG->KR = 0X5555;//使能对PR和RLR的写
	IWDG->PR = prer;//分频系数
	IWDG->RLR = rlr;//重加载寄存器 低11位有效
	IWDG->KR = 0XAAAA;//重装载
	IWDG->KR = 0XCCCC;//使能看门狗

}
//喂狗操作
void Feed_Dog()
{


	IWDG->KR = 0XAAAA;//喂狗给值
	
}
