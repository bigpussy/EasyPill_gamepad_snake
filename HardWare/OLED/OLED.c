#include "OLED.h"
#include "string.h"

u8 OLEDBuffer[1024] = {
	0x80, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xE7, 0xE7, 0xE3, 
	0xF3, 0xF9, 0xFF, 0xFF, 0xFF, 0xF7, 0x7, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 
	0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x3F, 0x1F, 0xF, 0x7, 0x3, 0x0, 0x0, 0x0, 0xC0, 
	0xE0, 0x60, 0x20, 0x20, 0x60, 0xE0, 0xE0, 0xE0, 0x0, 0x0, 0x80, 0xC0, 0xE0, 0x60, 0x20, 0x60, 
	0x60, 0xE0, 0xE0, 0xE0, 0x0, 0x0, 0x80, 0xC0, 0x60, 0x60, 0x20, 0x60, 0x60, 0xE0, 0xE0, 0x0, 
	0x0, 0x0, 0xE0, 0xE0, 0x0, 0x0, 0x0, 0xE0, 0xE0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xE0, 
	0x60, 0x60, 0x60, 0x60, 0xE0, 0x80, 0x0, 0x0, 0x0, 0xE0, 0xE0, 0x0, 0x0, 0x0, 0xE0, 0xE0, 
	0x00, 0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	
	0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0xF, 0x7, 0x7, 
	0x7, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3E, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xF, 0x3F, 
	0x70, 0x60, 0x60, 0x60, 0x60, 0x30, 0x7F, 0x3F, 0x0, 0x0, 0x1F, 0x3F, 0x70, 0x60, 0x60, 0x60, 
	0x60, 0x39, 0xFF, 0xFF, 0x0, 0x6, 0x1F, 0x39, 0x60, 0x60, 0x60, 0x60, 0x30, 0x3F, 0x7F, 0x0, 
	0x0, 0x60, 0xFF, 0xFF, 0x60, 0x60, 0x0, 0x7F, 0x7F, 0x70, 0x60, 0x60, 0x40, 0x0, 0x7F, 0x7F, 
	0x0, 0x0, 0x0, 0x0, 0x7F, 0x7F, 0x0, 0x0, 0x0, 0x7F, 0x7F, 0x0, 0x0, 0x60, 0xFF, 0xFF, 
	0x60, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
		
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x3, 0x7, 0xF, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F, 0x7, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x7F, 0x3F, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x1F, 0x3F, 0x70, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x6, 0x0, 0x0, 0x0, 0x3, 0x3, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 

	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 

	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

	0x0, 0x0, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF0, 0xC0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC0, 
	0xC0, 0x0, 0x0, 0x0, 0xC0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0xC0, 0xC0, 0x0, 0x0, 0x0, 0x80, 
	0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0xC0, 0xC0, 0x0, 0x0, 0x0, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 
	0xC0, 0x80, 0x0, 0x0, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x0, 0x0, 0x0, 0xC0, 0xC0, 0x0, 
	0x0, 0x0, 0xC0, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC0, 0xC0, 0x0, 0x0, 0x0, 0x80, 0xC0, 
	0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x0, 0x0, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x0, 0x0, 

	0x0, 0x7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, 
	0xF8, 0xF0, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF, 
	0xFF, 0x0, 0x0, 0x0, 0xFF, 0xFF, 0xE0, 0xC0, 0xC0, 0xC0, 0xFF, 0x7F, 0x0, 0x0, 0x1E, 0x7F, 
	0xE1, 0xC0, 0xC0, 0xC0, 0xC0, 0x61, 0xFF, 0xFF, 0x0, 0x0, 0xFE, 0xFF, 0x1, 0x0, 0x0, 0x0, 
	0xFF, 0xFF, 0x0, 0x0, 0x21, 0xF9, 0xF8, 0xDC, 0xCC, 0xCF, 0x7, 0x0, 0xC0, 0xFF, 0xFF, 0xC0, 
	0x80, 0x0, 0xFF, 0xFF, 0xC0, 0xC0, 0x80, 0x0, 0x0, 0xFF, 0xFF, 0x0, 0x0, 0x1F, 0x7F, 0xF9, 
	0xC8, 0xC8, 0xC8, 0xC8, 0x79, 0x39, 0x0, 0x0, 0x71, 0xF9, 0xD8, 0xCC, 0xCE, 0x47, 0x3, 0x0, 

	0x0, 0x0, 0x0, 0x3, 0x7, 0x1F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFD, 0xF1, 0xE3, 
	0xE3, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFC, 0x7F, 0x3F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF0, 0xE0, 0x80, 0x0, 0x0, 0x0, 0xC, 
	0x1C, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7F, 0x7F, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0x7, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1C, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
};

