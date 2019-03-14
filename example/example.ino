#include <Honeywell_pressure_sensors.h>
#include <SPI.h>

//for sensor: SSCMLNN030PASA3
//HPS hps(1, 16384.0, 0.0, 30.0, 0.0); // cs is pin 1, outputMax=16384, outputMin=0, pressureMax=30, pressureMin=0

//for sensor HSCDRRN015PDSA5
HPS hps(10, 14746.0, 1638.0, 15.0, -15.0); // cs is pin 10, outputMax=14746, outputMin=1638, pressureMax=15, pressureMin=-15

void setup() {
    Serial.begin(9600);
    SPI.begin();
    SPI.beginTransaction(SPISettings(800000, MSBFIRST, SPI_MODE0));
}

void loop() {
  Serial.println(hps.readPressure());
  delay(500);
}
