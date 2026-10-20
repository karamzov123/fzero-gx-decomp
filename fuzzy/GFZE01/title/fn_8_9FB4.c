/* Non-matching: best partial attempt (80.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/title/operation.h"

typedef struct {
    u8 pad_0[0x24];
    u16 unk_24;
    u8 pad_26[0xA];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[0x64];
    u16 unk_9C;
    u8 pad_9E[2];
    f32 unk_A0;
    f32 unk_A4;
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x70];
    s32 unk_124;
    s32 unk_128;
} fn_8_9FB4_obj;

typedef struct {
    f64 v_00;
    f32 v_08;
    f32 v_0C;
    f64 v_10;
    u8 pad_14[0xC];
    f32 v_20;
    f32 v_24;
    f64 v_28;
    u8 pad_30[4];
    f32 v_34;
    f32 v_38;
    f32 v_3C;
    f32 v_40;
    f32 v_44;
    f32 v_48;
    u8 pad_4C[0xC4];
    f32 v_110;
    f32 v_114;
    f64 v_118;
    f32 v_120;
    f32 v_124;
    u32 v_128;
    f32 v_12C;
    f32 v_130;
    f32 v_134;
    f32 v_138;
} fn_8_9FB4_pool;

extern fn_8_9FB4_pool lbl_8_rodata_160;
extern u32 lbl_801A66B4;
extern u32 lbl_801A66A0;
extern void fn_1_5233C(void);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(u32 *, f32);
extern f32 fn_1_9E14C(u32, u32, f32);

void fn_8_9FB4(void) {
    fn_8_9FB4_obj *obj = (fn_8_9FB4_obj *)&lbl_8_bss_2A8;
    fn_8_9FB4_pool *pool = &lbl_8_rodata_160;
    f32 g;
    f32 h;
    s32 v;
    f32 t;
    f32 p;
    volatile u8 b; /* retail stores a dead byte here */
    u32 w;

    if ((f64)obj->unk_124 < pool->v_00) {
        t = (f32)(pool->v_10 - (f32)obj->unk_124 / pool->v_00);
        p = pool->v_0C * t;
        v = (s32)(pool->v_08 + p);
    } else if ((f64)obj->unk_128 - pool->v_00 > (f64)obj->unk_124) {
        t = (f32)(pool->v_10 - (f32)(obj->unk_128 - obj->unk_124) / pool->v_00);
        p = pool->v_0C * t;
        v = (s32)(pool->v_08 - p);
    } else {
        t = pool->v_34;
        v = 0x140;
    }
    g = (pool->v_38 - t) * (pool->v_38 - t);

    fn_1_49410();
    fn_1_495B0(0x8000u << 16);
    fn_1_49590(pool->v_3C);
    fn_1_495C8(9);
    fn_1_496FC((f32)v, pool->v_110);
    fn_1_4954C(pool->v_40);
    fn_1_4955C(pool->v_24, pool->v_24);
    fn_1_495A0(g);
    fn_1_4D0A0();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(pool->v_44);
    fn_1_4AE0C(*(const char **)&lbl_8_data_9778[lbl_801A66B4 * 4]);
    fn_1_49738(0);
    b = (s32)(pool->v_48 * g);
    w = pool->v_128;
    fn_1_4D0D4(&w, pool->v_20);

    if (obj->unk_124 > obj->unk_128 - 30) {
        obj->unk_34 = pool->v_124;
        obj->unk_30 = pool->v_12C - pool->v_130 * (f32)(obj->unk_128 - obj->unk_124) / pool->v_134;
    } else {
        obj->unk_30 = pool->v_120;
        obj->unk_34 = pool->v_124;
    }

    obj->unk_24 = 0;
    obj->unk_9C = (u16)(lbl_801A66A0 << 9);

    if (obj->unk_124 < obj->unk_128 - 90) {
        g = pool->v_114 * (pool->v_38 - (f32)obj->unk_124 / (f32)(obj->unk_128 - 90));
        if (g > pool->v_38) {
            g = pool->v_38;
        }
        h = fn_1_9E14C(lbl_8_data_9270.unk_0, lbl_8_data_9270.unk_4, pool->v_34);
        fn_1_9E14C(lbl_8_data_9270.unk_8, lbl_8_data_9270.unk_C, pool->v_34);
        fn_1_9E14C(lbl_8_data_9270.unk_10, lbl_8_data_9270.unk_14, pool->v_34);
        obj->unk_A8 = fn_1_9E14C(lbl_8_data_9270.unk_0, lbl_8_data_9270.unk_4, g);
        obj->unk_AC = fn_1_9E14C(lbl_8_data_9270.unk_8, lbl_8_data_9270.unk_C, g);
        obj->unk_B0 = fn_1_9E14C(lbl_8_data_9270.unk_10, lbl_8_data_9270.unk_14, g);
        obj->unk_AC = obj->unk_AC - pool->v_138;
        obj->unk_A0 = fn_1_9E14C(lbl_8_data_9270.unk_18, lbl_8_data_9270.unk_1C, g);
        obj->unk_A8 = (f32)(h + pool->v_118 * (obj->unk_A8 - h));
    }
}
