/* Non-matching: best partial attempt (98.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/bg_lig.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[4] = {0x00000000, 0x0280012C, 0x00000000, 0x00000001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 100.0f;
    s = 3.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.7;
    d = 0.3;
    s = 32767.0f;
    s = 235.0f;
    s = 80.0f;
    s = 30.0f;
    d = 512.0;
    d = 0.5;
    d = 300.0;
    d = 17.0;
    s = 3276.800048828125f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    d = 0.98;
    s = 0.07999999821186066f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.99;
    d = 0.02;
    s = 400.0f;
    s = 0.7071067690849304f;
    s = 1.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table11[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.5f;
    s = 0.5f;
    s = 10.0f;
    s = 5.0f;
    s = 0.6000000238418579f;
    s = 170.0f;
    s = 120.0f;
    s = 32.0f;
    s = 90.0f;
    s = 0.4000000059604645f;
    s = 768.0f;
}
static const u32 fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.05;
    s = 2.5f;
    s = 0.10000000149011612f;
    s = 50.0f;
    s = 20.0f;
    s = 70.0f;
    s = 33.0f;
    s = 15.0f;
    s = 0.6499999761581421f;
}
#pragma section code_type ".text"

typedef struct {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[0x30];
    u32 unk_38;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Sig_fn_1_9EDE8_Obj;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 pad_c[0xC];
    f32 r;
    f32 g;
    f32 b;
    f32 unk_24;
    s16 unk_28;
    u8 pad_2a[2];
    s16 unk_2C;
} UnkR29;

typedef struct {
    u8 pad_0[0x8];
    UnkR29 *unk_8;
} Arg0;

typedef struct {
    u8 pad_0[0x24];
    void *unk_24;
} UnkR30;

typedef struct {
    u8 pad_0[0x170];
    UnkR30 *unk_170;
} UnkR4;

extern f32 lbl_8006D0B4(f32);
extern u32 fn_800720B0(u32);
extern int fn_1_58C4(void);
extern void * memset(void *, int, u32);
extern void fn_1_681C(u8, f32 *);
extern void fn_1_9EDE8(Sig_fn_1_9EDE8_Obj *);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073678(u32);
extern void fn_80073778(void *, s32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);
extern void lbl_8006D758(void);
extern void lbl_8006D7DC(f32 *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E1B0(void *, void *);
extern void mathutil_mtxA_rotate_z(s16);

#define CALC_DIST() (lbl_8006D0B4((f32)((r29->x - fn_1_D8878_array_read(0, loc_8)) * (r29->x - fn_1_D8878_array_read(0, loc_8))) + \
                                  (r29->y - fn_1_D8878_array_read(1, loc_8)) * (r29->y - fn_1_D8878_array_read(1, loc_8)) + \
                                  (r29->z - loc_8[2]) * (r29->z - loc_8[2])))

#pragma opt_common_subs off
static inline f32 fn_1_D8878_array_read(s32 index, f32 *array) { return array[index]; }
#pragma opt_strength_reduction off
void fn_1_D8878(Arg0 *arg0) {
    Sig_fn_1_9EDE8_Obj obj;
    f32 loc_14[3];
    u32 i;
    void *val;
    f32 f1;
    f32 f5;
    f32 f4;
    f32 unk_24;
    s16 fade;
    struct { f32 value; } min_dist;
    f32 loc_8[3];
    u32 count;
    UnkR30 *r30;
    UnkR29 *r29;
    UnkR4 *r4;
    Obj_1_data_2A7E0_At3C *r26;
    UnkR29 * fzgx_live;
    s32 lab_t5;

    r26 = lbl_1_data_2A7E0.unk_3C;
    r4 = (UnkR4 *)lbl_1_bss_38458->unk_8;
    fzgx_live = arg0->unk_8;
    r29 = fzgx_live;
    r30 = r4->unk_170;

    lbl_8006DCA4();
    lbl_8006E1B0(r29, loc_14);
    lbl_8006D7DC(loc_14);
    mathutil_mtxA_rotate_z(r29->unk_28);
    count = fn_1_58C4();

    fn_1_681C(0, loc_8);
    min_dist.value = CALC_DIST();

    for (i = 1; i < count; i++) {
        fn_1_681C(i, loc_8);
        min_dist.value = (min_dist.value < CALC_DIST()) ? min_dist.value : CALC_DIST();
    }

    if (min_dist.value < 20.0f) {
        min_dist.value /= 20.0f;
    } else {
        min_dist.value = 1.0f;
    }

    fade = r29->unk_2C;
    if (fade > 0) {
        min_dist.value *= 1.0f - (f32)fade / 15.0f;
    }

    memset(&obj, 0, sizeof(obj));
    lbl_8006DB74(&obj.pad_8);

    unk_24 = r29->unk_24;
    f4 = min_dist.value < 0.0f ? 0.0f : (min_dist.value > 1.0f ? 1.0f : min_dist.value);

    f5 = r26->unk_6C0;
    f1 = f4 * f5;
    obj.unk_0 = 0.70710677f * unk_24;
    obj.r = (u32)(u8)r29->r * f4 * f5;
    obj.g = (u32)(u8)r29->g * f4 * f5;
    obj.b = (u32)(u8)r29->b * f4 * f5;
    obj.a = 255;

    if (f1 < 0.1f) {
        return;
    }

    obj.unk_38 |= 2;
    obj.unk_4 = 2.0 * obj.unk_0;
    val = r30->unk_24;
    fn_80074788(0);
    fn_80072864(1);
    fn_80073778(val, 0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80073C6C(0);
    fn_80072C24(0, 15, 14, 8, 15);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    lab_t5 = 0;
    fn_80072E20(0, 0, 0, 0, 1, lab_t5);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 7, 0);
    fn_800720B0(0);
    fn_800728A8(1, 3, 1, 7);
    lbl_8006D758();
    fn_1_9EDE8(&obj);
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

