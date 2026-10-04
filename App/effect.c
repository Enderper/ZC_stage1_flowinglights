#include "effect.h"
#include "app_state.h"
#include "bsp_soft_pwm.h"

/**
 * @brief 初始化各个流水效果
 * 
 */
void Effect_Init(void)
{
    Effect_BaseFlow_Init();
    // ...
}

/**
 * @brief 复位当前效果
 * 
 */
void Effect_Reset(void)
{
    switch (g_app_state.mode)
    {
        case 0:
            Effect_BaseFlow_Reset();
            break;

        // ...

        default:
            break;
    }
}

/**
 * @brief 更新当前流水效果
 * @note  主循环中非阻塞调用
 * 
 */
void Effect_Update(void)
{
    // 若运行态为0,STOP,熄灭所有oled
    if (g_app_state.run_state == 0)
    {
        Bsp_SoftPwm_SetMask(0);
        return;
    }

    // 根据不同模式设置不同效果
    switch (g_app_state.mode)
    {
        case 0:
            Effect_BaseFlow_Update();
            break;
        
        // ...

        default:
           Bsp_SoftPwm_SetMask(0);
            break;
    }
}

/**
 * @brief 切换模式
 * 
 * @param mode 
 */
uint8_t Effect_SetMode(uint8_t mode)
{
    if (mode != 0)
    {
        return 1;
    }

    g_app_state.mode = mode;
    Effect_Reset();
    return 0;
}
