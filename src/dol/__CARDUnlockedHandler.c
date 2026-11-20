#include "types.h"


/* --- dol/__CARDUnlockedHandler.c --- */
extern s32 EXIProbe(s32 chan);
extern u32 lbl_80177960[];

typedef void (*CardUnlockedCallback)(s32 chan, s32 result);

void __CARDUnlockedHandler(s32 chan) {
    u32 offset;
    u32 callback;

    offset = chan * 272;
    callback = *(u32 *)((u8 *)((u8 *)&lbl_80177960 + offset) + 220);
    if (callback != 0) {
        *(u32 *)((u8 *)((u8 *)&lbl_80177960 + offset) + 220) = 0;
        ((CardUnlockedCallback)callback)(chan, EXIProbe(chan) != 0 ? 1 : -3);
    }
}

/* --- dol/__CARDEnableInterrupt.c --- */
/* --- dol/__CARDEnableInterrupt.c --- */
extern s32 EXISelect(s32 chan, s32 dev, s32 freq);
extern s32 EXIImm(s32 chan, void *buf, s32 len, s32 type, void *callback);
extern s32 EXISync(s32 chan);
extern s32 EXIDeselect(s32 chan);

s32 __CARDEnableInterrupt(s32 chan, s32 enable) {
    u32 command;
    s32 failed;

    if (!EXISelect(chan, 0, 4)) {
        return -3;
    }

    command = enable ? 0x81010000 : 0x81000000;  /* fzgx-allow: A1 unnamed OS/hardware memory */
    failed = !EXIImm(chan, &command, 2, 1, 0);
    failed |= !EXISync(chan);
    failed |= !EXIDeselect(chan);

    if (failed) {
        return -3;
    }
    return 0;
}

/* --- dol/__CARDReadStatus.c --- */
s32 __CARDReadStatus(s32 chan, void *status) {
    u32 command;
    s32 failed;

    if (!EXISelect(chan, 0, 4)) {
        return -3;
    }

    command = 0x83000000;
    failed = !EXIImm(chan, &command, 2, 1, 0);
    failed |= !EXISync(chan);
    failed |= !EXIImm(chan, status, 1, 0, 0);
    failed |= !EXISync(chan);
    failed |= !EXIDeselect(chan);

    if (failed) {
        return -3;
    }
    return 0;
}
