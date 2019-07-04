#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "rtc.h"
#include "OLED.h"
#include "BEEP.h"

#define SNAKE_MAX_LENGTH 100
void showFood();
void newFood();
void printSnake();
void moveSnake();
struct{
	u8 x[SNAKE_MAX_LENGTH];
	u8 y[SNAKE_MAX_LENGTH];
	u8 direction;
	u8 speed;
	u8 length;
}snake;

struct{
	u8 x;
	u8 y;
	u8 blink;
} food;
	
int main(void){
	
	snake.x[0] = 2;
	snake.y[0] = 0;
	snake.x[1] = 1;
	snake.y[1] = 0;
	snake.x[2] = 0;
	snake.y[2] = 0;
	snake.direction = 4;
	snake.speed = 1;
	snake.length = 3;
	
	food.x = 10;
	food.y = 10;
	food.blink = 1;
	
	u32 r, c, t;
	u8 direction = 4;
	extern u8  OLEDBuffer[];
	delay_init();
	LED_Init();
	KEY_Init();
	OLEDInit();
	OLEDClear();
	OLEDDisplay();
	Beep_Init();
	
	delay_ms(300);
	
	for(r=0;r<1024;r++){
		OLEDBuffer[r] = 0x00;
	}
	OLEDDisplay();

	OLEDDisplay();
	
	newFood();
	LED3 = 1;
	while(1){
		moveSnake();
		printSnake();
		OLEDDisplay();
		delay_ms(100);
		
		t = KEY_Scan(0);
		
		if(t == KEYUP_PRES|| t == KEYLEFT_PRES || t == KEYDOWN_PRES || t == KEYRIGHT_PRES ){
			
			if(snake.direction == 1 && t != KEYDOWN_PRES){
				snake.direction = t;
			}
			
			if(snake.direction == 2 && t != KEYRIGHT_PRES){
				snake.direction = t;
			}
			
			if(snake.direction == 3 && t != KEYUP_PRES){
				snake.direction = t;
			}
			
			if(snake.direction == 4 && t != KEYLEFT_PRES){
				snake.direction = t;
			}
		}
	}
}

static unsigned int next = 1;
int rand_r(u32 *seed)
{
	*seed = *seed * 1103515245 + 12345;
	return (*seed % ((unsigned int)1000 + 1));
}

int rand(void)
{
	return (rand_r(&next));
}

void srand(u32 seed)
{
   next = seed;
}

void newFood(){
	food.x = rand() % 64;
	food.y = rand() % 32;
	printSpot(food.x, food.y);
}

void showFood(){
	if(food.blink == 1){
		printSpot(food.x, food.y);
	}else{
		clearSpot(food.x, food.y);
	}
	food.blink = 1 - food.blink;
}
// print the snake
void printSnake(){
	int i;
	for(i = 0; i < snake.length; i++){
		printSpot(snake.x[i], snake.y[i]);
	}
}

void moveSnake(){
	int i;
	u8 tail_x = snake.x[snake.length - 1];
	u8 tail_y = snake.y[snake.length - 1];
	if(snake.direction == 1){
		if(snake.y[0] > 0){
			clearSpot(snake.x[snake.length - 1], snake.y[snake.length - 1]);
			for(i = snake.length - 1; i > 0; i--){
				snake.x[i] = snake.x[i-1];
				snake.y[i] = snake.y[i-1];
			}
			if(snake.y[0] - 1 == food.y && snake.x[0] == food.x){
				snake.y[0]--;
				snake.x[snake.length] = snake.x[snake.length - 1];
				snake.y[snake.length] = snake.y[snake.length - 1];
				snake.length++;
				sound();
				newFood();
			}else{ 
				snake.y[0] -- ;
				printSpot(snake.x[0], snake.y[0]);
			}
		}
	}
	
	if(snake.direction == 2){
		if(snake.x[0] > 0){
			clearSpot(snake.x[snake.length - 1], snake.y[snake.length - 1]);
			for(i = snake.length - 1; i > 0; i--){
				snake.x[i] = snake.x[i-1];
				snake.y[i] = snake.y[i-1];
			}
			if(snake.x[0] - 1 == food.x && snake.y[0] == food.y){
				snake.x[0]--;
				snake.x[snake.length] = snake.x[snake.length - 1];
				snake.y[snake.length] = snake.y[snake.length - 1];
				snake.length++;
				sound();
				newFood();
			}else{
				snake.x[0] -- ;
				printSpot(snake.x[0], snake.y[0]);
			}
		}
	}
	
	if(snake.direction == 3){
		if(snake.y[0] < 31){
			clearSpot(snake.x[snake.length - 1], snake.y[snake.length - 1]);
			for(i = snake.length - 1; i > 0; i--){
				snake.x[i] = snake.x[i-1];
				snake.y[i] = snake.y[i-1];
			}
			if(snake.y[0] + 1 == food.y && snake.x[0] == food.x){
				snake.y[0]++;
				snake.x[snake.length] = snake.x[snake.length - 1];
				snake.y[snake.length] = snake.y[snake.length - 1];
				snake.length++;
				sound();
				newFood();
			}else{
				snake.y[0] ++ ;
				printSpot(snake.x[0], snake.y[0]);
			}
		}
	}
	
	if(snake.direction == 4){
		if(snake.x[0] < 63){
			clearSpot(tail_x, tail_y);
			for(i = snake.length - 1; i > 0; i--){
				snake.x[i] = snake.x[i-1];
				snake.y[i] = snake.y[i-1];
			}
			
			if(snake.x[0] + 1 == food.x && snake.y[0] == food.y){
				snake.x[0]++;
				snake.x[snake.length] = snake.x[snake.length - 1];
				snake.y[snake.length] = snake.y[snake.length - 1];
				snake.length++;
				sound();
				newFood();
			}else{
				snake.x[0] ++ ;
				printSpot(snake.x[0], snake.y[0]);
			}

			
		}
	}
	
}
