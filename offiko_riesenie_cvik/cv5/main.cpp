#include "mbed.h"
#include "Led.h"
#include "Button.h"
#include "Uart.h"
#include <cstdio>
#include <stdio.h>
#include <string.h>

//LED and button PIN names
#define LED_GREEN       PC_7   // LD1 LED_GREEN
#define LED_BLUE        PB_7   // LD2 LED_BLUE
#define LED_RED         PG_2   // LD3 LED_RED
#define USER_BUTTON     PC_13  // B1  USER_BUTTON

int main()
{

    DigitalOut red_led(LED_RED);    // NO PWM on this pin
    Led green_led(LED_GREEN), blue_led(LED_BLUE);
    Button btn(USER_BUTTON);
    Uart pc(USBTX, USBRX, 115200); // Baud Rate = 115200
    char c;
    uint8_t num;
    printf("---------START-------\r\n");
    printf("Press number : \r\n");
    while (true) {
        if (pc.isCharReceived()) {
            c = pc.getReceivedChar();
            printf("\r\n");
            //pc.writeChar(pc.getReceivedChar());
            if((c >='0') && (c <= '9'))
            {
                num = c - '0';  // conversion of character to number
                printf("Received number : %d \r\n", num);
                green_led.setBlinkPeriod(num);
            }
        }
    }
}
