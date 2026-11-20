#include "types.h"


/* --- dol/fn_80077B14.c --- */
struct fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

extern u32 OSReport(u32, ...);
extern u32 lbl_8015AD48[];

s32 fn_80077B14(struct fn_80077B14_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0;
    v0 = arg0->unk_20;
    v1 = ((u32)arg0 + v0);
    v2 = v1;
    if ((arg0->unk_4 & 0x18) != 0) {
    v2 = (v2 + *(u32 *)((u8 *)v2 + 8));
    } else {
    v2 = (u32)&lbl_8015AD48;
    t0 = OSReport((u32)v2);
    v2 = t0;
    v2 = 0;
    }
    return v2;
}

/* --- dol/fn_80077B64.c --- */
struct fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};


s32 fn_80077B64(struct fn_80077B64_Arg0 *arg0) {
    u32 v0;
    u32 t0;
    v0 = (u32)arg0;
    if ((arg0->unk_4 & 0x18) != 0) {
    v0 = (v0 + *(u32 *)((u8 *)v0 + 32));
    } else {
    v0 = (u32)&lbl_8015AD48;
    t0 = OSReport((u32)v0);
    v0 = t0;
    v0 = 0;
    }
    return v0;
}
