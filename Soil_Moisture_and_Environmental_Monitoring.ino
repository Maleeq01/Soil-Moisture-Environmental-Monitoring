#define BLYNK_TEMPLATE_ID "TMPL6Ep6xywh6"
#define BLYNK_TEMPLATE_NAME "Soil Moiture and Environmental Monitoring"
#define BLYNK_AUTH_TOKEN "y4xLPVCsVZUvSSAocP0WBjRTF7Bgxb8w"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "maleeq";  // type your wifi name
char pass[] = "12345679";  // type your wifi password

BlynkTimer timer;

#define DHTPIN 26 // Connect DHT sensor to GPIO 4 (D2) in ESP32
#define SOIL_MOISTURE_PIN 34 // Connect soil moisture sensor to GPIO 34 (ADC1_CH6) in ESP32
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

void sendSensor()
{
  int soilmoisture = analogRead(SOIL_MOISTURE_PIN);  // Read from the soil moisture sensor
  int soilmoisturepercentage = map(soilmoisture, 3500, 4095, 100, 0);
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more than 10 values per second.
  Blynk.virtualWrite(V0, soilmoisturepercentage);
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  Serial.print("Soil Moisture : ");
  Serial.print(soilmoisturepercentage);
  Serial.print(" Temperature : ");
  Serial.print(t);
  Serial.print("    Humidity : ");
  Serial.println(h);
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(100L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();                                       
}