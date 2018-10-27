// *** File   : /esp8266-arduino/dht11/dht11.ino
// *** Author : Erwin Ouyang
// *** Date   : 17 Agt 2018

#include <DHT.h>

// DHT object declaration
DHT dht(D4, DHT11);

void setup()
{
    // Setup serial communication
    Serial.begin(74880);
    // Initialize DHT11
    dht.begin();
}

void loop()
{
    // *** Read temperature and humidity ***
    float celcius = dht.readTemperature();
    float fahrenheit = dht.readTemperature(true);
    float humidity = dht.readHumidity();

    // *** Send temperature and humidity to
    // serial monitor ***  
    Serial.printf("Temperature: %.0fC, %.0fF " \
            "Humidity: %.0f%%\n", celcius,
            fahrenheit, humidity);
            
    delay(2000);
}

