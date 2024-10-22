/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "led.h"
#include "button.h"
#include "counter.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     175ms

LED* green = new LED(LED1);
LED* blue = new LED(LED2);
//LED* red = new LED(LED3);

Button* button = new Button(BUTTON1);
Counter* counter = new Counter(BUTTON1);


int main()
{
    green->getPwm()->period(0.01f);
    while (true) {
        green->getPwm()->write(0.10f);
    }
    delete green;
    delete blue;
   // delete red;
    delete button;
}
