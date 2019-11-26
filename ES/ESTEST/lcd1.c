#include <LPC17XX.H>
#define E 28
#define RS 27
#define DT 23
unsigned char commands={0x30,0x30,0x30,0x20,0x28,0x0C,0X06,0X01,0X80};
unsigned char msg={"AYUSH"};
unsigned int flag1,flag2,i,j;
unsigned long temp1,temp2;
void delay(unsigned int);
void lcd_write(void);
void port_write(void);
int main(void)
{
	LPC_PINCON->PINSEL1&=0XFC003FFF;
	LPC_GPIO0->FIODIR=(1<<E|1<<RS|0XF<<DT);
	flag1=0;
	for(j=0;j<9;j++)
	{
		temp1=commands[j];
		lcd_write();
	}
	flag1=1;
	j=0;
	while(msg[j]!'\0')
	{
		temp1=msg[j++];
		lcd_write();		
	}	
}
void lcd_write()
{
	flag2=(flag1==1)?0:(temp1==0x30||temp1==0x20)?1:0;
	temp2=temp1>>4;
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
	LPC_GPIOO->FIOPIN=00;
	LPC_GPIO0->FIOPIN=temp2<<DT;
	if(flag1==0)
		LPC_GPIO0->FIOCLR=(1<<RS);
	else
		LPC_GPIO0->FIOSET=(1<<RS);
	LPC_GPIO0->FIOSET=1<<E;
	delay(25);
	LPC_GPIO0->FIOCLR=1<<E;
	delay(1000);
}