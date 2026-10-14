/* Non-matching: best partial attempt (98.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/sel/sel.h"
#include "rel/sel/data/lbl_10_rodata_1C40.h"

extern const struct fn_10_25610_lbl_10_rodata_1548_pool {
    u8 pad_0[0x700];
    f32 unk_700;
    f32 unk_704;
    f32 unk_708;
} lbl_10_rodata_1548;

extern u32 lbl_801A6410;
extern s16 lbl_1_bss_960;
extern s32 lbl_801A66B4;

typedef union Word8 {
    u32 w;
    f32 f;
} Word8;

typedef struct Node {
    u8 unk_0;
    u8 pad_1[3];
    u16 unk_4;
    Word8 unk_8;
} Node;

extern u32 fn_1_45D0(u32, u32, u32, u32);
extern u32 fn_800793D4(u32, s32, u32);
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_1_411A4(u32);
extern void fn_1_A2D84(u32);
extern u32 fn_10_2406C;
extern u32 fn_10_24BD0;
extern u32 fn_10_23990;

#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_pointer_analysis off
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
#pragma opt_dead_assignments off

void fn_10_25610(u32 arg0, u32 arg1, u8 arg2) {
    u16 fzgx_value;
    Obj_10_bss_55CD8_Target **slot = &lbl_10_bss_55CD8;
    struct fn_10_25610_lbl_10_rodata_1548_pool *pool_lbl_10_rodata_1548 = (struct fn_10_25610_lbl_10_rodata_1548_pool *)&lbl_10_rodata_1548;
    u8 *data = lbl_10_data_68E0;
    Node *n;
    u32 i;
    struct { u32 value; } j;
    u16 *p;
    u32 lab_t2;

    *slot = (Obj_10_bss_55CD8_Target *)fn_1_45D0(lbl_801A6410, 0x40, (u32)(data + 0xa0), 0x4ef);
    lab_t2 = 0x40;
    fn_800793D4((u32)*slot, 0, lab_t2);
    (*slot)->unk_4 = arg0;
    (*slot)->unk_8 = arg1;
    fn_1_435C(arg0);
    (*slot)->unk_18 = fn_1_3F8C((u32)(data + 0x130), (u32)&fn_10_2406C, 0, 0xa);
    fn_1_47F74(0x8f);
    if (lbl_1_bss_960 != 1) {
        fn_1_47F74(0x9a);
        fn_1_47F74(0x9e);
        fn_1_411A4(1);
    }
    fn_1_435C(arg1);
    (*slot)->unk_1C = fn_1_3F8C((u32)(data + 0x140), (u32)&fn_10_24BD0, 0, 0xa);
    if (lbl_801A66B4 == 5) {
        (*slot)->unk_3C = (u32)data;
        (*slot)->unk_3B = 4;
    } else {
        (*slot)->unk_3C = (u32)(data + 0x50);
        (*slot)->unk_3B = 4;
    }
    i = 0;
    while (i < (*slot)->unk_3B) {
        n = (Node *)fn_1_45D0(lbl_801A6410, 0xc, (u32)(data + 0xa0), 0x1a5);
        lab_t2 = 0xc;
        fn_800793D4((u32)n, 0, lab_t2);
        n->unk_0 = i;
        switch ((u8)i) {
        case 0:
            n->unk_4 = 0xb2;
            n->unk_8.f = pool_lbl_10_rodata_1548->unk_700;
            break;
        case 1:
            fzgx_value = 0x114;
            n->unk_4 = fzgx_value;
            n->unk_8.f = pool_lbl_10_rodata_1548->unk_704;
            break;
        case 2:
            n->unk_4 = 0x139;
            n->unk_8.f = pool_lbl_10_rodata_1548->unk_708;
            break;
        case 3:
            n->unk_4 = 0x54;
            n->unk_8.f = pool_lbl_10_rodata_1548->unk_704;
            break;
        }
        fn_1_3F8C((u32)(data + 0x158), (u32)&fn_10_23990, (u32)n, 0xb);
        i++;
    }
    (*slot)->unk_C = arg2;
    j.value = 0;
    p = (u16 *)(*slot)->unk_3C;
    while (j.value < (*slot)->unk_3B) {
        *p = 0;
        j.value++;
    }
    (*slot)->unk_12 = 0x62;
    fn_1_A2D84(0xa9100000U);
    ((u8 *)slot)[4] = 0;
    ((u8 *)slot)[5] = 0;
}

#pragma opt_dead_assignments reset
#pragma opt_lifetimes reset
#pragma opt_strength_reduction reset
#pragma opt_pointer_analysis reset
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
#pragma opt_common_subs reset
