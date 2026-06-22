# 📳 Smart Alert Watch for Deaf Users

### IoT-Based Home Safety Notification System Using ESP32, MQTT, and Node-RED

![Platform](https://img.shields.io/badge/Platform-ESP32-green)
![Protocol](https://img.shields.io/badge/Protocol-MQTT-blue)
![Framework](https://img.shields.io/badge/Framework-Node--RED-red)
![Domain](https://img.shields.io/badge/Domain-IoT-orange)

---

## 📌 Overview

The Smart Alert Watch is an IoT-based assistive technology project designed to help deaf and hard-of-hearing individuals receive critical home safety notifications through vibration and visual alerts.

The system consists of three main components:

- A **Home Safety Node** (ESP32 simulated in Wokwi) that monitors gas levels.
- A **Node-RED processing layer** that analyzes incoming sensor data and generates alerts.
- A **Smart Watch Node** (ESP32) that receives alerts and notifies the user using an OLED display, LED indicator, and vibration motor.

When a dangerous gas level is detected, the watch immediately alerts the user without relying on sound.

---

## 🎯 Problem Statement

Traditional home safety systems mainly depend on audible alarms, making them less effective for people with hearing impairments.

This project addresses that challenge by converting emergency notifications into vibration and visual alerts that can be perceived without sound.

Potential applications include:

- Gas leak detection
- Fire alarm notifications
- Home safety alerts
- Emergency warning systems

---

## 🏗️ System Architecture

```text
MQ Gas Sensor
      │
      ▼
┌─────────────────────┐
│ Home Safety Node    │
│ ESP32 (Wokwi)       │
└─────────┬───────────┘
          │ MQTT
          ▼
┌─────────────────────┐
│ Node-RED            │
│ Alert Processing    │
└─────────┬───────────┘
          │ MQTT
          ▼
┌─────────────────────┐
│ Smart Watch Node    │
│ ESP32 DevKit V1     │
└──────┬──────┬───────┘
       │      │
       ▼      ▼
 OLED Display Motor
       │
       ▼
      LED
```

---

## ⚙️ System Components

### Home Safety Node

**Platform:** ESP32 (Wokwi Simulation)

Responsibilities:

- Read gas sensor values
- Detect dangerous gas levels
- Publish sensor data using MQTT
- Simulate a smart home safety system

### Node-RED Processing Layer

Responsibilities:

- Subscribe to MQTT topics
- Process sensor data
- Detect emergency conditions
- Forward alert messages to the watch

### Smart Watch Node

**Platform:** ESP32 DevKit V1

Responsibilities:

- Connect to Wi-Fi
- Subscribe to MQTT alert topics
- Display system status on an OLED screen
- Activate a vibration motor during emergencies
- Provide visual feedback using an LED

### Watch States

| State | OLED Display | LED | Motor |
|---------|---------|---------|---------|
| SAFE | SAFE - State: Normal | OFF | OFF |
| ALERT | ALERT! Gas Leak | ON | ON |

---

## 📡 MQTT Communication

### Topics

| Topic | Purpose |
|---------|---------|
| Home/gas | Gas sensor readings |
| watch/vibrate | Alert notifications |

### Communication Flow

1. The gas sensor monitors environmental gas levels.
2. The Home Safety Node publishes sensor readings through MQTT.
3. Node-RED processes the incoming data.
4. If a dangerous condition is detected, Node-RED publishes an alert.
5. The Smart Watch Node receives the alert.
6. The OLED displays an emergency message.
7. The LED turns ON.
8. The vibration motor activates.

---

## 🛠️ Technologies Used

### Hardware

- ESP32 DevKit V1
- MQ Gas Sensor
- SSD1306 OLED Display (128×64)
- Vibration Motor
- LED

### Software

- Arduino IDE
- ESP32 Arduino Framework
- MQTT
- Node-RED
- Wokwi Simulator

### Libraries

- WiFi.h
- PubSubClient
- Adafruit_GFX
- Adafruit_SSD1306

---

## 🔌 Hardware Connections

### Home Safety Node

| Component | ESP32 Pin |
|------------|------------|
| MQ Gas Sensor (AO) | GPIO 34 |

### Smart Watch Node

| Component | ESP32 Pin |
|------------|------------|
| LED | GPIO 4 |
| Vibration Motor | GPIO 23 |
| OLED Display | I2C |

---

## 📸 Demonstration

### Home Safety Node Simulation

The ESP32 safety node is simulated in Wokwi and publishes gas sensor readings through MQTT.

![Home Safety Node](<img width="1366" height="728" alt="wokwi2" src="https://github.com/user-attachments/assets/4f1a521c-1878-4d7b-a52f-90db0976dabd" />
)

### Node-RED Alert Processing

Node-RED receives sensor data and forwards emergency notifications to the Smart Watch Node.

![Node-RED Flow](<img width="1366" height="728" alt="node-red" src="https://github.com/user-attachments/assets/360cdecd-d12a-40a2-a3ce-7612cc299c33" />)

---

## 🎥 Demo

https://github.com/user-attachments/assets/7a3f2cd2-341b-4c33-9367-3305c6dab1b4

---

## 📊 Results

- Successfully established MQTT communication between ESP32 devices.
- Implemented real-time gas leak alert transmission.
- Integrated Node-RED for event processing and routing.
- Developed an OLED-based user interface.
- Implemented vibration and LED notifications.
- Demonstrated an end-to-end IoT accessibility solution.

---

## 🚀 Future Improvements

- Multiple alert categories
- Custom vibration patterns
- Battery-powered wearable enclosure
- Mobile application integration
- Home Assistant integration
- BLE connectivity
- Additional safety sensors

---

## 🎓 Learning Outcomes

Through this project, I gained practical experience with:

- ESP32 firmware development
- MQTT publish/subscribe architecture
- Node-RED workflow design
- OLED display integration
- IoT system architecture
- Real-time embedded communication
- Accessibility-focused engineering design



