// *** File   : /esp8266-arduino/serial-data-logger/
//              serial-data-logger.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

int trimpotValue;

void setup()
{
    // Setup serial communication
    Serial.begin(74880);
}

void loop() 
{
    // Read analog value
    trimpotValue = analogRead(A0);
    // Send trimpot value to serial monitor
    Serial.printf("%d\n", trimpotValue);
    delay(1000);
}

