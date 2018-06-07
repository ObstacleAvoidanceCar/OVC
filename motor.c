#include "reg52.h"
#include "head.h"
#include "mylib.h"
#include "motor.h"

void MotorSet(motor M,bit S)
{
	if(S==0)
	{
		switch(M)
		{
			case LF:MLF1=1,MLF0=0;
			case LB:MLB1=1,MLB0=0;
			case RF:MRF1=1,MRF0=0;
			case RB:MRB1=1,MRB0=0;
		}
	}
	else
	{
		switch(M)
		{
			case LF:MLF1=0,MLF0=1;
			case LB:MLB1=0,MLB0=1;
			case RF:MRF1=0,MRF0=1;
			case RB:MRB1=0,MRB0=1;
		}
	}
}

void MotorReset(motor M)
{
	switch(M)
		{
			case LF:MLF1=0,MLF0=0;
			case LB:MLB1=0,MLB0=0;
			case RF:MRF1=0,MRF0=0;
			case RB:MRB1=0,MRB0=0;
		}
}

void MotorFront(void)
{
	MotorSet(LF,0);
	MotorSet(RF,0);
	MotorSet(RB,0);
	MotorSet(LB,0);
}
/*
void MotorRight(void)
{
	MotorSet(LF,0);
	MotorSet(LB,0);
	MotorSet(RF,1);
	MotorSet(RB,1);
	delay_ms(295);
}

void MotorLeft(void)
{
	MotorSet(LF,0);
	MotorSet(LB,0);
	MotorSet(RF,1);
	MotorSet(RB,1);
	delay_ms(295);
}
*/

void MotorRight(void)
{
	MotorSet(LF,0);
	MotorSet(LB,0);
	MotorSet(RF,1);
	MotorSet(RB,1);
	delay_ms(100);
}

void MotorLeft(void)
{
	MotorSet(LF,1);
	MotorSet(LB,1);
	MotorSet(RF,0);
	MotorSet(RB,0);
	delay_ms(100);
}

void MotorStop(void)
{
	MotorReset(LF);
	MotorReset(RF);
	MotorReset(RB);
	MotorReset(LB);
}

