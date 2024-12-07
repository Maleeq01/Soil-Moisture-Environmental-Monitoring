# Soil-Moisture-Environmental-Monitoring

An IoT project utilizing an ESP32 microcontroller, soil sensor module, DHT11, and Blynk interface to monitor and visualize soil and environmental parameters in real-time.

## Features
- **Soil Moisture Monitoring**: Measures soil moisture levels using a soil sensor module.
- **Environmental Monitoring**: Tracks temperature and humidity using a DHT11 sensor.
- **Real-Time Data**: Sends data to the Blynk app for visualization on a mobile dashboard.
- **Alerts**: Notifies users when soil moisture or environmental conditions fall outside the defined range.

---

## Hardware Components
1. **ESP32**: Microcontroller for processing and communication.
2. **Soil Moisture Sensor**: Detects soil moisture levels.
3. **DHT11 Sensor**: Measures temperature and humidity.
4. **Connecting Wires**: For circuit connections.
5. **Power Source**: 5V USB or battery.

---

## Software Requirements
- **Arduino IDE**: To program the ESP32.
- **Blynk Library**: For communication with the Blynk platform.
- **DHT Library**: To interface with the DHT11 sensor.

---

## Setup Instructions
1. **Hardware Setup**:
   - Connect the soil sensor module to the ESP32.
   - Attach the DHT11 sensor to the ESP32 as per the circuit diagram.
   - Power the ESP32 using a USB cable or a battery.

2. **Software Configuration**:
   - Install the required libraries in the Arduino IDE:
     - [Blynk](https://github.com/blynkkk/blynk-library)
     - [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
   - Configure the WiFi credentials in the Arduino code:
     ```cpp
     #define WIFI_SSID "Your_SSID"
     #define WIFI_PASSWORD "Your_Password"
     ```
   - Generate a Blynk authentication token and add it to the code:
     ```cpp
     #define BLYNK_AUTH_TOKEN "Your_Blynk_Token"
     ```

3. **Upload Code**:
   - Connect the ESP32 to your PC and upload the code using Arduino IDE.

4. **Blynk Dashboard**:
   - Create a new project in the Blynk app.
   - Add widgets (e.g., gauge, chart) to visualize soil moisture, temperature, and humidity data.


