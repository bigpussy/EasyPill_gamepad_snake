#ifndef _LED_H_
#define _LED_H_
#include "stm32f10x.h"	
#include "sys.h"
void LED_Init(void);

#define LEDPORT GPIOC
#define LED1 GPIO_Pin_1
#define LED2 GPIO_Pin_13
#define LED3 PCout(13)	// PD2	
#define LED4 PAout(9)	// PD2	
#endif
