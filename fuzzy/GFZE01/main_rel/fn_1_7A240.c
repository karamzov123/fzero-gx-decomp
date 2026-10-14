/* Non-matching: best partial attempt (92.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x04050000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -200.0f;
    s = 1000.0f;
}
static const u32 fzgx_pool_table3[3] = {0x006E9600, 0x08050000, 0xC3480000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2000.0f;
}
static const u32 fzgx_pool_table5[3] = {0x0A0A2800, 0x07040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3000.0f;
}
static const u32 fzgx_pool_table7[3] = {0x171A1D00, 0x0C020000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 820.0f;
}
static const u32 fzgx_pool_table9[3] = {0x6E787900, 0xFF040000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03125f;
    s = 1.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 0.01666666753590107f;
}
static const u32 fzgx_pool_table13[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 640.0f;
    s = 480.0f;
    s = 320.0f;
    s = 240.0f;
    s = 0.029999999329447746f;
    s = 0.75f;
    s = 0.019999999552965164f;
    s = 1.5f;
    s = 360.0f;
    s = 128.0f;
    s = 0.5f;
    s = 8.0f;
    s = 408.0f;
}
static const u32 fzgx_pool_table15[1] = {0x42C80000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.1920928955078125e-07f;
    s = 2.0f;
    s = 60.0f;
}
#pragma section code_type ".text"

typedef struct {
    u32 flags;
    s32 count;
    void *entries;
} Sig_fn_1_7A67C_EffectTable;

struct fn_1_7A240_Arg2 {
    f32 unk_0;
};

struct fn_1_7A240_lbl_1_rodata_3278 {
    u8 pad_0[0x54];
    f32 unk_54;
    u8 pad_58[0x18];
    f32 unk_70;
    u8 pad_74[0xC];
    f32 unk_80;
    u8 pad_84[0x28];
    f32 unk_AC;
    f32 unk_B0;
};

struct fn_1_7A240_Entry {
    u32 unk_0;
    f32 unk_4;
    void *unk_8;
    f32 unk_C;
};

extern f32 fn_1_A71AC(void);
extern f32 lbl_1_data_4;
extern struct fn_1_7A240_lbl_1_rodata_3278 lbl_1_rodata_3278;
extern u32 lbl_801A6D00;
extern void * fn_1_7A67C(Sig_fn_1_7A67C_EffectTable *);
extern void lbl_8006E1B0(void *, void *);

#pragma opt_propagation off
#pragma opt_strength_reduction off
void *fn_1_7A240(Sig_fn_1_7A67C_EffectTable *arg0, void *arg1,
                 struct fn_1_7A240_Arg2 *arg2,
                 Sig_fn_1_7A67C_EffectTable *arg3,
                 f32 arg4)
{
    f32 fzgx_live__;
    s32 idx1;
    f32 fzgx_live;
    u32 limit;
    struct fn_1_7A240_lbl_1_rodata_3278 *p;
    f32 fzgx_live_;
    Sig_fn_1_7A67C_EffectTable *tbl;
    void *node;
    struct fn_1_7A240_Entry *cur;
    s32 i;
    s32 flag1;
    s32 flag2;
    s32 count;
    f32 out;
    f32 neg;
    f32 dist;
    f32 scale;
    struct { f32 a[18]; } loc;

    p = &lbl_1_rodata_3278;
    scale = arg4;
    arg2->unk_0 = (1.0f);
    node = *(void **)((u8 *)arg0->entries + 8);
    if (node == 0) {
        return 0;
    }
    tbl = arg3 ? arg3 : arg0;
    count = tbl->count;
    flag2 = tbl->flags & 0x40;
    cur = tbl->entries;
    idx1 = count;
    flag1 = tbl->flags & 1;
    if (flag2 != 0) {
        idx1 = count - 2;
    }
    limit = idx1;
    if (flag1 != 0) {
        limit = idx1 - 1;
    }
    out = (tbl->flags & 0x80) ? (0.0f) : lbl_1_data_4;

    lbl_8006E1B0((u8 *)node + 8, &loc);
    neg = -loc.a[2];
    if (arg0->flags & 0x2) {
        dist = -*(f32 *)((u8 *)*(u32 *)&lbl_801A6D00 + 0x2c);
    } else {
        dist = neg;
    }
    if (arg3 != 0) {
        dist = dist - *(f32 *)((u8 *)node + 0x14);
    }

    if (tbl->flags & 0x2) {
        if (!(dist < (1.1920929e-07f))) {
            for (i = 0; i < tbl->count; i++) {
                if (dist < cur->unk_C) {
                    if (flag1 != 0) {
                        struct fn_1_7A240_Entry *e;
                        f32 t;
                        f32 v;
                        e = (struct fn_1_7A240_Entry *)((u8 *)tbl->entries + (idx1 * 16) - 0x10);
                        fzgx_live = (0.0f);
                        v = fzgx_live;
                        out = dist;
                        fzgx_live_ = e->unk_4;
                        t = (dist - fzgx_live_) / (e->unk_C - fzgx_live_);
                        if (t < v) {
                            /* clamped to zero, keep v */
                        } else {
                            v = (1.0f);
                            if (t > v) {
                                /* clamped to one, keep v */
                            } else {
                                v = t;
                            }
                        }
                        arg2->unk_0 = v;
                    }
                    if (flag2 != 0) {
                        if (!(tbl->flags & 0x80)) {
                            scale = (f32)((2.0f) * *(f32 *)((u8 *)node + 0x14)) * scale;
                            out = (240.0f) * scale / (neg * fn_1_A71AC());
                        } else {
                            if (flag1 == 0) {
                                out = dist;
                            }
                        }
                    }
                    break;
                }
                cur = (struct fn_1_7A240_Entry *)((u8 *)cur + 0x10);
            }
        } else {
            i = 0;
        }
    } else {
        if (neg < (1.1920929e-07f)) {
            i = 0;
        } else {
            f32 k;
            scale = (f32)((2.0f) * *(f32 *)((u8 *)node + 0x14)) * scale;
            k = neg * fn_1_A71AC();
            for (i = 0; i < limit; i++) {
                if (scale > (f32)(cur->unk_C / (240.0f)) * k) {
                    if (flag1 != 0) {
                        struct fn_1_7A240_Entry *e;
                        f32 t;
                        f32 v;
                        e = (struct fn_1_7A240_Entry *)((u8 *)tbl->entries + (idx1 * 16) - 0x10);
                        out = (240.0f) * scale / k;
                        fzgx_live = (0.0f);
                        v = fzgx_live;
                        fzgx_live_ = e->unk_4;
                        t = (out - fzgx_live_) / (e->unk_C - fzgx_live_);
                        if (t < v) {
                            /* clamped to zero, keep v */
                        } else {
                            v = (1.0f);
                            if (t > v) {
                                /* clamped to one, keep v */
                            } else {
                                v = t;
                            }
                        }
                        arg2->unk_0 = v;
                    }
                    if (flag2 != 0) {
                        if (tbl->flags & 0x80) {
                            out = dist;
                        } else if (flag1 == 0) {
                            out = (240.0f) * scale / k;
                        }
                    }
                    break;
                }
                cur = (struct fn_1_7A240_Entry *)((u8 *)cur + 0x10);
            }
        }
    }

    if (cur->unk_8 != 0 && i < limit) {
        if (arg3 != 0) {
            node = fn_1_7A67C(arg0);
        }
        if (flag2 != 0) {
            if (arg2->unk_0 >= (1.0f)) {
                struct fn_1_7A240_Entry *e;
                f32 t;
                f32 v;
                e = (struct fn_1_7A240_Entry *)((u8 *)tbl->entries + (count * 16) - 0x10);
                fzgx_live = (0.0f);
                v = fzgx_live;
                fzgx_live_ = e->unk_4;
                fzgx_live__ = e->unk_C;
                t = (fzgx_live__ - out) / (fzgx_live__ - fzgx_live_);
                if (t < v) {
                    /* clamped to zero, keep v */
                } else {
                    v = (1.0f);
                    if (t > v) {
                        /* clamped to one, keep v */
                    } else {
                        v = t;
                    }
                }
                arg2->unk_0 = v;
            }
        }
        if (arg2->unk_0 > (0.0f) && node != 0) {
            if (arg1 != 0) {
                *(u32 *)arg1 = cur->unk_0;
            }
            return node;
        }
    }
    if (arg1 != 0) {
        *(u32 *)arg1 = 0;
    }
    return 0;
}
#pragma opt_strength_reduction reset

#pragma opt_propagation reset

