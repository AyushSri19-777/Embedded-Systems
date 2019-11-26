#include <LPC17xx.h>
unsigned int i,j,k;
unsigned long LED = 0x00000010,DEL;


int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &=0XFF0000FF;
	LPC_GPIO0->FIODIR |=0XFF0;
	while(1)
	{
		LED = 0X00000010;
		for(i=1;i<256;i++)
		{
			LPC_GPIO0->FIOPIN = LED;
			for(j=0;j<10000;j++);
			LED += 16;
		}
	}
}