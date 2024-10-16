#ifndef __LED_H
#define __LED_H

#include "mbed.h"

// class Led
class Led 
{
private:

public:
    //! Constructor
    Led(PinName pin);

    //! Destructor
    ~Led();

    // set value
    void set(bool s);

    DigitalOut* getDigitalOut();

private:
    DigitalOut led;

};

#endif
