
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
