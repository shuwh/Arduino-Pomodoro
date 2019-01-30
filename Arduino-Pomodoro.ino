// include all the required files
// #include "condition.h"
#include "pin.h"
#include "button.h"
#include "led.h"
#include "motor.h"
#include "param.h"
#include "timer.h"

int state;

Timer *workTimer;
Timer *vibrateTimer;
Timer *snoozeTimer;

Button *main_button;
Button *snooze_button;

Motor *motor;

LED *led;

void setup()
{
  // Library Setup
  hardwareSetup();

  // Serial Initialize
  Serial.begin(9600);
  Serial.println("Initialize Counter");

  // State initialize
  state = IDLE;

  workTimer = new Timer(25 * 60, 1000);
  vibrateTimer = new Timer(1 * 60, 1000);
  snoozeTimer = new Timer(5 * 60, 1000);

  main_button = new Button(main_button_pin, LOW, LOW);
  snooze_button = new Button(snooze_button_pin, LOW, LOW);

  motor = new Motor(motorPin);

  led = new LED(ledPin, LOW);
}

void loop()
{
  switch (state)
  {
  case IDLE:
    led->powerOn();
    workTimer->readTimeSetting(timePin);
    if (is_start_button_pressed())
    {
      state = TIME_RUNNING;
    }
    break;
  case TIME_RUNNING:
    led->timerRunning();
    workTimer->run();
    if (is_pause_button_pressed())
    {
      state = IDLE;
    }
    else if (is_preset_time_reached())
    {
      state = VIBRATING;
    }
    else if (is_time_setting_changed())
    {
      state = IDLE;
    }
    else
    {
      state = TIME_RUNNING;
    }
    break;
  case VIBRATING:
    led->powerOff();
    motor->start();
    vibrateTimer->run();
    if (is_walk_button_pressed())
    {
      state = WALKING;
    }
    else if (is_snooze_button_pressed())
    {
      state = SNOOZING;
    }
    else if (is_vibrating_overtime())
    {
      state = WALKING;
    }
    else
    {
      state = VIBRATING;
    }
    break;
  case WALKING:
    led->walking();
    motor->stop();
    workTimer->reset();
    vibrateTimer->reset();
    state = IDLE;
    break;
  case SNOOZING:
    motor->stop();
    snoozeTimer->reset();
    vibrateTimer->reset();
    state = SNOOZED;
    break;
  case SNOOZED:
    led->snoozed();
    snoozeTimer->run();
    if (is_snoozed_time_reached())
    {
      state = VIBRATING;
    }
    else
    {
      state = SNOOZED;
    }
    break;
  }
}

bool is_start_button_pressed()
{
  return main_button->isRiseEdge();
}

bool is_pause_button_pressed()
{
  return main_button->isRiseEdge();
}

bool is_preset_time_reached()
{
  return workTimer->isOvertime();
}

bool is_time_setting_changed()
{
  return workTimer->isThresholdChanged(timePin);
}

bool is_walk_button_pressed()
{
  return main_button->isRiseEdge();
}

bool is_snooze_button_pressed()
{
  return snooze_button->isRiseEdge();
}

bool is_vibrating_overtime()
{
  return vibrateTimer->isOvertime();
}

bool is_snoozed_time_reached()
{
  return snoozeTimer->isOvertime();
}
