#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"

extern u32 lbl_1_bss_6EA78;
extern u32 lbl_1_bss_6EA7C;
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, void *, s32);
extern const f32 lbl_1_rodata_41FC;
extern u8 fn_1_86624(void);
extern void *fn_1_14F04(void);
extern f32 lbl_1_rodata_4244[7];
extern void fn_1_17920(s32, s32, f32);
extern void fn_1_85C58(s32, f32);
extern void lbl_8006DB74(void *);
extern void fn_1_9DDA8(u32, u32, u32);
extern void fn_1_9DFB8(u32, u32, u32, u32);
extern void GXPeekZ(u32, u32, void *);
extern void fn_80034200(u32);
extern void fn_8003432C(u32, u32, u32 *);

/* fzgx:begin fn_1_9CF78 */
extern s32 fn_8006FC1C(const char *, const char *);
extern s32 fn_8006FC5C(const char *, const char *, s32);
extern s32 strlen(const char *);

typedef u32 (*FilterCallback)(u32, void *);

typedef struct {
    s32 type;
    const char *str;
} TblEntry;

typedef struct {
    s32 count;
    u32 unk4;
    TblEntry *entries;
} TblGroup;

void fn_1_9CF78(void *arg0, FilterCallback arg1) {
    s32 n;
    u32 idx;
    TblEntry *e;
    TblGroup ***p;
    s32 slen;
    TblEntry *q;
    const char *s;
    s32 ok;
    TblGroup *g;
    s32 res;

    p = (TblGroup ***)&lbl_1_data_2CC30;
    ok = 1;
    while (*p != 0) {
        g = **p;
        if (g == 0) {
            p++;
            continue;
        }
        e = g->entries;
        n = g->count;
        for (; n > 0; n--, e++) {
            s = e->str;
            slen = strlen(s);
            q = (TblEntry *)arg0;
            for (idx = 0; q->str != 0; idx++, q++) {
                switch (q->type) {
                case 0:
                    res = fn_8006FC5C(s, q->str, strlen(q->str));
                    break;
                case 1:
                    res = fn_8006FC1C(s, q->str);
                    break;
                case 2: {
                    s32 len = strlen(q->str);
                    if (len > slen) {
                        res = 0;
                    } else {
                        res = fn_8006FC5C(s + (slen - len), q->str, len);
                    }
                    break;
                }
                default:
                    res = 0;
                    break;
                }
                if (res != 0) {
                    ok = arg1(idx, e);
                }
                if (ok == 0) {
                    break;
                }
            }
            if (ok == 0) {
                break;
            }
        }
        if (ok == 0) {
            break;
        }
        p++;
    }
}
/* fzgx:end fn_1_9CF78 */

/* fzgx:begin fn_1_9D77C */
typedef struct {
    u32 flags;
    u8 _pad[0x34];
    void *link;
    u8 _tail[4];
} Fn1_9D77C_Item;

typedef struct {
    u8 _pad[4];
    u32 value;
} Fn1_9D77C_Link;

void fn_1_9D77C(Fn1_9D77C_Item *items, s32 count) {
    s32 i;
    u32 *first;
    u32 *second;

    first = (u32 *)lbl_1_bss_6EA78;
    second = (u32 *)lbl_1_bss_6EA7C;

    for (i = 0; i < 5; i++) {
        if (lbl_1_bss_6EA78 != 0 && first != 0 && *first != 0) {
            fn_1_46B4(lbl_801A6410, *first, lbl_1_data_2CB60, 0x922);
            *first = 0;
        }
        if (lbl_1_bss_6EA7C != 0 && second != 0 && *second != 0) {
            fn_1_46B4(lbl_801A6410, *second, lbl_1_data_2CB60, 0x923);
            *second = 0;
        }
        first++;
        second++;
    }

    i = 0;
    while (i < count) {
        if ((items->flags & 0x1000) != 0 &&
            items->link != 0 &&
            ((Fn1_9D77C_Link *)items->link)->value != 0) {
            fn_1_46B4(lbl_801A6410,
                       ((Fn1_9D77C_Link *)items->link)->value,
                       lbl_1_data_2CB60, 0x92b);
            ((Fn1_9D77C_Link *)items->link)->value = 0;
        }
        i++;
        items++;
    }

    if (lbl_1_bss_6EA78 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_6EA78, lbl_1_data_2CB60, 0x92e);
        lbl_1_bss_6EA78 = 0;
    }
    if (lbl_1_bss_6EA7C != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_6EA7C, lbl_1_data_2CB60, 0x92f);
        lbl_1_bss_6EA7C = 0;
    }
}
/* fzgx:end fn_1_9D77C */

/* fzgx:begin fn_1_9D93C */
s32 fn_1_9D93C(s32 arg0, u32 *arg1) {
    if (arg0 == 0) {
        lbl_1_data_2A7E0.unk_80 = *arg1;
    } else {
        lbl_1_data_2A7E0.unk_7C = *arg1;
    }
    {
        s32 result;
        result = 0;
        if (lbl_1_data_2A7E0.unk_80 == 0 ||
            lbl_1_data_2A7E0.unk_7C == 0) {
            result = 1;
        }
        return result;
    }
}
/* fzgx:end fn_1_9D93C */

