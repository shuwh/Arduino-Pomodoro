#include "motor.h"
#include "Arduino.h"

Motor::Motor(int pin)
{
  this->motorPin = pin;
  pinMode(this->motorPin, OUTPUT);
  digitalWrite(this->motorPin, LOW);
}

Motor::~Motor()
{
  digitalWrite(this->motorPin, LOW);
  pinMode(this->motorPin, INPUT);
}

void Motor::start()
{
  digitalWrite(this->motorPin, HIGH);
}

void Motor::stop()
{
  digitalWrite(this->motorPin, LOW);
}
