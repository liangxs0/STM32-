//��ʱ��2
#ifndef _TIM2_H_
#define _TIM2_H_
#include <stm32f10x.h>
#include "briupUSART.h"
#include "briupBasePeriph.h"
#include "briupDelay.h"
#include "briuoNVIC.h"

//�ӿڳ�ʼ�
//����Ͳ��� Ԥ��Ƶϵ��
void briupTIM2Init(u16 psc);

//������ʱ������
void briupTIM2Start(u16 arr);

//�رն�ʱ��
void briupTIM2Stop(void);

#endif

