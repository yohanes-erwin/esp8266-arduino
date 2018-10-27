// *** File   : /esp8266-arduino/rgb-led-spectrum/
//              rgb-led-spectrum.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

// RGB color, starts with red
byte rgb[3] = {255, 0, 0};

void setup()
{
    // Set PWM range from 0 to 255
    analogWriteRange(255);
}

void loop()
{
    for (int i = 0; i <= 2; i++)
    {
        // *** Select which colors to decrement and
		// increment ***
        int dec = i;
        int inc = (dec + 1) % 3;

        // *** Decrement and increment the colors ***
        for (int j = 0; j < 255; j++)
        {
            rgb[dec] -= 1;
            rgb[inc] += 1;
            rgbLedWrite(rgb[0], rgb[1], rgb[2]);
            delay(5);
        }
    }
}

void rgbLedWrite(byte red, byte green, byte blue)
{
    analogWrite(D5, 255-red);
    analogWrite(D7, 255-green);
    analogWrite(D8, 255-blue);
}

