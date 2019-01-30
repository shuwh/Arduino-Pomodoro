// #include "pin.h"
// #include "param.h"
#include "button.h"
#include "timer.h"
#include "Arduino.h"

extern Button *main_button;
extern Button *snooze_button;
extern const int timePin;

extern Timer *workTimer;
extern Timer *vibrateTimer;
extern Timer *snoozeTimer;

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