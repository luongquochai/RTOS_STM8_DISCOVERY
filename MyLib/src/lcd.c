#include "lcd.h"
#include "stm8l_define.h"
#include <string.h>

void LCD_Init(uint8_t SEG){
  LCD->CR1 |= (3<<1); // 1/4 Duty 
  LCD->CR1 &= ~(1<<0); // 1/3 Bias
  
  LCD->CR2 |= (1<<4); // HD on
  LCD->CR2 |= (4<<1); //Vlcd4
  LCD->CR2 &= ~(1<<0); // Internal Voltage Source
  
  LCD->FRQ = 0x30;
  
  LCD->PM[3] = 0x00;
  if (SEG & (1<<1)){ // SEG1 Enable
    LCD->PM[0] |= (3<<0);
    LCD->PM[2] |= (3<<4);
  }
  if (SEG & (1<<2)){ // SEG2 Enable
    LCD->PM[0] |= (12<<0);
    LCD->PM[2] |= (3<<4);
  }
  if (SEG & (1<<3)){ // SEG3 Enable
    LCD->PM[0] |= (3<<4);
    LCD->PM[2] |= (12<<0);
  }
  if (SEG & (1<<4)){ // SEG4 Enable
    LCD->PM[0] |= (12<<4);
    LCD->PM[2] |= (3<<0);
  }
  if (SEG & (1<<5)){ // SEG5 Enable
    LCD->PM[1] |= (12<<4);
    LCD->PM[1] |= (3<<0);
  }
  if (SEG & (1<<6)){ // SEG6 Enable
    LCD->PM[1] |= (3<<4);
    LCD->PM[1] |= (12<<0);
  }
  
  LCD->CR3 |= (1<<5); //IRQ Enable
  LCD->CR3 |= (1<<6); //LCD Enalbe
}

void LCD_SEG1(uint16_t data){
  _1A = 0;//(data & (1<<0)) ? 1:0;
  _1B = 0;//(data & (1<<1)) ? 1:0;
  _1C = (data & (1<<2)) ? 1:0;
  _1D = (data & (1<<3)) ? 1:0;
  _1E = (data & (1<<4)) ? 1:0;
  _1F = 0;//(data & (1<<5)) ? 1:0;
  _1G = 0;//(data & (1<<6)) ? 1:0;
  _1H = 0;//(data & (1<<7)) ? 1:0;
  _1J = 0;//(data & (1<<8)) ? 1:0;
  _1K = 0;//(data & (1<<9)) ? 1:0;
  _1M = (data & (1<<10)) ? 1:0;
  _1N = (data & (1<<11)) ? 1:0;
  _1P = (data & (1<<12)) ? 1:0;
  _1Q = 0;//(data & (1<<13)) ? 1:0;
  _1DP = (data & (1<<14)) ? 1:0;
  _1CL = (data & (1<<15)) ? 1:0;
}

void LCD_SEG2(uint16_t data){
  _2A = (data & (1<<0)) ? 1:0;
  _2B = (data & (1<<1)) ? 1:0;
  _2C = (data & (1<<2)) ? 1:0;
  _2D = (data & (1<<3)) ? 1:0;
  _2E = (data & (1<<4)) ? 1:0;
  _2F = (data & (1<<5)) ? 1:0;
  _2G = (data & (1<<6)) ? 1:0;
  _2H = (data & (1<<7)) ? 1:0;
  _2J = (data & (1<<8)) ? 1:0;
  _2K = (data & (1<<9)) ? 1:0;
  _2M = (data & (1<<10)) ? 1:0;
  _2N = (data & (1<<11)) ? 1:0;
  _2P = (data & (1<<12)) ? 1:0;
  _2Q = (data & (1<<13)) ? 1:0;
  _2DP = (data & (1<<14)) ? 1:0;
  _2CL = (data & (1<<15)) ? 1:0;
}

