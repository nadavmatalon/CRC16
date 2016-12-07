
# CRC16

[![Platform Badge](https://img.shields.io/badge/platform-Arduino-orange.svg)](https://www.arduino.cc/)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
[![SemVer](https://img.shields.io/badge/SemVer-1.0.0-brightgreen.svg)](http://semver.org/)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## INTRODUCTION

This library contains a simple yet powerful and fast 16-BIT data validation check-value generator. 

To balance between speed and memory footprint, the library's CRC check-value generator utilizes a look-up table which is placed in Progmem spcae rather than within ordinary ram, and contains a single function for creating the said value (that is, no objects are instantiated).

## Repository Contents

- **CRC16.h** - Library Header file.  
- **CRC16.cpp** - Library Compilation file.  
- **/examples**   
  - **/CRC16_Usage.ino**  
    - **CRC16_Usage.ino** - A simple sketch in which an actual implementation is illustrated.   
  - **/CRC16_Timing**  
    - **CRC16_Timing.ino** - A sketch which measures the average length of time (in uS) for generating a given sample size of check-values.  
- **/extras**
  - **License.txt** - A cope of the end-user license agreement.  
- **keywords.txt** - Keywords for this library which will be highlighted in sketches within the Arduino IDE. 
- **library.properties** - General library properties for the Arduino's IDE (>1.5) Library Package Manager.
- **README.md** - The readme file for this library.
- **library.json** - JSON file for the Arduino's IDE (>1.5) Package Manager.

## LIBRARY INSTALLATION & SETUP

To install the library either use the Arduino IDE's Installation Wizard (Arduino Version >1.5) or download the library's ZIP folder from GITHUB, extract it, and copy the extraxcted folder to your Arduino 'libraries' folder.

All that's needed then is to include the library at the top of the sketch as follows:

```
#include "CRC.h"
```

## LIBRARY FUNCTIONS

With the library installed & included in the sketch, the following function is available (see the usage example for an actual implementation):

>Note that since no objects are instantiated, the library name needs to preceed the function name as shown below.

__CRC16::calc();__  
Parameters:&nbsp;&nbsp;&nbsp;unsigned int  
Description:&nbsp;&nbsp;&nbsp;Calculates a 16-BIT Check-Value for the provided datum.   
Returns:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;unsigned int  

## RUNNING THE EXAMPLE SKETCHES

1) Start the Arduino IDE and open the relevant example sketch  
2) Upload the said sketch to the Arduino  
3) Open the Serial Communications Window (make sure the baud-rate is set to 9600 or change it in the sketch to match your Serial Port's buad-rate)  

## BUG REPORTS

Please report any issues/bugs/suggestions at the [Issues](https://github.com/nadavmatalon/CRC16/issues) section of this Github repository.

## TODO

## VERSION HISTORY

__Ver. 1.0.0__ - First release (25.3.16)  

## LICENSE

[The MIT License (MIT)](https://opensource.org/licenses/MIT)
Copyright (c) 2016 Nadav Matalon

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


