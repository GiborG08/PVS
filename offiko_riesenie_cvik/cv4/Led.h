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
    
    // set duty
    void setDuty(float duty);
    
    // get duty
    float getDuty();
    
    void graduallyOn();

    PwmOut* getPwmOut();

private:
    PwmOut led;

};
#endif
