/*
 * robot.cpp
 *
 *  Created on: Aug 24, 2024
 *      Author: dell
 */
#include "robot.h"
	Robot::Robot(Motor * m1, Motor * m2)
	{
		m1->Stop();
		m2->Stop();
	}
	void Robot::forward()
	{
		m1->CW();
		m2->CCW();
	}
	void Robot::backward()
	{
		m1->CCW();
		m2->CW();
	}
	void Robot::left()
	{
		m1->CCW();
		m2->Stop();
	}
	void Robot::right()
	{
		m1->Stop();
		m2->CW();
	}


