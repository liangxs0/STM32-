
#include "briupLCD.h"
#include "briupLCDFont.h"

//LCD�Ļ�����ɫ�ͱ���ɫ	   
u16 POINT_COLOR=0x0000;	//������ɫ
u16 BACK_COLOR=0xFFFF;  //����ɫ 

//����LCD��Ҫ����
//Ĭ��Ϊ����
_lcd_dev lcddev;
	
		   
//д�Ĵ�������
//regval:�Ĵ���ֵ
void LCD_WR_REG(u16 regval)
{ 
	LCD->LCD_REG=regval;//д��Ҫд�ļĴ������	 
}
//дLCD����
//data:Ҫд���ֵ
void LCD_WR_DATA(u16 data)
{										    	   
	LCD->LCD_RAM=data;		 
}
//��LCD����
//����ֵ:������ֵ
u16 LCD_RD_DATA(void)
{										    	   
	return LCD->LCD_RAM;		 
}					   
//д�Ĵ���
//LCD_Reg:�Ĵ�����ַ
//LCD_RegValue:Ҫд�������
void LCD_WriteReg(u8 LCD_Reg, u16 LCD_RegValue)
{	
	LCD->LCD_REG = LCD_Reg;		//д��Ҫд�ļĴ������	 
	LCD->LCD_RAM = LCD_RegValue;//д������	    		 
}	   
//���Ĵ���
//LCD_Reg:�Ĵ�����ַ
//����ֵ:����������
u16 LCD_ReadReg(u8 LCD_Reg)
{										   
	LCD_WR_REG(LCD_Reg);		//д��Ҫ���ļĴ������
	_delay_us(3);
	return LCD_RD_DATA();		//���ض�����ֵ
}   


void  briupLcdInit(void)
{
	briupFSMCInit();
	lcddev.id = 0;
	
	LCD_WR_REG( 0x00b0);
	LCD_WR_DATA( 0x00);
	
	LCD_WR_REG( 0x00d3);
	LCD_RD_DATA();
	LCD_RD_DATA();
	lcddev.id=LCD_RD_DATA();
	lcddev.id<<=8;
	lcddev.id|=LCD_RD_DATA();
	printf("%x\r\n", lcddev.id);
	
		LCD_WR_REG(0xC0);  		//��Դ����
	LCD_WR_DATA(0x0a);     //1e  contrast
	LCD_WR_DATA(0x0a);     //1e  contrast
	
		LCD_WR_REG(0xC1);				//	��Դ����
	LCD_WR_DATA(0x44);    //41
	
		LCD_WR_REG(0XC5);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x09);  //vcom  10
	
		LCD_WR_REG(0xB1);				//֡���ʿ���
	LCD_WR_DATA(0x90);			//56HZ
	LCD_WR_DATA(0x11);			//25 clocks
	
		LCD_WR_REG(0xB4);			//	��ʾ��ת����
	LCD_WR_DATA(0x02);
	
		LCD_WR_REG(0xB7);			//����ģʽ���ã�������������
	LCD_WR_DATA(0xC6);
	
		LCD_WR_REG(0xB6);		//	��ʾ���ܿ���
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x22);//0 GS SS SM ISC[3:0];??GS SS??????,????R36
	LCD_WR_DATA(0x3B);

	LCD_WR_REG(0xE0);			//ͼ��Ҷȿ���
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x04);
	LCD_WR_DATA(0x06);
	LCD_WR_DATA(0x02);
	LCD_WR_DATA(0x11);
	LCD_WR_DATA(0x0C);
	LCD_WR_DATA(0x3F);
	LCD_WR_DATA(0xAC);
	LCD_WR_DATA(0x4F);
	LCD_WR_DATA(0x09);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x0A);
	LCD_WR_DATA(0x21);
	LCD_WR_DATA(0x24);
	LCD_WR_DATA(0x0F);
	
		LCD_WR_REG(0XE1);			//����٤�����
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x1B);
	LCD_WR_DATA(0x1E);
	LCD_WR_DATA(0x05);
	LCD_WR_DATA(0x11);
	LCD_WR_DATA(0x06);
	LCD_WR_DATA(0x30);
	LCD_WR_DATA(0xff);
	LCD_WR_DATA(0x40);
	LCD_WR_DATA(0x03);
	LCD_WR_DATA(0x0E);
	LCD_WR_DATA(0x0D);
	LCD_WR_DATA(0x39);
	LCD_WR_DATA(0x3B);
	LCD_WR_DATA(0x0F);
	
	LCD_WR_REG(0XF2);
	LCD_WR_DATA(0x18);
	LCD_WR_DATA(0xA3);
	LCD_WR_DATA(0x12);
	LCD_WR_DATA(0x02);
	LCD_WR_DATA(0xB2);
	LCD_WR_DATA(0x12);
	LCD_WR_DATA(0xFF);
	LCD_WR_DATA(0x10);
	LCD_WR_DATA(0x00);
	
	LCD_WR_REG(0XF7);
	LCD_WR_DATA(0xA9);
	LCD_WR_DATA(0x91);
	LCD_WR_DATA(0x2D);
	LCD_WR_DATA(0x0A);
	LCD_WR_DATA(0x4F);
	
	LCD_WR_REG(0XFB);
	LCD_WR_DATA(0x21);
	LCD_WR_DATA(0x04);
	
	LCD_WR_REG(0x36);				//����ɨ�跽ʽ
	LCD_WR_DATA(0x00);		 //88 48   68   ??????
	
	LCD_WR_REG(0x3A);			//	�ӿ����ظ�ʽ��ѡ��16λ�Ľӿ�ģʽ
	LCD_WR_DATA(0x55);
	
	LCD_WR_REG(0xF9);  
	LCD_WR_DATA(0x00);  
	LCD_WR_DATA(0x08);  
	
	LCD_WR_REG(0xF4);  
	LCD_WR_DATA(0x00);  
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x08);  
	LCD_WR_DATA(0x91); 
	LCD_WR_DATA(0x04);
	LCD_WR_REG(0x11);
	
	_delay_ms(120);
	LCD_WR_REG(0x29);
	
	lcddev.setxcmd=0x2A;
	lcddev.setycmd=0x2B;
	lcddev.wramcmd=0x2C;
