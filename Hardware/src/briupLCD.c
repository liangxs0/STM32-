
#include "briupLCD.h"
#include "briupLCDFont.h"

//LCDµÄ»­±ÊÑÕÉ«ºÍ±³¾°É«	   
u16 POINT_COLOR=0x0000;	//»­±ÊÑÕÉ«
u16 BACK_COLOR=0xFFFF;  //±³¾°É« 

//¹ÜÀíLCDÖØÒª²ÎÊý
//Ä¬ÈÏÎªÊúÆÁ
_lcd_dev lcddev;
	
		   
//Ð´¼Ä´æÆ÷º¯Êý
//regval:¼Ä´æÆ÷Öµ
void LCD_WR_REG(u16 regval)
{ 
	LCD->LCD_REG=regval;//Ð´ÈëÒªÐ´µÄ¼Ä´æÆ÷ÐòºÅ	 
}
//Ð´LCDÊý¾Ý
//data:ÒªÐ´ÈëµÄÖµ
void LCD_WR_DATA(u16 data)
{										    	   
	LCD->LCD_RAM=data;		 
}
//¶ÁLCDÊý¾Ý
//·µ»ØÖµ:¶Áµ½µÄÖµ
u16 LCD_RD_DATA(void)
{										    	   
	return LCD->LCD_RAM;		 
}					   
//Ð´¼Ä´æÆ÷
//LCD_Reg:¼Ä´æÆ÷µØÖ·
//LCD_RegValue:ÒªÐ´ÈëµÄÊý¾Ý
void LCD_WriteReg(u8 LCD_Reg, u16 LCD_RegValue)
{	
	LCD->LCD_REG = LCD_Reg;		//Ð´ÈëÒªÐ´µÄ¼Ä´æÆ÷ÐòºÅ	 
	LCD->LCD_RAM = LCD_RegValue;//Ð´ÈëÊý¾Ý	    		 
}	   
//¶Á¼Ä´æÆ÷
//LCD_Reg:¼Ä´æÆ÷µØÖ·
//·µ»ØÖµ:¶Áµ½µÄÊý¾Ý
u16 LCD_ReadReg(u8 LCD_Reg)
{										   
	LCD_WR_REG(LCD_Reg);		//Ð´ÈëÒª¶ÁµÄ¼Ä´æÆ÷ÐòºÅ
	_delay_us(3);
	return LCD_RD_DATA();		//·µ»Ø¶Áµ½µÄÖµ
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
	
		LCD_WR_REG(0xC0);  		//µçÔ´¿ØÖÆ
	LCD_WR_DATA(0x0a);     //1e  contrast
	LCD_WR_DATA(0x0a);     //1e  contrast
	
		LCD_WR_REG(0xC1);				//	µçÔ´¿ØÖÆ
	LCD_WR_DATA(0x44);    //41
	
		LCD_WR_REG(0XC5);
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x09);  //vcom  10
	
		LCD_WR_REG(0xB1);				//Ö¡ËÙÂÊ¿ØÖÆ
	LCD_WR_DATA(0x90);			//56HZ
	LCD_WR_DATA(0x11);			//25 clocks
	
		LCD_WR_REG(0xB4);			//	ÏÔÊ¾·´×ª¿ØÖÆ
	LCD_WR_DATA(0x02);
	
		LCD_WR_REG(0xB7);			//ÊäÈëÄ£Ê½ÉèÖÃ£¡£¡£¡£¡£¡£¡£¡
	LCD_WR_DATA(0xC6);
	
		LCD_WR_REG(0xB6);		//	ÏÔÊ¾¹¦ÄÜ¿ØÖÆ
	LCD_WR_DATA(0x00);
	LCD_WR_DATA(0x22);//0 GS SS SM ISC[3:0];??GS SS??????,????R36
	LCD_WR_DATA(0x3B);

	LCD_WR_REG(0xE0);			//Í¼Ïñ»Ò¶È¿ØÖÆ
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
	
		LCD_WR_REG(0XE1);			//Ïû³ýÙ¤Âí½ÃÕý
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
	
	LCD_WR_REG(0x36);				//ÉèÖÃÉ¨Ãè·½Ê½
	LCD_WR_DATA(0x00);		 //88 48   68   ??????
	
	LCD_WR_REG(0x3A);			//	½Ó¿ÚÏñËØ¸ñÊ½¡£Ñ¡Ôñ16Î»µÄ½Ó¿ÚÄ£Ê½
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
#if USE_HORIZONTAL==1	//Ê¹ÓÃºáÆÁ	  
	lcddev.dir=1;//ºáÆÁ
	lcddev.width=480;
	lcddev.height=320;			
	LCD_WriteReg(0x36,0x31);