/* fzgx:begin fn_1_9D994 */
extern u32 lbl_1_bss_6EA78;
extern u32 lbl_1_bss_6EA7C;
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, void *, s32);
extern const f32 lbl_1_rodata_41FC;
extern u8 fn_1_86624(void);
extern void *fn_1_14F04(void);
extern f32 lbl_1_rodata_4244[7];
extern void fn_1_17920(s32, s32, f32);
extern void fn_1_85C58(s32, f32);
extern void lbl_8006DB74(void *);
extern void fn_1_9DDA8(u32, u32, u32);
extern void fn_1_9DFB8(u32, u32, u32, u32);
extern void GXPeekZ(u32, u32, void *);
extern void fn_80034200(u32);
extern void fn_8003432C(u32, u32, u32 *);

extern s32 fn_1_9D93C(s32, u32 *);
typedef u32 (*Sig_fn_1_9CF78_FilterCallback)(u32, void *);
extern void fn_1_9CF78(void *, Sig_fn_1_9CF78_FilterCallback);

/* Retail TU .data objects in retail order: MWCC addresses them off one section base
   (lbl_1_data_2A0C0), so the unit defines them; its copy is dropped at integration. */
u32 fzgx_obj_lbl_1_data_2A0C0[4] = {1};
u8 fzgx_pool_fzgx_gap_2A0D0[0x2A7E0 - 0x2A0D0] = {1};
Obj_1_data_2A7E0 fzgx_obj_lbl_1_data_2A7E0 = {0};
u8 fzgx_pool_fzgx_gap_2A8D8[0x2CC70 - 0x2A8D8] = {1};
u8 fzgx_obj_lbl_1_data_2CC70[0x8] = {1};
u8 fzgx_pool_fzgx_obj_lbl_1_data_2CC78[0x18] = {1};
u8 fzgx_pool_fzgx_gap_2CC90[0xC] = {1};
u8 fzgx_obj_lbl_1_data_2CC9C[0x8] = {1};
u8 fzgx_pool_fzgx_obj_lbl_1_data_2CCA4[0x18] = {1};

void fn_1_9D994(s32 arg0) {
    void *table;

    fzgx_obj_lbl_1_data_2A7E0.unk_80 = 0;
    fzgx_obj_lbl_1_data_2A7E0.unk_7C = 0;
    table = fzgx_pool_fzgx_obj_lbl_1_data_2CC78;
    if (arg0 == 0x2b) {
        table = fzgx_pool_fzgx_obj_lbl_1_data_2CCA4;
    }
    fn_1_9CF78(table, (Sig_fn_1_9CF78_FilterCallback)fn_1_9D93C);
}
/* fzgx:end fn_1_9D994 */

/* fzgx:begin fn_1_9D9E4 */
typedef struct {
    u8 pad[0x468];
    f32 value;
} Fn14F04Result;

void fn_1_9D9E4(void) {
    f32 value;
    s32 offset;
    s32 i;
    s32 count;
    Fn14F04Result *result;

    value = lbl_1_rodata_41FC;
    lbl_1_data_2A7E0.unk_74 = 1;
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        lbl_1_data_2A7E0.unk_70 = fn_1_86624();
    } else {
        lbl_1_data_2A7E0.unk_70 = 0x1e;
    }

    if (lbl_1_bss_3BE0 != 0) {
        result = (Fn14F04Result *)fn_1_14F04();
        count = lbl_1_bss_3BE0->unk_8;
        if (count > 0) {
            count--;
        } else {
            count = 0;
        }
        fn_1_17920(count, 0, lbl_1_rodata_4244[0]);
        value = result->value;
    }

    i = 0;
    offset = 0;
    while (i < (s8)lbl_1_data_2A7E0.unk_70) {
        fn_1_85C58(i, value);
        lbl_8006DB74((u8 *)lbl_1_data_2A7E0.unk_78 + offset);
        offset += 0x30;
        i++;
    }
}
/* fzgx:end fn_1_9D9E4 */

/* fzgx:begin fn_1_9DB04 */
#include "psvec.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 6885000.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[2] = {0x000000FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    d = 1.0;
    s = 182.04444885253906f;
}
static const u32 fzgx_pool_table9[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static inline void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.4000000059604645f;
    s = 0.01666666753590107f;
    s = -90000.0f;
    s = 100.0f;
    s = -401.0f;
    s = -0.10000000149011612f;
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table11[7] = {0x00FF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 60.0;
    d = 3.0;
    s = 400.0f;
    s = 0.05000000074505806f;
    s = 2.75f;
}
static const u32 fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u8 unk_00[8];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    f32 unk_14;
} Sig_fn_1_555D0_Object;

