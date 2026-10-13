#ifndef __EFFECT_MODES_H
#define __EFFECT_MODES_H

#include <stdint.h>

void Effect_Flow_Init(void);
void Effect_ResetStep(void);
void Effect_BaseFlow_Update(void);

void Effect_PingPong_Updata(void);
void Effect_CENTER_Update(void);
void Effect_CONVERGE_Update(void);
void Effect_STACK_Update(void);
void Effect_ODDEVEN_Update(void);

#endif
