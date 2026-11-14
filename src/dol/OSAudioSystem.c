#include <dolphin/os.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

void *memcpy(void *dest, const void *src, size_t n);

vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;

extern u8 DSPInitCode[128];

void __OSInitAudioSystem(void) {
    u32 r28;
    u16 r3;
    u32 padding;
    memcpy((void *)((u8 *)OSGetArenaHi() - 128), (void *)FZGX_ADDR___OSAudioInitBuffer, 128);
    memcpy((void *)FZGX_ADDR___OSAudioInitBuffer, (void *)DSPInitCode, 128);
    DCFlushRange((void *)FZGX_ADDR___OSAudioInitBuffer, 128);
    __DSPRegs[9] = 0x43;
    __DSPRegs[5] = 0x8AC;
    __DSPRegs[5] |= 1;
    while (__DSPRegs[5] & 1)
        ;
    __DSPRegs[0] = 0;
    while (((__DSPRegs[2] << 16) | __DSPRegs[3]) & 0x80000000)
        ;
    *(u32 *)&__DSPRegs[16] = 0x1000000;
    *(u32 *)&__DSPRegs[18] = 0;
    *(u32 *)&__DSPRegs[20] = 0x20;
    r3 = __DSPRegs[5];
    while (!(r3 & 0x20))
        r3 = __DSPRegs[5];
    __DSPRegs[5] = r3;
    r28 = OSGetTick();
    while ((s32)(OSGetTick() - r28) < 0x892)
        ;
    *(u32 *)&__DSPRegs[16] = 0x1000000;
    *(u32 *)&__DSPRegs[18] = 0;
    *(u32 *)&__DSPRegs[20] = 0x20;
    r3 = __DSPRegs[5];
    while (!(r3 & 0x20))
        r3 = __DSPRegs[5];
    __DSPRegs[5] = r3;
    __DSPRegs[5] &= ~0x800;
    while ((__DSPRegs[5]) & 0x400)
        ;
    __DSPRegs[5] &= ~4;
    r3 = __DSPRegs[2];
    while (!(r3 & 0x8000))
        r3 = __DSPRegs[2];
    (void)__DSPRegs[3];
    (void)(r3 != 0x8000); // Retain the mailbox halfword conversion.

    __DSPRegs[5] |= 4;
    __DSPRegs[5] = 0x8AC;
    __DSPRegs[5] |= 1;
    while (__DSPRegs[5] & 1)
        ;
    memcpy((void *)FZGX_ADDR___OSAudioInitBuffer, (void *)((u8 *)OSGetArenaHi() - 128), 128);
}

void __OSStopAudioSystem(void) {
    u32 r28;
    __DSPRegs[5] = 0x804;
    r28 = __DSPRegs[27];
    __DSPRegs[27] = r28 & ~0x8000;
    r28 = (__DSPRegs[5]);
    while (r28 & (0x400)) {
        r28 = (__DSPRegs[5]);
    };
    r28 = (__DSPRegs[5]);
    while (r28 & (0x200)) {
        r28 = (__DSPRegs[5]);
    };
    __DSPRegs[5] = 0x8ac;
    __DSPRegs[0] = 0;
    while (((__DSPRegs[2] << 16) | __DSPRegs[3]) & 0x80000000)
        ;
    r28 = OSGetTick();
    while ((s32)(OSGetTick() - r28) < 0x2c)
        ;
    __DSPRegs[5] |= 1;
    r28 = (__DSPRegs[5]);
    while (r28 & (0x001)) {
        r28 = (__DSPRegs[5]);
    };
}
