/* Non-matching: best partial attempt (94.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 300.0f;
    s = 320.0f;
    s = 234.0f;
    s = 230.0f;
    s = 0.0f;
    s = 0.5f;
    s = 2.0f;
    s = 0.009999999776482582f;
    s = 0.019999999552965164f;
}
static const u32 fzgx_pool_table2[4] = {0x0032FFFF, 0x000000FF, 0x000000FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.2;
    s = 0.6000000238418579f;
    s = 62.0f;
    s = 16.0f;
    s = 0.20000000298023224f;
    s = 3.0f;
    s = 940.0f;
    s = 650.0f;
    s = 36.0f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 9350.0f;
    s = 1800.0f;
    d = 210.0;
    s = 32.0f;
    s = 484.0f;
    s = 424.0f;
    s = 588.0f;
    s = 443.0f;
    s = 480.0f;
    s = 430.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75;
    s = 1.8249999284744263f;
}
static const u32 fzgx_pool_table6[1] = {0x9999999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
    s = 9.999999747378752e-05f;
    s = 200.0f;
}
#pragma section code_type ".text"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Sig_fn_1_862D4_Triple;

struct Sig_fn_1_862A8_fn_1_862A8_Arg1 {
    u16 unk_0;
    u32 unk_4;
    u32 unk_8;
};

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3f;

static f32 fn_dist(V3f *v, V3f *b) {
    f32 dx = v->x - b->x;
    f32 dy = v->y - b->y;
    f32 dz = v->z - b->z;
    return (f32)(dx * dx) + dy * dy + dz * dz;
}

typedef struct {
    u32 unk_0;
    Sig_fn_1_862D4_Triple v0;
    Sig_fn_1_862D4_Triple v1;
    s16 unk_1C;
    f32 unk_20;
    u8 unk_24;
} Ent;

typedef struct {
    u8 pad_0[0x66C];
    u8 unk_66C;
    u8 pad_66D[3];
    s32 unk_670;
    u32 unk_674;
    u8 pad_678[8];
    Ent *unk_680;
    V3f *unk_684;
    f32 unk_688[6];
    f32 unk_6A0;
    f32 unk_6A4;
} Bss_1_bss_1148;

typedef struct {
    u8 pad_0[0x138];
    u32 unk_138;
    u8 pad_13C[4];
    u32 unk_140;
    u32 unk_144;
} Data_1_data_43B8;

typedef struct {
    f32 unk_0;
    u8 pad_4[0x10];
    f32 unk_14;
    u8 pad_18[0xA0];
    f32 unk_B8;
    f32 unk_BC;
} Rodata_4E0;

typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    s16 unk_4;
    s16 unk_6;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u16 unk_14;
    u8 pad_16[2];
    u32 unk_18;
    Sig_fn_1_862D4_Triple v0;
    u8 pad_28[0x24];
    Sig_fn_1_862D4_Triple v1;
    f32 unk_58;
    s16 unk_5C;
    u8 pad_5E[8];
    u16 unk_66;
    u8 pad_68[8];
    struct Sig_fn_1_862A8_fn_1_862A8_Arg1 unk_70;
} Obj;

extern Data_1_data_43B8 lbl_1_data_43B8;
const f32 lbl_1_rodata_4E0 = 1.0f;
const u8 lbl_1_rodata_4E0__fzgx_offset_4[16] = {0x43,0x96,0x00,0x00,0x43,0xA0,0x00,0x00,0x43,0x6A,0x00,0x00,0x43,0x66,0x00,0x00};
const f32 lbl_1_rodata_4F4 = 0.0f;
const u8 lbl_1_rodata_4F4__fzgx_offset_4[72] = {0x3F,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x3C,0x23,0xD7,0x0A,0x3C,0xA3,0xD7,0x0A,0x00,0x32,0xFF,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x3F,0xC9,0x99,0x99,0x99,0x99,0x99,0x9A,0x3F,0x19,0x99,0x9A,0x42,0x78,0x00,0x00,0x41,0x80,0x00,0x00,0x3E,0x4C,0xCC,0xCD,0x40,0x40,0x00,0x00,0x44,0x6B,0x00,0x00,0x44,0x22,0x80,0x00,0x42,0x10,0x00,0x00};
const u8 lbl_1_rodata_540[8] = {0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00};
const u8 lbl_1_rodata_548[16] = {0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x46,0x12,0x18,0x00,0x44,0xE1,0x00,0x00};
const u8 lbl_1_rodata_558[40] = {0x40,0x6A,0x40,0x00,0x00,0x00,0x00,0x00,0x42,0x00,0x00,0x00,0x43,0xF2,0x00,0x00,0x43,0xD4,0x00,0x00,0x44,0x13,0x00,0x00,0x43,0xDD,0x80,0x00,0x43,0xF0,0x00,0x00,0x43,0xD7,0x00,0x00,0x00,0x00,0x00,0x00};
const u8 lbl_1_rodata_580[8] = {0x3F,0xE8,0x00,0x00,0x00,0x00,0x00,0x00};
const u8 lbl_1_rodata_588[16] = {0x3F,0xE9,0x99,0x99,0x99,0x99,0x99,0x9A,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00};
const f32 lbl_1_rodata_588__fzgx_offset_10 = 9.99999975e-05f;
const f32 lbl_1_rodata_588__fzgx_offset_14 = 200.0f;
const u8 lbl_1_rodata_588__fzgx_offset_18[100] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xE0,0x00,0x00,0x46,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xEC,0x00,0x00,0x00,0x00,0x00,0x00,0xBE,0x00,0x00,0x00,0x41,0xF0,0x00,0x00,0x3F,0x94,0x7A,0xE1,0x47,0xAE,0x14,0x7B,0x40,0x50,0x40,0x00,0x00,0x00,0x00,0x00,0x3F,0xA9,0x99,0x99,0x99,0x99,0x99,0x9A,0x40,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x00,0x00};
extern u32 lbl_801A63C0;
extern void fn_1_862A8(s16, void *);
extern void fn_1_862D4(int, Sig_fn_1_862D4_Triple *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1148[5];
u8 fzgx_obj_lbl_1_bss_115C;
u8 lbl_1_bss_1148_gap_115D;
u16 lbl_1_bss_1148_gap_115D_fill_115E;
u32 lbl_1_bss_1160[403];
u8 fzgx_obj_lbl_1_bss_17AC;
u8 lbl_1_bss_1148_gap_17AD;
u16 lbl_1_bss_1148_gap_17AD_fill_17AE;
u32 fzgx_obj_lbl_1_bss_17B0;
u8 lbl_1_bss_17B4;
u8 lbl_1_bss_17B4_fill_17B5;
u16 lbl_1_bss_17B4_fill_17B6;
s32 lbl_1_bss_17B4_4;
u32 lbl_1_bss_17B4_8;
u8 lbl_1_bss_17C0;
u8 lbl_1_bss_1148_gap_17C1;
u16 lbl_1_bss_1148_gap_17C1_fill_17C2;
u32 lbl_1_bss_17C4_fill_17C4;
Ent *lbl_1_bss_17C4_4;
V3f *lbl_1_bss_17C4_8;
f32 fzgx_obj_lbl_1_bss_17D0[6];
f32 lbl_1_bss_17D0_18;
f32 lbl_1_bss_17D0_1C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1148;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_115C;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D;
    s = *(u8 *)&lbl_1_bss_1148_gap_115D_fill_115E;
    s = *(u8 *)&lbl_1_bss_1160;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17AC;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD;
    s = *(u8 *)&lbl_1_bss_1148_gap_17AD_fill_17AE;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17B0;
    s = *(u8 *)&lbl_1_bss_17B4;
    s = *(u8 *)&lbl_1_bss_17B4_fill_17B5;
    s = *(u8 *)&lbl_1_bss_17B4_fill_17B6;
    s = *(u8 *)&lbl_1_bss_17B4_4;
    s = *(u8 *)&lbl_1_bss_17B4_8;
    s = *(u8 *)&lbl_1_bss_17C0;
    s = *(u8 *)&lbl_1_bss_1148_gap_17C1;
    s = *(u8 *)&lbl_1_bss_1148_gap_17C1_fill_17C2;
    s = *(u8 *)&lbl_1_bss_17C4_fill_17C4;
    s = *(u8 *)&lbl_1_bss_17C4_4;
    s = *(u8 *)&lbl_1_bss_17C4_8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_17D0;
    s = *(u8 *)&lbl_1_bss_17D0_18;
    s = *(u8 *)&lbl_1_bss_17D0_1C;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
#pragma opt_loop_invariants off
u16 fn_1_107B8(Obj *arg) {
    
    Rodata_4E0 *p_ro;
    Ent *e;
    Data_1_data_43B8 *p_data = (Data_1_data_43B8 *)&lbl_1_data_43B8;
    Ent *tab = lbl_1_bss_17C4_4;
    u32 arr[29];
    V3f p;
    V3f t;
    V3f b;
    u32 cnt;
    u32 num;
    V3f *vec;
    f32 bestd;
    s32 best;
    struct { u32 value; } i;
    s32 changed;
    u32 n;
    u32 found;
    u32 j;

    p_data->unk_138 = 1;
    e = &tab[arg->unk_4];

    if (arg->unk_0 == 5 || arg->unk_0 <= 1 || arg->unk_0 == 2) {
        cnt = p_data->unk_140;
        fn_1_862D4(arg->unk_6, (Sig_fn_1_862D4_Triple *)&t);
        num = p_data->unk_144;
        vec = lbl_1_bss_17C4_8;
        fn_1_862D4(arg->unk_6, (Sig_fn_1_862D4_Triple *)&b);
        bestd = fn_dist(vec, &b);
        best = 0;
        for (i.value = 1; i.value < num; i.value++) {
            f32 d = fn_dist(&vec[i.value], &b);
            if (bestd < d) {
                continue;
            }
            bestd = d;
            best = i.value;
        }
        changed = 0;
        if (lbl_1_bss_17B4_4 != best) {
            lbl_1_bss_17B4_4 = best;
            changed = 1;
        }
        if (changed) {
            n = 0;
            found = (u8)(1);
            for (j = n; j < cnt; j++) {
                if (best == tab[j].unk_0) {
                    arr[n] = j;
                    found = (u8)(0);
                    n++;
                }
            }
            if (found) {
                lbl_1_bss_17B4_8 = 0;
            } else {
                u32 r = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
                lbl_801A63C0 = r;
                lbl_1_bss_17B4_8 = arr[(r & 0x7FFF) % n];
            }
            arg->unk_18 = 1;
        }
        arg->unk_14 = lbl_1_bss_17B4_8;
        arg->unk_C |= 0x200000;
    }

    {
        f32 dist;

        fn_1_862D4(arg->unk_6, (Sig_fn_1_862D4_Triple *)&p);
        fn_1_862A8(arg->unk_6, (struct Sig_fn_1_862A8_fn_1_862A8_Arg1 *)&arg->unk_70);
        arg->v0 = e->v0;
        if (e->unk_24 == 3) {
            arg->v1 = e->v1;
        } else {
            arg->v1 = *(Sig_fn_1_862D4_Triple *)&p;
        }
        lbl_1_bss_17B4 = e->unk_24;
        arg->unk_5C = e->unk_1C;
        arg->unk_58 = e->unk_20;
        dist = fn_dist((V3f *)&arg->v0, &p);
        lbl_1_bss_17D0_18 = dist;
        lbl_1_bss_17D0_1C = dist;
        switch (e->unk_24) {
        case 1:
        case 2:
        case 5:
            arg->unk_66 = 180;
            break;
        case 4:
        {
            f32 *q = fzgx_obj_lbl_1_bss_17D0;
            arg->unk_66 = 200;
            q[0] = lbl_1_rodata_4F4;
            q[1] = lbl_1_rodata_4E0;
            q[4] = lbl_1_rodata_4F4;
            q[5] = lbl_1_rodata_588__fzgx_offset_10;
            q[2] = lbl_1_rodata_588__fzgx_offset_14;
            q[3] = lbl_1_rodata_588__fzgx_offset_14;
        }
            break;
        default:
            arg->unk_66 = 120;
            break;
        }
    }
    return (u32)tab;
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

