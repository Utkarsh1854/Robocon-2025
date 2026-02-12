#include <PS4Controller.h>

// Pins (Unchanged)
#define GRIPPER_DIR 2
#define GRIPPER_PWM 4
#define PULLEY_DIR 14
#define PULLEY_PWM 13
#define LOADER_DIR 26
#define LOADER_PWM 25
#define LIMIT_TOP_PIN 5
#define LIMIT_BOTTOM_PIN 18

#define MOTOR_SPEED 80 // Bumped up; 50 is often too low for loaded DC motors

void setup() {
  Serial.begin(115200);

  pinMode(GRIPPER_DIR, OUTPUT);
  pinMode(GRIPPER_PWM, OUTPUT);
  pinMode(PULLEY_DIR, OUTPUT);
  pinMode(PULLEY_PWM, OUTPUT);
  pinMode(LOADER_DIR, OUTPUT);
  pinMode(LOADER_PWM, OUTPUT);

  pinMode(LIMIT_TOP_PIN, INPUT_PULLUP);
  pinMode(LIMIT_BOTTOM_PIN, INPUT_PULLUP);

  PS4.begin("01:02:03:04:05:06"); // Replace with your ESP32 MAC if needed
  Serial.println("System Ready.");
}

void loop() {
  if (PS4.isConnected()) {
    handleGripper();
    handlePulley();
    handleLoader();
  } else {
    stopAll();
  }
}

// === Logic Handlers (Non-Blocking) ===

void handleGripper() {
  if (PS4.Square()) {
    digitalWrite(GRIPPER_DIR, LOW);
    analogWrite(GRIPPER_PWM, MOTOR_SPEED);
  } else if (PS4.Circle()) {
    digitalWrite(GRIPPER_DIR, HIGH);
    analogWrite(GRIPPER_PWM, MOTOR_SPEED);
  } else {
    analogWrite(GRIPPER_PWM, 0);
  }
}

void handlePulley() {
  bool topLimit = (digitalRead(LIMIT_TOP_PIN) == LOW);
  bool bottomLimit = (digitalRead(LIMIT_BOTTOM_PIN) == LOW);

  if (PS4.Triangle() && !topLimit) {
    digitalWrite(PULLEY_DIR, HIGH);
    analogWrite(PULLEY_PWM, MOTOR_SPEED);
  } else if (PS4.Cross() && !bottomLimit) {
    digitalWrite(PULLEY_DIR, LOW);
    analogWrite(PULLEY_PWM, MOTOR_SPEED);
  } else {
    analogWrite(PULLEY_PWM, 0);
  }
}

void handleLoader() {
  if (PS4.L1()) {
    digitalWrite(LOADER_DIR, HIGH);
    analogWrite(LOADER_PWM, MOTOR_SPEED);
  } else {
    analogWrite(LOADER_PWM, 0);
  }
}

void stopAll() {
  analogWrite(GRIPPER_PWM, 0);
  analogWrite(PULLEY_PWM, 0);
  analogWrite(LOADER_PWM, 0);
}
