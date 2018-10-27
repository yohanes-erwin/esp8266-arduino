// *** File   : /esp8266-arduino/timer/timer.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

unsigned long ms;

void setup()
{
    // Setup serial communication
    Serial.begin(74880);
}

void loop()
{
    // Get milliseconds value
    ms = millis();
    // Send milliseconds value to serial monitor
    Serial.println(ms);
    delay(1000);
}

