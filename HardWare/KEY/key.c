#include "key.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//按键输入 驱动代码		   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2014/3/06
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									   
//////////////////////////////////////////////////////////////////////////////////	 
 	    
//按键初始化函数 
//PA15和PC5 设置成输入
void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB| RCC_APB2Periph_GPIOE,ENABLE);//使能PORTA,PORTC时钟

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//关闭jtag，使能SWD，可以用SWD模式调试
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;//PA8
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA8
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11| GPIO_Pin_10 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1;//PA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0
	
} 
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//返回值：
//0，没有任何按键按下
//KEY0_PRES，KEY0按下
//KEY1_PRES，KEY1按下
//WKUP_PRES，WK_UP按下 
//注意此函数有响应优先级,KEY0>KEY1>WK_UP!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEYUP==0||KEYLEFT==0||KEYDOWN==0 || KEYRIGHT==0 || KEYA==0 || KEYB==0))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(KEYUP==0)return KEYUP_PRES;
		else if(KEYLEFT==0)return KEYLEFT_PRES;
		else if(KEYDOWN==0)return KEYDOWN_PRES;
		else if(KEYRIGHT==0)return KEYRIGHT_PRES; 
		else if(KEYA==0)return KEYA_PRES; 
		else if(KEYB==0)return KEYB_PRES; 
	}else if(KEYUP==1&&KEYLEFT==1&&KEYDOWN==1&&KEYRIGHT==1)key_up=1; 	     
	return 0;// 无按键按下
}
