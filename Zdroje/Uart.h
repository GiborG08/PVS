#pragma once

#ifndef UART_H
#define UART_H

#include "mbed.h"

class Uart {
private:
    UnbufferedSerial serial;

public:
    //! Constructor
    Uart(PinName tx, PinName rx, int baud);

    //! Destructor
    ~Uart();

    // Tlačí reťazec
    void print(const char* message);

    // Tlačí formátovaný reťazec s hodnotou
    void print(const char* format, int value);
};

#endif // UART_H
