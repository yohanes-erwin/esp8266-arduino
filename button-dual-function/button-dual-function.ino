// *** File   : /esp8266-arduino/button-dual-function/
//              button-dual-function.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

unsigned long pressed = 0;
unsigned long released = 0;
uint8_t r = 0, g = 0, b = 0;

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
        pressed = millis();
    }
    else
    {
        released = millis();
        if ((released - pressed) < 1000)
        {
            // Toggle the LED
            digitalWrite(D3, !digitalRead(D3));
        }
        else
        {
            // *** Toggle the RGB LED ***
            r ^= 0xFF;
            g ^= 0xFF;
            b ^= 0xFF;
            rgbLedWrite(r, g, b);
        }
    }
}

void loop()
{
}

void rgbLedWrite(byte red, byte green, byte blue)
{
    analogWrite(D5, 255-red);
    analogWrite(D7, 255-green);
    analogWrite(D8, 255-blue);
}

