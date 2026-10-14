/* Non-matching: best partial attempt (65.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Sig_fn_800501F4_fn_800501F4_Arg0 {
    u8 pad_0[0x8];
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
};

struct fn_80050698_Entry {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    f32 unk_10;
    f32 unk_14;
};

struct fn_80050698_Arg1 {
    u8 pad_0[0x4];
    s32 unk_4;
    u8 pad_8[0x8];
    s32 unk_10;
    s32 unk_14;
    struct fn_80050698_Entry *unk_18;
};

extern u32 lbl_80187114;
extern u32 lbl_80186FA8;
extern s32 fn_800501F4(struct Sig_fn_800501F4_fn_800501F4_Arg0 *, s32);
extern f32 lbl_80130A48[];
extern s32 lbl_80130B98[];
extern s8 lbl_80130C00[3][32];
extern s8 lbl_80130C60[3][128];
extern s8 lbl_80130DE0[3][1024];

void fn_80050698(struct Sig_fn_800501F4_fn_800501F4_Arg0 *arg0, struct fn_80050698_Arg1 *arg1,
                u32 *arg2, u32 *arg3, s32 arg4, f32 *arg5) {
    u32 *q0;
    u32 *q1;
    f32 *pw;
    u32 *p2;
    u32 *p3;
    f32 *p5;
    f32 *base;
    s32 i;
    s32 j;
    struct fn_80050698_Entry *ent;
    s32 n;
    s32 cnt;
    s32 thresh;
    f32 *pz;
    s32 sh;
    s32 val;
    s32 idx;
    s32 mask;
    s32 t;
    s32 q;
    s32 q2;
    f32 m;
    f32 sx;
    f32 sy;

    ent = arg1->unk_18;
    base = arg5;
    n = arg1->unk_4;
    p2 = arg2;
    p3 = (u32 *)((u8 *)arg3 + (arg4 << 7));
    p5 = arg5;
    lbl_80187114 = 0;
    lbl_80186FA8 = 0;

    for (i = 0; i < cnt; i++) {
        q0 = p2;
        q1 = p3;
        pw = p5;

        for (j = 0; j < (i < thresh ? n : 1); j++) {
            if (*q0 != 0) {
                struct fn_80050698_Entry *e = ent + *q0;

                m = lbl_80130A48[*q1];
                sx = e->unk_10 * m;
                sy = e->unk_14 * m;

                if (e->unk_8 == 3) {
                    sh = e->unk_4;
                    if (sh <= 8) {
                        t = fn_800501F4(arg0, sh * 3);
                        mask = lbl_80130B98[sh];
                        pw[64] = sx * (f32)(s32)(t & mask) + sy;
                        pw[32] = sx * (f32)(s32)((t >> sh) & mask) + sy;
                        pw[0] = sx * (f32)(s32)((t >> sh) >> sh) + sy;
                    } else {
                        pw[0] = sx * (f32)(s32)fn_800501F4(arg0, sh) + sy;
                        pw[32] = sx * (f32)(s32)fn_800501F4(arg0, sh) + sy;
                        pw[64] = sx * (f32)(s32)fn_800501F4(arg0, sh) + sy;
                    }
                } else {
                    val = e->unk_0;
                    idx = fn_800501F4(arg0, e->unk_4);
                    if (val == 3) {
                        pw[0] = sx * (f32)(s32)lbl_80130C00[0][idx] + sy;
                        pw[32] = sx * (f32)(s32)lbl_80130C00[1][idx] + sy;
                        pw[64] = sx * (f32)(s32)lbl_80130C00[2][idx] + sy;
                    } else if (val == 5) {
                        pw[0] = sx * (f32)(s32)lbl_80130C60[0][idx] + sy;
                        pw[32] = sx * (f32)(s32)lbl_80130C60[1][idx] + sy;
                        pw[64] = sx * (f32)(s32)lbl_80130C60[2][idx] + sy;
                    } else if (val == 9) {
                        pw[0] = sx * (f32)(s32)lbl_80130DE0[0][idx] + sy;
                        pw[32] = sx * (f32)(s32)lbl_80130DE0[1][idx] + sy;
                        pw[64] = sx * (f32)(s32)lbl_80130DE0[2][idx] + sy;
                    } else {
                        q = idx / val;
                        q2 = q / val;
                        pw[0] = sx * (f32)(s32)(idx - q * val) + sy;
                        pw[32] = sx * (f32)(s32)(q2 - (q2 / val) * val) + sy;
                        pw[64] = sx * (f32)(s32)(q - q2 * val) + sy;
                    }
                }
            } else {
                pw[0] = pw[32] = pw[64] = 0.0f;
            }

            if (n == 2 && i >= thresh) {
                p5[96] = p5[0];
                p5[128] = p5[32];
                p5[160] = p5[64];
            }

            q0 += 32;
            q1 += 96;
            pw += 96;
        }

        p2++;
        p3++;
        p5++;
        ent += 16;
    }

    pz = base + cnt;
    for (i = cnt; i < 32; i++) {
        for (j = 0; j < n; j++) {
            pz[0] = pz[32] = pz[64] = 0.0f;
            pz += 96;
        }
        pz++;
    }
}
