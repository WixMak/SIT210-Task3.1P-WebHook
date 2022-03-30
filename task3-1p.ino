
#include <Adafruit_DHT.h>

#define DHTPIN D6

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
    delay(2000);

    float h = dht.getHumidity();
    float t = dht.getTempCelcius();
    float f = dht.getTempFarenheit();

    if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
    
    Particle.publish("temp", String (t), PUBLIC);
   
  
  delay(15000);

}