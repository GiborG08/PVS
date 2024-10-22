#include "mbed.h"
#include "Led.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

#define GREEN_LED     PC_7   // LD1 LED_GREEN
#define BLUE_LED      PB_7   // LD2 LED_BLUE
#define RED_LED       PG_2   // LD3 LED_RED

/* int main()
{
   
    DigitalOut gLed(GREEN_LED);                 // Initialise the digital pin LED1 as an output
    DigitalOut* p_green = &gLed;                // Pointer on gLed
    *p_green = 0;                               // Dereferencing operator
    p_green->write(0);                          // Call by pointer
    Led bLed(BLUE_LED);                         // Initialise the object of Led class on pin PB_7
    DigitalOut *red = new DigitalOut(RED_LED);  //  New Operator in C++ for Dynamic Memory.
    gLed = 1;
    *bLed.getDigitalOut() = 0;
    bLed.getDigitalOut()->write(1);
    ThisThread::sleep_for(BLINKING_RATE);
    *bLed.getDigitalOut() = 0;
    
    while (true) {
        gLed = !gLed;
        *red = !*red;
        ThisThread::sleep_for(BLINKING_RATE);
    }
    delete red;                 // Delete Operator in C++ for Dynamic Memory.

} */

int main()
{
    Led leds[] = {Led(RED_LED),Led(BLUE_LED), Led(GREEN_LED)};
    Led *ptr = leds;    // Led *ptr = &leds[0];

    leds[0].set(1);     // Turn red led On
    ptr->set(1);        // Turn red led ON
    leds->set(1);       // Turn red led ON
    (*leds).set(1);     // Turn red led ON

    (*(ptr+1)).set(1);  // Turn blue led ON, using dereferencing operator (blue led - index 1)
    (ptr+2)->set(1);    // Turn green led ON (green led - index 2)
 
    ThisThread::sleep_for(BLINKING_RATE);


    while (true) {
        for(int8_t i=2; i>=0 ;i--)
        {
            (leds+i)->set(0); // leds[i].set(0);
            ThisThread::sleep_for(BLINKING_RATE);
        }

        for(int8_t i=0; i<=2; i++)
        {
            leds[i].set(1);
            ThisThread::sleep_for(BLINKING_RATE);
        }
    }
}