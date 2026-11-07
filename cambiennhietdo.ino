#include <dummy.h>


#include "DHT.h"

// Khai bao chan ket noi
#define DHTPIN 33
#define DHTTYPE DHT11

// Khoi tao cam bien
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Khoi tao Serial
  Serial.begin(115200);

  // Khoi dong cam bien DHT11
  dht.begin();

  Serial.println("ESP32 + DHT11");
  Serial.println("Dang doc nhiet do va do am...");
}

void loop() {
  // Doc do am (%)
  float humidity = dht.readHumidity();

  // Doc nhiet do (do C)
  float temperature = dht.readTemperature();

  // Kiem tra loi doc cam bien
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Loi: Khong doc duoc DHT11!");
    delay(2000);
    return;
  }

  // Hien thi ket qua
  Serial.print("Nhiet do: ");
  Serial.print(temperature);
  Serial.println(" *C");

  Serial.print("Do am: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("----------------------");

  // Cho 2 giay truoc khi doc tiep
  delay(2000);
}