const u8 fzgx_pool_lbl_1_rodata_41F0[12] = {0};
const f32 fzgx_pool_lbl_1_rodata_41FC = 0.0f;
const u8 fzgx_pool_lbl_1_rodata_4200[4] = {0x4A,0xD2,0x1D,0x10};
const u8 fzgx_pool_lbl_1_rodata_4208[8] = {0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00};
const u8 fzgx_pool_lbl_1_rodata_4210[40] = {0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00,0x42,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00};
const f32 fzgx_pool_lbl_1_rodata_4210__fzgx_offset_28 = 182.044449f;
const u8 fzgx_pool_lbl_1_rodata_4210__fzgx_offset_2C[8] = {0};
const f32 fzgx_pool_lbl_1_rodata_4244 = 1.0f;
const u8 fzgx_pool_lbl_1_rodata_4244__fzgx_offset_4[12] = {0x3E,0xCC,0xCC,0xCD,0x3C,0x88,0x88,0x89,0xC7,0xAF,0xC8,0x00};
const f32 fzgx_pool_lbl_1_rodata_4244__fzgx_offset_10 = 100.0f;
const u8 fzgx_pool_lbl_1_rodata_4244__fzgx_offset_14[8] = {0xC3,0xC8,0x80,0x00,0xBD,0xCC,0xCC,0xCD};
const u8 fzgx_pool_lbl_1_rodata_4260[32] = {0x3C,0x23,0xD7,0x0A,0x00,0xFF,0x00,0xFF};
const f64 fzgx_pool_lbl_1_rodata_4260__fzgx_offset_20 = 60.0;
const f64 fzgx_pool_lbl_1_rodata_4260__fzgx_offset_28 = 3.0;
const f32 fzgx_pool_lbl_1_rodata_4260__fzgx_offset_30 = 400.0f;
const f32 fzgx_pool_lbl_1_rodata_4260__fzgx_offset_34 = 0.0500000007f;
const f32 fzgx_pool_lbl_1_rodata_4260__fzgx_offset_38 = 2.75f;
const u8 fzgx_pool_lbl_1_rodata_4260__fzgx_offset_3C[4] = {0};
extern f32 fn_1_9E14C(s32, void *, f32);
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_3FC48(void);
extern void fn_1_A2D84(u32);
extern void fn_1_55FF0(f32);
extern void fn_1_566EC(s32, s32);
extern void fn_1_555D0(Sig_fn_1_555D0_Object *);
extern void lbl_8006DFE8(u32);
extern void lbl_8006E0B4(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern u32 mathutil_mtxA_rotate_x(u32);

void fn_1_9DB04(void) {
    f32 v[3];
    f32 arr[30];
    s32 angle;
    s32 i;
    struct { s32 value; } j;
    f32 zero;
    f32 x;

    if ((s32)lbl_1_data_2A7E0.unk_74 != 0) {
        x = (f32)((f64)lbl_1_data_2A7E0.unk_1C / fzgx_pool_lbl_1_rodata_4260__fzgx_offset_20);
        if (x > lbl_1_data_2CCBC.unk_54) {
            lbl_1_data_2A7E0.unk_74 = 0;
        }
        angle = (s32)(fn_1_9E14C(5, (void *)&lbl_1_data_2CCBC, x) * fzgx_pool_lbl_1_rodata_4210__fzgx_offset_28);
        if (fzgx_pool_lbl_1_rodata_4260__fzgx_offset_28 == x && (s16)fn_1_3F0C8() == 0x28 && fn_1_3FC48() == 0) {
            fn_1_A2D84(0xa9091700);
        }
    } else {
        angle = 0;
    }

    for (i = 0; i < (s8)lbl_1_data_2A7E0.unk_70; i++) {
        f32 cmp;
        lbl_8006DFE8(lbl_1_data_2A7E0.unk_78 + i * 0x30);
        if (lbl_1_data_2A7E0.unk_7C != 0) {
            lbl_8006E1B0((void *)(lbl_1_data_2A7E0.unk_7C + 8), v);
            cmp = *(f32 *)(lbl_1_data_2A7E0.unk_7C + 0x14);
        } else {
            cmp = fzgx_pool_lbl_1_rodata_41FC;
            psvec_set(v, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C),
                *(f32 *)(0xE0000000 + 0x0C));
        }
        if (v[2] > cmp) {
            arr[i] = fzgx_pool_lbl_1_rodata_41FC;
        } else {
            arr[i] = (fzgx_pool_lbl_1_rodata_4260__fzgx_offset_30 + ((2)[v])) / fzgx_pool_lbl_1_rodata_4244__fzgx_offset_10;
            if (arr[i] <= fzgx_pool_lbl_1_rodata_41FC) {
                continue;
            }
            if (arr[i] > fzgx_pool_lbl_1_rodata_4244) {
                arr[i] = fzgx_pool_lbl_1_rodata_4244;
            }
            if (lbl_1_data_2A7E0.unk_7C != 0) {
                fn_1_55FF0(arr[i]);
                fn_1_566EC(1, 0x80);
                fn_1_555D0((Sig_fn_1_555D0_Object *)lbl_1_data_2A7E0.unk_7C);
                fn_1_566EC(0, 0);
            }
        }
    }

    zero = fzgx_pool_lbl_1_rodata_41FC;
    if (lbl_1_data_2A7E0.unk_80 != 0 && (s32)lbl_1_data_2A7E0.unk_74 != 0) {
        for (j.value = 0; j.value < (s8)lbl_1_data_2A7E0.unk_70; j.value++) {
            if (arr[j.value] <= zero) {
                continue;
            }
            lbl_8006DFE8(lbl_1_data_2A7E0.unk_78 + ((0x30) * (j.value)));
            lbl_8006E0B4(fzgx_pool_lbl_1_rodata_41FC, fzgx_pool_lbl_1_rodata_4260__fzgx_offset_34, fzgx_pool_lbl_1_rodata_4260__fzgx_offset_38);
            mathutil_mtxA_rotate_x(angle);
            fn_1_55FF0(arr[j.value]);
            fn_1_555D0((Sig_fn_1_555D0_Object *)lbl_1_data_2A7E0.unk_80);
        }
    }
}
/* fzgx:end fn_1_9DB04 */

