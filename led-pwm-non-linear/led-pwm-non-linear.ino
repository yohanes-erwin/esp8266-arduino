// *** File   : /esp8266-arduino/led-pwm-non-linear/
//              led-pwm-non-linear.ino
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
        analogWrite(D3, pow(2, (i/102.3))-1);
        delay(25);
    }
    // *** Decrease brightness ***
    for (int i = 1023; i >= 0; i -= 20)
    {
        analogWrite(D3, pow(2, (i/102.3))-1);
        delay(25);
    }
}

