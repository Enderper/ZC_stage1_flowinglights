#include "effect_modes.h"
#include "app_state.h"
#include "app_config.h"
#include "bsp_soft_pwm.h"
#include "main.h"

#define BASE_FLOW_STEP_MS 100   // 基础流水步进时间

static uint8_t base_index;  // 当前点亮的LED索引,0对应LED1
static uint32_t base_last_tick; // 上一次步进的时间戳

/**
 * @brief 初始化,索引归零,记录当前时间
 * 
 */
void Effect_BaseFlow_Init(void)
{
    base_index = 0;
    base_last_tick = HAL_GetTick();
}

/**
 * @brief 复位，RUN命令使用，从LED1开始亮起
 */
void Effect_BaseFlow_Reset(void)
{
    base_index = 0;
    base_last_tick = HAL_GetTick();

    Bsp_SoftPwm_SetMask(1UL << base_index);
}

/**
 * @brief 非阻塞更新LED状态，100ms推进一次
 * 
 */
void Effect_BaseFlow_Update(void)
{
    uint32_t now = HAL_GetTick();

    // 是否到达步进时间
    if ((now - base_last_tick) >= BASE_FLOW_STEP_MS)
    {
        // 计算其间经过了多少个步进周期,修正时间戳
        uint32_t steps = (now - base_last_tick) /BASE_FLOW_STEP_MS;
        base_last_tick += steps * BASE_FLOW_STEP_MS;

        // 推进索引
        base_index = (uint8_t)((base_index + steps) % LED_NUM);
    }

    // 不论是否亮每轮都设置掩码保存进度
    Bsp_SoftPwm_SetMask(1UL << base_index);
}