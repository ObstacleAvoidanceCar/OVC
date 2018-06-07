#include "reg52.h"
#include "head.h"
#include "mylib.h"
#include "UT.h"
#include "LCD.h"

void delay_ms(unsigned char x)
{
	u16 t;
	for(t=0;t<(x*110);t++);
}

