# Automated Pharma Inventory Management Robot

Overview

The Automated Pharma Inventory Management Robot is an embedded and IoT-based system designed to automate medicine identification, navigation, and retrieval in pharmacy environments. The system integrates RFID technology, sensor-based navigation, and robotic actuation to improve operational efficiency and reduce human error.

---

Key Features

- RFID-based automatic medicine identification
- Autonomous robot navigation with obstacle detection
- Robotic arm for pick-and-place operations
- Real-time system monitoring via IoT
- Low-cost and scalable embedded solution

---

System Architecture

The system is designed using a layered architecture:

- Sensing Layer: RFID Reader, Ultrasonic Sensor
- Processing Layer: Arduino Uno (ATmega328P)
- Communication Layer: IoT / Wireless Module
- Actuation Layer: DC Motors, Servo Motor

---

Hardware Components

- Arduino Uno
- MFRC522 RFID Reader
- HC-SR04 Ultrasonic Sensor
- L298N Motor Driver
- DC Motors
- Servo Motor
- LCD Display (I2C)
- Power Supply Unit

---

Software Stack

- Embedded C/C++ (Arduino IDE)
- MATLAB (Machine Learning Model)
- Communication Protocols: SPI, I2C, PWM

---

Working Principle

1. System initializes all hardware components
2. RFID reader scans and detects medicine tags
3. Tag ID is matched with stored data
4. Robot navigates to the target location
5. Ultrasonic sensor detects and avoids obstacles
6. Robotic arm performs pick-and-place operation
7. Status is displayed on LCD and updated via IoT

---

Repository Structure

pharma-robot/
│
├── arduino-code/        # Main firmware (.ino)
├── sensors/             # Sensor handling modules
├── robot-control/       # Movement and arm control
├── ml-model/            # MATLAB model
├── docs/                # Project documentation
└── README.md

---

Performance Metrics

- RFID Identification Accuracy: 98%
- Obstacle Detection Accuracy: 95%
- Navigation Success Rate: 93%
- Pick-and-Place Accuracy: 92%

---

Limitations

- Limited RFID detection range (2–5 cm)
- Processing constraints of microcontroller
- Limited payload capacity of robotic arm
- Performance depends on controlled environment

---

Future Enhancements

- Integration of computer vision for medicine recognition
- Cloud-based inventory management system
- Mobile application for remote monitoring and control
- Advanced navigation using SLAM algorithms

---

Setup Instructions

Arduino

1. Install Arduino IDE
2. Install required libraries:
   - MFRC522
   - Servo
   - LiquidCrystal_I2C
3. Upload the firmware to Arduino Uno

MATLAB

1. Open MATLAB
2. Run the provided ".m" file
3. Evaluate model performance metrics

---

Authors

- Nachukuppam Lokesh
- Bhuvaneshwari V
- Preethi S
- Sanjay G

---

Institution

Agni College of Technology
Department of Electronics and Communication Engineering
(Affiliated to Anna University)

---

License

This project is intended for academic and educational use.