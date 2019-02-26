#include <Honeywell_pressure_sensors.h>
#include <SPI.h>

HPS hps(1);

void setup() {
    Serial.begin(9600);
    SPI.begin();
    SPI.beginTransaction(SPISettings(800000, MSBFIRST, SPI_MODE0));
}

void loop() {
  Serial.println(hps.readPressure());
  delay(500);
}
