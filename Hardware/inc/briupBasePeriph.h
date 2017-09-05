/***
*FileName: briupBasePeriph.h
*GreatteDate: 2017 8 24
*Author: Lamos
*Description: �����������������ʼ���ӿڼ�����غ궨�壬�����ӿ�
*Update
*/

#ifndef _BASEPERIPH_H_




#define _BASEPERIPH_H_

#include <stm32f10x.h>

#define  LED_R	(1<<2)
#define  LED_G  (1<<1)
#define  LED_B	(1<<0)
#define  LED_ALL (0x07)

// �����ɫ
#define  LED_Y	(LED_R|LED_G)
#define  LED_P	(LED_R|LED_B)
#define  LED_C	(LED_B|LED_G)
#define  LED_W	(LED_ALL)
//������
#define Beep (1<<14)

//�̵���
#define Relay1 (1<<13)//G
#define Relay2 (1<<3)//C

/*******
*FileName: basePeriphInit(); 
*Description : ��ʼ�����躯���ӿ�
*InPut: NULL
*OutPut : NULL
*/
void basePeriphInit(void);
/*******
*FileName: setLed(U8 LedStat)
*Description : ����LedStat������ӦLED
*InPut: 			LedStat  �õ���λ��Ӧ3��LED�Ƶ�״̬
*OutPut : NULL
*/
void setLed(u8 LedStat);
//����LedStatϨ���Ӧ�ĵ�
void resetLed(u8 LedStat);	
//���������� 0 �� 1��
void setBeep (void);
void resetBeep (void);


//�̵���
void setRelay1(void);
void setRelay2(void);
void resetRelay1(void);
void resetRelay2(void);

#endif

