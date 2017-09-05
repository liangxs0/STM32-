
#ifndef __BALLANCE_LCD_H__
#define __BALLANCE_LCD_H__

#include <stm32f10x.h>
#include "briupDelay.h"
#include "briupUsart.h"
#include "briupFsmc.h"

//��Ļ�����ṹ�嶨��
typedef struct
{
	u16 width;	//��Ļ��� 320
	u16 height; //��Ļ�߶� 480
	u16 id;		//��Ļ��ʶ��
	u8 dir;		//
	u8 wramcmd; //дRAM����
	u8 setxcmd; //���ú���������
	u8 setycmd; //��������������
}_lcd_dev;

extern _lcd_dev lcddev;
extern u16 POINT_COLOR;
extern u16 BACK_COLOR;

#define LCD_LED_ON()	GPIOB->ODR |= 0x01;
#define LCD_LED_OFF()	GPIOB->ODR &= ~0x01;
#define LCD_WIDTH_MAX	320
#define LCD_HIGH_MAX	480

//LCD��ַ�ṹ��
typedef struct
{
	u16 LCD_REG;	//Register
	u16 LCD_RAM;	//������ʴ洢��
} LCD_TypeDef;
//ʹ��NOR/SRAM�� Bank1.sector4,��ַλHADDR[27,26]=11 A10��Ϊ�������������� 
//ע������ʱSTM32�ڲ�������һλ����! 111110=0X3E			    
#define LCD_BASE        ((u32)(0x6C000000 | 0x000007FE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)

#define	LCD_RST_SET  GPIOC->BSRR=1<<5    //��λ			PC5
#define	LCD_RST_CLR  GPIOC->BRR=1<<5    //��λ			PC5


//ɨ�跽����
#define L2R_U2D  0 //������,���ϵ���
#define L2R_D2U  1 //������,���µ���
#define R2L_U2D  2 //���ҵ���,���ϵ���
#define R2L_D2U  3 //���ҵ���,���µ���

#define U2D_L2R  4 //���ϵ���,������
#define U2D_R2L  5 //���ϵ���,���ҵ���
#define D2U_L2R  6 //���µ���,������
#define D2U_R2L  7 //���µ���,���ҵ���	 

#define DFT_SCAN_DIR  L2R_U2D  //Ĭ�ϵ�ɨ�跽��
#define WHITE       0xFFFF
#define BLACK      	0x0000	  
#define BLUE       	0xF800 
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF
#define RED         0x001F
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 			0X457 
#define BRRED 			0XFC07 
#define GRAY  			0X8430 
//GUI

#define DARKBLUE      	 0X01CF	
#define LIGHTBLUE      	 0X7D7C	
#define GRAYBLUE       	 0X5458 

#define LIGHTGREEN     	0X841F 
//#define LIGHTGRAY     0XEF5B 
#define LGRAY 			 		0XC618 

#define LGRAYBLUE      	0XA651 
#define LBBLUE          0X2B12 

//ͼƬ���Խṹ��
typedef struct {
	u16 imgW;
	u16 imgH;
	//������x ������y
	u16 localX;
	u16 localY;
	
	//�����ٶȣ������ٶ�
	short Vx;//X����
	short Vy;//Y���ٶ�
	//ͼƬ��ʾģʽ
	// drawMOde = 0; �������õ�ɫ���
	// drawMOde = 1 ͼƬ����
	// drawMOde = 2 ͼƬ��
	u8 drawMode;
	
	//ͼƬ��Դ
	unsigned char * imgArr;
	
}ImgTypeDey;

void briupLcdInit(void);	//Һ������ʼ������
void briupLcdDisplayOn(void);	//����ʾģʽ								//����ʾ
void briupLcdDisplayOff(void);  //����ʾ
void briupLcdClear(u16 Color);	 												//����

//���ٻ�����
void briupLcdFastDrawDirection(u16 x1, u16 x2, u16 y1,u16 y2,u16 color, u8 full);
//���ٻ���
void briupLcdFastDrawPoint(u16 x, u16 y, u16 color);
//���ٻ���
void briupLcdFastDrawLine(u16 x1, u16 y1,u16 x2, u16 y2, u16 color);
//���ٻ�Բ
void briupLcdFastDrawCircle( u16 x, u16 y, u16 r, u16 color, u8 full);

//��LCD��д������
void LCD_WriteReg(u8 LCD_Reg, u16 LCD_RegValue);
//��ȡLCDָ���Ĵ���������
u16 LCD_ReadReg(u8 LCD_Reg);

//��ʾ�ַ���
void briupLcdShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode,u16 point_colar,u16 back_colar);
//��ʾ����
void briupLcdShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode);
//��ʾͼƬ�ӿ�
void briupLcdImageInit(ImgTypeDey* img,u16 imgW,u16 imgH,u16 localX,u16 localY,unsigned char * imgArr);
//ͼƬ��ʾ����
void briupLcdImageDraw(ImgTypeDey * img);

#endif
