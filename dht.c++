#include "DHT.h"
#define DHTPIN 2          
#define DHTTYPE DHT22     


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT22 Room Temperature"));
  dht.begin();
}

void loop() {
  delay(2000);  

  float h = dht.readHumidity();
  float t = dht.readTemperature();        
  float f = dht.readTemperature(true);   

  // Check if any reads failed
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C  ("));
  Serial.print(f);
  Serial.println(F("°F)"));
}