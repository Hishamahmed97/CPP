/*
 * robot.h
 *
 *  Created on: Aug 24, 2024
 *      Author: dell
 */

#ifndef INC_ROBOT_H_
#define INC_ROBOT_H_
#include "Motor.h"
class Robot
{
public:
	Robot(Motor * m1, Motor * m2);
	void forward();
	void backward();
	void left();
	void right();
private:
	Motor *m1;
	Motor *m2;
};



#endif /* INC_ROBOT_H_ */
