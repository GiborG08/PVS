#pragma once
#ifndef JUMP_LOGIC_H
#define JUMP_LOGIC_H

#include "mbed.h"
#include "Zdroje/Uart.h" // Pre výstup cez UART
#include "Zdroje/Led.h"  // Pre signalizáciu udalostí

class JumpLogic {
private:
    Uart& pc;
    Led& led;
    bool& jump;
    bool& collision;
    int& score;

public:
    // Constructor
    JumpLogic(Uart& pc_uart, Led& led_instance, bool& jump_status, bool& collision_status, int& game_score);

    // Function to handle jump logic
    void handle_jump();
};

#endif // JUMP_LOGIC_H
