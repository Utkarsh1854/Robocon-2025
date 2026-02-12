#include <Arduino.h>
// === PINS ===
#define TRIG1_PIN    12
#define ECHO1_PIN    14
#define TRIG2_PIN    27
#define ECHO2_PIN    34 // MOVED from 26 (Conflict)

#define UP_DIR_PIN   32
#define UP_PWM_PIN   33
#define HOLD_DIR_PIN 25
#define HOLD_PWM_PIN 26
#define LOAD_DIR_PIN 4
#define LOAD_PWM_PIN 5

#define RC_LIFT_PIN     15
#define RC_GRIP_PIN     2
#define RC_LOAD_PIN     0 // Warning: Boot Pin
#define RC_DRIBBLE_PIN  13

#define PWM_CH_UP    0
#define PWM_CH_HOLD  1
#define PWM_CH_LOAD  2
#define PWM_FREQ     1000
#define PWM_RES      8

enum DribbleState { IDLE, RELEASING, WAITING_DROP, CATCHING };
DribbleState state = IDLE;
unsigned long timer = 0;

long readDistance(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long dur = pulseIn(echo, HIGH, 25000);
  return (dur == 0) ? 9999 : (long)((dur * 0.343) / 2.0);
}

void setMotor(int dirPin, int ch, bool dir, int spd) {
  digitalWrite(dirPin, dir);
  ledcWrite(ch, spd);
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG1_PIN, OUTPUT); pinMode(ECHO1_PIN, INPUT);
  pinMode(TRIG2_PIN, OUTPUT); pinMode(ECHO2_PIN, INPUT);

  pinMode(UP_DIR_PIN, OUTPUT); pinMode(HOLD_DIR_PIN, OUTPUT); pinMode(LOAD_DIR_PIN, OUTPUT);
  
  pinMode(RC_LIFT_PIN, INPUT); pinMode(RC_GRIP_PIN, INPUT);
  pinMode(RC_LOAD_PIN, INPUT); pinMode(RC_DRIBBLE_PIN, INPUT);

  ledcSetup(PWM_CH_UP, PWM_FREQ, PWM_RES); ledcAttachPin(UP_PWM_PIN, PWM_CH_UP);
  ledcSetup(PWM_CH_HOLD, PWM_FREQ, PWM_RES); ledcAttachPin(HOLD_PWM_PIN, PWM_CH_HOLD);
  ledcSetup(PWM_CH_LOAD, PWM_FREQ, PWM_RES); ledcAttachPin(LOAD_PWM_PIN, PWM_CH_LOAD);
}

void loop() {
  int rcLift = pulseIn(RC_LIFT_PIN, HIGH, 25000);
  int rcGrip = pulseIn(RC_GRIP_PIN, HIGH, 25000);
  int rcLoad = pulseIn(RC_LOAD_PIN, HIGH, 25000);
  int rcDribble = pulseIn(RC_DRIBBLE_PIN, HIGH, 25000);

  long dist = (readDistance(TRIG1_PIN, ECHO1_PIN) + readDistance(TRIG2_PIN, ECHO2_PIN)) / 2;

  // Manual Control
  if (state == IDLE) {
    if (rcLift > 1700) setMotor(UP_DIR_PIN, PWM_CH_UP, true, 200);
    else if (rcLift > 0 && rcLift < 1300) setMotor(UP_DIR_PIN, PWM_CH_UP, false, 200);
    else ledcWrite(PWM_CH_UP, 0);

    if (rcGrip > 1500) setMotor(HOLD_DIR_PIN, PWM_CH_HOLD, true, 150);
    else ledcWrite(PWM_CH_HOLD, 0);

    if (rcLoad > 1500) setMotor(LOAD_DIR_PIN, PWM_CH_LOAD, true, 200);
    else ledcWrite(PWM_CH_LOAD, 0);
  }

  // Dribble Logic
  if (rcDribble > 1500 && state == IDLE && dist > 950) {
    state = RELEASING;
    timer = millis();
  } else if (rcDribble < 1500 && state != IDLE) {
    state = IDLE;
    ledcWrite(PWM_CH_LOAD, 0);
    ledcWrite(PWM_CH_HOLD, 0);
  }

  switch (state) {
    case RELEASING:
      setMotor(LOAD_DIR_PIN, PWM_CH_LOAD, true, 200);
      if (millis() - timer > 1500) {
        ledcWrite(PWM_CH_LOAD, 0);
        state = WAITING_DROP;
        timer = millis();
      }
      break;

    case WAITING_DROP:
      if (dist < 750) {
        state = CATCHING;
        timer = millis();
      } else if (millis() - timer > 3000) {
        state = IDLE;
      }
      break;

    case CATCHING:
      setMotor(HOLD_DIR_PIN, PWM_CH_HOLD, true, 150);
      if (millis() - timer > 1000) {
        ledcWrite(PWM_CH_HOLD, 0);
        state = IDLE;
      }
      break;
  }
  delay(10);
}
