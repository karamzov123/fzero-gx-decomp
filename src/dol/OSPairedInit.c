#include <dolphin/types.h>
#include <dolphin/os/OSPairedInit.h>

#pragma peephole off

u32 PPCMfhid2(void);
void PPCMthid2(u32 val);
void ICFlashInvalidate(void);
void OSReport(const char *msg, ...);

struct DIRegs {
    u8 _pad0[0x24];
    volatile u32 config;  /* Memory-mapped drive configuration register. */
};
extern struct DIRegs __DIRegs;

void __OSPSInit(void) {
    PPCMthid2(PPCMfhid2() | 0xA0000000);
    ICFlashInvalidate();
    __sync();
    OS_CLEAR_GQRS();
}

u32 __OSGetDIConfig(void) {
    return __DIRegs.config & 0xff;
}

void OSRegisterVersion(const char *id) { OSReport("%s\n", id); }
