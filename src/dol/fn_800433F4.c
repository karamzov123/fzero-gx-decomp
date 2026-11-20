#include "types.h"


/* --- dol/fn_800433F4.c --- */
typedef u32 (*fn_800433F4_Fn0)(u32, u32);

extern u32 lbl_8017A284[];

struct fn_800433F4_Arg0 {
    u8 pad_0[0xB0];
    u32 unk_B0;
};

void fn_800433F4(struct fn_800433F4_Arg0 *arg0, u32 arg1) {
    u32 unk_1;

    unk_1 = arg0->unk_B0;
    if (unk_1 != 0) {
        ((fn_800433F4_Fn0)lbl_8017A284[0])(unk_1, arg1);
    }
}

/* --- dol/fn_8004342C.c --- */
extern u32 fn_80043460(u32);
extern u32 fn_80043798(void);

struct fn_8004342C_Arg0 {
    u8 pad_0[0x9A];
    s16 unk_9A;
};

void fn_8004342C(struct fn_8004342C_Arg0 *arg0) {
    if (arg0->unk_9A == 1) {
    fn_80043460((u32)arg0);
    } else {
    fn_80043798();
    }
}
