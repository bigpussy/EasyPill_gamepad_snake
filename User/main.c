#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "rtc.h"
#include "OLED.h"
#include "BEEP.h"

#define SNAKE_MAX_LENGTH 100
#define MAP_HEIGHT 32
#define MAP_WIDTH 50
void showFood();
void initMap();
void newFood();
void printSnake();
void moveSnake();
void showLength();
void gameOver();
struct{
	u8 x[SNAKE_MAX_LENGTH];
	u8 y[SNAKE_MAX_LENGTH];
	u8 direction;
	u8 speed;
	u8 length;
	u8 died;
	u8 pause;
}snake;

struct{
	u8 x;
	u8 y;
	u8 blink;
} food;
	
int main(void){
	
	
	
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
	
	

	LED3 = 1;
	
	initMap();
	showLength();
	
	while(1){
		if(snake.died == 0 && snake.pause == 0){
			moveSnake();
		}
		
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
		
		if(t == KEYA_PRES){
			snake.pause = !snake.pause;
			if(snake.pause == 1){
				showString(51, 20, "  P");
			}else{
				showString(51, 20, "   ");
			}
			pauseSound();
		}
		
		if(t == KEYB_PRES){
			initMap();
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

void initMap(){
	snake.x[0] = 3;
	snake.y[0] = 1;
	snake.x[1] = 2;
	snake.y[1] = 1;
	snake.x[2] = 1;
	snake.y[2] = 1;
	snake.direction = 4;
	snake.speed = 1;
	snake.length = 3;
	snake.died = 0;
	snake.pause = 0;
	extern u8  OLEDBuffer[];
	
	for(int r=0;r<1024;r++){
		OLEDBuffer[r] = 0x00;
	}
	
	startSound();
	
	newFood();
	
	for(int i=0; i < MAP_WIDTH; i++){
		printSpot(i , 0);
		printSpot(i , MAP_HEIGHT - 1);
	}
	
	for(int i=1; i < MAP_HEIGHT - 1; i++){
		printSpot(0 , i);
		printSpot(MAP_WIDTH - 1, i);
	}
	
	//printSpot(MAP_WIDTH , MAP_HEIGHT);
}

void newFood(){
	food.x = rand() % (MAP_WIDTH - 2) + 1;
	food.y = rand() % (MAP_HEIGHT - 2) + 1;
	
	for(int i=0; i < snake.length; i++){
		if(snake.x[i] == food.x && snake.y[i] == food.y){
			newFood();
			break;
		}
	}
	
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
		if(snake.y[0] > 1){
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
		}else{
			snake.died = 1;
		}
	}
	
	if(snake.direction == 2){
		if(snake.x[0] > 1){
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
		}else{
			snake.died = 1;
		}
	}
	
	if(snake.direction == 3){
		if(snake.y[0] < MAP_HEIGHT - 2){
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
		}else{
			snake.died = 1;
		}
	}
	
	if(snake.direction == 4){
		if(snake.x[0] < MAP_WIDTH - 2){
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
		}else{
			snake.died = 1;
		}
	}
	
	// judge die
	for(i = snake.length - 1; i > 0; i--){
		if(snake.x[i] == snake.x[0] && snake.y[i] == snake.y[0]){
			snake.died = 1;
			break;
		}
	}
	showLength();
	if(snake.died == 1){
		deadSound();
		gameOver();
	}

}

void gameOver(){
	showString(MAP_WIDTH / 2 - 18, MAP_HEIGHT / 2 - 4 , "GAME OVER" );
}


void showLength(){
	u8 length = snake.length;
	char num[] = "000";

	for(int i = 2; i >= 0; i--){
		num[i] = length % 10 + 0x30;
		length /= 10;
	}

	showString(51, 2, num);
}
