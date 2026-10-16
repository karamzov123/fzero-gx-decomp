/* Non-matching: best partial attempt (90.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const struct fn_80069FCC_lbl_801A7350_pool {
    f64 unk_0;
} lbl_801A7350;

extern const struct fn_80069FCC_lbl_801A7358_pool {
    f32 unk_0;
} lbl_801A7358;

extern const struct fn_80069FCC_lbl_801A735C_pool {
    f32 unk_0;
} lbl_801A735C;

extern const struct fn_80069FCC_lbl_801A7360_pool {
    f32 unk_0;
} lbl_801A7360;

extern const struct fn_80069FCC_lbl_801A7364_pool {
    f32 unk_0;
} lbl_801A7364;

extern u32 lbl_801A6C80;
extern f64 fn_80088578(f32);

typedef struct {
    u8 pad_0[9];
    u8 unk_9;
    u8 pad_A[0x22];
    u8 unk_2C;
} fn_80069FCC_Arg0;

struct Slot {
    u8 pad[0x496];
    u8 field_496;
};

#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
s32 fn_80069FCC(fn_80069FCC_Arg0 *arg0, u32 arg1) {
    u8 *entry;
    u8 *r4_base;
    u8 *p;
    u32 count;
    s8 i;
    u8 v;
    u8 idx;
    f32 f;
    s32 s;
    u8 *base;
    struct Slot *slot;

    entry = (u8 *)lbl_801A6C80 + (*(u8 *)((u8 *)lbl_801A6C80 + 0x45b) << 4);
    r4_base = *(u8 **)(entry + 8);
    p = r4_base + (arg0->unk_2C << 7);
    p = (p + 4) + *(u32 *)(r4_base + 0x20);
    count = arg0->unk_9;
    i = 0;

    if (count > 0) {
        if (count > 8) {
            s32 limit = count - 8;
            for (; (u8)i < (u8)limit; i += 8) {
                p += 8;
            }
        }
        for (; (u8)i < (u8)count; i++) {
            p++;
        }
    }

    v = *p;
    if (v != 0) {
        f = (f32)(lbl_801A7350.unk_0 * fn_80088578((f32)v / lbl_801A7358.unk_0));
    } else {
        f = lbl_801A735C.unk_0;
    }

    v = *(u8 *)((u8 *)lbl_801A6C80 + 0x5a08);
    if (v != 0) {
        f += (f32)(lbl_801A7350.unk_0 * fn_80088578((f32)v / lbl_801A7360.unk_0));
    } else {
        f = lbl_801A735C.unk_0;
    }

    idx = (u8)arg1;
    slot = (struct Slot *)((u8 *)lbl_801A6C80 + (idx << 4));
    (void) slot;  /* fzgx: keeps the web at its definition */
    v = slot->field_496;
    if (v != 0) {
        f += (f32)(lbl_801A7350.unk_0 * fn_80088578((f32)v / lbl_801A7360.unk_0));
    } else {
        f = lbl_801A735C.unk_0;
    }

    base = (u8 *)lbl_801A6C80;
    v = base[0x461];
    s = *(s16 *)((((0x5a14) + ((idx << 1))) + (base)));
    if (v != 0) {
        f = f + (f32)(lbl_801A7350.unk_0 * fn_80088578((f32)v / lbl_801A7360.unk_0));
    } else {
        f = lbl_801A735C.unk_0;
    }

    s += *(s16 *)((u8 *)lbl_801A6C80 + 0x5a10);
    s += (s16)(s32)(lbl_801A7364.unk_0 * f);
    if (s < -960) {
        s = -960;
    }
    return s;
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset
#pragma opt_dead_assignments reset
