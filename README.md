# 🔧 IR–OLED–Ultrasonic Control

A smart **distance-based LED control system** using **ultrasonic sensing**, **OLED display**, and **IR remote communication**.  
With this project, you can **wirelessly adjust** the trigger distance that controls when the LED turns on or off — all displayed in real time on the OLED screen.

---

## 🚀 Features

- 📏 **Ultrasonic sensor** continuously measures real-time distance
- 🖥️ **OLED display** shows:
  - Current distance
  - Target (trigger) distance
- 📡 **IR remote** lets you:
  - Increase or decrease trigger distance
  - Control settings from a distance
- 🔧 Fully built with **Arduino** and standard modules

---

## ⚙️ Hardware Used

| Component                          | Description                             |
| ---------------------------------- | --------------------------------------- |
| 🔌 **Arduino**                     | Main controller                         |
| 📟 **OLED Display (128x64)**       | For real-time distance and settings     |
| 📡 **Ultrasonic Sensor (HC-SR04)** | Measures object distance                |
| 📶 **IR Receiver + Transmitter**   | Enables remote control                  |
| 🔘 **Remote (5 buttons)**          | Used to adjust the target distance      |
| 💡 **LED**                         | Visual indicator controlled by distance |

---

## 🧠 Working Principle

1. The **ultrasonic sensor** measures the distance to the nearest object.
2. If the distance is **less than the target value**, the **LED turns off**.  
   Otherwise, the LED stays **on**.
3. The **OLED** shows both the current distance and the set target value.
4. Using the **IR remote**, you can:
   - Increase or decrease the target distance

---

## 🖼️ Project Photos

| Description            | Image                                       | Trigger Value |
| ---------------------- | ------------------------------------------- | ------------- |
| LED OFF (object close) | ![LED Off](docs/project-photos/led_off.png) | 10            |
| LED ON (object far)    | ![LED On](docs/project-photos/led_on.png)   | 10            |
| Remote Control         | ![Remote](docs/project-photos/remote.jpg)   |
| OLED Display           | ![OLED](docs/project-photos/oled.jpg)       |
| Full Setup             | ![Setup](docs/project-photos/setup.jpg)     |

---

## 🧩 Code Overview

Main components are divided into modules for clean structure:

- `oled.h` – OLED initialization and display functions
- `ultrasonic.h` – Ultrasonic measurement logic (with led)
- `IR.h` – IR receiver and transmitter handling
- `buttons.h` – Button configuration and input logic
- `main.c` – Core control loop

---

## 🧰 Requirements

- Arduino IDE
- Libraries:
  - `Adafruit_GFX`
  - `Adafruit_SSD1306`
  - `IRremote`
  - `Wire`
