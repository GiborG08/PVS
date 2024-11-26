#include "Button.h"

//! Constructor
Button::Button(PinName pin) : button(pin), pressed(false) {
    button.mode(PullUp); // Nastavenie s pull-up rezistorom
    button.rise(callback(this, &Button::onPress)); // Prerušenie pri stlačení tlačidla
}

//! Destructor
Button::~Button() {}

// Priradenie funkcie pri stlačení tlačidla
void Button::attachOnPress(Callback<void()> func) {
    button.rise(func);
}

// Zisťuje, či bolo tlačidlo stlačené
bool Button::wasPressed() {
    if (pressed) {
        pressed = false;
        return true;
    }
    return false;
}

// Interná funkcia pri stlačení tlačidla
void Button::onPress() {
    pressed = true;
}
