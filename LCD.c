#include "reg52.h"
#include "mylib.h"
#include "LCD.h"


unsigned int t=1;
unsigned code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};	  //ÊýÂë¹Ü¶ÏÂë
unsigned code dis[]  ={0xfe,0xfd,0xfb,0xf7};




void Display_SMG(u8 n1,u8 n2,u8 n3,u8 n4)
{
	u8 i;
	unsigned int disbuff[4];
	disbuff[0]=n1;
	disbuff[1]=n2;
	disbuff[2]=n3;
	disbuff[3]=n4;
	for(i=0;i<4;i++)
	{
		P0=table[disbuff[i]];
		P2=dis[i];
		delay_ms(1);
	}
 }