u8 Number[] = {
	0x00, 0x00, 0x00, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	0xf8, 0x88, 0xf8, //0
	
	0xf8, 0x88, 0xf8, //0
	0x00, 0x00, 0xf8, //1
	0xb8, 0xa8, 0xe8, //2
	0xa8, 0xa8, 0xf8, //3
	0xe0, 0x20, 0xf8, //4
	0xe8, 0xa8, 0xb8, //5
	0xf8, 0xa8, 0xb8, //6
	0x80, 0x80, 0xf8, //7
	0xf8, 0xa8, 0xf8, //8
	0xe8, 0xa8, 0xf8, //9
	
	0xe8, 0xa8, 0xf8, //9
	0xe8, 0xa8, 0xf8, //9
	0xe8, 0xa8, 0xf8, //9
	0xe8, 0xa8, 0xf8, //9
	0xe8, 0xa8, 0xf8, //9
	0xe8, 0xa8, 0xf8, //9
	0xe8, 0xa8, 0xf8, //9
	
	0x78, 0xa0, 0x78, //A
	0xf8, 0xa8, 0x50, //B
	0x70, 0x88, 0x50, //C
	0xf8, 0x88, 0x70, //D
	0xf8, 0xa8, 0x88, //E
	0xf8, 0xa0, 0x80, //F
	0x70, 0xa8, 0xb0, //G
	0xf8, 0x20, 0xf8, //H
	0x88, 0xf8, 0x88, //I
	0x88, 0xf8, 0x80, //J
	0xf8, 0x50, 0x88, //K
	0xf8, 0x08, 0x08, //L
	0xf8, 0x40, 0xf8, //M
	0xf8, 0x80, 0xf8, //N
	0x70, 0x88, 0x70, //O
	0xf8, 0xa0, 0x40, //P
	0x60, 0x98, 0x68, //Q
	0xf8, 0x90, 0x68, //R
	0x48, 0xa8, 0x90, //S
	0x80, 0xf8, 0x80, //T
	0xf8, 0x08, 0xf8, //U
	0xf0, 0x08, 0xf0, //V
	0xf8, 0x30, 0xf8, //W
	0xd8, 0x20, 0xd8, //X
	0xc0, 0x38, 0xc0, //Y
	0x98, 0xa8, 0xc8, //Z
};


void initOLEDPORT(){
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);	
}

