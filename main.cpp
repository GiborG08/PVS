#include "mbed.h"
#include "Zdroje/Led.h"    // Trieda pre LED
#include "Zdroje/Uart.h"   // Trieda pre UART
#include "Zdroje/Button.h" // Trieda pre tlačidlo

// Definovanie hardvérových prvkov pomocou tried z repozitára
Led led(LED1);              // LED dióda
Button button(BUTTON1);     // Tlačidlo na doske
Uart pc(USBTX, USBRX, 9600); // UART komunikácia
Ticker obstacle_ticker;     // Ticker na generovanie prekážok

// Premenné pre stav hry
bool jump = false;
bool collision = false;
int score = 0;

// Funkcia pre skok dinosaura
void jump_dino() {
    if (!jump) {
        jump = true;
        pc.print("Jump!\n"); // Odoslanie skoku cez UART
    }
}

// Funkcia pre generovanie prekážok
void generate_obstacle() {
    // Ak je dinosaurus na "zemi" a nevykoná skok, nastane kolízia
    if (!jump) {
        collision = true;
        led.set(false);  // LED zhasne pri kolízii
        pc.print("Collision! Game Over. Final Score: %d\n", score);
        return;
    } else {
        // Úspešný skok - zvýšenie skóre
        score++;
        pc.print("Score: %d\n", score);
        led.set(!led.getDuty());  // LED blikne pri úspechu
        jump = false; // Po skoku sa dinosaurus vráti "na zem"
    }
}

int main() {
    // Inicializácia
    pc.print("Dino Game Started! Press button to jump.\n");
    led.set(true);  // LED je zapnutá na začiatku hry
    button.attachOnPress(&jump_dino);  // Prerušenie na stlačenie tlačidla

    // Nastavenie tickeru na generovanie prekážok každé 2 sekundy
    obstacle_ticker.attach(&generate_obstacle, 2s);

    while (!collision) {
        // Hlavná slučka hry
        // Všetka logika prebieha v prerušení a tickeri
    }

    // Koniec hry
    led.set(false);  // LED vypnutá
    while (true) {
        // Nekonečná slučka po ukončení hry
    }
}
