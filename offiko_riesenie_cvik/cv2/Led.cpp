#include "Led.h"

// Constructor
Led::Led(PinName pin)
    : led(pin)
{
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

DigitalOut* Led::getDigitalOut()
{
    return &led;
};