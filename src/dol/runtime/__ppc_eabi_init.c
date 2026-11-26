#include "types.h"

typedef u32 (*__init_cpp_Fn)(void);

extern u32 _ctors[];
extern u32 PPCHalt(void);
extern void __OSPSInit(void);
extern void __OSFPRInit(void);
extern void __OSCacheInit(void);

/* The SDK's mixed startup unit enters these routines without a C frame.
 * The instructions below are from the GX .init routines; see the TU map
 * and the scoped entries in config/original_assembly.json. */
__declspec(section ".init") asm void __init_hardware(void) {
    nofralloc
    mfmsr r0
    ori r0, r0, 0x2000
    mtmsr r0
    mflr r31
    bl __OSPSInit
    bl __OSFPRInit
    bl __OSCacheInit
    mtlr r31
    blr
}

__declspec(section ".init") asm void __flush_cache(void *addr, u32 size) {
    nofralloc
    lis r5, 0xffff
    ori r5, r5, 0xfff1
    and r5, r5, r3
    subf r3, r5, r3
    add r4, r4, r3
flush_line:
    dcbst r0, r5
    sync
    icbi r0, r5
    addic r5, r5, 0x8
    subic. r4, r4, 0x8
    bge flush_line
    isync
    blr
}

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
