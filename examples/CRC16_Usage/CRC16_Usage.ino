/* 
  CRC16 LIBRARY - USAGE EXAMPLE
  -----------------------------

  INTRODUCTION
  ------------
  This sketch generates a CRC16 check-value for all integers between 0-65535 and prints them out in the
  Serial Communication Window.

  BUG REPORTS
  -----------
  Please report any bugs/issues/suggestions at the GITHUB Repository of this library at:
  https://github.com/nadavmatalon/CRC16

  LICENSE
  -------
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
*/

#include "CRC16.h"
     
void setup() {
    Serial.begin(9600);
    Generate_CRC16();
}

void loop() {}

void Generate_CRC16() {
    Serial.print(F("\n\n"));
    for (unsigned int rawData=0; rawData<=65535; rawData++) {
        Serial.print(F("raw data:  "));
        Serial.print(rawData);
        Serial.print(F("\tcheck value:  "));
        Serial.print(CRC16::calc(rawData));
        Serial.print(F("\n\n"));
    }
}
