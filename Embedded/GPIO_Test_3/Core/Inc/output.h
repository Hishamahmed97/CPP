/*
 * output.h
 *
 *  Created on: Aug 30, 2024
 *      Author: dell
 */

#ifndef INC_OUTPUT_H_
#define INC_OUTPUT_H_
#include "main.h"

static constexpr uint32_t OUTPUT_HIGH_SPEED = 3;
static constexpr uint32_t BITS_PER_PIN = 4;
static constexpr uint32_t BITS_PER_REGISTER = 32;
static constexpr uint32_t PINS_PER_REGISTER = 8;

class Output
{
public:
	Output(GPIO_TypeDef * GPIO, uint8_t pin);
	~Output();
	void On();
	void Off();
	void Toggle();
private:
	GPIO_TypeDef * port_;
	uint8_t pin_;
	static uint8_t output_counter;
};



#endif /* INC_OUTPUT_H_ */
