#include "main.h"
#include "delay.h"
#include "output.h"
unsigned int counter;

int main()
{
	RCC->APB2ENR |= (1<<4); //RCC enable for GPIOC
	//Configure the whole port to be output Pins (in both mode and configuration)
	GPIOC->CRH = 0x33333333;
	Output green_led(GPIOC,13); //check the 13
	DelayInit();

	while(1)
	{
		GPIOC->ODR &=~(1<<13);//below can replace this line
		green_led.Off();
		DelayMs(1000);
		GPIOC->ODR |= (1<<13);//below can replace this line
		green_led.On();
		DelayMs(1000);
	}
	return 0;
}
