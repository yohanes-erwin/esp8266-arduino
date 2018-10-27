// *** File   : /esp8266-arduino/button-debouncing/
//              button-debouncing.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// *** Check library setting ***
#if (SSD1306_LCDHEIGHT != 64)    // 128 x 64 pixel display
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// Comment this line to disable button debouncing
#define DEBOUNCE

// OLED I2C address
#define OLED_ADDR 0x3C

// OLED object declaration
Adafruit_SSD1306 oled;
// Counter
uint8_t count = 0;
// Debounced press
uint8_t deb_press = 0;

void setup()
{
    // Set pin as input pull-up
    pinMode(D6, INPUT_PULLUP);

    // *** Initialize and clear display ***
    oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    // Clear OLED buffer
    oled.clearDisplay();
    
    // *** Display text ***
    oled.setTextSize(3);
    oled.setTextColor(WHITE);
    oled.setCursor(48, 24);
    oled.printf("%02d", count);
    oled.display();
}

void loop()
{
#ifndef DEBOUNCE
    if (digitalRead(D6) == LOW)
    {
        oled.clearDisplay();
        oled.setCursor(48, 24);
        oled.printf("%02d", ++count);
        oled.display();
    }
#else
    // *** Debouncing the button ***
    debounce();
    delay(10);
    
    if (deb_press == HIGH)
    {
        deb_press = LOW;
        oled.clearDisplay();
        oled.setCursor(48, 24);
        oled.printf("%02d", ++count);
        oled.display();
    }
#endif
}

void debounce()
{
    static uint8_t deb_count = 0;
    static uint8_t deb_state = 0; 

    // Read and invert the active-low button state
    uint8_t read_state = !digitalRead(D6);
    
    // *** Debouncing the button state ***
    if (read_state != deb_state)     
    {
        // If there is a transition then increment
        // the debouncing count
        deb_count++;
        if (deb_count >= 4)
        {
            // If the debouncing count reach 4
            // then update the debounced state
            deb_state = read_state;
            // If the debounced state is HIGH,
            // it means the button is pressed
            if (deb_state == HIGH)
                deb_press = HIGH;              
            deb_count = 0;
        }
    }
    else
    {
        // Reset debouncing count
        deb_count = 0;
    }
}
