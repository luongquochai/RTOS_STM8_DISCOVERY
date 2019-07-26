#ifndef RAM_H
#define RAM_H

#include "stm8l_define.h"
#include "stdbool.h"

signed int counta = 0, countb = 0;
volatile unsigned int done = 0;
volatile bool press = true, sent = false;
volatile unsigned char recvData = '0';

#endif