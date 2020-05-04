# SPI honeywell pressure Sensor (ABPDJJT001PDSA3) 
**version :** 0.9

**Description :** ABPDJJT001PDSA3 sensor differential pressure reading is made by SPI communication, it values changes from sensor to sensor depending the references, so you have to change the
values to ajust sensor you have.

**Conection :** parameters can be found on datasheet, itś important do not forget the capacitor of 0.1 uF conection, it's also recomendable to put pullup resistors in order to stabilize the communication

#### Code Explanined :
First we have to import SPI Library and set the ss pin to start the communication, also it's important to declare a 2 bits variables

```
short data;
```
```
data = SPI.transfer16(0x00);
```
```
SPISettings settingsA(425000, MSBFIRST, SPI_MODE0);
```

**Transfer Function :** To find the pressure applied to sensor we have to find the 

// under 1638.4 the value is -1pis
// after 14745.6 the value is 1 psi
