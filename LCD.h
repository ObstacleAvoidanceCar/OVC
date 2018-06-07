#ifndef _LCD_
#define _LCD_
#include "head.h"


//以下定义数码管模块的引脚
sbit L0=P2^0;
sbit L1=P2^1;
sbit L2=P2^2;
sbit L3=P2^3;

void Display_SMG(u8 n1,u8 n2,u8 n3,u8 n4);


#endif