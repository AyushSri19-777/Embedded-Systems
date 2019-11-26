#include <LPC17XX.H>
#define RS 27
#define E 28
#define DT 23
unsigned char command[]={0x30,0x30,0x30,0x20,0x28,0x0C,0X06,0X01,0X80};
unsigned int i,flag,flag2,temp1,temp2,temp,col,key,row,x,flag1,j;
unsigned char msg[2];
void lcd_write(void);
void port_write(void);
void scan(void);
void display(void);
void delay(unsigned int );
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL1=00;
	LPC_GPIO0->FIODIR=(1<<RS|1<<E|0XF<<DT);
	LPC_PINCON->PINSEL3&=0xFFC03FFF;
	LPC_PINCON->PINSEL4&=0XF00FFFFF;
	LPC_GPIO1->FIODIR|=0<<23;
	LPC_GPIO2->FIODIR|=0XF<<10;
	while(1)
	{
		for(row=0;row<4;row++)
		{
			LPC_GPIO2->FIOPIN=1<<(row+10);
			flag=0;
			scan();
			if(flag==1)
				key=(row*4)+col;
			display();
		}
	}
}
void scan(void)
{
	x=LPC_GPIO1->FIOPIN&=0XF<<23;
	if(x)
	{
		flag=1;
		x=x>>23;
		switch(x)
		{
			case 1:col=0;
				break;
			case 2:col=1;
				break;
			case 4:col=2;
				break;
			case 8:col=3;
				break;
		}
	}
}
void display(void)
{
	if(key<=9)
		msg[0]=key+0x30;
	else
		msg[0]=key+0x37;
	msg[1]='\0';
	flag1=0;
	for(j=0;j<9;j++)
	{
		temp1=command[j];
		lcd_write();
	}
	flag1=1;
	j=0;
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
	{
		if(!flag2)
		{
			temp2=temp1&0x0F;
			port_write();
		}
		delay(30000);
	}
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
	
	