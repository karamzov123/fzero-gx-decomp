#include <dolphin/os.h>
#include <dolphin/exi.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSRtc.h>
#include "types.h"


/* --- dol/UnlockSram.c --- */
struct OSRtcBss {
    SramControlBlock Scb;
};

void WriteSramCallback(s32 chan, OSContext *context);

static BOOL WriteSram(void *buffer, u32 offset, u32 size);

void WriteSramCallback(s32 chan, OSContext *context);

extern struct OSRtcBss Scb_8015BFC0;

static inline BOOL WriteSram(void *buffer, u32 offset, u32 size) {
    BOOL err;
    u32 cmd;
    if (!EXILock(0, 1, WriteSramCallback)) {
        return 0;
    }
    if (!EXISelect(0, 1, 3)) {
        EXIUnlock(0);
        return 0;
    }
    offset <<= 6;
    cmd = 0xa0000000 | 0x00000100 + offset;
    err = 0;
    err |= !EXIImm(0, &cmd, 4, 1, ((void *)0));
    err |= !EXISync(0);
    err |= !EXIImmEx(0, buffer, (s32)size, 1);
    err |= !EXIDeselect(0);
    EXIUnlock(0);
    return !err;
}

BOOL UnlockSram(BOOL commit, u32 offset) {
    u32 *offsetField;

    struct OSRtcBss *bss = &Scb_8015BFC0;

    u16 *p;
    if (commit) {
        if (offset == 0) {
            OSSram *sram = (OSSram *)(bss->Scb).sram;
            if (2u < (sram->flags & 3)) {
                sram->flags &= ~3;
            }
            sram->checkSum = sram->checkSumInv = 0;
            for (p = (u16 *)&sram->counterBias; p < (u16 *)((bss->Scb).sram + sizeof(OSSram));
                 p++) {
                sram->checkSum += *p;
                sram->checkSumInv += ~*p;
            }
        }
        offsetField = (u32 *)((u8 *)bss + (u32) & ((struct OSRtcBss *)0)->Scb.offset);
        if (offset < (*offsetField)) {
            (*offsetField) = offset;
        }
        (bss->Scb).sync =
            WriteSram((bss->Scb).sram + (*offsetField), (*offsetField), 64 - (*offsetField));
        if ((bss->Scb).sync) {
            (*offsetField) = 64;
        }
    }
    (bss->Scb).locked = 0;
    OSRestoreInterrupts((bss->Scb).enabled);
    return (bss->Scb).sync;
}

/* --- dol/__OSUnlockSram.c --- */
void __OSUnlockSram(u32 arg0) {
    UnlockSram(arg0, 0);
}

/* --- dol/__OSUnlockSramEx.c --- */
void __OSUnlockSramEx(u32 arg0) {
    UnlockSram(arg0, 20);
}
