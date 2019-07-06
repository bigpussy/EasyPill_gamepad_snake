#ifndef __BEEP__H__
#define __BEEP__H__

#include "sys.h"


#define BEEEP PBout(0)
#define BEEP_PIN GPIO_Pin_0
void Beep_Init(void);

void sound();
void deadSound();
#endif