#if USE_HORIZONTAL==1	//ʹ�ú���	  
	lcddev.dir=1;//����
	lcddev.width=480;
	lcddev.height=320;			
	LCD_WriteReg(0x36,0x31);
#else//����
	lcddev.dir=0;//����				 	 		
	lcddev.width=320;
	lcddev.height=480;	
	LCD_WriteReg(0x36,0x08);
#endif
	
	LCD_LED_ON();
	briupLcdClear( 0xeed3);
}

//LCD_DisplayOn
void briupLcdDisplayOn(void)
{
	 LCD_WriteReg(0x0029,0);
}
//LCD_Displayoff
void briupLcdDisplayOff(void)
{
	LCD_WriteReg(0x0028,0);
}

void briupLcdClear(u16 Color)
{
	BACK_COLOR = Color;
	briupLcdFastDrawDirection( 0, lcddev.width-1, 0,lcddev.height-1, Color, 1);
}

//���ٻ���
void briupLcdFastDrawPoint(u16 x, u16 y, u16 color)
{
	LCD->LCD_REG = 0x2a;	//���
	LCD->LCD_RAM = x >> 8;
	LCD->LCD_RAM = x;
	LCD->LCD_RAM = x >> 8;
	LCD->LCD_RAM = x;
	LCD->LCD_REG = 0x2b;
	LCD->LCD_RAM = y >> 8;
	LCD->LCD_RAM = y;
	LCD->LCD_RAM = y >> 8;
	LCD->LCD_RAM = y;
	
	LCD->LCD_REG= 0x2c;
	LCD->LCD_RAM=color;
}

//���ٻ���
void briupLcdFastDrawLine(u16 x1, u16 y1,u16 x2, u16 y2, u16 color)
{
	int dx = x2-x1;
	int dy = y2-y1;
	int y = y1;
	int eps = 0, i;
	
	LCD->LCD_REG = 0x2a;	//���
	LCD->LCD_RAM = x1 >> 8;
	LCD->LCD_RAM = x1;
	LCD->LCD_RAM = x2 >> 8;
	LCD->LCD_RAM = x2;
	LCD->LCD_REG = 0x2b;
	LCD->LCD_RAM = y1 >> 8;
	LCD->LCD_RAM = y1;
	LCD->LCD_RAM = y2 >> 8;
	LCD->LCD_RAM = y2;
	
	LCD->LCD_REG= 0x2c;
	if(dx == 0)
		for( i = y1; i <= y2; i++)
			LCD->LCD_RAM = color;
	else if( dy == 0)
		for( i = x1; i <= x2; i++)
			LCD->LCD_RAM = color;
	else
		for( i = x1; i <= x2; i++)
		{
			LCD->LCD_RAM = color;
			eps+= dy;
			if( (eps << 1) >= dx)
			{
				y++;
				eps -= dx;
			}
		}
}


