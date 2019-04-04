#ifndef _PIN_H_
#define _PIN_H_

// #include "button.h"
// #include "motor.h"
// #include "led.h"
// #include "Arduino.h"

const int timePin = 11;
const int motorPin = 9;
// extern Motor *motor;

const int ledPin = 13;
// extern LED *led;

const int main_button_pin = 2;
const int snooze_button_pin = 3;

const int batteryEnablePin = 6;
const int batteryMonitorPin = 7;
const int batteryLEDPin = 12;
// extern Button *main_button;
// extern Button *snooze_button;

// class Pins
// {
// public:
//   static const int timePin = 10;
//   static const int motorPin = 13;
//   static const int ledPin = 14;
//   static const int main_button_pin = 11;
//   static const int snooze_button_pin = 12;
//   void hardwareSetup();
// };

void hardwareSetup();

#endif