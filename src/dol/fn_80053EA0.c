#include "types.h"


/* --- dol/fn_80053EA0.c --- */
/* --- dol/fn_80053EA0.c --- */
struct fn_80053EA0_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};

u32 fn_80053EA0(struct fn_80053EA0_Arg0 *arg0) {
    return arg0->unk_1C;
}

/* --- dol/fn_80053EA8.c --- */
struct fn_80053EA8_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};

u32 fn_80053EA8(struct fn_80053EA8_Arg0 *arg0) {
    return arg0->unk_20;
}

/* --- dol/fn_80053EB0.c --- */
typedef u32 (*fn_80053EB0_Fn0)(u32, u32);
struct fn_80053EB0_Arg0 {
    u8 pad_0[0x5];
    u8 unk_5;
};

extern u32 fn_800510D8(u32);
extern u32 fn_80051448(u32);
extern u32 fn_80053F38(void);

void fn_80053EB0(struct fn_80053EB0_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 t0, t1, t2, t3;
    v0 = (u32)arg0;
    if ((s8)arg0->unk_5 == 2) {
    t0 = fn_80053F38();
    v0 = t0;
    } else {
    if ((s8)arg0->unk_5 == 1) {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 12);
    v1 = *(u32 *)((u8 *)v0 + 0);
    t1 = ((fn_80053EB0_Fn0)*(u32 *)((u8 *)v1 + 36))(v0, 1);
    v0 = t1;
    if ((s32)v0 >= 36) {
    v0 = *(u32 *)((u8 *)(u32)arg0 + 0);
    t2 = fn_80051448(v0);
    v0 = t2;
    v0 = *(u32 *)((u8 *)(u32)arg0 + 0);
    t3 = fn_800510D8(v0);
    v0 = t3;
    v0 = 1;
    *(u8 *)((u8 *)(u32)arg0 + 7) = v0;
    *(u8 *)((u8 *)(u32)arg0 + 5) = 2;
    }
    }
    }
}
