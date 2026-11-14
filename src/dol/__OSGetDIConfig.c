#include <dolphin/os.h>
#include <dolphin/types.h>
#pragma peephole off

void OSReport(const char *msg, ...);

struct DIRegs {
    u8 _pad0[0x24];
    volatile u32 config;  /* fzgx-allow: S2 memory-mapped register */
};

extern struct DIRegs __DIRegs;

u32 __OSGetDIConfig(void) {
    return __DIRegs.config & 0xff;
}

void OSRegisterVersion(const char *id) { OSReport("%s\n", id); }
