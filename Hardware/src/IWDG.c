//�������Ź�������⵽Ӳ���쳣ʱ��λCPU
//��Ƶ��0~7  �Զ���װ��ֵ0~0XFFF
//��Ƶ���� = 4*2^prer  Time_OUt = ((4*2^prer)*rlr)/32(ms)

#include "IWDG.h"
//��ʼ��
void IWDG_Init(u8 prer,u16 rlr)
{

	IWDG->KR = 0X5555;//ʹ�ܶ�PR��RLR��д
	IWDG->PR = prer;//��Ƶϵ��
	IWDG->RLR = rlr;//�ؼ��ؼĴ��� ��11λ��Ч
	IWDG->KR = 0XAAAA;//��װ��
	IWDG->KR = 0XCCCC;//ʹ�ܿ��Ź�

}
//ι������
void Feed_Dog()
{


	IWDG->KR = 0XAAAA;//ι����ֵ
	
}
