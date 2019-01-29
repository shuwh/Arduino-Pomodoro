#include "led.h"
#include "Arduino.h"

LED::LED(byte pin, bool state) {
  this.ledPin = pin;
  pinMode(this.ledPin, OUTPUT);
  digitalWrite(this.ledPin, state);
}

LED::~LED() {
  disattach();
} 

void LED::on() {
  digitalWrite(this.ledPin, HIGH);
}

void LED::off() {
  digitalWrite(this.ledPinj, LOW);
}

bool LED::getState() {
  return digitalRead(this.ledPin);
}

void LED::disattach() {
  digitalWrite(this.ledPin, LOW);
  pinMode(this.ledPin, INPUT);
}