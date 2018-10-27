// *** File   : /esp8266-arduino/dht11-ds1307/
//              dht11-ds1307.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <RtcDS1307.h>
#include <DHT.h>

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
// RTC object declaration
RtcDS1307<TwoWire> rtc(Wire);
// DHT object declaration
DHT dht(D4, DHT11);

RtcDateTime now;
float celcius, humidity;
uint8_t second = 0;

void setup()
{
    // *** Initialize and clear display ***
    oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    // Clear OLED buffer
    oled.clearDisplay();

    // Initialize RTC
    rtc.Begin();
    
    // *** Set RTC date and time to code
    // compiled time ***
    RtcDateTime compiled = RtcDateTime(__DATE__,
            __TIME__);
    rtc.SetDateTime(compiled);
    rtc.SetIsRunning(true);

    // Initialize DHT11
    dht.begin();
}

void loop()
{
    // Read RTC date and time
    now = rtc.GetDateTime();

    // *** Read temperature and humidity every 3
    // seconds ***
    if (second == 3)
    {
        celcius = dht.readTemperature();
        humidity = dht.readHumidity();
        second = 0;
    }
        
    // *** Display date, time, temperature,
    // and humidity on OLED ***  
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 0);
    oled.printf("%04d/%02d/%02d",
            now.Year(), now.Month(), now.Day());
    oled.setCursor(80, 0);
    oled.printf("%02d:%02d:%02d",
            now.Hour(), now.Minute(), now.Second());
    oled.drawBitmap(32, 20, temperature_bmp, 16, 16, 1);
    oled.drawBitmap(32, 40, humidity_bmp, 16, 16, 1);
    oled.setTextSize(2);
    oled.setCursor(55, 20);
    oled.printf("%.0f%cC", celcius, (char)247);
    oled.setCursor(55, 40);
    oled.printf("%.0f%%", humidity);
    oled.display();

    delay(1000);
    second++;
}

