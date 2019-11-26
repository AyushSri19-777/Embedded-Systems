#include <LPC17XX.H>
unsigned long count,x;
int main(void)
{
	LPC_PINCON->PINSEL0&=0XFF0000FF;
	LPC_GPIO0->FIODIR|=(0XFF<<4);
	LPC_PINCON->PINSEL2&=0X00;
	LPC_GPIO2->FIODIR|=(00<<12);
	while(1)
	{
		x=LPC_GPIO2->FIOPIN&(1<<12);
		if(x)
		{
			count++;
			LPC_GPIO0->FIOPIN=count<<4;
		}
	}
}