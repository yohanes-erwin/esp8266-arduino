// *** File   : /esp8266-arduino/led-without-delay/
//              led-without-delay.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

unsigned long now = 0;
unsigned long last = 0;

void setup()
{
    // Set pin as output
    pinMode(D3, OUTPUT);
    // Set pin as input pull-up
    pinMode(D6, INPUT_PULLUP);
    // Set PWM range from 0 to 255
    analogWriteRange(255);
}

void loop()
{
    // *** Blink the red LED ***
    // Read current millis value
    now = millis();
    // If 1 second has been elapsed
    if ((now - last) > 1000)
    {
        // Toggle the LED
        digitalWrite(D3, !digitalRead(D3));
        // Save current millis value as a
        // reference for next loop
        last = now;
    }

    // *** Read button state *** 
    if (digitalRead(D6) == LOW)
        rgbLedWrite(255, 255, 255);
    else
        rgbLedWrite(0, 0, 0);
}

void rgbLedWrite(byte red, byte green, byte blue)
{
    analogWrite(D5, 255-red);
    analogWrite(D7, 255-green);
    analogWrite(D8, 255-blue);
}

