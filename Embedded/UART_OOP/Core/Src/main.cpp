#include "Uart.h"

int main()
{
	// bluetooth is a pointer to instance of uart class
	// new create new instance in heap by default and call constructor for this class
	//so we will make placement new to create this instance in the required address for the Uart1  periphral
	// Now you need to make operator overloading for the new operator to make it accept input argument for address
	//finally we can pass the UART1Instance for the UART constructor to determine which Uart to initialize
	UART * bl_spp = new(UART1Instance) UART();
	while (1)
	{
		auto control = bl_spp->read();
		if(control == 'w')
		{
			bl_spp->sendString("LED ON");
		}
	}
return 0;
}
