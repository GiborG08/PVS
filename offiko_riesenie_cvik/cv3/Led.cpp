#include "Led.h"

// Constructor
Led::Led(PinName pin)
    : led(pin)
{
    led.period_ms(10);
    led = 0;
};

// Destructor
Led::~Led()
{
};

void Led::set(bool s)
{
    if(s)
        led = 1;
    else
        led = 0;
};

void Led::setDuty(float duty)
{
    led.write(duty);
};

void Led::graduallyOn()
{
    for(float i=0 ; i<=1; i=i+0.01)
    {
        this->setDuty(i);
        ThisThread::sleep_for(20ms);
    }
    led = 0;
};