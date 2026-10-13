#ifndef __EFFECT_MODES_H
#define __EFFECT_MODES_H

#include <stdint.h>

void Effect_Flow_Init(void);
void Effect_ResetStep(void);
void Effect_BaseFlow_Update(void);

// ∂ÓÕ‚Ãÿ–ß
void Effect_PingPong_Updata(void);
void Effect_Center_Update(void);
void Effect_Converge_Update(void);
void Effect_Stack_Update(void);
void Effect_OddEven_Update(void);

#endif
