#include "types.h"

extern struct fn_16_6834_lbl_16_rodata_58 lbl_16_rodata_58;

struct fn_16_6834_lbl_16_rodata_58 {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x28];
    f32 unk_34;
    u8 pad_38[0x1C];
    f32 unk_54;
    u8 pad_58[0x18];
    f32 unk_70;
    u8 pad_74[0x44];
    f32 unk_B8;
    u8 pad_BC[0xC4];
    f32 unk_180;
    u8 pad_184[0x2C];
    f32 unk_1B0;
    f32 unk_1B4;
    f32 unk_1B8;
    f32 unk_1BC;
    f32 unk_1C0;
    f32 unk_1C4;
    f32 unk_1C8;
    f32 unk_1CC;
};

u8 lbl_16_data_83440[] = {
    0x25U, 0x73U, 0x0AU, 0x00U, 0x25U, 0x34U, 0x64U, 0x6BU, 0x67U, 0x0AU, 0x00U, 0x00U, 0x63U, 0x30U, 0x78U, 0x38U, 0x33U, 0x62U, 0x34U, 0x00U, 0x63U, 0x30U, 0x78U, 0x38U, 0x33U, 0x62U, 0x32U, 0x00U
};

f32 fn_16_6834(u32 arg0, f32 arg1) {
    struct fn_16_6834_lbl_16_rodata_58 *p;
    f32 v;
    p = (struct fn_16_6834_lbl_16_rodata_58 *)&lbl_16_rodata_58;
    switch ((s16)arg0) {
    case 0: v = p->unk_70; break;
    case 1: v = p->unk_70; break;
    case 2: v = p->unk_1B0; break;
    case 3: v = p->unk_1B0; break;
    case 4: v = p->unk_8; break;
    case 5: v = p->unk_1B4; break;
    case 6: v = p->unk_70; break;
    case 7: v = p->unk_8; break;
    case 8: v = p->unk_1B8; break;
    case 9: v = p->unk_1B4; break;
    case 10: v = p->unk_1BC; break;
    case 11: v = p->unk_8; break;
    case 12: v = p->unk_1C0; break;
    case 13: v = p->unk_70; break;
    case 14: v = p->unk_1B4; break;
    case 15: v = p->unk_70; break;
    case 16: v = p->unk_8; break;
    case 17: v = p->unk_1B0; break;
    case 18: v = p->unk_180; break;
    case 19: v = p->unk_1B8; break;
    case 20: v = p->unk_1B8; break;
    case 21: v = p->unk_B8; break;
    case 22: v = p->unk_70; break;
    case 23: v = p->unk_1B4; break;
    case 24: v = p->unk_B8; break;
    case 25: v = p->unk_1BC; break;
    case 26: v = p->unk_1B0; break;
    case 27: v = p->unk_1B4; break;
    case 28: v = p->unk_1BC; break;
    case 29: v = p->unk_1B8; break;
    case 30: v = p->unk_1C4; break;
    case 31: v = p->unk_1C4; break;
    case 32: v = p->unk_34; break;
    case 33: v = p->unk_1B8; break;
    case 34: v = p->unk_1B4; break;
    case 35: v = p->unk_70; break;
    case 36: v = p->unk_8; break;
    case 37: v = p->unk_1BC; break;
    case 38: v = p->unk_8; break;
    case 39: v = p->unk_1C8; break;
    case 40: v = p->unk_1C4; break;
    default: v = p->unk_54; break;
    }
    return p->unk_1CC * v;
}
