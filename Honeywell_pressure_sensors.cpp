/*
	Arduino library for Honeywell pressure sensors
	Currently just supporting SPI sensors. I2c and Analog to come.
	Fletcher Bach - Dec. 2016
	MIT license
*/

#include "Arduino.h"
#include "Honeywell_pressure_sensors.h"

HPS::HPS(int pin) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    _pin = pin;
}

void HPS::readPressure(int whichChip) {
    whichChip = pin;

    byte firstByte;
    byte secondByte;

    // asserting this sensor by bringing CS pin low
    digitalWrite(whichChip, LOW);

    // here we're asking for our two bytes
    firstByte = SPI.transfer(0x00);
    secondByte = SPI.transfer(0x00);

    // here we're bitshifting the first byte 8 bits to the left
    uint16_t bothBytes = (firstByte << 8) | secondByte;
    transferFunction(bothBytes);

    // de-asserting this sensor by bringing CS pin high
    digitalWrite(whichChip, HIGH);
    //return (combinedInts);
    return (bothBytes);
}

void HPS::readTemperature(){

}

void HPS::getStatus(){

}

float HPS::transferFunction(uint16_t dataIn) {
    float outputMax = 16384.0; // 2 to the 14th power (from sensor's data sheet)
    float outputMin = 0.0;
	float pressureMax = 30.0; // max 30 psi (from sensor's datea sheet)
	float pressureMin = 0.0;
	float pressure = 0.0;
	// from data sheet "output" in this case, is passed as dataIn

	// transfer function: using sensor output to solve for pressure
	pressure = (dataIn - outputMin) * (pressureMax - pressureMin) / (outputMax - outputMin);
	pressure = pressure + pressureMin;

	psiOutput = pressure;
	Serial.print(psiOutput);
	return (psiOutput);

}


