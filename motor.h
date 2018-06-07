#ifndef _MOTOR_
#define _MOTOR_

sbit MLF1=P1^0;
sbit MLF0=P1^1;
sbit MLB1=P1^2;
sbit MLB0=P1^3;
sbit MRF1=P1^4;
sbit MRF0=P1^5;
sbit MRB1=P1^6;
sbit MRB0=P1^7;


typedef enum
{
	LF,
	RF,
	LB,
	RB
}motor;


void MotorSet(motor M,bit S);
void MotorReset(motor M);
void MotorFront(void);
void MotorRight(void);
void MotorLeft(void);
void MotorStop(void);


#endif