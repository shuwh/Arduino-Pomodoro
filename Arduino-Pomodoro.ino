// include all the required files
#include "param.h"
#include "condition.h"
#include "led.h"
#include "utility.h"
#include "pin.h"
#include "button.h"


void setup() {
  // Library Setup 
  hardwareSetup();

  // Serial Initialize
  Serial.begin(9600);
  Serial.println("Initialize Counter");

  // State initialize
  state = IDEL;
  workTimer = new Timer(25*60, 1000);
  vibrateTimer = new Timer(1*60, 1000);
  snoozeTimer = new Timer(5*60, 1000);
}

void loop() {
 switch (state) {
  case IDEL:
    // led_power_on();
    workTimer -> readTimeSetting(timePin);
    if (is_start_button_pressed()) {
      state = TIME_RUNNING;
    }
    break;
  case TIME_RUNNING:
    // led_timer_running();
    workTimer -> run();
    if (is_pause_button_pressed()) {
      state = IDLE;
    } else if (is_preset_time_reached()) {
      state = VIBRATING;
    } else if (is_time_setting_changed()) {
      state = IDLE;
    } else {
      state = TIME_RUNNING;
    }
    break;
  case VIBRATING:
    motor -> start();
    vibrateTimer -> run();
    if (is_walk_button_pressed()) {
      state = WALKING;
    } else if (is_snooze_button_pressed()) {
      state = SNOOZING;
    } else if (is_vibrating_overtime()) {
      state = WALKING;
    } else {
      state = VIBRATING;
    }
    break;
  case WALKING:
    motor -> stop();
    workTimer -> reset();
    vibrateTimer -> reset();
    state = IDLE;
    break;
  case SNOOZING:
    motor -> stop();
    snoozeTimer -> reset();
    vibrateTimer -> reset();
    state = SNOOZED; 
    break;
  case SNOOZED:
    snoozeTimer -> run();
    if (is_snoozed_time_reached()) {
      state = VIBRATING;
    } else {
      state = SNOOZED;
    }
    break;
 }
}
