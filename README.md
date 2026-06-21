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
### 🛠 Hardware Implementation

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
### 🔧 System Internals

| DHT11 Temperature & Humidity | MQ-5 Gas Detection | Ultrasonic & LDR Module |
|:----------------------------:|:------------------:|:-----------------------:|
| <img src="images/DHT11-hardware.jpeg" width="280"> | <img src="images/MQ5-hardware.jpeg" width="280"> | <img src="images/Ultrasonic-LDR-hardware.jpeg" width="280"> |

---
## 🛠 Hardware Components

- **Microcontrollers:** ESP32 DevKit V1, Arduino Uno
- **Sensors:** DHT11, MQ-5, LDR Module, Ultrasonic Sensor (HC-SR04), RFID Module (RC522)
- **Actuators:** 12V DC Fan, Relay Module, Active Buzzer
- **Displays & Indicators:** 16x2 LCD Display, LED Lights
- **Communication:** Wi-Fi (ESP32), Blynk IoT Platform
- **Power Supply:** USB Power Bank / 5V DC Supply

---
## 🏗 System Architecture

### Overall System Architecture

<p align="center">
  <img src="images/System-diagram.jpg" width="850">
</p>

This diagram illustrates the interaction between the ESP32, Arduino Uno, sensors, actuators, and the Blynk IoT platform within the HiveLink Smart Home Automation System.

---

### Internal Circuit Connections

<p align="center">
  <img src="images/System-diagram-internal.jpg" width="850">
</p>

This diagram presents the detailed internal wiring connections of the ESP32 and Arduino Uno, including DHT11, MQ-5 Gas Sensor, RFID RC522, LCD Display, LDR Module, Ultrasonic Sensor, Relay Module, 12V DC Fan, Indoor Lights, and Buzzers.

### Power Management

The HiveLink Smart Home Automation System uses separate power supplies for the ESP32 and Arduino Uno to ensure stable performance.

1. **ESP32 Unit:** Controls DHT11, MQ-5, RFID, LCD, relay, indoor lights, fan, and gas alert buzzer.

2. **Arduino Uno Unit:** Controls the LDR module, Ultrasonic sensor, fence lights, rooftop lights, and parking buzzer.

This design minimizes power interference and improves system reliability.

---
<h2>👥 Team Members & Responsibilities (Y1S1Mtr2)</h2>

<table>
  <tr>
    <th>IT Number</th>
    <th>Name</th>
    <th>Primary Responsibility</th>
    <th>Key Contributions</th>
  </tr>

  <tr>
    <td><b>IT25102735</b></td>
    <td>Jayasekara E.O.</td>
    <td>Temperature Monitoring System</td>
    <td>DHT11 temperature and humidity monitoring, 12V DC fan control using relay module, and LCD display for real-time environmental data.</td>
  </tr>

  <tr>
    <td><b>IT25102198</b></td>
    <td>Nisanka P.G.U.</td>
    <td>Smart Security & Parking System</td>
    <td>RFID card authentication, door access control, ultrasonic sensor integration, and parking assistance alerts.</td>
  </tr>

  <tr>
    <td><b>IT25102205</b></td>
    <td>Hewamana Y.C.K.</td>
    <td>Gas Detection & Safety</td>
    <td>MQ-5 gas sensor integration, gas level monitoring, and gas alert buzzer system.</td>
  </tr>

  <tr>
    <td><b>IT25102657</b></td>
    <td>Thirasara K.W.D.D.</td>
    <td>Smart Lighting System</td>
    <td>LDR-based fence and rooftop lights, indoor smart lights, and Blynk IoT application control.</td>
  </tr>

  <tr>
    <td><b>IT25102894</b></td>
    <td>Wijesinghe Y.N.</td>
    <td>System Architecture</td>
    <td>Designed system architecture, circuit diagrams, integration of ESP32 and Arduino Uno, and overall system coordination.</td>
  </tr>

</table>

---

## 📁 Documentation

Access the complete project documents below:

- [ Project Proposal](Project%20Proposal%20Y1S1%20Mtr2.pdf)
- [ Progress Report](IT1140%20-%20Progress%20report-Mtr02.pdf)
- [ User Manual](HiveLink_User_Manual.pdf)

---

