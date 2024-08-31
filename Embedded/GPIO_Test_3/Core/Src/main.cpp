#include "main.h"
#include "Output.h"

int main()
{
	// 1- Enable clock gating for GPIOA and GPIOB
	RCC->APB2ENR = (1<<2) | (1<<3);
	//RCC register is a struct where ABP2ENR register exists, set the bit 2 & 3 to high for Ports A and B enabling
	// 2- Configure PA1 to be output Pin (in both mode and configuration)
	GPIOA->CRL = (3<<4);
	// GPIO register is a struct where CRL exists, 0011 (decimal 3) starting from bit 4 in the GPIO_CRL
	// same for PB4 (Input pull up) (0100) (floating input) (16/4 for pin 4)
	GPIOB->CRL = (4<<16);

	Output green_led(GPIOA,2);

	while (1)
	{
		auto btn_value = GPIOB->IDR & (1<<4); //4 is pin number
		// note that btn is active low (pull up resistor)
		if (btn_value == 0)
		{
		GPIOA->ODR=(1<<1);// I think below line can replace this line
		green_led.On();
		}
		else
		{
			GPIOA->ODR = 0x0000;// I think also below line can replace this line
			green_led.Off();
		}
	}
	return 0;
}
