#include "effect_modes.h"
#include "app_state.h"
#include "app_config.h"
#include "bsp_soft_pwm.h"
#include "main.h"

#define BASE_FLOW_STEP_MS 100   // 基础流水步进时间

static uint32_t effect_step;    // 全局计数器
static uint32_t effect_last_tick; // 上一次步进的时间戳

static uint32_t Effect_Led_Rematch(uint8_t idx);
static void Effect_Step(void);

void Effect_Flow_Init(void)
{
    Effect_ResetStep();
}

/**
 * @brief 复位step数并记录当前时间
 */
void Effect_ResetStep(void)
{
    effect_step = 0;
    effect_last_tick = HAL_GetTick();
}

/**
 * @brief 非阻塞更新LED状态，100ms推进一次
 * 
 */
void Effect_BaseFlow_Update(void)
{
    Effect_Step();
    // 不论是否亮每轮都设置掩码保存进度
    //Bsp_SoftPwm_SetMask(1UL << base_index);
    Bsp_SoftPwm_SetMask(Effect_Led_Rematch((uint8_t)(effect_step % LED_NUM)));
}





/**
 * @brief 重映射LED引脚使其逆时针流动
 * 
 * @param pos 
 */
static uint32_t Effect_Led_Rematch(uint8_t pos)
{
    uint8_t idx = (pos < LED_NUM / 2) ? pos : ((LED_NUM-1) - (pos - LED_NUM / 2));
    
    return 1UL << idx;
}

/**
 * @brief 更新全局计数
 * 
 */
static void Effect_Step(void)
{
    uint32_t now = HAL_GetTick();

    // 是否到达步进时间
    if ((now - effect_last_tick) >= BASE_FLOW_STEP_MS)
    {
        // 计算其间经过了多少个状态周期
        uint32_t steps = (now - effect_last_tick) /BASE_FLOW_STEP_MS;
        // 更新上一个时间(这里采用了加回去而不是now赋值回去？)
        effect_last_tick += steps * BASE_FLOW_STEP_MS;

        // 将计算出的计数数加入全局计数中
        effect_step += steps;
    }
}
