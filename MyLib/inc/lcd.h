#ifndef LCD_H
#define LCD_H


#include "stm8l_define.h"

#include <stdint.h>
typedef struct{
  uint8_t bit0 : 1;
  uint8_t bit1 : 1;
  uint8_t bit2 : 1;
  uint8_t bit3 : 1;
  uint8_t bit4 : 1;
  uint8_t bit5 : 1;
  uint8_t bit6 : 1;
  uint8_t bit7 : 1;
} BF;

typedef struct{
  uint8_t CR1;
  uint8_t CR2;
  uint8_t CR3;
  uint8_t FRQ;
  uint8_t PM[4];
  uint8_t Reserved[4];
  BF RAM[14];
}LCD_Type;

#define LCD ((volatile LCD_Type *)0x5400)

//-----0, 1, 22, 23 => PM0 = 0x03 / PM2 = 0xC0
#define _1A     (LCD->RAM[6].bit2)      //S1[22]
#define _1B     (LCD->RAM[2].bit6)      //S0[22]
#define _1C     (LCD->RAM[3].bit5)      //S1[1]
#define _1D     (LCD->RAM[3].bit4)      //S1[0]
#define _1E     (LCD->RAM[0].bit0)      //S0[0]
#define _1F     (LCD->RAM[6].bit3)      //S1[23]
#define _1G     (LCD->RAM[2].bit7)      //S0[23]
#define _1H     (LCD->RAM[13].bit3)     //S3[23]
#define _1J     (LCD->RAM[13].bit2)     //S3[22]
#define _1K     (LCD->RAM[9].bit6)      //S2[22]
#define _1M     (LCD->RAM[0].bit1)      //S0[1]
#define _1N     (LCD->RAM[10].bit4)     //S3[0]
#define _1P     (LCD->RAM[7].bit0)      //S2[0]
#define _1Q     (LCD->RAM[9].bit7)      //S2[23]
#define _1DP    (LCD->RAM[10].bit5)     //S3[1]
#define _1CL    (LCD->RAM[7].bit1)      //S2[1]

//-----2, 3, 20, 21 => PM0 = 0x0C / PM2 =0x30
#define _2A     (LCD->RAM[6].bit0)      //S1[20]
#define _2B     (LCD->RAM[2].bit4)      //S0[20]
#define _2C     (LCD->RAM[3].bit7)      //S1[3]
#define _2D     (LCD->RAM[3].bit6)      //S1[2]
#define _2E     (LCD->RAM[0].bit2)      //S0[2]
#define _2F     (LCD->RAM[6].bit1)      //S1[21]
#define _2G     (LCD->RAM[2].bit5)      //S0[21]
#define _2H     (LCD->RAM[13].bit1)     //S3[21]
#define _2J     (LCD->RAM[13].bit0)     //S3[20]
#define _2K     (LCD->RAM[9].bit4)      //S2[20]
#define _2M     (LCD->RAM[0].bit3)      //S0[3]
#define _2N     (LCD->RAM[10].bit6)     //S3[2]
#define _2P     (LCD->RAM[7].bit2)      //S2[2]
#define _2Q     (LCD->RAM[9].bit5)      //S2[21]
#define _2DP    (LCD->RAM[10].bit7)     //S3[3]
#define _2CL    (LCD->RAM[7].bit3)      //S2[3]

//-----4, 5, 18, 19 => PM0 = 0x30 / PM2 = 0x0C
#define _3A     (LCD->RAM[5].bit6)      //S1[18]
#define _3B     (LCD->RAM[2].bit2)      //S0[18]
#define _3C     (LCD->RAM[4].bit1)      //S1[5]
#define _3D     (LCD->RAM[4].bit0)      //S1[4]
#define _3E     (LCD->RAM[0].bit4)      //S0[4]
#define _3F     (LCD->RAM[5].bit7)      //S1[19]
#define _3G     (LCD->RAM[2].bit3)      //S0[19]
#define _3H     (LCD->RAM[12].bit7)     //S3[19]
#define _3J     (LCD->RAM[12].bit6)     //S3[18]
#define _3K     (LCD->RAM[9].bit2)      //S2[18]
#define _3M     (LCD->RAM[0].bit5)      //S0[5]
#define _3N     (LCD->RAM[11].bit0)     //S3[4]
#define _3P     (LCD->RAM[7].bit4)      //S2[4]
#define _3Q     (LCD->RAM[9].bit3)      //S2[19]
#define _3DP    (LCD->RAM[11].bit1)     //S3[5]
#define _3CL    (LCD->RAM[7].bit5)      //S2[5]