//���ٻ�����
void briupLcdFastDrawDirection(u16 x1, u16 x2, u16 y1,u16 y2,u16 color, u8 full)
{
	u16 i,j;
	
	if( full == 1)
	{
		LCD->LCD_REG = 0x2a;
		LCD->LCD_RAM = x1 >> 8;
		LCD->LCD_RAM = x1;
		LCD->LCD_RAM = x2 >> 8;
		LCD->LCD_RAM = x2;
		LCD->LCD_REG = 0x2b;
		LCD->LCD_RAM = y1 >> 8;
		LCD->LCD_RAM = y1;
		LCD->LCD_RAM = y2 >> 8;
		LCD->LCD_RAM = y2;
		
		LCD->LCD_REG= 0x2c;
		for(i = x1;i <= x2;i++)
			for(j = y1; j <= y2; j++)
				LCD->LCD_RAM=color;
	}else
	{
		//�Ȼ�����
		LCD->LCD_REG = 0x2a;
		LCD->LCD_RAM = x1 >> 8;
		LCD->LCD_RAM = x1;
		LCD->LCD_RAM = x2 >> 8;
		LCD->LCD_RAM = x2;
		LCD->LCD_REG = 0x2b;
		LCD->LCD_RAM = y1 >> 8;
		LCD->LCD_RAM = y1;
		LCD->LCD_RAM = y1 >> 8;
		LCD->LCD_RAM = y1;
		
		LCD->LCD_REG= 0x2c;
		for(i = x1; i <= x2; i++)
			LCD->LCD_RAM=color;
		
		LCD->LCD_REG = 0x2b;
		LCD->LCD_RAM = y2 >> 8;
		LCD->LCD_RAM = y2;
		LCD->LCD_RAM = y2 >> 8;
		LCD->LCD_RAM = y2;
		
		LCD->LCD_REG= 0x2c;
		for(i = x1; i <= x2; i++)
			LCD->LCD_RAM=color;
		
		//�ٻ�����
		LCD->LCD_REG = 0x2b;
		LCD->LCD_RAM = y1 >> 8;
		LCD->LCD_RAM = y1;
		LCD->LCD_RAM = y2 >> 8;
		LCD->LCD_RAM = y2;
		LCD->LCD_REG = 0x2a;
		LCD->LCD_RAM = x1 >> 8;
		LCD->LCD_RAM = x1;
		LCD->LCD_RAM = x1 >> 8;
		LCD->LCD_RAM = x1;
		
		LCD->LCD_REG= 0x2c;
		for(i = y1; i <= y2; i++)
			LCD->LCD_RAM=color;
		
		LCD->LCD_REG = 0x2a;
		LCD->LCD_RAM = x2 >> 8;
		LCD->LCD_RAM = x2;
		LCD->LCD_RAM = x2 >> 8;
		LCD->LCD_RAM = x2;
		
		LCD->LCD_REG= 0x2c;
		for(i = y1; i <= y2; i++)
			LCD->LCD_RAM=color;
	}
}

