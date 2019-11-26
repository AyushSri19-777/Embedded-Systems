#include <LPC17XX.H>
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL4=01<<20;
	LPC_GPIO0->FIODIR|=01<<11;
	LPC_SC->EXTMODE=0X1;
	LPC_SC->EXTPOLAR=0X1;
	NVIC_EnableIRQ(EINT0_IRQn);
	while(1);
}
void EINT0_IRQHandler(void)
{
	LPC_SC->EXTINT=0X1;
	LPC_GPIO0->FIOPIN=~LPC_GPIO0->FIOPIN;
}