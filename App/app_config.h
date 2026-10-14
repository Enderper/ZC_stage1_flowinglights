#define LED_NUM 30

#include "main.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} LedPin_t;

extern const LedPin_t led_pins[LED_NUM];
