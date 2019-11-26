#include <LPC17XX.h>
#include <math.h>
unsigned long x;
float y;
void display(unsigned long);
int main(void)
{
	LPC_PINCON->PINSEL3=3<<28;
	LPC_ADC->ADCR=(1<<4|1<<21|1<<24);
	while(1)
	{
		while(!(LPC_ADC->ADGDR&0X1<<31));
		x=LPC_ADC->ADGDR&0XFFF<<4;//reading value didn't change the DONE bit to 0
		x>>=4;
		display(x);
		//call lcd display for x and y both
		
	}
}
void display(unsigned long x)
{
	//x>>=4;
	y=(x*3.3)/4096;
	y=ceil(y);
}
		