void briupLcdFastDrawCircle( u16 xc, u16 yc, u16 r, u16 color, u8 full)
{
	int x = 0, y = r, yi, d;

	d = 3 - 2 * r;

	if (full) 
	{
		// �����䣨��ʵ��Բ��
		while (x <= y) {
			for (yi = x; yi <= y; yi++)
			{
				briupLcdFastDrawPoint(xc + x, yc + y, color);
				briupLcdFastDrawPoint(xc - x, yc + y, color);
				briupLcdFastDrawPoint(xc + x, yc - y, color);
				briupLcdFastDrawPoint(xc - x, yc - y, color);
				briupLcdFastDrawPoint(xc + y, yc + x, color);
				briupLcdFastDrawPoint(xc - y, yc + x, color);
				briupLcdFastDrawPoint(xc + y, yc - x, color);
				briupLcdFastDrawPoint(xc - y, yc - x, color);
			}

			if (d < 0) {
				d = d + 4 * x + 6;
			} else {
				d = d + 4 * (x - y) + 10;
				y--;
			}
			x++;
		}
	} else 
	{
		// �������䣨������Բ��
		while (x <= y) {
			briupLcdFastDrawPoint(xc + x, yc + y, color);
			briupLcdFastDrawPoint(xc - x, yc + y, color);
			briupLcdFastDrawPoint(xc + x, yc - y, color);
			briupLcdFastDrawPoint(xc - x, yc - y, color);
			briupLcdFastDrawPoint(xc + y, yc + x, color);
			briupLcdFastDrawPoint(xc - y, yc + x, color);
			briupLcdFastDrawPoint(xc + y, yc - x, color);
			briupLcdFastDrawPoint(xc - y, yc - x, color);
			if (d < 0) {
				d = d + 4 * x + 6;
			} else {
				d = d + 4 * (x - y) + 10;
				y--;
			}
			x++;
		}
	}
}

//=======================================================================================
//m^n����
//����ֵ:m^n�η�.
u32 LCD_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}

//��ָ��λ����ʾһ���ַ�
//x,y:��ʼ����
//num:Ҫ��ʾ���ַ�:" "--->"~"
//size:�����С 12/16
//mode:���ӷ�ʽ(1)���Ƿǵ��ӷ�ʽ(0)
void briupLcdShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode,u16 point_colar,u16 back_colar)
{
	u8 temp=0,t1,t,size_x=0;
	u16 Supplementary_data_x = 0;
	u16 y0=y;
	u16 colortemp=POINT_COLOR;
	//���ô���		   
	num=num-' ';//�õ�ƫ�ƺ��ֵ
	if(!mode) //�ǵ��ӷ�ʽ
	{
				if(size == 12)size_x = 12;  //����1206����
				if(size == 16)size_x = 16;	//����1608���� 	                          
				if(size == 32){size_x = 64;Supplementary_data_x=960;}	//����3210���� 
		for(t=0;t<size_x;t++)
	    {   
				if(size == 12)temp=asc2_1206[num][t];  //����1206����
				if(size == 16)temp=asc2_1608[num][t];	 //����1608���� 	                          
				if(size == 32)temp=asc2_3210[num][t];	 //����3210����
				for(t1=0;t1<8;t1++)
				{			    
					if(temp&0x80)POINT_COLOR=colortemp;
					else POINT_COLOR=BACK_COLOR;
					briupLcdFastDrawPoint( x, y, POINT_COLOR);	
					temp<<=1;
					y++;
					if(x>=lcddev.width+Supplementary_data_x){POINT_COLOR=colortemp;return;}//��������
					if((y-y0)==size)
					{
						y=y0;
						x++;
						if(x>=lcddev.width+Supplementary_data_x){POINT_COLOR=colortemp;return;}//��������
						break;
					}
				}  	 
	    }    
	}else//���ӷ�ʽ
	{
			if(size == 12)size_x = 12;  //����1206����
			if(size == 16)size_x = 16;	//����1608���� 	                          
			if(size == 32){size_x = 64;Supplementary_data_x=960;}	//����3210���� 
	    for(t=0;t<size_x;t++)
	    {   
				if(size == 12)temp=asc2_1206[num][t];  //����1206����
				if(size == 16)temp=asc2_1608[num][t];	 //����1608���� 	                          
				if(size == 32)temp=asc2_3210[num][t];	 //����3210����                          
				for(t1=0;t1<8;t1++)
				{			    
					if(temp&0x80)briupLcdFastDrawPoint( x, y, point_colar);
					else briupLcdFastDrawPoint( x, y, back_colar);
					temp<<=1;
					y++;
					if(x>=lcddev.height+Supplementary_data_x){POINT_COLOR=colortemp;return;}//��������
					if((y-y0)==size)
					{
						y=y0;
						x++;
						if(x>=lcddev.width+Supplementary_data_x){POINT_COLOR=colortemp;return;}//��������
						break;
					}
				}  	 
	    }     
	}
	POINT_COLOR=colortemp;	    	   	 	  
}   