/* fzgx:begin fn_1_9DDA8 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "dolphin/hw_regs.h"
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"
#include "dolphin/hw_regs.h"

/* begin game/main_rel/background_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BACKGROUND_TYPES_H
#define GAME_MAIN_REL_BACKGROUND_TYPES_H

// Types (and the externs that name them) of background.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    s32 type;     /* 0: constant, 1: linear, else: hermite */
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} CurveKey;


#endif  // GAME_MAIN_REL_BACKGROUND_TYPES_H

/* end game/main_rel/background_types.h */

typedef struct {
    s32 type;     /* 0: constant, 1: linear, else: hermite */
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} fn_1_9DDA8_CurveKey;

/* Evaluate a keyframe curve at time t; derivative != 0 returns the slope. */
f32 fn_1_9DDA8(s32 count, fn_1_9DDA8_CurveKey *keys, s32 derivative, f32 t) {
    fn_1_9DDA8_CurveKey *p;
    s32 i;
    f32 a, dt, d, m0, m1, u, s, u2, u3, w, b, e;
    f64 lin;

    if (count < 2 || t <= keys[0].time) {
        if (derivative) {
            return keys[0].tanOut;
        }
        return keys[0].value;
    }
    if (t >= keys[count - 1].time) {
        if (derivative) {
            return keys[count - 1].tanIn;
        }
        return keys[count - 1].value;
    }

    count--;
    keys++;
    for (i = 1; i < count; i++) {
        if (keys->time > t) {
            break;
        }
        keys++;
    }
    p = keys - 1;

    if (derivative) {
        switch (p->type) {
        case 0:
            return 0.0f;
        case 1:
            return keys->value - p->value;
        default:
            a = t - p->time;
            dt = keys->time - p->time;
            d = p->value - keys->value;
            m0 = (f32)(dt * p->tanOut);
            u = a / dt;
            s = m0 + (f32)(dt * keys->tanIn);
            return m0 + ((f32)((f32)(u * u) * (((f32)(2.0f * d) + s) / 3.0f))
                         - (f32)(u * ((m0 + ((f32)(3.0f * d) + s)) / 2.0f)));
        }
    } else {
        switch (p->type) {
        case 0:
            return p->value;
        case 1:
            dt = keys->time - p->time;
            a = t - p->time;
            u = a / dt;
            lin = p->value * (1.0 - u);
            return lin + (f32)(keys->value * u);
        default:
            a = t - p->time;
            dt = keys->time - p->time;
            u = a / dt;
            u2 = (f32)(u * u);
            u3 = (f32)(u2 * u);
            w = u3 - u2;
            e = (f32)(2.0f * w) - u2;
            b = u + (w - u2);
            return ((f32)((1.0f + e) * p->value) - (f32)(e * keys->value))
                   + (f32)(dt * ((f32)(p->tanOut * b) + (f32)(w * keys->tanIn)));
        }
    }
}
/* fzgx:end fn_1_9DDA8 */

/* fzgx:begin fn_1_9E14C */
void fn_1_9E14C(u32 arg0, u32 arg1) {
    fn_1_9DDA8(arg0, arg1, 0);
}
/* fzgx:end fn_1_9E14C */

/* fzgx:begin fn_1_9E170 */
void fn_1_9E170(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    fn_1_9DFB8(arg0, arg1, arg2, 0);
}
/* fzgx:end fn_1_9E170 */

/* fzgx:begin fn_1_9E194 */
void fn_1_9E194(u32 arg0, u32 arg1) {
    fn_1_9DDA8(arg0, arg1, 1);
}
/* fzgx:end fn_1_9E194 */

/* fzgx:begin fn_1_9E1B8 */
void fn_1_9E1B8(void) {
    lbl_1_bss_6EA80 = 0;
    lbl_1_bss_6EA84 = (u32)&lbl_1_bss_6EA80;
}
/* fzgx:end fn_1_9E1B8 */

/* fzgx:begin fn_1_9E1D0 */
typedef struct {
    s16 unk_0;
    s16 unk_2;
    u32 unk_4;
    u8 unk_8;
} Fn_1_9E1D0_Entry;

typedef struct Fn_1_9E1D0_Node {
    struct Fn_1_9E1D0_Node *unk_0;
    s32 unk_4;
    Fn_1_9E1D0_Entry *unk_8;
} Fn_1_9E1D0_Node;

void fn_1_9E1D0(void) {
    s32 count;
    Fn_1_9E1D0_Node *node;
    Fn_1_9E1D0_Entry *entry;
    u32 result;

    node = (Fn_1_9E1D0_Node *)lbl_1_bss_6EA80;
    while (node != 0) {
        entry = node->unk_8;
        count = node->unk_4;
        while (count > 0) {
            if (entry->unk_4 == 0) {
                GXPeekZ((u16)entry->unk_0, (u16)entry->unk_2, &entry->unk_4);
                fn_80034200(2);
                fn_8003432C((u16)entry->unk_0, (u16)entry->unk_2, &result);
                entry->unk_8 = (u8)(result >> 24);
            }
            count--;
            entry++;
        }
        node = node->unk_0;
    }
    lbl_1_bss_6EA80 = 0;
    lbl_1_bss_6EA84 = (u32)&lbl_1_bss_6EA80;
}
/* fzgx:end fn_1_9E1D0 */

