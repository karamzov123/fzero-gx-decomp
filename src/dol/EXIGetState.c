#include <dolphin/exi/EXIPriv.h>
#pragma scheduling off

extern EXIControl Ecb[3];

u32 EXIGetState(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    return (u32)exi->state;
}
