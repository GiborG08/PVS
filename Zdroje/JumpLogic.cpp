#include "JumpLogic.h"

// Constructor
JumpLogic::JumpLogic(Uart& pc_uart, Led& led_instance, bool& jump_status, bool& collision_status, int& game_score)
    : pc(pc_uart), led(led_instance), jump(jump_status), collision(collision_status), score(game_score) {}

// Function to handle jump logic
void JumpLogic::handle_jump() {
    if (!jump) {
        jump = true;
        pc.print("Jump!\n"); // Odoslanie skoku cez UART
    }

    // After obstacle passes or jump is completed
    if (collision) {
        led.set(false);  // LED zhasne pri kolízii
        pc.print("\nCollision! Game Over. Final Score: %d\n", score);
    } else {
        // Úspešný skok - zvýšenie skóre
        score++;
        led.toggle();  // LED blikne pri úspechu
        jump = false;  // Po skoku sa dinosaurus vráti "na zem"
    }
}
