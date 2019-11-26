#include <LPC17XX.H>
#include <stdlib.h>
#include <stdio.h>
#define RS 27
#define E 28
#define DT 23
unsigned char command[]={0x30,0x30,0x30,0x20,0x28,0x0C,0X06,0X01,0X80};
unsigned char str[]={"0123456"};
unsigned int i,j,flag1,flag2,temp1,temp2,f,x,k;
unsigned char msg[2];
void lcd_write(void);
void port_write(void);
void delay(unsigned int );
int main(void)
{
SystemInit();
SystemCoreClockUpdate();
LPC_PINCON->PINSEL1=00;
LPC_GPIO0->FIODIR=(1<<RS|1<<E|0XF<<DT);
flag1=0;
for(j=0;j<9;j++)
{
temp1=command[j];
lcd_write();
}
flag1=1;
j=0;

while(1)
{
x=LPC_GPIO2->FIOPIN&0X1<<12;
if(!x)
{
k=rand()%6;
k++;
msg[0]=str[k];
msg[1]='\0';
for(j=0;j<1;j++)
{ flag1=0;
temp1=0x01;
lcd_write();
flag1=1;
temp1=msg[j];
lcd_write();
}
    }
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
delay(1000);
}
void delay(unsigned int n)
{
for(i=0;i<n;i++);
return;
}