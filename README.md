# Honeywell Pressure Sensors
This is a simple library for interacting with pressure sensors from Honeywell's TruStability Board Mount collection.
[Collection Catalog] (http://sensing.honeywell.com/honeywell-sensing-trustability-ssc-series-standard-accuracy-board-mount-pressure-sensors-50099533-a-en.pdf)
[SPI Technical Notes] (http://sensing.honeywell.com/spi-comms-digital-ouptu-pressure-sensors-tn-008202-3-en-final-30may12.pdf)
[I2C Technical Notes] (http://sensing.honeywell.com/i2c-comms-digital-output-pressure-sensors-tn-008201-3-en-final-30may12.pdf)

SPI - SSCMLNN030PASA3
I2C -
Analog -  

__Currently, this library only supports SPI, but I2C and Analog functionality is forthcoming!__

## Functions
Here is a complete list of the functions that this library provides. 
```cpp
readPressure();
readTemp();
getStatus();
```

## Examples
The following example programs demonstrate the functions of this library.  

```cpp
/*
Reading pressure from Honeywell TruStability pressure sensor SSCMLNN030PASA3   
*/

#include <Honeywell_pressure_sensors.h>

Honeywell_pressure_sensors hps(1);

void setup(){
    Serial.begin(9600);
}

void loop(){
    hps.readPressure();
}
```
