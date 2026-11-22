#include "types.h"

typedef u32 (*__init_cpp_Fn)(void);

extern u32 _ctors[];
extern u32 PPCHalt(void);

void __init_cpp(void);

#pragma peephole off
#pragma dont_inline on
void __init_user(void) {
    __init_cpp();
}
#pragma dont_inline reset

void __init_cpp(void) {
    __init_cpp_Fn *p = (__init_cpp_Fn *)&_ctors;
    while (*p != 0) {
        (*p)();
        p++;
    }
}
#pragma peephole reset

u32 _ExitProcess(void) {
    return PPCHalt();
}
