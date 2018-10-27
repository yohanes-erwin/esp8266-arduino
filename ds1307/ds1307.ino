// *** File   : /esp8266-arduino/ds1307/ds1307.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

#include <Wire.h>
#include <RtcDS1307.h>

// RTC object declaration
RtcDS1307<TwoWire> rtc(Wire);

void setup()
{
    // Setup serial communication
    Serial.begin(74880);
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
    // *** Send RTC date and time to serial
	// monitor ***  
    Serial.printf("%04d/%02d/%02d %02d:%02d:%02d\n",
            now.Year(), now.Month(), now.Day(),
			now.Hour(), now.Minute(), now.Second());
    delay(1000);
}

