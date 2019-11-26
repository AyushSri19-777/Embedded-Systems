#include <LPC17XX.H>
#include <math.h>
unsigned long x,y,k,v;
float z;
void display(unsigned long);
int main(void)
{
	LPC_PINCON->PINSEL3=0xF<<28;
	LPC_ADC->ADCR=(1<<4|1<<21|1<<24|1<<5);
	while(1)
	{
		while((!(LPC_ADC->ADSTAT&(0X1<<4)))&&(!(LPC_ADC->ADSTAT&(0X1<<5))));
		k=LPC_ADC->ADGDR&0XFFF0;
		if(LPC_ADC->ADSTAT&0X1<<4)
		{
			k>>=4;
			display(x);
		}
		else
		{
			k>>=4;
			display(y);
		}
	}
}
void display(unsigned long v)
{
	z=(v*3.3)/4096;
}
	