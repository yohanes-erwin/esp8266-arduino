// *** File   : /esp8266-arduino/button-interrupt/
//              button-interrupt.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

void setup()
{
    // Set pin as output
    pinMode(D3, OUTPUT);
    // Set pin as input pull-up
    pinMode(D6, INPUT_PULLUP);
    // Set external interrupt from pin D6 that is
	// connected to button
    attachInterrupt(digitalPinToInterrupt(D6),
			isr, CHANGE);
    // Set PWM range from 0 to 255
    analogWriteRange(255);
}

void isr()
{ 
    // *** Read button state *** 
    if (digitalRead(D6) == LOW)
    {
        // If button is pressed, then turn on the LED 
        digitalWrite(D3, HIGH);
    }
    else
    {
        // If button is not pressed, then turn off the LED
        digitalWrite(D3, LOW);
    }
}

void loop()
{
    // *** Blink LED white ***
    rgbLedWrite(255, 255, 255);
    delay(2000);
    rgbLedWrite(0, 0, 0);
    delay(2000);
}

void rgbLedWrite(byte red, byte green, byte blue)
{
    analogWrite(D5, 255-red);
    analogWrite(D7, 255-green);
    analogWrite(D8, 255-blue);
}

