#include "types.h"
#include "dol/globals.h"


/* --- dol/fn_80063094.c --- */
extern s32 fn_80067898(u32);

s32 fn_80063094(s32 arg0, s32 arg1, s32 arg2) {
    u32 v0 = (arg0 & 0xF) << 16;
    u8 *p = (u8 *)(v0 + arg1);
    s32 r;

    switch (arg1) {
    case 0xA5000000:
        r = fn_80067898((u32)((v0 - 0x5A900000) + (arg2 & 0x7F00)));
        if (r != 0)
            return r;
        p = (u8 *)(v0 - 0x5B000000) + ((arg2 & 0x7F) << 8);
        break;
    case 0xA5100000:
        p += (arg2 & 0x7F) << 8;
        break;
    case 0xA5200000:
    case 0xA5300000:
    case 0xA5400000:
    case 0xA5500000:
    case 0xA7000000:
    case 0xA7100000:
        p += ((arg2 + 0x40) & 0x7F) << 8;
        break;
    case 0xA6000000:
        p += ((arg2 & 0x7F) << 8) + ((arg2 << 13) & 0x100000);
        break;
    case 0xA7200000: {
        u8 *q = (u8 *)lbl_801A6C80;
        q += (arg0 & 0xF) << 1;
        *(u16 *)(q + 0x5AF4) = arg2;
        break;
    }
    default:
        return -2;
    }
    return fn_80067898((u32)p);
}

/* --- dol/fn_800631EC.c --- */
struct fn_800631EC_Entry {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u32 unk_10;
    u8 unk_14[16][4];
};

extern struct fn_800631EC_Entry lbl_80192D68[16];

void fn_800631EC(void) {
    u8 i;
    u8 j;

    for (i = 0; i < 16; i++) {
        lbl_80192D68[i].unk_0 = 0xff;
        lbl_80192D68[i].unk_1 = 0;
        lbl_80192D68[i].unk_3 = 0x7f;
        lbl_80192D68[i].unk_4 = 0x40;
        lbl_80192D68[i].unk_5 = 0x40;
        lbl_80192D68[i].unk_6 = 0x40;
        lbl_80192D68[i].unk_7 = 0x40;
        lbl_80192D68[i].unk_9 = 0x40;
        lbl_80192D68[i].unk_A = 0x40;
        lbl_80192D68[i].unk_B = 0;
        lbl_80192D68[i].unk_C = 0;
        lbl_80192D68[i].unk_D = 0;
        lbl_80192D68[i].unk_E = 0;
        lbl_80192D68[i].unk_F = 0;
        lbl_80192D68[i].unk_10 = 0;
        for (j = 0; j < 16; j++) {
            lbl_80192D68[i].unk_14[j][0] = 0;
            lbl_80192D68[i].unk_14[j][1] = 0;
            lbl_80192D68[i].unk_14[j][2] = 0xff;
            lbl_80192D68[i].unk_14[j][3] = 0xff;
        }
    }
}
