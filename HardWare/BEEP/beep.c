#include "beep.h"
#include "delay.h"

void Beep_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = BEEP_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	BEEEP = 0;
}

void sound(){
	int i;
	for(i = 0; i < 20 ; i++){
		delay_us(800);
		BEEEP = ~BEEEP;
	}
	for(i = 0; i < 20 ; i++){
		delay_us(700);
		BEEEP = ~BEEEP;
	}
	
	for(i = 0; i < 20 ; i++){
		delay_us(500);
		BEEEP = ~BEEEP;
	}
	for(i = 0; i < 100 ; i++){
		delay_us(100);
		BEEEP = ~BEEEP;
	}
	BEEEP = 0;
}

void deadSound(){
	int i;
	for(i = 0; i < 20 ; i++){
		delay_ms(5);
		BEEEP = ~BEEEP;
	}
	for(i = 0; i < 20 ; i++){
		delay_ms(10);
		BEEEP = ~BEEEP;
	}
	delay_ms(200);
	for(i = 0; i < 20 ; i++){
		delay_ms(5);
		BEEEP = ~BEEEP;
	}
	for(i = 0; i < 20 ; i++){
		delay_ms(10);
		BEEEP = ~BEEEP;
	}
	BEEEP = 0;
}