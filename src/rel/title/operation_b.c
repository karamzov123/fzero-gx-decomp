#include "types.h"
#include "rel/title/globals.h"
#include "rel/title/operation.h"
extern s16 lbl_1_bss_96A;
extern u16 lbl_1_bss_9F8[];
extern s32 lbl_801A66B4;
extern u32 fn_1_3EB78(u32, u32, u32, u32);
extern u32 fn_1_3ED8C(u32, u32, u32, u32, u32, u32, u32);
extern void fn_1_3EF08(u8);
extern void fn_1_3EF8C(u8);
extern void fn_1_3EFF0(u32, u8);
extern void fn_1_3F02C(u32);
extern char lbl_8_data_A0C4[];
extern char lbl_8_data_A174[];
extern char lbl_8_data_A178[];
extern char lbl_8_data_A17C[];
extern char lbl_8_data_A180[];
extern char lbl_8_data_A184[];
extern s32 fn_1_1555B0(s32);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_14BCBC(void *, u32);
extern u32 fn_1_144F40(u32, void *);
extern void fn_8_D020(void);

/* fzgx:begin fn_8_D034 */
typedef struct { u8 r, g, b, a; } fn_8_D034_Color8;
typedef struct { const char *msg[6]; } MsgTable;

u8 lbl_8_bss_540;
s32 lbl_8_bss_544;
s32 lbl_8_bss_544__fzgx_offset_4;
s32 lbl_8_bss_544__fzgx_offset_8;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 v;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    v = lbl_8_bss_540;
    v = *(u8 *)&lbl_8_bss_544;
    v = *(u8 *)&lbl_8_bss_544__fzgx_offset_4;
    v = *(u8 *)&lbl_8_bss_544__fzgx_offset_8;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static const MsgTable fzgx_pool_msgs = {{
    lbl_8_data_A0C4, lbl_8_data_A174, lbl_8_data_A178, lbl_8_data_A17C, lbl_8_data_A180, lbl_8_data_A184,
}};  /* fzgx-allow: A1 retail data bytes and bindings */
static const fn_8_D034_Color8 fzgx_pool_white = { 0xFF, 0xFF, 0xFF, 0x00 };  /* fzgx-allow: A1 retail pool bytes */
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 989.0;
    d = 795.0;
    d = 15.0;
    d = 975.0;
    d = 0.0;
    d = 320.0;
    d = 640.0;
    d = 1.0;
    d = 780.0;
    d = 990.0;
    s = 0.5f;
    s = 240.0f;
    s = 0.0f;
    s = 1.0f;
    s = 0.8333333134651184f;
    s = 5.0f;
    s = 255.0f;
    s = 20.0f;
    d = 1800.0;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

struct Sig_fn_8_CF94_fn_8_CF94_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA4];
    u32 unk_A8;
    u32 unk_AC;
    u8 pad_B0[0x14];
    u32 unk_C4;
    u8 pad_C8[0x4];
    u32 unk_CC;
};
struct fn_8_D034_lbl_8_bss_540 {
    u8 unk_0;
    u8 pad_1[3];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
};
struct fn_8_D034_lbl_8_rodata_368 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 pad_1C[4];
    f64 unk_20;
    f64 unk_28;
    f64 unk_30;
    f64 unk_38;
    f64 unk_40;
    f64 unk_48;
    f64 unk_50;
    f32 unk_58;
    f64 unk_60;
    f64 unk_68;
    f32 unk_70;
    f32 unk_74;
    f32 unk_78;
    f32 unk_7C;
    f64 unk_80;
    f32 unk_84;
    f32 unk_88;
    f64 unk_8C;
    f64 unk_90;
    f64 unk_98;
};
struct fn_8_D034_lbl_8_data_A0C0 { u8 unk_0; };
struct fn_8_D034_lbl_1_bss_8E51D { u8 unk_0; };

extern struct fn_8_D034_lbl_1_bss_8E51D lbl_1_bss_8E51D;

extern struct fn_8_D034_lbl_8_rodata_368 lbl_8_rodata_368;

