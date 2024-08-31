/*
 * input.h
 *
 *  Created on: Aug 30, 2024
 *      Author: dell
 */

#ifndef INC_INPUT_H_
#define INC_INPUT_H_
#include "main.h"

static constexpr uint32_t INPUT_FLOATING = 4;
static constexpr uint32_t BITS_PER_PIN = 4;
static constexpr uint32_t BITS_PER_REGISTER = 32;
static constexpr uint32_t PINS_PER_REGISTER = 8;
class Input
{
public:
	Input(GPIO_TypeDef * GPIO,uint8_t pin) ;

	~Input();
uint32_t GetStatus();
private:
GPIO_TypeDef * port_;
uint8_t pin_;
};



#endif /* INC_INPUT_H_ */