//-----6, 7, 16, 17 => PM0 = 0xC0 / PM2 = 0x03
#define _4A     (LCD->RAM[5].bit4)      //S1[16]
#define _4B     (LCD->RAM[2].bit0)      //S0[16]
#define _4C     (LCD->RAM[4].bit3)      //S1[7]
#define _4D     (LCD->RAM[4].bit2)      //S1[6]
#define _4E     (LCD->RAM[0].bit6)      //S0[6]
#define _4F     (LCD->RAM[5].bit5)      //S1[17]
#define _4G     (LCD->RAM[2].bit1)      //S0[17]
#define _4H     (LCD->RAM[12].bit5)     //S3[17]
#define _4J     (LCD->RAM[12].bit4)     //S3[16]
#define _4K     (LCD->RAM[9].bit0)      //S2[16]
#define _4M     (LCD->RAM[0].bit7)      //S0[7]
#define _4N     (LCD->RAM[11].bit2)     //S3[6]
#define _4P     (LCD->RAM[7].bit6)      //S2[6]
#define _4Q     (LCD->RAM[9].bit1)      //S2[17]
#define _4DP    (LCD->RAM[11].bit3)     //S3[7]
#define _4CL    (LCD->RAM[7].bit7)      //S2[7]

//-----8, 9, 14, 15 => PM1 = 0xC3
#define _5A     (LCD->RAM[5].bit2)      //S1[14]
#define _5B     (LCD->RAM[1].bit6)      //S0[14]
#define _5C     (LCD->RAM[4].bit5)      //S1[9]
#define _5D     (LCD->RAM[4].bit4)      //S1[8]
#define _5E     (LCD->RAM[1].bit0)      //S0[8]
#define _5F     (LCD->RAM[5].bit3)      //S1[15]
#define _5G     (LCD->RAM[1].bit7)      //S0[15]
#define _5H     (LCD->RAM[12].bit3)     //S3[15]
#define _5J     (LCD->RAM[12].bit2)     //S3[14]
#define _5K     (LCD->RAM[8].bit6)      //S2[14]
#define _5M     (LCD->RAM[1].bit1)      //S0[9]
#define _5N     (LCD->RAM[11].bit4)     //S3[8]
#define _5P     (LCD->RAM[8].bit0)      //S2[8]
#define _5Q     (LCD->RAM[8].bit7)      //S2[15]

//-----10, 11, 12, 13 => PM1 = 0x3C
#define _6A     (LCD->RAM[5].bit0)      //S1[12]
#define _6B     (LCD->RAM[1].bit4)      //S0[12]
#define _6C     (LCD->RAM[4].bit7)      //S1[11]
#define _6D     (LCD->RAM[4].bit6)      //S1[10]
#define _6E     (LCD->RAM[1].bit2)      //S0[10]
#define _6F     (LCD->RAM[5].bit1)      //S1[13]
#define _6G     (LCD->RAM[1].bit5)      //S0[13]
#define _6H     (LCD->RAM[12].bit1)     //S3[13]
#define _6J     (LCD->RAM[12].bit0)     //S3[12]
#define _6K     (LCD->RAM[8].bit4)      //S2[12]
#define _6M     (LCD->RAM[1].bit3)      //S0[11]
#define _6N     (LCD->RAM[11].bit6)     //S3[10]
#define _6P     (LCD->RAM[8].bit2)      //S2[10]
#define _6Q     (LCD->RAM[8].bit5)      //S2[13]
#define COL1    (LCD->RAM[7].bit1)
#define COL2    (LCD->RAM[7].bit7)


void LCD_Init(uint8_t SEG);

void LCD_SEG1(uint16_t data);
void LCD_SEG2(uint16_t data);
void LCD_SEG3(uint16_t data);
void LCD_SEG4(uint16_t data);
void LCD_SEG5(uint16_t data);
void LCD_SEG6(uint16_t data);
void Display_string(char *str);


uint16_t GetHexCodeNum(int data);
uint16_t GetHexCodeChar(char data);

#endif


