/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output

    DigitalOut* ledka1 = new DigitalOut(LED1);
    DigitalOut* ledka2 = new DigitalOut(LED2);
    DigitalOut* ledka3 = new DigitalOut(LED3);

    while (true) {
        *ledka1 = !(*ledka1);
        ThisThread::sleep_for(BLINKING_RATE);
        *ledka1 = !(*ledka1);
        *ledka2 = !(*ledka2);
        ThisThread::sleep_for(BLINKING_RATE);
        *ledka2 = !(*ledka2);
        *ledka3 = !(*ledka3);
        ThisThread::sleep_for(BLINKING_RATE);
        *ledka3 = !(*ledka3);
    }
    delete ledka1;
    delete ledka2;
    delete ledka3;
}