void LCD_SEG3(uint16_t data){
  _3A = (data & (1<<0)) ? 1:0;
  _3B = (data & (1<<1)) ? 1:0;
  _3C = (data & (1<<2)) ? 1:0;
  _3D = (data & (1<<3)) ? 1:0;
  _3E = (data & (1<<4)) ? 1:0;
  _3F = (data & (1<<5)) ? 1:0;
  _3G = (data & (1<<6)) ? 1:0;
  _3H = (data & (1<<7)) ? 1:0;
  _3J = (data & (1<<8)) ? 1:0;
  _3K = (data & (1<<9)) ? 1:0;
  _3M = (data & (1<<10)) ? 1:0;
  _3N = (data & (1<<11)) ? 1:0;
  _3P = (data & (1<<12)) ? 1:0;
  _3Q = (data & (1<<13)) ? 1:0;
  _3DP = (data & (1<<14)) ? 1:0;
  _3CL = (data & (1<<15)) ? 1:0;
}

void LCD_SEG4(uint16_t data){
  _4A = (data & (1<<0)) ? 1:0;
  _4B = (data & (1<<1)) ? 1:0;
  _4C = (data & (1<<2)) ? 1:0;
  _4D = (data & (1<<3)) ? 1:0;
  _4E = (data & (1<<4)) ? 1:0;
  _4F = (data & (1<<5)) ? 1:0;
  _4G = (data & (1<<6)) ? 1:0;
  _4H = (data & (1<<7)) ? 1:0;
  _4J = (data & (1<<8)) ? 1:0;
  _4K = (data & (1<<9)) ? 1:0;
  _4M = (data & (1<<10)) ? 1:0;
  _4N = (data & (1<<11)) ? 1:0;
  _4P = (data & (1<<12)) ? 1:0;
  _4Q = (data & (1<<13)) ? 1:0;
  _4DP = (data & (1<<14)) ? 1:0;
  _4CL = (data & (1<<15)) ? 1:0;
}

void LCD_SEG5(uint16_t data){
  _5A = (data & (1<<0)) ? 1:0;
  _5B = (data & (1<<1)) ? 1:0;
  _5C = (data & (1<<2)) ? 1:0;
  _5D = (data & (1<<3)) ? 1:0;
  _5E = (data & (1<<4)) ? 1:0;
  _5F = (data & (1<<5)) ? 1:0;
  _5G = (data & (1<<6)) ? 1:0;
  _5H = (data & (1<<7)) ? 1:0;
  _5J = (data & (1<<8)) ? 1:0;
  _5K = (data & (1<<9)) ? 1:0;
  _5M = (data & (1<<10)) ? 1:0;
  _5N = (data & (1<<11)) ? 1:0;
  _5P = (data & (1<<12)) ? 1:0;
  _5Q = (data & (1<<13)) ? 1:0;
}

void LCD_SEG6(uint16_t data){
  _6A = (data & (1<<0)) ? 1:0;
  _6B = (data & (1<<1)) ? 1:0;
  _6C = (data & (1<<2)) ? 1:0;
  _6D = (data & (1<<3)) ? 1:0;
  _6E = (data & (1<<4)) ? 1:0;
  _6F = (data & (1<<5)) ? 1:0;
  _6G = (data & (1<<6)) ? 1:0;
  _6H = (data & (1<<7)) ? 1:0;
  _6J = (data & (1<<8)) ? 1:0;
  _6K = (data & (1<<9)) ? 1:0;
  _6M = (data & (1<<10)) ? 1:0;
  _6N = (data & (1<<11)) ? 1:0;
  _6P = (data & (1<<12)) ? 1:0;
  _6Q = (data & (1<<13)) ? 1:0;
}