//��ʾ����,��λΪ0,������ʾ
//x,y:�������
//num:��ֵ(0~999999999);
//len:����(��Ҫ��ʾ��λ��)
//size:�����С 12 / 16
//mode:
//[7]:0,�����;1,���0.
//[6:1]:����
//[0]:0,�ǵ�����ʾ;1,������ʾ.
void briupLcdShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode)
{  
	u8 t,temp;
	u8 enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				if(mode&0X80)briupLcdShowChar(x+(size/2)*t,y,'0',size,mode&0X01,POINT_COLOR,0xffff);  
				else briupLcdShowChar(x+(size/2)*t,y,' ',size,mode&0X01,POINT_COLOR,0xffff);  
 				continue;
			}else enshow=1; 
		 	 
		}
	 	briupLcdShowChar(x+(size/2)*t,y,temp+'0',size,mode&0X01,POINT_COLOR,0xffff); 
	}
}



//��ʾͼƬ�ӿ�
void briupLcdImageInit(ImgTypeDey* img,u16 imgW,u16 imgH,u16 localX,u16 localY,unsigned char * imgArr)
{
	img->imgW = imgW;
	img->imgH = imgH;
	img->localX = localX;
	img->localY = localY;
	
	img->Vx = 0;
	img->Vy = 0;
	img->drawMode = 1;
	img->imgArr = imgArr;
	
}
//ͼƬ��ʾ����
void briupLcdImageDraw(ImgTypeDey * img )
{
	
	u16 imgColor;
	u32 i,j;
	u16 x1,y1,x2,y2;
	u16 offset = 3;
	//�ֲ�ˢ��
	if(img->drawMode == 2)
	{
		if(img->Vx > 0)
		{
			x1 = img->localX - img->Vx - offset;
			x2 = img->localX;
			y1 = img->localY - offset;
			y2 = img->localY + img->imgH + offset;
			briupLcdFastDrawDirection(x1,x2,y1,y2,BACK_COLOR,1);
		}
		else if (img->Vx < 0)
		{
			x1 = img->localX + img->imgW;
			x2 = x1 - img->Vx + offset;
			y1 = img->localY - offset;
			y2 = img->localY + img->imgH + offset;
			briupLcdFastDrawDirection(x1,x2,y1,y2,BACK_COLOR,1);
		}
		if (img->Vy > 0)
		{
			y1 =  img->localY-img->Vy-offset;
			y2 = img->localY;
			x1 = img->localX - offset;
			x2 = img->localX + img->imgW + offset;
			briupLcdFastDrawDirection(x1,x2,y1,y2,BACK_COLOR,1);
		}
		else if (img->Vy < 0)
		{
			y1 = img->localY + img->imgH;
			y2 = y1 - img->Vy + offset;
			x1 = img->localX - offset;
			x2 = img->localX + img->imgW + offset;
			briupLcdFastDrawDirection(x1,x2,y1,y2,BACK_COLOR,1);
		}
			return ;
	}
	
	
	//����������ʾ�����п�
	LCD->LCD_REG = 0x2a;
	//��ʼ��SC
	LCD->LCD_RAM = img->localX >> 8;//��ʼ�и߰�λ
	LCD->LCD_RAM = img->localX & 0xff;//��ʼ�еͰ�λ
	//������EC
	LCD->LCD_RAM = (img->localX + img->imgW-1) >>8;
	LCD->LCD_RAM = (img->localX + img->imgW-1) & 0xff;

	//������ʾ����
	LCD->LCD_REG = 0x2b;
	
	LCD->LCD_RAM = img->localY >> 8;
	LCD->LCD_RAM = img->localY & 0xff;
	LCD->LCD_RAM = (img->localY + img->imgH) >>8;
	LCD->LCD_RAM = img->localY + img->imgH & 0xff;
	//����ͼ������
	LCD->LCD_REG = 0x2c;
//	for (i = 0;i < img->imgH*img->imgW*2;i+=2)
if(img->drawMode == 0)
{
	for(i = 0;i<img->imgH;i++)
	{
		for(j=0;j<img->imgW;j++)
		{
			LCD->LCD_RAM = BACK_COLOR;
		}
	}
}

//1 ����ͼƬ
if(img->drawMode == 1)
	{
	for (i = 0; i<img->imgH ; i++)
	{
		for(j = 0; j<img->imgW;j++)
		{
			imgColor = img->imgArr[(j+i*img->imgW)*2+1]<<8;
			imgColor |= img->imgArr[(j+i*img->imgW)*2];
			LCD->LCD_RAM = imgColor;
		}
	}
	}
}

