# AUTOMATIC PUMP SYSTEM

### COMPONENTS
  	-Arduino Uno
	-Jumper wires
	-12 DC Water pump
	-Two buckets(Tank and Reservour)
	-5V relay
	-16X2 LCD display
	-Ultrasonic Sensor x2
	
### OPERATION
The Arduino uno was used as the system microcontroller. The two untrasonic sensors each placed at the top of each bucket were used to measure the water level in both the tank and the reservour.
When the water level in the tank goes below 10% the relay contacts(Normally open) are clossed which in turn opens the pump which pumps water from the Reservour to the tank.When the water level in the tank reaches 80% the MCU opens the relay contacts hence closing the pump.The system also ensures that the pump doesnt pump dry(When there's no water in the reservour). 

### PIN CONFIGURATION
	ARDUINO		TANK ULTRASONIC
	D2		TRIG
	D3 		ECHO
	GND 		GND
	VCC		VCC
	
	ARDUINO 	RESERVE ULTRASONIC
	D4		TRIG
	D5		ECHO
	GND 		GND
	VCC		VCC
	
	ARDUINO 	LCD I2C
	SCL 		A5
	SDA 		A4
	GND 		GND
	VCC		VCC
	
	ARDUINO 	RELAY
	D7 		IN1
	GND 		GND
	VCC 		VCC
	
	
