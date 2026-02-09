#include "stm32_gpio_driver.h"

// Define pins for Nucleo-64 (Standard pins)
#define BOARD_LED    5   // PA5
#define BOARD_BUTTON 13  // PC13
#define EXT_LED_A    6   // PA6
#define EXT_LED_B    7   // PA7

int main(void) {
    // 1. Setup the pins
    GPIO_Init(GPIOA, BOARD_LED, GPIO_MODE_OUTPUT);
    GPIO_Init(GPIOC, BOARD_BUTTON, GPIO_MODE_INPUT);
    GPIO_Init(GPIOA, EXT_LED_A, GPIO_MODE_OUTPUT);
    GPIO_Init(GPIOA, EXT_LED_B, GPIO_MODE_OUTPUT);

    // 2. Set initial state for Task 2 (One ON, one OFF)
    GPIO_WritePin(GPIOA, EXT_LED_A, 1);
    GPIO_WritePin(GPIOA, EXT_LED_B, 0);

    while (1) {
        // --- TASK 1: Button Toggle ---
        // Most Nucleo buttons are "Active Low" (0 = Pressed)
        if (GPIO_ReadPin(GPIOC, BOARD_BUTTON) == 0) {
            GPIO_TogglePin(GPIOA, BOARD_LED);
            
            // "Newbie" Debounce: Wait until button is released
            while (GPIO_ReadPin(GPIOC, BOARD_BUTTON) == 0);
            delay_ms(50); 
        }

        // --- TASK 2: Alternating External LEDs ---
        // Flip both pins every 250ms
        GPIO_TogglePin(GPIOA, EXT_LED_A);
        GPIO_TogglePin(GPIOA, EXT_LED_B);
        
        delay_ms(250); // Total period will be 500ms
    }
}
