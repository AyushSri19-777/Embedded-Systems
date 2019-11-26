#include <LPC17XX.H>
unsigned int dig_sel=0;
unsigned long x,y,z,k;
void display(void);
int main(void)
{
	LPC_PINCON->PINSEL0&=0XFF0000F;
	LPC_GPIO0->FIODIR=(0XFF<<4);
	LPC_PINCON->PINSEL3&=0XFFC03FFF;
	LPC_GPIO1->FIODIR=0XF<<23;
	LPC_ADC->ADCR=(1<<21|1<<16|1<<4);
	LPC_ADC->ADINTEN=(1<<4);
	NVIC_EnableIRQ(ADC_IRQn);
	while(1);
}
void ADC_IRQHandler()
{
	x=LPC_ADC->ADGDR&(0XFFF0);
	x>>=4;
	y=x/1024;
	k=x-1024*y;
	if(k>0)
		y++;
	while(dig_sel<=y)
	{
		dig_sel++;
		display();
		//delay(21)
	}
	dig_sel=0;
}
void display(void)
{
	z=x/512;
	switch(dig_sel)
	{
		case 1:LPC_GPIO1->FIOPIN=03<<23;
					break;
		case 2:LPC_GPIO1->FIOPIN=02<<23;
					break;
		case 3:LPC_GPIO1->FIOPIN=01<<23;
					break;
		case 4:LPC_GPIO1->FIOPIN=00<<23;
					break;
	}
	if(z>0&&dig_sel==1)
	{
		LPC_GPIO0->FIOPIN=0X30<<4;
		//delay(21);
		//LPC_GPIO0->FIOPIN=0X00;
	}
	if(z>1&&dig_sel==1)
	{
		LPC_GPIO0->FIOPIN=0X36<<4;
	}
	if(z>2&&dig_sel==2)
	{
		LPC_GPIO0->FIOPIN=0X30<<4;
	}
	if(z>3&&dig_sel==2)
	{
		LPC_GPIO0->FIOPIN=0X36<<4;
	}
	if(z>4&&dig_sel==3)
	{
		LPC_GPIO0->FIOPIN=0X30<<4;
	}
	if(z>5&&dig_sel==3)
	{
		LPC_GPIO0->FIOPIN=0X36<<4;
	}
	if(z>6&&dig_sel==4)
	{
		LPC_GPIO0->FIOPIN=0X30<<4;
	}
	if(z>7&&dig_sel==4)
	{
		LPC_GPIO0->FIOPIN=0X36<<4;
	}
}
