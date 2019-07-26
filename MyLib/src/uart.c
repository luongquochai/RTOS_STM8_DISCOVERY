#include "uart.h"

void UART_Init(void)
{
	UART->BRR1 = 0x68;
	UART->BRR2 = 0x03; //9600 Baudrate

	UART->CR1 &= ~((1<<4)|(1<<5)); //8 data bit + UART enable
	UART->CR3 &= ~(3<<4); // 1 stop bit

	UART->CR2 |= (1<<3); // Transmitter Enable
	UART->CR2 |= (1<<2); // Receiver Enable
	UART->CR2 |= (1<<5); // Receiver Interrupt Enable
       // UART->CR2 |= (1<<7); //Transmitter interrupt enable

}

void UART_Transmit(char data)
{
	while(!(UART->SR & (1<<7)));
	UART->DR = data;
}
void UART_SendString(char *data)
{
	register unsigned i = 0;
	while (data[i]){
		UART_Transmit(data[i]);
		i++;
	}
}


/*NOTED:register gives the compiler a hint to place the variable in a register instead of memory/stack space.
 In some cases, there won't be enough registers for every variable you place this keyword on so placing it
 on too many variables can force some of the others out of registers again.*/