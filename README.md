# SIT315
TinkerCAD Arduino board project

# Task M1QP – Interrupt-Based Sense-Think-Act System 

## Overview

In this project, an arduino uno board was used to demonstrate an interrupt-driven sense think and act system. The system uses Pin Change Interrupt (PCI) and a Timer Interrupt to handle three sensors including two digital buttons, one analog potentiometer and an actuator.

## Features

- **Pin Change Interrupts (PCI):**
  - Button 1 (D8) turns the LED ON
  - Button 2 (D9) turns the LED OFF

- **Timer1 Interrupt (every 1 second):**
  - Toggles the LED state (blinking effect)
  - Reads and logs analog sensor value from A0

-  **Modular design:**
  - ISR-safe flag system
  - Separation between event-driven and time-driven logic

-  **Serial output** 
  - for debugging and real-time sensor feedback

---

## Components

- Arduino Uno (or compatible board)
- 2x Pushbuttons (wired to D8, D9)
- 1x Potentiometer (wired to A0)
- 1x LED (D13 with 220Ω resistor)
- Jumper wires, breadboard, and resistors (10kΩ for pull-up)

---

## Pin Configuration

| Component       | Arduino Pin | Interrupt Type  |
|----------------|-------------|-----------------|
| Button 1 (ON)  | D8          | Pin Change (PCI)|
| Button 2 (OFF) | D9          | Pin Change (PCI)|
| LED            | D13         | Output (PWM)    |
| Potentiometer  | A0          | Timer-based     |

---

## How It Works

1. **PCI ISR** detects button presses:
   - D8 sets `ledOnFlag`
   - D9 sets `ledOffFlag`

2. **Timer1 ISR** fires every 1 second:
   - Toggles `toggleLedFlag` (blinking LED)
   - Sets `readSensorFlag` (reads analog input)

3. The `loop()` checks flags and performs:
   - `digitalWrite()` to LED
   - `analogRead()` and `Serial.print()` for sensor value

---

## Circuit Diagram

Link: https://www.tinkercad.com/things/19KuCMHAtY1-surprising-elzing-waasa/ 

---

## File Structure

📁 TaskM1QP/
├── sit315hd.cpp # Final Arduino sketch (.ino or .cpp)
├── README.md # This file
├── Fantastic Vihelmo-Curcan.png # Screenshot of breadboard 
├── board.png # Board diagram

---

## Demonstration

- LED blinks by default (Timer-based)
- Button 1 turns LED ON (PCI)
- Button 2 turns LED OFF (PCI)
- Potentiometer value logged every second
- Serial monitor will display analog values and button events

---

## Setup Instructions

1. Upload `sit315hd.cpp` to Arduino Uno via Arduino IDE
2. Press buttons and adjust potentiometer
3. Observe real-time output and LED behavior

—

## References

- DeakinSync SIT315 Learning Resources
- ChatGPT (README File formatting)
- Robotics Backend (https://roboticsbackend.com/arduino-led-complete-tutorial/)
- Soldered (https://soldered.com/learn/what-is-a-pull-up-pull-down-resistor/)
