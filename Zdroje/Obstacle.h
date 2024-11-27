#pragma once

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "mbed.h"
#include "Zdroje/Uart.h"  // Pre signalizáciu udalostí

class Obstacle {
private:
    Uart& pc;

public:
    // Constructor
    Obstacle(Uart& pc_uart);

    // Main logic for obstacle movement and interaction
    void generate_obstacle();
};

#endif // OBSTACLE_H
