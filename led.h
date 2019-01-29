#ifndef _LED_H_
#define _LED_H_

#include "Arduino.h"

class LED {
  private:
    byte ledPin;

  public:
    LED(byte pin, bool state=LOW);
    ~LED();
    byte getPin();
    void on();
    void off();
    bool getState();
    void disattach();
    void powerOn();
    void timerRunning();
    void snoozed();
    void walking();
};

#endif
