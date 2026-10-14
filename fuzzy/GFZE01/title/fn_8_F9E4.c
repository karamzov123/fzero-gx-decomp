/* Non-matching: best partial attempt (93.92% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef union Word8 {
    u32 w;
    f32 f;
} Word8;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_c;
    u8 pad_d[5];
    u16 unk_12;
    u8 pad_14[4];
    u32 unk_18;
    u32 unk_1c;
    u8 pad_20[0x1b];
    u8 unk_3b;
    u32 unk_3c;
} Obj;

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    u16 unk_4;
    Word8 unk_8;
} Node;

typedef struct {
    u8 pad_0[0x700];
    f32 unk_700;
    f32 unk_704;
    f32 unk_708;
} RData;

extern u32 lbl_801A6410;
extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;
extern u8 lbl_8_data_A1E8[0xA0];
extern u32 lbl_8_bss_550;
extern RData lbl_8_rodata_408;
extern s32 fn_1_45D0(u32, u32, u32, u32);
extern u32 fn_800793D4(u32, s32, u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_8_E440;
extern u32 fn_8_EFA4;
extern u32 fn_8_DD64;

#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_pointer_analysis off
#pragma opt_strength_reduction off

void fn_8_F9E4(u32 arg0, u32 arg1, u8 arg2) {
    Obj **slot = (Obj **)&lbl_8_bss_550;
    RData *rd = &lbl_8_rodata_408;
    u8 *data = lbl_8_data_A1E8;
    Node *n;
    u32 i;
    struct { u32 value; } j;
    u16 *base;

    *slot = (Obj *)fn_1_45D0(lbl_801A6410, 0x40, (u32)(data + 0xa0), 0x4ef);
    fn_800793D4((u32)*slot, 0, 0x40);
    (*slot)->unk_4 = arg0;
    (*slot)->unk_8 = arg1;
    fn_1_435C(arg0);
    (*slot)->unk_18 = fn_1_3F8C((u32)(data + 0x130), (u32)&fn_8_E440, 0, 0xa);
    fn_1_47F74(0x8f);
    if (lbl_1_bss_960 != 1) {
        fn_1_47F74(0x9a);
        fn_1_47F74(0x9e);
        fn_1_411A4(1);
    }
    fn_1_435C(arg1);
    (*slot)->unk_1c = fn_1_3F8C((u32)(data + 0x140), (u32)&fn_8_EFA4, 0, 0xa);
    if (lbl_801A66B4 == 5) {
        (*slot)->unk_3c = (u32)lbl_8_data_A1E8;
        (*slot)->unk_3b = 4;
    } else {
        (*slot)->unk_3c = (u32)(data + 0x50);
        (*slot)->unk_3b = 4;
    }
    for (i = 0; i < (*slot)->unk_3b; i++) {
        n = (Node *)fn_1_45D0(lbl_801A6410, 0xc, (u32)(data + 0xa0), 0x1a5);
        fn_800793D4((u32)n, 0, 0xc);
        n->unk_0 = (u8)i;
        switch ((u8)i) {
        case 0: {
            u16 id = 0xb2;
            f32 v = rd->unk_700;
            n->unk_4 = id;
            n->unk_8.f = v;
            break;
        }
        case 1: {
            u16 id = 0x114;
            f32 v = rd->unk_704;
            n->unk_4 = id;
            n->unk_8.f = v;
            break;
        }
        case 2: {
            u16 id = 0x139;
            f32 v = rd->unk_708;
            n->unk_4 = id;
            n->unk_8.f = v;
            break;
        }
        case 3: {
            u16 id = 0x54;
            f32 v = rd->unk_704;
            n->unk_4 = id;
            n->unk_8.f = v;
            break;
        }
        }
        fn_1_3F8C((u32)(data + 0x158), (u32)&fn_8_DD64, (u32)n, 0xb);
    }
    (*slot)->unk_c = arg2;
    {
        u16 * fzgx_loop_base;
        j.value = 0;
        fzgx_loop_base = (u16 *)(*slot)->unk_3c;
        while (j.value < (*slot)->unk_3b) {
            *fzgx_loop_base = 0;
            j.value++;
        }
        base = fzgx_loop_base;
    }
    (*slot)->unk_12 = 0x62;
    fn_1_A2D84(0xa9100000);
    ((u8 *)slot)[4] = 0;
    ((u8 *)slot)[5] = 0;
}

#pragma opt_strength_reduction reset
#pragma opt_pointer_analysis reset
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset
