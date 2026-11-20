#include "types.h"

struct fn_800658B4_lbl_801A6C80_T {
    u8 pad_0[0x240];
    u32 unk_240[64];
    u8 pad_340[0x101];
    u8 unk_441;
    u8 pad_442[0x1];
    u8 unk_443;
    u8 pad_444[0x20];
    s8 unk_464;
};

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern struct fn_800658B4_lbl_801A6C80_T *lbl_801A6C80;
extern u32 lbl_801A6C78;

static inline s32 fn_800658B4_push(u32 value) {
    s32 status = 0;
    if (lbl_801A6C80->unk_464 != 0) {
        status = -3;
    } else {
        lbl_801A6C80->unk_464 = -1;
        if ((value & 0x80000000) == 0) {
            status = -2;
        } else {
            BOOL enabled;
            enabled = OSDisableInterrupts();
            lbl_801A6C78 = enabled;
            if (lbl_801A6C80->unk_441 < 64 && lbl_801A6C80->unk_240[lbl_801A6C80->unk_443] == 0) {
                lbl_801A6C80->unk_240[lbl_801A6C80->unk_443] = value;
                lbl_801A6C80->unk_443 = (lbl_801A6C80->unk_443 + 1) & 0x3F;
                lbl_801A6C80->unk_441 = lbl_801A6C80->unk_441 + 1;
            } else {
                status = -1;
            }
            OSRestoreInterrupts(lbl_801A6C78);
        }
        lbl_801A6C80->unk_464 = 0;
    }
    return status;
}

s32 fn_800658B4(s32 arg0, u32 arg1) {
    s32 status;
    u32 lab_t0;
    switch (arg0) {
    case 0xA4000000:
        lab_t0 = (arg1 & 0x7F00) - 0x5B900000;
        status = fn_800658B4_push(lab_t0);
        if (status != 0) {
            return status;
        }
        arg1 = ((arg1 & 0x7F) << 8) - 0x5C000000;
        break;
    default:
        return -2;
    }
    return fn_800658B4_push(arg1);
}
