#pragma once

#ifndef LED_H
#define LED_H

#include "mbed.h"

class Led {
private:
    PwmOut led;

public:
    //! Constructor
    Led(PinName pin);

    //! Destructor
    ~Led();

    // Nastaví stav LED
    void set(bool state);

    // Prepne stav LED
    void toggle();

    // Vráti aktuálnu hodnotu PWM (0 alebo 1)
    float getDuty();
};

#endif // LED_H
