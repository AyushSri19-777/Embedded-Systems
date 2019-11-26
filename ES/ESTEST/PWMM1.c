#include <LPC17XX.h>
unsigned char flag,flag1;
void PWM1_IRQHandler(void);
void pwm_init(void);
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL3=0x00008000;
	pwm_init();
	while(1);
}
void pwm_init(void)
{
	LPC_PWM1->CTCR=00;
	LPC_PWM1->TCR=0X2;
	LPC_PWM1->PCR=0X1000;	
	LPC_PWM1->MCR=0X03;	
	LPC_PWM1->MR0=40;
	LPC_PWM1->MR4=0X20;
	LPC_PWM1->LER=0XFF;
	LPC_PWM1->TCR=0X09;
	NVIC_EnableIRQ(PWM1_IRQn);
}
void PWM1_Handler()
{
	LPC_PWM1->IR = 0Xff;
	if(flag == 0x00)
	{
		LPC_PWM1->MR4+=100;
		LPC_PWM1->LER=0X11;
		if(LPC_PWM1->MR4 >=38)
		{
			flag1=0xff;
			flag=0xff;
			LPC_PWM1->LER=0X11;
		}
	}
	else if(flag1 == 0xff)
	{
		LPC_PWM1->MR4 -= 100;
		LPC_PWM1->LER=0XFF;
		if(LPC_PWM1->MR4 <= 5)
		{
			flag1=0x00;
			flag=0x00;
			LPC_PWM1->LER=0XFF;
		}
	}
}
		
