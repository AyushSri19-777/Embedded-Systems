#include <LPC17XX.H>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RS 27
#define E 28
#define DT 23
unsigned long x,y,temp,t1=0,t2=0;
unsigned int channel,result,i,flag,flag2,temp1,temp2,col,key,row,flag1,j;;
unsigned char command[]={0x30,0x30,0x30,0x20,0x28,0x0C,0X06,0X01,0X80};
unsigned char msg[16];
void lcd_write(void);
void port_write(void);
void scan(void);
void display(void);
void delay(unsigned int );
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_SC->PCONP=1<<12;
	LPC_PINCON->PINSEL3=(0XF<<28);
	LPC_GPIO0->FIODIR=(1<<RS|1<<E|0XF<<DT);
	LPC_ADC->ADCR=(1<<4|1<<5|1<<16|1<<21);
	LPC_ADC->ADINTEN=(1<<4|1<<5);
	LPC_PINCON->PINSEL1=00;
	
	for(j=0;j<9;j++)
		{
			temp1=command[j];
			lcd_write();
		}
		flag1=1;
		j=0;
	NVIC_EnableIRQ(ADC_IRQn);
	while(1);
}
void ADC_IRQHandler(void)
{

		x=LPC_ADC->ADSTAT&(3<<4);	
		if(x==(x&1<<4))
		{
			t1=LPC_ADC->ADDR4&(0XFFF<<4);
		}
		else if(x==(x&3<<4))
		{
			t2=LPC_ADC->ADDR5&(0XFFF<<4);
		}
		y=LPC_ADC->ADGDR;
		if((t1>>4)!=0)
		{
			t1>>=4;
			t1=ceil((t1*3.3)/4096);
		}
		t2>>=4;
		
		t2=ceil((t2*3.3)/4096);
		result=abs(t1-t2);
		sprintf(msg,"The Voltage Diff %dV",result);
		flag1=1;
		while(msg[j]!='\0')
		{
			temp1=msg[j];
			lcd_write();
			j++;
		}
		
		}

void lcd_write()
{
	flag2=(flag1==1)?0:((temp1==0x30)||(temp1==0x20))?1:0;
	temp2=temp1&0xF0;
	temp2>>=4;
	port_write();
		if(!flag2)
		{
			temp2=temp1&0x0F;
			port_write();
		}
		delay(30000);
	}

void port_write()
{
	LPC_GPIO0->FIOPIN=0;
	LPC_GPIO0->FIOPIN=temp2<<DT;
	if(flag1==0)
	LPC_GPIO0->FIOCLR=1<<RS;
	else
	LPC_GPIO0->FIOSET=1<<RS;
	LPC_GPIO0->FIOSET=1<<E;
	delay(25);
	LPC_GPIO0->FIOCLR=1<<E;
	delay(4000);
}
void delay(unsigned int n)
{
	for(i=0;i<n;i++);
	return;
}