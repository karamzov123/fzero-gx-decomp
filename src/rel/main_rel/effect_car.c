#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"

extern void fn_1_6F90C(void *arg0, void *arg1);
extern s16 fn_1_72318(void);
extern void fn_1_71D0C(void *arg0, void *arg1);

extern void *lbl_801A6410;
extern void fn_1_46B4(u32 value, void *field, u8 *data, s32 code);
extern u32 fn_1_4630(u32 value, u32 size, u8 *data, s32 code);
extern void fn_1_862D4(s16 value, void *result);
extern void fn_1_58E3C(void *entry);
extern u32 fn_1_58C4(void);
extern s8 lbl_1_bss_6C878[];
extern struct fn_1_6F404_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern void * fn_1_868C0(s8);
extern u32 fn_1_71024(void *, void *, u32, f32);
extern u32 fn_1_7099C(void *, void *, u32, f32, f32);
extern u32 fn_1_71768(void *, void *);
extern u32 fn_1_702A0(void *, void *, u32, u32);
extern u32 fn_80008C20(void *, void *, void *);
extern u32 lbl_8006E1C0(void *, void *);
extern u32 fn_1_584AC(void);
extern u32 fn_1_6FD58(void *, void *, f32, f32);
extern u32 fn_1_A33F0(u32, f32);
extern u32 fn_1_6D7BC(void *, void *, f32);
extern u32 fn_1_A5594(u32, void *);
extern u32 fn_1_714A8(void *, void *, u32, f32);

/* fzgx:begin fn_1_680F8 */
extern u8 *memset(u8 *dst, int value, u32 size);
extern void *lbl_801A6410;

typedef struct Fn1_680F8Arg {
    u8 pad_00[0x18];
    s16 unk_18;
    u16 unk_1a;
    u8 pad_1c[0x18];
    u32 unk_34;
    u8 *unk_38;
    u8 unk_3c[4];
} Fn1_680F8Arg;

typedef struct Fn1_680F8Entry {
    u8 pad_00[0x0c];
    u16 unk_0c;
    u8 pad_0e[0x0a];
    s16 unk_18;
    u8 pad_1a[0x1e];
    u8 *unk_38;
    u8 pad_3c[0xac];
} Fn1_680F8Entry;

void fn_1_680F8(Fn1_680F8Arg *arg) {
    u8 *p;
    Fn1_680F8Entry entry;
    u32 n;
    s32 i;

    arg->unk_1a = 0xffff;
{
    u8 *base;
    base = arg->unk_38;
    arg->unk_34 = fn_1_4630((u32)lbl_801A6410, 0x300, lbl_1_data_1D8A8, 0xc7);
    fn_1_862D4(arg->unk_18, arg->unk_3c);
    memset((u8 *)&entry, 0, 0xe8);
    entry.unk_18 = arg->unk_18;
    entry.unk_0c = 4;
    p = base;
}
    for (i = 0; i < 4; i++) {
        entry.unk_38 = p + 0x3b4;
        fn_1_58E3C(&entry);
        p += 0x30;
    }
    n = fn_1_58C4();
    for (i = 0; i < n; i++) {
        lbl_1_bss_6C878[i * 24] = -1;
    }
}
/* fzgx:end fn_1_680F8 */

/* fzgx:begin fn_1_68248 */
typedef struct Fn1_68248Arg {
    u8 pad0[0x34];
    void *unk_34;
} Fn1_68248Arg;

// Register the effect resource with the shared effect manager.
void fn_1_68248(Fn1_68248Arg *arg) {
    fn_1_46B4((u32)lbl_801A6410, arg->unk_34, lbl_1_data_1D8A8, 0xe2);
}
/* fzgx:end fn_1_68248 */

/* fzgx:begin fn_1_68B68 */
// Stub function that immediately returns.
void fn_1_68B68(void) {
}
/* fzgx:end fn_1_68B68 */

/* fzgx:begin fn_1_69BBC */
typedef struct EffectCar {
    u8 pad_00[0x1a];
    u16 field_1a;
} EffectCar;

void fn_1_69BBC(EffectCar *car) {
    car->field_1a = 0xffff;
}
/* fzgx:end fn_1_69BBC */

