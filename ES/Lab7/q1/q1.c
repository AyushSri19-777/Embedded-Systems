#include <LPC17xx.h>
#include <stdio.h>
#define FIRST_SEG 0xF87FFFFF
#define SECOND_SEG 0xF8FFFFFF
#define THIRD_SEG 0xF97FFFFF
#define FOURTH_SEG 0xF9FFFFFF
#define DISABLE_ALL 0xFA7FFFFF
unsigned int dig1=0x9,dig2=0x9,dig3=0x9,dig4=0x9;
unsigned int twenty_count = 0x00,dig_count=0x00,temp1=0x00;
unsigned char array_dec[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char tmr0_flg = 0x00,one_sec_flg = 0x00;
unsigned long int temp2 = 0x00000000,i=0,x,c=0;
unsigned int temp3=0x00;
void Delay(void);
void Display(void);
void timer_init(void);
int main(void)
{
SystemInit();
SystemCoreClockUpdate();
	timer_init();
LPC_PINCON->PINSEL0 &= 0x3F0000FF; 
//GPIO data lines
LPC_PINCON->PINSEL3 &= 0xFFC03FFF;
//GPIO enable lines
LPC_GPIO0->FIODIR |= 0x00000FF0; 
LPC_GPIO1->FIODIR |= 0x07800000; 
while(1)
{
dig_count +=1;
if(dig_count == 0x05)
{ dig_count = 0x00;
//one_sec_flg =0xFF;
}
if(one_sec_flg == 0xFF)
{
one_sec_flg = 0x00;
dig1 -=1;
if(dig1 == -1)
{
dig1 = 9;
dig2 -=1;
if(dig2 == -1)
{
dig2 = 9;
dig3-=1;
if(dig3 == -1)
{
dig3 = 9;
dig4 -= 1;
if(dig4 == -1)
{
dig4 = 9;
} 
} 
} 
} 
} 
Display();
Delay();
}} 
void Display(void) //To Display on 7-segments
{
if(dig_count == 0x01) // For Segment U8
{
temp1 = dig1;
LPC_GPIO1->FIOPIN = FIRST_SEG;
}
else if(dig_count == 0x02) // For Segment U9
{
temp1 = dig2;
LPC_GPIO1->FIOPIN = SECOND_SEG;
}
else if(dig_count == 0x03) // For Segment U10
{
temp1 = dig3;
LPC_GPIO1->FIOPIN = THIRD_SEG;
}
else if(dig_count == 0x04) // For Segment U11
{
temp1 = dig4;
LPC_GPIO1->FIOPIN = FOURTH_SEG;
}
temp1 &= 0x0F;
temp2 = array_dec[temp1]; // Decoding to 7-segment
temp2 = temp2 << 4;
LPC_GPIO0->FIOPIN = temp2; // Taking Data Lines for 7-Seg
for(i=0;i<500;i++);
LPC_GPIO0->FIOCLR = 0x00000FF0;
// LPC_GPIO1->FIOPIN = DISABLE_ALL;//disable all the segments
}
void Delay(void)
{ 
while(!(LPC_TIM0->EMR&0X01));
	LPC_TIM0->EMR=0x20;
if(twenty_count ==1000) //multiplied by 500x2msec for
//1 Sec
{
one_sec_flg = 0xFF;
twenty_count = 0x00;
	}
	else twenty_count += 1;
}
void timer_init(){
	LPC_TIM0->CTCR=0;
	LPC_TIM0->TCR=2;
	LPC_TIM0->MR0=999;
	LPC_TIM0->MCR=0x2;
	LPC_TIM0->EMR=0x20;
	LPC_TIM0->PR=2;
	LPC_TIM0->TCR=1;
}
