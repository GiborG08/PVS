#include "Button.h"

// Constructor
Button::Button(PinName pin)
    : button(pin)
{
    counter = 0;
    pressed = false;
    button.rise(callback(this, &Button::interrupt)); // attach increment function of this counter instance
    // set pin mode : PullUp / PullDown / PullNone / OpenDrain
};


void Button::interrupt()
{
    pressed = true;
    counter++;
    if(counter >= 8)
        counter=0;
};

// Destructor
Button::~Button()
{
};

bool Button::read(void)
{
    return button.read();
};

bool Button::wasPressed(void)
{
    if(pressed)
    {
        pressed = false;
        return true;
    }
    else
        return false;
};

uint16_t Button::getCount(void)
{
    return counter;
};