/* fzgx:begin fn_1_9E514 */
extern f32 lbl_1_rodata_42C0[4];
extern void fn_80038BFC(f32 *);
extern u32 __cvt_fp2unsigned(f32);

typedef struct {
    u8 unk_00[0x14];
    f32 unk_14;
    f32 unk_18;
} Fn_1_9E514_Data;

s32 fn_1_9E514(f32 arg0) {
    Fn_1_9E514_Data data;
    f32 *table = (f32 *)&lbl_1_rodata_42C0;
    f32 prod;
    f32 value;

    fn_80038BFC((f32 *)&data);
    prod = data.unk_14 * arg0;
    value = data.unk_18 + prod;
    value /= arg0;
    value = (table[1] - value) * table[3];
    if (value < table[2]) {
        return 0;
    }
    return __cvt_fp2unsigned(value);
}
/* fzgx:end fn_1_9E514 */

/* fzgx:begin fn_1_9E598 */
typedef struct Node Node;
struct Node {
    Node *next;
};

// Append a node to the linked-list tail and terminate the new tail.
void fn_1_9E598(Node *node) {
    Node *tail;

    tail = *(Node **)&lbl_1_bss_6EA84;
    tail->next = node;
    node->next = 0;
    lbl_1_bss_6EA84 = (u32)node;
}
/* fzgx:end fn_1_9E598 */

/* fzgx:begin fn_1_9E5B8 */
// Removes a node from the background-node chain and updates its tail link.
void fn_1_9E5B8(Obj_1_bss_6EA80_Target *node) {
    u32 *link;

    link = (u32 *)&lbl_1_bss_6EA80;
    while (*link != 0 && *link != (u32)node) {
        link = (u32 *)*link;
    }
    if (*link == 0) {
        return;
    }
    *link = node->unk_0;
    if (lbl_1_bss_6EA84 == (u32)node) {
        lbl_1_bss_6EA84 = (u32)link;
    }
}
/* fzgx:end fn_1_9E5B8 */

/* fzgx:begin fn_1_9E608 noprologue */
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"
#include "dolphin/hw_regs.h"
#include "types.h"
#include "dolphin/types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"
#include "dolphin/hw_regs.h"

/* begin game/main_rel/background_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BACKGROUND_TYPES_H
#define GAME_MAIN_REL_BACKGROUND_TYPES_H

// Types (and the externs that name them) of background.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    s32 type;     /* 0: constant, 1: linear, else: hermite */
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} CurveKey;


#endif  // GAME_MAIN_REL_BACKGROUND_TYPES_H

/* end game/main_rel/background_types.h */

typedef struct {
    u8 r, g, b, a;
} BgColor;

typedef struct {
    u8 unk_0[0xC];
    f32 size;
    s16 rotZ;
    u16 flags;
    BgColor color;
} BgSprite;

