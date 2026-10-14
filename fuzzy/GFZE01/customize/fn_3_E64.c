/* Non-matching: best partial attempt (87.35% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

typedef struct {
    u8 pad_0[0xE1C];
    u32 tbl1[9];
    u32 tbl2[9];
    u8 pad_1[0x15D4 - 0xE64];
    char fmt[0x448];
} CustomizeData;

typedef struct {
    u32 t08;
    u32 t0c;
    u32 t10;
    u32 t14;
    u32 t18;
    u32 t1c;
    u32 t20;
    u32 t24;
    u32 v28;
    u32 v2c;
    u32 res;
} Tmp;

extern f32 lbl_3_rodata_0[17];
extern s32 lbl_801A66B4[1];

extern u32 fn_800081C8(void *a, void *b, f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4D494(void);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *, ...);
extern u32 fn_1_4D4C8(void *, f32, f32);
extern void fn_1_49528(u32 *);

#pragma opt_common_subs off
static inline s32 fn_3_E64_array_read(s32 index, s32 *array) { return array[index]; }
#pragma opt_propagation off
static inline u8 *fn_3_E64_array_read_(u8 *array) { return array; }
#pragma opt_strength_reduction off
static inline u32 *fn_3_E64_array_read__(u32 *array) { return array; }
#pragma opt_lifetimes off
static inline u32 *fn_3_E64_read_pointer(CustomizeData *owner) { return owner->tbl1; }

void fn_3_E64(u8 *param) {
    struct { f32 *value; } pool;
    struct { CustomizeData *value; } dat;
    Tmp s;

    pool.value = lbl_3_rodata_0;
    dat.value = (CustomizeData *)&lbl_3_data_0;
    s.v28 = ((u32 *)pool.value)[0x23];
    s.v2c = ((u32 *)pool.value)[0x22];
    s.res = fn_800081C8(&s.v2c, &s.v28, pool.value[0x2A]);
    fn_1_49410();
    fn_1_4955C(pool.value[0x1F], pool.value[0x1F]);
    fn_1_495C8(9);
    if (fn_3_E64_array_read(0, lbl_801A66B4) != 5) {
        fn_1_495B0(0x80000000u);
        fn_1_49590(pool.value[0x05]);
        fn_1_4966C(pool.value[0x18], pool.value[0x1A]);
    }
    fn_1_496FC(pool.value[0x2B], pool.value[0x01]);
    fn_1_495C8(10);
    if (fn_3_E64_array_read_(param)[0] == 0) {
        fn_1_4D494();
        s.t24 = ((u32 *)pool.value)[0x24];
        fn_1_49514(&s.t24);
        fn_1_4954C(pool.value[0x2C]);
        fn_1_4AE0C(dat.value->fmt, fn_3_E64_array_read__(fn_3_E64_read_pointer(dat.value))[fn_3_E64_array_read(0, lbl_801A66B4)], &lbl_801A66B4[0]);
        s.t20 = s.res;
        fn_1_4D4C8(&s.t20, pool.value[0x1C], pool.value[0x2D]);
    } else {
        s.t1c = ((u32 *)pool.value)[0x25];
        fn_1_49514(&s.t1c);
        s.t18 = ((u32 *)pool.value)[0x26];
        fn_1_49528(&s.t18);
        fn_1_4954C(pool.value[0x2C]);
        fn_1_4AE0C(dat.value->fmt, fn_3_E64_array_read__(fn_3_E64_read_pointer(dat.value))[fn_3_E64_array_read(0, lbl_801A66B4)], &lbl_801A66B4[0]);
    }
    fn_1_496FC(pool.value[0x2E], pool.value[0x01]);
    fn_1_495C8(8);
    if (fn_3_E64_array_read_(param)[0] == 0) {
        s.t14 = ((u32 *)pool.value)[0x27];
        fn_1_49514(&s.t14);
        s.t10 = ((u32 *)pool.value)[0x28];
        fn_1_49528(&s.t10);
        fn_1_4954C(pool.value[0x2C]);
        fn_1_4AE0C(dat.value->fmt, fn_3_E64_array_read__(dat.value->tbl2)[fn_3_E64_array_read(0, lbl_801A66B4)], &lbl_801A66B4[0]);
    } else {
        fn_1_4D494();
        s.t0c = ((u32 *)pool.value)[0x29];
        fn_1_49514(&s.t0c);
        fn_1_4954C(pool.value[0x2C]);
        fn_1_4AE0C(dat.value->fmt, fn_3_E64_array_read__(dat.value->tbl2)[fn_3_E64_array_read(0, lbl_801A66B4)], &lbl_801A66B4[0]);
        s.t08 = s.res;
        fn_1_4D4C8(&s.t08, pool.value[0x1C], pool.value[0x2D]);
    }
}

#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset

#pragma opt_propagation reset

#pragma opt_common_subs reset
