#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK miniSTM32������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PCin(5)   	
//#define KEY1 PAin(15)	 
//#define WK_UP  PAin(0)	 
 

#define KEYUP  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)//��ȡ����0
#define KEYLEFT  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)//��ȡ����1
#define KEYDOWN   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)//��ȡ����2 
#define KEYRIGHT   GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define KEYA   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
#define KEYB   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)

#define KEYUP_PRES	1		 
#define KEYLEFT_PRES	2	
#define KEYDOWN_PRES	3		
#define KEYRIGHT_PRES	4
	 
#define KEYA_PRES	5
#define KEYB_PRES	6

void KEY_Init(void);//IO��ʼ��
u8 KEY_Scan(u8 mode);  	//����ɨ�躯��					    
#endif
