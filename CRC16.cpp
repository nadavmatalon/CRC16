/*==============================================================================================================*

    @file     CRC16.cpp
    @author   Nadav Matalon
    @license  MIT (c) 2016 Nadav Matalon

    CRC16 (Cyclic Redundancy Check) Library

    Ver. 1.0.0 - Initial release (25.3.16)
 
 *===============================================================================================================*
    LICENSE
 *===============================================================================================================*
 
    The MIT License (MIT)
    Copyright (c) 2016 Nadav Matalon

    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
    documentation files (the "Software"), to deal in the Software without restriction, including without
    limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be included in all copies or substantial
    portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
    LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 *==============================================================================================================*/

#if 1
__asm volatile ("nop");
#endif

#include "CRC16.h"

/*==============================================================================================================*
    CALCULATE CRC16 VALUE
 *==============================================================================================================*/

unsigned int CRC16::calc(unsigned int input) {
    byte nTemp;
    unsigned int crc = 0xFFFF;
    union Data_Array { byte b[2]; unsigned int i; } data_array;
    data_array.i = input;
    for (byte pos=0; pos<2; pos++) {
        nTemp = (data_array.b[pos] ^ crc);
        crc >>= 8;
        crc ^= (pgm_read_word(&(crc_table[nTemp])));
    }
    return crc;
}
