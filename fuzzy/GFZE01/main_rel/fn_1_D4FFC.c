/* Non-matching: best partial attempt (90.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Sig_fn_1_862A8_fn_1_862A8_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};
struct Fn_1_D4FFC_Pool {
    u8 pad_0[0x148];
    u32 v_148;
    u32 v_14c;
    u32 v_150;
    f32 f_154;
    f32 f_158;
    u8 pad_15c[4];
    f64 d_160;
};
struct D4FFC_Slot {
    u8 pad_0[0x2630];
    s16 val[4];
};
extern struct Fn_1_D4FFC_Pool lbl_1_rodata_6168;
extern s16 camera_get_mode(void);
extern s32 fn_1_6EC0(u8);
extern u32 fn_1_864E8(s32);
extern u32 fn_1_862A8(u32, struct Sig_fn_1_862A8_fn_1_862A8_Arg1 *);
extern f32 lbl_8006D6FC(void *, void *);
extern u32 lbl_801A63C0;
extern u32 lbl_801A66A0;

#pragma opt_common_subs off
static inline f32 D4FFC_float(s32 v, f64 bias) {
    return (f32)v;
}

#pragma opt_loop_invariants off
void fn_1_D4FFC(u32 arg0, u32 arg1, f32 arg2) {
    struct { s16 value; } mode;
    struct Sig_fn_1_862A8_fn_1_862A8_Arg1 tmp;
    struct {
    u8 lab_pad[8]; struct Fn_1_D4FFC_Pool *value; } pool;
    u32 v_8[3];
    u8 *base;

    pool.value = &lbl_1_rodata_6168;
    base = (u8 *)arg0 + 0xc140;
    v_8[0] = pool.value->v_148;
    v_8[1] = pool.value->v_14c;
    v_8[2] = pool.value->v_150;
    mode.value = camera_get_mode();
    if (mode.value != -1 && fn_1_6EC0((u8)arg1) != 0 && (fn_1_864E8(mode.value) & 0x20) != 0) {
        ((struct D4FFC_Slot *)base)->val[arg1] = -1;
    } else if (mode.value != -1) {
        u32 off;
        s32 i;
        s32 n;
        f32 val;
        f32 scale;
        f32 div;

        fn_1_862A8(camera_get_mode(), &tmp);
        val = lbl_8006D6FC(&tmp, v_8);
        off = (arg1 << 1) + 0x2630;
        ((struct D4FFC_Slot *)base)->val[arg1] = 2;
        scale = pool.value->f_154;
        n = 0;
        for (i = 0; i < 2; i++) {
            s32 j;
            for (j = 0; j < 2; j++) {
                if (val > scale * D4FFC_float(*(s16 *)(base + 0x2628 + i * 4 + j * 2), pool.value->d_160) / D4FFC_float(*(s16 *)(base + 0x262e), pool.value->d_160)) {
                    *(s16 *)(base + off) = n;
                }
                n++;
            }
        }
        if ((lbl_801A66A0 & 7) == 0) {
            div = pool.value->f_158;
            lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
            *(f32 *)(base + 0x2620) = D4FFC_float((lbl_801A63C0 >> 16) & 0x7fff, pool.value->d_160) / div;
            lbl_801A63C0 = lbl_801A63C0 * 0x676a4b6b + 0x33cb;
            *(f32 *)(base + 0x2624) = D4FFC_float((lbl_801A63C0 >> 16) & 0x7fff, pool.value->d_160) / div;
        }
    } else {
        ((struct D4FFC_Slot *)base)->val[arg1] = -1;
    }
}
#pragma opt_loop_invariants reset

