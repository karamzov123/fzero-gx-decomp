#ifndef DATA_GXRESETFUNCINFO_H
#define DATA_GXRESETFUNCINFO_H

#include "types.h"

typedef struct {
    void (*at_0)(void);
    u32 at_4;
    u32 at_8;
    u32 at_C;
} Data_GXResetFuncInfo;
extern Data_GXResetFuncInfo GXResetFuncInfo;

#endif
