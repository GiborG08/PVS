#pragma once
#include "mbed.h"

class LED {
    private:
        DigitalOut _led;
        PwmOut _pwmLed;
    public:
    LED(PinName pin) :  _led(pin), _pwmLed(pin)
    {};
    ~LED()=default;
    DigitalOut* getDigitalOut() { return &_led; }
    PwmOut* getPwm() { return &_pwmLed; }
    void setDigitalOut(int s) { _led.write(s); }
};

