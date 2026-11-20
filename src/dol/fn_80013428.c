#include "types.h"
#include "dolphin/os/OSContext.h"


/* --- dol/fn_80013428.c --- */
extern u8 lbl_8015CC10[160];
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern void fn_800133DC(u32, u32);
extern void fn_800133E0(u32);
extern u32 fn_800136E8(u32, u32, u32, u32);

struct SIEntry2 {
    u8 status;
    u8 pad0[19];
    u32 callback;
    u8 pad1[16];
};

s32 fn_80013428(u32 channel, u32 callback) {
    u32 interrupts;
    u32 unused[2];
    s32 result;
    struct SIEntry2 *entry;

    entry = (struct SIEntry2 *)lbl_8015CC10 + channel;
    result = callback != 0 ? (s32)callback : (s32)(u32)fn_800133DC;
    interrupts = OSDisableInterrupts();
    if (entry->callback != 0) {
        result = -2;
    } else {
        entry->callback = (u32)result;
        result = 0;
    }
    OSRestoreInterrupts(interrupts);
    if (result != 0) {
        return result;
    }
    entry->status = 0xff;
    fn_800136E8(channel, 1, 3, (u32)fn_800133E0);
}

/* --- dol/fn_800134DC.c --- */
extern u32 lbl_801A6828;

struct Fn800134DCEntry {
    u8 unk0[0x14];
    void (*callback)();
    s32 status;
    u8 unk1[8];
    void (*callback2)();
};

void fn_800134DC(u32 arg0, u32 arg1, void *arg2) {
    struct Fn800134DCEntry *entry;
    u32 unused[2];
    OSContext context;

    entry = (struct Fn800134DCEntry *)((u8 *)&lbl_8015CC10 + arg0 * 40);
    if ((s32)lbl_801A6828 == 0) {
        if ((arg1 & 0x8) != 0) {
            entry->status = -1;
        } else if ((arg1 & 0x7) != 0) {
            entry->status = -3;
        } else {
            entry->status = 0;
        }
        if (entry->callback2 != 0) {
            void (*callback2)() = entry->callback2;
            entry->callback2 = 0;
            callback2(arg0);
        }
        if (entry->callback != 0) {
            OSClearContext(&context);
            OSSetCurrentContext(&context);
            {
                void (*cb)(u32, s32) = entry->callback;
                entry->callback = 0;
                cb(arg0, entry->status);
            }
            OSClearContext(&context);
            OSSetCurrentContext(arg2);
        }
    }
}
