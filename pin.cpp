#include "pin.h"
#include "button.h"
#include "motor.h"
#include "led.h"
#include "Arduino.h"


void pin_setup() {
  // Input Initialize
  pinMode(timePin, INPUT);

  // Output Initialize
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, INPUT);

  // button and button state
	main_button = new Button(main_button_pin);
	snooze_button = new Button(snooze_button_pin);

  motor = new Motor(motorPin);

  led = new LED(ledPin, LOW);
}
