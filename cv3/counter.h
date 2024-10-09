#pragma once
#include "mbed.h"

class Counter {
    private:
        InterruptIn _interrupt;
        volatile int _count = 0;
    public:
    Counter(PinName pin) : _interrupt(pin)
    {
        _interrupt.rise(callback(this, &Counter::increment));
    };
    ~Counter()=default;
    void increment(){ 
        if (_count > 7) {
            _count = 0;
        };
        _count++;
    }
    int read(){ return _count; }
};

