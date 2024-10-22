#pragma once
#include "mbed.h"

class Button {
    private:
        DigitalIn* _button;
    public:
    Button(PinName pin){ _button= new DigitalIn(pin); }
    ~Button(){ delete _button; }
    DigitalIn* getButton() { return _button; }

};