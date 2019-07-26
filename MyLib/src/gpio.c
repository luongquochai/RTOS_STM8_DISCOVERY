#include "stm8l_define.h"
#include "gpio.h"


void GPIO_DeInit(GPIO_TypeDef* GPIOx)
{
	GPIOx->CR2 = 0x00;
	GPIOx->ODR = 0x00;
	GPIOx->DDR = 0x00;
	GPIOx->CR1 = 0x00;
}
