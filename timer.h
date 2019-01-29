#ifndef _TIMER_H_
#define _TIMER_H_

class Timer {
  private:
    unsigned long timer;
    unsigned long threshold;
    unsigned long step;

  public:
    Timer(unsigned long threshold, unsigned long step); // seconds, miliseconds
    ~Timer();

    unsigned long getTimer();
    void setTimer(unsigned long timer);
    unsigned long getThreshold();
    void setThreshold(unsigned long threshold);
    void run();
    void reset_timer();
    void readTimeSetting(int timePin);
};

#endif