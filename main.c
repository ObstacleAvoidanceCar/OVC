#include "reg52.H"
#include "LCD.h"
#include "mylib.h"
#include "head.h"
#include "motor.h"
#include "UT.h"
#include "SM.h"
u16 ti=0;

void UTConut(void)		   //�������
{
	TMOD=0X11;
	TH1=0XFc;	  //1Ms��ʱ
	TL1=0X18;
	TH0=0;
	TL0=0;  
	TR1= 1;
	ET1= 1;
	ET0= 1;
	EA = 1;
  while(!ECHO);		       //��RXΪ��ʱ�ȴ�
	TR0=1;			       //��������
	while(ECHO);			   //��RXΪ1�������ȴ�
	TR0=0;				   //�رռ���
	time=TH0*256+TL0;		   //��ȡ������
	TH0=0;
	TL0=0;
	S=(time*1.7)/100;
}

void UTDisplay()
{
	u8 N4,N3,N2,N1;
  UTStart();
	N4=S/1000;
	N3=(S/100)%10;
	N2=(S/10)%10;
	N1=S%10;
	Display_SMG(N4,N3,N2,N1);
}

void Trick()
{
	unsigned long S1=0;
	MotorStop();
		for(ti=0;ti<10;ti++)
		{
			SMRight();
		}
		UTConut();
		delay_ms(2);
		for(ti=0;ti<10;ti++)
			{
				UTDisplay();
			}
		S1=S;
		delay_ms(20);
		for(ti=0;ti<10;ti++)
		{
			SMLeft();
		}
		UTConut();
		delay_ms(2);
		for(ti=0;ti<10;ti++)
			{
				UTDisplay();
			}
		for(ti=0;ti<10;ti++)
		{
			SMCenter();
		}
		if(S1<S)
		{
			MotorLeft();
			delay_ms(32);
			MotorStop();
			delay_ms(30);
			MotorFront();
			delay_ms(100);
			MotorStop();
			delay_ms(30);
			MotorRight();
			delay_ms(38);
			MotorStop();
			delay_ms(30);
			MotorFront();
			delay_ms(200);
			delay_ms(80);
			MotorStop();
			delay_ms(30);
			MotorRight();
			delay_ms(30);
			MotorStop();
			delay_ms(30);
			MotorFront();
			delay_ms(100);
			MotorStop();
			delay_ms(30);
			MotorLeft();
			delay_ms(58);
			MotorStop();
			delay_ms(30);
		}
		else
		{
			MotorRight();
			delay_ms(30);
			MotorStop();
			delay_ms(30);
			MotorFront();
			delay_ms(100);
			MotorStop();
			delay_ms(30);
			MotorLeft();
			delay_ms(40);
			MotorStop();
			delay_ms(30);
			MotorFront();
			delay_ms(200);
			delay_ms(80);
			MotorStop();
			delay_ms(30);
			MotorLeft();
			delay_ms(40);
			MotorStop();
			delay_ms(30);
			MotorFront();
			delay_ms(100);
			MotorStop();
			delay_ms(30);
			MotorRight();
			delay_ms(58);
			MotorStop();
			delay_ms(30);
		}
}

void main()
{
	unsigned long S_bak1,S_bak2;
	while(1)
	{
		for(ti=0;ti<4;ti++)
		{
			SMCenter();
		}
		UTConut();
		S_bak1=S;
		UTConut();
		S_bak2=S;
		UTConut();
		S=(S_bak1+S_bak2+S)/3;
		delay_ms(2);
		for(ti=0;ti<3;ti++)
		{
			UTDisplay();
		}
		while((S/1000!=0)||((S/100)%10!=0)||(((S/10)%10*10+S%10)>18))
		{
			MotorFront();
			UTConut();
			S_bak1=S;
			UTConut();
			S_bak2=S;
			UTConut();
			S=(S_bak1+S_bak2+S)/3;
			UTDisplay();
		}
		Trick();
	}
}