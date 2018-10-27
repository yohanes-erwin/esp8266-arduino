// *** File   : /esp8266-arduino/serial-strtok/
//              serial-strtok.ino
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

String cmd_s;
char cmd_c[64];
char *chr_p;

void setup()
{
    // Set pin as output
    pinMode(D3, OUTPUT);
    // Set PWM range from 0 to 255
    analogWriteRange(255);
    // Setup serial communication
    Serial.begin(74880);
    
    // *** Initialize OLED display ***
    oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.display();
}

void loop()
{
    if (Serial.available() > 0)
    {
        // Read command from receive buffer
        cmd_s = Serial.readStringUntil('\n');

        // *** Split the command ***
        cmd_s.toCharArray(cmd_c, 64);
        chr_p = strtok(cmd_c, "+,");
        String tokens[4];
        uint8_t idx = 0;  
        while (chr_p != NULL)
        {
            tokens[idx++] = chr_p;
            chr_p = strtok(NULL, "+,");
        }
        
        // *** Process the command ***
        if (tokens[0] == "LED")
        {
            if (tokens[1] == "ON")
            {
                digitalWrite(D3, HIGH);
            }
            else if (tokens[1] == "OFF")
            {
                digitalWrite(D3, LOW);
            }
            else
            {
                if (digitalRead(D3))
                    Serial.println("LED is on");
                else
                    Serial.println("LED is off"); 
            }
        }
        else if (tokens[0] == "RGB")
        {
            rgbLedWrite(tokens[1].toInt(),
                    tokens[2].toInt(), tokens[3].toInt());
        }
        else if (tokens[0] == "OLED")
        {
            oled.clearDisplay();
            oled.setCursor(0, 0);
            oled.printf("%s", tokens[2].c_str());
            oled.display();
        }
        else
        {
            Serial.println("Unknown command");
        }
    }
}

void rgbLedWrite(byte red, byte green, byte blue)
{
    analogWrite(D5, 255-red);
    analogWrite(D7, 255-green);
    analogWrite(D8, 255-blue);
}

