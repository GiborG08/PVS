/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 

#include "mbed.h"
#include "led.h"
#include "button.h"
#include "counter.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     175ms

DigitalOut* green = new DigitalOut(LED1);
DigitalOut* blue = new DigitalOut(LED2);
DigitalOut* red = new DigitalOut(LED3);

Button* button = new Button(BUTTON1);
Counter* counter = new Counter(BUTTON1);


void binar(int cislo){
    green->write(0);
    blue->write(0);
    red->write(0);
    switch (cislo) {
        case 1:
            green->write(1);
            break;
        case 2:
            blue->write(1);
            break;
        case 3:
            green->write(1);
            blue->write(1);
            break;
        case 4:
            red->write(1);
            break;
        case 5:
            red->write(1);
            green->write(1);
            break;
        case 6:
            red->write(1);
            blue->write(1);
            break;
        case 7:
            red->write(1);
            blue->write(1);
            green->write(1);
            break;   
        default:
            break;    
    }
}

int main()
{
    // Initialise the digital pin LED1 as an output

    

    int press = button->getButton()->read();
    while (true) {
        /**ledka1 = !(*ledka1);
        ThisThread::sleep_for(BLINKING_RATE);
        *ledka1 = !(*ledka1);
        *ledka2 = !(*ledka2);
        ThisThread::sleep_for(BLINKING_RATE);
        *ledka2 = !(*ledka2);
        *ledka3 = !(*ledka3);
        ThisThread::sleep_for(BLINKING_RATE);
        *ledka3 = !(*ledka3);
        if (press) {
            ledka1->write(!ledka1->read());
        } 
        ThisThread::sleep_for(BLINKING_RATE)
        binar(counter->read());
        ThisThread::sleep_for(BLINKING_RATE);
    }
    delete green;
    delete blue;
    delete red;
    delete button;
}*/