/* fzgx:begin fn_1_6D488 */
#include "dolphin/hw_regs.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
    s = 1.1920928955078125e-07f;
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table8[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table22[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
#pragma section code_type ".text"
struct Sig_fn_1_867CC_fn_1_867CC_Arg1 { u32 unk_0; u32 unk_4; u32 unk_8; };
struct fn_1_6D488_Arg0 { u8 pad_0[0x18]; s16 unk_18; };
extern s16 camera_get_mode(void);
extern u32 fn_1_867CC(u32, struct Sig_fn_1_867CC_fn_1_867CC_Arg1 *);
extern u8 *memset(u8 *, int, u32);
extern u32 fn_1_58C4(void);
extern u32 fn_1_584AC(void);
extern s32 fn_1_66B8(void *, f32);
extern u8 fn_1_86634(int);
extern s16 fn_1_59078(void *);
extern s16 fn_1_58F50(const void *);
extern void lbl_8006DC6C(void *);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E1B0(void *, void *);
#pragma opt_loop_invariants off
#pragma opt_propagation off
void fn_1_6D488(struct fn_1_6D488_Arg0 *arg0) {
    void * lab_t1;
    u16 count;
    struct { u32 a[58]; } loc_20;
    struct Sig_fn_1_867CC_fn_1_867CC_Arg1 loc_14;
    struct { f32 x,y,z; } loc_8;
    f32 z;
    f32 y;
    fn_1_867CC(arg0->unk_18, &loc_14);
    memset((u8 *)&loc_20, 0, 232);
    *(s16 *)((u8 *)&loc_20 + 24) = arg0->unk_18;
    *(u16 *)((u8 *)&loc_20 + 12) = 17;
    *(u16 *)((u8 *)&loc_20 + 26) = 65535;
    loc_20.a[2] |= 0x40000;
    if (fn_1_58C4() >= 2 || arg0->unk_18 != (s16)camera_get_mode()) count = 1;
    else count = 3;
    while (count) {
        *(s16 *)((u8 *)&loc_20 + 0x54) = fn_1_584AC();
        *(s16 *)((u8 *)&loc_20 + 0x56) = fn_1_584AC();
        *(s16 *)((u8 *)&loc_20 + 0x5a) = (s32)(768.0f + (f32)(768.0f * ((f32)(u16)fn_1_584AC() / 32767.0f)));
        *(s16 *)((u8 *)&loc_20 + 0x5c) = (s32)(768.0f + (f32)(768.0f * ((f32)(u16)fn_1_584AC() / 32767.0f)));
        if (!fn_1_66B8(&loc_14, 4.0f)) break;
        lbl_8006DC6C((u8 *)arg0 + 0xb8);
        {
            struct { f32 *base; } cache;
            f32 x = *(f32 *)&loc_14.unk_0;
            y = *(f32 *)&loc_14.unk_4;
            z = *(f32 *)&loc_14.unk_8;
            cache.base = (f32 *)LC_BASE;
            cache.base[3] = x;
            cache.base[7] = y;
            cache.base[11] = z;
        }
        mathutil_mtxA_rotate_y(*(s16 *)((u8 *)&loc_20 + 0x56));
        mathutil_mtxA_rotate_x(*(s16 *)((u8 *)&loc_20 + 0x54));
        {
            struct { f32 x,y,z; } velocity = {0.0f, 0.0f, -2.0f};
            lab_t1 = (u8 *)&loc_20 + 0x3c;
            lbl_8006E1B0(&velocity, lab_t1);
        }
        *(f32 *)((u8 *)&loc_20 + 0x28) = 4.0f;
        if ((s8)fn_1_86634(arg0->unk_18) != -1) fn_1_59078(&loc_20);
        else fn_1_58F50(&loc_20);
        count--;
    }
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_6D488 */

/* fzgx:begin fn_1_6D6A8 */
extern void fn_1_6F90C(void *arg0, void *arg1);
extern s16 fn_1_72318(void);
extern void fn_1_71D0C(void *arg0, void *arg1);

extern void *lbl_801A6410;
extern void fn_1_46B4(u32 value, void *field, u8 *data, s32 code);
extern u32 fn_1_4630(u32 value, u32 size, u8 *data, s32 code);
extern void fn_1_862D4(s16 value, void *result);
extern void fn_1_58E3C(void *entry);
extern u32 fn_1_58C4(void);
extern s8 lbl_1_bss_6C878[];
extern struct fn_1_6F404_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern void * fn_1_868C0(s8);
extern u32 fn_1_71024(void *, void *, u32, f32);
extern u32 fn_1_7099C(void *, void *, u32, f32, f32);
extern u32 fn_1_71768(void *, void *);
extern u32 fn_1_702A0(void *, void *, u32, u32);
extern u32 fn_80008C20(void *, void *, void *);
extern u32 lbl_8006E1C0(void *, void *);
extern u32 fn_1_584AC(void);
extern u32 fn_1_6FD58(void *, void *, f32, f32);
extern u32 fn_1_A33F0(u32, f32);
extern u32 fn_1_6D7BC(void *, void *, f32);
extern u32 fn_1_A5594(u32, void *);
extern u32 fn_1_714A8(void *, void *, u32, f32);

struct Fn1_6D6A8Car {
    u8 pad_00[0x18];
    s16 field_18;
};

struct Fn1_6D6A8Work {
    u8 pad_00[0x8];
    u32 field_08;
    s16 field_0c;
    u8 pad_0e[0xa];
    s16 field_18;
    u16 field_1a;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    u8 pad_2c[0x8];
    u32 field_34;
    u8 pad_38[0x4];
    f32 field_3c[3];
    u8 pad_48[0x68];
    u16 field_b0;
    u8 pad_b2[0x36];
};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
#pragma section code_type ".text"

// Spawn the car effect with a randomised brightness.
void fn_1_6D6A8(struct Fn1_6D6A8Car *car) {
    struct Fn1_6D6A8Work work;
    f32 t;
    f32 ratio;
    f32 scale;

    memset(&work, 0, sizeof(work));
    work.field_18 = car->field_18;
    work.field_0c = 0xe;
    work.field_1a = 0xffff;
    work.field_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x88);
    work.field_08 |= 0x40000;
    fn_1_867CC(car->field_18, work.field_3c);
    work.field_28 = 4.0f;
    work.field_b0 = 0;

    ratio = (f32)(u16)fn_1_584AC() / 32767.0f;
    scale = 0.2f * ratio;
    scale = 0.8f + scale;
    work.field_1c = (255.0f * (0.5f * (1.0f + scale))) / 255.0f;
    work.field_20 = (85.0f * scale) / 255.0f;
    work.field_24 = 0.0f;
    fn_1_59078(&work);
}
/* fzgx:end fn_1_6D6A8 */

/* fzgx:begin fn_1_6E140 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
    s = 1.1920928955078125e-07f;
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table8[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table22[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0xC0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 768.0f;
}
static const u32 fzgx_pool_table28[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_T;

typedef struct {
    u8 pad_00[0x0C];
    s16 unk_0C;
    u8 pad_0E[2];
    u32 unk_10;
    u8 pad_14[6];
    s16 unk_1A;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[4];
    Vec3_T unk_3C;
    Vec3_T unk_48;
    u8 pad_54[4];
    s16 unk_58;
    u8 pad_5A[0x8A];
} Loc_T;

typedef struct {
    u8 pad_0[0xE8];
    u32 unk_E8;
} Tgt_T;

extern s16 fn_1_58F50(const void *);
extern u32 fn_1_584AC(void);
extern u32 fn_1_58C4(void);
extern u8 * memset(u8 *, int, u32);

static inline f32 fn_1_6E140_operand(f32 right, f32 left) { return left + right; }
static inline f32 fn_1_6E140_operand_(f32 right, f32 left) { return left + right; }
#pragma opt_propagation off
void fn_1_6E140(Vec3_T *arg0, Vec3_T *arg1, f32 arg2) {
    f32 u;
    f32 t;
    f32 v;
    f32 w;

    if (fn_1_58C4() >= 3) {
        return;
    }
{
    Loc_T x;
    memset((u8 *)&x, 0, 0xE8);
    x.unk_1A = 3;
    x.unk_0C = 22;
    x.unk_34 = ((Tgt_T *)(u8 *)lbl_1_bss_38458->unk_8)->unk_E8;
    x.unk_3C = *arg0;
    x.unk_48 = *arg1;
    x.unk_3C.x = x.unk_3C.x - x.unk_48.x;
    x.unk_3C.y = x.unk_3C.y - x.unk_48.y;
    x.unk_3C.z = x.unk_3C.z - x.unk_48.z;
    t = (f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
    w = (f32)(0.2f * t);
    u = 0.8f + w;
    v = arg2 * u;
    x.unk_2C = 5.0f * v;
    x.unk_28 = 3.0f * v;
    t = (f32)(u32)(fn_1_584AC() & 0xFFFF) / 32767.0f;
    w = (f32)(0.2f * t);
    u = 0.8f + w;
    x.unk_1C = (255.0f * (0.5f * (1.0f + u))) / 255.0f;
    x.unk_20 = (224.0f * u) / 255.0f;
    x.unk_24 = (176.0f * u) / 255.0f;
    x.unk_58 = fn_1_584AC();
    x.unk_10 = 22;
    fn_1_58F50(&x);
}
}
#pragma opt_propagation reset
/* fzgx:end fn_1_6E140 */

/* fzgx:begin fn_1_6E320 noprologue */
#include "types.h"
#include "rel/main_rel/effect.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} EffVec;

typedef struct {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[0x3C - 0x1A];
    EffVec pos;
    u8 pad_48[0xB4 - 0x48];
    f32 unk_B4;
    u8 unk_B8[0x30];
} EffCar;

typedef struct {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x10 - 0xE];
    s32 unk_10;
    u8 pad_14[0x18 - 0x14];
    s16 unk_18;
    s16 unk_1A;
    u8 pad_1C[0x28 - 0x1C];
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x3C - 0x30];
    EffVec unk_3C;
    EffVec unk_48;
    u8 pad_54[0x9C - 0x54];
    f32 unk_9C;
    u8 pad_A0[0xB8 - 0xA0];
    u8 unk_B8[0x30];
} EffParticle;

