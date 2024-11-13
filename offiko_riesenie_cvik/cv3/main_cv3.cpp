#include "mbed.h"
#include "Led.h"
#include "Button.h"

//LED and button PIN names
#define LED_GREEN       PC_7   // LD1 LED_GREEN
#define LED_BLUE        PB_7   // LD2 LED_BLUE
#define LED_RED         PG_2   // LD3 LED_RED
#define USER_BUTTON     PC_13  // B1  USER_BUTTON

int main()
{
    DigitalOut red_led(LED_RED);    // NO PWM on this pin
    Led green_led(LED_GREEN), blue_led(LED_BLUE);

    uint8_t counter = 0;
    green_led.graduallyOn();
    Button btn(USER_BUTTON);
    while (true) {

        while(!btn.read()){}    // wait until press button - blocking operation
        while(btn.read()){}     // wait until release button - blocking operation
        counter ++;
        if(counter>7)
            counter = 0;
        
        // RED-MSB   BLUE  GREEN-LSB
        red_led.write(false); blue_led.set(false); green_led.set(false);

        if(counter & (1<<0))    // counter & 1  
            green_led.set(true);

        if(counter & (1<<1))    // counter & 2
            blue_led.set(true);

        if(counter & (1<<2))    // counter & 4
            red_led.write(true);
        
        printf("Button counter : %d \r\n", btn.getCount());     //interrupt counter
    }
}