void OLEDInit(){
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //Ê¹ÄÜA¶Ë¿ÚÊ±ÖÓ

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //ÍÆÍìÊä³ö
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//ËÙ¶È50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	  //³õÊ¼»¯GPIOD3,6
 	GPIO_SetBits(GPIOB,GPIO_Pin_1|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);	
	
	OLEDWriteCmd(0xAE);//--turn off oled panel
	OLEDWriteCmd(0x00);//---set low column address
	OLEDWriteCmd(0x10);//---set high column address
	OLEDWriteCmd(0x40);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLEDWriteCmd(0x81);//--set contrast control register
	OLEDWriteCmd(0xCF); // Set SEG Output Current Brightness
	OLEDWriteCmd(0xA1);//--Set SEG/Column Mapping     0xa0×óÓÒ·´ÖÃ 0xa1Õý³£
	OLEDWriteCmd(0xC8);//Set COM/Row Scan Direction   0xc0ÉÏÏÂ·´ÖÃ 0xc8Õý³£
	OLEDWriteCmd(0xA6);//--set normal display
	OLEDWriteCmd(0xA8);//--set multiplex ratio(1 to 64)
	OLEDWriteCmd(0x3f);//--1/64 duty
	OLEDWriteCmd(0xD3);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	OLEDWriteCmd(0x00);//-not offset
	OLEDWriteCmd(0xd5);//--set display clock divide ratio/oscillator frequency
	OLEDWriteCmd(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	OLEDWriteCmd(0xD9);//--set pre-charge period
	OLEDWriteCmd(0xF1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLEDWriteCmd(0xDA);//--set com pins hardware configuration
	OLEDWriteCmd(0x12);
	OLEDWriteCmd(0xDB);//--set vcomh
	OLEDWriteCmd(0x40);//Set VCOM Deselect Level
	OLEDWriteCmd(0x20);//-Set Page Addressing Mode (0x00/0x01/0x02)
	OLEDWriteCmd(0x02);//
	OLEDWriteCmd(0x8D);//--set Charge Pump enable/disable
	OLEDWriteCmd(0x14);//--set(0x10) disable
	OLEDWriteCmd(0xA4);// Disable Entire Display On (0xa4/0xa5)
	OLEDWriteCmd(0xA6);// Disable Inverse Display On (0xa6/a7) 
	OLEDWriteCmd(0xAF);//--turn on oled panel
	OLEDWriteCmd(0xAF); /*display ON*/ 
}




void OLEDWriteCmd(u8 cmd){
	OLED_DC_Low();
	spiWrite(cmd);
}

void OLEDWriteData(u8 data){
	OLED_DC_High();
	spiWrite(data);
}

void spiWrite(u8 data){
	int8_t i;
	OLED_CS_Low();
	
	

		for(i=0;i<8;i++)
		{
			OLED_SCLK_Low();
			if(data&0x80)
			   OLED_SDIN_High();
			else 
			   OLED_SDIN_Low();
			OLED_SCLK_High();
			data<<=1;   
		}

	
	OLED_CS_High();
}


void OLEDClear(void){
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLEDWriteCmd(0xb0+i);
		OLEDWriteCmd(0x00);
		OLEDWriteCmd(0x10);
		for(n=0;n<128;n++)OLEDWriteData(0); 
	}
}

void OLEDSetPos(u8 x, u8 y){
	OLEDWriteCmd(0xb0+y);
	OLEDWriteCmd(((x&0xf0)>>4)|0x10);
	OLEDWriteCmd((x&0x0f)); 
}

void OLEDDisplay(void){
	u8 x, y ;
	for(y=0; y < 8; y++){
		OLEDSetPos(0,y);
		for(x = 0; x < 128; x++){
			OLEDWriteData(OLEDBuffer[y * 128 + x]);
		}
	}
}
// print a spot in x,y position (y [0-63], x[0-31])
void printSpot(u8 x, u8 y){
	u8 value = 0x00;
	if(y % 4 == 0){
		value = 0x03;
	}
	if(y % 4 == 1){
		value = 0x0c;
	}
	if(y % 4 == 2){
		value = 0x30;
	}
	
	if(y % 4 == 3){
		value = 0xc0;
	}
	OLEDBuffer[(x * 2) + (128) * (y / 4)] |= value;
	OLEDBuffer[(x * 2) + (128) * (y / 4) + 1] |= value;
}

void clearSpot(u8 x, u8 y){
	u8 value = 0x00;
	if(y % 4 == 0){
		value = 0x03;
	}
	if(y % 4 == 1){
		value = 0x0c;
	}
	if(y % 4 == 2){
		value = 0x30;
	}
	
	if(y % 4 == 3){
		value = 0xc0;
	}
	OLEDBuffer[(x * 2) + (128) * (y / 4)] &= ~value;
	OLEDBuffer[(x * 2) + (128) * (y / 4) + 1] &= ~value;
}

void showChar(u8 x, u8 y, u8 num){
	u8 n1 = Number[(num - 0x20) * 3];
	u8 n2 = Number[(num - 0x20) * 3 + 1];
	u8 n3 = Number[(num - 0x20) * 3 + 2];
	
	u8 dot_x, dot_y;
	dot_x = x;
	dot_y = y;
	for(int i = 0; i < 5; i++){
		if((n1 & 0x80) == 0x80){
			printSpot(dot_x, dot_y);
		}else{
			clearSpot(dot_x, dot_y);
		}
		n1 <<= 1;
		dot_y++;
	}
	
	dot_x = x + 1;
	dot_y = y;
	for(int i = 0; i < 5; i++){
		if((n2 & 0x80) == 0x80){
			printSpot(dot_x, dot_y);
		}else{
			clearSpot(dot_x, dot_y);
		}
		n2 <<= 1;
		dot_y++;
	}

	dot_x = x + 2;
	dot_y = y;
	for(int i = 0; i < 5; i++){
		if((n3 & 0x80) == 0x80){
			printSpot(dot_x, dot_y);
		}else{
			clearSpot(dot_x, dot_y);
		}
		n3 <<= 1;
		dot_y++;
	}
}

void showString(u8 x, u8 y, char * str){
	for(int i = 0; i < strlen(str); i++){
		showChar(x, y, str[i]);
		x += 4;
	}
}


