#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include "mbed.h"

class Button {
private:
    InterruptIn button;
    volatile bool pressed;

public:
    //! Constructor
    Button(PinName pin);

    //! Destructor
    ~Button();

    // Priradenie funkcie pri stlačení tlačidla
    void attachOnPress(Callback<void()> func);

    // Zisťuje, či bolo tlačidlo stlačené
    bool wasPressed();

private:
    void onPress();
};

#endif // BUTTON_H
