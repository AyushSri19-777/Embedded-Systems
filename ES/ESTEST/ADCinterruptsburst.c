#include <LPC17XX.h>
#include <math.h>
unsigned long x;
float y;
void display(unsigned long);
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL3=3<<28;
	LPC_ADC->ADCR=(1<<4|1<<21|1<<16);
	LPC_ADC->ADINTEN=1<<4;
	NVIC_EnableIRQ(ADC_IRQn);
	while(1);	
}
void ADC_IRQHandler()
{
	x=LPC_ADC->ADGDR&0XFFF<<4;//reading value didn't change the DONE bit to 0
	x>>=4;
	display(x);
}
void display(unsigned long x)
{
	//x>>=4;
	y=(x*3.3)/4096;
	y=ceil(y);
}