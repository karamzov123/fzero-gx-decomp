/* Non-matching: best partial attempt (98.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/motasglist.h"
typedef struct Sig_fn_1_42254_Fn41CB8Node {
    u8 pad0[0x28];
    u32 items;
    u8 pad2C[4];
    struct Sig_fn_1_42254_Fn41CB8Node *next;
} Sig_fn_1_42254_Fn41CB8Node;
typedef struct Sig_fn_1_42254_Fn41CB8Entry {
    u8 pad0[4];
    Sig_fn_1_42254_Fn41CB8Node *next;
    u8 pad8[2];
    u16 count;
} Sig_fn_1_42254_Fn41CB8Entry;
struct fn_1_42254_Arg0 {
    u8 pad_0[0x2];
    u16 unk_2;
    u8 pad_4[0x4];
    u32 unk_8;
    u8 pad_C[0x6];
    u16 unk_12;
    u8 pad_14[0xC];
    u32 unk_20;
    u8 pad_24[0x2];
    u8 unk_26;
    u8 pad_27[0x1];
    u32 unk_28;
    u8 pad_2C[0x8];
    u32 unk_34;
    u8 pad_38[0x4];
    u32 unk_3C;
    u8 pad_40[0xC];
    u8 unk_4C;
};
#pragma opt_lifetimes on
#pragma opt_loop_invariants off
s32 fn_1_42254(struct fn_1_42254_Arg0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct Sig_fn_1_42254_Fn41CB8Node * fzgx_live_;
    struct Sig_fn_1_42254_Fn41CB8Node * fzgx_live;
    u16 v0;
    u32 v1;
    u32 v2;
    u32 v4;
    Sig_fn_1_42254_Fn41CB8Node *v5;
    u32 v2_2;
    struct { int value; } v8;
    u32 v11;
    u32 v12;
    u8 v13;
    u32 v17;
    u16 v14;
    u16 v14_2;
    u32 v15;
    int v18;
    u16 v20;
    u16 v22;
    u32 v23;
    struct { s32 value; } frame;
    v0 = arg0->unk_12;
    v1 = arg0->unk_26;
    v2 = arg3;
    if ((s32)v0 < (s32)v1) {
        v2_2 = arg0->unk_28 + v0 * 12;
    } else if (arg0->unk_34 != 0) {
        v2_2 = arg0->unk_34 + (v0 - arg0->unk_4C) * 12;
    }
    v4 = arg0->unk_2;
    if (v4 & 1) {
        v5 = (Sig_fn_1_42254_Fn41CB8Node *)(*(u32 *)(v2_2 + 4) + *(u16 *)(v2_2 + 10) * 52);
    } else {
        v5 = *(Sig_fn_1_42254_Fn41CB8Node **)(v2_2 + 4);
        for (v8.value = 0; v8.value < (*(u16 *)(v2_2 + 10)); v8.value++) {
            fzgx_live_ = v5->next;
            fzgx_live = fzgx_live_;
            v5 = fzgx_live;
        }
    }
    frame.value = (s32)*(f32 *)(arg0->unk_8 + 76);
    v11 = (((arg1 << 2)) + (v5->items));
    if ((s32)v0 >= (s32)v1) {
        v12 = arg0->unk_3C;
    } else {
        v12 = arg0->unk_20;
    }
    v13 = *(u8 *)(v11 + 1);
    if (v13 != 0 || v12 != 0) {
        if (v4 & 4) {
            v14 = frame.value;
            v15 = v12 + (*(u16 *)(v11 + 2) << 4);
            v17 = v15;
            for (v18 = 0; v18 < v13; v18++) {
                if (v14 < *(u16 *)(v17 + 2)) break;
                v17 += 16;
            }
            if (v18 == 0) v18 = v13;
            return v15 + ((v18 - 1) << 4);
        } else {
            v20 = (u16)(*(u16 *)(v11 + 2));
{
    u16 v21;
            v21 = 65535;
            v14_2 = frame.value;
            v22 = v20;
            do {
                v23 = v12 + (v22 << 4);
                if (v14_2 < *(u16 *)(v23 + 2)) {
                    v21 = v22;
                    v22 = *(u16 *)(v23 + 12);
                } else {
                    v22 = *(u16 *)(v23 + 14);
                }
            } while (v22 != 65535);
            if (v21 == 65535) {
                v21 = v20;
                while ((v22 = *(u16 *)(v12 + (v21 << 4) + 12)) != 65535) {
                    v21 = v22;
                }
            }
            return v12 + (v21 << 4);
}
        }
    }
    return 0;
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

