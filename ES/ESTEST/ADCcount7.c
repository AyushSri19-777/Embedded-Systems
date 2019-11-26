#include <LPC17XX.H>
unsigned char seven_seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned int dig_sel=0,count=0;
unsigned long x,y,i,k,s;
void display(void);
int main(void)
{
	/*LPC_SC->PCONP=1<<12;
	SystemInit();
	SystemCoreClockUpdate();*/
	LPC_PINCON->PINSEL0&=0xFF0000FF;
	LPC_GPIO0->FIODIR=(0XFF<<4);
	LPC_PINCON->PINSEL3&=0XFFC03FFF;
	LPC_GPIO1->FIODIR=(0XF<<23);
	LPC_PINCON->PINSEL4&=0XFCFFFFFF;
	LPC_GPIO2->FIODIR=00;//SWITCH AT 2.12
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
	k=x-(1024*y);
	if(k>0)
		y++;
	s=LPC_GPIO2->FIOPIN&(1<<12);
		if(s)
		{
			count=10;
		}
	/*while(dig_sel<=y)
	{
		dig_sel++;
		display();
		//delay(25);
	}
	dig_sel=0;*/
	display();
}
void display(void)
{
	switch(y)
	{
		case 0:LPC_GPIO1->FIOPIN=00<<23;
						break;
		case 1:LPC_GPIO1->FIOPIN=01<<23;
						break;
		case 2:LPC_GPIO1->FIOPIN=02<<23;
						break;
		case 3:LPC_GPIO1->FIOPIN=03<<23;
						break;
	}
	LPC_GPIO0->FIOPIN=seven_seg[count]<<4;
	for(i=0;i<25;i++);
	LPC_GPIO0->FIOPIN=00;
}