#else//ÊúÆÁ
	lcddev.dir=0;//ÊúÆÁ				 	 		
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

//¿ìËÙ»­µã
void briupLcdFastDrawPoint(u16 x, u16 y, u16 color)
{
	LCD->LCD_REG = 0x2a;	//ÃüÁî£¡
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

//¿ìËÙ»­Ïß
void briupLcdFastDrawLine(u16 x1, u16 y1,u16 x2, u16 y2, u16 color)
{
	int dx = x2-x1;
	int dy = y2-y1;
	int y = y1;
	int eps = 0, i;
	
	LCD->LCD_REG = 0x2a;	//ÃüÁî£¡
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


//¿ìËÙ»­¾ØÐÎ
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
		//ÏÈ»­ºáÏß
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
		
		//ÔÙ»­ÊúÏß
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
		// Èç¹ûÌî³ä£¨»­ÊµÐÄÔ²£©
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
		// Èç¹û²»Ìî³ä£¨»­¿ÕÐÄÔ²£©
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
//m^nº¯Êý
//·µ»ØÖµ:m^n´Î·½.
u32 LCD_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}

//ÔÚÖ¸¶¨Î»ÖÃÏÔÊ¾Ò»¸ö×Ö·û
//x,y:ÆðÊ¼×ø±ê
//num:ÒªÏÔÊ¾µÄ×Ö·û:" "--->"~"
//size:×ÖÌå´óÐ¡ 12/16
//mode:µþ¼Ó·½Ê½(1)»¹ÊÇ·Çµþ¼Ó·½Ê½(0)
void briupLcdShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode,u16 point_colar,u16 back_colar)
{
	u8 temp=0,t1,t,size_x=0;
	u16 Supplementary_data_x = 0;
	u16 y0=y;
	u16 colortemp=POINT_COLOR;
	//ÉèÖÃ´°¿Ú		   
	num=num-' ';//µÃµ½Æ«ÒÆºóµÄÖµ
	if(!mode) //·Çµþ¼Ó·½Ê½
	{
				if(size == 12)size_x = 12;  //µ÷ÓÃ1206×ÖÌå
				if(size == 16)size_x = 16;	//µ÷ÓÃ1608×ÖÌå 	                          
				if(size == 32){size_x = 64;Supplementary_data_x=960;}	//µ÷ÓÃ3210×ÖÌå 
		for(t=0;t<size_x;t++)
	    {   
				if(size == 12)temp=asc2_1206[num][t];  //µ÷ÓÃ1206×ÖÌå
				if(size == 16)temp=asc2_1608[num][t];	 //µ÷ÓÃ1608×ÖÌå 	                          
				if(size == 32)temp=asc2_3210[num][t];	 //µ÷ÓÃ3210×ÖÌå
				for(t1=0;t1<8;t1++)
				{			    
					if(temp&0x80)POINT_COLOR=colortemp;
					else POINT_COLOR=BACK_COLOR;
					briupLcdFastDrawPoint( x, y, POINT_COLOR);	
					temp<<=1;
					y++;
					if(x>=lcddev.width+Supplementary_data_x){POINT_COLOR=colortemp;return;}//³¬ÇøÓòÁË
					if((y-y0)==size)
					{
						y=y0;
						x++;
						if(x>=lcddev.width+Supplementary_data_x){POINT_COLOR=colortemp;return;}//³¬ÇøÓòÁË
						break;
					}
				}  	 
	    }    
	}else//µþ¼Ó·½Ê½
	{
			if(size == 12)size_x = 12;  //µ÷ÓÃ1206×ÖÌå
			if(size == 16)size_x = 16;	//µ÷ÓÃ1608×ÖÌå 	                          
			if(size == 32){size_x = 64;Supplementary_data_x=960;}	//µ÷ÓÃ3210×ÖÌå 
	    for(t=0;t<size_x;t++)
	    {   
				if(size == 12)temp=asc2_1206[num][t];  //µ÷ÓÃ1206×ÖÌå
				if(size == 16)temp=asc2_1608[num][t];	 //µ÷ÓÃ1608×ÖÌå 	                          
				if(size == 32)temp=asc2_3210[num][t];	 //µ÷ÓÃ3210×ÖÌå                          
				for(t1=0;t1<8;t1++)
				{			    
					if(temp&0x80)briupLcdFastDrawPoint( x, y, point_colar);
					else briupLcdFastDrawPoint( x, y, back_colar);
					temp<<=1;
					y++;
					if(x>=lcddev.height+Supplementary_data_x){POINT_COLOR=colortemp;return;}//³¬ÇøÓòÁË
					if((y-y0)==size)
					{
						y=y0;
						x++;
						if(x>=lcddev.width+Supplementary_data_x){POINT_COLOR=colortemp;return;}//³¬ÇøÓòÁË
						break;
					}
				}  	 
	    }     
	}
	POINT_COLOR=colortemp;	    	   	 	  
}   

