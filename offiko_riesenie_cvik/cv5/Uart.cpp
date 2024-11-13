#include "Uart.h"

// Constructor
Uart::Uart(PinName tx, PinName rx, int baud = 9600)
    : serial(tx, rx, baud)
{
    received = false;
    received_character = ' ';
     // Set desired properties
    serial.baud(baud);
    serial.format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );
    serial.attach(callback(this, &Uart::rxInterrupt), SerialBase::RxIrq);
};


void Uart::rxInterrupt()
{
    char c;
    serial.read(&c, 1);
    received_character = c;
    received = true;
};

// Destructor
Uart::~Uart()
{
};

bool Uart::isCharReceived()
{
    if(received)
    {
        received = false;
        return true;
    }
    else 
        return false;
};

char Uart::getReceivedChar()
{
    return received_character;
};

void Uart::writeChar(char c)
{
    serial.write(&c, 1);
};

UnbufferedSerial* Uart::getSerial()
{
    return &serial;
};