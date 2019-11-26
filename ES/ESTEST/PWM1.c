#include <LPC17xx.h>
unsigned int flag=0;
unsigned long x;
void pwm_init(void);
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL3 |= 0x00008000;
	LPC_PINCON->PINSEL0&=0XFFFFFCFF;
	pwm_init();
	while(1);
}
void pwm_init(void)
{
	LPC_PWM1->CTCR=00;
	LPC_PWM1->TCR=0X02;
	//LPC_PWM1->IR=0X100;
	LPC_PWM1->LER=0X11;
	LPC_PWM1->MCR=0X03;
	LPC_PWM1->MR0=30000;
	LPC_PWM1->MR4=0x100;
	LPC_PWM1->PCR=0x1000;		
	LPC_PWM1->TCR=0X09;
	NVIC_EnableIRQ(PWM1_IRQn);	
}
void PWM1_Handler()
{
	LPC_PWM1->IR=0x01;
	if(flag==0&&LPC_PWM1->MR4<=2700)
	{
		LPC_PWM1->MR4+=100;
		LPC_PWM1->LER=0X11;
		if(LPC_PWM1->MR4==0X2700)
		{
			flag=1;
			LPC_PWM1->LER=0X11;
		}
	}
	else if(flag==1&&LPC_PWM1->MR4>=500)
	{
		LPC_PWM1->MR4-=100;
		LPC_PWM1->LER=0X11;
		if(LPC_PWM1->MR4>=500)
		{
			flag=0;
			LPC_PWM1->LER=0X11;
		}
	}
}
	