extern void fn_1_47F74(s32);
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f64, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_5233C(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4D0D4(fn_8_D034_Color8 *, f32);
extern int fn_1_3F038(void);
extern void fn_8006CE1C(f32);
extern void fn_1_3F894(void);
extern void fn_8_CF94(struct Sig_fn_8_CF94_fn_8_CF94_Arg0 *);

typedef union { struct { u16 pad : 7; u16 value : 9; } a; struct { u16 pad : 4; u16 value : 12; } b; } fn_8_D034_Bits;
#pragma opt_propagation off
void fn_8_D034(void) {
    u8 fzgx_value;
    MsgTable msgs = fzgx_pool_msgs;
    s32 n;
    s32 m;
    s32 idx;
    f32 x;
    f64 curve;
    f32 alpha;
    f64 t;
    u32 lab_t1;
    fn_8_D034_Color8 c2;

    if (lbl_8_bss_544 == 1) {
        n = (*(struct fn_8_D034_lbl_8_data_A0C0 *)&lbl_8_data_A0C0).unk_0;
        n = n + 1;
        m = n > 36 ? 31 : (n < 31 ? 36 : n);
        lbl_8_bss_540 = m;
        fzgx_value = m;
        (*(struct fn_8_D034_lbl_8_data_A0C0 *)&lbl_8_data_A0C0).unk_0 = fzgx_value;
        fn_1_3EF8C(6);
        lab_t1 = 3;
        fn_1_3ED8C(0, lab_t1, 1, (*(struct fn_8_D034_lbl_8_data_A0C0 *)&lbl_8_data_A0C0).unk_0, 10, 10, 0);
        fn_1_3EB78(0, 0, 0, 0);
        fn_1_3EFF0((u32)fn_8_CF94, 1);
        fn_1_3F02C((u32)fn_8_D020);
        fn_1_3EF08(0);
        fn_1_14A1AC(lbl_1_bss_8E51D.unk_0);
        fn_1_14BC40();
        fn_1_1554D0();
        fn_1_1555B0(lbl_8_bss_540);
        lbl_8_bss_544__fzgx_offset_4 = 1020;
        lbl_8_bss_544__fzgx_offset_8 = 0;
        fn_1_47F74(149);
        fn_1_47F74(151);
        fn_1_47F74(152);
    }
    if (lbl_8_bss_544-- > 0) {
        return;
    }
    if (lbl_8_bss_544__fzgx_offset_8 == 0 && lbl_8_bss_544__fzgx_offset_4 == 989.0) {
        fn_1_A2D84(0xA9121C00);
    }
    if (lbl_8_bss_544__fzgx_offset_8 == 0) {
        idx = lbl_8_bss_544__fzgx_offset_4;
        curve = idx < 795.0 ? (f32)(idx - 795.0) / 15.0
              : (idx > 975.0 ? (f32)(idx - 975.0) / 15.0 : 0.0);
        x = 320.0 + (640.0 * curve);
        t = (idx < 780.0 || 990.0 < idx) ? 0.0
          : ((795.0 < idx && idx < 975.0) ? 1.0
          : ((780.0 <= idx && idx <= 795.0) ? (f32)(idx - 780.0) / 15.0
          : (f32)(990.0 - idx) / 15.0));
        alpha = t;
        alpha *= alpha;
        fn_1_49410();
        fn_1_495B0(0x80000000);
        fn_1_49590(0.5f);
        fn_1_495C8(9);
        fn_1_496FC(x, 240.0f);
        fn_1_4954C(0.0f);
        if ((lbl_801A66B4) == 5) {
            fn_1_4955C(1.0f, 1.0f);
        } else {
            fn_1_4955C(0.8333333f, 0.8333333f);
        }
        fn_1_495A0(alpha);
        fn_1_4D0A0();
        fn_1_49738((u32)fn_1_5233C);
        fn_1_49748(5.0f);
        fn_1_4A0D8((*((lbl_801A66B4) + msgs.msg)));
        {
            fn_8_D034_Color8 c = fzgx_pool_white;
            c.a = 255.0f * alpha;
            c2 = c;
            fn_1_4D0D4(&c2, 20.0f);
        }
    }
    fn_1_14BCBC(&lbl_8_bss_540, 0);
    if (((((fn_8_D034_Bits *)&lbl_1_bss_9F8[14])->a.value >> 3) & 1) || ((lbl_1_bss_9F8[14] >> 2) & 1) || (lbl_1_bss_9F8[14] & 1) || ((lbl_1_bss_9F8[14] >> 1) & 1) || ((lbl_1_bss_9F8[4] >> 11) & 1) || ((lbl_1_bss_9F8[4] >> 9) & 1) || ((lbl_1_bss_9F8[4] >> 8) & 1)) {
        if (0 == lbl_8_bss_544__fzgx_offset_8) {
            lbl_8_bss_544__fzgx_offset_4 += 1800.0;
            lbl_8_bss_544__fzgx_offset_8 = 1;
        }
    }
    fn_1_144F40(10, &lbl_8_bss_540);
    if (fn_1_3F038()) {
        lbl_1_bss_96A = 0x9e;
    } else if (lbl_8_bss_544__fzgx_offset_4-- < 0) {
        fn_8006CE1C(1.0f);
        fn_1_3F894();
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_8_D034 */
