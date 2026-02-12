🤖 ABU Robocon 2025 – Team Raptors

Robocon is an international robotics competition where engineering students design, build, and program robots to complete a themed challenge.  
This repository showcases the code, documentation, and design work created as part of the project.

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
<img width="347" height="400" alt="image" src="https://github.com/user-attachments/assets/aa31bbd1-a5ba-413f-8750-120cfd4e0d0c" />



---

## ⚙️ Technical Details

### 🔌 Electronics & Control
- Microcontrollers: ESP32, Arduino Mega  
- Motor Drivers: Cytron MDD10, Cytron 20A dual channel  
- Controllers: FlySky FSi6s  
- Sensors: IR array, ultrasonic sensors  

### 🔩 Mechanical
- Drive: 4 omni-wheel configuration (plus pattern)  
- Actuators: Johnson motors 1000RPM, RS37 motors  
- Mechanisms: Ball gripper, loader, lifter  

### 💻 Software
- Language: Embedded C/C++, MATLAB (simulation)  
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

---

## 🎥 Media

https://github.com/user-attachments/assets/9354739f-c9c6-4fa6-b732-47641746f2a6


https://github.com/user-attachments/assets/048daeb4-b0f8-4244-b2fa-2c2cc8078bb7

---

## 🔮 Future Work

- Implement computer vision for autonomous robot navigation.  
- Optimize gripper mechanism for faster object handling.  
- Improve stability & precision in high-speed movements.  

