#include "types.h"


/* --- dol/fn_8006C134.c --- */
struct fn_8006C134_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x6];
    u16 unk_12;
    u8 pad_14[0x14];
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u8 pad_34[0x4];
    u32 unk_38;
};

s32 fn_8006C134(struct fn_8006C134_Arg0 *arg0) {
    arg0->unk_28 = (arg0->unk_28 | 1);
    arg0->unk_28 = (arg0->unk_28 & 0xFFFFFFFD);
    arg0->unk_2C = 0;
    arg0->unk_30 = arg0->unk_8;
    if ((arg0->unk_28 & 0x40) != 0) {
    arg0->unk_38 = (arg0->unk_12 << 16);
    }
    return 0;
}

/* --- dol/fn_8006C17C.c --- */
struct fn_8006C17C_Arg0 {
    u8 pad_0[0x28];
    u32 unk_28;
};

s32 fn_8006C17C(struct fn_8006C17C_Arg0 *arg0) {
    arg0->unk_28 = (arg0->unk_28 & ~0x1);
    return 0;
}
