#ifndef __EFFECT_H
#define __EFFECT_H

#include <stdint.h>

#define MODE_BASE_FLOW 0
#define MODE_PINGPONG  1
#define MODE_CENTER    2
#define MODE_CONVERGE  3
#define MODE_STACK     4
#define MODE_ODDEVEN   5
#define MODE_MAX       5

void Effect_Init(void);
void Effect_Reset(void);
void Effect_Update(void);       
uint8_t Effect_SetMode(int mode);

#endif
