#include "timer.h"
#include "led.h"

Timer *timer;
LED *led;

void setup()
{
  timer = new Timer(5, 1000);
  led = new LED(13, LOW);
  Serial.begin(9600);
}

void loop()
{
  if (timer->isOvertime())
  {
    timer->reset();
    if (led->getState() == HIGH)
    {
      led->off();
    }
    else
    {
      led->on();
    }
  }
}
