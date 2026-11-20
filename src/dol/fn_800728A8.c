#include "types.h"
#include "dol/globals.h"


/* --- dol/fn_800728A8.c --- */
extern void fn_80037B14(s32, s32, s32, s32);

void fn_800728A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (2 == arg0) {
        if (*(s32 *)(lbl_801A6D38 + 0x1c) == 2 &&
            *(s32 *)(lbl_801A6D38 + 0x28) == arg3) {
            return;
        }

        fn_80037B14(2, arg1, arg2, arg3);
        *(s32 *)(lbl_801A6D38 + 0x1c) = 2;
        *(s32 *)(lbl_801A6D38 + 0x20) = arg1;
        *(s32 *)(lbl_801A6D38 + 0x24) = arg2;
        *(s32 *)(lbl_801A6D38 + 0x28) = arg3;
        return;
    }

    if (*(s32 *)(lbl_801A6D38 + 0x1c) == arg0 &&
        *(s32 *)(lbl_801A6D38 + 0x20) == arg1 &&
        *(s32 *)(lbl_801A6D38 + 0x24) == arg2) {
        return;
    }

    fn_80037B14(arg0, arg1, arg2, arg3);
    *(s32 *)(lbl_801A6D38 + 0x1c) = arg0;
    *(s32 *)(lbl_801A6D38 + 0x20) = arg1;
    *(s32 *)(lbl_801A6D38 + 0x24) = arg2;
    *(s32 *)(lbl_801A6D38 + 0x28) = arg3;
}

/* --- dol/fn_800729B0.c --- */
extern void GXSetTevSwapModeTable(s32, s32, s32, s32, s32);

void fn_800729B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p;

    p = (u8 *)lbl_801A6D38 + arg0 * 16 + 0x2c;
    if (*(s32 *)(p + 0) == arg1 &&
        *(s32 *)(p + 4) == arg2 &&
        *(s32 *)(p + 8) == arg3 &&
        *(s32 *)(p + 0xc) == arg4) {
        return;
    }

    GXSetTevSwapModeTable(arg0, arg1, arg2, arg3, arg4);
    *(s32 *)(p + 0) = arg1;
    *(s32 *)(p + 4) = arg2;
    *(s32 *)(p + 8) = arg3;
    *(s32 *)(p + 0xc) = arg4;
}