extern f32 fn_1_8652C(int);
extern u32 fn_1_584AC(void);
extern s32 fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
extern s16 camera_get_mode(void);
extern s32 fn_1_58C4(void);
extern s16 fn_1_59078(Obj_1_bss_6C84C_Target *);
extern s16 fn_1_58F50(const void *);
extern u8 *memset(u8 *, int, u32);
extern void fn_8006F1F0(EffVec *, EffVec *, EffVec *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DD14(void *, void *);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[3] = {0x00000000, 0x3DCCCCCD, 0x40000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

static inline f32 CLAMP(f32 x, f32 lo, f32 hi) {
    return x < lo ? lo : (x > hi ? hi : x);
}

static inline f32 CLAMP2(f32 x, f32 lo, f32 hi) {
    if (x < lo) {
        return lo;
    }
    if (x > hi) {
        return hi;
    }
    return x;
}

#pragma fp_contract off
s16 fn_1_6E320(EffCar *car, EffVec *offset, u8 mode) {
    EffParticle part;
    EffVec pos;
    f32 speed;
    f32 ratio;
    f32 scale;
    f32 diff;
    f64 rnd;
    f32 fade;
    f32 clamped;

    speed = fn_1_8652C(car->unk_18);
    memset((u8 *)&part, 0, sizeof(part));
    part.unk_1A = 1;
    part.unk_C = 25;
    part.unk_18 = car->unk_18;
    diff = 1.8f - speed / 800.0f;
    part.unk_10 = (s32)(60.0f * (0.5f + (f32)(u16)fn_1_584AC() / 32767.0f) / 2.0f * CLAMP(diff, 0.2f, 1.8f));
    pos.x = car->pos.x + offset->x;
    pos.y = car->pos.y + offset->y;
    pos.z = car->pos.z + offset->z;
    if (mode == 1) {
        EffVec up = {0.0f, 1.0f, 0.0f};
        fn_8006F1F0(&car->pos, &up, &pos);
        lbl_8006DB74(part.unk_B8);
    } else {
        part.unk_48.z = 0.05f;
        lbl_8006DD14(car->unk_B8, part.unk_B8);
        if (fn_1_6EC0(0) != 0 && camera_get_entry_field_0xa4(0) == 0) {
            part.unk_9C -= 5.0f;
            part.unk_48.z = 0.0f;
        }
    }
    part.unk_3C.x -= part.unk_48.x;
    part.unk_3C.y -= part.unk_48.y;
    part.unk_3C.z -= part.unk_48.z;
    part.unk_28 = 2.0f;
    ratio = speed / 800.0f;
    scale = CLAMP(ratio, 0.4f, 1.8f);
#pragma fp_contract off
    rnd = 0.33333334f * (0.8f + (f64)(0.2 * ((f32)(u16)fn_1_584AC() / 32767.0f)));
    part.unk_2C = rnd * scale;
#pragma fp_contract on
    fade = speed / 1200.0f;
    car->unk_B4 = 0.5 * CLAMP2(fade, 0.0f, 1.0f);
    if (car->unk_18 == camera_get_mode() && (u32)fn_1_58C4() == 1) {
        return fn_1_59078((Obj_1_bss_6C84C_Target *)&part);
    }
    return fn_1_58F50(&part);
}
/* fzgx:end fn_1_6E320 */

/* fzgx:begin fn_1_6F288 noprologue */
#include "types.h"

extern s32 fn_1_864E8(s16 arg0);
extern void fn_1_867CC(s16 arg0, void *arg1);
extern s16 fn_1_58F50(const void *arg0);
extern u16 fn_1_584AC(void);
extern void *memset(void *dest, int value, u32 size);

struct EffectCar {
    u8 pad_00[0x18];
    s16 field_18;
    u8 pad_1a[0x1a];
    u32 field_34;
};

struct EffectData {
    u8 pad_00[0x08];
    u32 field_1c;
    u16 field_20;
    u8 pad_22[0x0a];
    s16 field_2c;
    u16 field_2e;
    u8 pad_30[0x1c];
    u32 field_4c;
    u8 pad_50[0x20];
    s16 field_70;
    u8 pad_72[0x3e];
    f32 field_b0;
    u8 pad_b4[0x48];
};

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
#pragma section code_type ".text"
void fn_1_6F288(struct EffectCar *arg0) {
    s32 result;
    u8 temp[0xc];
    struct EffectData data;
    f32 scale;

    result = fn_1_864E8(arg0->field_18);
    fn_1_867CC(arg0->field_18, temp);
    memset(&data, 0, 0xe8);
    data.field_2c = arg0->field_18;
    data.field_20 = 0x1c;
    data.field_2e = 0xffff;
    data.field_1c |= 0x2000;

    if (result & 8) {
        data.field_4c = arg0->field_34;
        data.field_b0 = 2.5f;
        fn_1_58F50(&data);
        data.field_b0 = -2.5f;
        fn_1_58F50(&data);
    } else {
        data.field_4c = arg0->field_34;
        data.field_b0 = 2.5f;
        scale = 1280.0f * ((f32)fn_1_584AC() / 32767.0f);
        data.field_70 = 4096.0f + scale;
        fn_1_58F50(&data);
        data.field_b0 = -2.5f;
        scale = 1280.0f * ((f32)fn_1_584AC() / 32767.0f);
        data.field_70 = 4096.0f + scale;
        fn_1_58F50(&data);
    }
}
/* fzgx:end fn_1_6F288 */

/* fzgx:begin fn_1_6F404 */
struct fn_1_6F404_lbl_1_rodata_2D70 {
    f32 unk_0;
    u8 pad_4[0x14];
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x8];
    f32 unk_28;
    u8 pad_2C[0x48];
    f32 unk_74;
    u8 pad_78[0x4];
    f32 unk_7C;
    u8 pad_80[0x10];
    f32 unk_90;
    u8 pad_94[0x18];
    f32 unk_AC;
    f32 unk_B0;
    u8 pad_B4[0x24];
    f32 unk_D8;
    u8 pad_DC[0x1BC];
    f32 unk_298;
    u8 pad_29C[0x74];
    u32 unk_310;
    u32 unk_314;
    u32 unk_318;
    f32 unk_31C;
    f32 unk_320;
};

void fn_1_6F404(void *arg0, void *arg1) {
    struct fn_1_6F404_lbl_1_rodata_2D70 *tbl;
    u32 sp[3];
    u16 rnd;
    f32 var_f31;
    f32 temp_f0;
    f32 temp_f1;
    void *temp_r30;
    void *temp_r27;
    void *unused;

    unused = arg1;
    tbl = &lbl_1_rodata_2D70;
    temp_r30 = (void *)(*(void **)((u8 *)(arg0) + 56));
    temp_r27 = (void *)(fn_1_868C0((s8)((s8) (*(s16 *)((u8 *)(arg0) + 24)))));
    if ((s16) (*(s16 *)((u8 *)(arg0) + 92)) == 0xA) {
        fn_1_71024((void *)(arg0), (void *)(arg1), (u32)(0x37U), (f32)(tbl->unk_31C));
        fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(0U), (f32)(tbl->unk_18), (f32)(tbl->unk_320));
    }
    if ((s16) (*(s16 *)((u8 *)(arg0) + 92)) == 5) {
        fn_1_71024((void *)(arg0), (void *)(arg1), (u32)(0x37U), (f32)(tbl->unk_31C));
        fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(0U), (f32)(tbl->unk_18), (f32)(tbl->unk_320));
        fn_1_71768((void *)(arg0), (void *)(arg1));
        fn_1_702A0((void *)(arg0), (void *)(arg1), (u32)(0x14U), (u32)(1U));
    }
    if (!((*(s32 *)((u8 *)(temp_r27) + 912)) & 0x01000000) && !((*(s32 *)((u8 *)(temp_r30) + 1420)) & 0x10)) {
        if (!((*(s32 *)((u8 *)(temp_r30) + 0)) & 2)) {
            temp_f1 = *(f32 *)((u8 *)(temp_r30) + 380);
            if (temp_f1 > tbl->unk_320) {
                temp_f0 = temp_f1 / tbl->unk_298;
                sp[0] = tbl->unk_310;
                sp[1] = tbl->unk_314;
                sp[2] = tbl->unk_318;
                var_f31 = tbl->unk_0;
                if (temp_f0 < var_f31) {
                    var_f31 = tbl->unk_0;
                } else if (temp_f0 > tbl->unk_74) {
                    var_f31 = tbl->unk_74;
                } else {
                    var_f31 = temp_f0;
                }
                fn_80008C20((void *)((u8 *)(temp_r30) + 0x7C), (void *)(arg1), (void *)((u8 *)(arg0) + 0x48));
                lbl_8006E1C0((void *)(sp), (void *)(sp));
                rnd = (s32)(u16) fn_1_584AC();
                if ((rnd % 6) == 0) {
                    fn_1_6FD58((void *)(arg0), (void *)(sp), (f32)(var_f31), (f32)(tbl->unk_1C));
                }
                fn_1_A33F0((u32)((u32) (*(s16 *)((u8 *)(temp_r30) + 4))), (f32)(tbl->unk_1C * var_f31));
                if (((u16) (*(u16 *)((u8 *)(temp_r30) + 1248)) < 0x32U)) {
                    rnd = (s32) fn_1_584AC();
                    if ((rnd % 10) == 0) {
                        fn_1_702A0((void *)(arg0), (void *)(sp), (u32)(1U), (u32)(0U));
                    }
                }
            }
        }
        if ((*(s32 *)((u8 *)(temp_r30) + 1420)) & 0x80) {
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 80) == 0) {
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
                fn_1_6FD58((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_D8), (f32)(tbl->unk_90));
                if ((s8) (*(u8 *)((u8 *)(temp_r30) + 1141)) >= 0) {
                    fn_1_A5594((u32)(0xA9092A00U), (void *)((u8 *)(arg0) + 0x3C));
                }
            }
        } else if ((s8) (*(u8 *)((u8 *)(temp_r30) + 1141)) != -1) {
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                if ((s8) (*(u8 *)((u8 *)(temp_r30) + 1141)) >= 0) {
                    fn_1_A5594((u32)(0xA9092A00U), (void *)((u8 *)(arg0) + 0x3C));
                }
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_714A8((void *)(arg0), (void *)(arg1), (u32)(0x16U), (f32)(tbl->unk_B0));
            }
        } else {
            rnd = (s32) fn_1_584AC();
            if ((rnd % 10) == 0) {
                fn_1_6D7BC((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_AC));
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 5) == 0) {
                fn_1_7099C((void *)(arg0), (void *)(arg1), (u32)(1U), (f32)(tbl->unk_7C), (f32)(tbl->unk_28));
            }
            rnd = (s32) fn_1_584AC();
            if ((rnd % 20) == 0) {
                fn_1_6FD58((void *)(arg0), (void *)(arg1), (f32)(tbl->unk_D8), (f32)(tbl->unk_90));
            }
        }
    }
}
/* fzgx:end fn_1_6F404 */

