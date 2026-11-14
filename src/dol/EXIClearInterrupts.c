#include <dolphin/exi/EXIPriv.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

u32 EXIClearInterrupts(s32 chan, BOOL exi, BOOL tc, BOOL ext) {
    u32 cpr;
    u32 prev;
    prev = cpr = (__EXIRegs[((chan) * 5) + (0)]);
    cpr &= 0x7f5;
    if (exi)
        cpr |= 2;
    if (tc)
        cpr |= 8;
    if (ext)
        cpr |= 0x800;
    (__EXIRegs[((chan) * 5) + (0)]) = cpr;
    return prev;
}
