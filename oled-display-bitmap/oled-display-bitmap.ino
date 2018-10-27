// *** File   : /esp8266-arduino/oled-display-bitmap/
//              oled-display-bitmap.ino
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

// Temperature logo
static const unsigned char PROGMEM temperature_bmp[] =
{
    B00000011, B11001111,
    B00000110, B01100000,
    B00000100, B00101111,
    B00000100, B00100000,
    B00000100, B00101111,
    B00000101, B10100000,
    B00000101, B10101111,
    B00000101, B10100000,
    B00001101, B10110000,
    B00011011, B11011000,
    B00110111, B11101100,
    B00101111, B11110100,
    B00101111, B11110100,
    B00110111, B11101100,
    B00011000, B00011000,
    B00001111, B11110000
};
// Humidity logo
static const unsigned char PROGMEM humidity_bmp[] =
{
	B00000001, B10000000,
    B00000011, B11000000,
    B00000110, B01100000,
    B00000100, B00100000,
    B00001100, B00110000,
    B00001000, B00010000,
    B00011000, B00011000,
    B00010000, B00001000,
    B00110100, B00001100,
    B00101100, B00000100,
    B00101100, B00000100,
    B00101100, B00000100,
    B00110110, B00001100,
    B00011011, B00011000,
    B00001100, B00110000,
    B00000111, B11100000
};

// OLED object declaration
Adafruit_SSD1306 oled;

void setup()
{
    // *** Initialize and clear display ***
    oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    // Clear OLED buffer
    oled.clearDisplay();

    // *** Display bitmap ***
    oled.drawBitmap(32, 16, temperature_bmp, 16, 16, 1);
    oled.drawBitmap(32, 36, humidity_bmp, 16, 16, 1);
    
    // *** Display text ***
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(55, 16);
    oled.printf("25%cC", (char)247);
    oled.setCursor(55, 36);
    oled.print("60%");

    // Show OLED buffer on the display
    oled.display();
}

void loop()
{
}

