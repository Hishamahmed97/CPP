/*
 * output.cpp
 *
 *  Created on: Aug 30, 2024
 *      Author: dell
 */

#include "Output.h"

uint8_t Output::output_counter = 0;
Output::Output(GPIO_TypeDef * GPIO, uint8_t pin) : port_{GPIO}, pin_{pin}
	{
		Off();
		//below if to configure the 4 bits for output
		if (output_counter ==0)
		{
			port_->CRL = 0x00000000;
			port_->CRH = 0x00000000;
		}
		output_counter++;
				if(pin_<PINS_PER_REGISTER)
				{
					port_->CRL |= (OUTPUT_HIGH_SPEED<<pin_*BITS_PER_PIN);
					//e.g.: PA1 will OUTPUT HIGH will be (3<<1*4);
				}
				else
				{
					port_->CRH |= (OUTPUT_HIGH_SPEED<<(pin_*BITS_PER_PIN-BITS_PER_REGISTER));
				}
	}
	Output::~Output()
		{
			Off();
		}

	void Output::On()
		{
			port_->ODR |= (1<<pin_); //This is the way for setting bit high keeping the value in other bits in the register
		}

		void Output::Off()
		{
			port_->ODR &=~(1<<pin_); //This is the way we clear certain bit keeping value in other bits in the register
		}

		void Output::Toggle()
		{
			port_->ODR ^= (1<<pin_);//This is the way to toggle certain bit
		}



