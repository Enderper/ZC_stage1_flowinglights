#include "bsp_timer.h"

extern TIM_HandleTypeDef htim2;

/**
 * @brief 计时器中断回调函数
 * @param htim TIM句柄
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2) {
        Bsp_SoftPwm_IRQHandler(); // 调用软PWM中断处理函数
    }
}
