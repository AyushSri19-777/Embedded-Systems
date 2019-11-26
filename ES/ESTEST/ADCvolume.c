#include <LPC17XX.H>
unsigned long x,y;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_SC->PCONP=1<<12;
	LPC_PINCON->PINSEL0&=0XFF0000FF;
	LPC_GPIO0->FIODIR=(0XFF<<4);
	LPC_ADC->ADCR=(1<<16|1<<21|1<<4);
	LPC_ADC->ADINTEN=(1<<4);
	NVIC_EnableIRQ(ADC_IRQn);
	while(1);
}
void ADC_IRQHandler()
{
	y=LPC_ADC->ADGDR&0XFFF0;
	y>>=4;
	x=y/512;
	switch(x)
	{
		case 0:LPC_GPIO0->FIOPIN=0X10;
			break;
		case 1:LPC_GPIO0->FIOPIN=0X30;
			break;
		case 2:LPC_GPIO0->FIOPIN=0X70;
			break;
		case 3:LPC_GPIO0->FIOPIN=0XF0;
			break;
		case 4:LPC_GPIO0->FIOPIN=0X1F0;
			break;
		case 5:LPC_GPIO0->FIOPIN=0X3F0;
			break;
		case 6:LPC_GPIO0->FIOPIN=0X7F0;
			break;
		case 7:LPC_GPIO0->FIOPIN=0XFF0;
			break;
	}
}