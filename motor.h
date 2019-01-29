#ifndef _MOTOR_H_
#define _MOTOR_H_

class Motor {
  private:
    int motorPin;
  
  public:
    Motor(int pin);
    ~Motor();
    void start();
    void stop();
};

#endif