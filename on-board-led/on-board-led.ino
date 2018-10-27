// *** File   : /esp8266-arduino/on-board-led/
//              on-board-led.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

void setup()
{
    // Set on-board LED pin as output
    pinMode(D4, OUTPUT);
}
 
void loop()
{
    // Turn on the active-low LED
    digitalWrite(D4, LOW);
}

