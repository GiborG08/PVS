#ifndef __BUTTON_H
#define __BUTTON_H

#include "mbed.h"

// class Led
class Button
{
private:
    void interrupt();
public:
    //! Constructor
    Button(PinName pin);

    //! Destructor
    ~Button();

    // get value
    bool read(void);

    bool wasPressed(void);
    // get number of button pressed
    uint16_t getCount(void);

private:
    InterruptIn button;
    volatile bool pressed;
    volatile uint16_t counter;
};

#endif
