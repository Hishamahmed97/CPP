/*
 * Input.cpp
 *
 *  Created on: Aug 30, 2024
 *      Author: dell
 */
#include "Input.h"

Input::Input(GPIO_TypeDef * GPIO,uint8_t pin) : port_{GPIO} , pin_{pin}
	{
		//below if to configure the 4 bits for input
						if(pin_<PINS_PER_REGISTER)
						{
							port_->CRL |= (INPUT_FLOATING<<pin_*BITS_PER_PIN);
							//e.g.: PB4 will OUTPUT HIGH will be (4<<4*4);
						}
						else
						{
							port_->CRH |= (INPUT_FLOATING<<(pin_*BITS_PER_PIN-BITS_PER_REGISTER));
						}
	}

Input::~Input()
{

}
uint32_t Input::GetStatus()
{
	return port_->IDR & pin_;
}





