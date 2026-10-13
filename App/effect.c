#include "effect.h"
#include "app_state.h"
#include "bsp_soft_pwm.h"
#include "effect_modes.h"

/**
 * @brief 初始化各个流水效果
 * 
 */
void Effect_Init(void)
{
    Effect_Flow_Init();
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
            Effect_ResetStep();
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
        case 0://基础流水
            Effect_BaseFlow_Update();
            break;
        // case 1://往返流水
        //     Effect_PingPong_Updata();
        //     break;
        // case 2://中心扩散
        //     Effect_CENTER_Update();
        //     break;
        // case 3://两侧汇聚
        //     Effect_CONVERGE_Update();
        //     break;
        // case 4://逐级堆叠
        //     Effect_STACK_Update();
        //     break;
        // case 5://奇偶交替
        //     Effect_ODDEVEN_Update();
        //     break;

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
