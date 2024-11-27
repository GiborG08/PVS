#include "Obstacle.h"

// Constructor
Obstacle::Obstacle(Uart& pc_uart)
    : pc(pc_uart) {}

// Function to generate obstacles
void Obstacle::generate_obstacle() {
        for (int i = 20; i >= 0; i--) {
            // Vytvorenie grafického výstupu pre približovanie sa prekážky s číslom
            char buffer[128];
            snprintf(buffer, sizeof(buffer), "\rTime to impact: %2d | [Obstacle]%*s[Dino]", i, i, " ");
            pc.print(buffer);
            ThisThread::sleep_for(chrono::milliseconds(200));
        }
}
