#include "Uart.h"

//! Constructor
Uart::Uart(PinName tx, PinName rx, int baud) : serial(tx, rx) {
    serial.baud(baud); // Nastavenie prenosovej rýchlosti
}

//! Destructor
Uart::~Uart() {}

// Tlačí reťazec
void Uart::print(const char* message) {
    while (*message) {
        serial.write(message++, 1);
    }
}

// Tlačí formátovaný reťazec s hodnotou
void Uart::print(const char* format, int value) {
    char buffer[128];
    snprintf(buffer, sizeof(buffer), format, value);
    print(buffer);
}
