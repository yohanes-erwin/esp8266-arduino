// *** File   : /esp8266-arduino/led/led.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

void setup()
{
    // Set GPIO pin as output using NodeMCU pins,
    pinMode(D3, OUTPUT);
	// or use ESP8266 pins
	//pinMode(0, OUTPUT);
}

void loop()
{
    // Turn on LED
    digitalWrite(D3, HIGH);
    delay(1000);
    // Turn off LED
    digitalWrite(D3, LOW);
    delay(1000);
}

