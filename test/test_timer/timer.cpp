// #include "timer.h"
// #include "Arduino.h"

// Timer::Timer(unsigned int threshold, unsigned int step = 1000)
// {
//   this->timer = 0;
//   this->threshold = threshold;
//   this->step = step;
//   this->prevTime = millis();
// }

// Timer::~Timer()
// {
// }

// unsigned int Timer::getTimer()
// {
//   return this->timer;
// }

// void Timer::setTimer(unsigned int timer)
// {
//   this->timer = timer;
// }

// unsigned int Timer::getThreshold()
// {
//   return this->threshold;
// }

// void Timer::setThreshold(unsigned int threshold)
// {
//   this->threshold = threshold;
// }

// void Timer::run()
// {
//   unsigned long curtTime = millis();
//   if (curtTime - this->prevTime >= this->step)
//   {
//     this->timer++;
//     this->prevTime = curtTime;
//   }
// }

// void Timer::reset()
// {
//   this->setTimer(0);
// }

// void Timer::readTimeSetting(int timePin)
// {
//   if (timePin == HIGH)
//   {
//     this->setThreshold(25 * 60);
//   }
//   else
//   {
//     this->setThreshold(10 * 60);
//   }
// }

// bool Timer::isOvertime()
// {
//   this->run();
//   return this->getTimer() >= this->getThreshold();
// }
