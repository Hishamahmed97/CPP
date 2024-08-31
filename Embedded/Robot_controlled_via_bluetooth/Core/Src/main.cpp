#include "Motor.h"
#include "robot.h"
MotorConfig M1_config
{
	{GPIOA, 5},
	{GPIOB, 1},
	{GPIOA, 6}
};

MotorConfig M2_config
{
	{GPIOA, 4},
	{GPIOA, 0},
	{GPIOB, 0}
};
int main()
{
	// Enable clock gating
	//RCC register is a struct where ABP2ENR exists, set the bit 2 & 3to high for Ports A and B enabling
			RCC->APB2ENR = (1<<2) | (1<<3);

			Motor M1(&M1_config);
			Motor M2(&M2_config);
			Robot robot(&M1, &M2);
	while (1)
	{
		robot.forward();
	}
	return 0;
}

