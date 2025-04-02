
#include "DHT.h"
#define dhtpin 2

#define RELAY 10

#define TEMP_HIGH 21.0


DHT dht(dhtpin, DHT11);
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(RELAY, OUTPUT);
}
void loop() {
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  Serial.print(temp);
  Serial.print(",");
  Serial.println(humidity);


  if (temp > TEMP_HIGH) {
    digitalWrite(RELAY, HIGH);
  } else {

    digitalWrite(RELAY, LOW);
  }


  delay(1000);
}
