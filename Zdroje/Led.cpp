#include "Led.h"

//! Constructor
Led::Led(PinName pin) : led(pin) {
    led = 0; // LED je na začiatku vypnutá
}

//! Destructor
Led::~Led() {}

// Nastaví stav LED
void Led::set(bool state) {
    led = state;
}

// Prepne stav LED
void Led::toggle() {
    led = !led;
}

// Vráti aktuálnu hodnotu PWM (0 alebo 1)
float Led::getDuty() {
    return led.read();
}
