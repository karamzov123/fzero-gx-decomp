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
extern void GXPeekZ(u32, u32, void *);
extern void GXPokeAlphaRead(u32);
extern void fn_8003432C(u32, u32, u32 *);

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
extern void GXPeekZ(u32, u32, void *);
extern void GXPokeAlphaRead(u32);
extern void fn_8003432C(u32, u32, u32 *);

extern s32 fn_1_9D93C(s32, u32 *);
typedef u32 (*Sig_fn_1_9CF78_FilterCallback)(u32, void *);
extern void fn_1_9CF78(void *, Sig_fn_1_9CF78_FilterCallback);

/* Retail TU .data objects in retail order: MWCC addresses them off one section base
   lbl_1_data_2A0C0, so the unit defines them; its copy is dropped at integration. */
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
            lbl_8006DFE8(lbl_1_data_2A7E0.unk_78 + ((0x30) * j.value));
            lbl_8006E0B4(fzgx_pool_lbl_1_rodata_41FC, fzgx_pool_lbl_1_rodata_4260__fzgx_offset_34, fzgx_pool_lbl_1_rodata_4260__fzgx_offset_38);
            mathutil_mtxA_rotate_x(angle);
            fn_1_55FF0(arr[j.value]);
            fn_1_555D0((Sig_fn_1_555D0_Object *)lbl_1_data_2A7E0.unk_80);
        }
    }
}
/* fzgx:end fn_1_9DB04 */
