#include "app.h"
#include "bsp_uart.h"
#include "bsp_soft_pwm.h"
#include "cmd_parser.h"
#include "effect.h"
#include "app_state.h"

/**
 * @brief 初始化各个模块
 * 
 */
void App_Init(void)
{
    Bsp_Uart_Init();
    Bsp_SoftPwm_Init();
    CmdParser_Init();
    AppState_Init();
    Effect_Init();
}

/**
 * @brief 工作循环，放入主循环中
 * 
 */
void App_Loop(void)
{
    CmdParser_Process();
    Effect_Update();
}
