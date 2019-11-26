#include <LPC17xx.h>
unsigned int temp,i;
unsigned long x,y;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_SC->PCONP=1<<12;
	LPC_ADC->ADCR=(1<<4|1<<16|1<<21);
	LPC_ADC->ADINTEN=(1<<4);
	LPC_PINCON->PINSEL0&=0XFF0000FF;
	LPC_GPIO0->FIODIR=(0XFF<<4);
	LPC_PINCON->PINSEL3=0XFFC03FFF;
	LPC_GPIO1->FIODIR=(0XF<<23);
	NVIC_EnableIRQ(ADC_IRQn);
	while(1);
}
void ADC_IRQHandler()
{
	x=LPC_ADC->ADGDR&(0XFFF<<4);
	x>>=4;
	y=x/512;
	if(y>0)
	{
		LPC_GPIO1->FIOSET=0<<23;
		temp=0x06;
		LPC_GPIO0->FIOSET=temp<<4;
	}
	if(y>=1)
	{
		LPC_GPIO1->FIOSET=0<<23;
		temp=0x60;
		LPC_GPIO0->FIOSET=temp<<4;
	}
	if(y>=2)
	{
		LPC_GPIO1->FIOSET=1<<23;
		temp=0x06;
		LPC_GPIO0->FIOSET=temp<<4;
	}
	if(y>=3)
	{
		LPC_GPIO1->FIOSET=1<<23;
		temp=0x60;
		LPC_GPIO0->FIOSET=temp<<4;
	}
	if(y>=4)
	{
		LPC_GPIO1->FIOPIN=2<<23;
		temp=0x06;
		LPC_GPIO0->FIOSET=temp<<4;
	}
	if(y>=5)
	{
		LPC_GPIO1->FIOSET=2<<23;
		temp=0x60;
		LPC_GPIO0->FIOSET=temp<<4;
	}
	if(y>=6)
	{
		LPC_GPIO1->FIOSET=3<<23;
		temp=0x06;
		LPC_GPIO0->FIOSET=temp<<4;
	}
	if(y>=7)
	{
		LPC_GPIO1->FIOPIN=3<<23;
		temp=0x60;
		LPC_GPIO0->FIOSET=temp<<4;
	}	
	for(i=0;i<500;i++);
	LPC_GPIO0->FIOPIN=00<<4;
}


	