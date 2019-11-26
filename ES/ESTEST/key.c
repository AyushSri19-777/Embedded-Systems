#include <LPC17XX.H>
void scan(void);
void display();
unsigned long x;
unsigned int row,col,flag,key;
int main(void)
{
	LPC_PINCON->PINSEL4&=0xF00FFFFF;
	LPC_GPIO2->FIODIR=0xF<<10;
	LPC_PINCON->PINSEL3&=0xFFC03FFF;
	LPC_GPIO1->FIODIR|=00;
	while(1)
	{
		for(row=0;row<4;row++)
		{
			LPC_GPIO2->FIOPIN=1<<(row+10);
			flag=0;
			scan();
			if(flag==1)
			{
				key=row*4+col;
				//display();
			}
		}
	}
}
void scan()
{
	
	x=LPC_GPIO1->FIOPIN&=(0XF<<23);
	if(x)
	{
		flag=1;
		x>>=23;
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