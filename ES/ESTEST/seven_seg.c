#include <LPC17xx.H>
unsigned char seven_seg[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned int dig_sel,dig0=1,dig1=3,dig2=5,dig3=4,temp,i;
void display(void);
void delay(unsigned int);
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0&=0XFF0000FF;
	LPC_PINCON->PINSEL3&=0XFFC03FFF;
	LPC_GPIO0->FIODIR|=0XFF0;
	LPC_GPIO1->FIODIR|=0X07800000;
	while(1)
	{
		dig_sel++;
		if(dig_sel==5)
			dig_sel=0;
		display();
	}
}
void display(void)
{
	if(dig_sel==1)
	{
		LPC_GPIO1->FIOPIN=00<<23;
		temp=dig0;
	}
	else if(dig_sel==2)
	{
		LPC_GPIO1->FIOPIN=01<<23;
		temp=dig1;
	}
	else if(dig_sel==3)
	{
		LPC_GPIO1->FIOPIN=02<<23;
		temp=dig2;
	}
	else
	{
		LPC_GPIO1->FIOPIN=03<<23;
		temp=dig3;
	}
	LPC_GPIO0->FIOPIN=seven_seg[temp]<<4;
	delay(21);
	LPC_GPIO0->FIOPIN=00<<4;
}
void delay(unsigned int x)
{
	for(i=0;i<x;i++);
}

	
	

