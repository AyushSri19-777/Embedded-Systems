#include <LPC17XX.h>
#define E 28
#define RS 27
#define DT 23
void lcd_write(void);
void port_write(void);
void delay(unsigned int);
unsigned char commands[]={0x30,0x30,0x30,0x20,0x28,0x0C,0x06,0X01,0X08};
unsigned char msg[]={"Ayush is here"};
unsigned int i=0,j=0;
unsigned long temp1,temp2,flag1,flag2;
int main(void)
{
	LPC_PINCON->PINSEL1&=0xFC003FFF;
	LPC_GPIO0->FIODIR=(1<<E|1<<RS|0XF<<DT);
	flag1=0;
	for(j=0;j<9;j++)
	{
		temp1=commands[j];
		lcd_write();
	}
	flag1=1;
	j=0;
	while(msg[j]!='\0')
	{
		temp1=msg[j];
		lcd_write();
	}
}
void lcd_write(void)
{
	flag2=(flag1==1)?0:(temp1==0x30||temp1==0x20)?1:0;
	temp2=temp1>>4;
	port_write();
	if(!flag2)
	{
		temp2=temp1&0xF;
		port_write();
		j++;
	}
	//delay(30000);
}
void port_write(void)
{
	LPC_GPIO0->FIOPIN=0;
	LPC_GPIO0->FIOSET=temp2<<DT;
	if(flag1==0)
		LPC_GPIO0->FIOCLR=(1<<RS);
	else
		LPC_GPIO0->FIOSET=1<<RS;
	LPC_GPIO0->FIOSET=1<<E;
	//delay(25);
	LPC_GPIO0->FIOCLR=1<<E;
	//delay(1000);
}