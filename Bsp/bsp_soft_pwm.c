#include "bsp_soft_pwm.h"
#include "bsp_led.h"

#define PWM_LEVELS 100 // PWM分辨率为100级

extern TIM_HandleTypeDef htim2;

static volatile uint8_t pwm_counter = 0; // PWM计数器
static volatile uint8_t pwm_brightness = 50; // PWM亮度值
static volatile uint32_t pwm_mask = 0; // 当前应亮的LED掩码

/**
 * @brief 开启TIM2中断并初始化软PWM
 * 
 */
void Bsp_SoftPwm_Init(void)
{
    pwm_counter = 0;
    pwm_brightness = 50; // 默认亮度50%
    pwm_mask = 0; // 默认没有LED亮
    HAL_TIM_Base_Start_IT(&htim2);
}

/**
 * @brief 软PWM中断处理函数，软PWM的主要实现
 * @note  在TIM2_IRQHandler中调用
 * 
 */
void Bsp_SoftPwm_IRQHandler(void)
{
    pwm_counter++;
    // 计数超过ARR重置
    if (pwm_counter >= PWM_LEVELS)
    {
        pwm_counter = 0;
    }

    uint32_t output = 0;

    if (pwm_brightness > 0)
    {
        // CCR超过ARR，直接使得灯常亮
        if (pwm_brightness >= PWM_LEVELS) 
        {
            output = pwm_mask;
        } 
        // 计数小于CCR，点亮
        else if (pwm_counter < pwm_brightness) 
        {
            output = pwm_mask;
        } 
        // 计数大于CCR，熄灭
        else 
        {
            output = 0;
        }
    }

    Bsp_Led_SetMask(output);
}

/**
 * @brief 设置LED亮度
 * 
 * @param bri 
 */
void Bsp_SoftPwm_SetBrightness(uint8_t bri)
{
    if (bri > PWM_LEVELS) {
        bri = PWM_LEVELS; // 限制最大值为PWM_LEVELS
    }
    pwm_brightness = bri;
}

/**
 * @brief 设置当前应亮的LED掩码
 * 
 * @param mask 
 */
void Bsp_SoftPwm_SetMask(uint32_t mask)
{
    pwm_mask = mask;
}

/**
 * @brief 获取当前亮度值，给应用层使用
 * 
 * @return uint8_t 亮度值
 */
uint8_t Bsp_SoftPwm_GetBrightness(void)
{
    return pwm_brightness;
}
