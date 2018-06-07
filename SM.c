#include "SM.h"

void SMCenter()
{
	u8 i;
	u16 t1,t2;
	for(i=0;i<10;i++)
	{
	for(t1=0;t1<170;t1++)//0.00979818us
	{
		SM=1;
	}
	for(t2=0;t2<2760;t2++)//0.00980907us
	{
		SM=0;
	}
	}
}

void SMRight()
{
	u8 i;
	u16 t1,t2;
	for(i=0;i<10;i++)
	{
	for(t1=0;t1<75;t1++)//0.00979818us
	{
		SM=1;
	}
	for(t2=0;t2<2930;t2++)//0.00980907us
	{
		SM=0;
	}
	}
}

void SMLeft()
{
	u8 i;
	u16 t1,t2;
	for(i=0;i<10;i++)
	{
	for(t1=0;t1<380;t1++)//0.00979818us
	{
		SM=1;
	}
	for(t2=0;t2<2630;t2++)//0.00980907us
	{
		SM=0;
	}
	}
}