// *** File   : /esp8266-arduino/trimpot-rgb-led/
//              rgb-led.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

#include<math.h>

int trimpotValue;

uint8_t r, g, b;

void setup()
{
    // Set PWM range from 0 to 255
    analogWriteRange(255);   
}

void loop()
{
    // Read trimpot value
    trimpotValue = analogRead(A0);
    // Map trimpot value from 0-1023 to 0-359
    trimpotValue = map(trimpotValue, 0, 1023, 0, 359);
    // Convert trimpot value to RGB value
    hsvToRgb(trimpotValue, 1.0, 1.0, &r, &g, &b);
    // Send RGB value to RGB LED
    rgbLedWrite(r, g, b);

    delay(10);
}

void hsvToRgb(uint16_t H, float S, float V,
    uint8_t *R, uint8_t *G, uint8_t *B)
{
    float R_a, G_a, B_a;
  
    // Calculate C
    float C = V * S;
    // Calculte X
    float X = C * (1.0 - fabs(fmod(H/60.0, 2.0) - 1.0));
    // *** Calculate R', G', and B' ***
    if ((H >= 0) && (H < 60))
    {
        R_a = C; G_a = X; B_a = 0;
    }
    else if ((H >= 60) && (H < 120))
    {
        R_a = X; G_a = C; B_a = 0;
    }
    else if ((H >= 120) && (H < 180))
    {
        R_a = 0; G_a = C; B_a = X;
    }
    else if ((H >= 180) && (H < 240))
    {
        R_a = 0; G_a = X; B_a = C;
    }
    else if ((H >= 240) && (H < 300))
    {
        R_a = X; G_a = 0; B_a = C;
    }
    else if ((H >= 300) && (H < 360))
    {
        R_a = C; G_a = 0; B_a = X;
    }          
    // Calculate m
    float m = V - C;
    // *** Calculate R, G, and B ***
    *R = (uint8_t)((R_a + m) * 255);
    *G = (uint8_t)((G_a + m) * 255);
    *B = (uint8_t)((B_a + m) * 255);
}

void rgbLedWrite(byte red, byte green, byte blue)
{
    analogWrite(D5, 255-red);
    analogWrite(D7, 255-green);
    analogWrite(D8, 255-blue);
}

