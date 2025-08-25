
# WiFi-Based Servo Motor Control Using Arduino and ESP8266

## 📌 Project Overview

This project demonstrates how to control a servo motor remotely using **Arduino**, **ESP8266 WiFi module**, and the **Arduino IDE**. The ESP8266 acts as a web server and receives commands from a web browser, which are then processed by the Arduino to move the servo motor to the desired position smoothly.

This project highlights the integration of **Embedded Systems** and **IoT (Internet of Things)** and can be applied in **home automation, robotics, and smart devices**.

---

## 🔧 Components Required

* Arduino Uno (or compatible board)
* ESP8266 WiFi Module (ESP-01 or NodeMCU if preferred)
* Servo Motor (e.g., SG90 or MG90S)
* Jumper wires
* Breadboard
* Power supply (5V for Arduino & servo, 3.3V for ESP8266)

---

## ⚡ Circuit Connections

* **ESP8266 → Arduino**

  * ESP8266 TX → Arduino Pin 2 (RX)
  * ESP8266 RX → Arduino Pin 3 (TX)
  * ESP8266 VCC & CH\_PD → 3.3V
  * ESP8266 GND → GND

* **Servo Motor → Arduino**

  * Servo Signal → Pin 8
  * Servo VCC → 5V
  * Servo GND → GND

---

## 🖥️ Software Setup

1. Install **Arduino IDE** (if not already installed).
2. Add **ESP8266 AT firmware support** (ensure your ESP8266 has AT firmware).
3. Install required Arduino libraries:

   * `SoftwareSerial.h` (built-in)
   * `Servo.h` (built-in)

---

## 🚀 Steps to Run

1. Clone this repository:

   ```bash
   git clone https://github.com/your-username/WiFi-Servo-Control.git
   cd WiFi-Servo-Control
   ```
2. Open the `.ino` file in Arduino IDE.
3. Replace WiFi credentials in the code:

   ```cpp
   sendData("AT+CWJAP=\"WiFiName\",\"WiFiPassword\"\r\n", 4000, DEBUG);
   ```
4. Select the correct **Arduino board** and **COM port** in Arduino IDE.
5. Upload the code to Arduino.
6. Open the Serial Monitor at **115200 baud rate** to check ESP8266 responses.
7. Find the IP address of ESP8266 (printed in Serial Monitor).
8. Open a browser and go to:

   ```
   http://<ESP8266_IP>/?sr1=<angle>
   ```

   Example:

   ```
   http://192.168.1.5/?sr1=90
   ```

   This will move the servo motor to 90°.

---

## 📡 Example Commands

* `/?sr1=20` → Moves servo to 20°
* `/?sr1=90` → Moves servo to 90°
* `/?sr1=160` → Moves servo to 160°

---

## 📌 Applications

* Smart Door Locks
* IoT-based Robotics
* Remote-controlled surveillance cameras
* Home Automation Systems

---

## 📷 Project Demo (Optional)

> *(Here you can add images, circuit diagrams, or demo GIFs later once tested.)*

---

## 📝 Author

Developed by **\[Your Name]** using Arduino IDE, ESP8266, and Servo motor.

