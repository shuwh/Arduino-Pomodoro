#include "motor.h"
#include "button.h"

const int motorPin = 9;
const int buttonPin = 2;
Button *button;
Motor *motor;

void setup()
{
  button = new Button(buttonPin);
  motor = new Motor(motorPin);
}

void loop()
{
  if (button->isRiseEdge())
  {
    motor->reverse();
  }
}