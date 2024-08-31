/*
 * Motor.cpp
 *
 *  Created on: Aug 23, 2024
 *      Author: dell
 */
#include"Motor.h"

	Motor::Motor(MotorConfig * config) : config_{config}
	{
		config_->in1.Off();
		config_->in2.Off();
		config_->en.Off();
	}

	void Motor::CW()
	{
		config_->in1.On();
		config_->in2.Off();
		config_->en.On();
	}
	void Motor::CCW()
		{
		config_->in1.Off();
		config_->in2.On();
		config_->en.On();
		}
	void Motor::Stop()
			{
			config_->in1.Off();
			config_->in2.Off();
			config_->en.Off();
			}



