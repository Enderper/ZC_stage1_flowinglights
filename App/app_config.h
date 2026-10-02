#define LED_NUM 30

#include "main.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} LedPin_t;

// 请理解为什么要这么写
extern const LedPin_t led_pins[LED_NUM];
