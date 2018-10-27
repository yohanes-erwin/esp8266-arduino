// *** File   : /esp8266-arduino/rgb-led/rgb-led.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

void setup()
{
    // Set PWM range from 0 to 255
    analogWriteRange(255);
}

void loop()
{
    // Red
    rgbLedWrite(255, 0, 0);
    delay(1000);
    // Orange
    rgbLedWrite(255, 50, 0);
    delay(1000);
    // Yellow
    rgbLedWrite(255, 150, 0);
    delay(1000);
    // Green
    rgbLedWrite(0, 255, 0);
    delay(1000);
    // Light Blue
    rgbLedWrite(0, 150, 255);
    delay(1000);
    // Blue
    rgbLedWrite(0, 0, 255);
    delay(1000);
    // Purple
    rgbLedWrite(150, 0, 255);
    delay(1000);
    // White
    rgbLedWrite(255, 255, 255);
    delay(1000);
}

void rgbLedWrite(byte red, byte green, byte blue)
{
    analogWrite(D5, 255-red);
    analogWrite(D7, 255-green);
    analogWrite(D8, 255-blue);
}

