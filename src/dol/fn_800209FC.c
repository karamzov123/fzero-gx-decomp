#include "types.h"


/* --- dol/fn_800209FC.c --- */
extern u32 lbl_801A6AB8;

struct fn_800209FC_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_800209FC(struct fn_800209FC_Arg0 *arg0) {
    arg0->unk_8 = lbl_801A6AB8;
    lbl_801A6AB8 = (u32)arg0;
}

/* --- dol/fn_80020A0C.c --- */
/* --- dol/fn_80020A0C.c --- */

u32 fn_80020A0C(u32 arg0) {
    u32 ptr;

    ptr = lbl_801A6AB8;
    if (ptr == 0) {
        return ptr;
    }
    lbl_801A6AB8 = *(u32 *)(ptr + 8);
    return ptr;
}

/* --- dol/fn_80020A28.c --- */
struct fn_80020A28_Arg0 {
    u8 pad_0[12];
    u32 unk_C;
};

extern u32 lbl_8015D100[];
extern u32 lbl_8015D180[];

u32 fn_80020A28(struct fn_80020A28_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    v0 = arg0->unk_C;
    v1 = *(u32 *)(((u8 *)&lbl_8015D100 + (v0 << 2)));
    v2 = *(u32 *)(((u8 *)&lbl_8015D180 + (v0 << 2)));
    if (v1 == v2) {
    *(u32 *)((u8 *)((u8 *)&lbl_8015D180 + (v0 << 2)) + 0) = 0;
    *(u32 *)((u8 *)((u8 *)&lbl_8015D100 + (v0 << 2)) + 0) = 0;
    return (u32)arg0;
    }
    if ((u32)arg0 == v1) {
    v3 = *(u32 *)(arg0);
    *(u32 *)((u8 *)((u8 *)&lbl_8015D100 + (v0 << 2)) + 0) = v3;
    v3 = *(u32 *)(((u8 *)&lbl_8015D100 + (v0 << 2)));
    *(u32 *)((u8 *)v3 + 4) = 0;
    return v3;
    }
    if ((u32)arg0 == v2) {
    v3 = *(u32 *)((u8 *)arg0 + 4);
    *(u32 *)((u8 *)((u8 *)&lbl_8015D180 + (v0 << 2)) + 0) = v3;
    v3 = *(u32 *)(((u8 *)&lbl_8015D180 + (v0 << 2)));
    *(u32 *)((u8 *)v3 + 0) = 0;
    return v3;
    }
    v4 = *(u32 *)((u8 *)arg0 + 4);
    arg0 = (struct fn_80020A28_Arg0 *)*(u32 *)(arg0);
    *(u32 *)((u8 *)v4 + 0) = (u32)arg0;
    *(u32 *)((u8 *)arg0 + 4) = v4;
    return (u32)arg0;
}
