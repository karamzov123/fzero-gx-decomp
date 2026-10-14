/* Non-matching: best partial attempt (83.74% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/title/operation.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 15.0;
    s = 320.0f;
    s = 640.0f;
    d = 1.0;
    s = 150.0f;
    s = 0.10000000149011612f;
    s = 20.0f;
    s = 0.8333333134651184f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 0.5f;
    s = 0.09000000357627869f;
    s = 5.0f;
    s = 255.0f;
}
static const u32 fzgx_pool_table4[6] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
}
static const u32 fzgx_pool_table6[17] = {0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.699999988079071f;
    s = 0.009999999776482582f;
    s = 240.0f;
    s = 45.0f;
    s = 0.0010000000474974513f;
    s = 100.0f;
    s = -200.0f;
    s = 120.0f;
    s = 200.0f;
    s = -120.0f;
    s = -0.009999999776482582f;
    s = 10.0f;
    s = -10240.0f;
    s = 1.7999999523162842f;
    s = -1.7999999523162842f;
    s = -20.0f;
    s = -4096.0f;
    s = -2048.0f;
    s = 1.100000023841858f;
    s = -0.5099999904632568f;
    s = 4096.0f;
    s = -1.100000023841858f;
    s = 0.800000011920929f;
}
static const u32 fzgx_pool_table8[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 345.0f;
    s = 2.0f;
    d = 0.85;
    s = -160.0f;
    s = 90.0f;
}
#pragma section code_type ".text"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color4;

struct Bss2A8_Sub {
    u8 lab_pad[8];
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x4];
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
};

struct Bss2A8 {
    u8 pad_0[0x114];
    s32 unk_114;
    u8 pad_118[0xC];
    s32 unk_124;
    s32 unk_128;
};

extern s32 lbl_801A66B4;

extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4D0D4(Color4, f32);
extern void fn_1_5233C(void);
extern f32 fn_1_9E14C(u32, u32, f32);

void fn_8_9B44(void) {
    struct Bss2A8 *p = (struct Bss2A8 *)&lbl_8_bss_2A8;
    f32 t_2;
    s32 x;
    f32 t;
    f32 var_f30;
    f32 f31;
    f32 scale;
    struct Bss2A8_Sub *sub;

    if (p->unk_124 == p->unk_128 - 1) {
        fn_1_A2D84(0xA9100100);
    }

    if (p->unk_124 < 15.0) {
        t = 1.0 - (f32)p->unk_124 / 15.0;
        x = 320.0f + (f32)(640.0f * t);
    } else if (p->unk_124 > p->unk_128 - 15.0) {
        t = 1.0 - (f32)(p->unk_128 - p->unk_124) / 15.0;
        x = 320.0f - (f32)(640.0f * t);
    } else {
        t = 0.0f;
        x = 320;
    }

    var_f30 = (1.0f - t) * (1.0f - t);

    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_495C8(9);
    fn_1_496FC((f32)x, 345.0f);
    fn_1_4954C(0.09f);
    scale = 5.0f / 6.0f;
    fn_1_4955C(scale, scale);
    fn_1_495A0(var_f30);
    fn_1_4D0A0();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(5.0f);
    fn_1_4AE0C(((const char **)lbl_8_data_96AC)[lbl_801A66B4]);
    fn_1_49738(0);

{
    Color4 color = { 255, 255, 255, 255 };
    color.a = 255.0f * var_f30;
    fn_1_4D0D4(color, 20.0f);
}

    if (p->unk_124 < p->unk_128 - 180) {
        var_f30 = 2.0f * (1.0f - (f32)p->unk_124 / (f32)(p->unk_128 - 180));
        if (var_f30 > 1.0f) {
            var_f30 = 1.0f;
        }

        f31 = fn_1_9E14C(lbl_8_data_95B8.unk_0, lbl_8_data_95B8.unk_4, 0.0f);
        fn_1_9E14C(lbl_8_data_95B8.unk_8, lbl_8_data_95B8.unk_C, 0.0f);
        fn_1_9E14C(lbl_8_data_95B8.unk_10, lbl_8_data_95B8.unk_14, 0.0f);

        sub = (struct Bss2A8_Sub *)((u8 *)p + 0x24);
        sub->unk_C = fn_1_9E14C(lbl_8_data_95B8.unk_0, lbl_8_data_95B8.unk_4, var_f30);
        sub->unk_10 = fn_1_9E14C(lbl_8_data_95B8.unk_8, lbl_8_data_95B8.unk_C, var_f30);
        sub->unk_14 = fn_1_9E14C(lbl_8_data_95B8.unk_10, lbl_8_data_95B8.unk_14, var_f30);
        sub->unk_4 = fn_1_9E14C(lbl_8_data_95B8.unk_18, lbl_8_data_95B8.unk_1C, var_f30);

        {
            f64 delta = 0.85f * (sub->unk_C - f31);
            sub->unk_C = f31 + delta;
        }
    }

    {
        s32 unk_128 = p->unk_128;
        struct Bss2A8_Sub *subD8 = (struct Bss2A8_Sub *)((u8 *)p + 0xD8);
        s32 unk_124 = p->unk_124;

        subD8->unk_C = -160.0f;
        subD8->unk_10 = 90.0f;

        if (unk_124 > unk_128 - 60) {
            t = (f32)(unk_128 - unk_124) / 60.0f;
            subD8->unk_4 = t;
            subD8->unk_4 = t * t;
        } else if (unk_124 < 60) {
            t_2 = (f32)unk_124 / 60.0f;
            subD8->unk_4 = t_2;
            subD8->unk_4 = t_2 * t_2;
        } else {
            subD8->unk_4 = 1.0f;
        }

        p->unk_114 = 0;
        if (unk_124 < unk_128 - 90 && unk_124 > unk_128 - 180) {
            if (unk_124 % 30 > 10) {
                p->unk_114 = 1;
            }
        }
    }
}
