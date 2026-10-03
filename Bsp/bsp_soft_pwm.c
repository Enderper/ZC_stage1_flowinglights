#include "bsp_soft_pwm.h"
#include "tim.h"

static volatile uint8_t pwm_counter = 0; // PWM计数器
static volatile uint8_t pwm_brightness = 50; // PWM亮度值
static volatile uint32_t pwm_mask = 0; // 当前应亮的LED掩码


void Bsp_SoftPwm_Init(void)
{
    HAL_TIM_Base_Start_IT(&htim2);
}
