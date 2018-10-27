// *** File   : /esp8266-arduino/dht11-oled-display/
//              dht11-oled-display.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "DHT.h"

// *** Check library setting ***
#if (SSD1306_LCDHEIGHT != 64)    // 128 x 64 pixel display
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// OLED I2C address
#define OLED_ADDR 0x3C

// OLED object declaration
Adafruit_SSD1306 oled;
// DHT object declaration
DHT dht(D4, DHT11);

void setup()
{
    // *** Initialize and clear display ***
    oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    oled.clearDisplay();
    
    // Initialize DHT11
    dht.begin();
}

void loop()
{
    // *** Read temperature and humidity ***
    float celcius = dht.readTemperature();
    float humidity = dht.readHumidity();

    // *** Display temperature and humidity on OLED ***
    oled.clearDisplay();
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(45, 12);
    oled.printf("%.0f%cC", celcius, (char)247);
    oled.setCursor(50, 38);
    oled.printf("%.0f%%", humidity);
    oled.display();

    delay(3000);
}

