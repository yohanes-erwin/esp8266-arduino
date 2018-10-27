// *** File   : /esp8266-arduino/ds1307-oled-display/
//              ds1307-oled-display.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <RtcDS1307.h>

// *** Check library setting ***
#if (SSD1306_LCDHEIGHT != 64)    // 128 x 64 pixel display
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// OLED I2C address
#define OLED_ADDR 0x3C

// OLED object declaration
Adafruit_SSD1306 oled;
// RTC object declaration
RtcDS1307<TwoWire> rtc(Wire);

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
}

void loop()
{
    // Read RTC date and time
    RtcDateTime now = rtc.GetDateTime();
    
    // *** Display RTC date and time on OLED ***  
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(8, 30);
    oled.printf("%04d/%02d/%02d %02d:%02d:%02d",
            now.Year(), now.Month(), now.Day(),
			now.Hour(), now.Minute(), now.Second());
    oled.display();

    delay(1000);
}

