// *** File   : /esp8266-arduino/trimpot/trimpot.ino
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

int trimpotValue;

void setup()
{
    // *** Initialize and clear display ***
    oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    // Clear OLED buffer
    oled.clearDisplay();
}

void loop()
{
    // Read analog value
    trimpotValue = analogRead(A0);
    
    // *** Display timpot value ***
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(27,30);
    oled.print("Trimpot: ");
    oled.print(trimpotValue);
    oled.display();

    delay(1000);
}
