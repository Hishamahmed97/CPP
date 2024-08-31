/*
 * Uart.h
 *
 *  Created on: Aug 31, 2024
 *      Author: dell
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include "main.h"

#define FOSC 8000000 //frequency oscillator
#define BAUD 9600

//Belwo addresses based on advanced periph. brdige, bus 2 and Uart periphral
enum UARTInstance : uint32_t //to limit enum size to 32 bits
{
	UART1Instance = 0x40013800,
	UART2Instance = 0x40014400,
	UART3Instance = 0x40014800
};

class UART
{
public:
	UART()
	{
		//for the current pointer which points to instance of uart
		// if it equals to uart1instance (after casting) then
		//initialize uart1
		if(this == reinterpret_cast<UART*>(UART1Instance))
		{
			UART1_Initialize();
		}

	}

	void UART1_Initialize()
	{
		//Enable RCC for GPIOA (bit 2) where UART1 connected, then for UART itself (bit 14)
						// then enable AFIO (bit 0)
							RCC->APB2ENR = (1<<2) | (1<<14) | (1<<0);
							//Now configure PA9 to be output alternate for UART trans
							GPIOA->CRH = (11<<4);//1011 on bit 4 for pin 9
							//Now configure PA10 to be input floating for Uart receive
							GPIOA->CRH |= (4<<8); //0100

							double usart_div = FOSC / (BAUD);
							USART1->BRR = usart_div;
							//Enable transmission and reception
							USART1->CR1 = (1<<2) | (1<<3);
							USART1->CR1 |= (1<<13);
	}



	char read()
	{
		while(!(SR&(1<<5))); //flag for receive not empty
		return DR & 0x00FF; //masking for 1st 8 bits
	}
	void sendChar(char data)
	{
		DR = data;
	}
	void sendString(char * data)
	{
		auto i{0};
		while (data[i] !='\0')
		{
			sendChar(data[i]);
			i++;
		}

	}
	//we can make function overloading  for the above two functions
	//below is the operator overloading for new
	void * operator new(size_t, UARTInstance uart)
	{
		//since uart is address, we need to cast it as below to be void pointer (generic)
		return reinterpret_cast<void*>(uart);
	}
private:
	//registers (should be orderd)
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
	uint32_t GPTR;
};



#endif /* INC_UART_H_ */
