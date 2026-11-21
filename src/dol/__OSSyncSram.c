#include "types.h"


/* --- dol/__OSSyncSram.c --- */
extern struct __OSSyncSram_Scb_8015BFC0 Scb_8015BFC0;

struct __OSSyncSram_Scb_8015BFC0 {
    u8 pad_0[0x4C];
    u32 unk_4C;
};

u32 __OSSyncSram(void) {
    return Scb_8015BFC0.unk_4C;
}

/* --- dol/__OSReadROM.c --- */
extern void DCInvalidateRange(void* addr, u32 length);
extern int EXILock(int chan, int dev, int priority);
extern int EXISelect(int chan, int dev, int freq);
extern int EXIUnlock(int chan);
extern int EXIImm(int chan, void* data, int len, int type, void* callback);
extern int EXISync(int chan);
extern int EXIDma(int chan, void* data, int len, int type, void* callback);
extern int EXIDeselect(int chan);

int __OSReadROM(void* dst, u32 length, u32 offset) {
    int result;
    u32 command;

    DCInvalidateRange(dst, length);
    if (!EXILock(0, 1, 0)) {
        return 0;
    }
    if (!EXISelect(0, 1, 3)) {
        EXIUnlock(0);
        return 0;
    }

    command = offset << 6;
    result = !EXIImm(0, &command, 4, 1, 0);
    result |= !EXISync(0);
    result |= !EXIDma(0, dst, length, 0, 0);
    result |= !EXISync(0);
    result |= !EXIDeselect(0);
    EXIUnlock(0);

    return !result;
}
