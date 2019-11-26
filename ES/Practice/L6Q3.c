#include <LPC17xx.h>
unsigned int i,j,k;
unsigned long LED = 0x00000010,DEL;


int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &=0XFF000FF;
	LPC_GPIO0->FIODIR |=0XFF0;
	while(1)
	{
		LED = 0X00000E20;
		for(i=1;i<9;i++)
		{
			LPC_GPIO0->FIOPIN=LED;			
			for(j=0;j<100000;j++);
			DEL=LED<<1;
			DEL &= 0x1000;
			DEL >>= 8;
			LED <<=1;
			LED &=0XFF0;
			LED |=DEL;	
		}
	}
}