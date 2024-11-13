#ifndef __UART_H
#define __UART_H

#include "mbed.h"

// class Led
class Uart
{
private:
    void rxInterrupt();
public:
    //! Constructor
    Uart(PinName rx, PinName tx, int baud);

    //! Destructor
    ~Uart();

    bool isCharReceived();
    char getReceivedChar();
    void writeChar(char c);
    UnbufferedSerial* getSerial();
private:
    UnbufferedSerial serial;
    volatile char received_character;
    volatile bool received;
};

#endif
