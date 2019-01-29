#ifndef _PARAM_H_
#define _PARAM_H_

#include "timer.h"

// State Machine Defination
const int IDLE = 0;
const int TIME_RUNNING = 2;
const int VIBRATING = 4;
const int WALKING = 8;
const int SNOOZING = 16;
const int SNOOZED = 32;
int state;

// Global Defination
// unsigned long work_timer;
// unsigned long work_time_threshold;
// unsigned long vibrate_timer;
// const unsigned long vibrate_time_threshold = 60;
// unsigned long snooze_timer;
// const unsigned long snooze_time_threshold = 60;

Timer* workTimer;
Timer* vibrateTimer;
Timer* snoozeTimer;

#endif