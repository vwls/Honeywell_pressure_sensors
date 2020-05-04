/*
  Autor : Johan Ramirez
  date  : 2/05/2020
  Description : Analog ABP sensor reading is made by the function AnalogRead(pin), it values
              changes from sensor to sensor depending the references, so you can change the
              values to ajust sensor you have.
  Sensor used : ABP-D-AN-T 015PG-A-A5
  min pressure : 0 psi
  max pressure : 15 psi
  Tranfer Function : 10% to 90% of Vsupply
*/

double TranferFunction(int data);
int data = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  data = analogRead(0);
  //Serial.println(data);
  //Serial.println(String(TranferFunction(data))+"[psi]");
  Serial.println(TranferFunction(data));
  delay(10);
}

double TranferFunction(int data) {
  // transfer function: using sensor output to solve for pressure
  if (data <= 102) return 0; 
  float pressure = (data - 0.1*(1024))/((0.8*(1024))/(15));
  return pressure;
}
