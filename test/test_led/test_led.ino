#include "led.h"

const int ledPin = 13;
LED *led;
LED *led2;

void setup()
{
  // led = new LED(ledPin, LOW);
  led2 = new LED(ledPin, LOW);
};

void loop()
{
  // led->on();
  // delay(1000);
  // led->off();
  // delay(1000);

  led2->periodBlink(200, 5, 3000);
}