void Display_string(char *str)
{
  unsigned int length = strlen(str);
  register int i = 0;
  while(str[i]){

    i++;
    switch(length){
      case 1:{
        LCD_SEG1(0x0000);
        LCD_SEG2(GetHexCodeChar(str[0]));
        LCD_SEG3(0x0000);
        LCD_SEG4(0x0000);
        LCD_SEG5(0x0000);
        LCD_SEG6(0x0000);
        break;
      }
      case 2:{
        LCD_SEG1(0x0000);
        LCD_SEG2(GetHexCodeChar(str[0]));
        LCD_SEG3(GetHexCodeChar(str[1]));
        LCD_SEG4(0x0000);
        LCD_SEG5(0x0000);
        LCD_SEG6(0x0000);
        break;
      }
      case 3:{
        LCD_SEG1(0x0000);
        LCD_SEG2(GetHexCodeChar(str[0]));
        LCD_SEG3(GetHexCodeChar(str[1]));
        LCD_SEG4(GetHexCodeChar(str[2]));
        LCD_SEG5(0x0000);
        LCD_SEG6(0x0000);
        
        break;
             }
      case 4:{
        LCD_SEG1(0x0000);
    LCD_SEG2(GetHexCodeChar(str[0]));
    LCD_SEG3(GetHexCodeChar(str[1]));
    LCD_SEG4(GetHexCodeChar(str[2]));
    LCD_SEG5(GetHexCodeChar(str[3]));
    LCD_SEG6(0x0000);
    break;
            }
  case 5:{
    LCD_SEG1(0x0000);
    LCD_SEG2(GetHexCodeChar(str[0]));
    LCD_SEG3(GetHexCodeChar(str[1]));
    LCD_SEG4(GetHexCodeChar(str[2]));
    LCD_SEG5(GetHexCodeChar(str[3]));
    LCD_SEG6(GetHexCodeChar(str[4]));
    break;
          }
 
  default:
    LCD_SEG6(0x00000);
    LCD_SEG5(0x00000);
    LCD_SEG4(0x00000);
    LCD_SEG3(0x00000);
    LCD_SEG2(0x00000);
    LCD_SEG1(0x00000);
    break;
  }
}
}

  


uint16_t GetHexCodeNum(int data){
  switch (data){
  case 0: return 0x003F; break;
  case 1: return 0x0006; break;
  case 2: return 0x045B; break;
  case 3: return 0x044F; break;
  case 4: return 0x0466; break;
  case 5: return 0x046D; break;
  case 6: return 0x047D; break;
  case 7: return 0x0007; break;
  case 8: return 0x047F; break;
  case 9: return 0x046F; break;
  default: break;
  
  }
}

uint16_t GetHexCodeChar(char data){
  switch (data){
  case ' ': return 0x0000; break;
  case 'A': case 'a': return 0x08F0/*0x0477*/; break;
  case 'B': case 'b': return 0x047C/*0x0150F*/; break;
  case 'C': case 'c': return 0x0039; break;
  case 'D': case 'd': return 0x110F; break;
  case 'E': case 'e': return 0x0079; break;
  case 'F': case 'f': return 0x0071; break;
  case 'G': case 'g': return 0x043D; break;
  case 'H': case 'h': return 0x0476; break;
  case 'I': case 'i': return 0x1109; break;
  case 'J': case 'j': return 0x001E; break;
  case 'K': case 'k': return 0x0A70; break;
  case 'L': case 'l': return 0x0038; break;
  case 'M': case 'm': return 0x02B6; break;
  case 'N': case 'n': return 0x08B6; break;
  case 'O': case 'o': return 0x003F; break;
  case 'P': case 'p': return 0x0473; break;
  case 'Q': case 'q': return 0x083F; break;
  case 'R': case 'r': return 0x0C73; break;
  case 'S': case 's': return 0x046D; break;
  case 'T': case 't': return 0x1101; break;
  case 'U': case 'u': return 0x003E; break;
  case 'V': case 'v': return 0x2230; break;
  case 'W': case 'w': return 0x2836; break;
  case 'X': case 'x': return 0x2A80; break;
  case 'Y': case 'y': return 0x1280; break;
  case 'Z': case 'z': return 0x2209; break;
  case '0': return 0x003F; break;
  case '1': return 0x0206; break;
  case '2': return 0x045B; break;
  case '3': return 0x040F; break;
  case '4': return 0x0466; break;
  case '5': return 0x046D; break;
  case '6': return 0x047D; break;
  case '7': return 0x0007; break;
  case '8': return 0x047F; break;
  case '9': return 0x046F; break;
  default : return 0x0000;
  }

}