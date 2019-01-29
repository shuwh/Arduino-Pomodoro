#include "motor.h"
#include "Arduino.h"

Motor::Motor(int pin) {
  this.motorPin = pin;
  pinMode(this.motorPin, OUTPUT);
  digitalWrite(this.motorPin, LOW);
}

Motor::~Motor() {
  digitalWrite(this.motorPin, LOW);
  pinMode(this.motorPin, INPUT);
}

void Motor::startMotor() {
  digitalWrite(this.motorPin, HIGH);
}

void Motor::stopMotor() {
  digitalWrite(this.motorPin, LOW);
}

