#include "effect.h"
#include "app_state.h"
#include "bsp_soft_pwm.h"
#include "effect_modes.h"

/**
 * @brief 初始化特效
 * @note  复位共享步数
 * 
 */
void Effect_Init(void)
{
    Effect_Flow_Init();
    // ...
}

/**
 * @brief 复位当前特效
 * @note  所有模式共用同一套步进计数
 * 
 */
void Effect_Reset(void)
{
    Effect_ResetStep();
}

/**
 * @brief 更新当前流水效果
 * @note  主循环中非阻塞调用
 * 
 */
void Effect_Update(void)
{
    // 若运行态为0,STOP,熄灭所有led
    if (g_app_state.run_state == 0)
    {
        Bsp_SoftPwm_SetMask(0);
        return;
    }

    // 根据不同模式设置不同效果
    switch (g_app_state.mode)
    {
        case MODE_BASE_FLOW://基础流水
            Effect_BaseFlow_Update();
            break;
         case MODE_PINGPONG://往返流水
             Effect_PingPong_Update();
             break;
         case MODE_CENTER://中心扩散
             Effect_Center_Update();
             break;
         case MODE_CONVERGE://两侧汇聚
             Effect_Converge_Update();
             break;
         case MODE_STACK://逐级堆叠
             Effect_Stack_Update();
             break;
         case MODE_ODDEVEN://奇偶交替
             Effect_OddEven_Update();
             break;

        default:
           Bsp_SoftPwm_SetMask(0);
            break;
    }
}

/**
 * @brief  切换模式
 * @param  mode 
 * @return 成功0，参数越界1
 * 
 */
uint8_t Effect_SetMode(int mode)
{
    if (mode < 0 || mode > MODE_MAX)
    {
        return 1;
    }

    g_app_state.mode = mode;
    Effect_Reset();
    return 0;
}
