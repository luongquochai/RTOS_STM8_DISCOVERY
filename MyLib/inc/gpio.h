#ifndef GPIO_H
#define GPIO_H

/**
  * @brief General Purpose I/Os (GPIO)
  */
typedef struct GPIO_struct
{
  __IO uint8_t ODR; /*!< Output Data Register */
  __IO uint8_t IDR; /*!< Input Data Register */
  __IO uint8_t DDR; /*!< Data Direction Register */
  __IO uint8_t CR1; /*!< Configuration Register 1 */
  __IO uint8_t CR2; /*!< Configuration Register 2 */
}
GPIO_TypeDef;

/*Peripherals Base Address */
#define GPIOA_BASE                  (uint16_t)0x5000
#define GPIOB_BASE                  (uint16_t)0x5005
#define GPIOC_BASE                  (uint16_t)0x500A
#define GPIOD_BASE                  (uint16_t)0x500F
#define GPIOE_BASE                  (uint16_t)0x5014
#define GPIOF_BASE                  (uint16_t)0x5019
#define GPIOG_BASE                  (uint16_t)0x501E
#define GPIOH_BASE                  (uint16_t)0x5023
#define GPIOI_BASE                  (uint16_t)0x5028

/******************************************************************************/
/*                          Peripherals declarations                          */
/******************************************************************************/

#define GPIOA                       ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB                       ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC                       ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD                       ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE                       ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF                       ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG                       ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH                       ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI                       ((GPIO_TypeDef *) GPIOI_BASE)

void GPIO_DeInit(GPIO_TypeDef* GPIOx);



#endif 