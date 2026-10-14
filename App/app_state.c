#include "app_state.h"

AppState_t g_app_state;

/**
 * @brief 初始化全局态状：默认停止，基础流水模式
 * 
 */
void AppState_Init(void)
{
    g_app_state.run_state = 0;  // 初始状态
    g_app_state.mode = 0;           // 初始模式
}
