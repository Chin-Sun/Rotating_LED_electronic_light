

[![Rotating LED electronic light](https://res.cloudinary.com/marcomontalbano/image/upload/v1654680990/video_to_markdown/images/youtube--um-tjEZWeqE-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/um-tjEZWeqE "Rotating LED electronic light")  

# 🔧 Rotating LED Electronic Light Development

📅 **Project Date:** June 2019  
🔗 **GitHub Repository:** [Rotating_LED_electronic_light](https://github.com/Chin-Sun/Rotating_LED_electronic_light)

## 📌 Overview

This project involves the complete design and implementation of a **rotating LED electronic display system** that functions as a real-time clock, thermometer, and message display. It integrates hardware circuit design, embedded programming, and system debugging.

---

## 🧩 Key Features

- Real-time **temperature and time display** using rotating LED lighting
- Embedded system capable of **clock functionality**
- Modular design with **display**, **time**, and **infrared control** subsystems
- **Stable performance** and responsive display output through precise timing and hardware control

---

## 🔧 Hardware Design

- **PCB Design Tool:** Altium Designer  
- **Microcontrollers & Chips Used:**
  - `STC12C5A32S2`: Main microcontroller for logic control and peripheral communication
  - `DS1302`: Real-Time Clock (RTC) chip for time tracking
  - `CH340G`: USB to serial chip for PC-to-microcontroller communication
  - Additional components: IR receiver module, temperature sensor, LEDs, resistors, capacitors

- **Modules Designed:**
  - **Display Control Module:** Controlled the LED rotation and content update
  - **Time Module:** Synced with the RTC chip for real-time clock functions
  - **Infrared Module:** Enabled remote control interaction using IR receiver

---

## 💻 Embedded Programming

- **Language:** C/C++  
- **IDE/Compiler:** Keil uVision  
- **Key Software Components:**
  - Initialization and communication setup for each hardware module (I²C/SPI/UART)
  - Timer interrupts for controlling LED refresh rate and rotation speed
  - Custom display logic to encode time and temperature into LED binary patterns
  - Error handling and signal filtering for the IR receiver input

---

## 🛠️ Development Process

1. **Requirements Analysis** – Defined display behavior, real-time functions, and power needs  
2. **Circuit Design & Simulation** – Created schematic and PCB layout in Altium Designer  
3. **Component Testing** – Breadboard testing of modules before integration  
4. **Embedded Software Development** – Wrote and tested C++ firmware for each functional module  
5. **System Integration** – Combined all modules and performed debugging and timing adjustments  
6. **Final Testing** – Verified real-time accuracy, display stability, and IR control responsiveness

---

## 📚 Core Skills Demonstrated

- **Hardware development** (PCB design, schematic reading, microcontroller integration)  
- **Low-level embedded programming** (C/C++, register manipulation, timer control)  
- **Microchip datasheet comprehension** and protocol integration  
- **Debugging and testing** both on software and hardware levels  
- **System thinking** in modular design and integration
