#include <SPI.h>

// using two incompatible SPI devices, A and B. Incompatible means that they need different SPI_MODE
const int slaveAPin = 53;
const int slaveBPin = 21;

// set up the speed, data order and data mode
SPISettings settingsA(2000000, MSBFIRST, SPI_MODE1);
SPISettings settingsB(16000000, LSBFIRST, SPI_MODE3);

void setup() {
  // set the Slave Select Pins as outputs:
  pinMode (slaveAPin, OUTPUT);
  pinMode (slaveBPin, OUTPUT);
  // initialize SPI:
  SPI.begin();
  // Inicializacion Serial
  Serial.begin(9600);
}

uint8_t stat, val1, val2, result;

void loop() {
  // read three bytes from device A
  SPI.beginTransaction(settingsA);
  digitalWrite (slaveAPin, LOW);
  // reading only, so data sent does not matter
  stat = SPI.transfer(0);
//  val1 = SPI.transfer(0);
//  val2 = SPI.transfer(0);
  digitalWrite (slaveAPin, HIGH);
  SPI.endTransaction();
  // if stat is 1 or 2, send val1 or val2 else zero
  Serial.println(String(stat));
  delay(5);
}
