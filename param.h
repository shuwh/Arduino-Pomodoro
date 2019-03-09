#ifndef _PARAM_H_
#define _PARAM_H_

// State Machine Defination
const int IDLE = 0;
const int TIME_RUNNING = 2;
const int VIBRATING = 4;
const int WALKING = 8;
const int SNOOZING = 16;
const int SNOOZED = 32;

// Working time Parameters (test use)
// const int WORKINGTIME1 = 20;
// const int WORKINGTIME2 = 15;
// const int VIBRATINGTIME = 10;
// const int SNOOZINGTIME = 15;

// Working time Parameters (test use)
const int WORKINGTIME1 = 20 * 60;
const int WORKINGTIME2 = 15 * 60;
const int VIBRATINGTIME = 10 * 60;
const int SNOOZINGTIME = 15 * 60;

#endif