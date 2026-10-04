#ifndef __EFFECT_H
#define __EFFECT_H

#include <stdint.h>

void Effect_Init(void);
void Effect_Reset(void);
void Effect_Update(void);       // 主循环中非阻塞调用
uint8_t Effect_SetMode(uint8_t mode);

#endif
