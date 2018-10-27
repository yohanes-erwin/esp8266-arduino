// *** File   : /esp8266-arduino/serial-led-pwm/
//              serial-led-pwm.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

String pwmValue;

void setup()
{
    // Setup serial communication
    Serial.begin(74880);
}

void loop()
{
    if (Serial.available() > 0)
    {
        // Read PWM value from receive buffer
        pwmValue = Serial.readStringUntil('\n');
        // Process the command
        analogWrite(D3, pwmValue.toInt());
    }
}

