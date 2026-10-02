#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "app_config.h"

void LED_Init(void);
void Bsp_Led_On(uint8_t led_index);
void Bsp_Led_Off(uint8_t led_index);
void Bsp_Led_AllOff(void);
void Bsp_Led_SetMask(uint32_t mask);

#endif
