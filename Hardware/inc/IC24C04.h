//24c04部分初始化函数 IIc2
#ifndef _IC24C04_H_
#define _IC24C04_H_

#ifndef _cplusplus
typedef enum {FL = 0,TU = !FL }bool;
#endif

#include <stm32f10x.h>
#include "briupDelay.h"

#define I2SCL_H GPIOB->IDR |= 1<<6;
#define I2SCL_L GPIOB->IDR |= 0<<6;
#define I2SDA_H GPIOB->IDR |= 1<<7;
#define I2SDA_L GPIOB->IDR |= 0<<7;

#define I2CSCL_read  (GPIOB->IDR & ~(0<<6));
#define I2CSDA_read  (GPIOB->IDR & ~(0<<7));

#define I2C2_PageSize 8 //24c02每页8字节 

#define EEPROM_WriteAddress1    0x00 //写入地址 
#define EEPROM_ReadAddress1     0x00 //读取地址
#define BufferSize1             (countof(Tx1_Buffer)-1)//写入字节长度  
#define countof(a) (sizeof(a) / sizeof(*(a)))  


//IO的初始化
void C04Init(void);
//读取字节
bool I2C_WriteByte(u8 sendByte,u16 WriteAddress,u8 DeviceAddress);
//缓冲区
bool I2C_BufferWrite(u8* pBuffer,u8 length,u16 WriteAddress,u8 DeviceAddress);
//页的写入 注意写入时不可以跨越页和行来进行写入
void I2C_PageWrite(u8* pBuffer,u8 length,u16 WriteAddress,u8 DeviceAddress);
//读取字节
bool I2C_ReadByte(u8* pBuffer,u8 length,u16 ReadAddress,u8 DeviceAddress);
//发送字符串
bool I2C_SendStr(u8* pBuffer,u8 length,u16 WriteAddress,u8 DeviceAddress);
//读取字符串
bool I2C_ReadStr(u8* pBuffer,u8 length,u16 ReadAddress,u8 DeviceAddress);


#endif

