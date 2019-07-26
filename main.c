#include "stm8l_define.h"
#include "gpio.h"
#include "uart.h"

/*      Timer1 register definitions
 *---------------------------------------------------------------------------*/
#define TIM1_CR1 (*(volatile uint8_t *)0x52b0)
#define TIM1_PCNTRH (*(volatile uint8_t *)0x52bf)
#define TIM1_PCNTRL (*(volatile uint8_t *)0x52c0)
#define TIM1_PSCRH (*(volatile uint8_t *)0x52c1)
#define TIM1_PSCRL (*(volatile uint8_t *)0x52c2)
#define TIM1_ARRH (*(volatile uint8_t *)0x52c3)
#define TIM1_ARRL (*(volatile uint8_t *)0x52c4)
#define TIM1_IER (*(volatile uint8_t *)0x52B5)
#define TIM1_SR1 (*(volatile uint8_t *)0x52B6)

/* TASK: BLINKING LED WITHOUT USING RTOS, CONTROL 2 LEDs*/

void CLK_config(void);
void TIM1_config(void); 

int main( void )
{
   //config led pins
  GPIOE->DDR = 0x80;
  GPIOE->CR1 = 0x80;
  
  GPIOC->DDR = 0x80;
  GPIOC->CR1 = 0x80;
  
  //PC1 input with pull-up
  GPIOC->CR1 |= 0x02;
  GPIOC->CR2 |= 0x02;
  EXTI->CR1 |= 0x08; //interrupt external portc c pin 1
  
  CLK_config();
  TIM1_config();
  TIM1_IER = 0x01; //enable interrupt timer1
  
  asm("rim\n");
  TIM1_CR1 = 0x01;
  while(1)
  {
  }
  
}
void CLK_config(void)
{
  /*Set the frequency to 16/128=0,125 MHz */
  CLK->DIVR = 0x07;
  CLK->PCKENR2 |= 0x02;
}
void TIM1_config(void)
{
  TIM1_PSCRH = 0x00;
  TIM1_PSCRL = 0x28;
  
  TIM1_ARRH = 0x0c; // count from 0 -3125
  TIM1_ARRL = 0x35;
  
  TIM1_IER = 0x01;
}

#pragma vector = 25
__interrupt void TIM1_int_handler(void)
{
  GPIOE->ODR ^= 0x80;
  TIM1_SR1 = 0x02;

}
#pragma vector = 11
__interrupt void EXTI1_int_handler(void)
{
  GPIOE->ODR ^= 0x80;
  EXTI->SR1 = 0x02;
}

