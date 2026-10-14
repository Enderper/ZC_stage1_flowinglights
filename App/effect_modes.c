#include "effect_modes.h"
#include "app_state.h"
#include "app_config.h"
#include "bsp_soft_pwm.h"
#include "main.h"

#define BASE_FLOW_STEP_MS 100   // 基础流水步进时间

static uint32_t effect_step;    // 全局步进计数，特效公用，每个步进周期+1
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
 * @brief 基础流水
 * @note  非阻塞更新LED状态，固定时间推进一次
 * 
 */
void Effect_BaseFlow_Update(void)
{
    Effect_Step();
    uint8_t pos = effect_step % LED_NUM;
    Bsp_SoftPwm_SetMask(Effect_Led_Rematch(pos));
}

/**
 * @brief 往返流水
 * @note  三角波 0 -> N-1 -> 1 -> 0
 * 
 */
void Effect_PingPong_Update(void)
{
    Effect_Step();

    uint32_t period = 2 * (LED_NUM - 1); // 一个来回所需步数
    uint32_t t = effect_step % period;
    
    uint8_t  pos = (t < LED_NUM) ? (uint8_t)t // 去程： 0->N-1
                      :(uint8_t)(period - t); // 回程:  N-2..1

    Bsp_SoftPwm_SetMask(Effect_Led_Rematch(pos));
}

/**
 * @brief 中心向两侧扩散
 * @note  从中间两颗灯开始，每步同时向两侧各扩散一格
 * 
 */
void Effect_Center_Update(void)
{
    Effect_Step();

    uint32_t half = LED_NUM / 2;        // 中心分界，如30灯为15
    uint32_t k = effect_step % half;    // 0 .. half-1

    uint8_t left  = (uint8_t)(half - 1 - k); // 14 -> 0
    uint8_t right = (uint8_t)(half + k);     // 15 -> 29

    Bsp_SoftPwm_SetMask(Effect_Led_Rematch(left) | Effect_Led_Rematch(right));
}

/**
 * @brief 两侧向中心汇聚
 * @note  从两端开始，每步同时向中间各收缩一格
 * 
 */
void Effect_Converge_Update(void)
{
    Effect_Step();

    uint32_t half = LED_NUM / 2;        // 半步数
    uint32_t k = effect_step % half;    // 0 .. half-1

    uint8_t left  = (uint8_t)k;                 // 0 -> 14
    uint8_t right = (uint8_t)(LED_NUM - 1 - k); // 29 -> 15

    Bsp_SoftPwm_SetMask(Effect_Led_Rematch(left) | Effect_Led_Rematch(right));
}

/**
 * @brief 逐级堆叠
 * @note  按顺序逐颗点亮，堆满后清空重来
 * 
 */
void Effect_Stack_Update(void)
{
    Effect_Step();

    uint32_t count = effect_step % (LED_NUM + 1); // 0 .. N（0为清空帧）
    uint32_t mask = 0;

    for (uint8_t i = 0; i < count; i++)
    {
        mask |= Effect_Led_Rematch(i);
    }

    Bsp_SoftPwm_SetMask(mask);
}

/**
 * @brief 奇偶交替
 * @note  奇数位与偶数位灯交替点亮
 * 
 */
void Effect_OddEven_Update(void)
{
    Effect_Step();

    uint8_t start = (uint8_t)(effect_step & 1); // 0:偶位 1:奇位
    uint32_t mask = 0;

    for (uint8_t i = start; i < LED_NUM; i += 2)
    {
        mask |= Effect_Led_Rematch(i);
    }

    Bsp_SoftPwm_SetMask(mask);
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
 * @brief 非阻塞推进共享步进计数
 * @note  整数倍推进防止累计误差
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
        // 整数倍推进时间
        effect_last_tick += steps * BASE_FLOW_STEP_MS;

        // 将计算出的计数数加入全局计数中
        effect_step += steps;
    }
}
