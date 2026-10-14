#ifndef __APP_STATE_H
#define __APP_STATE_H

#include <stdint.h>

typedef struct
{
    volatile uint8_t run_state;     // 运行状态
    volatile uint8_t mode;          // 当前模式
} AppState_t;

extern AppState_t g_app_state;

void AppState_Init(void);

#endif
