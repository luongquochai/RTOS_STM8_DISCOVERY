#ifndef STM8L_DEFINE_H
#define STM8L_DEFINE_H

#include <stdint.h>
#include <intrinsics.h>
#include <stdbool.h>

#define     __I     volatile const   /*!< defines 'read only' permissions     */
#define     __O     volatile         /*!< defines 'write only' permissions    */
#define     __IO    volatile         /*!< defines 'read / write' permissions  */




/*CLK_STRUCT */

typedef struct CLK_struct
{
  __IO uint8_t DIVR;      /*!< Clock Master Divider Register */
  __IO uint8_t CRTCR;  /*!< RTC Clock selection Register */
  __IO uint8_t ICKR;     /*!< Internal Clocks Control Register */
  __IO uint8_t PCKENR1;  /*!< Peripheral Clock Gating Register 1 */
  __IO uint8_t PCKENR2;  /*!< Peripheral Clock Gating Register 2 */
  __IO uint8_t CCOR;       /*!< Configurable Clock Output Register */
  __IO uint8_t ECKR;     /*!< External Clocks Control Register */
  __IO uint8_t SCSR;     /*!< System clock status Register */
  __IO uint8_t SWR;      /*!< System clock Switch Register */
  __IO uint8_t SWCR;     /*!< Switch Control Register */
  __IO uint8_t CSSR;     /*!< Clock Security Sytem Register */
  __IO uint8_t CBEEPR;     /*!< Clock BEEP Register */
  __IO uint8_t HSICALR;     /*!< HSI Calibration Register */
  __IO uint8_t HSITRIMR; /*!< HSI clock Calibration Trimmer Register */
  __IO uint8_t HSIUNLCKR; /*!< HSI Unlock  Register */
  __IO uint8_t REGCSR;  /*!< Main regulator control status register */
  __IO uint8_t PCKENR3;  /*!< Peripheral Clock Gating Register 3 */
}
CLK_TypeDef;

/*External Interrupt */

typedef struct EXTI_struct
{
  __IO uint8_t CR1;           /*!<  The four LSB EXTI  pin sensitivity */
  __IO uint8_t CR2;           /*!<  The four MSB EXTI  pin sensitivity */
  __IO uint8_t CR3;           /*!<  EXTI port B & port D sensitivity */
  __IO uint8_t SR1;           /*!<  Pins Status flag register 1 */
  __IO uint8_t SR2;           /*!<  Ports Status flage register 2 */
  __IO uint8_t CONF1;         /*!<  Port interrupt selector */
  uint8_t RESERVED[4];  /*!<  reserved area */
  __IO uint8_t CR4;           /*!<  EXTI port G & port H sensitivity */
  __IO uint8_t CONF2;         /*!<  Port interrupt selector */
}
EXTI_TypeDef;

/**
  * @brief Interrupt Controller (ITC)
  */
typedef struct ITC_struct
{
  __IO uint8_t ISPR1; /*!<  Interrupt Software Priority register 1 */
  __IO uint8_t ISPR2; /*!<  Interrupt Software Priority register 2 */
  __IO uint8_t ISPR3; /*!<  Interrupt Software Priority register 3 */
  __IO uint8_t ISPR4; /*!<  Interrupt Software Priority register 4 */
  __IO uint8_t ISPR5; /*!<  Interrupt Software Priority register 5 */
  __IO uint8_t ISPR6; /*!<  Interrupt Software Priority register 6 */
  __IO uint8_t ISPR7; /*!<  Interrupt Software Priority register 7 */
  __IO uint8_t ISPR8; /*!<  Interrupt Software Priority register 8 */
}
ITC_TypeDef;


typedef struct{
  uint8_t SR;
  uint8_t DR;
  uint8_t BRR1;
  uint8_t BRR2;
  uint8_t CR1;
  uint8_t CR2;
  uint8_t CR3;
  uint8_t CR4;
  uint8_t CR5;
  uint8_t GTR;
  uint8_t PSCR;
 }UART_TypeDef;


/*BASE ADDRESS */

#define CLK_BASE                    (uint16_t)0x50C0
#define EXTI_BASE                   (uint16_t)0x50A0
#define ITC_BASE                    (uint16_t)0x7F70
#define UART_BASE                   (uint16_t)0x5230

/*ADDRESS */

#define CLK                         ((CLK_TypeDef *) CLK_BASE)
#define EXTI                        ((EXTI_TypeDef *) EXTI_BASE)
#define ITC                         ((ITC_TypeDef *) ITC_BASE)
#define UART                        ((UART_TypeDef *) UART_BASE)




#endif 