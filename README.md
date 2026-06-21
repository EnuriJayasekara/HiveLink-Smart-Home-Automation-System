# 🏠 HiveLink - Smart Home Automation System

### IT1140 - Fundamentals of Computing Project (SLIIT)

![HiveLink Banner](images/HiveLink-Banner.png)

HiveLink is an intelligent IoT-based Smart Home Automation and Safety System designed to improve home security, convenience, and energy efficiency. The system integrates Arduino Uno and ESP32 microcontrollers to automate lighting, garage parking assistance, RFID-based door access, gas leak detection, and environmental monitoring. Through the Blynk IoT platform, users can monitor sensor values and remotely control selected home devices in real time.

---

## 📖 Overview

HiveLink is a modern Smart Home Automation and Safety System that combines multiple IoT technologies to create a secure, efficient, and user-friendly home environment. The project addresses common household challenges such as unauthorized access, gas leaks, inefficient lighting, uncomfortable indoor conditions, and parking difficulties.

The system is built using two microcontrollers: Arduino Uno and ESP32. The Arduino Uno manages the LDR sensor, Ultrasonic sensor, fence lights, rooftop lights, and parking buzzer. The ESP32 handles RFID door access, DHT11 temperature and humidity monitoring, MQ-5 gas leak detection, LCD display, and Blynk IoT cloud connectivity. This architecture ensures efficient processing and reliable operation of all smart home functionalities.

Using the Blynk IoT mobile application, users can monitor real-time temperature, humidity, and gas levels, receive safety alerts, and remotely control home lighting through a Wi-Fi connection. HiveLink aims to provide a safer, smarter, and more energy-efficient living experience.

- **Project Code:** Y1S1Mtr02
- **Academic Module:** IT1140 - Fundamentals of Computing
- **Academic Year:** Year 1, Semester 1 - 2025
- **Version:** v1.0
- **Current Release:** Ready for Demonstration

---

## ✨ Features

-  RFID Door Lock Security: Provides secure and contactless home access using RFID cards or RFID tags, allowing only authorized users to unlock the door.

-  Smart Fence & Rooftop Lighting: Uses an LDR sensor to automatically turn on the fence and rooftop lights when the ambient light intensity falls below the threshold value of **100**, improving safety and energy efficiency.

-  Garage Parking Assistant: Utilizes an Ultrasonic Sensor to measure the distance between the vehicle and the garage wall. When the distance reaches **2.9 cm or less**, the buzzer alerts the driver for safer parking.

-  Temperature & Humidity Monitoring: Continuously monitors environmental conditions using the DHT11 sensor. The **12V DC fan** automatically turns on when the temperature exceeds **30°C** or the humidity exceeds **60%**.

-  MQ-5 Gas Leak Detection: Detects harmful and flammable gases in the kitchen area. If the gas sensor value exceeds the threshold of **2000**, the system activates the buzzer and displays an alert status.

-  Blynk IoT Mobile Application: Enables users to monitor real-time temperature, humidity, gas levels, and system status through a smartphone using the Blynk IoT platform.

-  Remote Light Control: Allows users to remotely turn ON or OFF the home lighting system from anywhere using the Blynk mobile application over a Wi-Fi connection.

-  LCD Real-Time Display: Displays temperature, humidity, gas values, fan status, light status, and gas safety alerts directly on the LCD screen for quick local monitoring.

---


---
## 📸 Project Gallery

### 🏠 Smart Home Overview

| Complete Smart Home Model | Rooftop Garden & Lighting |
|:-------------------------:|:-------------------------:|
| <img src="images/Project-HiveLink.jpeg" width="420"> | <img src="images/Rooftop-Lights.jpeg" width="420"> |

---

### 💡 Smart Lighting & Security

| App Controlled Lights | Fence Lights, RFID & Ultrasonic |
|:---------------------:|:-------------------------------:|
| <img src="images/App-controlled-Lights.jpeg" width="420"> | <img src="images/FenceLights-RFID-UltraSonic.jpeg" width="420"> |

---

### 🌡 Environment Control

| DHT11 , 12V DC Fan System and MQ5 - Buzzer | LCD Display |
|:-----------------:|:-----------:|
| <img src="images/12v DC-fan.jpeg" width="420"> | <img src="images/LCD-Dispaly.jpeg" width="420"> |

---

### 📱 Blynk IoT Mobile Dashboard

| Blynk IoT Mobile Dashboard |
|:--------------------------:|
| <img src="images/Blynk-IoT.jpeg" width="350"> |

---
