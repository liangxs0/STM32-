#include <stm32f10x.h>
#include <string.h>

#include "briupBasePeriph.h"
#include "briupDelay.h"
#include "briupKeyboard.h"
#include "briupUsart.h"
#include "briuoNVIC.h"
#include "briupTIM2.h"

#include "briupLCD.h"

#include "briupMPU6050.h"
//void show(void);
extern const unsigned char gImage_test[13400];
extern const unsigned char gImage_test2[11200];

//自动重转载值
//u16 beepFreq[21]={
//									
//									34351,30612,2272,25787,22959,20454,18218,
//									17208,15332,13657,12893,11479,10227,9109,
//									8604,7659,6828,6442,5739,5113,4554
//				};
int main()
{
	
	//X翻滚角度，水平时为零 左翻为负数，右翻为整数
	//Y俯仰角度，仰角为正数。俯角为负数
	short x,y;
	ImgTypeDey imgTest;
	ImgTypeDey imgTest2;
	
	briupTIM2Init(4);
	briupNVICGroupInit(2);
	delay_init(72);
	basePeriphInit();
	briupKeyInit();
	briupUsart1Init(57600);
	
	
	briupLcdInit();
	//需要大约0.5秒初始化
	//此时尽量保证水平放置，否则会出现一个偏移量
	//此偏移量可通过软件消除
	//同时初始化函数有点不稳定，可能会初始化失败
	briupMPU6050Init();
	
	briupLcdImageInit(&imgTest,100,67,10,10,(unsigned char*)gImage_test);
	briupLcdImageDraw(&imgTest);
	imgTest.Vx = 1;
	imgTest.Vy = 1;
	
	briupLcdImageInit(&imgTest2,100,56,50,50,(unsigned char*)gImage_test2);;
	briupLcdImageDraw(&imgTest2);
	imgTest2.Vx = 1;
	imgTest2.Vy = 1;
	briupLcdClear(0x0000);
	
 x = 0;
 y = 0;
while(1)
{
	//获取陀螺仪数据
	getMPU6050Data(&x,&y);
	imgTest.Vx = x%6;
	imgTest.Vy = y%6;
	imgTest2.Vx = x%4;
	imgTest2.Vy = y%4;
	if(x>0)
		setLed(LED_R);
	else
		resetLed(LED_R);
	
	if(y>0)
		setLed(LED_B);
	else
		resetLed(LED_B);
	imgTest.drawMode = 2;
	briupLcdImageDraw(&imgTest);
	if(imgTest.localX +  imgTest.Vx < 5)
	{
			imgTest.Vx = 0;
		}
	if(imgTest.localX + imgTest.imgW + imgTest.Vx > lcddev.width - 5 )
		{
				imgTest.Vx = 0;
		}
		
	if(imgTest.localY +  imgTest.Vy < 5)
		{
			imgTest.Vy = 0;
		}
	if(imgTest.localY + imgTest.imgH + imgTest.Vy > lcddev.height - 5 )
		{
				imgTest.Vy = 0;
		}
	imgTest.localX +=  imgTest.Vx ;
	imgTest.localY +=  imgTest.Vy ;	
	imgTest.drawMode = 1;		
	briupLcdImageDraw(&imgTest);



	imgTest2.drawMode = 2;
	briupLcdImageDraw(&imgTest2);
	if(imgTest2.localX +  imgTest2.Vx < 5)
	{
			imgTest2.Vx = 0;
		}
	if(imgTest2.localX + imgTest2.imgW + imgTest2.Vx > lcddev.width - 5 )
		{
				imgTest2.Vx = 0;
		}
		
	if(imgTest2.localY +  imgTest2.Vy < 5)
		{
			imgTest2.Vy = 0;
		}
	if(imgTest2.localY + imgTest2.imgH + imgTest2.Vy > lcddev.height - 5 )
		{
				imgTest2.Vy = 0;
		}
	imgTest2.localX +=  imgTest2.Vx ;
	imgTest2.localY +=  imgTest2.Vy ;	
	imgTest2.drawMode = 1;		
	briupLcdImageDraw(&imgTest2);
//0 右撞 2 左
 if(imgTest2.localY + imgTest2.imgH >= imgTest.localY)
 {
//		 setBeep();
//	 _delay_ms(200);
//	 resetBeep();
	} 

}
 
	

}


