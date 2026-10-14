/* Non-matching: best partial attempt (96.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/font.h"

struct fn_1_49F08_Arg1 {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x16];
    f32 unk_24;
    u8 pad_28[0x4];
    u32 unk_2C;
};
struct fn_1_49F08_Arg2 {
    u8 lab_pad[4];
    u8 pad_0[0x4];
    s16 unk_4;
};
struct fn_1_49F08_Entry {
    u8 *unk_0;
    s8 unk_4;
    s8 unk_5;
    u8 pad_6[2];
};
extern f32 lbl_1_rodata_FD0[60];

#pragma opt_common_subs off
#pragma opt_strength_reduction off
u32 fn_1_49F08(u32 arg0, struct fn_1_49F08_Arg1 *arg1, struct fn_1_49F08_Arg2 *arg2, f32 arg3) {
    f32 fzgx_live;
    u8 *pool = (u8 *)lbl_1_rodata_FD0;
    u32 v0 = arg2->unk_4;
    struct fn_1_49F08_Entry *v5;
    s32 v8;
    u32 v7;
    u8 *v10;
    u32 v11;
    if ((arg0 & 0xFFFF) == 32) {
        fzgx_live = arg1->unk_24;
        return (u32)((f32)v0 * fzgx_live);
    }
    if ((arg1->unk_2C & 0x80000000) == 0) {
        return v0;
    }
    v5 = 0;
    v8 = 0;
    switch (arg1->unk_C) {
    case 5: v5 = (void *)(pool + 0x1148); break;
    case 6: v5 = (void *)(pool + 0x13f0); break;
    case 42: v5 = (void *)(pool + 0x130); break;
    case 7: v5 = (void *)(pool + 0xb88); break;
    case 8: v5 = (void *)(pool + 0xe68); break;
    case 33: v5 = (void *)(pool + 0x440); break;
    case 10: v5 = (void *)(pool + 0x350); break;
    case 29: v5 = (void *)(pool + 0x518); break;
    case 30: v5 = (void *)(pool + 0x5f0); break;
    case 18: v5 = (void *)(pool + 0x6c8); break;
    case 21: v5 = (void *)(pool + 0x730); break;
    case 22: v5 = (void *)(pool + 0x8b8); break;
    case 19: v5 = (void *)(pool + 0x3c8); break;
    case 25: v5 = (void *)(pool + 0xa38); break;
    case 41: v5 = (void *)(pool + 0xb18); break;
    case 36: v5 = (void *)(pool + 0xaa8); break;
    }
    if (v5 != 0) {
        v7 = arg0 & 0xffff;
        if (v7 > 128) {
            while (v5->unk_5) {
                v10 = v5->unk_0;
                if (v10[0] >= 128 && v7 == (u16)((v10[0] << 8) | v10[1])) {
                    v8 = 1;
                    break;
                }
                ++v5;
            }
        } else {
            while (v5->unk_5) {
                v11 = (u8)(v5->unk_0[0]);
                if (v11 <= 128 && (s32)(v11 & 0xff) == (s32)v7) {
                    v8 = 1;
                    break;
                }
                ++v5;
            }
        }
        if (v8) {
            v0 = ((*(s8 volatile *)&((*(s8 volatile *)&(v5->unk_4)) /* Retail reloads this field. */)) /* Retail reloads this field. */ << 16) | v5->unk_5;
        }
    }
    return v0;
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

