#include <LPC17XX.H>
#include <math.h>
unsigned long x,y,k,diff;
float z;
void display(unsigned long);
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL3=0XF<<28;
	LPC_ADC->ADCR=(1<<4|1<<21|1<<24|1<<5);
	while(1)
	{
		while(!(LPC_ADC->ADDR4&0X1<<31)&&!(LPC_ADC->ADDR5&0X1<<31));
		k=LPC_ADC->ADGDR&0X4<<24;
		if(k==0X04000000)
		{
			x=LPC_ADC->ADDR4&0XFFF<<4;
			x>>=4;
			display(x);
		}
		else
		{
			y=LPC_ADC->ADDR5&0XFFF<<4;
			y>>=4;
			display(y);
		}
		diff=x-y;
	}
}
void display(unsigned long x)
{
	z=(x*3.3)/4096;
}
	