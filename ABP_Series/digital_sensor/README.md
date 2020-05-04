# SPI honeywell pressure Sensor (ABPDJJT001PDSA3) 
**version :** 0.9

**Description :** ABPDJJT001PDSA3 sensor differential pressure reading is made by SPI communication, it values changes from sensor to sensor depending the references, so you have to change the
values to ajust sensor you have.

**Conection :** parameters can be found on datasheet, it's important do not forget the capacitor of 0.1 uF conection, it's also recomendable to put pullup resistors in order to stabilize the communication

#### Code Explanined :
First we have to import SPI Library and set the ss pin to start the communication, also it's important to declare a 2 bits  variable

```
short data;
```
in [datataSheet](https://datasheet.octopart.com/ABPDJJT001PGAA5-Honeywell-datasheet-136608874.pdf) we can find that the Digital interface clock frequency is in range of [50-800]Khz, since that we set SPI frecuency in 425 Khz, next que have to define SPI mode and which of MSB or LSB is used to that in [Technical notes](https://sensing.honeywell.com/spi-comms-digital-ouptu-pressure-sensors-tn-008202-3-en-final-30may12.pdf) we can find that honeywell sensor use MSB and data is sampled at the leading rising edge of the clock, hence the configuration is : 
```
SPISettings settingsA(425000, MSBFIRST, SPI_MODE0);
```
Then we have to read data, to do that use transfer16() insted of transfer() beacuse transfer16() read 2 bits  

```
data = SPI.transfer16(0x00);
```

**Transfer Function :** To find the pressure applied to sensor we have to interpret the output data from sensor since sensor have sensor has a linear behavior the behivior can be describe like :

y = mx + b , with that the expression that describe the pressure applied is :


```
pressure  = (data - 0.1*16384 )/(0.4*16384) - 1;
```

**video :**
