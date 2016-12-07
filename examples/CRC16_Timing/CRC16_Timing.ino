/* 
  CRC16 LIBRARY - TIMING EXAMPLE
  ------------------------------

  INTRODUCTION
  ------------
  This sketch measures the average time-penality (in uS) involved in generating a CRC16 check-value based on
  a given sample size of random numbers.

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

const unsigned int SAMPLE_SIZE = 500;

unsigned long start_time, stop_time, interval, sum;
unsigned int rawData, checkVal;
float average;

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(0));
    timeCRC16();
}

void loop() {}

void timeCRC16() {
    Serial.print(F("\n\n"));
    for (unsigned int sampleNum=0; sampleNum<SAMPLE_SIZE; sampleNum++) {
        rawData = (unsigned int)(random(0, 65536));
        start_time = micros();
        checkVal = CRC16::calc(rawData);
        stop_time = micros();
        interval = stop_time - start_time;
        sum += interval;
        Serial.print(F("sample number:  "));
        Serial.print(sampleNum);
        Serial.print(F("\t\traw data:  "));
        Serial.print(rawData);
        if (rawData < 10000) Serial.print(F("\t"));
        Serial.print(F("\t\tcheck value:  "));
        Serial.print(checkVal);
        Serial.print(F("\t\ttime to generatel:  "));
        Serial.print(interval);
        Serial.print(F("uS\n\n"));
    } 
    average = sum/(float)SAMPLE_SIZE;
    Serial.print(F("\naverage time: "));
    Serial.print(average);
    Serial.print(F("uS\n"));
}
