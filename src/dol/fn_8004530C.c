#include "types.h"


/* --- dol/fn_8004530C.c --- */
extern u32 fn_8004E198(u32);

struct fn_8004530C_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

u32 fn_8004530C(struct fn_8004530C_Arg0 *arg0) {
    u32 v0;
    u32 t0;
    v0 = (u32)arg0;
    if ((s32)arg0->unk_4 == 3) {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 8);
    t0 = fn_8004E198(v0);
    v0 = t0;
    *(u32 *)((u8 *)(u32)arg0 + 140) = 0;
    *(u32 *)((u8 *)(u32)arg0 + 4) = 0;
    }
    return v0;
}

/* --- dol/fn_80045354.c --- */
extern u32 fn_8004E1B0(u32);

struct fn_80045354_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_80045354(struct fn_80045354_Arg0 *arg0) {
    fn_8004E1B0(arg0->unk_8);
    *(u32 *)((u8 *)(u32)arg0 + 4) = 0;
}
