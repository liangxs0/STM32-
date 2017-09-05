#include "briupFSMC.h"

void briupFSMCInit(void)
{
	//使能FSMC
	RCC->AHBENR |= 1<<8;
	//使能GPIO时钟
	//RS/RD/WR/A10/D0 --D15/cs /BL
	RCC->APB2ENR |= 1<<3 | 1<<5 | 1<<6 | 1<<8;
	GPIOB->CRL &= ~(0x0F);
	GPIOB->CRL |= 0x03;
	
	GPIOD->CRL &= 0xff00ff00;
	GPIOD->CRL |= 0x00BB00BB;
	GPIOD->CRH &= 0x00fff000;
	GPIOD->CRH |= 0xBB000BBB;
	
	GPIOE->CRL &= 0x0fffffff;
	GPIOE->CRL |= 0xB0000000;
 	GPIOE->CRH =  0xBBBBBBBB;
	
	GPIOG->CRL &= ~0x0f;
	GPIOG->CRL |= 0x0B;
	GPIOG->CRH &= 0xfff0ffff;
	GPIOG->CRH |= 0x000B0000;
	
	FSMC_Bank1->BTCR[6] = 0;
	FSMC_Bank1->BTCR[7] = 0;
	FSMC_Bank1E->BWTR[6] = 0;
	
	FSMC_Bank1->BTCR[6] = 1<<14 | 1<<12 |1<<4;
	FSMC_Bank1->BTCR[7] = 0x0f<<8 | 0x01;
	
	FSMC_Bank1E->BWTR[6] = 0x03<<8;
	
	FSMC_Bank1->BTCR[6] |= 0x01;
	
	_delay_ms(50);	
	
}