/* fzgx:begin fn_1_6F8D0 */
void fn_1_6F8D0(void *arg0, void *arg1) {
    struct EffectData {
        u8 pad_000[0x58c];
        u32 field_58c;
    };
    struct EffectCar {
        u8 pad_00[0x38];
        struct EffectData *field_38;
        u8 pad_3c[0x76];
        u16 field_b2;
    };
    struct EffectCar *self = (struct EffectCar *)arg0;

    if ((self->field_38->field_58c & 0x10) != 0 && self->field_b2 == 0) {
        fn_1_6F90C(arg0, arg1);
    }
}
/* fzgx:end fn_1_6F8D0 */

/* fzgx:begin fn_1_6F90C noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

struct EffectCarData {
    u32 flags;
    s16 field_4;
    u8 pad_6[0x475 - 6];
    s8 field_475;
};

struct EffectCar {
    u8 pad_00[0x38];
    struct EffectCarData *data;
    Vec3f pos;
    u8 pad_48[0x5c - 0x48];
    u16 field_5c;
    u8 pad_5e[0xb2 - 0x5e];
    u16 field_b2;
};

/* Pool primer: reproduces the TU literal pool layout ahead of this function. */
#pragma section RX ".fzgxpool"

static const u32 fzgx_pool_table_000[6] = {
    0x00000000, 0xBF800000, 0x41C80000, 0x41700000, 0x41000000, 0x43160000,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_018(f32 *f) {
    f[0] = 10.0f;
}
static const u32 fzgx_pool_table_01C[2] = {0x3F000000, 0x3E000000};
__declspec(section ".fzgxpool") void fzgx_pool_primer_024(f32 *f) {
    f[0] = 32767.0f;
}
static const u32 fzgx_pool_table_028[4] = {0x41F00000, 0x41A00000, 0x44960000, 0x3E19999A};
__declspec(section ".fzgxpool") void fzgx_pool_primer_038(f32 *f, s32 n) {
    f[0] = (f32)n;
}
static const u32 fzgx_pool_table_040[7] = {
    0x43300000, 0x00000000, 0x437F0000, 0x42CC0000, 0x3FE99999, 0x9999999A, 0x3FCCCCCD,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_05C(f32 *f) {
    f[0] = 3.0f;
}
static const u32 fzgx_pool_table_060[13] = {
    0x3C23D70A, 0x3F19999A, 0x3FD33333, 0x33333333, 0x3F333333, 0x3E4CCCCD, 0x3ECCCCCD,
    0x3DCCCCCD, 0x3FC00000, 0x00000000, 0x40000000, 0x00000000, 0x3F4CCCCD,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_094(f32 *f) {
    f[0] = 1.0f;
}
static const u32 fzgx_pool_table_098[21] = {
    0x42AA0000, 0x3E800000, 0x00000000, 0x00000000, 0x00000000, 0x42C80000, 0x40600000,
    0x41B80000, 0x42700000, 0x40800000, 0x34000000, 0x43080000, 0x3CF5C28F, 0x00000000,
    0x3FE00000, 0x00000000, 0x3E99999A, 0x43000000, 0x43600000, 0x43FA0000, 0x3F6E147B,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_0EC(f32 *f) {
    f[0] = 5.0f;
}
static const u32 fzgx_pool_table_0F0[36] = {
    0x40000000, 0x3D4CCCCD, 0x3DA3D70A, 0x3F666666, 0x3FD33333, 0x40000000, 0x3FC99999,
    0x9999999A, 0xBFD33333, 0x33333333, 0xBFF00000, 0x00000000, 0x00000000, 0x00000000,
    0x403E0000, 0x00000000, 0x40080000, 0x00000000, 0x3A83126F, 0x3B03126F, 0x3FF33333,
    0x461C4000, 0x453B8000, 0x43360B61, 0x3F109091, 0x3F30B0B1, 0x4066C16C, 0x20000000,
    0x40140000, 0x00000000, 0x3FE3851E, 0xB851EB85, 0x46800000, 0x00000000, 0x3DCCCCCD,
    0x3FC00000,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_180(f32 *f) {
    f[0] = 800.0f;
}
static const u32 fzgx_pool_table_184[102] = {
    0x447A0000, 0x3FA99999, 0x9999999A,
    0x40280000, 0x00000000, 0xBFC47AE1, 0x47AE147B,
    0x405DC000, 0x00000000, 0x40040000, 0x00000000,
    0x3FF00000, 0x00000000, 0x449C4000, 0x00000000,
    0x3FD99999, 0x9999999A, 0x43960000, 0x00000000,
    0x3FC99999, 0xA0000000, 0x451C4000, 0x459C4000,
    0x3FB99999, 0x9999999A, 0x40490000, 0x00000000,
    0x3F33A92A, 0x30553261, 0x3F947AE1, 0x47AE147B,
    0x3F99999A, 0x00000000, 0x3FE33333, 0x33333333,
    0x42300000, 0x00000000, 0x3FF4CCCC, 0xCCCCCCCD,
    0x3A03126F, 0x00000000, 0x3F689374, 0xBC6A7EFA,
    0x469C4000, 0x00000000, 0x3F800000, 0x3F000000,
    0x42080000, 0x00000000, 0x40240000, 0x00000000,
    0x00000000, 0x00000000, 3221225472u, 0x44400000,
    0x00000000, 0x00000000, 0x00000000, 0x41800000,
    0x45800000, 0x40C00000, 0x44E38E39, 0x42EE0000,
    0x424C0000, 0x00000000, 0x3DCCCCCD, 0x00000000,
    0x40200000, 0x43C80000, 0x44FA0000, 0x43300000,
    0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000,
    0x3F800000, 0x00000000, 0x3FE66666, 0x00000000,
    0x3FD55555, 0x60000000, 0x3FE99999, 0xA0000000,
    0x00000000, 0xBF000000, 0x3FA66666, 0xBF99999A,
    0x44BB8000, 0x00000000, 0x3FD99999, 0xA0000000,
    0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000,
    0x40440000, 0x00000000, 3223322624u, 0x44A00000,
    0x00000000, 0x3ECCCCCD, 0x3F800000,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer_31C(f32 *f) {
    f[0] = 2.7f;
    f[1] = 50.0f;
}

extern u32 lbl_801A63C0;

extern f32 lbl_8006D0B4(f32);
extern s32 fn_1_58C4(void);
extern u32 fn_1_6FD58(void *, void *, f32, f32);
extern u32 fn_1_7099C(void *, void *, u32, f32, f32);
extern u32 fn_1_71024(void *, void *, u32, f32);
extern u32 fn_1_71768(void *, void *);
extern u32 fn_1_A5594(u32, void *);
extern void fn_1_681C(u8, Vec3f *);
extern u32 fn_1_702A0(void *, void *, u32, u32);
extern void fn_1_A2D84(u32);
extern void game_camera_set_shake(s16, s16, s32, const Vec3f *);
extern void lbl_8006D5F0(Vec3f *, Vec3f *, f32);

#define EFFECT_RAND() \
    (lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB, (s32)((lbl_801A63C0 >> 16) & 0x7FFF))

static inline f32 effect_distance(Vec3f *a, Vec3f *b) {
    f32 dx = a->x;
    f32 dy = a->y;
    f32 dz = a->z;
    f32 sum;

    dx -= b->x;
    dy -= b->y;
    dz -= b->z;

    sum = dx * dx;
    sum += dy * dy;
    sum += dz * dz;
    return lbl_8006D0B4(sum);
}

static inline f32 effect_clamp(f32 v, f32 lo, f32 hi) {
    f32 r;
    if (v < lo) {
        r = lo;
    } else if (v > hi) {
        r = hi;
    } else {
        r = v;
    }
    return r;
}

void fn_1_6F90C(struct EffectCar *self, void *arg1) {
    struct EffectCarData *data = self->data;
    Vec3f shake;
    u32 count;
    u32 i;
    f32 scale;
    f32 min;
    f32 t;
    f32 a;
    f32 b;

    if (data->flags & 1) {
        return;
    }
    self->field_5c = 15;
    self->field_b2 = 1;
    if (data->field_475 >= 0) {
        Vec3f dir = {0.0f, 0.0f, 0.0f};
        dir.x = EFFECT_RAND() / 32767.0f;
        dir.y = EFFECT_RAND() / 32767.0f;
        dir.z = EFFECT_RAND() / 32767.0f;
        shake = dir;
        lbl_8006D5F0(&shake, &shake, 3.0f);
        game_camera_set_shake(data->field_475, data->field_4,
                              72.0f * (1.0f + EFFECT_RAND() / 32767.0f), &shake);
        fn_1_A2D84(0xA9093000);
    } else {
        fn_1_A5594(0xA9092F00, &self->pos);
    }
    fn_1_71024(self, arg1, 0x37, 5.7f);
    fn_1_702A0(self, arg1, 0x14, 1);
    if (data->field_475 != -1) {
        Vec3f pos;

        count = fn_1_58C4();
        fn_1_681C(0, &pos);
        min = effect_distance(&self->pos, &pos);
        for (i = 1; i < count; i++) {
            fn_1_681C(i, &pos);
            if (min < effect_distance(&self->pos, &pos)) {
                min = min;
            } else {
                min = effect_distance(&self->pos, &pos);
            }
        }
        t = 50.0f * (min / 800.0f);
        scale = effect_clamp(t, 1.0f, 50.0f);
    } else {
        scale = 1.0f;
    }
    if (data->flags & 0x40000000) {
        fn_1_71024(self, arg1, 0x37, 2.7f);
        fn_1_7099C(self, arg1, 0, 10.0f, 50.0f);
        fn_1_71768(self, arg1);
        fn_1_702A0(self, arg1, 0x14, 1);
    }
    a = 5.0f * scale;
    b = 50.0f * scale;
    fn_1_7099C(self, arg1, 0, a, b);
    fn_1_7099C(self, arg1, 0, a, b);
    fn_1_7099C(self, arg1, 0, a, b);
    fn_1_6FD58(self, arg1, 1.0f, 1.0f);
    fn_1_6FD58(self, arg1, 1.0f, 1.0f);
    fn_1_6FD58(self, arg1, 1.0f, 1.0f);
}
/* fzgx:end fn_1_6F90C */

/* fzgx:begin fn_1_6FD58 noprologue */
#include "types.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
    s = 1.1920928955078125e-07f;
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table8[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table22[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table24[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table26[3] = {0x00000000, 0x00000000, 0xC0000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 768.0f;
}
static const u32 fzgx_pool_table28[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table32[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table34[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table40[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
static const u32 fzgx_pool_table42[3] = {0x00000000, 0x3ECCCCCD, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.700000047683716f;
    s = 50.0f;
}
static const u32 fzgx_pool_table44[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const u32 *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime45(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 72.0f;
    s = 5.699999809265137f;
    d = 0.10000000149011612;
    d = 1.399999976158142;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_80008C20_fn_80008C20_Vec;

typedef struct {
    u32 a;
    u32 b;
} Struct_1_6FD58_pair48;

typedef struct {
    u8 pad_00[0x18];
    s16 field_18;
    u16 field_1a;
    f32 field_1c;
    f32 field_20;
    f32 field_24;
    u8 pad_28[0x14];
    f32 field_3c;
    f32 field_40;
    f32 field_44;
    Struct_1_6FD58_pair48 field_48;
    u32 field_50;
    u8 pad_54[0x64];
    u8 field_b8[0x30];
} Struct_1_6FD58;

extern u8 * memset(u8 *, int, u32);
extern u32 fn_1_584AC(void);
extern u32 fn_1_6CF3C(void *, Sig_fn_80008C20_fn_80008C20_Vec *, f32, f32);
extern void lbl_8006DD14(u32, void *);

#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
#pragma opt_lifetimes on
void fn_1_6FD58(Struct_1_6FD58 *arg0, Sig_fn_80008C20_fn_80008C20_Vec *arg1, f32 arg2, f32 arg3) {
    Struct_1_6FD58 s;
    s32 i;
    f32 scale;
    f64 m;

    memset((u8 *)&s, 0, sizeof(s));
    s.field_18 = arg0->field_18;
    s.field_1a = 0xFFFF;
    s.field_1c = 136.0f;
    s.field_20 = 136.0f;
    s.field_24 = 0.0f;
    s.field_48 = arg0->field_48;
    s.field_50 = arg0->field_50;
    lbl_8006DD14((u32)((u8 *)arg0 + 0xb8), (void *)&s.field_b8);
    for (i = 0; i < 2; i++) {
        s.field_3c = arg0->field_3c + ((u16)fn_1_584AC() / 32767.0f - 0.5);
        s.field_40 = arg0->field_40 + ((u16)fn_1_584AC() / 32767.0f - 0.5);
        s.field_44 = arg0->field_44 + ((u16)fn_1_584AC() / 32767.0f - 0.5);
        m = 0.5 * ((u16)fn_1_584AC() / 32767.0f);
        scale = arg2 * (0.1f * (m + 0.5));
        m = 0.5 * ((u16)fn_1_584AC() / 32767.0f);
        fn_1_6CF3C(&s, arg1, scale, arg3 * (1.4f * (m + 0.5)));
    }
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_strength_reduction reset
/* fzgx:end fn_1_6FD58 */

/* fzgx:begin fn_1_6FFA0 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn6FFA0Vec;

typedef struct Fn6FFA0Car {
    u8 pad_00[0x18];
    s16 unk_18;
    u8 pad_1a[0x9e];
    u8 unk_b8[4];
} Fn6FFA0Car;

typedef struct Fn6FFA0Work {
    u8 pad_00[0xc];
    s16 unk_0c;
    u8 pad_0e[2];
    u32 unk_10;
    u8 pad_14[4];
    s16 unk_18;
    u16 unk_1a;
    u8 pad_1c[0xc];
    f32 unk_28;
    f32 unk_2c;
    u8 pad_30[0xc];
    Fn6FFA0Vec unk_3c;
    u8 pad_48[0xc];
    s16 unk_54;
    s16 unk_56;
    u8 pad_58[2];
    s16 unk_5a;
    s16 unk_5c;
    u8 pad_5e[0x8a];
} Fn6FFA0Work;

extern void *memset(void *dest, int value, u32 size);
extern void fn_1_867CC(s16 arg0, void *arg1);
extern u32 fn_1_58C4(void);
extern s16 camera_get_mode(void);
extern u16 fn_1_584AC(void);
extern s32 fn_1_66B8(void *arg0, f32 arg1);
extern void lbl_8006DC6C(void *arg0);
extern void mathutil_mtxA_rotate_y(s16 angle);
extern void mathutil_mtxA_rotate_x(s16 angle);
extern void lbl_8006E1B0(Fn6FFA0Vec *arg0, Fn6FFA0Vec *arg1);
extern s16 fn_1_59078(void *arg0);
extern u32 lbl_801A63C0;
/* Set the translation column of the current matrix (locked cache). */
static inline void fn_1_6FFA0_set_translate(f32 x, f32 y, f32 z) {
    *(f32 *)(0xE0000000 + 0x0C) = x;
    *(f32 *)(0xE0000000 + 0x1C) = y;
    *(f32 *)(0xE0000000 + 0x2C) = z;
}

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
    s = 1000.0f;
    d = 0.05;
    d = 12.0;
    d = -0.16;
    d = 119.0;
    d = 2.5;
    d = 1.0;
    s = 1250.0f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4;
    s = 300.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.20000000298023224;
    s = 2500.0f;
    s = 5000.0f;
    d = 0.1;
    d = 50.0;
    d = 0.0003;
    d = 0.02;
    s = 1.2000000476837158f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6;
    s = 44.0f;
}
static const u32 fzgx_pool_table20[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.3;
    s = 0.0005000000237487257f;
}
static const u32 fzgx_pool_table22[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const u32 *volatile cp; cp = fzgx_pool_table22; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.003;
    s = 20000.0f;
}
static const u32 fzgx_pool_table24[3] = {0x00000000, 0x3F800000, 0x3F000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const u32 *volatile cp; cp = fzgx_pool_table24; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime25(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 34.0f;
}
static const u32 fzgx_pool_table26[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep26(void) { const u32 *volatile cp; cp = fzgx_pool_table26; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime27(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 10.0;
}
static const u32 fzgx_pool_table28[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep28(void) { const u32 *volatile cp; cp = fzgx_pool_table28; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime29(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -2.0f;
    s = 768.0f;
}
static const u32 fzgx_pool_table30[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep30(void) { const u32 *volatile cp; cp = fzgx_pool_table30; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime31(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 16.0f;
    s = 4096.0f;
    s = 6.0f;
    s = 1820.4444580078125f;
    s = 119.0f;
    s = 51.0f;
}
static const u32 fzgx_pool_table32[3] = {0x00000000, 0x3DCCCCCD, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep32(void) { const u32 *volatile cp; cp = fzgx_pool_table32; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
    s = 400.0f;
    s = 2000.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table34[6] = {0x00000000, 0x3DCCCCCD, 0x40000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const u32 *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime35(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.7999999523162842f;
}
static const u32 fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const u32 *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime37(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3333333432674408;
    d = 0.800000011920929;
}
static const u32 fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const u32 *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime39(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 1.2999999523162842f;
    s = -1.2000000476837158f;
    s = 1500.0f;
}
static const u32 fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const u32 *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime41(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.4000000059604645;
}
static const u32 fzgx_pool_table42[4] = {0x00000000, 0x3DCCCCCD, 0x3FC00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep42(void) { const u32 *volatile cp; cp = fzgx_pool_table42; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime43(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 40.0;
    s = -2.5f;
    s = 1280.0f;
}
static const u32 fzgx_pool_table44[14] = {0, 0x3ECCCCCD, 0x3F800000, 0x402CCCCD, 0x42480000, 0, 0, 0, 0x42900000, 0x40B66666, 0x3FB99999, 0xA0000000, 0x3FF66666, 0x60000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep44(void) { const u32 *volatile cp; cp = fzgx_pool_table44; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* Inline LCG used by the effect code: next 15-bit random value. */
#define FN6FFA0_RAND() \
    (lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB, (s32)((lbl_801A63C0 >> 16) & 0x7FFF))

#pragma opt_loop_invariants off
#pragma opt_propagation off
void fn_1_6FFA0(Fn6FFA0Car *car, u32 arg1, u32 arg2) {
    Fn6FFA0Vec pos;
    Fn6FFA0Vec dir;
    Fn6FFA0Work work;
    Fn6FFA0Vec tmp;
    register f32 *matrix;
    Fn6FFA0Vec *velocity;
    u16 n;
    u32 random;

    fn_1_867CC(car->unk_18, &pos);
    memset(&work, 0, sizeof(work));
    work.unk_18 = car->unk_18;
    work.unk_0c = 0x21;
    work.unk_1a = 0xffff;
    work.unk_10 = arg2;
    if (fn_1_58C4() >= 2 || car->unk_18 != camera_get_mode()) {
        n = 2;
    } else {
        n = 3;
    }
    goto setup; /* fzgx-allow: S1 shared loop-entry setup is laid out after the loop in retail */
loop:
    for (; n != 0; n--) {
        work.unk_28 = 0.2f;
        random = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        lbl_801A63C0 = random;
        work.unk_2c = 1.2f * (0.5f + (f32)(0.5f * ((f32)(s32)((random >> 16) & 0x7fff) / 32767.0f)));
        work.unk_54 = fn_1_584AC();
        work.unk_56 = fn_1_584AC();
        work.unk_5a = 256.0f + (f32)(1024.0f * ((f32)fn_1_584AC() / 32767.0f));
        work.unk_5c = 256.0f + (f32)(1024.0f * ((f32)fn_1_584AC() / 32767.0f));
        if (fn_1_66B8(&pos, 4.0f) == 0) {
            return;
        }
        lbl_8006DC6C(car->unk_b8);
        {
            {
                f32 fzgx_lc0_z;
                f32 fzgx_lc0_y;
                f32 fzgx_lc0_x;
                fzgx_lc0_x = *(volatile f32 *)&(pos.x); /* fzgx-allow: S2 preserve locked-cache column load order */
                fzgx_lc0_y = (pos.y);
                fzgx_lc0_z = (pos.z);
                matrix = (f32 *)0xE0000000; /* fzgx-allow: A2 locked-cache current matrix address */
                matrix[3] = fzgx_lc0_x;
                matrix[7] = fzgx_lc0_y;
                matrix[11] = fzgx_lc0_z;
            }
        }
        mathutil_mtxA_rotate_y(work.unk_56);
        mathutil_mtxA_rotate_x(work.unk_54);
        {
            Fn6FFA0Vec tmp = {0.0f, 0.0f, 0.0f};

            tmp.z = 3.0f * -((f32)FN6FFA0_RAND() / 32767.0f);
            dir = tmp;
        }
        lbl_8006E1B0(&dir, velocity);
        fn_1_59078(&work);
    }
    return;
setup:
    velocity = &work.unk_3c;
    goto loop; /* fzgx-allow: S1 return from shared loop-entry setup */
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_1_6FFA0 */

/* fzgx:begin fn_1_71024 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/effect_car.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -1.0f;
    s = 25.0f;
    s = 15.0f;
    s = 8.0f;
    s = 150.0f;
    s = 10.0f;
    s = 0.5f;
    s = 0.125f;
    s = 32767.0f;
    s = 30.0f;
    s = 20.0f;
    s = 1200.0f;
    s = 0.15000000596046448f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
    s = 255.0f;
    s = 102.0f;
    d = 0.8;
    s = 1.600000023841858f;
    s = 3.0f;
    s = 0.009999999776482582f;
    s = 0.6000000238418579f;
    d = 0.3;
    s = 0.699999988079071f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 0.10000000149011612f;
    s = 1.5f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 2.0;
    s = 0.800000011920929f;
    s = 1.0f;
    s = 85.0f;
    s = 0.25f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 100.0f;
    s = 3.5f;
    s = 23.0f;
    s = 60.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table6[1] = {0x34000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.5;
    s = 0.30000001192092896f;
    s = 128.0f;
    s = 224.0f;
    s = 500.0f;
    s = 0.9300000071525574f;
    s = 5.0f;
    s = 2.0f;
    s = 0.05000000074505806f;
    s = 0.07999999821186066f;
    s = 0.8999999761581421f;
    d = 0.30000001192092896;
    d = 0.2;
    d = -0.3;
    d = -1.0;
    d = 0.0;
    d = 30.0;
    d = 3.0;
    s = 0.0010000000474974513f;
    s = 0.0020000000949949026f;
    s = 1.899999976158142f;
    s = 10000.0f;
    s = 3000.0f;
    s = 182.04444885253906f;
    s = 0.5647059082984924f;
    s = 0.6901960968971252f;
    s = 3.605555534362793f;
}
static const u32 fzgx_pool_table10[1] = {0x20000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 5.0;
    s = 1.7774999141693115f;
    s = -5.004882768844254e-05f;
    s = 16384.0f;
}
static const u32 fzgx_pool_table12[3] = {0x00000000, 0x3DCCCCCD, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 800.0f;
}
#pragma section code_type ".text"

typedef struct Fn1_71024Vec {
    f32 x, y, z;
} Fn1_71024Vec;

typedef struct Fn1_71024Car {
    u8 pad_00[0x18];
    s16 unk_18;
    u8 pad_1a[0x1e];
    u8 *unk_38;
    Fn1_71024Vec pos;
    Fn1_71024Vec vel;
} Fn1_71024Car;

typedef struct Fn1_71024Work {
    u8 pad_00[0xc];
    s16 unk_0c;
    u8 pad_0e[0x2];
    s32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u16 unk_1a;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2c;
    u8 pad_30[0x4];
    u32 unk_34;
    u8 pad_38[0x4];
    Fn1_71024Vec pos;
    Fn1_71024Vec vel;
    u8 pad_54[0x4];
    u16 unk_58;
    u8 pad_5a[0x5a];
    f32 unk_b4;
    u8 pad_b8[0x30];
} Fn1_71024Work;

extern void *memset(void *dest, int value, u32 size);
extern u16 fn_1_584AC(void);
extern s16 fn_1_59078(void *arg0);
extern u32 fn_1_58C4(void);
extern void fn_1_681C(u8 index, Fn1_71024Vec *pos);
extern f32 lbl_8006D0B4(f32);

static inline f32 fn_1_71024_dist(Fn1_71024Car *car, Fn1_71024Vec *p) {
    f32 dx = car->pos.x;
    f32 dy = car->pos.y;
    f32 dz = car->pos.z;
    f32 sq;
    dx -= p->x;
    dy -= p->y;
    dz -= p->z;
    sq = dx * dx;
    sq += dy * dy;
    sq += dz * dz;
    return lbl_8006D0B4(sq);
}
/* Random offset in [-1, 1]. */
static inline f64 fn_1_71024_jitter(void) {
    return 2.0 * ((f32)fn_1_584AC() / 32767.0f - 0.5);
}

static inline f32 fn_1_71024_clamp(f32 v, f32 lo, f32 hi) {
    return (v < lo) ? lo : ((v > hi) ? hi : v);
}

#define FN_1_71024_DIST(car, p) fn_1_71024_dist(car, &(p))
#define FN_1_71024_SCALE(d) (10.0f * ((d) / 800.0f))

void fn_1_71024(Fn1_71024Car *car, Fn1_71024Vec *vel, u32 count, f32 scale) {
    Fn1_71024Vec point;
    Fn1_71024Work work;
    u8 *owner;
    f32 ratio;
    f32 s;
    f32 t;
    f32 r;
    f32 min;
    u32 n;
    u32 i;

    owner = car->unk_38;
    memset(&work, 0, sizeof(work));
    work.unk_1a = 0xffff;
    work.unk_18 = car->unk_18;
    work.unk_0c = 0x22;
    if (fn_1_584AC() % 2) {
        work.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x50);
    } else {
        work.unk_34 = *(u32 *)(lbl_1_bss_38458->unk_8 + 0x58);
    }
    work.pos.x = car->pos.x + fn_1_71024_jitter();
    work.pos.y = car->pos.y + fn_1_71024_jitter();
    work.pos.z = car->pos.z + fn_1_71024_jitter();
    work.vel = car->vel;
    work.vel.x += (f32)(0.5f * vel->x);
    work.vel.y += (f32)(0.5f * vel->y);
    work.vel.z += (f32)(0.5f * vel->z);
    work.pos.x -= work.vel.x;
    work.pos.y -= work.vel.y;
    work.pos.z -= work.vel.z;

    ratio = (f32)fn_1_584AC() / 32767.0f;
    s = 0.2f * ratio;
    s = 0.8f + s;
    work.unk_2c = scale * s;
    work.unk_28 = 0.2f * s;

    ratio = (f32)fn_1_584AC() / 32767.0f;
    s = 0.2f * ratio;
    s = 0.8f + s;
    work.unk_1c = (255.0f * (0.5f * (1.0f + s))) / 255.0f;
    work.unk_20 = (136.0f * s) / 255.0f;
    work.unk_24 = 0.0f;

    work.unk_58 = fn_1_584AC();
    ratio = (f32)fn_1_584AC() / 32767.0f;
    s = 0.2f * ratio;
    s = 0.8f + s;
    work.unk_10 = (s16)(s * (f32)count);

    if ((s8)owner[0x475] != -1) {
        n = fn_1_58C4();
        fn_1_681C(0, &point);
        min = FN_1_71024_DIST(car, point);
        for (i = 1; i < n; i++) {
            fn_1_681C(i, &point);
            if (min < FN_1_71024_DIST(car, point)) {
                min = min;
            } else {
                min = FN_1_71024_DIST(car, point);
            }
        }
        /* clamp 10 * min / 800 to [1, 10] */
        r = 1.0f;
        r = (FN_1_71024_SCALE(min) < r) ? r
          : (FN_1_71024_SCALE(min) > 10.0f) ? 10.0f
          : FN_1_71024_SCALE(min);
        work.unk_b4 = r;
    } else {
        work.unk_b4 = 1.0f;
    }
    fn_1_59078(&work);
}
/* fzgx:end fn_1_71024 */

/* fzgx:begin fn_1_71CA0 */
void fn_1_71CA0(void *arg0, void *arg1, u16 arg2) {
    if (arg2 == 0xb4) {
        ((struct {
            u8 pad[0x58];
            s16 field_58;
        } *)arg0)->field_58 = fn_1_72318();
    }
    if (arg2 == 0xaa) {
        fn_1_71D0C(arg0, arg1);
    }
}
/* fzgx:end fn_1_71CA0 */

/* fzgx:begin fn_1_72318 noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

extern void fn_1_867CC(s16 arg0, void *arg1);
extern u32 lbl_1_rodata_314C[13];
extern void lbl_8006DC6C(void *arg0, u32 arg1);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern s16 fn_1_59078(void *arg0);
extern void *memset(void *dest, int value, u32 size);

struct EffectCar {
    u8 pad_18[0x18];
    s16 field_18;
    u8 pad_1a[0x1e];
    u32 field_38;
    u8 pad_3c[0x7c];
    u8 field_b8;
};

struct EffectWorkData {
    u8 pad_00[0xc];
    s16 field_0c;
    u8 pad_0e[0xa];
    s16 field_18;
    u16 field_1a;
    u8 pad_1c[0x1c];
    u32 field_38;
    u32 field_3c;
    u32 field_40;
    u32 field_44;
    u8 pad_48[0x14];
    s16 field_5c;
    u8 pad_5e[0x8a];
};

#pragma opt_propagation off
s16 fn_1_72318(struct EffectCar *arg0) {
    f32 vec[3];
    struct EffectWorkData data;
    u32 lab_t0;
    f32 v0, v1, v2;

    lab_t0 = arg0->field_18;

    fn_1_867CC(lab_t0, vec);
    memset(&data, 0, sizeof(data));

    data.field_18 = arg0->field_18;
    data.field_0c = 0x25;
    data.field_38 = arg0->field_38;
    data.field_1a = 0xffff;
    lbl_8006DC6C(&arg0->field_b8, data.field_38);

    v2 = vec[0];
    v1 = vec[1];
    v0 = vec[2];

    // These are effect-engine scratch registers used to pass the generated vector.
    // fzgx-allow: A2 hardware scratch register addresses are encoded by the target.
    *(volatile f32 *)(LC_BASE + 0xC) = v2;
    // fzgx-allow: A2 hardware scratch register addresses are encoded by the target.
    *(volatile f32 *)(LC_BASE + 0x1C) = v1;
    // fzgx-allow: A2 hardware scratch register addresses are encoded by the target.
    *(volatile f32 *)(LC_BASE + 0x2C) = v0;

    data.field_3c = lbl_1_rodata_314C[0];
    data.field_40 = lbl_1_rodata_314C[1];
    data.field_44 = lbl_1_rodata_314C[2];
    lbl_8006E1B0(&data.field_3c, &data.field_3c);

    data.field_5c = 0x100;
    return fn_1_59078(&data);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_72318 */
