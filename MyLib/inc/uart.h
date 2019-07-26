#ifndef UART_H
#define UART_H

#include "stm8l_define.h"

#define Tx 3	//c3
#define Rx 2 	//C2

void UART_Init(void);
void UART_Transmit(char data);
void UART_Receive(char data);
void UART_SendString(char *data);

#endif