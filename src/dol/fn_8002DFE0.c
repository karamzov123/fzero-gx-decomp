#include "types.h"
#include "dol/globals.h"


/* --- dol/fn_8002DFE0.c --- */
extern s32 __CARDSync(u32);
extern s32 CARDMountAsync(u32, void *, void *, void *);
extern void __CARDSyncCallback(void);

s32 fn_8002DFE0(u32 arg0, u32 arg1, u32 arg2) {
    s32 status;

    status = CARDMountAsync(arg0, (void *)arg1, (void *)arg2, __CARDSyncCallback);
    if (status < 0) {
        return status;
    }
    status = __CARDSync(arg0);
    return status;
}

/* --- dol/DoUnmount.c --- */
extern u32 OSDisableInterrupts(void);
extern void EXISetExiCallback(s32 chan, void *callback);
extern void EXIDetach(s32 chan);
extern void OSCancelAlarm(void *arg);
extern void OSRestoreInterrupts(u32 level);

void DoUnmount(s32 chan, void *callback) {
    Obj_80177960 *card;
    u32 level;

    card = (Obj_80177960 *)((u8 *)&lbl_80177960 + chan * 0x110);
    level = OSDisableInterrupts();
    if ((s32)card->unk_0 != 0) {
        EXISetExiCallback(chan, 0);
        EXIDetach(chan);
        OSCancelAlarm((u8 *)card + 0xe0);
        card->unk_0 = 0;
        card->unk_4 = (u32)callback;
        card->unk_24 = 0;
    }
    OSRestoreInterrupts(level);
}
