//¶¨Ê±Æ÷2
#ifndef _TIM2_H_
#define _TIM2_H_
#include <stm32f10x.h>
#include "briupUSART.h"
#include "briupBasePeriph.h"
#include "briupDelay.h"
#include "briuoNVIC.h"

//½Ó¿Ú³õÊ¼»
//´«ÈëºÍ²ÎÊý Ô¤·ÖÆµÏµÊý
void briupTIM2Init(u16 psc);

//¿ªÆô¶¨Ê±Æ÷²Ù×÷
void briupTIM2Start(u16 arr);

//¹Ø±Õ¶¨Ê±Æ÷
void briupTIM2Stop(void);

#endif

