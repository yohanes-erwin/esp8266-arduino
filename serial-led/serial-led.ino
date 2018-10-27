// *** File   : /esp8266-arduino/serial-led/
//              serial-led.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

String cmd;

void setup()
{
    // Set pin as output
    pinMode(D3, OUTPUT);
    // Setup serial communication
    Serial.begin(74880);
}

void loop()
{
    if (Serial.available() > 0)
    {
        // Read command from receive buffer
        cmd = Serial.readStringUntil('\n');
        
        // *** Process the command ***
        if (cmd == "LED+ON")		// Turn on LED
        {
            digitalWrite(D3, HIGH);
        }
        else if (cmd == "LED+OFF")  // Turn off LED
        {
            digitalWrite(D3, LOW);
        }
        else if (cmd == "LED")      // Ask the LED value
        {
            if (digitalRead(D3))
                Serial.println("LED is on");
            else
                Serial.println("LED is off");
        }
        else
        {
            Serial.println("Unknown command");
        }
    }
}

