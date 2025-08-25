#include <SoftwareSerial.h>   // Software serial for ESP8266
#include <Servo.h>            // Servo motor library

// ESP8266 communication pins
SoftwareSerial esp(2, 3);     // RX = 2, TX = 3

// Servo setup
#define servopin 8            // Servo connected to pin 8
Servo servo1;

int current_position = 170;   // Initial servo position
int v = 10;                   // Servo movement speed
int minposition = 20;         // Minimum servo angle
int maxposition = 160;        // Maximum servo angle

#define DEBUG true            // Enable Serial debug

// Function to send AT commands to ESP8266
String sendData(String command, const int timeout, boolean debug) {
  String response = "";
  esp.print(command);
  long int time = millis();

  while ((time + timeout) > millis()) {
    while (esp.available()) {
      char c = esp.read();
      response += c;
    }
  }

  if (debug) {
    Serial.print(response);
  }

  return response;
}

void setup() {
  servo1.attach(servopin);
  servo1.write(maxposition);
  servo1.detach();

  Serial.begin(115200);   // Debug Serial
  esp.begin(115200);      // ESP8266 Serial

  // Initialize ESP8266
  sendData("AT+RST\r\n", 2000, DEBUG);                       
  sendData("AT+CWMODE=1\r\n", 1000, DEBUG);                  
  sendData("AT+CWJAP=\"WiFiName\",\"WiFiPassword\"\r\n", 4000, DEBUG); // Replace with your WiFi credentials

  // Wait until connected
  while (!esp.find("OK")) {}

  // Get IP and start server
  sendData("AT+CIFSR\r\n", 1000, DEBUG);    
  sendData("AT+CIPMUX=1\r\n", 1000, DEBUG);      
  sendData("AT+CIPSERVER=1,80\r\n", 1000, DEBUG); 
}

void loop() {
  if (esp.available()) {
    if (esp.find("+IPD,")) {
      String msg;
      esp.find("?");
      msg = esp.readStringUntil(' ');

      String command = msg.substring(0, 3);    
      String valueStr = msg.substring(4);     
      int value = valueStr.toInt();

      if (DEBUG) {
        Serial.println(command);
        Serial.println(value);
      }

      delay(100);

      if (command == "sr1") {
        if (value >= maxposition) value = maxposition;
        if (value <= minposition) value = minposition;

        servo1.attach(servopin);

        while (current_position != value) {
          if (current_position > value) {
            current_position -= 1;
          } else if (current_position < value) {
            current_position += 1;
          }

          servo1.write(current_position);
          delay(100 / v);
        }

        servo1.detach();
      }
    }
  }
}

