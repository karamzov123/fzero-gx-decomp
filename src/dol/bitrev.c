#include <dolphin/card/CARDPriv.h>
#include "types.h"
#include "dol/globals.h"


/* --- dol/bitrev.c --- */
u32 bitrev(u32 data) {
    u32 wk;
    u32 i;
    u32 k = 0;
    u32 j = 1;
    wk = 0;
    for (i = 0; i < 32; i++) {
        if (i > 15) {
            if (i == 31) {
                wk |= (((data & (0x01 << 31)) >> 31) & 0x01);
            } else {
                wk |= ((data & (0x01 << i)) >> j);
                j += 2;
            }
        } else {
            wk |= ((data & (0x01 << i)) << (31 - i - k));
            k++;
        }
    }
    return wk;
}

/* --- dol/ReadArrayUnlock.c --- */
extern s32 EXISelect(s32 chan, s32 dev, s32 freq);
extern s32 EXIImmEx(s32 chan, void *buf, s32 len, s32 type);
extern s32 EXIDeselect(s32 chan);

s32 ReadArrayUnlock(s32 chan, u32 address, void *buffer, s32 length, s32 use_full_address) {
    u8 command[5];
    s32 failed;
    Obj_80177960 *work;

    work = (Obj_80177960 *)((u8 *)&lbl_80177960 + chan * 0x110);
    if (!EXISelect(chan, 0, 4)) {
        return -3;
    }

    address &= ~0xfff;
    memset(command, 0, 5);
    command[0] = 0x52;
    if (!use_full_address) {
        command[1] = (address >> 29) & 3;
        command[2] = (address >> 21) & 0xff;
        command[3] = (address >> 19) & 3;
        command[4] = (address >> 12) & 0x7f;
    } else {
        command[1] = address >> 24;
        command[2] = address >> 16;
    }

    failed = !EXIImmEx(chan, command, 5, 1);
    failed |= !EXIImmEx(chan, (u8 *)work->unk_80 + 0x200, work->unk_14, 1);
    failed |= !EXIImmEx(chan, buffer, length, 0);
    failed |= !EXIDeselect(chan);

    if (failed) {
        return -3;
    }
    return 0;
}

/* --- dol/DummyLen.c --- */
extern u32 OSGetTick(void);
// The seed is shared with other random-number users and must be observed at each access.
extern volatile u32 lbl_801A6510;

s32 DummyLen(void) {
    u32 v0;
    u32 v1;
    u32 v4;
    u32 v3;
    s32 v2;
    u32 v5;
    u32 v6;
    u32 t0, t1;
    u64 pad;

    v4 = 1;
    v2 = 0;
    t0 = OSGetTick();
    lbl_801A6510 = t0;
    v0 = 0x41C64E6D;
    v1 = (lbl_801A6510 * v0) + 12345;
    lbl_801A6510 = v1;
    v3 = ((lbl_801A6510 >> 16) & 0x1F) + 1;
    while ((s32)v3 < 4 && (u32)v2 < 10) {
        t1 = OSGetTick();
        v3 = t1;
        v5 = v3 << v4;
        v4++;
        if (v4 > 16) {
            v4 = 1;
        }
        lbl_801A6510 = v5;
        v2++;
        v3 = lbl_801A6510 * v0;
        v6 = v3 + 12345;
        lbl_801A6510 = v6;
        v3 = (lbl_801A6510 >> 16) & 0x1F;
        v3++;
    }
    if ((s32)v3 < 4) {
        v3 = 4;
    }
    return v3;
}
