// *** File   : /esp8266-arduino/led-pwm/led-pwm.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

void setup()
{
}

void loop()
{
    // *** Increase brightness ***
    for (int i = 0; i <= 1023; i += 20)
    {
        analogWrite(D3, i);
        delay(25);
    }
    // *** Decrease brightness ***
    for (int i = 1023; i >= 0; i -= 20)
    {
        analogWrite(D3, i);
        delay(25);
    }
}

