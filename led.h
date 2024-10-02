#pragma once
#include "mbed.h"
class LED {
    private:
        DigitalOut led;
    public:
    LED(PinName pin);
    ~LED()=default;
    DigitalOut* getDigitalOut() { return &led; }
    void setDigitalOut(int s) { led.write(s); }
};

