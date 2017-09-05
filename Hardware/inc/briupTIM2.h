//定时器2
#ifndef _TIM2_H_
#define _TIM2_H_
#include <stm32f10x.h>
#include "briupUSART.h"
#include "briupBasePeriph.h"
#include "briupDelay.h"
#include "briuoNVIC.h"

//接口初始�
//传入和参数 预分频系数
void briupTIM2Init(u16 psc);

//开启定时器操作
void briupTIM2Start(u16 arr);

//关闭定时器
void briupTIM2Stop(void);

#endif

