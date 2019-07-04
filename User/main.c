#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "rtc.h"
#include "OLED.h"
int main(void){
	u32 r, c, t;
	u16 position_x = 0, position_y = 0;
	u8 direction = 4;
	extern u8  OLEDBuffer[];
	delay_init();
	LED_Init();
	KEY_Init();
	OLEDInit();
	OLEDClear();
	OLEDDisplay();
	
	delay_ms(300);
	
	for(r=0;r<1024;r++){
		OLEDBuffer[r] = 0x00;
	}
	OLEDDisplay();

	OLEDDisplay();
	
	while(1){
		
		if(direction == 1){
			if(position_y > 0){
				position_y -- ;
				clearSpot(position_x, position_y + 1);
				printSpot(position_x, position_y);
			}
		}
		
		if(direction == 2){
			if(position_x > 0){
				position_x -- ;
				clearSpot(position_x + 1, position_y);
				printSpot(position_x, position_y);
			}
		}
		
		if(direction == 3){
			if(position_y < 31){
				position_y ++ ;
				clearSpot(position_x, position_y - 1);
				printSpot(position_x, position_y);
			}
		}
		
		if(direction == 4){
			if(position_x < 63){
				position_x ++ ;
				clearSpot(position_x - 1, position_y);
				printSpot(position_x, position_y);
			}
		}
		
		OLEDDisplay();
		delay_ms(10);
		
		t = KEY_Scan(0);
		
		if(t == KEYUP_PRES|| t == KEYLEFT_PRES || t == KEYDOWN_PRES || t == KEYRIGHT_PRES ){
			LED3 = ~LED3;
			
			if(direction == 1 && t != KEYDOWN_PRES){
				direction = t;
			}
			
			if(direction == 2 && t != KEYRIGHT_PRES){
				direction = t;
			}
			
			if(direction == 3 && t != KEYUP_PRES){
				direction = t;
			}
			
			if(direction == 4 && t != KEYLEFT_PRES){
				direction = t;
			}
		}
	}
}

