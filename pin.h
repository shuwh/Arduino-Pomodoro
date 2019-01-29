#ifndef _PIN_H_
#define _PIN_H_

#include "button.h"
#include "motor.h"
#include "led.h"

// Pin Defination
const int timePin = 10;
const int motorPin = 13;
Motor* motor;

// Led
const int ledPin = 14;
LED* led;


// button and button state
const int main_button_pin = 11;
const int snooze_button_pin = 12;
Button* main_button;
Button* snooze_button;

void hardwareSetup();

#endif