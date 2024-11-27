#include "mbed.h"
#include "Zdroje/Led.h"    // Trieda pre LED
#include "Zdroje/Uart.h"   // Trieda pre UART
#include "Zdroje/Button.h" // Trieda pre tlačidlo
#include "Obstacle.h"      // Trieda pre prekážky
#include "JumpLogic.h"     // Trieda pre logiku skoku

// Premenné pre stav hry
bool jump = false;
bool collision = false;
int score = 0;

// Definovanie hardvérových prvkov pomocou tried z repozitára
Led led(LED1);              // LED dióda
Button button(BUTTON1);     // Tlačidlo na doske
Uart pc(USBTX, USBRX, 9600); // UART komunikácia
Obstacle obstacle(pc); // Objekt pre generovanie prekážok
JumpLogic jump_logic(pc, led, jump, collision, score); // Objekt pre logiku skoku

Thread obstacle_thread;
Thread button_thread;

// Funkcia pre spracovanie skoku pri stlačení tlačidla
void jump_dino() {
    jump_logic.handle_jump();
}

// Funkcia pre vlákno generujúce prekážky
void obstacle_logic_thread() {
    obstacle.generate_obstacle();
}

// Funkcia pre vlákno monitorujúce tlačidlo
void button_logic_thread() {
    while (!collision) {
        if (button.wasPressed()) {
            jump_dino();
        }
        ThisThread::sleep_for(50ms); // Kontrola tlačidla každých 50 ms pre rýchlejšiu odozvu
    }
}

int main() {
    pc.print("Dino Game Started! Press button to jump.\n");
    led.set(true);  // LED je zapnutá na začiatku hry

    // Spustenie vlákien
    obstacle_thread.start(obstacle_logic_thread);
    button_thread.start(button_logic_thread);

    while (!collision) {
        // Hlavná slučka hry
        ThisThread::sleep_for(100ms); // Zabraňuje vysokému využitiu CPU v hlavnej slučke
    }

    // Koniec hry
    led.set(false);  // LED vypnutá
    pc.print("Game Over. Thank you for playing!\n");
    while (true) {
        // Nekonečná slučka po ukončení hry
        ThisThread::sleep_for(1s); // Časová pauza pre stabilitu
        obstacle_thread.terminate();
        button_thread.terminate();
    }
}
