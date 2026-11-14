#include "types.h"
struct Sig_fn_8006C634_fn_8006C634_Arg2 { u32 unk_0; };
struct Sig_fn_8006C6E8_fn_8006C6E8_Arg0 {
    u8 pad_0[0x24]; u32 unk_24; u8 pad_28[0x10]; u32 unk_38; u32 unk_3C;
};
struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 {
    u8 pad_0[2]; u8 unk_2; u8 unk_3; s16 unk_4; s16 unk_6;
};
struct fn_8006C190_Arg0 {
    u8 unk_0; u8 pad_1[3]; u32 unk_4; u32 unk_8;
    s16 unk_C; u16 unk_E; u16 unk_10; u16 unk_12;
    s16 unk_14; u8 pad_16[0x12]; u32 unk_28;
    u32 unk_2C; u32 unk_30; u32 unk_34; u32 unk_38;
};
struct fn_8006C634_lbl_8019E014 { s16 unk_0[1]; };
extern struct fn_8006C634_lbl_8019E014 lbl_8019E014[];
extern struct fn_8006C634_lbl_8019E014 lbl_8019E094[];
extern s32 fn_8006C6E8(struct Sig_fn_8006C6E8_fn_8006C6E8_Arg0 *, struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 *);
extern u32 fn_8006C570(struct fn_8006C190_Arg0 *, void *, s32);
extern s32 fn_8006C788(struct fn_8006C190_Arg0 *, void *);
extern void fn_8006C634(u32, u32, struct Sig_fn_8006C634_fn_8006C634_Arg2 *);

static inline s32 fn_8006C190_ramp(s32 current, s32 duration, s32 start, s32 end) {
    s32 round;
    s32 difference;
    difference = end - start;
    round = duration / 2;
    if (difference < 0) round = -round;
    difference = difference * current;
    difference += round;
    return start + difference / duration;
}

s32 fn_8006C190(struct fn_8006C190_Arg0 *arg0, u32 arg1) {
    s32 v4;
    u32 v10;
    s16 v9;
    s32 v8;
    s32 v17;
    struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 * lab_t1;
    if (arg0->unk_28 & 1) {
        if (arg0->unk_30 != 0) {
            arg0->unk_30 -= arg1;
            if ((s32)arg0->unk_30 < 0) arg0->unk_30 = 0;
        } else {
            arg0->unk_2C += arg1;
            if (arg0->unk_4 != -1 && arg0->unk_4 < arg0->unk_2C) {
                if (arg0->unk_28 & 2) arg0->unk_28 &= ~1;
            }
        }
    }
    arg0->unk_28 |= 2;
    v4 = 0;
    if ((arg0->unk_28 & 1) && arg0->unk_30 == 0) v4 = 1;
    if (v4) {
        if (arg0->unk_28 & 0x10) {
            v4 = fn_8006C570(arg0, &arg0->unk_10, arg0->unk_C);
            fn_8006C634(v4, arg0->unk_E, (struct Sig_fn_8006C634_fn_8006C634_Arg2 *)&arg0->unk_34);
        } else if (arg0->unk_28 & 0x20) {
            v4 = fn_8006C190_ramp(arg0->unk_2C, arg0->unk_4, arg0->unk_C, *(s16 *)&arg0->unk_E);
            fn_8006C634(v4, arg0->unk_10, (struct Sig_fn_8006C634_fn_8006C634_Arg2 *)&arg0->unk_34);
        } else if (arg0->unk_28 & 0x40) {
            arg1 = (arg1 << 24) / arg0->unk_10;
            arg0->unk_38 += arg1;
            if (arg0->unk_38 >= 0x1000000) arg0->unk_38 -= arg0->unk_38 & ~0xFFFFFF;
            v9 = fn_8006C570(arg0, (u8 *)arg0 + 0x18, *(u8 *)&arg0->unk_C);
            switch (arg0->unk_0) {
            case 2:
                v10 = (arg0->unk_38 >> 16) & 0xFF;
                if (v10 < 64) v4 = lbl_8019E014[0].unk_0[v10];
                else if (v10 < 128) v4 = lbl_8019E014[0].unk_0[127-v10];
                else if (v10 < 192) v4 = -(*((0) + (lbl_8019E014))).unk_0[v10-128];
                else v4 = -lbl_8019E014[0].unk_0[255-v10];
                v8 = v4;
                break;
            case 3:
                v8 = -1024;
                if ((arg0->unk_38 >> 16) < 128) v8 = 1024;
                break;
            case 4:
                v10 = (arg0->unk_38 >> 16) & 0xFF;
                if (v10 < 64) v4 = lbl_8019E094[0].unk_0[v10];
                else if (v10 < 128) v4 = lbl_8019E094[0].unk_0[127-v10];
                else if (v10 < 192) v4 = -lbl_8019E094[0].unk_0[v10-128];
                else v4 = -lbl_8019E094[0].unk_0[255-v10];
                v8 = v4;
                break;
            case 5: v8 = lbl_8019E094[0].unk_0[(arg0->unk_38 >> 18) & 63]; break;
            case 6: v8 = lbl_8019E094[0].unk_0[(255 - ((arg0->unk_38 >> 16) & 255)) >> 2]; break;
            default: v8 = 0; break;
            }
            v4 = 512;
            if (v8 < 0) v4 = -512;
            v17 = v8 * v9;
            v17 += v4;
            v4 = v17 / 1024 + arg0->unk_14;
            fn_8006C634(v4, arg0->unk_E, (struct Sig_fn_8006C634_fn_8006C634_Arg2 *)&arg0->unk_34);
        } else if (arg0->unk_28 & 0x80) {
            lab_t1 = (struct Sig_fn_8006C6E8_fn_8006C6E8_Arg1 *)&arg0->unk_C;
            switch (arg0->unk_0) {
            case 7:
                arg0->unk_34 = fn_8006C6E8((struct Sig_fn_8006C6E8_fn_8006C6E8_Arg0 *)arg0, lab_t1);
                break;
            case 8:
                arg0->unk_34 = fn_8006C788(arg0, lab_t1);
                if ((s32)arg0->unk_34 == 0) arg0->unk_34 = arg0->unk_34 + 1;
                break;
            default: arg0->unk_34 = 0; break;
            }
        } else return 0;
    } else arg0->unk_34 = 0;
    return 1;
}

