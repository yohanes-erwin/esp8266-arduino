// *** File   : /esp8266-arduino/button/button.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

void setup()
{
    // Set pin as output
    pinMode(D3, OUTPUT);
    // Set pin as input pull-up
    pinMode(D6, INPUT_PULLUP);
}

void loop()
{
    // *** Read button state *** 
    if (digitalRead(D6) == LOW)
    {
        // If button is pressed, then turn on
		// the LED 
        digitalWrite(D3, HIGH);
    }
    else
    {
        // If button is not pressed, then turn off
		// the LED
        digitalWrite(D3, LOW);
    }
}
