#include "reg52.h"
#include "head.h"
#include "mylib.h"
#include "UT.h"
#include "LCD.h"
#include <intrins.h>

 void  UTStart() 		      //启动测距信号
 {
	  TRIG=1;			                
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  TRIG=0;
  }

/*
void  UTStart(void) 		      //启动测距信号
{
	 TRIG=1;			                
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_();
	 _nop_(); 
	 _nop_(); 
	 _nop_(); 
	 _nop_();
	 TRIG=0;
}


unsigned long UTConut(void)		   //计算距离
{
	unsigned long S=0;
	unsigned int time=0;
	TMOD=0X11;
	TH1=0XFc;	  //1Ms定时
	TL1=0X18;
	TH0=0;
	TL0=0;  
	TR1= 1;
	ET1= 1;
	ET0= 1;
	EA = 1;
  while(!ECHO);		       //当RX为零时等待
	TR0=1;			       //开启计数
	while(ECHO);			   //当RX为1计数并等待
	TR0=0;				   //关闭计数
	time=TH0*256+TL0;		   //读取脉宽长度
	TH0=0;
	TL0=0;
	S=(time*1.7)/100;  
	return S;
}

*/
/*
void UTDisplay()
{
	unsigned long num;
	u8 N4,N3,N2,N1;
  UTStart();
	num=UTConut();
	N4=num/1000;
	N3=(num/100)%10;
	N2=(num/10)%10;
	N1=num%10;
	Display_SMG(N4,N3,N2,N1);
}
*/