#include "app_state.h"

AppState_t g_app_state;

void AppState_Init(void)
{
    g_app_state.run_state = 0;  // 初始状态
    g_app_state.mode = 0;           // 初始模式
}
