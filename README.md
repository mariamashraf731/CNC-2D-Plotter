# ✍️ SketchBot: IoT-Controlled 2D CNC Plotter

![Flutter](https://img.shields.io/badge/App-Flutter-blue)
![Hardware](https://img.shields.io/badge/Hardware-Arduino%20%7C%20ESP8266-orange)
![Drive](https://img.shields.io/badge/Motors-Steppers%20(NEMA)-green)

## 📌 Project Overview
**SketchBot** is a wireless 2D Plotter capable of drawing complex vector graphics and text. The system is controlled via a custom **Flutter Mobile App**, which sends drawing commands over Wi-Fi to the machine.

The project bridges the gap between high-level software (Mobile App) and low-level actuation (Stepper Motors), enabling remote creativity without the need for physical cables.

## ⚙️ System Architecture
1.  **Mobile Application (Flutter):**
    * User interface to select images or text to draw.
    * Converts graphics into coordinates/commands.
    * Sends data to the cloud/controller via WiFi.
2.  **Wireless Bridge (ESP8266):**
    * Receives drawing packets from the app.
    * Forwards commands to the motion controller via UART (Serial).
3.  **Motion Controller (Arduino):**
    * Parses incoming commands (G-Code flavored).
    * Drives X and Y Stepper Motors using **CNC Shield / A4988 Drivers** to move the pen with precision.
    * Controls the Z-axis (Servo) for Pen Up/Down movements.

## 🛠️ Tech Stack
* **Software:** Dart (Flutter), C++ (Embedded).
* **Electronics:** Arduino Uno, ESP8266 (NodeMCU), CNC Shield, Stepper Drivers.
* **Actuators:** NEMA 17 Stepper Motors, Micro Servo (SG90).
* **Mechanics:** 2-Axis Gantry System (GT2 Belts & Pulleys).

## 🚀 How to Run
### 1. Firmware Setup
* Flash `firmware/motion_controller/arduino_main.ino` to the Arduino.
* Flash `firmware/wifi_bridge/esp_handler.ino` to the ESP8266.
* *Note: Ensure Serial Baud rates match in both codes.*

### 2. Mobile App
```bash
cd mobile_app
flutter pub get
flutter run