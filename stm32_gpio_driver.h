#ifndef STM32_GPIO_DRIVER_H
#define STM32_GPIO_DRIVER_H

#include <stdint.h>

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
} GPIO_RegDef_t;

#define GPIOA_BASE_ADDR    0x40020000U
#define GPIOC_BASE_ADDR    0x40020800U

#define GPIOA    ((GPIO_RegDef_t *)GPIOA_BASE_ADDR)
#define GPIOC    ((GPIO_RegDef_t *)GPIOC_BASE_ADDR)

#define GPIO_MODE_INPUT    0
#define GPIO_MODE_OUTPUT   1
#define PIN_SET            1
#define PIN_RESET          0

void GPIO_Init(GPIO_RegDef_t *pGPIOx, int pinNumber, int mode);
void GPIO_WritePin(GPIO_RegDef_t *pGPIOx, int pinNumber, int value);
int  GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, int pinNumber);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, int pinNumber);
void delay_ms(int ms);

#endif
