/* Non-matching: best partial attempt (81.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

extern const struct fn_80060950_lbl_801A72A0_pool {
    f64 unk_0;
} lbl_801A72A0;

extern const struct fn_80060950_lbl_801A72A8_pool {
    f32 unk_0;
} lbl_801A72A8;

extern const struct fn_80060950_lbl_801A72AC_pool {
    f32 unk_0;
} lbl_801A72AC;

extern const struct fn_80060950_lbl_801A72B0_pool {
    f32 unk_0;
} lbl_801A72B0;

extern const struct fn_80060950_lbl_801A72B4_pool {
    f32 unk_0;
} lbl_801A72B4;

extern u8 lbl_80192D68[1344];
extern f64 fn_80088578(f32 arg);

struct fn_80060950_Arg0 {
    u8 pad_0[4];
    u8 unk_4;
    u8 pad_5[7];
    u8 unk_C;
    u8 unk_D;
    u8 pad_E[2];
};

struct fn_80060950_Ent {
    u8 unk_0;
    u8 unk_1;
    s16 unk_2;
};

struct fn_80060950_Node {
    u8 lab_pad[8];
    u32 unk_0;
    u32 unk_4;
    u16 unk_8;
    u32 unk_C[5];
    u32 unk_20;
};

#pragma opt_dead_assignments off
#pragma opt_strength_reduction off
s8 fn_80060950(struct fn_80060950_Arg0 *arg0, u8 arg1, u32 arg2, u32 arg3,
                u32 arg4) {
    struct fn_80060950_Ent *e =
        (struct fn_80060950_Ent *)((u8 *)arg0 + 0xC);
    u8 res = arg0->unk_4;
    u32 boff;
    u8 key = arg1;
    s16 cnt = arg0->unk_C;
    u32 lim;
    u8 idx;
    f32 val;
    u8 *q;
    s16 v23;
    f32 out;
    s32 v27;
    s16 v25;
    u32 a;
    struct fn_80060950_Node *nd;
    u8 *gb;

{
    u8 i;
    i = 0;
    e = (struct fn_80060950_Ent *)((u8 *)e + arg0->unk_D);
    while (i < cnt) {
        a = e->unk_0;
        if (key <= a) {
            break;
        }
        i++;
        res = a + 1;
        e++;
    }

    idx = arg2;
    boff = idx * 0x54;
    nd = (struct fn_80060950_Node *)((u8 *)lbl_801A6C80 +
                                     (((u8 *)lbl_80192D68)[boff] << 4));
    q = (u8 *)nd->unk_8;
    q = (u8 *)q + 0x84;
    lim = (((s32)e->unk_2 * ((s32)key - (s32)res)) >> 8) + e->unk_1;
    i = 0;
    q = q + *(u32 *)((u8 *)nd->unk_8 + 0x20);
    while (i < lim) {
        q++;
        i++;
}
    }

    a = q[0];
    if (a != 0) {
        val = (f32)(lbl_801A72A0.unk_0 * fn_80088578(a / lbl_801A72AC.unk_0));
    } else {
        val = lbl_801A72B0.unk_0;
    }
    a = ((u8 *)lbl_80192D68)[boff + 3];
    if (a != 0) {
        val = val + (f32)(lbl_801A72A0.unk_0 * fn_80088578(a / lbl_801A72A8.unk_0));
    } else {
        val = lbl_801A72B0.unk_0;
    }
    a = ((u8 *)lbl_80192D68)[boff + 0xE];
    if (a != 0) {
        val = val + (f32)(lbl_801A72A0.unk_0 * fn_80088578(a / lbl_801A72A8.unk_0));
    } else {
        val = lbl_801A72B0.unk_0;
    }
    a = ((u8 *)lbl_801A6C80)[0x461];
    gb = (u8 *)lbl_801A6C80 + idx * 2;
    v23 = *(s16 *)(gb + 0x5A74);
    if (a != 0) {
        out = val + (f32)(lbl_801A72A0.unk_0 * fn_80088578(a / lbl_801A72A8.unk_0));
    } else {
        out = lbl_801A72B0.unk_0;
    }

    v25 = *(s16 *)((u8 *)lbl_801A6C80 + 0x5A10);
    v27 = (s32)(lbl_801A72B4.unk_0 * out);
    *(f32 *)arg3 = out;
    *(u16 *)arg4 = (u16)(v23 + v25);
    v27 = (s16)(v23 + v25 + v27);
    if (v27 < -960) {
        v27 = -960;
    }
    return v27;
}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

