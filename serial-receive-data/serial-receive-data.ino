// *** File   : /esp8266-arduino/serial-receive-data/
//              serial-receive-data.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

String serialInput;

void setup()
{
    // Setup serial communication
    Serial.begin(74880);
}

void loop()
{
    // If there is data in receive buffer
    if (Serial.available() > 0)
    {
        // Read string from receive buffer
        serialInput = Serial.readString();
        // Print to serial monitor
        Serial.println(serialInput);
    }
}

