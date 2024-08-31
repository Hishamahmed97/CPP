/*
 * Motor.h
 *
 *  Created on: Aug 23, 2024
 *      Author: dell
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_
#include "output.h"

struct MotorConfig
{
	Output in1;
	Output in2;
	Output en;
};

struct Motor
{
	Motor(MotorConfig * config);

	void CW();

	void CCW();

	void Stop();

	MotorConfig * config_;
};

#endif /* INC_MOTOR_H_ */
