// *** File   : /esp8266-arduino/oled-display/
//              oled-display.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// *** Check library setting ***
#if (SSD1306_LCDHEIGHT != 64)    // 128 x 64 pixel display
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// OLED I2C address
#define OLED_ADDR 0x3C

// OLED object declaration
Adafruit_SSD1306 oled;

void setup()
{
    // *** Initialize and clear display ***
    oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    // Clear OLED buffer
    oled.clearDisplay();

    // *** Display text ***
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(27, 30);
    oled.print("Hello, world!");

    // Show OLED buffer on the display
    oled.display();
}

void loop()
{
}