extern u32 lbl_801A6D00;
extern s32 fn_1_54E34(void *arg0, f32 arg1);
extern void fn_800724C8(void);
extern void fn_8007245C(u32 value);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void lbl_8006DB30(void);
/* The color is passed by value: MWCC copies it to the stack and passes the copy's address. */
extern void fn_800736C0(u32, BgColor);
extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern void lbl_8006E1D8(f32 *, f32, f32, f32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E0A4(void *);
extern u32 lbl_8006D7B0(void);

/* GX write-gather FIFO: every store is a hardware write, so it must not be merged or dropped. */
#define BG_FIFO (*(volatile f32 *)GX_FIFO_BASE)

void fn_1_9E608(s32 count, BgSprite *list) {
    BgSprite *sprites;
    s32 remaining;
    f32 v[4][3];
    BgColor col;
    s32 i;
    BgSprite *start;
    BgSprite *last;
    BgSprite *s;
    s32 visible;
    s32 n;
    f32 neg;
    f32 size;

    s = list;
    visible = 0;
    for (i = count; i > 0; i--, s++) {
        if (fn_1_54E34(s, s->size) != 0) {
            visible++;
            s->flags &= ~1;
        } else {
            s->flags |= 1;
        }
    }
    if (visible == 0) {
        return;
    }

    fn_800724C8();
    fn_8007245C(0x2200);
    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();

    sprites = list;
    remaining = count;
    while (remaining > 0) {
        while (remaining > 0) {
            if (!(sprites->flags & 1)) {
                break;
            }
            remaining--;
            sprites++;
        }
        if (remaining == 0) {
            return;
        }
        col = sprites->color;
        fn_800736C0(0, col);
        fn_8003462C(0x90, 0, 8);
        start = sprites;
        remaining--;
        sprites++;
        for (i = 0; i < 8; i++) {
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
            BG_FIFO = 0.0f;
        }
        n = 1;
        while (remaining > 0) {
            if (!(sprites->flags & 1)) {
                if (col.r != sprites->color.r || col.g != sprites->color.g ||
                    col.b != sprites->color.b || col.a != sprites->color.a) {
                    remaining++;
                    last = sprites - 1;
                    break;
                }
                n++;
            }
            remaining--;
            sprites++;
        }
        fn_8003462C(0x80, 0, (u16)(n * 4));
        sprites = start;
        while (n > 0) {
            if (!(sprites->flags & 1)) {
                size = sprites->size;
                neg = -size;
                lbl_8006DAEC();
                lbl_8006E0A4(sprites);
                lbl_8006D7B0();
                if (sprites->rotZ != 0) {
                    mathutil_mtxA_rotate_z(sprites->rotZ);
                }
                lbl_8006E1D8(v[0], neg, neg, 0.0f);
                lbl_8006E1D8(v[1], size, neg, 0.0f);
                lbl_8006E1D8(v[2], size, size, 0.0f);
                lbl_8006E1D8(v[3], neg, size, 0.0f);
                lbl_8006DB30();
                n--;
                BG_FIFO = v[0][0];
                BG_FIFO = v[0][1];
                BG_FIFO = v[0][2];
                BG_FIFO = 0.0f;
                BG_FIFO = 0.0f;
                BG_FIFO = v[1][0];
                BG_FIFO = v[1][1];
                BG_FIFO = v[1][2];
                BG_FIFO = 1.0f;
                BG_FIFO = 0.0f;
                BG_FIFO = v[2][0];
                BG_FIFO = v[2][1];
                BG_FIFO = v[2][2];
                BG_FIFO = 1.0f;
                BG_FIFO = 1.0f;
                BG_FIFO = v[3][0];
                BG_FIFO = v[3][1];
                BG_FIFO = v[3][2];
                BG_FIFO = 0.0f;
                BG_FIFO = 1.0f;
            }
            sprites++;
        }
        remaining--;
        sprites = last + 1;
    }
}
/* fzgx:end fn_1_9E608 */

/* fzgx:begin fn_1_9EA94 */
typedef struct {
    u8 pad_0[0xC];
    f32 unk_C;
    s16 unk_10;
    u16 unk_12;
    u32 unk_14;
} Obj_1_9EA94_Target;

extern f32 lbl_1_rodata_42D0;
extern f32 lbl_1_rodata_42D4;
extern s32 fn_1_54E34(Obj_1_9EA94_Target *, f32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern u32 lbl_801A6D00;
extern void lbl_8006DB30(void);
extern void fn_800736C0(u32, void *);
extern void fn_8003462C(u32, u32, u32);
extern void lbl_8006E0A4(Obj_1_9EA94_Target *);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void lbl_8006E1D8(void *, f32, f32, f32);

#pragma opt_propagation off
void fn_1_9EA94(Obj_1_9EA94_Target *arg0) {
    u32 v0;
    f32 v3;
    f32 v2;
    void * lab_t0_2;
    f32 loc_30[3];
    f32 loc_24[3];
    f32 loc_18[3];
    f32 loc_C[3];
    u32 loc_8;
    void * lab_t0;

    if (fn_1_54E34(arg0, arg0->unk_C) == 0) {
        arg0->unk_12 |= 1;
        return;
    }
    arg0->unk_12 &= 0xFFFE;
    fn_800724C8();
    fn_8007245C(0x2200);
    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(*(u32 *)&lbl_801A6D00, 0);
    lbl_8006DB30();
    loc_8 = arg0->unk_14;
    fn_800736C0(0, &loc_8);
    fn_8003462C(0x90, 0, 8);
    v0 = 0x80;
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    fn_8003462C(v0, 0, 4);
    v2 = arg0->unk_C;
    v3 = -v2;
    lbl_8006DAEC();
    lbl_8006E0A4(arg0);
    if (arg0->unk_10 != 0) {
        mathutil_mtxA_rotate_z(arg0->unk_10);
    }
    lbl_8006E1D8((lab_t0 = loc_C), v3, v3, lbl_1_rodata_42D0);
    lab_t0 = loc_18;
    lbl_8006E1D8(lab_t0, v2, v3, lbl_1_rodata_42D0);
    lab_t0_2 = loc_24;
    lbl_8006E1D8(lab_t0_2, v2, v2, lbl_1_rodata_42D0);
    lab_t0_2 = loc_30;
    lbl_8006E1D8(lab_t0_2, v3, v2, lbl_1_rodata_42D0);
    lbl_8006DB30();
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_C[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_C[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_C[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_18[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_18[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_18[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_24[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_24[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_24[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_30[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_30[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = loc_30[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(volatile f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D4;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}
#pragma opt_propagation reset
/* fzgx:end fn_1_9EA94 */

/* fzgx:begin fn_1_9EDE8 */
#include "dolphin/hw_regs.h"
#include "types.h"
#include "dolphin/types.h"

extern volatile const f32 lbl_1_rodata_42D0; /* Reload before each ordered FIFO write. */
extern volatile const f32 lbl_1_rodata_42D4; /* Reload before each ordered FIFO write. */
extern u32 lbl_801A6D00;
extern s32 fn_1_54E34(void *, f32);
extern void fn_800724C8(void);
extern void fn_8007245C(u32);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern u32 GXLoadPosMtxImm(u32, u32);
extern void lbl_8006DB30(void);
extern void fn_800736C0(u32, void *);
extern u32 fn_8003462C(u32, u32, u32);
extern void lbl_8006DFC4(u32);
extern void lbl_8006E1D8(u32, f32, f32, f32);

extern vu32 __DIRegs[];

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad_00[0x14];
    f32 unk_14;
    u8 pad_18[0x0C];
    f32 unk_24;
    u8 pad_28[0x0C];
    f32 unk_34;
    u32 unk_38;
    u32 unk_3c;
} Obj_1_9EDE8;

/* fzgx-allow: A1 GX FIFO write port; retail materialises it as lis 0xcc01/stfs -0x8000 */
#define FIFO(v) (*(volatile f32 *)(GX_FIFO_BASE + 0x0) = (v)) /* Hardware access must remain ordered. */

void fn_1_9EDE8(Obj_1_9EDE8 *arg0) {
    Vec3 pos;
    u32 z;
    Vec3 vtx[4];
    struct { f32 value; } radius;
    struct { f32 value; } neg;

    pos.x = arg0->unk_14;
    pos.y = arg0->unk_24;
    pos.z = arg0->unk_34;
    if (arg0->unk_38 & 2) {
        radius.value = *(f32 *)((u8 *)arg0 + 4);
    } else {
        radius.value = *(f32 *)arg0;
    }
    if (!(arg0->unk_38 & 4) && fn_1_54E34(&pos, radius.value) == 0) {
        arg0->unk_38 |= 1;
        return;
    }
    arg0->unk_38 &= ~1;
    fn_800724C8();
    fn_8007245C(0x2200);
    lbl_8006DAEC();
    lbl_8006D758();
    GXLoadPosMtxImm(lbl_801A6D00, 0);
    lbl_8006DB30();
    z = arg0->unk_3c;
    fn_800736C0(0, &z);
    fn_8003462C(0x90, 0, 8);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    fn_8003462C(0x80, 0, 4);
    radius.value = *(f32 *)arg0;
    neg.value = -radius.value;
    lbl_8006DAEC();
    lbl_8006DFC4((u32)((u8 *)arg0 + 8));
    lbl_8006E1D8((u32)&vtx[0], neg.value, neg.value, lbl_1_rodata_42D0);
    lbl_8006E1D8((u32)&vtx[1], radius.value, neg.value, lbl_1_rodata_42D0);
    lbl_8006E1D8((u32)&vtx[2], radius.value, radius.value, lbl_1_rodata_42D0);
    lbl_8006E1D8((u32)&vtx[3], neg.value, radius.value, lbl_1_rodata_42D0);
    lbl_8006DB30();
    FIFO(vtx[0].x);
    FIFO(vtx[0].y);
    FIFO(vtx[0].z);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D0);
    FIFO(vtx[1].x);
    FIFO(vtx[1].y);
    FIFO(vtx[1].z);
    FIFO(lbl_1_rodata_42D4);
    FIFO(lbl_1_rodata_42D0);
    FIFO(vtx[2].x);
    FIFO(vtx[2].y);
    FIFO(vtx[2].z);
    FIFO(lbl_1_rodata_42D4);
    FIFO(lbl_1_rodata_42D4);
    FIFO(vtx[3].x);
    FIFO(vtx[3].y);
    FIFO(vtx[3].z);
    FIFO(lbl_1_rodata_42D0);
    FIFO(lbl_1_rodata_42D4);
}
/* fzgx:end fn_1_9EDE8 */

/* fzgx:begin fn_1_9F164 */
typedef struct { f32 x, y, z, w; } Vec4;

struct fn_1_9F164_Arg0 {
    f32 unk_0;
    f32 unk_4;
    Vec4 unk_8[3];
    u32 unk_38;
    u32 unk_3C;
};

#define XF_PUT(v) (*(volatile f32 *)0xCC008000 = (f32)(v)) /* fzgx-allow: A1,A2 unnamed OS/hardware memory */

extern f32 lbl_1_rodata_42D0;
extern f32 lbl_1_rodata_42D4;
extern s32 fn_1_54E34(void *, f32);
extern void fn_800736C0(u32, void *);
extern void fn_8003462C(u32, u32, u32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006E1D8(void *, f32, f32, f32);
extern void lbl_8006DB30(void);

#pragma opt_propagation off
void fn_1_9F164(struct fn_1_9F164_Arg0 *arg0, f32 arg1) {
    u32 v0;
    f32 v1;
    f32 v5;
    f32 v4;
    f32 loc_3C[3];
    f32 loc_30[3];
    f32 loc_24[3];
    f32 loc_18[3];
    f32 loc_C[3];
    u32 loc_8;
    void * lab_t0;
    loc_C[0] = arg0->unk_8[0].w;
    loc_C[1] = arg0->unk_8[1].w;
    loc_C[2] = arg0->unk_8[2].w;
    v0 = arg0->unk_38;
    if ((v0 & 0x2) != 0) {
        v1 = arg0->unk_4;
    } else {
        v1 = arg0->unk_0;
    }
    if ((v0 & 0x4) == 0 && fn_1_54E34((void *)loc_C, v1) == 0) {
        arg0->unk_38 |= 1;
    } else {
        arg0->unk_38 &= ~1;
        loc_8 = arg0->unk_3C;
        fn_800736C0(0, (void *)&loc_8);
        fn_8003462C(0x90, 0, 8);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0); XF_PUT(lbl_1_rodata_42D0);
        fn_8003462C(0x80, 0, 4);
        v4 = arg0->unk_0;
        v5 = -v4;
        lbl_8006DAEC();
        lbl_8006DFC4((void *)&arg0->unk_8[0]);
        lbl_8006E1D8((lab_t0 = (void *)loc_18), v5, v5, lbl_1_rodata_42D0);
        lab_t0 = (void *)loc_24;
        lbl_8006E1D8(lab_t0, v4, v5, lbl_1_rodata_42D0);
        lab_t0 = (void *)loc_30;
        lbl_8006E1D8(lab_t0, v4, v4, lbl_1_rodata_42D0);
        lab_t0 = (void *)loc_3C;
        lbl_8006E1D8(lab_t0, v5, v4, lbl_1_rodata_42D0);
        lbl_8006DB30();
        XF_PUT(loc_18[0]);
        XF_PUT(loc_18[1]);
        XF_PUT(loc_18[2]);
        XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(loc_24[0]);
        XF_PUT(loc_24[1]);
        XF_PUT(loc_24[2]);
        XF_PUT(lbl_1_rodata_42D4);
        XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(loc_30[0]);
        XF_PUT(loc_30[1]);
        XF_PUT(loc_30[2]);
        XF_PUT(lbl_1_rodata_42D4);
        XF_PUT(lbl_1_rodata_42D4);
        XF_PUT(loc_3C[0]);
        XF_PUT(loc_3C[1]);
        XF_PUT(loc_3C[2]);
        XF_PUT(lbl_1_rodata_42D0);
        XF_PUT(lbl_1_rodata_42D4);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_9F164 */

/* fzgx:begin fn_1_9F4B4 */
struct fn_1_9F4B4_Arg0 {
    u8 pad_0[0xC];
    f32 unk_C;
    s16 unk_10;
    u16 unk_12;
    u32 unk_14;
};
struct fn_1_9F4B4_lbl_1_rodata_42D0 {
    f32 unk_0;
};

extern struct fn_1_9F4B4_lbl_1_rodata_42D0 lbl_1_rodata_42D0;
extern struct fn_1_9F4B4_lbl_1_rodata_42D0 lbl_1_rodata_42D4;
extern s32 fn_1_54E34(void *, f32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800736C0(u32, void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E1D8(u32, f32, f32, f32);

#pragma opt_propagation off
static inline f32 fn_1_9F4B4_read_pointer(struct fn_1_9F4B4_lbl_1_rodata_42D0 * owner) { return owner->unk_0; }
#pragma opt_strength_reduction off
static inline f32 fn_1_9F4B4_read_pointer_(struct fn_1_9F4B4_lbl_1_rodata_42D0 * owner) { return owner->unk_0; }
void fn_1_9F4B4(struct fn_1_9F4B4_Arg0 *arg0) {
    f32 loc_30[3];
    f32 loc_24[3];
    f32 loc_18[3];
    f32 loc_C[3];
    u32 loc_8;
    struct { f32 value; } f31;
    struct { f32 value; } f30;
    u32 lab_t0;
    u32 lab_t0_;
    u32 lab_t0__;

    if (fn_1_54E34((void *)arg0, arg0->unk_C) == 0) {
        arg0->unk_12 |= 1;
    } else {
        arg0->unk_12 &= 0xFFFE;
        loc_8 = arg0->unk_14;
        fn_800736C0(0, (void *)&loc_8);
        fn_8003462C(0x90, 0, 8);
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = fn_1_9F4B4_read_pointer_(&lbl_1_rodata_42D0);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC010000 + -32768) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        fn_8003462C(0x80, 0, 4);
        {
            struct { f32 value; } f31s;
            f31s.value = -arg0->unk_C;
            f31.value = f31s.value;
            f30.value = arg0->unk_C;
            lbl_8006DAEC();
            lbl_8006E0A4((void *)arg0);
            if (arg0->unk_10 != 0) {
                mathutil_mtxA_rotate_z(arg0->unk_10);
            }
            lbl_8006E1D8((u32)loc_C, f31.value, f31.value, lbl_1_rodata_42D0.unk_0);
            lab_t0_ = (u32)loc_18;
            lbl_8006E1D8(lab_t0_, f30.value, f31.value, lbl_1_rodata_42D0.unk_0);
            lab_t0 = (u32)loc_24;
            lbl_8006E1D8(lab_t0, f30.value, f30.value, lbl_1_rodata_42D0.unk_0);
            lab_t0__ = (u32)&loc_30;
            lbl_8006E1D8(lab_t0__, f31.value, f30.value, lbl_1_rodata_42D0.unk_0);
        }
        lbl_8006DB30();
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_C[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_C[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_C[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_18[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_18[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_18[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = fn_1_9F4B4_read_pointer(&lbl_1_rodata_42D4);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_24[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_24[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_24[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = fn_1_9F4B4_read_pointer(&lbl_1_rodata_42D4);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = fn_1_9F4B4_read_pointer(&lbl_1_rodata_42D4);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_30[0];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_30[1];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = loc_30[2];  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = lbl_1_rodata_42D0.unk_0;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
        *(f32 *)((u8 *)0xCC000000 + 0x8000) = fn_1_9F4B4_read_pointer(&lbl_1_rodata_42D4);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    }
}
#pragma opt_strength_reduction reset

#pragma opt_propagation reset
/* fzgx:end fn_1_9F4B4 */
