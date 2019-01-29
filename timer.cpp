#include "timer.h"
#include "Arduino.h"

Timer::Timer(unsigned long threshold, unsigned long step) {
  this.timer = 0;
  this.threshold = threshold;
  this.step = step;
}

Timer::~Timer() {

}

unsigned long Timer::getTimer() {
  return this.timer;
}

void Timer::setTimer(unsigned long timer) {
  this.timer = timer;
}

unsigned long Timer::getThreshold() {
  return this.threshold;
}

void Timer::setThreshold(unsigned long threshold) {
  this.threshold = threshold;
}

void Timer::run() {
  delay(this.step);
  this.timer++;
}

void Timer::reset_timer() {
  this.setTimer(0);
}

void Timer::readTimeSetting(int timePin) {
  if (timePin == HIGH) {
    this.setThreshold(25);
  } else {
    this.setThreshold(10);
  }
}

