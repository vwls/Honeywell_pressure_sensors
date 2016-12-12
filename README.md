# Honeywell Pressure Sensors
This is a simple library for interacting with pressure sensors from Honeywell's ____ collection. 

Currently, this library only supports SPI, but I2C and Analog functionality is forthcoming!

## Functions
Here is a complete list of the functions that this library provides. 
```cpp
readPressure();
readTemp();
```

## Examples
The following example programs demonstrate the functions of this library.  

```cpp
#include <Honeywell_pressure_sensors.h>

Honeywell_pressure_sensors hps(1);

void setup(){
    Serial.begin(9600);
}

void loop(){
    hps.readPressure();
}
```
