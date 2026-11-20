#include "types.h"


/* --- dol/fn_800420F4.c --- */
extern u32 fn_80045354(u32);

struct fn_800420F4_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

void fn_800420F4(struct fn_800420F4_Arg0 *arg0) {
    fn_80045354(arg0->unk_4);
    *(u8 *)((u8 *)(u32)arg0 + 1) = 0;
}

/* --- dol/fn_8004212C.c --- */
struct fn_8004212C_Arg0 {
    u8 pad_0[0x1];
    u8 unk_1;
    u8 pad_2[0x1];
    u8 unk_3;
    u8 pad_4[0x28];
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u8 pad_48[0x50];
    u32 unk_98;
};

void fn_8004212C(struct fn_8004212C_Arg0 *arg0) {
    arg0->unk_98 = 0;
    arg0->unk_2C = 0;
    arg0->unk_30 = 0;
    arg0->unk_34 = 0;
    arg0->unk_38 = (0x80000000 - 1);
    arg0->unk_3C = -1;
    arg0->unk_40 = 0;
    arg0->unk_44 = 0;
    arg0->unk_3 = 0;
    arg0->unk_1 = 1;
}
