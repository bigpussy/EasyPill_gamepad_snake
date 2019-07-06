
#ifndef __OLED__H_
#define __OLED__H_

#include "sys.h"

#define OLED_SCLK_Low() GPIO_ResetBits(GPIOB,GPIO_Pin_12)//CLK
#define OLED_SCLK_High() GPIO_SetBits(GPIOB,GPIO_Pin_12)

#define OLED_SDIN_Low() GPIO_ResetBits(GPIOB,GPIO_Pin_13)//DIN
#define OLED_SDIN_High() GPIO_SetBits(GPIOB,GPIO_Pin_13)

#define OLED_DC_Low() GPIO_ResetBits(GPIOB,GPIO_Pin_14)//DC
#define OLED_DC_High() GPIO_SetBits(GPIOB,GPIO_Pin_14)

#define OLED_CS_Low()  GPIO_ResetBits(GPIOB,GPIO_Pin_15)//CS
#define OLED_CS_High()  GPIO_SetBits(GPIOB,GPIO_Pin_15)

#define OLED_CMD 0

void initOLEDPORT(void);

void OLEDWriteCmd(u8 cmd);

void OLEDWriteData(u8 data);

void spiWrite(u8 data);

void OLEDInit(void);

void OLEDDisplay(void);

void OLEDClear(void);

void OLEDSetPos(u8 x, u8 y);

void setDot(void);

void setPos(void);

void printSpot(u8 x, u8 y);

void clearSpot(u8 x, u8 y);

void showChar(u8 x, u8 y, u8 num);

void showString(u8 x, u8 y, char * str);

#endif
