#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK miniSTM32开发板
//按键驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PCin(5)   	
//#define KEY1 PAin(15)	 
//#define WK_UP  PAin(0)	 
 

#define KEYUP  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)//读取按键0
#define KEYLEFT  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)//读取按键1
#define KEYDOWN   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)//读取按键2 
#define KEYRIGHT   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define KEYA   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
#define KEYB   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)

#define KEYUP_PRES	1		 
#define KEYLEFT_PRES	2	
#define KEYDOWN_PRES	3		
#define KEYRIGHT_PRES	4
	 
#define KEYA_PRES	5
#define KEYB_PRES	6

void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8 mode);  	//按键扫描函数					    
#endif
