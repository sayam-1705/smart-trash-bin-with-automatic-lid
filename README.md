# 🗑️ Smart Trash Bin with Automatic Lid (Arduino-Based)

### 📍 Project Overview
The **Smart Trash Bin with Automatic Lid** is an Arduino-based system designed to promote **touchless waste disposal** using **ultrasonic and PIR sensors**.  
The bin lid opens automatically when a person approaches and closes after a short delay, accompanied by an audible buzzer warning.  
This project encourages **hygiene, automation, and user convenience** — ideal for smart home or public hygiene applications.

---

## 🧠 Key Features

| Feature | Description |
|----------|-------------|
| **Dual-Sensor Detection** | Uses Ultrasonic and PIR sensors for precise motion and proximity detection. |
| **Automatic Lid Operation** | Servo motor opens and closes the lid based on user presence. |
| **Warning Buzzer** | Alerts the user before the lid closes automatically. |
| **Timed Control** | Adjustable open and warning durations through software variables. |
| **Energy Efficient** | System remains idle until movement or object is detected. |
| **Simple, Hygienic, Contactless** | Prevents the need for manual touch, promoting sanitation. |

---

## 🧩 Components Used

| Component | Quantity | Function |
|------------|-----------|-----------|
| Arduino UNO | 1 | Main controller |
| HC-SR04 Ultrasonic Sensor | 1 | Measures object distance |
| PIR Motion Sensor | 1 | Detects human motion |
| Servo Motor (SG90/MG90S) | 1 | Opens and closes lid |
| Buzzer | 1 | Provides sound warning before closing |
| Breadboard & Jumper Wires | — | For wiring and assembly |
| Power Supply (5V) | 1 | Powers Arduino and servo |

---

## ⚙️ Working Principle

1. **Detection Phase**
   - The **Ultrasonic sensor** continuously measures the distance in front of the bin.  
   - The **PIR sensor** monitors motion in its field of view.

2. **Activation**
   - If the **Ultrasonic sensor** detects an object within **15 cm**, or  
   - The **PIR sensor** detects motion within **30 cm**,  
   → The servo motor rotates to **90°**, opening the lid.

3. **Warning & Closure**
   - After **2.5 seconds**, a buzzer beeps as a **warning** before closing.  
   - After **3 seconds**, the servo returns to **0°**, closing the lid.

4. **Reset Phase**
   - The system resets and waits for the next detection event.

---

## 🧾 Circuit Connection Table

| Component | Arduino Pin | Description |
|------------|--------------|-------------|
| HC-SR04 TRIG | D10 | Ultrasonic trigger output |
| HC-SR04 ECHO | D11 | Ultrasonic echo input |
| PIR Sensor OUT | D2 | Motion detection input |
| Servo Signal | D9 | Lid motor control |
| Buzzer | D3 | Warning sound output |
| 5V / GND | — | Power and ground for all modules |

---

## 🧱 Block Diagram

    ┌─────────────────────────────────┐
    │           Arduino UNO           │
    ├─────────────────────────────────┤
    │  Ultrasonic Sensor → D10 (TRIG) │
    │  Ultrasonic Sensor → D11 (ECHO) │
    │  PIR Motion Sensor → D2         │
    │  Servo Motor → D9               │
    │  Buzzer → D3                    │
    │  Power (5V, GND) → All Modules  │
    └─────────────────────────────────┘

---

## 💻 Arduino Code

> Full source code: [`Smart_Trash_Bin.ino`](https://github.com/sayam-1705/smart-trash-bin-with-automatic-lid/blob/main/smart_dustbin.ino)

The code performs the following tasks:
- Reads data from **Ultrasonic** and **PIR** sensors.  
- Controls **servo motor** for lid movement.  
- Uses **timing logic** for automatic closing.  
- Activates **buzzer warning** before closure.  
- Prints debug information to the **Serial Monitor**.

---

## 🔍 Verification & Testing

| Test | Expected Behavior |
|------|--------------------|
| **System Power ON** | Serial monitor shows “System Initialized. Waiting for motion…” |
| **Ultrasonic Detection** | Object within 15 cm → Lid opens. |
| **PIR Detection** | Motion detected within 30 cm → Lid opens. |
| **Buzzer** | Beeps once before the lid closes. |
| **Servo Motor** | Opens (90°) and closes (0°) the bin lid automatically. |

Use the **Serial Monitor** at **9600 baud** to observe distance readings and status messages.

---

## 🧮 Timing Configuration

| Event | Duration | Variable Name |
|--------|-----------|----------------|
| Lid Open Duration | 3 seconds | `lidOpenTime` |
| Warning Beep Time | 2.5 seconds | `warningTime` |
| Sensor Read Interval | 100 ms | `delay(100)` in loop |

---

## 🧠 Project Impact

- **Technical Impact:** Demonstrates real-time sensor integration and servo automation using Arduino.  
- **Social Impact:** Promotes hygiene by enabling contactless trash disposal.  
- **Environmental Impact:** Encourages clean waste management behavior in public areas.  

---

## 🧰 Future Enhancements

- Add **LCD display** for system messages.  
- Integrate **IR sensors** for improved precision.  
- Add **weight sensor** to detect trash level.  
- Include **solar-powered** operation for outdoor use.  
- Enable **IoT monitoring** for smart waste collection systems.  

---

## 👨‍💻 Project Details

- **Hardware Platform:** Arduino UNO R3  
- **Programming Language:** C++ (Arduino IDE)  
- **Version:** 1.0  
- **Project Type:** Personal Academic Project  
- **Repository Purpose:** Documentation and demonstration of embedded automation.  

---

## ⚖️ Personal Use Notice

This project is created for **personal and academic demonstration purposes only.**  
You are free to view, learn, and replicate this design for **educational or non-commercial projects**.  
Please credit the author if you reference or use any part of the code or documentation.

---

### 🚀 *Smart automation for a cleaner and more hygienic world.*
