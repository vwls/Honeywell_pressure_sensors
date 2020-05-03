# Honeywell Pressure Sensors
This is a light weight Arduino library for interacting with pressure sensors from Honeywell's TruStability Board Mount collection.

Datasheets:
- [Collection Catalog](http://sensing.honeywell.com/honeywell-sensing-trustability-ssc-series-standard-accuracy-board-mount-pressure-sensors-50099533-a-en.pdf)
- [SPI Technical Notes](http://sensing.honeywell.com/spi-comms-digital-ouptu-pressure-sensors-tn-008202-3-en-final-30may12.pdf)
- [I2C Technical Notes](http://sensing.honeywell.com/i2c-comms-digital-output-pressure-sensors-tn-008201-3-en-final-30may12.pdf)
 
__Currently, this library only supports SPI, but I2C and Analog functionality are forthcoming!__

## Functions
Here is a complete list of the functions. 
```cpp
readPressure();
readTemp();
getStatus();
```

## Examples
The following example programs demonstrate how to use the library.  

```cpp
/*
This program gets pressure readings from Honeywell's 
TruStability SPI pressure sensor. Was tested with SSCMLNN030PASA3 and  HSCDRRN015PDSA5
*/

#include <Honeywell_pressure_sensors.h>
#include <SPI.h>

HPS hps(1); // cs is pin 1

void setup(){
    Serial.begin(9600);
    SPI.begin();
    SPI.beginTransaction(SPISettings(800000, MSBFIRST, SPI_MODE0));
}

void loop(){
    Serial.println(hps.readPressure());
    delay(500);
}
```
## collaborators:
* [vwls](https://github.com/vwls)
* [emilopez](https://github.com/emilopez)
* [Johan Ramirez](https://github.com/joaramirezra)


## License
The MIT License

Copyright (c) 2016 Fletcher Bach

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

