#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H

#include "tim.h"
#include "bsp_soft_pwm.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif
