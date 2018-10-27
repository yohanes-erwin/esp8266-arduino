// *** File   : /esp8266-arduino/ticker/ticker.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

#include <Ticker.h>

Ticker ticker;

void setup()
{
    // Set pin as output
    pinMode(D3, OUTPUT);
    // Set ticker to generate interrupt every 1 second
    ticker.attach(1, tickerCallback);
}

void tickerCallback()
{
    // Toggle LED
    digitalWrite(D3, !digitalRead(D3));
}

void loop()
{
}
