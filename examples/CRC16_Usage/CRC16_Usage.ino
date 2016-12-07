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
