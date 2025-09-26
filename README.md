<img width="339" height="149" alt="image" src="https://github.com/user-attachments/assets/38d55911-8de3-43e0-b290-50a7eba6e788" /># 🤖 ABU Robocon 2025 – Team Raptors

Robocon is an international robotics competition where engineering students design, build, and program robots to complete a themed challenge.  
This repository showcases the code, documentation, and design work I created as part of the project.

## 📌 About Robocon 2025
- **Theme:** ROBOT BASKETBALL  
- **Objective:** In the robot basketball game, the red and blue teams, each consisting of two robots, compete to score points by shooting the ball into the opponents' basket while defending their own.
- **Arena:**  
  <img width="339" height="149" alt="image" src="https://github.com/user-attachments/assets/c53d174d-ae4c-4805-b4ac-170fc5936566" />

## 🦾 Our Robots
- **Robot 1 (Semi-Autonomous): responsible for dribbling the ball and then passing it to the second robot.    
- **Robot 2 (Semi-Autonomous): catching the ball from Robot 1, then continuing the dribble, and finally completing the task by placing the ball into the basket
- **Key Features:**
  - Both robots are the same 
  - Custom chassis with omni-wheels  
  - Gripper + loader mechanism for handling objects  
  - Stable drive system with planetary gear motors  

![Robot Image](docs/robot.png) <!-- Replace with your team photo or CAD -->

---

## ⚙️ Technical Details

### 🔌 Electronics & Control
- Microcontrollers: ESP32, Arduino Mega  
- Motor Drivers: Cytron MDD10, Cytron 20A dual channel  
- Controllers: FlySky FSi6s  
- Sensors: IR array, ultrasonic sensors  

### 🔩 Mechanical
- Drive: 4 omni-wheel configuration (plus pattern)  
- Actuators: MG555 motors, RS37 motors  
- Mechanisms: Ball gripper, loader, lifter  

### 💻 Software
- Language: Arduino C/C++, MATLAB (simulation)  
- Logic: Manual + semi-autonomous control, PWM motor control, sensor integration  
- Future: Autonomous navigation with vision (planned for 2026)  

### 🔋 Power
- Batteries: 12V LiPo  
- Protection: 2A glass tube fuse, LM2596 buck converters  

---

## 👨‍💻 My Contribution
- Designed and implemented the **drive system** using MDD10 + Arduino Mega.  
- Built **loader & gripper mechanism** with custom motor logic.  
- Integrated **FSi6s transmitter switches** for control of loader and gripper.  
- Worked on **safety and power distribution** (buck converters, fuses).  

---

## 🏆 Achievements
- Cleared **National Stage 2025** with **96/100 score**.  
- Ranked **Top 20 in 2024**.  
- Presented robotics solutions at multiple college & national-level events.  

---

## 🎥 Media
- Robot Demo Video: [YouTube Link Here]  
- Photos:  
  ![Robot Demo](media/demo.gif)  

---

## 🚀 How to Run Code
1. Install **Arduino IDE**  
2. Add required libraries (Servo, Cytron motor driver, etc.)  
3. Upload `drive_system.ino` to Arduino Mega  
4. Connect receiver → motor driver → motors  
5. Power on & control with RC transmitter  

---

## 🔮 Future Work
- Implement computer vision for autonomous robot navigation.  
- Optimize gripper mechanism for faster object handling.  
- Improve stability & precision in high-speed movements.  

---

## 🐦 Team Raptors
- Team of passionate engineers from [Your College Name].  
- Focused on building competitive robots for **ABU Robocon** and other robotics challenges.  
- [Add social links / YouTube / Instagram if available]

---
