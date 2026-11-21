#include "types.h"

extern u32 lbl_80164D60[];

u32 fn_80022E5C(void) {
    return (u32)&lbl_80164D60;
}

struct fn_80022E68_Arg0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u8 pad_20[0x4];
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x4];
    u32 unk_30;
    u8 pad_34[0x112];
    u16 unk_146;
    u8 pad_148[0x26];
    u16 unk_16E;
    u8 pad_170[0xC];
    u16 unk_17C;
    u16 unk_17E;
    u16 unk_180;
    u16 unk_182;
    u16 unk_184;
};

void fn_80022E68(struct fn_80022E68_Arg0 *arg0) {
    arg0->unk_146 = 0;
    arg0->unk_16E = 0;
    arg0->unk_1C = 164;
    arg0->unk_28 = 0;
    arg0->unk_24 = 0;
    arg0->unk_30 = ((u32)arg0 + 52);
    arg0->unk_184 = 0;
    arg0->unk_182 = 0;
    arg0->unk_180 = 0;
    arg0->unk_17E = 0;
    arg0->unk_17C = 0;
}