//ÏÔÊ¾Êý×Ö,¸ßÎ»Îª0,»¹ÊÇÏÔÊ¾
//x,y:Æðµã×ø±ê
//num:ÊýÖµ(0~999999999);
//len:³¤¶È(¼´ÒªÏÔÊ¾µÄÎ»Êý)
//size:×ÖÌå´óÐ¡ 12 / 16
//mode:
//[7]:0,²»Ìî³ä;1,Ìî³ä0.
//[6:1]:±£Áô
//[0]:0,·Çµþ¼ÓÏÔÊ¾;1,µþ¼ÓÏÔÊ¾.
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



//ÏÔÊ¾Í¼Æ¬½Ó¿Ú
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
//Í¼Æ¬ÏÔÊ¾ÉèÖÃ
void briupLcdImageDraw(ImgTypeDey * img )
{
	
	u16 imgColor;
	u32 i,j;
	u16 x1,y1,x2,y2;
	u16 offset = 3;
	//¾Ö²¿Ë¢ÐÂ
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
	
	
	//ÉèÖÃ×ÝÏòÏÔÊ¾ÇøÓò£¨ÁÐ¿í£
	LCD->LCD_REG = 0x2a;
	//ÆðÊ¼ÁÐSC
	LCD->LCD_RAM = img->localX >> 8;//ÆðÊ¼ÁÐ¸ß°ËÎ»
	LCD->LCD_RAM = img->localX & 0xff;//ÆðÊ¼ÁÐµÍ°ËÎ»
	//½áÊøÁÐEC
	LCD->LCD_RAM = (img->localX + img->imgW-1) >>8;
	LCD->LCD_RAM = (img->localX + img->imgW-1) & 0xff;

	//×ÝÏòÏÔÊ¾ÇøÓò
	LCD->LCD_REG = 0x2b;
	
	LCD->LCD_RAM = img->localY >> 8;
	LCD->LCD_RAM = img->localY & 0xff;
	LCD->LCD_RAM = (img->localY + img->imgH) >>8;
	LCD->LCD_RAM = img->localY + img->imgH & 0xff;
	//·¢ËÍÍ¼ÏñÊý¾Ý
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

//1 »æÖÆÍ¼Æ¬
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

