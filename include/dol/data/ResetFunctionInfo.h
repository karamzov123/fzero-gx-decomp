#ifndef DATA_RESETFUNCTIONINFO_H
#define DATA_RESETFUNCTIONINFO_H

#include "types.h"

typedef struct {
    void (*at_0)(void);
    u32 at_4;
    u32 at_8;
    u32 at_C;
} Data_ResetFunctionInfo;
extern Data_ResetFunctionInfo ResetFunctionInfo;

#endif
