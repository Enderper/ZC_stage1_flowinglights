#ifndef __BSP_SOFT_PWM_H
#define __BSP_SOFT_PWM_H

#include <stdint.h>

void Bsp_SoftPwm_Init(void);                   // 启动TIM2中断
void Bsp_SoftPwm_IRQHandler(void);             // 在 TIM2_IRQHandler 中调用
void Bsp_SoftPwm_SetBrightness(uint8_t bri);   // 0~100
void Bsp_SoftPwm_SetMask(uint32_t mask);       // 效果层调用

#endif
