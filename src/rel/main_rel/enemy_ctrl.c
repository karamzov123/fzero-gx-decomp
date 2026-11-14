#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u32 lbl_1_bss_7AC48[5];
extern void *lbl_801A6410;
extern void fn_1_46B4(void *, u32, void *, u32);
extern void fn_1_C489C(void);
extern u32 lbl_1_bss_7AC54[4];
extern u8 lbl_1_bss_7AC90[12];
extern u32 lbl_1_rodata_5D40[7];
extern u32 fn_1_5910(void *);
extern u8 fn_1_86810(void *);
extern u32 fn_1_3F7E0(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(u32);
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5D18;
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(u32);
extern void fn_1_49728(u32);
extern void fn_1_4AE0C(void *, ...);
extern const f32 lbl_1_rodata_5D5C;
extern const f32 lbl_1_rodata_5D60;
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_5D64;
extern const f32 lbl_1_rodata_5D68;
extern void fn_1_51E60(void *);
extern const f32 lbl_1_rodata_5D6C;
extern void fn_1_C8DC0(void);
extern void fn_80008E84(u32);
extern const f32 lbl_1_rodata_5D88;
extern const f32 lbl_1_rodata_5D8C;
extern void fn_1_4955C(f32, f32);
extern const f32 lbl_1_rodata_5CD4;
extern const f32 lbl_1_rodata_5D90;
extern void fn_1_4966C(f32, f32);
extern const f64 lbl_1_rodata_5C00;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5E0C;
extern int sprintf(char *, const char *, ...);
extern s16 fn_1_12C7B8(s16);
extern s32 fn_1_465D0(char *, s32);
extern s8 fn_1_86690(s8);
extern u32 fn_1_12C930(u32);
extern u8 fn_1_86624(void);
extern u8 lbl_1_bss_9C;
extern void *fn_1_868C0(s8);
extern void fn_80006E10(u32);

/* fzgx:begin fn_1_C47B4 */
void fn_1_C47B4(void) {
    u32 *p = lbl_1_bss_7AC48;

    if (p[0] != 0) {
        fn_1_46B4(lbl_801A6410, p[0], lbl_1_data_3D234, 0x4af);
    }
    fn_1_46B4(lbl_801A6410, p[4], lbl_1_data_3D234, 0x4b0);
    fn_1_46B4(lbl_801A6410, p[3], lbl_1_data_3D234, 0x4b1);
    fn_1_46B4(lbl_801A6410, p[2], lbl_1_data_3D234, 0x4b2);
    p[0] = 0;
    p[4] = 0;
    p[3] = 0;
    p[2] = 0;
}
/* fzgx:end fn_1_C47B4 */

/* fzgx:begin fn_1_C487C */
void fn_1_C487C(void) {
    fn_1_C489C();
}
/* fzgx:end fn_1_C487C */

/* fzgx:begin fn_1_C489C noprologue */
#include "types.h"

struct fn_1_C489C_p_lbl_1_rodata_5168_40_E12 {
    u8 unk_0;
    u8 pad_1[2];
    u8 unk_3;
    u8 pad_4[4];
    u32 unk_8;
};
struct fn_1_C489C_lbl_1_rodata_5168 {
    u8 pad_0[0x40];
    struct fn_1_C489C_p_lbl_1_rodata_5168_40_E12 unk_40[41];
};
extern f32 lbl_1_bss_7AC64[9];
#pragma pool_data on
const u8 fzgx_pool_lbl_1_rodata_5168[64] = {
        0x62, 0x55, 0x2d, 0x46, 0x64, 0x64, 0x0a, 0x00, 0x64, 0x5a, 0x32, 0x50, 0x6e, 0x6e, 0x14, 0x05,
        0x66, 0x5e, 0x3c, 0x5a, 0x7d, 0x7d, 0x23, 0x14, 0x67, 0x60, 0x46, 0x64, 0x87, 0x87, 0x37, 0x1e,
        0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x66, 0x5f, 0x32, 0x50, 0x82, 0x82, 0x1e, 0x0a,
        0x69, 0x64, 0x41, 0x5a, 0x8c, 0x8c, 0x28, 0x14, 0x6c, 0x66, 0x4b, 0x64, 0x96, 0x96, 0x32, 0x28,
};
static const struct fn_1_C489C_p_lbl_1_rodata_5168_40_E12 fzgx_pool_vehicle_parameters[41] = {
        { 2, {75, 70}, 75, {0, 25, 100, 0}, 0x80000000 },
        { 1, {80, 90}, 75, {0, 30, 100, 0}, 0x80000000 },
        { 2, {70, 100}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 3, {80, 95}, 85, {20, 25, 100, 0}, 0x80000000 },
        { 0, {85, 90}, 90, {80, 25, 100, 0}, 0x20000000 },
        { 1, {100, 85}, 95, {80, 10, 100, 0}, 0x80000000 },
        { 0, {100, 100}, 100, {0, 25, 100, 0}, 0x40000000 },
        { 3, {70, 90}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 2, {90, 90}, 95, {0, 20, 100, 0}, 0x20000000 },
        { 3, {75, 85}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 1, {80, 80}, 70, {0, 30, 100, 0}, 0x80000000 },
        { 3, {90, 95}, 75, {0, 30, 100, 0}, 0x80000000 },
        { 1, {70, 100}, 80, {0, 25, 100, 0}, 0x80000000 },
        { 2, {80, 95}, 85, {0, 30, 100, 0}, 0x80000000 },
        { 1, {75, 90}, 90, {20, 35, 100, 0}, 0x80000000 },
        { 0, {100, 85}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 2, {90, 100}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 3, {75, 80}, 95, {0, 30, 100, 0}, 0x10000000 },
        { 0, {80, 80}, 90, {0, 25, 100, 0}, 0x80000000 },
        { 2, {75, 85}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 0, {90, 95}, 75, {0, 30, 100, 0}, 0x80000000 },
        { 3, {100, 100}, 70, {0, 20, 100, 0}, 0x80000000 },
        { 2, {70, 80}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 0, {80, 95}, 85, {50, 30, 100, 0}, 0x80000000 },
        { 1, {75, 90}, 90, {80, 30, 100, 0}, 0x80000000 },
        { 1, {90, 85}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 2, {80, 80}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 2, {70, 80}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 3, {80, 80}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 0, {80, 70}, 95, {80, 15, 100, 0}, 0x40000000 },
        { 0, {100, 100}, 80, {80, 15, 100, 0}, 0x40000000 },
        { 0, {100, 100}, 90, {80, 20, 100, 0}, 0x80000000 },
        { 1, {70, 100}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 0, {80, 85}, 85, {0, 30, 100, 0}, 0x80000000 },
        { 3, {75, 90}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 0, {100, 95}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 1, {80, 80}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 1, {70, 90}, 95, {0, 30, 100, 0}, 0x80000000 },
        { 3, {80, 80}, 90, {0, 30, 100, 0}, 0x80000000 },
        { 0, {75, 85}, 80, {0, 30, 100, 0}, 0x80000000 },
        { 2, {95, 100}, 95, {0, 30, 100, 0}, 0x80000000 },
};
const u32 fzgx_pool_lbl_1_rodata_5394[14] = {
    0x44E10000, 0x44ED8000, 0x452F0000, 0x454BC000, 0x45674000, 0x456D8000, 0x45834000, 0x4585C000,
    0x4592E000, 0x45A8C000, 0x45BB8000, 0x45F96000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_53CC[16] = {
    0x44110000, 0x44480000, 0x45098000, 0x45354000, 0x457A0000, 0x458CA000, 0x45B54000, 0x45D16000,
    0x45FA0000, 0x4607F000, 0x464E4000, 0x4668D000, 0x466D8000, 0x46716800, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_540C[6] = {
    0x45B22000, 0x45CB2000, 0x4636D000, 0x46403000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_5424[6] = {
    0x459DD000, 0x45A0F000, 0x45B54000, 0x45B86000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_543C[14] = {
    0x3F800000, 0x43C80000, 0x45674000, 0x45992000, 0x45D16000, 0x45F0A000, 0x46002000, 0x4607F000,
    0x460CA000, 0x46115000, 0x467D2000, 0x468A4800, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_5474[8] = {
    0x44ED8000, 0x45322000, 0x4625A000, 0x46354000, 0x4644E000, 0x46610000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_5494[14] = {
    0x3F800000, 0x44278000, 0x45C1C000, 0x45CB2000, 0x45DAC000, 0x45E42000, 0x45F3C000, 0x45FD2000,
    0x46435000, 0x465DE000, 0x46610000, 0x466E4800, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_54CC[10] = {
    0x44BB8000, 0x44ED8000, 0x452F0000, 0x454E4000, 0x45A28000, 0x45AD7000, 0x45D16000, 0x45D48000,
    0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_54F4[6] = {
    0x42480000, 0x43FA0000, 0x46787000, 0x46866000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_550C[4] = {
    0x45610000, 0x4573C000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_551C[4] = {
    0x464E9000, 0x4654F800, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_552C[16] = {
    0x43DC0000, 0x444A8000, 0x44D70000, 0x4507A000, 0x45412000, 0x45D39000, 0x460B1000, 0x4628C000,
    0x4639C800, 0x4642D800, 0x46816000, 0x46834000, 0x46898000, 0x468FC000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_556C[14] = {
    0x432F0000, 0x43D70000, 0x45A28000, 0x45A8C000, 0x461DD000, 0x4620F000, 0x46487800, 0x466A6000,
    0x46802000, 0x4681B000, 0x469E9800, 0x46A02800, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_55A4[32] = {
    0x44048000, 0x444D4000, 0x450FC000, 0x451C4000, 0x454DA000, 0x455AC000, 0x45A2D000, 0x45AA5000,
    0x45A2D000, 0x45AD7000, 0x45B86000, 0x45BF9000, 0x45CF3000, 0x45D66000, 0x45F0F000, 0x45F5F000,
    0x45FDC000, 0x46034000, 0x46075000, 0x460A4800, 0x4616A000, 0x46199800, 0x46200000, 0x4622F800,
    0x46296000, 0x462C5800, 0x4644E000, 0x465AC000, 0x466D8000, 0x46775800, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_5624[4] = {
    0x44BB8000, 0x44D48000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_5634[20] = {
    0x43A00000, 0x44F78000, 0x45098000, 0x45462000, 0x45778000, 0x45816000, 0x458DE000, 0x45AE6000,
    0x45D2A000, 0x45D7A000, 0x45E6F000, 0x4605E800, 0x46315800, 0x46412000, 0x4661C800, 0x466EC000,
    0x468C3C00, 0x468DA400, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_5684[22] = {
    0x45802000, 0x45857000, 0x459F6000, 0x45A28000, 0x45B54000, 0x45BB8000, 0x45D61000, 0x45D93000,
    0x4601B000, 0x4604A800, 0x460B1000, 0x460CA000, 0x46115000, 0x4612E000, 0x46234800, 0x46255000,
    0x462BB800, 0x462DC000, 0x46383800, 0x4639C800, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_56DC[12] = {
    0x44688000, 0x44960000, 0x45610000, 0x45CE4000, 0x46002000, 0x46115000, 0x4636D000, 0x463B8000,
    0x4694D400, 0x469D0800, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_570C[6] = {
    0x43480000, 0x43FA0000, 0x45DAC000, 0x45E10000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_5724[12] = {
    0x3C23D70A, 0x42480000, 0x45EA6000, 0x45FA0000, 0x460B1000, 0x46160000, 0x46593000, 0x465C5000,
    0x46642000, 0x466A6000, 0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_5754[18] = {
    0x44960000, 0x44E74000, 0x455AC000, 0x457A0000, 0x45C80000, 0x45DE8000, 0x45F0A000, 0x45FD2000,
    0x4612E000, 0x46250000, 0x463D1000, 0x46435000, 0x46499000, 0x46548000, 0x466A6000, 0x466F1000,
    0xBF800000, 0xBF800000,
};
const u32 fzgx_pool_lbl_1_rodata_579C[18] = {
    0x45898000, 0x4592E000, 0x45E42000, 0x45F0A000, 0x46034000, 0x4604D000, 0x46034000, 0x4604D000,
    0x463D1000, 0x4644E000, 0x46629000, 0x46723000, 0x46898000, 0x468D6800, 0x46A28000, 0x46A4D800,
    0xBF800000, 0xBF800000,
};
/* Volatile primer stores establish the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(volatile f64 *d, volatile f32 *f, u32 u, s32 s) { /* Volatile stores preserve the retail literal-pool order. */
    *d = 0.0;
    *f = 32767.0f;
    *d = 0.01;
    *d = 4503599627370496.0;
    *d = 0.00390625;
    *d = -1.0;
    *d = 1.0;
    *d = 0.5;
    *d = 4503601774854144.0;
    *d = 1.2;
    *d = 1.1;
    *d = 1.05;
    *d = 1.025;
    *d = 10.0;
    *d = 5.0;
    *d = 0.2;
    *d = 100.0;
    *d = 20.0;
    *d = 1.6;
    *d = 21.0;
    *d = 15.0;
}
#pragma section code_type ".text"

extern u32 fn_800793D4(u8 *, u32, u32);
static inline f64 clamp_value(f32 x) {
    if (x < 0.0) return 0.0;
    if (x > 20.0) return 20.0;
    return x;
}

void fn_1_C489C(void *arg0) {
    u32 v0;
    u32 v1;
    s16 v2;
    f64 v5;
    f32 v6;
    f64 v7;
    struct { void *value; } table;
    void *v10;
    void *v11;
    v0 = *(u32 *)((u8 *)arg0 + 1156);
    v1 = *(u32 *)((u8 *)v0 + 64);
    fn_800793D4((u8 *)v0, 0, 136);
    *(u32 *)((u8 *)v0 + 64) = v1;
    v2 = *(s16 *)((u8 *)arg0 + 6);
    if (v2 >= 41) {
        *(u8 *)((u8 *)v0 + 56) = v2 % 4;
    } else {
        *(u8 *)((u8 *)v0 + 56) = v2;
    }
    if (*(u8 *)((u8 *)arg0 + 1294) == 0) {
        *(u32 *)((u8 *)v0 + 0) |= 0x20000000;
    } else {
        *(u8 *)((u8 *)arg0 + 1294) = 0;
    }
    *(u8 *)((u8 *)v0 + 40) = 1;
    *(u8 *)((u8 *)v0 + 42) = 99;
    *(u8 *)((u8 *)v0 + 55) = 255;
    v5 = 0.0;
    *(f32 *)((u8 *)v0 + 36) = 0.2 * (100.0 - (f32)(lbl_1_bss_7AC64[4] * (f32)(u32)fzgx_pool_vehicle_parameters[*(u8 *)((u8 *)v0 + 56)].unk_3));
    v6 = *(f32 *)((u8 *)v0 + 36);
    v5 = clamp_value(v6);
    v7 = 1.0;
    *(f32 *)((u8 *)v0 + 36) = (f32)v5;
    if (*(f32 *)((u8 *)arg0 + 44) > v7)
        *(u32 *)((u8 *)v0 + 0) |= 0x1000000;
    if (*(f32 *)((u8 *)arg0 + 44) > 1.6)
        *(u32 *)((u8 *)v0 + 0) |= 0x800000;
    if (*(f32 *)((u8 *)arg0 + 28) < 21.0)
        *(u32 *)((u8 *)v0 + 0) |= 0x400000;
    if (*(f32 *)((u8 *)arg0 + 560) > 15.0)
        *(u32 *)((u8 *)v0 + 0) |= 0x200000;
    *(u32 *)((u8 *)v0 + 0) = (*(u32 *)((u8 *)v0 + 0) & ~0x8000) | ((fzgx_pool_vehicle_parameters[*(u8 *)((u8 *)v0 + 56)].unk_8 >> 14) & 0x8000);
    *(u32 *)((u8 *)v0 + 0) = (*(u32 *)((u8 *)v0 + 0) & ~0x4000) | ((fzgx_pool_vehicle_parameters[*(u8 *)((u8 *)v0 + 56)].unk_8 >> 14) & 0x4000);
    *(u8 *)((u8 *)v0 + 43) = 255;
    *(u8 *)((u8 *)v0 + 54) = 255;
    *(u8 *)((u8 *)v0 + 49) = fzgx_pool_vehicle_parameters[*(u8 *)((u8 *)v0 + 56)].unk_0;
    *(u8 *)((u8 *)v0 + 51) = 255;
    *(u8 *)((u8 *)v0 + 52) = 255;
}
/* fzgx:end fn_1_C489C */

/* fzgx:begin fn_1_C4ABC noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"
#include "lc_mtx.h"

/* a CPU route slot (.bss 0x7AC48 points to an array of them) */
typedef struct {
    u32 zone;
    f32 pos[3];
    u32 mask;
} CpuSlot;

/* a course zone: a stretch of track with a lateral window */
typedef struct {
    f32 start;
    f32 end;
    f32 left;
    f32 right;
    u8 type;
    u8 group;
    u8 pad_12[2];
} CpuZone;

/* the pre-pass per-race table (.bss 0x7AC50 points to it) */
typedef struct {
    u32 unk_0[30];
    u32 unk_78[30];
    u32 unk_F0[30];
    u32 unk_168[30];
    u8 unk_1E0[30];
    u8 unk_1FE[30];
} CpuPairs;

/* the difficulty tuning (.bss 0x7AC64) */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
} CpuLevel;

/* a CPU personality (.rodata 0x5168 + 0x40) */
typedef struct {
    u8 lane;
    u8 boost;
    u8 shuffle;
    u8 unk_3;
    u8 attack;
    u8 speed;
    u8 unk_6;
    u8 unk_7;
    u32 flags;
} CpuParams;

/* the CPU block of a machine (+0x484) */
typedef struct {
    u32 flags;
    f32 steer;
    f32 unk_8;
    f32 throttle;
    f32 unk_10;
    f32 unk_14;
    f32 target;
    f32 lateral;
    f32 prev_lateral;
    f32 unk_24;
    u8 state;
    u8 next_state;
    u8 rival;
    u8 zone;
    u8 state_timer;
    u8 unk_2D;
    u8 unk_2E;
    u8 timer;
    u8 blink;
    u8 lane;
    u8 pad_32[2];
    u8 unk_34;
    u8 spin_timer;
    u8 zone_type;
    u8 start_delay;
    u8 param;
    u8 cooldown;
    u8 unk_3A;
    u8 pad_3B;
    u32 unk_3C;
    u8 pad_40[4];
    f32 last_pos;
} CpuBlock;

typedef struct {
    u32 flags;
    s16 id;
    u8 pad_6[0x16];
    f32 unk_1C;
    u8 pad_20[0x5C];
    f32 pos[3];
    u8 pad_88[0x64];
    f32 mtx[3][4];
    u8 pad_11C[0x60];
    f32 unk_17C;
    u8 pad_180[4];
    f32 speed;
    u8 pad_188[2];
    u8 unk_18A;
    u8 pad_18B[0x31];
    f32 unk_1BC[3];
    u8 pad_1C8[0x2BC];
    CpuBlock *ai;
    u8 pad_488[0x620 - 0x488];
} Machine;

/* a machine progress record (fn_1_8627C) */
typedef struct {
    u8 pad_0[0x7C];
    u32 unk_7C;
    u8 pad_80[4];
    f32 unk_84;
    s32 unk_88;
    s32 unk_8C;
    u8 pad_90[0x68];
    f32 unk_F8;
    u8 pad_FC[4];
    f32 unk_100;
    u16 unk_104;
    u8 pad_106[2];
    f32 unk_108;
    u8 pad_10C[9];
    u8 unk_115;
    u8 pad_116[2];
    s32 unk_118;
} Progress;

typedef struct {
    u8 pad_0[0x90];
    f32 *unk_90;
} Course;

typedef struct {
    u32 unk_0;
    u8 unk_4;
} GameState;

/* the retail TU .bss objects this function uses, at their retail offsets, so MWCC
   addresses them off one section base */
CpuSlot *fzgx_obj_lbl_1_bss_7AC48;
u16 lbl_1_bss_7AC48__fzgx_offset_4;
CpuPairs *fzgx_obj_lbl_1_bss_7AC50;
s8 *fzgx_obj_lbl_1_bss_7AC54;
f32 (*lbl_1_bss_7AC54__fzgx_offset_4)[3];
u32 lbl_1_bss_7AC54__fzgx_offset_8;
f32 *lbl_1_bss_7AC54__fzgx_offset_C;
CpuLevel fzgx_obj_lbl_1_bss_7AC64;
f32 fzgx_obj_lbl_1_bss_7AC88;
CpuZone *lbl_1_bss_7AC88__fzgx_offset_4;
u8 fzgx_obj_lbl_1_bss_7AC90;
u8 lbl_1_bss_7AC90__fzgx_offset_1;
u8 lbl_1_bss_7AC90__fzgx_offset_2;
u8 lbl_1_bss_7AC90__fzgx_offset_3;
f32 lbl_1_bss_7AC90__fzgx_offset_4;
f32 lbl_1_bss_7AC90__fzgx_offset_8;
f32 fzgx_obj_lbl_1_bss_7AC9C;

#define cpu_slots fzgx_obj_lbl_1_bss_7AC48
#define cpu_slot_count lbl_1_bss_7AC48__fzgx_offset_4
#define cpu_pairs fzgx_obj_lbl_1_bss_7AC50
#define cpu_lines fzgx_obj_lbl_1_bss_7AC54
#define cpu_points lbl_1_bss_7AC54__fzgx_offset_4
#define cpu_ranges lbl_1_bss_7AC54__fzgx_offset_C
#define cpu_level fzgx_obj_lbl_1_bss_7AC64
#define cpu_line_step fzgx_obj_lbl_1_bss_7AC88
#define cpu_zones lbl_1_bss_7AC88__fzgx_offset_4
#define cpu_enabled fzgx_obj_lbl_1_bss_7AC90
#define cpu_best_rank lbl_1_bss_7AC90__fzgx_offset_1
#define cpu_worst_rank lbl_1_bss_7AC90__fzgx_offset_2
#define cpu_best_progress lbl_1_bss_7AC90__fzgx_offset_4
#define cpu_worst_progress lbl_1_bss_7AC90__fzgx_offset_8
#define cpu_line_scale fzgx_obj_lbl_1_bss_7AC9C

u32 fzgx_obj_lbl_1_data_3D230 = 1;    /* the CPU random generator */
#define cpu_seed fzgx_obj_lbl_1_data_3D230

/* retail .rodata 0x5168..0x57E4 (the CPU tables), so the literals below land at retail offsets */
const u32 fzgx_pool_lbl_1_rodata_5168[16] = {
    0x62552D46, 0x64640A00, 0x645A3250, 0x6E6E1405, 0x665E3C5A, 0x7D7D2314, 0x67604664, 0x8787371E,
    0x64646464, 0x64646464, 0x665F3250, 0x82821E0A, 0x6964415A, 0x8C8C2814, 0x6C664B64, 0x96963228,
};
const CpuParams fzgx_pool_lbl_1_rodata_5168__fzgx_offset_40[41] = {
    { 2, 75, 70, 75, 0, 25, 100, 0, 0x80000000 },
    { 1, 80, 90, 75, 0, 30, 100, 0, 0x80000000 },
    { 2, 70, 100, 80, 0, 30, 100, 0, 0x80000000 },
    { 3, 80, 95, 85, 20, 25, 100, 0, 0x80000000 },
    { 0, 85, 90, 90, 80, 25, 100, 0, 0x20000000 },
    { 1, 100, 85, 95, 80, 10, 100, 0, 0x80000000 },
    { 0, 100, 100, 100, 0, 25, 100, 0, 0x40000000 },
    { 3, 70, 90, 95, 0, 30, 100, 0, 0x80000000 },
    { 2, 90, 90, 95, 0, 20, 100, 0, 0x20000000 },
    { 3, 75, 85, 80, 0, 30, 100, 0, 0x80000000 },
    { 1, 80, 80, 70, 0, 30, 100, 0, 0x80000000 },
    { 3, 90, 95, 75, 0, 30, 100, 0, 0x80000000 },
    { 1, 70, 100, 80, 0, 25, 100, 0, 0x80000000 },
    { 2, 80, 95, 85, 0, 30, 100, 0, 0x80000000 },
    { 1, 75, 90, 90, 20, 35, 100, 0, 0x80000000 },
    { 0, 100, 85, 95, 0, 30, 100, 0, 0x80000000 },
    { 2, 90, 100, 90, 0, 30, 100, 0, 0x80000000 },
    { 3, 75, 80, 95, 0, 30, 100, 0, 0x10000000 },
    { 0, 80, 80, 90, 0, 25, 100, 0, 0x80000000 },
    { 2, 75, 85, 80, 0, 30, 100, 0, 0x80000000 },
    { 0, 90, 95, 75, 0, 30, 100, 0, 0x80000000 },
    { 3, 100, 100, 70, 0, 20, 100, 0, 0x80000000 },
    { 2, 70, 80, 80, 0, 30, 100, 0, 0x80000000 },
    { 0, 80, 95, 85, 50, 30, 100, 0, 0x80000000 },
    { 1, 75, 90, 90, 80, 30, 100, 0, 0x80000000 },
    { 1, 90, 85, 95, 0, 30, 100, 0, 0x80000000 },
    { 2, 80, 80, 90, 0, 30, 100, 0, 0x80000000 },
    { 2, 70, 80, 95, 0, 30, 100, 0, 0x80000000 },
    { 3, 80, 80, 90, 0, 30, 100, 0, 0x80000000 },
    { 0, 80, 70, 95, 80, 15, 100, 0, 0x40000000 },
    { 0, 100, 100, 80, 80, 15, 100, 0, 0x40000000 },
    { 0, 100, 100, 90, 80, 20, 100, 0, 0x80000000 },
    { 1, 70, 100, 80, 0, 30, 100, 0, 0x80000000 },
    { 0, 80, 85, 85, 0, 30, 100, 0, 0x80000000 },
    { 3, 75, 90, 90, 0, 30, 100, 0, 0x80000000 },
    { 0, 100, 95, 95, 0, 30, 100, 0, 0x80000000 },
    { 1, 80, 80, 90, 0, 30, 100, 0, 0x80000000 },
    { 1, 70, 90, 95, 0, 30, 100, 0, 0x80000000 },
    { 3, 80, 80, 90, 0, 30, 100, 0, 0x80000000 },
    { 0, 75, 85, 80, 0, 30, 100, 0, 0x80000000 },
    { 2, 95, 100, 95, 0, 30, 100, 0, 0x80000000 },
};
const u32 fzgx_pool_lbl_1_rodata_5168__fzgx_offset_22C[276] = {
    0x44E10000, 0x44ED8000, 0x452F0000, 0x454BC000, 0x45674000, 0x456D8000, 0x45834000, 0x4585C000,
    0x4592E000, 0x45A8C000, 0x45BB8000, 0x45F96000, 0xBF800000, 0xBF800000, 0x44110000, 0x44480000,
    0x45098000, 0x45354000, 0x457A0000, 0x458CA000, 0x45B54000, 0x45D16000, 0x45FA0000, 0x4607F000,
    0x464E4000, 0x4668D000, 0x466D8000, 0x46716800, 0xBF800000, 0xBF800000, 0x45B22000, 0x45CB2000,
    0x4636D000, 0x46403000, 0xBF800000, 0xBF800000, 0x459DD000, 0x45A0F000, 0x45B54000, 0x45B86000,
    0xBF800000, 0xBF800000, 0x3F800000, 0x43C80000, 0x45674000, 0x45992000, 0x45D16000, 0x45F0A000,
    0x46002000, 0x4607F000, 0x460CA000, 0x46115000, 0x467D2000, 0x468A4800, 0xBF800000, 0xBF800000,
    0x44ED8000, 0x45322000, 0x4625A000, 0x46354000, 0x4644E000, 0x46610000, 0xBF800000, 0xBF800000,
    0x3F800000, 0x44278000, 0x45C1C000, 0x45CB2000, 0x45DAC000, 0x45E42000, 0x45F3C000, 0x45FD2000,
    0x46435000, 0x465DE000, 0x46610000, 0x466E4800, 0xBF800000, 0xBF800000, 0x44BB8000, 0x44ED8000,
    0x452F0000, 0x454E4000, 0x45A28000, 0x45AD7000, 0x45D16000, 0x45D48000, 0xBF800000, 0xBF800000,
    0x42480000, 0x43FA0000, 0x46787000, 0x46866000, 0xBF800000, 0xBF800000, 0x45610000, 0x4573C000,
    0xBF800000, 0xBF800000, 0x464E9000, 0x4654F800, 0xBF800000, 0xBF800000, 0x43DC0000, 0x444A8000,
    0x44D70000, 0x4507A000, 0x45412000, 0x45D39000, 0x460B1000, 0x4628C000, 0x4639C800, 0x4642D800,
    0x46816000, 0x46834000, 0x46898000, 0x468FC000, 0xBF800000, 0xBF800000, 0x432F0000, 0x43D70000,
    0x45A28000, 0x45A8C000, 0x461DD000, 0x4620F000, 0x46487800, 0x466A6000, 0x46802000, 0x4681B000,
    0x469E9800, 0x46A02800, 0xBF800000, 0xBF800000, 0x44048000, 0x444D4000, 0x450FC000, 0x451C4000,
    0x454DA000, 0x455AC000, 0x45A2D000, 0x45AA5000, 0x45A2D000, 0x45AD7000, 0x45B86000, 0x45BF9000,
    0x45CF3000, 0x45D66000, 0x45F0F000, 0x45F5F000, 0x45FDC000, 0x46034000, 0x46075000, 0x460A4800,
    0x4616A000, 0x46199800, 0x46200000, 0x4622F800, 0x46296000, 0x462C5800, 0x4644E000, 0x465AC000,
    0x466D8000, 0x46775800, 0xBF800000, 0xBF800000, 0x44BB8000, 0x44D48000, 0xBF800000, 0xBF800000,
    0x43A00000, 0x44F78000, 0x45098000, 0x45462000, 0x45778000, 0x45816000, 0x458DE000, 0x45AE6000,
    0x45D2A000, 0x45D7A000, 0x45E6F000, 0x4605E800, 0x46315800, 0x46412000, 0x4661C800, 0x466EC000,
    0x468C3C00, 0x468DA400, 0xBF800000, 0xBF800000, 0x45802000, 0x45857000, 0x459F6000, 0x45A28000,
    0x45B54000, 0x45BB8000, 0x45D61000, 0x45D93000, 0x4601B000, 0x4604A800, 0x460B1000, 0x460CA000,
    0x46115000, 0x4612E000, 0x46234800, 0x46255000, 0x462BB800, 0x462DC000, 0x46383800, 0x4639C800,
    0xBF800000, 0xBF800000, 0x44688000, 0x44960000, 0x45610000, 0x45CE4000, 0x46002000, 0x46115000,
    0x4636D000, 0x463B8000, 0x4694D400, 0x469D0800, 0xBF800000, 0xBF800000, 0x43480000, 0x43FA0000,
    0x45DAC000, 0x45E10000, 0xBF800000, 0xBF800000, 0x3C23D70A, 0x42480000, 0x45EA6000, 0x45FA0000,
    0x460B1000, 0x46160000, 0x46593000, 0x465C5000, 0x46642000, 0x466A6000, 0xBF800000, 0xBF800000,
    0x44960000, 0x44E74000, 0x455AC000, 0x457A0000, 0x45C80000, 0x45DE8000, 0x45F0A000, 0x45FD2000,
    0x4612E000, 0x46250000, 0x463D1000, 0x46435000, 0x46499000, 0x46548000, 0x466A6000, 0x466F1000,
    0xBF800000, 0xBF800000, 0x45898000, 0x4592E000, 0x45E42000, 0x45F0A000, 0x46034000, 0x4604D000,
    0x46034000, 0x4604D000, 0x463D1000, 0x4644E000, 0x46629000, 0x46723000, 0x46898000, 0x468D6800,
    0x46A28000, 0x46A4D800, 0xBF800000, 0xBF800000,
};

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(volatile f64 *d, volatile f32 *f) { /* retail literal-pool order */
    *f = 0.0f;
    *d = 0.0;
    *f = 32767.0f;
    *d = 0.01;
    *d = 4503599627370496.0;
    *d = 0.00390625;
    *d = -1.0;
    *d = 1.0;
    *d = 0.5;
    *d = 4503601774854144.0;
    *d = 1.2;
    *d = 1.1;
    *d = 1.05;
    *d = 1.025;
    *d = 10.0;
    *d = 5.0;
    *d = 0.2;
    *d = 100.0;
    *d = 20.0;
    *d = 1.6;
    *d = 21.0;
    *d = 15.0;
    *f = 1.0f;
    *d = 0.25;
    *d = -0.42;
    *d = 0.42;
    *f = 0.4f;
    *f = -0.4f;
    *f = 100000.0f;
    *d = 4.0;
    *f = 6000.0f;
    *d = 1e-05;
    *d = 2.0;
    *d = 95.0;
    *d = 0.4;
    *d = 150.0;
    *d = 99.0;
    *f = 10000000.0f;
    *f = 10000.0f;
    *d = 3000.0;
    *d = 1000.0;
    *d = 500.0;
    *f = 20.0f;
    *d = 50.0 / 9.0;
    *d = 0.8;
    *d = 200.0;
    *d = 400.0;
    *d = 1.5;
    *d = 800.0;
    *d = 1.25;
    *d = 50.0;
    *d = 300.0;
    *f = 0.5f;
    *d = 0.9;
    *f = 1.1920929e-07f;
    *f = 8.0f;
    *d = 0.025;
    *d = 0.1;
    *f = 4096.0f;
    *d = 1.3;
    *d = -0.006;
    *d = 0.45;
    *f = 2048.0f;
}
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = (u32)fzgx_obj_lbl_1_bss_7AC48;
    s = lbl_1_bss_7AC48__fzgx_offset_4;
    s = (u32)fzgx_obj_lbl_1_bss_7AC50;
    s = (u32)fzgx_obj_lbl_1_bss_7AC54;
    s = (u32)lbl_1_bss_7AC54__fzgx_offset_4;
    s = lbl_1_bss_7AC54__fzgx_offset_8;
    s = (u32)lbl_1_bss_7AC54__fzgx_offset_C;
    s = fzgx_obj_lbl_1_bss_7AC64.unk_0;
    s = fzgx_obj_lbl_1_bss_7AC88;
    s = (u32)lbl_1_bss_7AC88__fzgx_offset_4;
    s = fzgx_obj_lbl_1_bss_7AC90;
    s = lbl_1_bss_7AC90__fzgx_offset_1;
    s = lbl_1_bss_7AC90__fzgx_offset_2;
    s = lbl_1_bss_7AC90__fzgx_offset_3;
    s = lbl_1_bss_7AC90__fzgx_offset_4;
    s = lbl_1_bss_7AC90__fzgx_offset_8;
    s = fzgx_obj_lbl_1_bss_7AC9C;
}
#pragma section code_type ".text"

extern GameState lbl_1_bss_3C30;
extern Course *lbl_1_bss_3BE0;
extern s32 fn_1_3F164(void);
extern void fn_1_12F4A8(Machine *car);
extern void fn_1_130C84(Machine *car);
extern void lbl_8006DC6C(f32 (*mtx)[4]);
extern Progress *fn_1_8627C(s32 index);
extern u32 fn_1_214C4(f32 *out, f32 pos, u32 state);
extern u8 fn_1_86624(void);
extern f32 fn_1_8CAF4(s32 a, s32 b);
extern f32 fn_1_8CA70(s32 a, s32 b);
extern f32 fn_1_8652C(s32 index);
extern s16 lbl_8006D24C(f32 x, f32 y);
extern f32 lbl_8006D0B4(f32 x);
extern void fn_8006E250(f32 *src, f32 *dst);
extern void fn_8006E2B0(f32 *src, f32 *dst);
extern s32 fn_1_8677C(s32 index);
extern f64 __fabs(f64);
extern int __abs(int);
#define abs(x) __abs(x)
#define fabs(x) __fabs(x)

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))
#define SIGN(x) ((x) > 0.0 ? 1.0 : ((x) < 0.0 ? -1.0 : 0.0))
#define LINE(lane, i) cpu_lines[((lane) << 9) + (i)]
#define POINT(lane, i) cpu_points[(i) + ((lane) << 9)]

#define cpu_params fzgx_pool_lbl_1_rodata_5168__fzgx_offset_40

static inline u32 cpu_rand(void) {
    cpu_seed = cpu_seed * 0x41C64E6D + 0x3039;
    return (cpu_seed >> 16) & 0x7FFF;
}

static inline s32 cpu_bit(u32 mask, s32 n) {
    return __rlwnm(mask, (n + 1) & 31, 31, 31);
}

/* the squared length of (x, y) */
static inline f32 cpu_mag2(f32 x, f32 y) {
    return __fmadds(y, y, x * x);
}

static inline s32 cpu_line_scan(CpuBlock *ai, s32 from, f32 *t) {
    s32 k;
    s32 j;
    s32 found;

    found = 0;
    for (k = 1; k < 30; k++) {
        j = k + from;
        if (j >= 512) {
            j -= 512;
        }
        if (LINE(ai->lane, j) != -128) {
            found = j;
            break;
        }
    }
    if (k > 2) {
        *t = 0.0f;
    }
    return found;
}

static inline f32 cpu_sub(f32 p, f32 q) {
    p -= q;
    return p;
}

static inline f32 cpu_madd(f32 *a, f32 *b, f32 sum) {
    f32 z = b[2];

    z = cpu_sub(a[2], z);
    return __fmadds(z, z, sum);
}

static inline f32 cpu_dist2(f32 *a, f32 *b) {
    f32 y = b[1];

    y = cpu_sub(a[1], y);
    y *= y;
    return cpu_madd(a, b, y);
}

#pragma fp_contract off

/* deal this machine in or out of every route slot */
static inline void cpu_deal_slots(Machine *car, CpuBlock *ai) {
    CpuSlot *slot = cpu_slots;
    u32 threshold = 32767.0f * cpu_level.unk_1C * (0.01 * cpu_params[ai->param].shuffle);
    u32 i;

    for (i = 0; i < cpu_slot_count; i++, slot++) {
        if (threshold < cpu_rand()) {
            slot->mask &= ~((u32)0x80000000 >> car->id);
        } else {
            slot->mask |= (u32)0x80000000 >> car->id;
        }
    }
}

/* 1 when pos lies outside every no-attack range */
static inline s32 cpu_outside_ranges(f32 pos) {
    f32 *range = cpu_ranges;

    if (range == NULL) {
        return 1;
    }
    do {
        if (pos > range[0] && pos < range[1]) {
            return 0;
        }
        range += 2;
    } while (range[0] > 0.0);
    return 1;
}

static inline s16 cpu_find_slot(u32 zone) {
    s16 found = -1;
    u32 i;

    for (i = 0; i < cpu_slot_count; i++) {
        if (zone == cpu_slots[i].zone) {
            found = i;
            break;
        }
    }
    return found;
}

/* the state the race position asks for */
static inline u8 cpu_wanted_state(Progress *prog) {
    if (cpu_best_rank >= prog->unk_115) {
        return 0;
    } else if (cpu_worst_rank > prog->unk_115) {
        return 1;
    } else {
        return 2;
    }
}

void fn_1_C4ABC(Machine *car) {
    f32 boost;
    f32 a[3];
    f32 b[3];
    f32 c[3];
    f32 d[3];
    s32 slot;
    f32 v[3];
    f32 tmp;
    Progress *prog;
    Progress *other;
    CpuZone *zone;
    f32 max_speed;
    u32 zi;
    s16 abs_angle;
    CpuZone *z;
    f32 scale;
    f32 rival_lat;
    f32 ahead;
    f32 rival_side;
    f32 best_dist;
    f32 best_side;
    f32 gap;
    f32 side_gap;
    f32 aim;
    f32 best;
    f32 lo;
    f32 lim;
    f32 side;
    CpuBlock *ai;
    s16 dir;
    f32 hi;
    f32 dist;
    f32 base;
    f32 first_start;
    f32 room;
    s32 inside;
    s32 done;
    s32 none;
    s32 first;
    s32 use_line;
    s16 angle;
    f32 t;
    u32 i;
    u32 mask;
    u8 want;

    rival_lat = 0.0f;
    rival_side = rival_lat;
    done = 0;
    if (cpu_enabled == 0) {
        return;
    }
    if (fn_1_3F164() != 0) {
        return;
    }
    ai = car->ai;
    if (ai == NULL) {
        return;
    }

    /* waiting on the grid */
    if ((*(u32 *)ai >> 29) & 1 && (car->flags & 0x8000)) {
        if (ai->start_delay == 0xFF) {
            ai->start_delay = (s32)(cpu_rand() * 120) / 32767;
            cpu_deal_slots(car, car->ai);
        }
        if (ai->start_delay != 0) {
            ai->throttle = 0.0f;
            if (lbl_1_bss_3C30.unk_0 & 0x4000) {
                ai->start_delay--;
            }
        } else {
            ai->throttle = 1.0f;
        }
        return;
    }
    if (ai->flags & 1) {
        fn_1_12F4A8(car);
        return;
    }
    if ((ai->flags >> 1) & 1) {
        fn_1_130C84(car);
        return;
    }

    lbl_8006DC6C(car->mtx);
    {
        f32 x;

        x = car->pos[0];
        base = car->pos[1];
        dist = car->pos[2];
        mtx_set_translate((void *)LC_BASE, x, base, dist);
    }
    prog = fn_1_8627C(car->id);
    max_speed = prog->unk_84;
    scale = 1.0f / max_speed;
    ai->prev_lateral = ai->lateral;
    ai->lateral = prog->unk_108 * scale;
    ai->unk_3C = fn_1_214C4(&tmp, prog->unk_100, ai->unk_3C);
    if (car->flags & 0x40000) {
        cpu_deal_slots(car, ai);
    }

    angle = (s16)prog->unk_104;
    dir = angle > 0 ? 1 : (angle < 0 ? -1 : 0);
    if ((prog->unk_7C & 0x1400000) && fabs(ai->lateral) > 0.25) {
        dir *= -1;
    }
    abs_angle = abs(angle);

    switch (ai->state) {
    case 4:
        ai->timer--;
        if (car->flags & 0x800000) {
            ai->timer = 4;
            if (ai->unk_2D < 10) {
                ai->unk_2D++;
            }
        }
        if (ai->timer == 0) {
            ai->flags |= 0x2000000;
            ai->state = 1;
            ai->unk_2D = 0;
        }
        break;
    case 3:
        if (abs_angle < 0x3000 && ai->spin_timer == 0) {
            ai->target = CLAMP(ai->lateral, -0.42, 0.42);
            ai->spin_timer = 120;
        }
        if (ai->spin_timer != 0) {
            ai->spin_timer--;
            if (ai->spin_timer == 0) {
                ai->state = 1;
            }
        }
        break;
    case 5:
    case 6:
        if (!cpu_outside_ranges(prog->unk_100)) {
            ai->timer = 0;
            ai->flags |= 0x2000000;
            ai->state = 1;
            ai->rival = 99;
        } else {
            ai->timer--;
            if (ai->timer == 0) {
                ai->flags |= 0x2000000;
                ai->state = 1;
                ai->rival = 99;
            }
        }
        break;
    }

    /* pick a rival to attack */
    switch (ai->state) {
    case 3:
    case 4:
        break;
    default:
        if (car->flags & 0x800000) {
            if (((ai->flags >> 28) & 1) && ai->zone_type != 1) {
                ai->flags &= ~0x10000000;
                ai->zone = 0xFF;
                ai->zone_type = 0xFF;
            }
            ai->timer = 4;
            ai->unk_2D = 1;
            ai->state = 4;
            ai->state_timer = 0;
        } else {
            if (abs_angle > 0x3800 && !((ai->flags >> 16) & 1)) {
                if (ai->lateral < 0.0) {
                    ai->target = 0.4f;
                } else {
                    ai->target = -0.4f;
                }
                ai->state = 3;
                ai->state_timer = 0;
            }
            if (ai->state != 6 && !((ai->flags >> 28) & 1) && !(car->flags & 2) && cpu_outside_ranges(prog->unk_100)) {
                s8 count;
                u32 best_index;
                u32 best_kind;
                u32 kind;

                count = (s8)fn_1_86624();
                best_dist = 100000.0f;
                best_index = 99;
                best_kind = 0;
                for (i = 0; i < count; i++) {
                    kind = 0;
                    if (car->id == i) {
                        continue;
                    }
                    if (ai->rival == i && ai->timer != 0) {
                        continue;
                    }
                    if (cpu_pairs->unk_1E0[car->id] != cpu_pairs->unk_1E0[i]) {
                        continue;
                    }
                    gap = fn_1_8CAF4(car->id, i);
                    if (fabs(best_dist) < fabs(gap)) {
                        continue;
                    }
                    side_gap = fn_1_8CA70(car->id, i);
                    if (cpu_bit(cpu_pairs->unk_0[car->id], i) && fabs(side_gap) < 4.0) {
                        if (car->unk_17C > fn_1_8652C(i)) {
                            kind = 1;
                        }
                    }
                    if ((cpu_bit(cpu_pairs->unk_0[car->id], i) || cpu_bit(cpu_pairs->unk_78[car->id], i)) && fabs(side_gap) < 10.0) {
                        u32 r = cpu_seed * 0x41C64E6D + 0x3039;

                        cpu_seed = r;
                        r = (r >> 16) & 0x7FFF;
                        if (32767.0f * (cpu_level.unk_20 * cpu_params[ai->param].attack) / 6000.0f > r) {
                            kind = 2;
                        }
                    }
                    if (kind != 0) {
                        best_dist = gap;
                        best_index = i;
                        best_side = side_gap;
                        best_kind = kind;
                    }
                }
                if (best_index != 99 && !((ai->flags >> 2) & 1)) {
                    ai->state_timer = 0;
                    ai->timer = 60;
                    if (best_kind == 1) {
                        ai->state = 5;
                    } else {
                        ai->state = 6;
                    }
                    ai->rival = best_index;
                    other = fn_1_8627C(best_index);
                    {
                        f32 lat = other->unk_108;

                        rival_lat = fabs(lat) < 1e-05 ? 1e-05 : lat;
                    }
                    rival_side = fabs(best_side) < 1e-05 ? 1e-05 : best_side;
                }
            }
        }
        break;
    }

    /* settle on the state the race position asks for */
    switch (ai->state) {
    case 0:
    case 1:
    case 2:
        want = cpu_wanted_state(prog);
        if ((ai->flags >> 25) & 1) {
            ai->flags &= ~0x2000000;
            ai->state = want;
            ai->state_timer = 0;
        } else if (want != *(u8 *)&ai->state) {
            if (ai->state_timer == 0) {
                ai->next_state = want;
                ai->state_timer = 60;
            } else {
                ai->state_timer--;
                if (ai->state_timer == 0) {
                    ai->state = ai->next_state;
                }
            }
        } else {
            ai->state_timer = 0;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    }

    /* choose the lateral target */
    if ((ai->flags >> 29) & 1) {
        ai->target = ai->lateral;
        done = 1;
        ai->flags &= ~0x20000000;
        ai->unk_2E = 180;
        ai->unk_3A = 0xFF;
        ai->flags |= 0x8000000;
    }
    if (!done && ai->state == 3) {
        done = 1;
    }
    if (!done && ai->state == 6) {
        ai->target = scale * fn_1_8627C(ai->rival)->unk_108;
        done = 1;
    }
    if (!done && rival_lat != 0.0) {
        inside = 0;
        if (fabs(rival_side) > 2.0) {
            f32 s = rival_side < 0.0 ? 1.0 : -1.0;

            aim = 5.0 * s + rival_lat;
            if (fabs(aim) < 0.5 * max_speed - 5.0) {
                inside = 1;
            }
        }
        if (!inside) {
            f32 s = rival_lat < 0.0 ? -1.0 : 1.0;

            aim = s * (fabs(rival_lat) - 5.0);
        }
        done = 1;
        ai->target = aim * scale;
    }
    if (!done && ((ai->flags >> 27) & 1)) {
        done = 1;
    }
    if (ai->cooldown != 0) {
        ai->cooldown--;
    }
    if (!done && ai->cooldown == 0) {
        if (car->speed < (f32)cpu_params[ai->param].speed && !cpu_bit(ai->flags, 28) && cpu_level.unk_3 == 0 && !(ai->flags & 0x14000000)) {
            for (zone = cpu_zones; zone->end > -1.0; zone++) {
                if (zone->type != 1 || zone->end < prog->unk_100) {
                    continue;
                }
                if (zone->group == ai->lane % (prog->unk_88 - 1) + 1) {
                    ai->flags |= 0x4000000;
                } else if (prog->unk_88 <= 1) {
                    ai->unk_34 = zone->group - 1;
                    ai->flags |= 0x4000000;
                    break;
                }
            }
        }
        if (car->speed > 95.0 && ((ai->flags >> 26) & 1)) {
            ai->flags &= ~0x4000000;
        }

        best = ai->target;
        zi = 0;
        for (z = cpu_zones; z->end > -1.0; zi++, z++) {
            if (ai->zone == zi) {
                continue;
            }
            if (prog->unk_8C != 0 && z->group != prog->unk_8C) {
                continue;
            }
            if (((*(u32 *)ai >> 20) & 1) && z->type != 1) {
                continue;
            }
            if (z->start - 150.0 > prog->unk_100) {
                continue;
            }
            if (z->type == 1 && !cpu_bit(ai->flags, 28)) {
                if (cpu_level.unk_3 != 0) {
                    continue;
                }
                if (z->end < prog->unk_100) {
                    continue;
                }
                if (car->speed > 95.0) {
                    continue;
                }
                if ((prog->unk_7C & 0x400000) && fabs(ai->lateral) > 0.25) {
                    continue;
                }
                if (ai->lateral > z->left && ai->lateral < z->right) {
                    tmp = ai->lateral;
                } else {
                    if (!(prog->unk_7C & 0x1400000)) {
                        lim = 0.5 - 10.0 * scale;
                        lo = CLAMP(z->left, -lim, lim);
                        hi = CLAMP(z->right, -lim, lim);
                    } else {
                        lo = z->left;
                        hi = z->right;
                    }
                    if (ai->lateral < lo) {
                        hi = lo + 0.5 * (hi - lo);
                    }
                    if (ai->lateral > hi) {
                        lo = lo + 0.5 * (hi - lo);
                    }
                    tmp = lo + (hi - lo) * (cpu_rand() / 32767.0f);
                }
                if ((ai->flags >> 28) & 1) {
                    if (ai->zone_type == 3 || fabs(ai->lateral - tmp) < fabs(ai->lateral - best)) {
                        best = tmp;
                        ai->zone = zi;
                        ai->zone_type = z->type;
                    }
                    continue;
                }
            } else {
                if (z->type != 3) {
                    continue;
                }
                if (ai->zone_type == 1) {
                    continue;
                }
                if (cpu_level.unk_2 != 0) {
                    continue;
                }
                if (z->start < prog->unk_100) {
                    continue;
                }
                if (car->flags & 2) {
                    continue;
                }
                slot = cpu_find_slot(zi);
                if (slot == -1) {
                    mask = 0;
                } else {
                    mask = cpu_slots[slot].mask;
                }
                if (!cpu_bit(mask, car->id)) {
                    continue;
                }
                tmp = max_speed * (0.5 * (z->left + z->right));
                if (prog->unk_7C & 0x1400000) {
                    f32 alt;

                    if (tmp < 0.0) {
                        alt = tmp + max_speed;
                    } else {
                        alt = tmp - max_speed;
                    }
                    tmp = tmp - prog->unk_108;
                    alt = alt - prog->unk_108;
                    tmp = fabs(tmp) < fabs(alt) ? tmp : alt;
                    if (fabs(tmp) > 0.4 * max_speed) {
                        continue;
                    }
                } else {
                    tmp = tmp - prog->unk_108;
                }
                if (abs(lbl_8006D24C(tmp, z->end - prog->unk_100)) > 0x1000) {
                    continue;
                }
                tmp = 0.5 * (z->right + z->left);
                if ((ai->flags >> 28) & 1) {
                    if (ai->zone_type == 1) {
                        continue;
                    }
                    if (fabs(ai->lateral - tmp) < fabs(ai->lateral - best)) {
                        best = tmp;
                        ai->zone = zi;
                        ai->zone_type = z->type;
                    }
                    continue;
                }
            }
            best = tmp;
            ai->zone = zi;
            ai->zone_type = z->type;
            ai->flags |= 0x10000000;
            if (z->type == 1) {
                ai->flags &= ~0x4000000;
            }
            if (ai->state == 5 || ai->state == 6) {
                ai->timer = 0;
                ai->state = 1;
                ai->rival = 99;
            }
        }
        if (ai->state != 5) {
            ai->target = best;
        }
    }
    if (!done && ai->state == 5) {
        done = 1;
    }
    if (!done && ((ai->flags >> 28) & 1) && ai->zone_type == 1) {
        done = 1;
        zone = &cpu_zones[ai->zone];
        if ((prog->unk_8C != 0 && zone->group != prog->unk_8C) || car->speed > 99.0 || zone->end < prog->unk_100 ||
            ((prog->unk_7C & 0x400000) && fabs(ai->lateral) > 0.25)) {
            ai->flags &= ~0x10000000;
            ai->zone = 0xFF;
            ai->zone_type = 0xFF;
            done = 0;
        }
    }

    /* steer along the course line */
    if (!done) {
        use_line = 1;
        if (((ai->flags >> 28) & 1) && ai->zone_type == 3) {
            slot = cpu_find_slot(ai->zone);
            zone = &cpu_zones[ai->zone];
            if (!(prog->unk_7C & 0x1400000) && fabs(ai->lateral) > fabs(ai->prev_lateral) && fabs(ai->lateral) > 0.4 && !(car->flags & 2)) {
                ai->flags &= ~0x10000000;
                ai->zone = 0xFF;
                ai->zone_type = 0xFF;
                ai->cooldown = 5;
            } else if ((prog->unk_8C != 0 && zone->group != prog->unk_8C) || zone->start < prog->unk_100) {
                ai->flags &= ~0x10000000;
                ai->zone = 0xFF;
                ai->zone_type = 0xFF;
            } else {
                fn_8006E250(car->pos, a);
                fn_8006E250(cpu_slots[slot].pos, b);
                use_line = 0;
            }
        }
        if (use_line) {
            s32 next;
            s32 prev;
            s32 far;
            s32 idx;
            s32 n;

            idx = prog->unk_100 * cpu_line_scale;
            n = 0;
            while (LINE(ai->lane, idx) == -128) {
                n++;
                if (--idx < 0) {
                    idx += 512;
                }
            }
            t = cpu_line_scale * (prog->unk_100 - cpu_line_step * (idx + n));
            next = idx;
            do {
                if (++next >= 512) {
                    next -= 512;
                }
            } while (LINE(ai->lane, next) == -128);
            far = cpu_line_scan(ai, next, &t);
            prev = far;
            do {
                if (--prev < 0) {
                    prev += 512;
                }
            } while (LINE(ai->lane, prev) == -128);
            fn_8006E250(POINT(ai->lane, idx), a);
            fn_8006E250(POINT(ai->lane, next), c);
            fn_8006E250(POINT(ai->lane, prev), d);
            fn_8006E250(POINT(ai->lane, far), b);
            a[0] = a[0] * (1.0 - t) + c[0] * t;
            a[1] = a[1] * (1.0 - t) + c[1] * t;
            a[2] = a[2] * (1.0 - t) + c[2] * t;
            b[0] = d[0] * (1.0 - t) + b[0] * t;
            b[1] = d[1] * (1.0 - t) + b[1] * t;
            b[2] = d[2] * (1.0 - t) + b[2] * t;
        }
        dist = b[0];
        side = SIGN(dist);
        dist = fabs(dist);
        angle = -lbl_8006D24C(a[0] - b[0], lbl_8006D0B4(cpu_dist2(a, b)));
        dir = angle > 0 ? 1 : (angle < 0 ? -1 : 0);
        abs_angle = abs(angle);
        ai->target = ai->lateral + b[0] * scale;
        ahead = -b[2];
    } else {
        f32 want_lat = ai->target * max_speed;
        f32 off = want_lat - prog->unk_108;

        if (prog->unk_7C & 0x1400000) {
            f32 off_r = want_lat - (prog->unk_108 + max_speed);
            f32 off_l = want_lat - (prog->unk_108 - max_speed);

            if (fabs(off) > fabs(off_r)) {
                off = off_r;
            }
            if (fabs(off) > fabs(off_l)) {
                off = off_l;
            }
        }
        side = SIGN(off);
        dist = fabs(off);
        ahead = 0.0f;
    }

    /* boost */
    if (ai->state == 4 || (ai->state == 3 && ai->spin_timer == 0) ||
        (ai->state == 6 && fn_1_8CAF4(car->id, ai->rival) < 0.0) || ai->unk_3A != 0 || ((ai->flags >> 4) & 1)) {
        boost = 0.0f;
    } else {
        none = 1;
        first = 1;
        tmp = 10000000.0f;
        for (zone = cpu_zones; zone->end > -1.0; zone++) {
            if (zone->type != 1) {
                continue;
            }
            if (zone->group != 0 && prog->unk_8C != 0 && zone->group != prog->unk_8C) {
                continue;
            }
            if (first) {
                first_start = zone->start;
                first = 0;
            }
            if (zone->end < prog->unk_100) {
                continue;
            }
            if (zone->start < prog->unk_100 && zone->end > prog->unk_100 && (zone->group == 0 || zone->group == prog->unk_8C)) {
                tmp = 0.0f;
                none = 0;
                break;
            }
            if (zone->start - prog->unk_100 < tmp) {
                tmp = zone->start - prog->unk_100;
                none = 0;
            }
        }
        if (none) {
            if (prog->unk_118 == lbl_1_bss_3C30.unk_4 - 1 && cpu_level.unk_0 > 1 && cpu_level.unk_0 < 5) {
                tmp = *lbl_1_bss_3BE0->unk_90 - prog->unk_100;
            } else if (!first) {
                tmp = *lbl_1_bss_3BE0->unk_90 + first_start - prog->unk_100;
            } else {
                tmp = 10000.0f;
            }
        }
        if (cpu_level.unk_0 == 0) {
            tmp = tmp > 3000.0 ? tmp : 3000.0;
        } else if (cpu_level.unk_0 == 1) {
            tmp = tmp > 1000.0 ? tmp : 1000.0;
        } else if (cpu_level.unk_0 == 2) {
            tmp = tmp > 500.0 ? tmp : 500.0;
        }
        boost = cpu_params[ai->param].boost / 100.0;
        if (tmp > 0.0) {
            boost = boost * ((car->speed / 20.0f) / (tmp / (50.0 / 9.0)));
        }
        switch (ai->state) {
        case 0:
            boost *= 0.8;
        case 1:
            boost *= 0.8;
        case 2:
        case 5:
        case 6:
            if (car->unk_17C < 200.0) {
                boost *= 2.0;
            } else if (car->unk_17C < 400.0) {
                boost *= 1.5;
            } else if (car->unk_17C < 800.0) {
                boost *= 1.25;
            }
            boost *= cpu_level.unk_1C;
            if ((ai->flags >> 21) & 1) {
                boost *= 1.5;
            }
            break;
        }
    }

    /* throttle */
    if (ai->state == 3 && ai->spin_timer == 0) {
        ai->unk_10 = 1.0f;
    } else {
        ai->unk_10 = 0.0f;
    }
    switch (ai->state) {
    case 0:
        tmp = prog->unk_F8 - cpu_best_progress - 50.0;
        tmp = CLAMP(tmp, 0.0, 300.0);
        if (cpu_best_rank == prog->unk_115) {
            ai->throttle = 1.0f;
        } else {
            ai->throttle = cpu_level.unk_8 + tmp / 300.0 * (cpu_level.unk_C - cpu_level.unk_8);
        }
        break;
    default:
    case 1:
        ai->throttle = cpu_level.unk_8;
        break;
    case 2:
        tmp = cpu_worst_progress - prog->unk_F8 - 50.0;
        tmp = CLAMP(tmp, 0.0, 300.0);
        ai->throttle = cpu_level.unk_8 + tmp / 300.0 * (cpu_level.unk_4 - cpu_level.unk_8);
        break;
    case 4:
        ai->throttle = 0.5f;
        break;
    case 3:
        if (abs_angle < 0x4000) {
            ai->throttle = cpu_level.unk_4;
        } else {
            ai->throttle = 0.0f;
        }
        break;
    case 5:
        if (ai->throttle < cpu_level.unk_C) {
            ai->throttle = cpu_level.unk_C;
        }
        break;
    case 6:
        if (fn_1_8CAF4(car->id, ai->rival) > 0.0f) {
            ai->throttle = cpu_level.unk_4;
        } else {
            ai->throttle = 0.0f;
        }
        break;
    }
    switch (ai->state) {
    case 0:
    case 1:
    case 2:
        if ((ai->flags >> 15) & 1) {
            ai->throttle *= 1.1;
        } else if ((ai->flags >> 14) & 1) {
            ai->throttle *= 0.9;
        }
        break;
    }
    if (!((ai->flags >> 24) & 1) || (car->flags & 0x3800000)) {
        if (fn_1_8677C(car->id) != 0) {
            if (ai->blink > 254) {
                ai->blink = 253;
            }
            ai->blink++;
            if (ai->blink & 1) {
                ai->throttle = 0.0f;
            }
            boost = 0.0f;
        }
    }
    if ((ai->flags >> 23) & 1) {
        ai->flags |= 0x40000000;
    }
    if (boost < 1.1920929e-07f) {
        ai->flags &= ~0x20000;
    } else if (car->speed > (f32)cpu_params[ai->param].speed) {
        if (car->unk_18A == 0 && ((ai->flags >> 17) & 1)) {
            ai->flags |= 0x80000000;
            ai->flags &= ~0x20000;
        } else if (cpu_rand() / 32767.0f < boost) {
            if (car->unk_18A != 0) {
                ai->flags |= 0x20000;
            } else {
                ai->flags |= 0x80000000;
            }
        }
    }

    /* steering */
    base = 0.0f;
    lo = 8.0f;
    hi = 20.0f;
    if ((*(u32 *)ai >> 22) & 1) {
        lo = lo * (0.8 * car->unk_1C / 20.0);
    }
    if ((ai->flags >> 18) & 1) {
        if (dist < lo) {
            ai->flags &= ~0x40000;
        }
    } else if (dist > 20.0f) {
        ai->flags |= 0x40000;
    }
    if ((ai->flags >> 19) & 1) {
        if (abs_angle < 0x600) {
            ai->flags &= ~0x80000;
        }
    } else if (abs_angle > 0x2000) {
        ai->flags |= 0x80000;
    }
    if (!((ai->flags >> 28) & 1)) {
        base = ai->unk_24;
        if (!(prog->unk_7C & 0x1400000)) {
            f64 used = max_speed * fabs(ai->lateral);
            f64 limit = 0.5 * max_speed - 10.0;

            if (base + used > limit) {
                room = limit - used;
                base = room > 0.0f ? room : 0.0f;
            }
        }
        lo += base;
        hi += base;
    }
    switch (ai->state) {
    case 4:
        if (abs_angle < 0x2000) {
            ai->steer = 0.025 * cpu_level.unk_14 + fabs(ai->steer);
        } else {
            ai->steer = fabs(ai->steer) - 0.1 * cpu_level.unk_14;
        }
        dir = side;
        break;
    case 3:
    default:
        if (ai->state == 3 && ai->spin_timer == 0) {
            if (car->unk_17C < 400.0) {
                ai->steer = cpu_level.unk_14;
                dir = -side;
            } else {
                ai->steer = 0.0f;
            }
        } else if ((ai->flags >> 18) & 1) {
            if (dist > hi) {
                ai->steer = cpu_level.unk_14;
                dir = side;
            } else if (dist > lo) {
                ai->steer = cpu_level.unk_14 * ((dist - lo) / (hi - lo));
                dir = side;
            } else {
                ai->steer = 0.0f;
            }
        } else if (abs_angle > 0x1000) {
            ai->steer = cpu_level.unk_14;
        } else {
            ai->steer = abs_angle / 4096.0f * cpu_level.unk_14;
        }
        break;
    }
    switch (ai->state) {
    case 4:
        ai->unk_14 = cpu_level.unk_18;
        break;
    case 3:
    default:
        if (ai->state == 3 && ai->spin_timer == 0) {
            if (car->unk_17C < 400.0) {
                ai->unk_14 = -cpu_level.unk_18;
            } else {
                ai->unk_14 = 0.0f;
            }
            break;
        }
        if ((ai->flags >> 19) & 1) {
            if (abs_angle > 0x1000) {
                ai->unk_14 = cpu_level.unk_18;
            } else {
                ai->unk_14 = abs_angle / 4096.0f * cpu_level.unk_18;
            }
            side = dir;
        } else if (dist < base) {
            ai->unk_14 = 0.0f;
        } else if (dist < lo) {
            ai->unk_14 = cpu_level.unk_18 * ((dist - base) / (lo - base));
        } else {
            ai->unk_14 = cpu_level.unk_18;
        }
        if (!((ai->flags >> 19) & 1) && ahead > 50.0) {
            f32 fade = 1.3 + -0.006 * ahead;

            ai->unk_14 *= CLAMP(fade, 0.1, 1.0);
        }
        break;
    }
    if (car->flags & 2) {
        if (ai->last_pos != prog->unk_100 && fabs(ai->lateral) < 0.45) {
            ai->unk_8 = 1.0f;
        } else {
            f32 tilt;

            fn_8006E2B0(car->unk_1BC, v);
            tilt = lbl_8006D24C(-v[2], v[1]) / 2048.0f;
            ai->unk_8 = CLAMP(tilt, -1.0, 1.0);
            ai->throttle = cpu_level.unk_4;
        }
    } else {
        ai->unk_8 = 0.0f;
    }
    if (ai->state == 6) {
        ai->flags |= 0x100000;
    }
    ai->steer = CLAMP(ai->steer, -cpu_level.unk_14, cpu_level.unk_14);
    ai->unk_8 = CLAMP(ai->unk_8, -1.0, 1.0);
    ai->unk_14 = CLAMP(ai->unk_14, -cpu_level.unk_18, cpu_level.unk_18);
    ai->throttle = CLAMP(ai->throttle, 0.0, cpu_level.unk_4);
    ai->unk_10 = CLAMP(ai->unk_10, 0.0, 1.0);
    ai->steer = ai->steer * dir;
    ai->unk_14 = ai->unk_14 * side;
    ai->last_pos = prog->unk_100;
}
#pragma fp_contract reset
/* fzgx:end fn_1_C4ABC */

/* fzgx:begin fn_1_C6ED4 */
typedef struct Fn1C6ED4Data {
    u32 flags;
    f32 value_4;
    f32 value_8;
    f32 value_c;
    f32 value_10;
    f32 value_14;
} Fn1C6ED4Data;

typedef struct Fn1C6ED4Enemy {
    u32 flags;
    u8 pad_4[0x1f0];
    f32 output_1f4;
    f32 output_1f8;
    f32 output_1fc;
    f32 output_200;
    f32 output_204;
    u8 pad_208[0x27c];
    Fn1C6ED4Data *data;
} Fn1C6ED4Enemy;

void fn_1_C6ED4(Fn1C6ED4Enemy *self) {
    Fn1C6ED4Data *data = self->data;

    self->output_1fc = data->value_4;
    self->output_1f4 = data->value_8;
    self->output_200 = data->value_c;
    self->output_204 = data->value_10;
    self->output_1f8 = data->value_14;

    if (data->flags >> 31) {
        self->flags |= 0x40;
        data->flags &= ~((u32)1 << 31);
    }
    if ((data->flags >> 30) & 1) {
        self->flags |= 0x1000;
        data->flags &= ~((u32)1 << 30);
    }
    if ((data->flags >> 20) & 1) {
        self->flags |= 0x8;
        data->flags &= ~((u32)1 << 20);
    }
}
/* fzgx:end fn_1_C6ED4 */

/* fzgx:begin fn_1_C6F70 */
u32 fn_1_C6F70(void) {
    return lbl_1_bss_7AC54[0];
}
/* fzgx:end fn_1_C6F70 */

/* fzgx:begin fn_1_C6F80 */
void fn_1_C6F80(u8 value) {
    lbl_1_bss_7AC90[0] = value;
}
/* fzgx:end fn_1_C6F80 */

/* fzgx:begin fn_1_C6F8C */
extern u32 lbl_1_bss_7AC48[5];
extern void *lbl_801A6410;
extern void fn_1_46B4(void *, u32, void *, u32);
extern void fn_1_C489C(void);
extern u32 lbl_1_bss_7AC54[4];
extern u8 lbl_1_bss_7AC90[12];
extern u32 lbl_1_rodata_5D40[7];
extern u32 fn_1_5910(void *);
extern u8 fn_1_86810(void *);
extern u32 fn_1_3F7E0(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(u32);
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5D18;
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(u32);
extern void fn_1_49728(u32);
extern void fn_1_4AE0C(void *, ...);
extern const f32 lbl_1_rodata_5D5C;
extern const f32 lbl_1_rodata_5D60;
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_5D64;
extern const f32 lbl_1_rodata_5D68;
extern void fn_1_51E60(void *);
extern const f32 lbl_1_rodata_5D6C;
extern void fn_1_C8DC0(void);
extern void fn_80008E84(u32);
extern const f32 lbl_1_rodata_5D88;
extern const f32 lbl_1_rodata_5D8C;
extern void fn_1_4955C(f32, f32);
extern const f32 lbl_1_rodata_5CD4;
extern const f32 lbl_1_rodata_5D90;
extern void fn_1_4966C(f32, f32);
extern const f64 lbl_1_rodata_5C00;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5E0C;
extern int sprintf(char *, const char *, ...);
extern s16 fn_1_12C7B8(s16);
extern s32 fn_1_465D0(char *, s32);
extern s8 fn_1_86690(s8);
extern u32 fn_1_12C930(u32);
extern u8 fn_1_86624(void);
extern u8 lbl_1_bss_9C;
extern void *fn_1_868C0(s8);
extern void fn_80006E10(u32);

extern const f32 lbl_1_rodata_5A50;
extern const f32 lbl_1_rodata_5A54;
extern const f32 lbl_1_rodata_5A58;
extern const f32 lbl_1_rodata_5A5C;
extern const f32 lbl_1_rodata_5A60;
extern const f32 lbl_1_rodata_5A64;

extern s16 fn_1_3F0C8(void);
extern u32 fn_1_D0428(void);
extern int fn_1_485A8(int);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(int);
extern void fn_1_52088(void);
extern u8 fn_1_D2D48(void);
extern u32 fn_1_C8294(u32, u8, u32);
extern void fn_1_CF5B0(s32);
extern s32 camera_get_flags(void);

/* six EnemyCtrlEntry rows for fn_1_C8294, copied whole onto the stack */
typedef struct {
	s16 x;
	s16 y;
	f32 scale;
	s16 ofs_x;
	s16 ofs_y;
} fn_1_C6F8C_Entry;

typedef struct {
	fn_1_C6F8C_Entry entries[6];
} fn_1_C6F8C_Msg;

extern const fn_1_C6F8C_Msg lbl_1_rodata_59C0;
extern const fn_1_C6F8C_Msg lbl_1_rodata_5A08;

typedef struct {
	u8 pad_0[0x2B4];
	u32 w[4];
	f32 unk_2C4;
	f32 unk_2C8;
	f32 unk_2CC;
	f32 unk_2D0;
	f32 unk_2D4;
	f32 unk_2D8;
	f32 unk_2DC;
} fn_1_C6F8C_Ctrl;

extern u8 lbl_1_data_3D290__fzgx_offset_0[];
extern u8 lbl_1_data_3D294__fzgx_offset_0[];
extern u8 lbl_1_data_3D2A0__fzgx_offset_0[];
extern u8 lbl_1_data_3D2AC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2B8__fzgx_offset_0[];
extern u8 lbl_1_data_3D2C4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2CC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2D4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2DC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2E4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2F0__fzgx_offset_0[];
extern u8 lbl_1_data_3D300__fzgx_offset_0[];
extern u8 lbl_1_data_3D310__fzgx_offset_0[];
extern u8 lbl_1_data_3D318__fzgx_offset_0[];
extern u8 lbl_1_data_3D320__fzgx_offset_0[];
extern u8 lbl_1_data_3D32C__fzgx_offset_0[];
extern u8 lbl_1_data_3D338__fzgx_offset_0[];
extern u8 lbl_1_data_3D348__fzgx_offset_0[];
extern u8 lbl_1_data_3D350__fzgx_offset_0[];
extern u8 lbl_1_data_3D35C__fzgx_offset_0[];
extern u8 lbl_1_data_3D368__fzgx_offset_0[];
extern u8 lbl_1_data_3D378__fzgx_offset_0[];
extern u8 lbl_1_data_3D380__fzgx_offset_0[];
extern u8 lbl_1_data_3D38C__fzgx_offset_0[];
extern u8 lbl_1_data_3D398__fzgx_offset_0[];
extern u8 lbl_1_data_3D3A8__fzgx_offset_0[];
extern u8 lbl_1_data_3D3B0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3BC__fzgx_offset_0[];
extern u8 lbl_1_data_3D3C4__fzgx_offset_0[];
extern u8 lbl_1_data_3D3D0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3E0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3EC__fzgx_offset_0[];
extern u8 lbl_1_data_3D3F8__fzgx_offset_0[];
extern u8 lbl_1_data_3D400__fzgx_offset_0[];
extern u8 lbl_1_data_3D414__fzgx_offset_0[];
extern u8 lbl_1_data_3D424__fzgx_offset_0[];
extern u8 lbl_1_data_3D434__fzgx_offset_0[];
extern u8 lbl_1_data_3D440__fzgx_offset_0[];
extern u8 lbl_1_data_3D44C__fzgx_offset_0[];
extern u8 lbl_1_data_3D45C__fzgx_offset_0[];
extern u8 lbl_1_data_3D464__fzgx_offset_0[];
extern u8 lbl_1_data_3D470__fzgx_offset_0[];
extern u8 lbl_1_data_3D478__fzgx_offset_0[];
extern u8 lbl_1_data_3D480__fzgx_offset_0[];
extern u8 lbl_1_data_3D488__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_3D290_gap_0[173] = {0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, (u32)lbl_1_data_3D290__fzgx_offset_0, (u32)lbl_1_data_3D294__fzgx_offset_0, (u32)lbl_1_data_3D2A0__fzgx_offset_0, (u32)lbl_1_data_3D2AC__fzgx_offset_0, (u32)lbl_1_data_3D2B8__fzgx_offset_0, (u32)lbl_1_data_3D2C4__fzgx_offset_0, (u32)lbl_1_data_3D2CC__fzgx_offset_0, (u32)lbl_1_data_3D2D4__fzgx_offset_0, (u32)lbl_1_data_3D2DC__fzgx_offset_0, (u32)lbl_1_data_3D2E4__fzgx_offset_0, (u32)lbl_1_data_3D2F0__fzgx_offset_0, (u32)lbl_1_data_3D300__fzgx_offset_0, (u32)lbl_1_data_3D310__fzgx_offset_0, (u32)lbl_1_data_3D318__fzgx_offset_0, (u32)lbl_1_data_3D320__fzgx_offset_0, (u32)lbl_1_data_3D32C__fzgx_offset_0, (u32)lbl_1_data_3D338__fzgx_offset_0, (u32)lbl_1_data_3D348__fzgx_offset_0, (u32)lbl_1_data_3D350__fzgx_offset_0, (u32)lbl_1_data_3D35C__fzgx_offset_0, (u32)lbl_1_data_3D368__fzgx_offset_0, (u32)lbl_1_data_3D378__fzgx_offset_0, (u32)lbl_1_data_3D380__fzgx_offset_0, (u32)lbl_1_data_3D38C__fzgx_offset_0, (u32)lbl_1_data_3D398__fzgx_offset_0, (u32)lbl_1_data_3D3A8__fzgx_offset_0, (u32)lbl_1_data_3D3B0__fzgx_offset_0, (u32)lbl_1_data_3D3BC__fzgx_offset_0, (u32)lbl_1_data_3D3C4__fzgx_offset_0, (u32)lbl_1_data_3D3D0__fzgx_offset_0, (u32)lbl_1_data_3D3E0__fzgx_offset_0, (u32)lbl_1_data_3D3EC__fzgx_offset_0, (u32)lbl_1_data_3D3F8__fzgx_offset_0, (u32)lbl_1_data_3D400__fzgx_offset_0, (u32)lbl_1_data_3D414__fzgx_offset_0, (u32)lbl_1_data_3D424__fzgx_offset_0, (u32)lbl_1_data_3D434__fzgx_offset_0, (u32)lbl_1_data_3D440__fzgx_offset_0, (u32)lbl_1_data_3D44C__fzgx_offset_0, (u32)lbl_1_data_3D45C__fzgx_offset_0, (u32)lbl_1_data_3D464__fzgx_offset_0, (u32)lbl_1_data_3D470__fzgx_offset_0, (u32)lbl_1_data_3D478__fzgx_offset_0, (u32)lbl_1_data_3D480__fzgx_offset_0, (u32)lbl_1_data_3D488__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_3D290_w[4] = {0xFF9FFFFF, 0xFF9FFFFF, 0xFF9FFFFF, 0xFF9FFFFF}; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2C4 = 632.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2C8 = -68.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2CC = 429.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2D0 = 460.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2D4 = 91.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2D8 = 160.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2DC = 160.0f; /* fzgx-allow: A1 measured pool bytes and bindings */

static inline u32 fn_1_C6F8C_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_common_subs off
typedef struct lbl_1_bss_3C30_t {
    u32 unk_0;
    u8 pad_4[4];
	u8 unk_8;
	u8 pad_9[0x9b];
	u16 unk_A4;
	u8 pad_A6[0x1416];
} lbl_1_bss_3C30_t;

typedef struct lbl_1_bss_8B3A0_t {
	u8 pad_0[0x94];
	u32 unk_94;
	u8 pad_98[0xb4];
} lbl_1_bss_8B3A0_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_3C30_t fzgx_obj_lbl_1_bss_3C30;
extern u32 lbl_1_bss_523C[8];
lbl_1_bss_8B3A0_t fzgx_obj_lbl_1_bss_8B3A0;
extern u32 lbl_1_bss_8B4EC[32];
extern u32 lbl_1_bss_8B5CC[8];

#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
void fn_1_C6F8C(void) {
	fn_1_C6F8C_Msg msgA;
	u16 idx;
	fn_1_C6F8C_Msg msgB;
	s32 i;

	if (((2) == (*(s16 *)&lbl_1_bss_960)) && (fn_1_3F0C8() == 0x25 || fn_1_3F0C8() == 0x26)) {
		return;
	}

	if (((((*(s16 *)&lbl_1_bss_960)) == ((2)))) && fn_1_3F0C8() == 0x27) {
		fn_1_D0428();
	} else {
		fzgx_pool_native_lbl_1_data_3D290_unk_2C4 = lbl_1_rodata_5A50;
		fzgx_pool_native_lbl_1_data_3D290_unk_2C8 = lbl_1_rodata_5A54;
		fzgx_pool_native_lbl_1_data_3D290_unk_2CC = lbl_1_rodata_5A58;
		fzgx_pool_native_lbl_1_data_3D290_unk_2D0 = lbl_1_rodata_5A5C;
		fzgx_pool_native_lbl_1_data_3D290_unk_2D4 = lbl_1_rodata_5A60;
		fzgx_pool_native_lbl_1_data_3D290_unk_2D8 = lbl_1_rodata_5A64;
		fzgx_pool_native_lbl_1_data_3D290_unk_2DC = lbl_1_rodata_5A64;
	}

	for (i = 0; i < 4; i++) {
		u32 x = fn_1_C6F8C_array_read(fzgx_pool_native_lbl_1_data_3D290_w, i);

		if (x & 1) {
			fzgx_pool_native_lbl_1_data_3D290_w[i] = ~x;
		}
	}

	if (fn_1_485A8(0x94) == 0) {
		return;
	}

	if (fn_1_58C4() == 1) {
		fn_1_52070(0x60);
	}

	if ((fn_1_C6F8C_array_read(fzgx_pool_native_lbl_1_data_3D290_w, 0) >> 31) && camera_get_flags() == 0 && fzgx_obj_lbl_1_bss_3C30.unk_8 < 2) {
		u8 kind = fn_1_D2D48();

		if ((fzgx_obj_lbl_1_bss_8B3A0.unk_94 & 0x40000000) == 0) {
			msgA = lbl_1_rodata_59C0;
			fn_1_C8294((u32)&msgA, kind, 1);
		} else {
			msgB = lbl_1_rodata_5A08;
			fn_1_C8294((u32)&msgB, kind, 1);
		}
	}

	fn_1_52088();

	if (fn_1_58C4() == 1) {
		fn_1_52070(0x140);
	}

	if (fzgx_obj_lbl_1_bss_8B3A0.unk_94 & 0x40000000) {
		s32 v;
		s32 t;
		s32 q;

		if (fzgx_obj_lbl_1_bss_3C30.unk_0 & 0x40000) {
			t = 0x63;
			q = ((s32)fzgx_obj_lbl_1_bss_3C30.unk_A4 + 0x3b) / 60;
			if (q < 0x63) {
				t = q;
			}
			v = t;
		}
		fn_1_CF5B0(v);
	}

	fn_1_52088();
}
#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_C6F8C */

/* fzgx:begin fn_1_C7224 */
#include "types.h"


extern s16 fn_1_3F0C8(void);
extern int fn_1_485A8(int);
extern void fn_1_C771C(void);
extern u32 fn_1_58C4(void);
extern void fn_1_C72D4(void);
extern void fn_1_C742C(void);

typedef struct {
    u8 padding[0x94];
    u32 flags;
} Fn1C7224State;



void fn_1_C7224(void) {
    if ((*(s16 *)&lbl_1_bss_960) == 2 &&
        (fn_1_3F0C8() == 0x25 || fn_1_3F0C8() == 0x26)) {
        return;
    }

    if (fn_1_485A8(0x94) != 0) {
        if ((*(Fn1C7224State *)&lbl_1_bss_8B3A0).flags & 0x40000000) {
            fn_1_C771C();
        } else if (fn_1_58C4() == 1) {
            if (!((*(Fn1C7224State *)&lbl_1_bss_8B3A0).flags & 0x40000000)) {
                fn_1_C72D4();
            } else {
                fn_1_C771C();
            }
        } else {
            fn_1_C742C();
        }
    }
}
/* fzgx:end fn_1_C7224 */

/* fzgx:begin fn_1_C72D4 noprologue */
#include "types.h"

typedef struct fn_1_C72D4_EnemyCtrl {
    unsigned char pad_000[0x118];
    int field_118;
    unsigned char pad_11c[0xd0];
    unsigned char field_1ec;
    unsigned char field_1ed;
    unsigned short field_1ee;
} fn_1_C72D4_EnemyCtrl;

extern s16 camera_get_mode(void);
extern fn_1_C72D4_EnemyCtrl *fn_1_8627C(int mode);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(int value);
extern void fn_1_CA8FC(int mode);
extern void fn_1_52088(void);
extern void fn_1_CA2A4(int mode);
extern void fn_1_CD51C(int mode);
extern void fn_1_CDC8C(void);
extern void fn_1_CEB38(void);
extern void fn_1_C8DC0(int mode);
extern void fn_1_CADC4(int mode);
extern u32 fn_1_3F114(void);
extern void fn_1_CC280(int, int, int, int);
extern u8 fn_1_CFA0C(int, int);
extern int fn_1_CBC24(int, int, u8, u8, u16);
extern int fn_1_5910(void);
extern void fn_1_CB424(int, int, int);
extern void fn_1_CB028(int, int);
extern void fn_1_CAB38(int, int, int);

void fn_1_C72D4(void) {
    int mode;
    fn_1_C72D4_EnemyCtrl *enemy;
    int offset;

    mode = camera_get_mode();
    if (mode == -1 || mode < 0) {
        return;
    }
    enemy = fn_1_8627C(mode);
    if (enemy != 0) {
        if (fn_1_58C4() == 1)
            fn_1_52070(0x60);
        fn_1_CA8FC(mode);
        fn_1_52088();
        if (fn_1_58C4() == 1)
            fn_1_52070(0x140);
        fn_1_CA2A4(mode);
        fn_1_CD51C(mode);
        fn_1_CDC8C();
        fn_1_CEB38();
        fn_1_52088();
        if (fn_1_58C4() == 1)
            fn_1_52070(0x220);
        offset = 0;
        fn_1_C8DC0(mode);
        fn_1_CADC4(mode);
        fn_1_CC280(0x19a, 0x18, enemy->field_118 + 1,
            fn_1_3F114() & 0xff);
        if (fn_1_CFA0C(0x268, 0x43) != 0)
            offset = 0x25;
        fn_1_CBC24(0x1bc, offset + 0x43, enemy->field_1ec,
            enemy->field_1ed, enemy->field_1ee);
        fn_1_CB424(0x269, offset + 0x6e, fn_1_5910());
        fn_1_CB028(0x269, offset + 0x96);
        fn_1_CAB38(mode, 0x268, offset);
        fn_1_52088();
    }
}
/* fzgx:end fn_1_C72D4 */

/* fzgx:begin fn_1_C742C noprologue */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


extern s32 fn_1_5910();


extern f32 fn_1_519FC(f32 value);


extern void fn_1_C742C(void);
extern s16 camera_get_mode(void);
extern void fn_1_52070(u32 value);


extern void fn_1_52088(void);


extern void fn_1_CD51C(void *object);


typedef void (*fn_1_C742C_DrawFunc)(s32, s32, s32);
typedef struct fn_1_C742C_Vec {
f32 x;
f32 y;
f32 z;
} fn_1_C742C_Vec;
typedef struct fn_1_C742C_Funcs { fn_1_C742C_DrawFunc f[6]; } fn_1_C742C_Funcs;
typedef struct fn_1_C742C_Offsets { fn_1_C742C_Vec v[3][4]; } fn_1_C742C_Offsets;
typedef struct fn_1_C742C_Positions { fn_1_C742C_Vec v[3][6]; } fn_1_C742C_Positions;
typedef struct fn_1_C742C_Values { s32 v[6]; } fn_1_C742C_Values;
extern const fn_1_C742C_Funcs lbl_1_rodata_5A68;
extern const fn_1_C742C_Offsets lbl_1_rodata_5A80;
extern const fn_1_C742C_Positions lbl_1_rodata_5B10;
extern const fn_1_C742C_Values lbl_1_rodata_5BE8;
extern s16 camera_get_mode(void);
extern s32 fn_1_5910(void);
extern u8 fn_1_5348(void);
extern void fn_1_CFA4C(u32, u32);
extern s32 camera_get_state(void);
extern f32 fn_1_519FC(f32);
extern void fn_1_52070(u32);
extern void fn_1_52088(void);
extern void fn_1_CD51C(void *);
extern void fn_1_C7AA0(void);
extern void fn_1_C7874(void);
void fn_1_C742C(void) {
fn_1_C742C_Funcs funcs = lbl_1_rodata_5A68;
fn_1_C742C_Offsets offsets = lbl_1_rodata_5A80;
fn_1_C742C_Positions positions = lbl_1_rodata_5B10;
fn_1_C742C_Values values = lbl_1_rodata_5BE8;
s32 idx;
fn_1_C742C_Vec *pos;
s32 *val;
fn_1_C742C_DrawFunc *fn;
fn_1_C742C_Vec *off;
s32 row;
s32 i;
f32 x;
f32 y;
s32 mode;
mode = camera_get_mode();
idx = fn_1_5910();
if (mode == -1 || mode < 0) {
fn_1_C742C_Vec *v = &offsets.v[2][idx];
if (fn_1_5348() == 3) {
fn_1_CFA4C((s32)v->x, (s32)v->y);
}
return;
}
switch ((s8)camera_get_state()) {
case 1:
row = 0;
break;
case 2:
row = 1;
break;
case 6:
case 7:
case 8:
row = 2;
break;
default:
return;
}
pos = positions.v[row];
val = values.v;
fn = funcs.f;
off = &offsets.v[row][idx];
for (i = 0; i < 6; i++) {
x = pos->x + off->x;
y = pos->y + off->y;
fn_1_52070((s32)fn_1_519FC((f32)*val));
(*fn)(mode, (s32)x, (s32)y);
fn_1_52088();
pos++;
val++;
fn++;
}
fn_1_CD51C((void *)mode);
switch ((s8)camera_get_state()) {
case 1:
fn_1_C7AA0();
break;
case 2:
fn_1_C7874();
break;
case 6:
case 7:
case 8:
fn_1_C7AA0();
fn_1_C7874();
break;
}
}
/* fzgx:end fn_1_C742C */

/* fzgx:begin fn_1_C771C noprologue */
#include "types.h"

typedef struct fn_1_C771C_EnemyCtrl {
    u8 pad_000[0x118];
    int field_118;
    u8 pad_11c[0xd0];
    u8 field_1ec;
    u8 field_1ed;
    u16 field_1ee;
} fn_1_C771C_EnemyCtrl;

extern s16 camera_get_mode(void);
extern fn_1_C771C_EnemyCtrl *fn_1_8627C(int);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(int);
extern void fn_1_CA690(int, int, int);
extern void fn_1_52088(void);
extern void fn_1_CD51C(int);
extern void fn_1_CD7BC(int);
extern void fn_1_C8DC0(int);
extern void fn_1_CADC4(int);
extern u32 fn_1_3F114(void);
extern void fn_1_CC280(int, int, int, u32);
extern u32 fn_1_CFA0C(int, int);
extern void fn_1_CBC24(int, int, u8, u8, u16);
extern int fn_1_5910(void);
extern void fn_1_CB424(int, int, int);
extern void fn_1_CB028(int, int);
extern void fn_1_CAB38(int, int, int);

void fn_1_C771C(void) {
    int mode;
    fn_1_C771C_EnemyCtrl *ctrl;
    int value;

    mode = camera_get_mode();
    if (mode == -1 || mode < 0) {
        return;
    }
    ctrl = fn_1_8627C(mode);
    if (ctrl == 0) {
        return;
    }
    if (fn_1_58C4() == 1) {
        fn_1_52070(0x60);
    }
    fn_1_CA690(mode, 0x18, 0x19c);
    fn_1_52088();
    if (fn_1_58C4() == 1) {
        fn_1_52070(0x140);
    }
    fn_1_CD51C(mode);
    fn_1_CD7BC(mode);
    fn_1_52088();
    if (fn_1_58C4() == 1) {
        fn_1_52070(0x220);
    }
    value = 0;
    fn_1_C8DC0(mode);
    fn_1_CADC4(mode);
    fn_1_CC280(0x19a, 0x18, ctrl->field_118 + 1, fn_1_3F114() & 0xff);
    if ((fn_1_CFA0C(0x268, 0x43) & 0xff) != 0) {
        value = 0x25;
    }
    fn_1_CBC24(0x1bc, value + 0x43, ctrl->field_1ec,
               ctrl->field_1ed, ctrl->field_1ee);
    fn_1_CB424(0x269, value + 0x6e, fn_1_5910());
    fn_1_CB028(0x269, value + 0x96);
    fn_1_CAB38(mode, 0x268, value);
    fn_1_52088();
}
/* fzgx:end fn_1_C771C */

/* fzgx:begin fn_1_C7874 noprologue */
#include "types.h"
#include "font.h"

struct fn_1_C7874_Copy88 { u32 a[22]; };
struct fn_1_C7874_lbl_1_rodata_5C08 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
};
extern struct fn_1_C7874_lbl_1_rodata_5C08 lbl_1_rodata_5C08;
extern u32 lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_5C38;
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5C40;
extern const f32 lbl_1_rodata_5C44;
extern const f32 lbl_1_rodata_5C48;
extern const f64 lbl_1_rodata_5C00;
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

void fn_1_C7874(void) {
    FontDrawPacket packet;
    struct fn_1_C7874_lbl_1_rodata_5C08 positions;
    u32 i;
    positions = lbl_1_rodata_5C08;
    packet = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image = 0x9457;
    fn_1_51678(&packet, 0x9457, 0, 0, 4, 8);
    *(f32 *)((u8 *)&packet + 0x10) *= lbl_1_rodata_5C38;
    packet.x = lbl_1_rodata_5C3C;
    packet.y = lbl_1_rodata_5C40;
    *(f32 *)((u8 *)&packet + 0xC) = lbl_1_rodata_5C44;
    *(u16 *)((u8 *)&packet + 0x28) = 0x4000;
    *(u32 *)((u8 *)&packet + 0x30) = 10;
    fn_1_4F734(&packet);
    for (i = 0; i < 12; i++) {
        packet = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
        packet.image = 0x9457;
        fn_1_51678(&packet, packet.image, 4, 0, 4, 8);
        packet.x = lbl_1_rodata_5C3C;
        packet.y = (f32)((s32 *)&positions)[i];
        *(f32 *)((u8 *)&packet + 0xC) = lbl_1_rodata_5C48;
        *(u16 *)((u8 *)&packet + 0x28) = 0x4000;
        *(u32 *)((u8 *)&packet + 0x30) = 10;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_C7874 */

/* fzgx:begin fn_1_C7AA0 noprologue */
#include "types.h"
#include "font.h"

struct fn_1_C7AA0_Copy88 { u32 a[22]; };
struct fn_1_C7AA0_lbl_1_rodata_5C4C {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
};
extern struct fn_1_C7AA0_lbl_1_rodata_5C4C lbl_1_rodata_5C4C;
extern u32 lbl_1_rodata_26F8;
extern f32 lbl_1_rodata_5A64[1];
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5C40;
extern const f32 lbl_1_rodata_5C7C;
extern const f32 lbl_1_rodata_5C80;
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

void fn_1_C7AA0(void) {
    FontDrawPacket packet;
    struct fn_1_C7AA0_lbl_1_rodata_5C4C positions;
    u32 i;
    positions = lbl_1_rodata_5C4C;
    packet = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image = 0x9457;
    fn_1_51678(&packet, 0x9457, 0, 0, 4, 8);
    *(f32 *)((u8 *)&packet + 0x10) *= lbl_1_rodata_5A64[0];
    packet.x = lbl_1_rodata_5C3C;
    packet.y = lbl_1_rodata_5C40;
    *(f32 *)((u8 *)&packet + 0xC) = lbl_1_rodata_5C7C;
    *(u32 *)((u8 *)&packet + 0x30) = 10;
    fn_1_4F734(&packet);
    for (i = 0; i < 12; i++) {
        packet = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
        packet.image = 0x9457;
        fn_1_51678(&packet, packet.image, 4, 0, 4, 8);
        packet.x = (f32)((s32 *)&positions)[i];
        packet.y = lbl_1_rodata_5C40;
        *(f32 *)((u8 *)&packet + 0xC) = lbl_1_rodata_5C80;
        *(u32 *)((u8 *)&packet + 0x30) = 10;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_C7AA0 */

/* fzgx:begin fn_1_C7CBC noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;
typedef double f64;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


extern f32 lbl_1_rodata_26F8[22];


extern const f64 lbl_1_rodata_5C00;


extern const f32 lbl_1_rodata_5C88;
extern const f32 lbl_1_rodata_5C8C;
extern const f64 lbl_1_rodata_5C00;
extern int fn_1_4F734(FontDrawPacket *);
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_5C84;

#pragma opt_common_subs off

void fn_1_C7CBC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, f32 arg4, f32 arg5) {
u32 v1;
u32 v0;
f32 v2;
f64 v3;
f32 v5;
f32 v6;
f32 v7;
f32 v8;
f32 v4;
s32 v9;
f64 v11;
f32 v12;
f32 v10;
f64 v13;
f32 v15;
f32 v16;
f32 v14;
f64 v18;
u32 v19;
f32 v20;
f32 v17;
f64 v21;
f32 v23;
f32 v24;
f32 v22;
f64 v26;
u32 v27;
f32 v28;
f32 v25;
f64 v30;
f32 v31;
f32 v29;
f64 v33;
u32 v34;
f32 v35;
f32 v32;
struct Color { u8 r, g, b, a; } loc_8;
FontDrawPacket loc_C;
loc_8 = *(struct Color *)&lbl_1_rodata_5C84;
v0 = (0x10000 - 26839);
if ((s32)arg3 != 0) {
v0 = (0x10000 - 27592);
}
v1 = (0x10000 - 26838);
if ((s32)arg3 != 0) {
v1 = (0x10000 - 27591);
}
v2 = (f32)(lbl_1_rodata_5C88 * (f32)(lbl_1_rodata_5C8C * arg4));
loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v3 = lbl_1_rodata_5C00;
v5 = (f32)((f32)(s32)(s16)arg0 - v2);
v6 = (f32)(s32)(s16)arg1;
v7 = (f32)(v6 - v2);
loc_C.image = v0;
v8 = (f32)(s32)(s16)arg2;
loc_C.x = v5;
loc_C.y = v7;
loc_C.z = v8;
loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
loc_C.flags = 15;
fn_1_4F734(&loc_C);
loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v9 = ((s16)arg2 + 1);
v11 = lbl_1_rodata_5C00;
v12 = (f32)(s32)v9;
loc_C.image = v1;
loc_C.x = v5;
loc_C.y = v7;
loc_C.z = v12;
loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
loc_C.flags = 15;
*(struct Color *)((u8 *)&loc_C + 56) = loc_8;
fn_1_4F734(&loc_C);
loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v13 = lbl_1_rodata_5C00;
v15 = (f32)((f32)(s32)(s16)arg0 + v2);
loc_C.image = v0;
v16 = (f32)(s32)(s16)arg2;
loc_C.x = v15;
loc_C.y = v7;
loc_C.z = v16;
loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
loc_C.flags = (0x80000 + 13);
fn_1_4F734(&loc_C);
loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v18 = lbl_1_rodata_5C00;
v19 = (0x80000 + 13);
v20 = (f32)(s32)v9;
loc_C.image = v1;
loc_C.x = v15;
loc_C.y = v7;
loc_C.z = v20;
loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
loc_C.flags = v19;
*(struct Color *)((u8 *)&loc_C + 56) = loc_8;
fn_1_4F734(&loc_C);
loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v21 = lbl_1_rodata_5C00;
v23 = (f32)((f32)(s32)(s16)arg1 + v2);
loc_C.image = v0;
v24 = (f32)(s32)(s16)arg2;
loc_C.x = v5;
loc_C.y = v23;
loc_C.z = v24;
loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
loc_C.flags = (0x100000 + 7);
fn_1_4F734(&loc_C);
loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v26 = lbl_1_rodata_5C00;
v27 = (0x100000 + 7);
v28 = (f32)(s32)v9;
loc_C.image = v1;
loc_C.x = v5;
loc_C.y = v23;
loc_C.z = v28;
loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
loc_C.flags = v27;
*(struct Color *)((u8 *)&loc_C + 56) = loc_8;
fn_1_4F734(&loc_C);
loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v30 = lbl_1_rodata_5C00;
loc_C.image = v0;
v31 = (f32)(s32)(s16)arg2;
loc_C.x = v15;
loc_C.y = v23;
loc_C.z = v31;
loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
loc_C.flags = (0x180000 + 5);
fn_1_4F734(&loc_C);
loc_C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v33 = lbl_1_rodata_5C00;
v34 = (0x180000 + 5);
v35 = (f32)(s32)v9;
loc_C.image = v1;
loc_C.x = v15;
loc_C.y = v23;
loc_C.z = v35;
loc_C.scale_x = (f32)(loc_C.scale_x * arg4);
loc_C.scale_y = (f32)(loc_C.scale_y * arg5);
loc_C.flags = v34;
*(struct Color *)((u8 *)&loc_C + 56) = loc_8;
fn_1_4F734(&loc_C);
}
/* fzgx:end fn_1_C7CBC */

/* fzgx:begin fn_1_C8294 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct EnemyCtrlFace {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x10];
    s32 unk_18;
    u8 pad_1C[0x1C];
    u32 unk_38;
    u32 unk_3C;
    u8 pad_40[0x20];
    u32 unk_60;
} EnemyCtrlFace;

typedef struct EnemyCtrlEntry {
    s16 x;
    s16 y;
    f32 scale;
    s16 ofs_x;
    s16 ofs_y;
} EnemyCtrlEntry;

extern u32 fn_1_58C4(void);
extern EnemyCtrlFace *fn_1_D2D24(s32);
extern EnemyCtrlFace *fn_1_D2D58(s32);
extern s32 fn_1_D2D38(void);
extern u16 fn_1_584AC(void);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern void fn_1_51914(const FontDrawPacket *);
extern void fn_1_51990(FontDrawPacket *);
extern s32 fn_1_4FC50(FontDrawPacket *, u32, u16, u16, u32);
extern void fn_1_53830(u32, f32, u8, volatile u8 *, volatile u8 *);  /* fzgx-allow: S2 prototype matches the definition in font.c */
extern void fn_1_C7CBC(s16, s16, s16, s32, f32, f32);
extern s32 fn_1_40B20(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32, f32);
extern f32 lbl_8006D188(s32);
extern u32 lbl_801A66A0;
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_5C48;
extern const f64 lbl_1_rodata_5C98;
extern const f32 lbl_1_rodata_5CA0;
extern const f64 lbl_1_rodata_5CA8;
extern const f64 lbl_1_rodata_5CB8;
extern const f64 lbl_1_rodata_5CC0;
extern const f32 lbl_1_rodata_5CC8;
extern const f32 lbl_1_rodata_5CCC;
extern const f32 lbl_1_rodata_5CD4;
extern const f32 lbl_1_rodata_5CD8;
extern const f32 lbl_1_rodata_5CDC;
extern const f32 lbl_1_rodata_5CE0;
extern const f32 lbl_1_rodata_5CE4;
extern const u32 lbl_1_rodata_5C90;
extern const u32 lbl_1_rodata_5C94;

#pragma fp_contract off
s16 fn_1_C8294(const EnemyCtrlEntry *entries, u8 count, s32 flag) {
    FontDrawPacket packet;
    FontDrawPacket head;
    u32 color;
    s32 n;
    s16 result;
    u32 img0;
    u32 img1;
    s32 i;
    u32 img2;
    u32 img3;
    u32 img4;
    s32 digits;
    EnemyCtrlFace *obj;
    s16 dx;
    s16 dy;
    s16 px;
    s16 py;
    s32 cx;
    s32 cy;
    s32 active;
    f32 range;
    f32 fade;

    result = -1;
    img0 = flag ? 0x9437 : 0x9728;
    img1 = flag ? 0x944C : 0x972F;
    img2 = flag ? 0x9454 : 0x9734;
    img3 = flag ? 0x9453 : 0x9714;
    img4 = flag ? 0x9418 : 0x9714;
    digits = flag ? 11 : 20;

    if (fn_1_58C4() > 1) {
        return -1;
    }
    if (fn_1_D2D24(0) == NULL) {
        return -1;
    }

    head = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    head.image = img0;
    fn_1_51914(&head);

    if (count > 6) {
        count = 6;
    }
    n = count;
    for (i = 0; i < n; i++) {
        active = 0;
        obj = fn_1_D2D58(i);
        if (obj == NULL) {
            continue;
        }
        if (obj == NULL) {
            dx = 0;
            dy = 0;
        } else if (obj->unk_3C == 0 && obj->unk_38 != 0) {
            range = lbl_1_rodata_5C98 * (obj->unk_38 / lbl_1_rodata_5C48);
            dx = range * (fn_1_584AC() / lbl_1_rodata_5CA0 - lbl_1_rodata_5CA8);
            dy = range * (fn_1_584AC() / lbl_1_rodata_5CA0 - lbl_1_rodata_5CA8);
        } else {
            dx = 0;
            dy = 0;
        }
        cx = entries[i].x + entries[i].scale / 2;
        cy = entries[i].y + entries[i].scale / 2;
        px = cx + dx;
        py = cy + dy;

        packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = img2;
        packet.x = px;
        packet.y = py;
        packet.z = i * 10 + 7;
        packet.scale_x *= entries[i].scale / fn_1_48690(img2);
        packet.scale_y *= entries[i].scale / fn_1_486C4(img2);
        packet.flags = 10;
        fn_1_4F734(&packet);

        if (fn_1_D2D38()) {
            if (obj->unk_18 == 0) {
                active = 1;
            }
        } else {
            if (obj->unk_18 != -1) {
                active = 1;
            }
        }

        if (active) {
            packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = img1;
            packet.x = px;
            packet.y = py;
            packet.z = i * 10 + 6;
            packet.scale_x *= entries[i].scale / fn_1_48690(img2);
            packet.scale_y *= entries[i].scale / fn_1_486C4(img2);
            *(u32 *)packet.color = lbl_1_rodata_5C90;
            packet.alpha = lbl_1_rodata_5CB8 + lbl_1_rodata_5CC0 * lbl_8006D188(lbl_1_rodata_5CC8 * (f32)(lbl_801A66A0 % 30) / lbl_1_rodata_5CCC);
            packet.flags = 10;
            fn_1_4F734(&packet);
        }

        if (obj != NULL && obj->unk_60 != 0) {
            packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
            packet.x = px;
            packet.y = py;
            packet.z = i * 10 + 5;
            packet.scale_x *= entries[i].scale / 64;
            packet.scale_y *= entries[i].scale / 64;
            packet.flags = 10;
            fn_1_51990(&packet);
            fn_1_4FC50(&packet, 5, 0x40, 0x40, obj->unk_60);
        }

        packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = img3;
        packet.x = px;
        packet.y = py;
        packet.z = i * 10 + 4;
        packet.scale_x *= entries[i].scale / fn_1_48690(img2);
        packet.scale_y *= entries[i].scale / fn_1_486C4(img2);
        packet.flags = 10;
        fn_1_4F734(&packet);

        packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = img4;
        packet.x = px;
        packet.y = py;
        packet.z = i * 10 + 3;
        packet.scale_x *= entries[i].scale / fn_1_48690(img2);
        packet.scale_y *= entries[i].scale / fn_1_486C4(img2);
        packet.flags = 10;
        if (active) {
            fade = lbl_1_rodata_5CD4 * (lbl_1_rodata_5CD4 * entries[i].scale) / lbl_1_rodata_5CD8;
            fn_1_53830(60, lbl_1_rodata_5CDC, 50, packet.color_add, packet.color);
            fn_1_C7CBC(px, py, i * 10 + 5, flag, fade, fade);
        }
        fn_1_4F734(&packet);

        if (obj->unk_4 == fn_1_40B20()) {
            packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
            packet.image = 0x9407;
            packet.x = px;
            packet.y = lbl_1_rodata_5CE0 + py;
            packet.z = i * 10 + 2;
            packet.flags = 10;
            fn_1_4F734(&packet);
        }

        fn_1_49410();
        fn_1_494DC(digits);
        fn_1_496FC(dx + entries[i].ofs_x, dy + entries[i].ofs_y);
        fn_1_4954C(i * 10 + 2);
        color = lbl_1_rodata_5C94;
        fn_1_49514(&color);
        if (!flag) {
            fn_1_4955C(lbl_1_rodata_5CE4, lbl_1_rodata_5CE4);
        }
        fn_1_4AE0C((const char *)&lbl_1_data_3D570, i + 1);
        if (active) {
            result = i;
        }
    }
    return result;
}
#pragma fp_contract reset
/* fzgx:end fn_1_C8294 */

/* fzgx:begin fn_1_C8DC0 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct Color {
    u8 r, g, b, a;
} Color;

typedef struct Actor {
    u8 pad_0[0x118];
    s32 unk_118;
    u8 pad_11C[0x58];
    u8 min;
    u8 sec;
    u16 ms;
    u8 pad_178[0x74];
    u8 best_min;
    u8 best_sec;
    u16 best_ms;
} Actor;

typedef struct Sprite {
    s32 used;
    u8 pad_4[2];
    s16 state;
    FontDrawPacket packet;
    u8 pad_60[0x18];
    void (*func)(void *);
    u32 unk_7C;
} Sprite;

extern Actor *fn_1_8627C(void *);
extern f32 fn_1_867F8(void *);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u32 fn_1_5910(void);
extern s16 fn_1_3F0C8(void);
extern u32 fn_1_864E8(void *);
extern Sprite *fn_1_4DF60(void);
extern u32 fn_1_58C4(void);
extern void fn_1_51E60(FontDrawPacket *);
extern void fn_1_51C74(Sprite *);
extern void fn_1_CA218(void *);
extern f32 lbl_1_rodata_26F8[22];
extern const u32 lbl_1_rodata_5CF0;
extern u32 lbl_801A66A0;
extern const f32 lbl_1_rodata_5CB0;
extern const f32 lbl_1_rodata_5CF4;
extern const f32 lbl_1_rodata_5CF8;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D00;
extern const f32 lbl_1_rodata_5D04;
extern const f32 lbl_1_rodata_5D08;
extern const f32 lbl_1_rodata_5D0C;
extern const f32 lbl_1_rodata_5D10;
extern const f32 lbl_1_rodata_5D14;
extern const f32 lbl_1_rodata_5D18;
extern const f32 lbl_1_rodata_5D1C;
extern const f32 lbl_1_rodata_5D20;
extern const f32 lbl_1_rodata_5D24;
extern const f32 lbl_1_rodata_5CD4;
extern const f32 lbl_1_rodata_5D28;
extern const f32 lbl_1_rodata_5D2C;
extern const f32 lbl_1_rodata_5CCC;
extern const f32 lbl_1_rodata_5D30;
extern const f32 lbl_1_rodata_5C80;

#pragma opt_propagation off
void fn_1_C8DC0(void *arg0) {
    Color add;
    FontDrawPacket packet;
    u32 width;
    Actor *actor;
    void *obj;
    BOOL flag;
    u32 cur;
    u32 best;
    f32 value;
    f32 full;
    f32 alpha;
    s32 sum;
    s32 period;
    Sprite *sprite;

    actor = fn_1_8627C(arg0);
    best = actor->best_min * 60000 + actor->best_sec * 1000 + actor->best_ms;
    cur = actor->min * 60000 + actor->sec * 1000 + actor->ms;
    width = lbl_1_rodata_5CB0 * ((cur != 0 && !(lbl_1_bss_3C30.unk_0 & 0x10)) ? best - cur : 9999);
    obj = arg0;
    full = fn_1_48690(0x9416) * fn_1_867F8(obj) / lbl_1_rodata_5CF4;
    flag = width < full - lbl_1_rodata_5CF8;
    alpha = lbl_1_rodata_5CFC;
    if (!(((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 30 & 1)) {
        return;
    }
    if (actor == NULL) {
        return;
    }
    if (flag) {
        add.r = add.g = add.b = 80;
    } else {
        add.r = add.g = add.b = 0;
    }
    value = fn_1_867F8(obj);
    if (value < lbl_1_rodata_5D00 && fn_1_3F0C8() == 41) {
        period = 30;
        if (value < lbl_1_rodata_5D04) {
            period = 15;
        }
        value = (f32)(lbl_801A66A0 % period) / period;
        alpha = (value < lbl_1_rodata_5D08) ? lbl_1_rodata_5D08 : ((value > lbl_1_rodata_5CFC) ? lbl_1_rodata_5CFC : value);
    }

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9400;
    packet.x = lbl_1_rodata_5D0C;
    packet.y = lbl_1_rodata_5D10;
    fn_1_51E60(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9417;
    packet.x = lbl_1_rodata_5D14;
    packet.y = lbl_1_rodata_5D18;
    packet.z = lbl_1_rodata_5D10;
    fn_1_51E60(&packet);

    if (actor->unk_118 + 1 >= 2 || (lbl_1_bss_3C30.unk_0 & 0x10)) {
        packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x9416;
        if (flag) {
            value = (width + 16) * fn_1_867F8(obj) / lbl_1_rodata_5CF4;
        } else {
            value = full;
        }
        fn_1_51678(&packet, packet.image, 0, 0, value, fn_1_486C4(0x9416));
        packet.x = lbl_1_rodata_5D1C;
        packet.y = lbl_1_rodata_5D20;
        *(Color *)packet.color_add = add;
        packet.color[0] = packet.color[0] * alpha;
        packet.color[1] = packet.color[1] * alpha;
        packet.color[2] = packet.color[2] * alpha;
        packet.z = lbl_1_rodata_5D24;
        fn_1_51E60(&packet);
    }

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9436;
    packet.x = lbl_1_rodata_5D1C;
    packet.y = lbl_1_rodata_5D20;
    packet.scale_x *= full / fn_1_48690(packet.image);
    packet.scale_y *= lbl_1_rodata_5CD4;
    *(Color *)packet.color = *(const Color *)&lbl_1_rodata_5CF0;
    sum = packet.color[0] + add.r;
    packet.color[0] = (sum < 255) ? sum : 255;
    sum = packet.color[1] + add.g;
    packet.color[1] = (sum < 255) ? sum : 255;
    sum = packet.color[2] + add.b;
    packet.color[2] = (sum < 255) ? sum : 255;
    packet.color[0] = packet.color[0] * alpha;
    packet.color[1] = packet.color[1] * alpha;
    packet.color[2] = packet.color[2] * alpha;
    packet.z = lbl_1_rodata_5D28;
    fn_1_51E60(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9451;
    packet.x = lbl_1_rodata_5D1C;
    packet.y = lbl_1_rodata_5D20;
    packet.scale_x *= fn_1_48690(0x9416) / fn_1_48690(packet.image);
    packet.z = lbl_1_rodata_5D2C;
    fn_1_51E60(&packet);

    if (flag) {
        packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x9450;
        packet.x = width + 484;
        packet.y = lbl_1_rodata_5D20;
        packet.z = lbl_1_rodata_5CCC;
        fn_1_51E60(&packet);
    }

    if (!(((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 20 & 1)) {
        return;
    }
    if (!(fn_1_864E8(obj) & 0x40)) {
        return;
    }
    if (fn_1_864E8(obj) & 0x800) {
        return;
    }
    sprite = fn_1_4DF60();
    if (sprite == NULL) {
        return;
    }
    sprite->packet.image = 0x9410;
    sprite->packet.x = lbl_1_rodata_5D30;
    sprite->packet.y = lbl_1_rodata_5C80;
    sprite->packet.z = lbl_1_rodata_5D20;
    if (fn_1_58C4() == 1 && (s32)lbl_1_bss_4E6A8 != 0) {
        sprite->packet.flags |= 0x8000000;
        sprite->packet.depth = (s32)lbl_1_bss_4E6AC;
    }
    sprite->state = 0;
    sprite->func = fn_1_CA218;
    fn_1_51C74(sprite);
}
/* fzgx:end fn_1_C8DC0 */

/* fzgx:begin fn_1_C96A4 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct Color {
    u8 r, g, b, a;
} Color;

typedef struct Actor {
    u8 pad_0[0x118];
    s32 unk_118;
    u8 pad_11C[0x58];
    u8 min;
    u8 sec;
    u16 ms;
    u8 pad_178[0x74];
    u8 best_min;
    u8 best_sec;
    u16 best_ms;
} Actor;

typedef struct Sprite {
    s32 used;
    u8 pad_4[2];
    s16 state;
    FontDrawPacket packet;
    u8 pad_60[0x18];
    void (*func)(void *);
    u32 unk_7C;
} Sprite;

extern Actor *fn_1_8627C(void *);
extern f32 fn_1_867F8(void *);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u32 fn_1_5910(void);
extern s16 fn_1_3F0C8(void);
extern u32 fn_1_864E8(void *);
extern Sprite *fn_1_4DF60(void);
extern void fn_1_CA218(void *);
extern f32 lbl_1_rodata_26F8[22];
extern const u32 lbl_1_rodata_5D34;
extern u32 lbl_801A66A0;
extern const f32 lbl_1_rodata_5CB0;
extern const f32 lbl_1_rodata_5CF4;
extern const f32 lbl_1_rodata_5CF8;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D00;
extern const f32 lbl_1_rodata_5D04;
extern const f32 lbl_1_rodata_5D08;
extern const f32 lbl_1_rodata_5D10;
extern const f32 lbl_1_rodata_5D38;
extern const f32 lbl_1_rodata_5D24;
extern const f32 lbl_1_rodata_5C80;
extern const f32 lbl_1_rodata_5D28;
extern const f32 lbl_1_rodata_5D2C;
extern const f32 lbl_1_rodata_5CCC;
extern const f32 lbl_1_rodata_5D20;
extern const f32 lbl_1_rodata_5D3C;

#pragma opt_propagation off
void fn_1_C96A4(void *arg0, s32 x, s32 y) {
    Color add;
    FontDrawPacket packet;
    u32 width;
    Actor *actor;
    void *obj;
    BOOL flag;
    u32 cur;
    u32 best;
    f32 value;
    f32 full;
    f32 alpha;
    s32 sum;
    s32 period;
    Sprite *sprite;

    actor = fn_1_8627C(arg0);
    best = actor->best_min * 60000 + actor->best_sec * 1000 + actor->best_ms;
    cur = actor->min * 60000 + actor->sec * 1000 + actor->ms;
    width = lbl_1_rodata_5CB0 * (cur != 0 ? best - cur : 9999);
    obj = arg0;
    full = fn_1_48690(0x9416) * fn_1_867F8(obj) / lbl_1_rodata_5CF4;
    flag = width < full - lbl_1_rodata_5CF8;
    alpha = lbl_1_rodata_5CFC;
    if (!(((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 30 & 1)) {
        return;
    }
    if (flag) {
        add.r = add.g = add.b = 80;
    } else {
        add.r = add.g = add.b = 0;
    }
    value = fn_1_867F8(obj);
    if (value < lbl_1_rodata_5D00 && fn_1_3F0C8() == 41) {
        period = 30;
        if (value < lbl_1_rodata_5D04) {
            period = 15;
        }
        value = (f32)(lbl_801A66A0 % period) / period;
        alpha = (value < lbl_1_rodata_5D08) ? lbl_1_rodata_5D08 : ((value > lbl_1_rodata_5CFC) ? lbl_1_rodata_5CFC : value);
    }

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9400;
    packet.x = x + 89;
    packet.y = y + 22;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9417;
    fn_1_51678(&packet, packet.image, 0, 0, fn_1_48690(0x9417), 10);
    packet.x = x;
    packet.y = y;
    packet.z = lbl_1_rodata_5D10;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9417;
    fn_1_51678(&packet, packet.image, 0, 14, fn_1_48690(0x9417), 10);
    packet.x = x;
    packet.y = y + 10;
    packet.z = lbl_1_rodata_5D38;
    fn_1_4F734(&packet);

    if (actor->unk_118 + 1 >= 2) {
        packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x9416;
        if (flag) {
            value = (width + 16) * fn_1_867F8(obj) / lbl_1_rodata_5CF4;
        } else {
            value = full;
        }
        fn_1_51678(&packet, packet.image, 0, 0, value, fn_1_486C4(0x9416));
        packet.x = x + 4;
        packet.y = y + 4;
        *(Color *)packet.color_add = add;
        packet.color[0] = packet.color[0] * alpha;
        packet.color[1] = packet.color[1] * alpha;
        packet.color[2] = packet.color[2] * alpha;
        packet.z = lbl_1_rodata_5D24;
        packet.scale_y *= lbl_1_rodata_5C80 / fn_1_486C4(packet.image);
        fn_1_4F734(&packet);
    }

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9436;
    packet.x = x + 4;
    packet.y = y + 4;
    packet.scale_x *= full / fn_1_48690(packet.image);
    packet.scale_y *= lbl_1_rodata_5C80 / fn_1_486C4(packet.image);
    *(Color *)packet.color = *(const Color *)&lbl_1_rodata_5D34;
    sum = packet.color[0] + add.r;
    packet.color[0] = (sum < 255) ? sum : 255;
    sum = packet.color[1] + add.g;
    packet.color[1] = (sum < 255) ? sum : 255;
    sum = packet.color[2] + add.b;
    packet.color[2] = (sum < 255) ? sum : 255;
    packet.color[0] = packet.color[0] * alpha;
    packet.color[1] = packet.color[1] * alpha;
    packet.color[2] = packet.color[2] * alpha;
    packet.z = lbl_1_rodata_5D28;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9451;
    packet.x = x + 4;
    packet.y = y + 4;
    packet.scale_x *= fn_1_48690(0x9416) / fn_1_48690(packet.image);
    packet.scale_y *= lbl_1_rodata_5C80 / fn_1_486C4(packet.image);
    packet.z = lbl_1_rodata_5D2C;
    fn_1_4F734(&packet);

    if (flag) {
        packet = *(const FontDrawPacket *)lbl_1_rodata_26F8;
        packet.image = 0x9450;
        packet.x = x + 4 + width;
        packet.y = y + 4;
        packet.z = lbl_1_rodata_5CCC;
        packet.scale_y *= lbl_1_rodata_5C80 / fn_1_486C4(packet.image);
        fn_1_4F734(&packet);
    }

    if (!(((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 20 & 1)) {
        return;
    }
    if (!(fn_1_864E8(obj) & 0x40)) {
        return;
    }
    if (fn_1_864E8(obj) & 0x800) {
        return;
    }
    sprite = fn_1_4DF60();
    if (sprite == NULL) {
        return;
    }
    sprite->packet.image = 0x9410;
    sprite->packet.x = x - 8;
    sprite->packet.y = y - 12;
    sprite->packet.z = lbl_1_rodata_5D20;
    sprite->packet.scale_y *= lbl_1_rodata_5D3C;
    if ((s32)lbl_1_bss_4E6A8 != 0) {
        sprite->packet.flags |= 0x8000000;
        sprite->packet.depth = (s32)lbl_1_bss_4E6AC;
    }
    sprite->state = 0;
    sprite->func = fn_1_CA218;
}
/* fzgx:end fn_1_C96A4 */

/* fzgx:begin fn_1_CA218 */
typedef struct EnemyCtrl_CA218 {
    u32 value;
    u8 pad4[2];
    s16 state;
    u32 action;
} EnemyCtrl_CA218;

void fn_1_CA218(EnemyCtrl_CA218 *self) {
    u32 actions[7];

    actions[0] = lbl_1_rodata_5D40[0];
    actions[1] = lbl_1_rodata_5D40[1];
    actions[2] = lbl_1_rodata_5D40[2];
    actions[3] = lbl_1_rodata_5D40[3];
    actions[4] = lbl_1_rodata_5D40[4];
    actions[5] = lbl_1_rodata_5D40[5];
    actions[6] = lbl_1_rodata_5D40[6];

    if (self->state < 14) {
        self->action = actions[self->state / 2];
        self->state = self->state + 1;
    } else {
        self->value = 0;
    }
}
/* fzgx:end fn_1_CA218 */

/* fzgx:begin fn_1_CA2A4 */
typedef struct {
    u32 x[22];
} fn_1_CA2A4_LocalData;

void fn_1_CA2A4(void *self) {
    fn_1_CA2A4_LocalData local;
    s32 count;
    s32 max;

    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910(self)] >> 29) & 1) == 0) {
        return;
    }
    count = (u8)fn_1_86810(self) + 1;
    max = fn_1_3F7E0();
    if (count > max) {
        return;
    }
    fn_1_49410();
    fn_1_494DC(0xc);
    fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5D18);
    fn_1_495C8(1);
    fn_1_49728(1);
    fn_1_4AE0C(&lbl_1_data_3D574, count);
    fn_1_49410();
    fn_1_494DC(0xd);
    fn_1_496FC(lbl_1_rodata_5D5C, lbl_1_rodata_5D60);
    fn_1_49728(1);
    fn_1_4AE0C(&lbl_1_data_3D574, max);
    local = *(fn_1_CA2A4_LocalData *)lbl_1_rodata_26F8;
    local.x[0] = 0x9429;
    ((f32 *)local.x)[1] = lbl_1_rodata_5D64;
    ((f32 *)local.x)[2] = lbl_1_rodata_5D68;
    fn_1_51E60(&local.x[0]);
    local = *(fn_1_CA2A4_LocalData *)lbl_1_rodata_26F8;
    local.x[0] = 0x9405;
    ((f32 *)local.x)[1] = lbl_1_rodata_5D6C;
    ((f32 *)local.x)[2] = lbl_1_rodata_5D68;
    fn_1_51E60(&local.x[0]);
}
/* fzgx:end fn_1_CA2A4 */

/* fzgx:begin fn_1_CA440 noprologue */
#include "types.h"
#include "font.h"

struct fn_1_CA440_lbl_1_data_3D544 {
    u32 unk_0[1];
};
struct fn_1_CA440_5D70 {
    u32 a[4];
};

extern struct fn_1_CA440_lbl_1_data_3D544 lbl_1_data_3D544;
extern u32 lbl_1_data_3D570;
extern struct fn_1_CA440_5D70 lbl_1_rodata_5D70;
extern u32 lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_5D80;
extern const f32 lbl_1_rodata_5D84;
extern const f64 lbl_1_rodata_5C00;
extern u32 fn_1_5910(void);
extern u8 fn_1_86810(void *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern int fn_1_4F734(FontDrawPacket *);

void fn_1_CA440(void *arg0, s32 arg1, s32 arg2) {
    struct fn_1_CA440_5D70 tbl;
    FontDrawPacket pkt;
    s32 t;
    s32 g;
    s32 f;
    s32 m;
    s32 n;

    if (((*(u32 *)&((&lbl_1_data_3D544)[fn_1_5910()]) >> 29) & 1) != 0) {
        t = (s32)((u8)fn_1_86810(arg0)) + 1;
        tbl = *(const struct fn_1_CA440_5D70 *)&lbl_1_rodata_5D70;
        fn_1_49410();
        fn_1_494DC(12);
        fn_1_4955C(lbl_1_rodata_5D80, lbl_1_rodata_5D84);
        fn_1_496FC((f32)arg1, (f32)arg2);
        fn_1_4AE0C((const char *)&lbl_1_data_3D570, t);
        pkt = *(const FontDrawPacket *)&lbl_1_rodata_26F8;
        f = 0;
        m = t % 100;
        if (m >= 10 && t % 100 <= 20) {
            f = 1;
        }
        if (f != 0) {
            n = 3;
        } else {
            g = 0;
            if (m % 10 >= 4 || m % 10 == 0) {
                g = 1;
            }
            if (g != 0) {
                n = 3;
            } else {
                n = m % 10 - 1;
            }
        }
        pkt.image = tbl.a[n];
        pkt.x = (f32)(arg1 + 34);
        pkt.y = (f32)(arg2 + 29);
        fn_1_4F734(&pkt);
    }
}
/* fzgx:end fn_1_CA440 */

/* fzgx:begin fn_1_CA690 */
extern u32 fn_1_5910(void *);
extern u8 fn_1_86810(void *);
extern u32 fn_1_3F7E0(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49728(u32);
extern void fn_1_4AE0C(void *, ...);


extern void fn_1_51E60(void *);

typedef struct {
    u32 x[22];
} fn_1_CA690_LocalData;

void fn_1_CA690(void *self, s32 arg1, s32 arg2) {
    fn_1_CA690_LocalData local;
    s32 count;
    s32 max;

    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910(self)] >> 29) & 1) == 0) {
        return;
    }
    count = (u8)fn_1_86810(self) + 1;
    fn_1_49410();
    fn_1_494DC(0xc);
    fn_1_496FC(arg1, arg2);
    fn_1_4955C(lbl_1_rodata_5D88, lbl_1_rodata_5D8C);
    fn_1_4966C(lbl_1_rodata_5CD4, lbl_1_rodata_5D90);
    fn_1_49728(1);
    fn_1_4AE0C(&lbl_1_data_3D574, count);
    max = fn_1_3F7E0();
    fn_1_49410();
    fn_1_494DC(0xd);
    fn_1_496FC(arg1 + 0x5c, arg2 + 0x1a);
    fn_1_49728(1);
    fn_1_4AE0C(&lbl_1_data_3D574, max);
    local = *(fn_1_CA690_LocalData *)lbl_1_rodata_26F8;
    local.x[0] = 0x9429;
    ((f32 *)local.x)[1] = arg1 + 0x4e;
    ((f32 *)local.x)[2] = arg2 + 0x1a;
    fn_1_51E60(&local.x[0]);
    local = *(fn_1_CA690_LocalData *)lbl_1_rodata_26F8;
    local.x[0] = 0x9405;
    ((f32 *)local.x)[1] = arg1 + 0x4e;
    ((f32 *)local.x)[2] = arg2 + 0xd;
    fn_1_51E60(&local.x[0]);
}
/* fzgx:end fn_1_CA690 */

/* fzgx:begin fn_1_CA8FC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct {
    u32 words[22];
} fn_1_CA8FC_Copy88;

extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_5D18;
extern const f32 lbl_1_rodata_5DBC;
extern const f32 lbl_1_rodata_5DC8;
extern const f64 lbl_1_rodata_5C00;
extern const f64 lbl_1_rodata_5DC0;
extern u32 lbl_1_rodata_5D94[10];
extern s32 fn_1_3F1D4(void);
extern u32 fn_1_5910(void);
extern void fn_1_51E60(void *);
extern f64 fn_80088598(f64, f64);

void fn_1_CA8FC(void) {
    fn_1_CA8FC_Copy88 pat;
    u32 tbl[10];
    s32 id;
    s32 off;
    s32 i;

    id = fn_1_3F1D4();
    if (id == -1) {
        return;
    }
    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 0x1CU) & 1) == 0) {
        return;
    }
    pat = *(fn_1_CA8FC_Copy88 *)lbl_1_rodata_26F8;
    pat.words[0] = 0x942D;
    ((f32 *)pat.words)[1] = lbl_1_rodata_5D18;
    ((f32 *)pat.words)[2] = lbl_1_rodata_5DBC;
    fn_1_51E60(&pat);
    tbl[0] = lbl_1_rodata_5D94[0];
    tbl[1] = lbl_1_rodata_5D94[1];
    tbl[2] = lbl_1_rodata_5D94[2];
    tbl[3] = lbl_1_rodata_5D94[3];
    tbl[4] = lbl_1_rodata_5D94[4];
    tbl[5] = lbl_1_rodata_5D94[5];
    tbl[6] = lbl_1_rodata_5D94[6];
    tbl[7] = lbl_1_rodata_5D94[7];
    tbl[8] = lbl_1_rodata_5D94[8];
    tbl[9] = lbl_1_rodata_5D94[9];
    pat = *(fn_1_CA8FC_Copy88 *)lbl_1_rodata_26F8;
    ((f32 *)pat.words)[2] = lbl_1_rodata_5DBC;
    for (i = 0, off = 0; i <= 1; i++, off += 0x16) {
        pat.words[0] = tbl[id / (s32)fn_80088598(lbl_1_rodata_5DC0, (f64)i) % 10];
        ((f32 *)pat.words)[1] = (f32)(0x40 - off);
        fn_1_51E60(&pat);
        pat.words[0] = 0x9430;
        ((f32 *)pat.words)[3] = ((f32 *)pat.words)[3] + lbl_1_rodata_5DC8;
        fn_1_51E60(&pat);
    }
}
/* fzgx:end fn_1_CA8FC */

/* fzgx:begin fn_1_CAB38 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u8 fn_1_86A10(u32);
extern s32 fn_1_5910(void);
extern f32 fn_1_15E1D0(u32);
extern void fn_1_51E60(FontDrawPacket *);
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_5D90; /* 0.0f */
extern const f32 lbl_1_rodata_5DCC; /* 4.0f */
extern const f32 lbl_1_rodata_5DD0; /* 150.0f */
extern const f32 lbl_1_rodata_5DD4; /* 22.0f */
extern const f32 lbl_1_rodata_5DD8; /* 23.0f */

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

void fn_1_CAB38(u32 arg0, u32 arg1, s32 y) {
    s32 count;
    s32 ypos;
    s32 i;
    s32 x;
    FontDrawPacket pkt;

    count = fn_1_86A10(arg0);
    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 21) & 1) == 0) {
        return;
    }
    if ((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 24) & 1) {
        ypos = (s32)((f32)y + (lbl_1_rodata_5DD0 +
                               (f32)(lbl_1_rodata_5DD4 *
                                     CLAMP(fn_1_15E1D0(fn_1_5910()), lbl_1_rodata_5D90, lbl_1_rodata_5DCC))));
    } else {
        ypos = y + 0x6c;
    }
    pkt = lbl_1_rodata_26F8;
    pkt.y = (f32)ypos;
    if (count > 30) {
        count = 30;
    }
    if (count / 10 > 0) {
        pkt.image = 0x940D;
        for (i = 0; i < count / 10; i++) {
            pkt.x = (f32)(616 - i * 18);
            pkt.flags = 7;
            fn_1_51E60(&pkt);
        }
        pkt.y += lbl_1_rodata_5DD8;
    }
    pkt.image = 0x940E;
    for (i = 0; i < count % 10; i++) {
        pkt.x = (f32)(616 - i * 17);
        pkt.flags = 7;
        fn_1_51E60(&pkt);
    }
}
/* fzgx:end fn_1_CAB38 */

/* fzgx:begin fn_1_CADC4 noprologue */
#include "types.h"

struct fn_1_CADC4_Copy88 { u32 a[22]; };
struct fn_1_CADC4_lbl_1_data_3D544 {
    u32 unk_0[1];
};
extern f32 lbl_1_rodata_5CD4;
extern f32 lbl_1_rodata_5D1C;
extern f32 lbl_1_rodata_5D90;
extern f32 lbl_1_rodata_5DDC;
extern f32 lbl_1_rodata_5DE0;
extern f32 lbl_1_rodata_5DE4;
extern struct fn_1_CADC4_lbl_1_data_3D544 lbl_1_data_3D544;
extern u32 lbl_1_data_3D57C;
extern u32 lbl_1_rodata_26F8;
extern f32 fn_1_8652C(int);
extern u32 fn_1_5910(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_49728(u8);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_51E60(u32);

struct FzgxCopy_88 { u32 words[22]; };
void fn_1_CADC4(s32 arg0) {
    struct FzgxCopy_88 loc_8;
    s32 sp4;
    s32 temp_r31;

    temp_r31 = (s32) fn_1_8652C((s32)(arg0));
    if (((*(u32 *)&((&lbl_1_data_3D544)[fn_1_5910()])) >> 0x1BU) & 1) {
        fn_1_49410();
        fn_1_494DC((s16)(0xF));
        fn_1_496FC((f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5D1C) + 0)), (f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5DDC) + 0)));
        fn_1_4966C((f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5CD4) + 0)), (f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5D90) + 0)));
        fn_1_49728((u8)(1U));
        fn_1_4AE0C((const char *)((s8 *) &lbl_1_data_3D57C), temp_r31);
        loc_8 = *(const struct FzgxCopy_88 *)((((s32)(((u8 *)(&lbl_1_rodata_26F8) + -4))) + 4));
        loc_8.words[0] = 0x9401;
        (*(f32 *)((u8 *)(&loc_8) + 4)) = *(f32 *)((u8 *)(&lbl_1_rodata_5DE0) + 0);
        (*(f32 *)((u8 *)(&loc_8) + 8)) = *(f32 *)((u8 *)(&lbl_1_rodata_5DE4) + 0);
        fn_1_51E60((u32)((u32)(&loc_8)));
    }
}
/* fzgx:end fn_1_CADC4 */

/* fzgx:begin fn_1_CAEBC noprologue */
#include "types.h"
#include "font.h"

struct fn_1_CAEBC_Copy88 { u32 a[22]; };
struct fn_1_CAEBC_lbl_1_data_3D544 {
    u32 unk_0[1];
};
extern f32 lbl_1_rodata_5CFC;
extern f32 lbl_1_rodata_5D90;
extern f32 lbl_1_rodata_5DE8;
extern f32 lbl_1_rodata_5DEC;
extern f64 lbl_1_rodata_5C00;
extern struct fn_1_CAEBC_lbl_1_data_3D544 lbl_1_data_3D544;
extern u32 lbl_1_data_3D57C;
extern u32 lbl_1_rodata_26F8;
extern f32 fn_1_8652C(int);
extern u32 fn_1_5910(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern int fn_1_4F734(FontDrawPacket *);

struct FzgxCopy_88 { u32 words[22]; };
void fn_1_CAEBC(s32 arg0, s32 arg1, s32 arg2) {
    FontDrawPacket loc_8;
    s32 sp4;
    s32 temp_r31;

    temp_r31 = (s32) fn_1_8652C((s32)(arg0));
    if (((*(u32 *)&((&lbl_1_data_3D544)[fn_1_5910()])) >> 0x1BU) & 1) {
        fn_1_49410();
        fn_1_494DC((s16)(0xF));
        fn_1_496FC((f32)((f32) arg1), (f32)((f32) arg2));
        fn_1_4955C((f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5DE8) + 0)), (f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5DEC) + 0)));
        fn_1_4966C((f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5CFC) + 0)), (f32)(*(f32 *)((u8 *)(&lbl_1_rodata_5D90) + 0)));
        fn_1_4AE0C((const char *)((s8 *) &lbl_1_data_3D57C), temp_r31);
        loc_8 = *(const FontDrawPacket *)((((s32)(((u8 *)(&lbl_1_rodata_26F8) + -4))) + 4));
        loc_8.image = 0x9401;
        loc_8.x = (f32) (arg1 + 0x45);
        loc_8.y = (f32) (arg2 + 0xA);
        fn_1_4F734((FontDrawPacket *)(&loc_8));
    }
}
/* fzgx:end fn_1_CAEBC */

/* fzgx:begin fn_1_CB028 noprologue */
#include "types.h"
#include "rel/main_rel/enemy_ctrl.h"

typedef struct {
    u8 r, g, b, a;
} CB028Color;

typedef struct {
    f32 x;
    f32 y;
    f32 scaleX;
    f32 scaleY;
    f32 alpha;
    u32 image;
    s32 index;
    CB028Color color;
    CB028Color color2;
} CB028Sprite;

typedef struct {
    u8 pad_0[3];
    u8 unk_3;
    u8 pad_4[4];
    u8 count;
    u8 pad_9[7];
    u32 images[8];
} CB028List;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
} CB028Entry;

extern s32 fn_1_5910(void);
extern void *fn_1_15F618(s32);
extern void fn_1_CB6D8(void *);
extern const CB028Color lbl_1_rodata_5DF0;
extern const CB028Color lbl_1_rodata_5DF4;
extern const CB028Color lbl_1_rodata_5DF8;
extern const CB028Color lbl_1_rodata_5DFC;
extern const CB028Color lbl_1_rodata_5E00;
extern const CB028Color lbl_1_rodata_5E04;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D04;
extern const f32 lbl_1_rodata_5E08;
extern const f32 lbl_1_rodata_5E0C;
extern const f32 lbl_1_rodata_5DD4;
extern const f32 lbl_1_rodata_5E10;
extern const f32 lbl_1_rodata_5CD8;

void fn_1_CB028(s32 x, s32 y) {
    CB028Color color;
    CB028Sprite sprite;
    CB028List *list;
    CB028Entry *entry;
    s32 i;
    s32 skip;
    u32 image;
    f32 step;
    f32 alpha;
    f32 scale;
    f32 shrink;
    f32 fade;
    s32 n;
    s32 last;
    s32 k;

    scale = lbl_1_rodata_5CFC;
    color = lbl_1_rodata_5DF0;
    if ((((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 24) & 1) {
        list = fn_1_15F618(fn_1_5910());
        entry = &((CB028Entry *)&lbl_1_bss_7ACA0)[fn_1_5910()];
        alpha = lbl_1_rodata_5CFC - (f32)list->unk_3 / 15.0f;
        n = list->count;
        if (n < 1) {
            return;
        }
        if (n > 4) {
            skip = n - 4;
            if (entry->unk_8 != 0) {
                alpha = lbl_1_rodata_5CFC;
                skip--;
                scale = (f32)entry->unk_8 / 15.0f;
            }
            n = 4;
        } else {
            skip = 0;
        }
        sprite.x = (f32)x;
        sprite.y = (f32)y;
        sprite.scaleX = lbl_1_rodata_5E08;
        sprite.scaleY = lbl_1_rodata_5E0C;
        sprite.alpha = 1.0f;
        sprite.index = -1;
        sprite.color = lbl_1_rodata_5DF4;
        sprite.color2 = lbl_1_rodata_5DF8;
        if (entry->unk_8 != 0) {
            entry->unk_8--;
        }
        last = n + skip;
        image = list->images[--last % 8];
        if (image == entry->unk_4) {
            if (entry->unk_9 != last) {
                entry->unk_A = entry->unk_9;
                entry->unk_B = 60;
                entry->unk_9 = last;
            }
            color = lbl_1_rodata_5DFC;
        }
        step = lbl_1_rodata_5DD4 * scale;
        shrink = lbl_1_rodata_5E0C;
        sprite.index = skip;
        for (i = 0; i < n - 1; i++) {
            k = i + skip;
            sprite.image = list->images[k % 8];
            if (i == 0) {
                sprite.scaleY = scale;
            } else {
                sprite.scaleY = lbl_1_rodata_5CFC;
            }
            sprite.scaleY *= shrink;
            if (entry->unk_9 == k) {
                sprite.color2 = lbl_1_rodata_5E00;
            } else if (entry->unk_A == k && entry->unk_B != 0) {
                fade = lbl_1_rodata_5CFC - (f32)entry->unk_B / lbl_1_rodata_5E10;
                fade *= lbl_1_rodata_5CD8;
                sprite.color2.b = fade;
                sprite.color2.r = 255;
                sprite.color2.g = 255;
            } else {
                sprite.color2 = lbl_1_rodata_5E04;
            }
            fn_1_CB6D8(&sprite);
            if (i == 0) {
                sprite.y += step;
            } else {
                sprite.y += lbl_1_rodata_5DD4;
            }
            sprite.index++;
        }
        if (entry->unk_B != 0) {
            entry->unk_B--;
        }
        sprite.image = image;
        sprite.color2 = color;
        sprite.alpha = alpha;
        fn_1_CB6D8(&sprite);
    }
}
/* fzgx:end fn_1_CB028 */

/* fzgx:begin fn_1_CB404 */
// Set the state flag for the selected enemy-control entry.
void fn_1_CB404(u8 value) {
    (&lbl_1_bss_7ACA0.unk_8)[value * 0xc] = 0xf;
}
/* fzgx:end fn_1_CB404 */

/* fzgx:begin fn_1_CB424 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u32 fn_1_5910(void);
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_51E60(void *);
extern u32 fn_1_CB6D8(void *);
extern u32 lbl_1_rodata_5E14;
extern u32 lbl_1_rodata_5E18;
extern const f64 lbl_1_rodata_5C00;
extern const f64 lbl_1_rodata_5CE8;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5CD4;
extern const f32 lbl_1_rodata_5CD8;
extern const f32 lbl_1_rodata_5E08;
extern const f32 lbl_1_rodata_5E0C;
extern const f32 lbl_1_rodata_5E1C;
extern const f32 lbl_1_rodata_5E20;
extern const f32 lbl_1_rodata_5E24;

struct Cb424_msg {
	s32 unk_0;
	f32 unk_4;
	f32 unk_8;
	u32 unk_C[19];
};

union Cb424_col {
	u32 w;
	struct {
		u8 r;
		u8 g;
		u8 b;
		u8 a;
	} c;
};

struct Cb424_out {
	f32 unk_0;
	f32 unk_4;
	f32 unk_8;
	f32 unk_C;
	f32 unk_10;
	u32 unk_14;
	s32 unk_18;
	union Cb424_col unk_1C;
	union Cb424_col unk_20;
};

#pragma opt_common_subs off
void fn_1_CB424(u32 arg0, u32 arg1, u32 arg2, f32 arg3) {
	Obj_1_bss_7ACA0 *p = (Obj_1_bss_7ACA0 *)((u8 *)&lbl_1_bss_7ACA0 + arg2 * 12);
	struct Cb424_out out;
	struct Cb424_msg msg;

	if (((*((u32 *)&lbl_1_data_3D544 + fn_1_5910()) >> 24) & 1) != 0) {
		msg = *(struct Cb424_msg *)&lbl_1_rodata_26F8;
		msg.unk_0 = 0x9402;
		msg.unk_4 = lbl_1_rodata_5E1C;
		msg.unk_8 = (f32)(s32)arg1;
		fn_1_51E60(&msg);
		msg = *(struct Cb424_msg *)&lbl_1_rodata_26F8;
		msg.unk_0 = 0x940A;
		msg.unk_4 = lbl_1_rodata_5E20;
		msg.unk_8 = (f32)(s32)arg1;
		fn_1_51E60(&msg);

		out.unk_0 = (f32)(s32)arg0;
		out.unk_4 = (f32)(s32)(arg1 + 14);
		out.unk_8 = lbl_1_rodata_5E08;
		out.unk_C = lbl_1_rodata_5E0C;
		out.unk_10 = lbl_1_rodata_5CFC;
		out.unk_18 = -1;
		out.unk_1C.w = lbl_1_rodata_5E14;
		out.unk_20.w = lbl_1_rodata_5E18;
		out.unk_14 = p->unk_0;
		if (p->unk_4 != 0) {
			if ((p->unk_0 & 0xFFFFF000) == 0) {
				f32 t = (f32)(p->unk_0 & 0xFFF) / lbl_1_rodata_5E24;
				f32 x = lbl_1_rodata_5CD4 * t;

				out.unk_1C.c.r = (u8)(lbl_1_rodata_5CD8 * (lbl_1_rodata_5CFC - t));
				out.unk_1C.c.g = (u8)(lbl_1_rodata_5CD8 * (lbl_1_rodata_5CFC - t));
				out.unk_1C.c.b = (u8)(lbl_1_rodata_5CD8 * (lbl_1_rodata_5CFC - t));
				if (x > lbl_1_rodata_5CFC) {
					x = lbl_1_rodata_5CFC;
				}
				out.unk_20.c.a = (u8)(lbl_1_rodata_5CD8 * (lbl_1_rodata_5CFC - x));
			}
		}
		fn_1_CB6D8(&out);
	}
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_CB424 */

/* fzgx:begin fn_1_CB6D8 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

struct fn_1_CB6D8_lbl_1_rodata_5E50 {
    u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C;
    u32 unk_10; u32 unk_14; u32 unk_18; u32 unk_1C;
    u32 unk_20; u32 unk_24; u32 unk_28; u32 unk_2C;
};
struct fn_1_CB6D8_lbl_1_rodata_5E28 {
    u32 unk_0; u32 unk_4; u32 unk_8; u32 unk_C;
    u32 unk_10; u32 unk_14; u32 unk_18; u32 unk_1C;
    u32 unk_20; u32 unk_24;
};
struct CB6D8Color { u8 r, g, b, a; };
struct CB6D8Packet {
    s32 glyph;
    f32 x, y, z, width, height;
    u32 unk18, unk1C, unk20, unk24, unk28;
    f32 scale;
    u32 mode, unk34;
    struct CB6D8Color color;
    u32 flags;
    u32 unk40, unk44, unk48, unk4C, unk50, unk54;
};
struct CB6D8Input {
    f32 x, y, width, height, scale;
    u32 time;
    s32 rank;
    u32 flags;
    struct CB6D8Color color;
};
extern struct fn_1_CB6D8_lbl_1_rodata_5E28 lbl_1_rodata_5E28;
extern struct fn_1_CB6D8_lbl_1_rodata_5E50 lbl_1_rodata_5E50;
extern struct CB6D8Packet lbl_1_rodata_26F8;
extern f32 fn_1_519FC(f32);
extern f32 fn_1_51AC0(f32);
extern s32 fn_1_58C4(void);
extern s32 fn_1_5910(void);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_51E60(FontDrawPacket *);
extern const f32 lbl_1_rodata_5CFC, lbl_1_rodata_5E0C;
extern const f32 lbl_1_rodata_5E90, lbl_1_rodata_5E94;
extern const f32 lbl_1_rodata_5DC8, lbl_1_rodata_5CD8;
extern const f64 lbl_1_rodata_5CE8;
extern struct CB6D8Color lbl_1_rodata_5E80, lbl_1_rodata_5E84;
extern struct CB6D8Color lbl_1_rodata_5E88, lbl_1_rodata_5E8C;
static inline f32 CB6D8Alpha(u8 a) {
    return lbl_1_rodata_5CFC - (f32)(u32)a / lbl_1_rodata_5CD8;
}
void fn_1_CB6D8(void *arg0) {
    struct CB6D8Packet packet;
    struct fn_1_CB6D8_lbl_1_rodata_5E28 loc_38 = lbl_1_rodata_5E28;
    struct fn_1_CB6D8_lbl_1_rodata_5E50 loc_8 = lbl_1_rodata_5E50;
    s32 i;
    s32 rank = ((struct CB6D8Input *)arg0)->rank;
    u32 time = ((struct CB6D8Input *)arg0)->time;
    s32 first = 0;
    packet = lbl_1_rodata_26F8;
    packet.x = fn_1_519FC(((struct CB6D8Input *)arg0)->x);
    packet.y = fn_1_51AC0(((struct CB6D8Input *)arg0)->y);
    packet.width = ((struct CB6D8Input *)arg0)->scale * ((struct CB6D8Input *)arg0)->width * ((u32)fn_1_58C4() == 1 ? lbl_1_rodata_5CFC : lbl_1_rodata_5E0C);
    packet.height = ((struct CB6D8Input *)arg0)->height * ((u32)fn_1_58C4() == 1 ? lbl_1_rodata_5CFC : lbl_1_rodata_5E0C);
    packet.mode = 5;
    packet.scale = ((struct CB6D8Input *)arg0)->scale;
    packet.flags = ((struct CB6D8Input *)arg0)->flags;
    if ((u32)fn_1_58C4() > 1) {
        if (fn_1_5910() & 1) packet.x -= lbl_1_rodata_5E90;
        else packet.x += lbl_1_rodata_5E94;
    }
    if (rank == -1) first = 3;
    else if (rank < 9) first = 1;
    for (i = 11; i >= first; i--) {
        packet.x -= (f32)(((struct CB6D8Input *)arg0)->width * (((struct CB6D8Input *)arg0)->scale * ((f32 *)&loc_8)[i]) * ((u32)fn_1_58C4() == 1 ? lbl_1_rodata_5CFC : lbl_1_rodata_5E0C));
        if (i != 2) {
            packet.color = ((struct CB6D8Input *)arg0)->color;
            switch (i) {
            case 0: packet.glyph = ((u32 *)&loc_38)[((rank + 1) / 10) % 10]; packet.color = lbl_1_rodata_5E80; break;
            case 1: packet.glyph = ((u32 *)&loc_38)[(rank + 1) % 10]; packet.color = lbl_1_rodata_5E84; break;
            case 3: packet.glyph = ((u32 *)&loc_38)[((time >> 20) & 255) / 10]; break;
            case 4: packet.glyph = ((u32 *)&loc_38)[((time >> 20) & 255) % 10]; break;
            case 6: packet.glyph = ((u32 *)&loc_38)[((time >> 12) & 255) / 10]; break;
            case 7: packet.glyph = ((u32 *)&loc_38)[((time >> 12) & 255) % 10]; break;
            case 9: packet.glyph = ((u32 *)&loc_38)[(time & 4095) / 100]; break;
            case 10: packet.glyph = ((u32 *)&loc_38)[((time & 4095) / 10) % 10]; break;
            case 11: packet.glyph = ((u32 *)&loc_38)[(time & 4095) % 10]; break;
            case 5: packet.glyph = 0x943E; break;
            case 8: packet.glyph = 0x943F; break;
            default: packet.glyph = 0x9440; break;
            }
            packet.scale = ((struct CB6D8Input *)arg0)->scale;
            fn_1_4F734((FontDrawPacket *)&packet);
            if (packet.glyph == 0x943E || packet.glyph == 0x943F) {
                packet.glyph = 0x942F;
                packet.z += lbl_1_rodata_5DC8;
                packet.color = lbl_1_rodata_5E88;
                packet.scale = CB6D8Alpha(*((u8 *)arg0 + 0x23));
                fn_1_51E60((FontDrawPacket *)&packet);
            } else {
                packet.glyph = 0x9430;
                packet.z += lbl_1_rodata_5DC8;
                packet.color = lbl_1_rodata_5E8C;
                packet.scale = CB6D8Alpha(*((u8 *)arg0 + 0x23));
                fn_1_51E60((FontDrawPacket *)&packet);
            }
        }
    }
}
/* fzgx:end fn_1_CB6D8 */

/* fzgx:begin fn_1_CBC24 noprologue */
#include "types.h"
#include "rel/main_rel/enemy_ctrl.h"

struct fn_1_CBC24_Copy88 { u32 a[1]; f32 x, y, z; u32 rest[18]; };
struct fn_1_CBC24_Copy40 { u32 a[10]; };

extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5E20;
extern s32 fn_1_5910(void);
extern const f64 lbl_1_rodata_5C00;
extern struct fn_1_CBC24_Copy40 lbl_1_rodata_5E98;
extern struct fn_1_CBC24_Copy88 lbl_1_rodata_26F8;
extern void fn_1_51E60(void *);

void fn_1_CBC24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct fn_1_CBC24_Copy88 loc_30;
    struct fn_1_CBC24_Copy40 loc_8;
    s32 t0;
    s32 v11;
    loc_8 = lbl_1_rodata_5E98;
    t0 = fn_1_5910();
    if ((((&lbl_1_data_3D544.unk_0)[t0] >> 25) & 1) != 0) {
        loc_30 = lbl_1_rodata_26F8;
        *(f32 *)((u8 *)&loc_30 + 8) = (f32)(arg1 + 14);
        loc_30.a[0] = loc_8.a[(arg2 / 10) % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)arg0;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[arg2 % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 22);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x943e;
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 44);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x942f;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[(arg3 / 10) % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 54);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[arg3 % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 78);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x943f;
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 98);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x942f;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[(arg4 / 100) % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 108);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[(arg4 / 10) % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 130);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30.a[0] = loc_8.a[arg4 % 10];
        *(f32 *)((u8 *)&loc_30 + 4) = (f32)(arg0 + 152);
        fn_1_51E60(&loc_30);
        loc_30.a[0] = 0x9430;
        *(f32 *)((u8 *)&loc_30 + 12) += lbl_1_rodata_5DC8;
        fn_1_51E60(&loc_30);
        loc_30 = lbl_1_rodata_26F8;
        loc_30.a[0] = 0x940a;
        *(f32 *)((u8 *)&loc_30 + 4) = lbl_1_rodata_5E20;
        *(f32 *)((u8 *)&loc_30 + 8) = (f32)arg1;
        fn_1_51E60(&loc_30);
    }
}
/* fzgx:end fn_1_CBC24 */

/* fzgx:begin fn_1_CC27C */
// fn_1_CC27C: empty in retail (single blr).
void fn_1_CC27C(void) {
}
/* fzgx:end fn_1_CC27C */

/* fzgx:begin fn_1_CC280 noprologue */
#include "types.h"
#include "font.h"

struct fn_1_CC280_Copy88 { u32 a[22]; };
struct fn_1_CC280_lbl_1_rodata_5EC0 {
    u32 unk_0[10];
};
struct fn_1_CC280_lbl_1_data_3D544 {
    u32 unk_0[1];
};
struct fn_1_CC280_lbl_1_rodata_5C00 {
    f64 unk_0;
};

extern f32 lbl_1_rodata_5CFC;
extern f32 lbl_1_rodata_5DC8;
extern f32 lbl_1_rodata_5E0C;
extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_1_CC280_lbl_1_data_3D544 lbl_1_data_3D544;
extern struct fn_1_CC280_lbl_1_rodata_5C00 lbl_1_rodata_5C00;
extern struct fn_1_CC280_lbl_1_rodata_5EC0 lbl_1_rodata_5EC0;
extern u32 fn_1_51E60(void *);
extern FontDrawPacket lbl_1_rodata_26F8;
extern u32 fn_1_5910(void);

void fn_1_CC280(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    s32 i;
    struct fn_1_CC280_lbl_1_rodata_5EC0 loc_8;
    FontDrawPacket loc_30;
    s32 v;

    loc_8 = lbl_1_rodata_5EC0;
    i = fn_1_5910();
    if (((lbl_1_data_3D544.unk_0[i] >> 26) & 1) != 0) {
        if (arg3 < 10) {
            loc_30 = lbl_1_rodata_26F8;
            v = (arg2 % 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)arg0;
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + lbl_1_rodata_5DC8;
            fn_1_4F734(&loc_30);
            loc_30.image = 0x10000 - 27618;
            loc_30.x = (f32)(arg0 + 22);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            v = (arg3 % 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 + 34);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + lbl_1_rodata_5DC8;
            fn_1_4F734(&loc_30);
            loc_30.image = 0x10000 - 27646;
            loc_30.x = (f32)(arg0 + 30);
            loc_30.y = (f32)(arg1 + 26);
            fn_1_51E60(&loc_30);
        } else {
            loc_30 = lbl_1_rodata_26F8;
            v = (arg2 / 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 - 16);
            loc_30.y = (f32)arg1;
            loc_30.scale_x = loc_30.scale_x * lbl_1_rodata_5E0C;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + lbl_1_rodata_5DC8;
            fn_1_4F734(&loc_30);
            v = (arg2 % 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 + 1);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + lbl_1_rodata_5DC8;
            fn_1_4F734(&loc_30);
            loc_30.image = 0x10000 - 27618;
            loc_30.x = (f32)(arg0 + 20);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            v = (arg3 / 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 + 31);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + lbl_1_rodata_5DC8;
            fn_1_4F734(&loc_30);
            v = (arg3 % 10);
            loc_30.image = loc_8.unk_0[v];
            loc_30.x = (f32)(arg0 + 48);
            loc_30.y = (f32)arg1;
            fn_1_51E60(&loc_30);
            loc_30.image = 0x10000 - 27600;
            loc_30.z = loc_30.z + lbl_1_rodata_5DC8;
            fn_1_4F734(&loc_30);
            loc_30.image = 0x10000 - 27646;
            loc_30.x = (f32)(arg0 + 41);
            loc_30.y = (f32)(arg1 + 26);
            loc_30.scale_x = lbl_1_rodata_5CFC;
            fn_1_51E60(&loc_30);
        }
    }
}
/* fzgx:end fn_1_CC280 */

/* fzgx:begin fn_1_CC8E4 noprologue */
#include "types.h"
#include "font.h"

extern u32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_5EE8[10];
extern const f64 lbl_1_rodata_5C00;
extern const f64 lbl_1_rodata_5CE8;
extern const f32 lbl_1_rodata_5CF8;
extern const f32 lbl_1_rodata_5C48;
extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5F10;
extern u32 lbl_1_data_3D544[1];
extern void *fn_1_8627C(s32);
extern u32 fn_1_3F114(void);
extern u32 fn_1_5910(void);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern int fn_1_4F734(FontDrawPacket *);

void fn_1_CC8E4(s32 arg0, s32 arg1, s32 arg2) {
    FontDrawPacket sp30;
    u32 sp8[10];
    s32 val1;
    u8 val2;

    sp8[0] = lbl_1_rodata_5EE8[0];
    sp8[1] = lbl_1_rodata_5EE8[1];
    sp8[2] = lbl_1_rodata_5EE8[2];
    sp8[3] = lbl_1_rodata_5EE8[3];
    sp8[4] = lbl_1_rodata_5EE8[4];
    sp8[5] = lbl_1_rodata_5EE8[5];
    sp8[6] = lbl_1_rodata_5EE8[6];
    sp8[7] = lbl_1_rodata_5EE8[7];
    sp8[8] = lbl_1_rodata_5EE8[8];
    sp8[9] = lbl_1_rodata_5EE8[9];
    val1 = *(s32 *)((u8 *)fn_1_8627C(arg0) + 280) + 1;
    val2 = fn_1_3F114();
    if ((lbl_1_data_3D544[fn_1_5910()] >> 26) & 1) {
        if ((s32)val2 < 0xA) {
            sp30 = *(const FontDrawPacket *)(((u8 *)lbl_1_rodata_26F8) + 0);
            sp30.image = sp8[val1 % 10];
            sp30.x = (f32)(arg1 + 3);
            sp30.y = (f32)arg2;
            sp30.scale_x *= lbl_1_rodata_5CF8 / (f32)fn_1_48690(sp30.image);
            sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
            fn_1_4F734(&sp30);
            sp30.image = 0x9430;
            sp30.z += lbl_1_rodata_5DC8;
            fn_1_4F734(&sp30);
            sp30 = *(const FontDrawPacket *)(((u8 *)lbl_1_rodata_26F8) + 0);
            sp30.image = 0x941E;
            sp30.x = (f32)(arg1 + 0x12);
            sp30.y = (f32)arg2;
            sp30.scale_x *= lbl_1_rodata_5C48 / (f32)fn_1_48690(0x941E);
            sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
            fn_1_4F734(&sp30);
            sp30 = *(const FontDrawPacket *)(((u8 *)lbl_1_rodata_26F8) + 0);
            sp30.image = sp8[val2 % 10];
            sp30.x = (f32)(arg1 + 0x1C);
            sp30.y = (f32)arg2;
            sp30.scale_x *= lbl_1_rodata_5CF8 / (f32)fn_1_48690(sp30.image);
            sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
            fn_1_4F734(&sp30);
            sp30.image = 0x9430;
            sp30.z += lbl_1_rodata_5DC8;
            fn_1_4F734(&sp30);
            sp30 = *(const FontDrawPacket *)(((u8 *)lbl_1_rodata_26F8) + 0);
            sp30.image = 0x9402;
            sp30.x = (f32)(arg1 + 0x2D);
            sp30.y = (f32)(arg2 + 9);
            fn_1_4F734(&sp30);
            return;
        }
        sp30 = *(const FontDrawPacket *)(((u8 *)lbl_1_rodata_26F8) + 0);
        sp30.image = sp8[val1 / 10];
        sp30.x = (f32)(arg1 - 0x1D);
        sp30.y = (f32)arg2;
        sp30.scale_x *= lbl_1_rodata_5CF8 / (f32)fn_1_48690(sp30.image);
        sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
        fn_1_4F734(&sp30);
        sp30.image = 0x9430;
        sp30.z += lbl_1_rodata_5DC8;
        fn_1_4F734(&sp30);
        sp30.image = sp8[val1 % 10];
        sp30.x = (f32)(arg1 - 0xD);
        sp30.y = (f32)arg2;
        fn_1_4F734(&sp30);
        sp30.image = 0x9430;
        sp30.z += lbl_1_rodata_5DC8;
        fn_1_4F734(&sp30);
        sp30 = *(const FontDrawPacket *)(((u8 *)lbl_1_rodata_26F8) + 0);
        sp30.image = 0x941E;
        sp30.x = (f32)(arg1 + 2);
        sp30.y = (f32)arg2;
        sp30.scale_x *= lbl_1_rodata_5C48 / (f32)fn_1_48690(0x941E);
        sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
        fn_1_4F734(&sp30);
        sp30 = *(const FontDrawPacket *)(((u8 *)lbl_1_rodata_26F8) + 0);
        sp30.image = sp8[val2 / 10];
        sp30.x = (f32)(arg1 + 0xC);
        sp30.y = (f32)arg2;
        sp30.scale_x *= lbl_1_rodata_5CF8 / (f32)fn_1_48690(sp30.image);
        sp30.scale_y *= lbl_1_rodata_5F10 / (f32)fn_1_486C4(sp30.image);
        fn_1_4F734(&sp30);
        sp30.image = 0x9430;
        sp30.z += lbl_1_rodata_5DC8;
        fn_1_4F734(&sp30);
        sp30.image = sp8[val2 % 10];
        sp30.x = (f32)(arg1 + 0x1C);
        sp30.y = (f32)arg2;
        fn_1_4F734(&sp30);
        sp30.image = 0x9430;
        sp30.z += lbl_1_rodata_5DC8;
        fn_1_4F734(&sp30);
        sp30 = *(const FontDrawPacket *)(((u8 *)lbl_1_rodata_26F8) + 0);
        sp30.image = 0x9402;
        sp30.x = (f32)(arg1 + 0x2D);
        sp30.y = (f32)(arg2 + 9);
        fn_1_4F734(&sp30);
    }
}
/* fzgx:end fn_1_CC8E4 */

/* fzgx:begin fn_1_CD36C noprologue */
#include "types.h"
#include "font.h"

struct fn_1_CD36C_Copy88 { u32 a[22]; };
struct fn_1_CD36C_lbl_1_rodata_5C48 {
    f32 unk_0;
};

extern f32 lbl_1_rodata_5F10;
extern f64 lbl_1_rodata_5C00;
extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_1_CD36C_lbl_1_rodata_5C48 lbl_1_rodata_5C48;
extern u32 fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern u32 lbl_1_rodata_26F8;
extern u32 fn_1_5910(void);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);

void fn_1_CD36C(u32 arg0, u32 arg1, u32 arg2) {
    FontDrawPacket loc_8;
    f32 v3;
    f32 v5;
    u16 lab_t5;

{
    s32 t0;
    t0 = fn_1_5910();
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = 0x9421;
    lab_t5 = 2;
    fn_1_51564(0, 0, 24, 20, 2, lab_t5);
    loc_8.x = (f32)(s32)arg1;
    loc_8.y = (f32)(s32)arg2;
    loc_8.z = *(f32 *)((u8 *)&lbl_1_rodata_5C48 + 0);
    fn_1_5158C(&loc_8, loc_8.image, (s16)(t0 % 2), (s16)(t0 / 2));
}
    fn_1_4F734(&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v3 = (f32)(s32)(arg1 + 12);
    loc_8.image = 0x9422;
    v5 = (f32)(s32)(arg2 + 10);
    loc_8.x = v3;
    loc_8.y = v5;
    loc_8.z = lbl_1_rodata_5F10;
    loc_8.flags = 10;
    fn_1_4F734(&loc_8);
}
/* fzgx:end fn_1_CD36C */

/* fzgx:begin fn_1_CD51C */
extern u32 fn_1_5910(void *object);
extern void *fn_1_8627C(void *object);
extern void *fn_1_4DF60(void);
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5C40;
extern const f32 lbl_1_rodata_5F18;
extern u32 fn_1_58C4(void);




extern u32 lbl_1_rodata_5F14;


extern void fn_1_CD6C0(void);
extern f32 fn_1_519FC(f32 value);
extern f32 fn_1_51AC0(f32 value);



typedef struct {
    u8 pad_0[0x6];
    u16 unk_6;
    u32 unk_8;
    f32 unk_c;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1c;
    u8 pad_20[0x18];
    u32 unk_38;
    f32 unk_3c;
    u32 unk_40;
    u8 pad_44[0x1c];
    void *unk_60;
    u8 pad_64[0x14];
    void (*unk_78)(void);
} Fn1Cd51cObject;

void fn_1_CD51C(void *object) {
    u32 index;
    void *actor;
    Fn1Cd51cObject *state;
    f32 factor;

    index = fn_1_5910(object);
    if (((((u32 *)&lbl_1_data_3D544)[index] >> 19) & 1) == 0) {
        return;
    }

    actor = fn_1_8627C(object);
    if (actor == 0) {
        return;
    }
    if (*(s32 *)((u8 *)actor + 0x10c) == 0) {
        return;
    }
    if (*(s32 *)((u8 *)actor + 0x110) == 0) {
        return;
    }

    state = fn_1_4DF60();
    if (state == 0) {
        return;
    }

    state->unk_8 = 0x9435;
    state->unk_c = lbl_1_rodata_5C3C;
    state->unk_10 = lbl_1_rodata_5C40;
    state->unk_14 = lbl_1_rodata_5F18;

    if (fn_1_58C4() == 1) {
        factor = lbl_1_rodata_5CFC;
    } else {
        factor = lbl_1_rodata_5E0C;
    }
    state->unk_18 *= factor;

    if (fn_1_58C4() == 1) {
        factor = lbl_1_rodata_5CFC;
    } else {
        factor = lbl_1_rodata_5E0C;
    }
    state->unk_1c *= factor;

    state->unk_38 = 10;
    state->unk_40 = lbl_1_rodata_5F14;

    if (fn_1_58C4() == 1 && (s32)lbl_1_bss_4E6A8 != 0) {
        u32 value = state->unk_38 | 0x8000000;
        state->unk_38 = value;
        state->unk_3c = (f32)(s32)lbl_1_bss_4E6AC;
    }

    state->unk_6 = 0;
    state->unk_78 = fn_1_CD6C0;
    state->unk_60 = object;
    state->unk_c = fn_1_519FC(state->unk_c);
    state->unk_10 = fn_1_51AC0(state->unk_10);
}
/* fzgx:end fn_1_CD51C */

/* fzgx:begin fn_1_CD6C0 */
extern u16 fn_1_8664C(void *object);
extern void *fn_1_8627C(void *object);
extern u32 fn_1_864E8(void *object);

typedef struct fn_1_CD6C0_object {
    s32 flags;
    u16 pad4;
    s16 state;
    u8 pad8[0x2c];
    f32 value;
    u8 pad38[0x28];
    void *controller;
} fn_1_CD6C0_object;

typedef struct fn_1_CD6C0_target {
    u8 pad0[0x10c];
    s32 flags;
} fn_1_CD6C0_target;

#pragma opt_propagation off
void fn_1_CD6C0(fn_1_CD6C0_object *object) {
    s32 state;
    s32 out;
    void *controller;
    fn_1_CD6C0_target *target;

    state = object->state;
    if (state + 1 > 0x3b) {
        out = 0;
    } else {
        state++;
        out = 0x3b;
        if (state >= 0) {
            out = state;
        }
    }
    object->state = out;
    if (object->state < 0x1e) {
        object->value = lbl_1_rodata_5CFC;
    } else {
        object->value = lbl_1_rodata_5D90;
    }
    if (fn_1_8664C(object->controller) != 0) {
        object->value = lbl_1_rodata_5D90;
        object->flags = 0;
    }
    if (object->state == 0x1e) {
        controller = object->controller;
        target = fn_1_8627C(controller);
        if (target != 0) {
            if (target->flags == 0) {
                object->flags = 0;
            }
            if ((fn_1_864E8(controller) & 0x10010880) != 0) {
                object->flags = 0;
            }
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_1_CD6C0 */

/* fzgx:begin fn_1_CD7BC noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


struct FzgxCopy_88 { u32 words[22]; };


extern f32 lbl_1_rodata_26F8[22];


extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5E0C;


extern const f32 lbl_1_rodata_5C40;
extern const f32 lbl_1_rodata_5F18;
extern u32 fn_1_58C4(void);


extern void fn_1_CD7BC(int arg0);


extern const f32 lbl_1_rodata_5D90;


extern const f32 lbl_1_rodata_5C48;
extern const f32 lbl_1_rodata_5F10;
extern u16 fn_1_48690(u32 unused);
extern u16 fn_1_486C4(u32 value);
extern u16 fn_1_8664C(int index);
extern u32 fn_1_864E8(int index);
extern f32 lbl_8006D0B4(f32);


extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5C40;
extern const f32 lbl_1_rodata_5C48;
extern const f32 lbl_1_rodata_5C7C;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D90;
extern const f32 lbl_1_rodata_5E0C;
extern const f32 lbl_1_rodata_5F10;
extern const f32 lbl_1_rodata_5F18;
extern const f32 lbl_1_rodata_5F1C;
void fn_1_CD7BC(int arg0) {
s32 base;
s32 y;
s32 n;
s32 i;
struct FzgxCopy_88 pkt;
f32 scale;
f32 one;
f32 step;
f32 count;
if (!(fn_1_864E8(arg0) & 0x10010080)) {
n = fn_1_8664C(arg0);
if (n > 0x14 && n < 0xAA) {
pkt = *(const struct FzgxCopy_88 *)(((u32 *)&lbl_1_rodata_26F8));
pkt.words[0] = 0x940C;
*(f32 *)((u8 *)&pkt + 12) = lbl_1_rodata_5F18;
if (fn_1_58C4() == 1) {
scale = lbl_1_rodata_5CFC;
} else {
scale = lbl_1_rodata_5E0C;
}
*(f32 *)((u8 *)&pkt + 16) *= scale;
if (fn_1_58C4() == 1) {
scale = lbl_1_rodata_5CFC;
} else {
scale = lbl_1_rodata_5E0C;
}
*(f32 *)((u8 *)&pkt + 20) *= scale;
i = 0;
y = 0;
base = n - 0x14;
*(f32 *)((u8 *)&pkt + 44) = lbl_1_rodata_5D90;
one = lbl_1_rodata_5CFC;
do {
s32 d;
*(f32 *)((u8 *)&pkt + 20) = one;
d = base - i;
if (i < 6) {
if (d > 0 && d < 0xA) {
pkt.words[0xC] = 9;
*(f32 *)((u8 *)&pkt + 4) = lbl_1_rodata_5C3C - (f32)((fn_1_48690(pkt.words[0]) >> 1U) & 0x7FFF);
} else {
pkt.words[0xC] = 0xB;
*(f32 *)((u8 *)&pkt + 4) = lbl_1_rodata_5C3C + (f32)((fn_1_48690(pkt.words[0]) >> 1U) & 0x7FFF);
}
} else if (d > 0 && d < 0xA) {
pkt.words[0xC] = 0xB;
*(f32 *)((u8 *)&pkt + 4) = lbl_1_rodata_5C3C + (f32)((fn_1_48690(pkt.words[0]) >> 1U) & 0x7FFF);
} else {
pkt.words[0xC] = 9;
*(f32 *)((u8 *)&pkt + 4) = lbl_1_rodata_5C3C - (f32)((fn_1_48690(pkt.words[0]) >> 1U) & 0x7FFF);
}
*(f32 *)((u8 *)&pkt + 8) = (f32)y + (lbl_1_rodata_5C40 - (f32)((fn_1_486C4(pkt.words[0]) >> 1U) & 0x7FFF));
if (d > 0 && d < 0xA) {
*(f32 *)((u8 *)&pkt + 16) *= lbl_8006D0B4(lbl_1_rodata_5C48 / (f32)(d + 1));
*(f32 *)((u8 *)&pkt + 44) = (f32)d / lbl_1_rodata_5C48;
} else if (d > 0x82 && d < 0x96) {
*(f32 *)((u8 *)&pkt + 16) *= lbl_8006D0B4(lbl_1_rodata_5F10 / (f32)(0x97 - d));
*(f32 *)((u8 *)&pkt + 44) = (f32)(0x96 - d) / lbl_1_rodata_5F10;
} else if (d >= 0xA && d <= 0x82) {
*(f32 *)((u8 *)&pkt + 16) = lbl_1_rodata_5CFC;
*(f32 *)((u8 *)&pkt + 44) = lbl_1_rodata_5CFC;
} else if (d <= 0 || d >= 0x96) {
*(f32 *)((u8 *)&pkt + 44) = lbl_1_rodata_5D90;
}
count = lbl_1_rodata_5C7C;
step = lbl_1_rodata_5F1C;
*(f32 *)((u8 *)&pkt + 28) = (f32)i / count;
*(f32 *)((u8 *)&pkt + 36) = (f32)(i + 1) / count;
*(f32 *)((u8 *)&pkt + 20) *= step;
fn_1_4F734((FontDrawPacket *)&pkt);
i += 1;
y += 4;
} while (i < 0xD);
}
}
}
/* fzgx:end fn_1_CD7BC */

/* fzgx:begin fn_1_CDC8C noprologue */
#include "types.h"
#include "font.h"

#pragma fp_contract off

typedef struct {
    s32 *unk_0;
    f32 *unk_4;
    u8 *unk_8;
    u8 *unk_C;
    u32 unk_10;
    u32 unk_14;
} HudSource;

extern HudSource lbl_1_bss_84;
extern u32 lbl_1_data_3D544[];
extern const FontDrawPacket lbl_1_rodata_26F8;
extern const u32 lbl_1_rodata_5F20;
extern const u32 lbl_1_rodata_5F24;
extern const u32 lbl_1_rodata_5F28;

extern void fn_1_CF5B0(s32);
extern s32 fn_1_5910(void);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(u32);
extern void fn_1_52088(void);
extern s16 fn_1_E5430(s16);
extern s16 fn_1_E5568(s16);

extern const f32 lbl_1_rodata_5C7C;
extern const f32 lbl_1_rodata_5C80;
extern const f32 lbl_1_rodata_5CCC;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D04;
extern const f32 lbl_1_rodata_5D18;
extern const f32 lbl_1_rodata_5D90;
extern const f32 lbl_1_rodata_5DBC;
extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5DCC;
extern const f32 lbl_1_rodata_5E24;
extern const f32 lbl_1_rodata_5E90;
extern const f32 lbl_1_rodata_5E94;
extern const f32 lbl_1_rodata_5F2C;
extern const f32 lbl_1_rodata_5F30;
extern const f32 lbl_1_rodata_5F34;
extern const f32 lbl_1_rodata_5F38;
extern const f32 lbl_1_rodata_5F3C;
extern const f32 lbl_1_rodata_5F40;
extern const f32 lbl_1_rodata_5F44;
extern const f32 lbl_1_rodata_5F48;
extern const f32 lbl_1_rodata_5F4C;
extern const f32 lbl_1_rodata_5F50;
extern const f32 lbl_1_rodata_5F54;
extern const f32 lbl_1_rodata_5F58;
extern const f32 lbl_1_rodata_5F5C;
extern const f32 lbl_1_rodata_5F60;
extern const f32 lbl_1_rodata_5F64;
extern const f32 lbl_1_rodata_5F68;
extern const f32 lbl_1_rodata_5F6C;
extern const f32 lbl_1_rodata_5F70;
extern const f32 lbl_1_rodata_5F74;
extern const f32 lbl_1_rodata_5F78;
extern const f32 lbl_1_rodata_5F7C;
extern const f32 lbl_1_rodata_5F80;
extern const f32 lbl_1_rodata_5F84;
extern const f32 lbl_1_rodata_5F88;
extern const f32 lbl_1_rodata_5F8C;
extern const f32 lbl_1_rodata_5F90;
extern const f32 lbl_1_rodata_5F94;
extern const f32 lbl_1_rodata_5F98;
extern const f32 lbl_1_rodata_5F9C;
extern const f32 lbl_1_rodata_5FA0;
extern const f32 lbl_1_rodata_5FA4;
extern const f32 lbl_1_rodata_5FA8;
extern const f32 lbl_1_rodata_5FAC;
extern const f32 lbl_1_rodata_5FB0;
extern const f32 lbl_1_rodata_5FB4;

static inline f32 blink_scale(s32 n) {
    if (n > 15) {
        return lbl_1_rodata_5CFC;
    }
    return (f32)n / lbl_1_rodata_5D04;
}
static inline f32 blink_scale_b(s32 n, f32 scale) {
    if (n > 15) {
        return scale;
    }
    return (f32)n / lbl_1_rodata_5D04;
}

#define DIG cur
#define CURSET cur = d2;

#define CNT c
#define LV j

#define YV y
#define YDEC 
#define p3_s s
void fn_1_CDC8C(void) {
    FontDrawPacket p1;
    FontDrawPacket p2;
    FontDrawPacket p3;
    s8 a;
    s8 d;
    s32 d2;
    s8 cur;
    f32 x0;
    f32 y0;
    f32 s;
    s32 n;
    s32 m;
    s32 i;
    f32 scale;
    f32 y;
    f32 v;
    s32 j;
    s32 c;
    f32 v_300;
    f32 v_430;
    f32 v_mul;
    f32 v_div;
    f32 yy;
    f32 fx;
    f32 t;

    n = 0;
    if (lbl_1_bss_84.unk_0 != NULL) {
        n = *lbl_1_bss_84.unk_0;
    }
    fn_1_CF5B0(n);

    if ((lbl_1_data_3D544[fn_1_5910()] >> 14) & 1) {
        if (fn_1_58C4() == 1) {
            fn_1_52070(0xA0);
        }
        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA0D;
        p1.x = lbl_1_rodata_5F2C;
        p1.y = lbl_1_rodata_5D18;
        fn_1_4F734(&p1);

        a = fn_1_E5430(1);
        d = a - fn_1_E5568(1);
        scale = lbl_1_rodata_5CFC;
        d2 = d;
        if (lbl_1_bss_84.unk_0 != NULL) {
            n = *lbl_1_bss_84.unk_0;
            if (n > 0) {
                d2 = d - 1;
                scale = blink_scale_b(n, scale);
            }
        }
        CURSET
        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1D;
        CURSET
        fn_1_51678(&p1, p1.image, (s8)(DIG / 10) * 18, 0, 18, 24);
        p1.x = lbl_1_rodata_5F30;
        p1.y = lbl_1_rodata_5F34;
        p1.flags = 9;
        if ((s8)(DIG / 10) != (s8)(d / 10)) {
            p1.scale_y = scale;
            p1.alpha = scale;
        }
        fn_1_4F734(&p1);

        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1D;
        fn_1_51678(&p1, p1.image, (s8)(DIG % 10) * 18, 0, 18, 24);
        p1.x = lbl_1_rodata_5F38;
        p1.y = lbl_1_rodata_5F34;
        p1.flags = 9;
        if ((s8)(DIG % 10) != (s8)(d % 10)) {
            p1.scale_y = scale;
            p1.alpha = scale;
        }
        fn_1_4F734(&p1);

        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1D;
        fn_1_51678(&p1, p1.image, (s8)(a / 10) * 18, 0, 18, 24);
        p1.x = lbl_1_rodata_5F3C;
        p1.y = lbl_1_rodata_5F34;
        p1.flags = 9;
        *(u32 *)p1.color = lbl_1_rodata_5F20;
        fn_1_4F734(&p1);

        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1D;
        fn_1_51678(&p1, p1.image, (s8)(a % 10) * 18, 0, 18, 24);
        p1.x = lbl_1_rodata_5F40;
        p1.y = lbl_1_rodata_5F34;
        p1.flags = 9;
        *(u32 *)p1.color = lbl_1_rodata_5F24;
        fn_1_4F734(&p1);

        p1 = lbl_1_rodata_26F8;
        p1.image = 0xBA1E;
        p1.x = lbl_1_rodata_5F44;
        p1.y = lbl_1_rodata_5F48;
        *(u32 *)p1.color = lbl_1_rodata_5F28;
        fn_1_4F734(&p1);
        fn_1_52088();
    }

    if ((lbl_1_data_3D544[fn_1_5910()] >> 13) & 1) {
        n = 0;
        m = 800;
        if (fn_1_58C4() == 1) {
            fn_1_52070(0);
        }
        if (lbl_1_bss_84.unk_4 != NULL) {
            n = *lbl_1_bss_84.unk_4;
        }
        if (lbl_1_bss_84.unk_10 != 0) {
            m = lbl_1_bss_84.unk_10;
        }

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA10;
        p2.x = lbl_1_rodata_5CCC;
        p2.y = lbl_1_rodata_5F4C;
        p2.z -= lbl_1_rodata_5DC8;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA14;
        p2.x = lbl_1_rodata_5D18;
        p2.y = lbl_1_rodata_5DBC;
        p2.z -= lbl_1_rodata_5F50;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA0F;
        p2.x = lbl_1_rodata_5F54;
        p2.y = lbl_1_rodata_5F58;
        p2.z -= lbl_1_rodata_5F5C;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA20;
        p2.x = lbl_1_rodata_5F54;
        p2.y = lbl_1_rodata_5F58;
        p2.z -= lbl_1_rodata_5F60;
        p2.scale_y = lbl_1_rodata_5F64;
        fn_1_4F734(&p2);

        v_430 = lbl_1_rodata_5F68;
        v_430 = v_430;
        v_mul = lbl_1_rodata_5F6C * (f32)(n - m);
        v_mul = v_mul;
        v_300 = lbl_1_rodata_5F70;
        v_300 = v_300;
        v_div = v_mul / v_300;
        v_div = v_div;
        YV = v_430 - v_div;
        if (YV < lbl_1_rodata_5F74) {
            YV = lbl_1_rodata_5F74;
        } else if (YV > v_430) {
            YV = v_430;
        }

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA02;
        p2.x = lbl_1_rodata_5F78;
        p2.y = YV - lbl_1_rodata_5E94;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA02;
        p2.x = lbl_1_rodata_5F7C;
        p2.y = YV - lbl_1_rodata_5E94;
        p2.rotation_z = -0x8000;
        p2.flags = 15;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA1B;
        p2.x = lbl_1_rodata_5CCC;
        p2.y = YV;
        p2.z -= lbl_1_rodata_5F80;
        fn_1_4F734(&p2);

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA07;
        p2.x = lbl_1_rodata_5F84;
        p2.y = YV - lbl_1_rodata_5DCC;
        fn_1_4F734(&p2);

        YDEC
        for (i = 0; (i < 5 && n > 0) || (i == 0 && n <= 0); i++) {
            p2 = lbl_1_rodata_26F8;
            p2.image = 0xBA04;
            fn_1_51678(&p2, p2.image, (s8)(n % 10) * 20, 0, 20, 20);
            p2.x = lbl_1_rodata_5F88 - lbl_1_rodata_5F8C * (f32)i;
            p2.y = YV - lbl_1_rodata_5C7C;
            fn_1_4F734(&p2);
            n /= 10;
        }

        for (i = 0; i < 3 && m > 0; i++) {
            p2 = lbl_1_rodata_26F8;
            p2.image = 0xBA05;
            fn_1_51678(&p2, p2.image, (s8)(m % 10) * 12, 0, 12, 12);
            p2.x = lbl_1_rodata_5F90 - lbl_1_rodata_5C80 * (f32)i;
            p2.y = lbl_1_rodata_5F94;
            p2.scale_y = lbl_1_rodata_5F98;
            fn_1_4F734(&p2);
            m /= 10;
        }

        p2 = lbl_1_rodata_26F8;
        p2.image = 0xBA00;
        p2.x = lbl_1_rodata_5F9C;
        p2.y = lbl_1_rodata_5FA0;
        fn_1_4F734(&p2);
        fn_1_52088();
    }

    if ((lbl_1_data_3D544[fn_1_5910()] >> 12) & 1) {
        v = lbl_1_rodata_5D90;
        if (fn_1_58C4() == 1) {
            fn_1_52070(0xA0);
        }
        if (lbl_1_bss_84.unk_C != NULL && lbl_1_bss_84.unk_8 != NULL) {
            v = *(f32 *)(lbl_1_bss_84.unk_8 + 0xFC) * (f32)lbl_1_bss_84.unk_C[4]
                - *(f32 *)(lbl_1_bss_84.unk_8 + 0xF8);
        }
        x0 = lbl_1_rodata_5FA4;
        y0 = lbl_1_rodata_5D18;
        s = lbl_1_rodata_5CFC;
        if (v < lbl_1_rodata_5E24) {
            x0 = lbl_1_rodata_5FA8;
            y0 = lbl_1_rodata_5FAC;
            s = lbl_1_rodata_5F98;
        }
        CNT = v;

        p3 = lbl_1_rodata_26F8;
        p3.image = 0xBA13;
        p3.x = x0;
        p3.y = y0;
        p3.scale_x *= s;
        p3.scale_y *= s;
        fn_1_4F734(&p3);

        p3 = lbl_1_rodata_26F8;
        p3.image = 0xBA08;
        p3.x = x0 + lbl_1_rodata_5FB0 * s;
        p3.y = y0 + lbl_1_rodata_5E90 * s;
        p3.scale_x *= s;
        p3.scale_y *= s;
        fn_1_4F734(&p3);

        for (LV = 0; (LV < 5 && CNT > 0) || (LV == 0 && CNT <= 0); LV++) {
            p3 = lbl_1_rodata_26F8;
            p3.image = 0xBA04;
            fn_1_51678(&p3, p3.image, (s8)(CNT % 10) * 20, 0, 20, 20);
            p3.y = y0;
            t = (lbl_1_rodata_5FB4 - lbl_1_rodata_5F78 * (f32)LV);
            p3.x = x0 + t * s;
            p3.scale_x *= s;
            p3.scale_y *= s;
            fn_1_4F734(&p3);
            CNT /= 10;
        }
        fn_1_52088();
    }
}
/* fzgx:end fn_1_CDC8C */

/* fzgx:begin fn_1_CEB38 noprologue */
#include "types.h"
#include "font.h"

#pragma fp_contract off

typedef struct {
    s32 *unk_0;
    f32 *unk_4;
    u8 *unk_8;
    u8 *unk_C;
    u32 unk_10;
    u32 unk_14;
} HudSource;

typedef struct {
    u8 pad_0[0x1E0];
    u8 min;
    u8 sec;
    u16 ms;
} ClearRecord;

typedef struct {
    u8 r, g, b, a;
} Color;

extern HudSource lbl_1_bss_84;
extern const FontDrawPacket lbl_1_rodata_26F8;

extern s32 fn_1_5910(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_49514(u32 *);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern int fn_1_8623C(void);
extern ClearRecord *fn_1_3F0D8(u8, u32 *, u32 *);
extern f32 lbl_8006D188(s16);

extern const f64 lbl_1_rodata_5C00;
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5C40;
extern const f32 lbl_1_rodata_5C48;
extern const f32 lbl_1_rodata_5CB0;
extern const f32 lbl_1_rodata_5CCC;
extern const f32 lbl_1_rodata_5CD8;
extern const f32 lbl_1_rodata_5CF4;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D04;
extern const f32 lbl_1_rodata_5D90;
extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5E90;
extern const f32 lbl_1_rodata_5F98;
extern const f32 lbl_1_rodata_5FCC;
extern const f32 lbl_1_rodata_5FD0;
extern const f32 lbl_1_rodata_5FD4;
extern const f32 lbl_1_rodata_5FD8;
extern const f32 lbl_1_rodata_5FDC;
extern const f64 lbl_1_rodata_5FE0;
extern const f32 lbl_1_rodata_5FE8;
extern const f32 lbl_1_rodata_5FEC;
extern const u32 lbl_1_rodata_5FC8;
extern u8 lbl_1_data_3D290__fzgx_offset_0[];
extern u8 lbl_1_data_3D294__fzgx_offset_0[];
extern u8 lbl_1_data_3D2A0__fzgx_offset_0[];
extern u8 lbl_1_data_3D2AC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2B8__fzgx_offset_0[];
extern u8 lbl_1_data_3D2C4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2CC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2D4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2DC__fzgx_offset_0[];
extern u8 lbl_1_data_3D2E4__fzgx_offset_0[];
extern u8 lbl_1_data_3D2F0__fzgx_offset_0[];
extern u8 lbl_1_data_3D300__fzgx_offset_0[];
extern u8 lbl_1_data_3D310__fzgx_offset_0[];
extern u8 lbl_1_data_3D318__fzgx_offset_0[];
extern u8 lbl_1_data_3D320__fzgx_offset_0[];
extern u8 lbl_1_data_3D32C__fzgx_offset_0[];
extern u8 lbl_1_data_3D338__fzgx_offset_0[];
extern u8 lbl_1_data_3D348__fzgx_offset_0[];
extern u8 lbl_1_data_3D350__fzgx_offset_0[];
extern u8 lbl_1_data_3D35C__fzgx_offset_0[];
extern u8 lbl_1_data_3D368__fzgx_offset_0[];
extern u8 lbl_1_data_3D378__fzgx_offset_0[];
extern u8 lbl_1_data_3D380__fzgx_offset_0[];
extern u8 lbl_1_data_3D38C__fzgx_offset_0[];
extern u8 lbl_1_data_3D398__fzgx_offset_0[];
extern u8 lbl_1_data_3D3A8__fzgx_offset_0[];
extern u8 lbl_1_data_3D3B0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3BC__fzgx_offset_0[];
extern u8 lbl_1_data_3D3C4__fzgx_offset_0[];
extern u8 lbl_1_data_3D3D0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3E0__fzgx_offset_0[];
extern u8 lbl_1_data_3D3EC__fzgx_offset_0[];
extern u8 lbl_1_data_3D3F8__fzgx_offset_0[];
extern u8 lbl_1_data_3D400__fzgx_offset_0[];
extern u8 lbl_1_data_3D414__fzgx_offset_0[];
extern u8 lbl_1_data_3D424__fzgx_offset_0[];
extern u8 lbl_1_data_3D434__fzgx_offset_0[];
extern u8 lbl_1_data_3D440__fzgx_offset_0[];
extern u8 lbl_1_data_3D44C__fzgx_offset_0[];
extern u8 lbl_1_data_3D45C__fzgx_offset_0[];
extern u8 lbl_1_data_3D464__fzgx_offset_0[];
extern u8 lbl_1_data_3D470__fzgx_offset_0[];
extern u8 lbl_1_data_3D478__fzgx_offset_0[];
extern u8 lbl_1_data_3D480__fzgx_offset_0[];
extern u8 lbl_1_data_3D488__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_1_data_3D290_gap_0[173] = {0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, (u32)lbl_1_data_3D290__fzgx_offset_0, (u32)lbl_1_data_3D294__fzgx_offset_0, (u32)lbl_1_data_3D2A0__fzgx_offset_0, (u32)lbl_1_data_3D2AC__fzgx_offset_0, (u32)lbl_1_data_3D2B8__fzgx_offset_0, (u32)lbl_1_data_3D2C4__fzgx_offset_0, (u32)lbl_1_data_3D2CC__fzgx_offset_0, (u32)lbl_1_data_3D2D4__fzgx_offset_0, (u32)lbl_1_data_3D2DC__fzgx_offset_0, (u32)lbl_1_data_3D2E4__fzgx_offset_0, (u32)lbl_1_data_3D2F0__fzgx_offset_0, (u32)lbl_1_data_3D300__fzgx_offset_0, (u32)lbl_1_data_3D310__fzgx_offset_0, (u32)lbl_1_data_3D318__fzgx_offset_0, (u32)lbl_1_data_3D320__fzgx_offset_0, (u32)lbl_1_data_3D32C__fzgx_offset_0, (u32)lbl_1_data_3D338__fzgx_offset_0, (u32)lbl_1_data_3D348__fzgx_offset_0, (u32)lbl_1_data_3D350__fzgx_offset_0, (u32)lbl_1_data_3D35C__fzgx_offset_0, (u32)lbl_1_data_3D368__fzgx_offset_0, (u32)lbl_1_data_3D378__fzgx_offset_0, (u32)lbl_1_data_3D380__fzgx_offset_0, (u32)lbl_1_data_3D38C__fzgx_offset_0, (u32)lbl_1_data_3D398__fzgx_offset_0, (u32)lbl_1_data_3D3A8__fzgx_offset_0, (u32)lbl_1_data_3D3B0__fzgx_offset_0, (u32)lbl_1_data_3D3BC__fzgx_offset_0, (u32)lbl_1_data_3D3C4__fzgx_offset_0, (u32)lbl_1_data_3D3D0__fzgx_offset_0, (u32)lbl_1_data_3D3E0__fzgx_offset_0, (u32)lbl_1_data_3D3EC__fzgx_offset_0, (u32)lbl_1_data_3D3F8__fzgx_offset_0, (u32)lbl_1_data_3D400__fzgx_offset_0, (u32)lbl_1_data_3D414__fzgx_offset_0, (u32)lbl_1_data_3D424__fzgx_offset_0, (u32)lbl_1_data_3D434__fzgx_offset_0, (u32)lbl_1_data_3D440__fzgx_offset_0, (u32)lbl_1_data_3D44C__fzgx_offset_0, (u32)lbl_1_data_3D45C__fzgx_offset_0, (u32)lbl_1_data_3D464__fzgx_offset_0, (u32)lbl_1_data_3D470__fzgx_offset_0, (u32)lbl_1_data_3D478__fzgx_offset_0, (u32)lbl_1_data_3D480__fzgx_offset_0, (u32)lbl_1_data_3D488__fzgx_offset_0}; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_3D290_w[4] = {0xFF9FFFFF, 0xFF9FFFFF, 0xFF9FFFFF, 0xFF9FFFFF}; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2C4 = 632.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2C8 = -68.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2CC = 429.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2D0 = 460.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2D4 = 91.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2D8 = 160.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
static f32 fzgx_pool_native_lbl_1_data_3D290_unk_2DC = 160.0f; /* fzgx-allow: A1 measured pool bytes and bindings */
extern u8 fn_1_CB6D8__fzgx_offset_34C[];
extern u8 fn_1_CB6D8__fzgx_offset_364[];
extern u8 fn_1_CB6D8__fzgx_offset_37C[];
extern u8 fn_1_CB6D8__fzgx_offset_388[];
extern u8 fn_1_CB6D8__fzgx_offset_394[];
extern u8 fn_1_CB6D8__fzgx_offset_3A0[];
extern u8 fn_1_CB6D8__fzgx_offset_3AC[];
extern u8 fn_1_CB6D8__fzgx_offset_3B8[];
extern u8 fn_1_CB6D8__fzgx_offset_3C4[];
extern u8 fn_1_CB6D8__fzgx_offset_3D0[];
extern u8 fn_1_CB6D8__fzgx_offset_3E0[];
extern u8 fn_1_CB6D8__fzgx_offset_3F0[];
static char fzgx_pool_native_lbl_1_data_3D290_s_2E0[] = "%1d"; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_3D290_s_2E4[] = "%02d"; /* fzgx-allow: A1 measured pool bytes and bindings */
static char fzgx_pool_native_lbl_1_data_3D290_s_2EC[] = "%4d"; /* fzgx-allow: A1 measured pool bytes and bindings */
static u32 fzgx_pool_native_lbl_1_data_3D290_jt_2F0[12] = {(u32)fn_1_CB6D8__fzgx_offset_34C, (u32)fn_1_CB6D8__fzgx_offset_364, (u32)fn_1_CB6D8__fzgx_offset_3F0, (u32)fn_1_CB6D8__fzgx_offset_37C, (u32)fn_1_CB6D8__fzgx_offset_388, (u32)fn_1_CB6D8__fzgx_offset_3D0, (u32)fn_1_CB6D8__fzgx_offset_394, (u32)fn_1_CB6D8__fzgx_offset_3A0, (u32)fn_1_CB6D8__fzgx_offset_3E0, (u32)fn_1_CB6D8__fzgx_offset_3AC, (u32)fn_1_CB6D8__fzgx_offset_3B8, (u32)fn_1_CB6D8__fzgx_offset_3C4}; /* fzgx-allow: A1 measured pool bytes and bindings */

#define FLAGS fzgx_pool_native_lbl_1_data_3D290_w

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_CEB38(void) {
    FontDrawPacket packet;
    FontDrawPacket packet2;
    FontDrawPacket packet3;
    u32 out1;
    u32 color;
    u32 out2;
    ClearRecord *rec;
    s32 n;
    s32 m;
    s32 k;
    s32 j;
    s32 angle;
    u32 i;
    f32 t;
    f32 v;
    f32 c;
    f32 scale;

    if ((FLAGS[fn_1_5910()] >> 11) & 1) {
        f32 time = lbl_1_rodata_5D90;
        s32 slot = 0;
        f32 xs[2] = {149.0f, 480.0f};
        f32 ys[2] = {36.0f, 36.0f};
        f32 x0;
        f32 y0;
        s32 *p;
        p = lbl_1_bss_84.unk_0;
        if (p != NULL) {
            time = *p;
        }
        if (lbl_1_bss_84.unk_10 != 0) {
            slot = lbl_1_bss_84.unk_10;
        }
        if (time > lbl_1_rodata_5D04) {
            t = lbl_1_rodata_5CFC;
        } else {
            t = time / lbl_1_rodata_5D04;
        }
        packet = lbl_1_rodata_26F8;
        packet.image = 0xBA0E;
        x0 = xs[slot];
        y0 = ys[slot];
        packet.x = x0 + t * (lbl_1_rodata_5C3C - x0);
        packet.y = y0 + t * (lbl_1_rodata_5C40 - y0);
        packet.scale_y = packet.scale_x = (lbl_1_rodata_5FCC + lbl_1_rodata_5FD0 * t) / lbl_1_rodata_5FD4;
        packet.alpha = (t < lbl_1_rodata_5FD8) ? lbl_1_rodata_5FD8 : t;
        packet.flags = 10;
        fn_1_4F734(&packet);
    }

    if ((FLAGS[fn_1_5910()] >> 10) & 1) {
        packet = lbl_1_rodata_26F8;
        packet.image = 0xBA0B;
        packet.x = lbl_1_rodata_5C3C;
        packet.y = lbl_1_rodata_5C40;
        if ((FLAGS[fn_1_5910()] >> 3) & 1) {
            packet.y -= lbl_1_rodata_5FDC;
        }
        packet.flags = 10;
        fn_1_4F734(&packet);
    }

    if ((FLAGS[fn_1_5910()] >> 7) & 1) {
        packet = lbl_1_rodata_26F8;
        packet.image = 0xBA15;
        packet.x = lbl_1_rodata_5C3C;
        packet.y = lbl_1_rodata_5C40;
        packet.flags = 10;
        fn_1_4F734(&packet);
    }

    if ((FLAGS[fn_1_5910()] >> 6) & 1) {
        fn_1_49410();
        fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5C40);
        fn_1_495C8(9);
        fn_1_4AE0C("YOU LOSE!");
    }

    if ((FLAGS[fn_1_5910()] >> 5) & 1) {
        fn_1_49410();
        fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5C40);
        fn_1_495C8(9);
        fn_1_4AE0C("BOMB!");
    }

    if ((FLAGS[fn_1_5910()] >> 3) & 1) {
        n = 0;
        if (lbl_1_bss_84.unk_0 != NULL) {
            n = *lbl_1_bss_84.unk_0;
        }
        m = n % 60;
        packet = lbl_1_rodata_26F8;
        v = (m > 30) ? m - 30 : 0;
        packet.image = 0xBA0A;
        packet.x = lbl_1_rodata_5C3C;
        packet.y = lbl_1_rodata_5C40;
        packet.z -= lbl_1_rodata_5DC8;
        packet.flags = 10;
        scale = lbl_1_rodata_5CFC + v / lbl_1_rodata_5C48;
        packet.scale_y = packet.scale_x = scale;
        packet.alpha = lbl_1_rodata_5CFC - v / lbl_1_rodata_5CCC;
        fn_1_51678(&packet, packet.image, n / 60 * 60, 0, 60, 52);
        fn_1_4F734(&packet);
    }

    if ((FLAGS[fn_1_5910()] >> 9) & 1) {
        packet2 = lbl_1_rodata_26F8;
        n = 0;
        if (lbl_1_bss_84.unk_0 != NULL) {
            n = *lbl_1_bss_84.unk_0;
        }
        packet2.image = 0xBA09;
        if (n > lbl_1_rodata_5FE0) {
            t = (f32)(n - lbl_1_rodata_5FE0) / lbl_1_rodata_5D04;
            packet2.flags = 10;
            packet2.x = lbl_1_rodata_5C3C;
            packet2.y = lbl_1_rodata_5C40;
            packet2.scale_x = packet2.scale_y = lbl_1_rodata_5CFC + lbl_1_rodata_5E90 * t;
            packet2.alpha = lbl_1_rodata_5CFC - t;
            fn_1_4F734(&packet2);
        } else {
            k = n - lbl_1_rodata_5FE0;
            angle = 0x10000 - (k % 60) * 0x444;
            packet2.flags = 9;
            packet2.scale_x = lbl_1_rodata_5FE8;
            for (i = 0, j = 0; i < 16; i++, j += 0x800) {
                c = lbl_1_rodata_5CFC + lbl_8006D188(angle - j);
                packet2.x = lbl_1_rodata_5CF4 + lbl_1_rodata_5FEC * i;
                packet2.y = lbl_1_rodata_5C40;
                c = lbl_1_rodata_5CD8 * (lbl_1_rodata_5CB0 * c);
                packet2.u0 = packet2.scale_x * i;
                packet2.u1 = packet2.scale_x * (i + 1);
                packet2.color_add[0] = c;
                packet2.color_add[1] = c;
                packet2.color_add[2] = c;
                fn_1_4F734(&packet2);
            }
        }
    }

    if ((FLAGS[fn_1_5910()] >> 8) & 1) {
        packet3 = lbl_1_rodata_26F8;
        n = 0;
        if (lbl_1_bss_84.unk_0 != NULL) {
            n = *lbl_1_bss_84.unk_0;
        }
        packet3.image = 0xBA0C;
        if (n > lbl_1_rodata_5FE0) {
            t = (f32)(n - lbl_1_rodata_5FE0) / lbl_1_rodata_5D04;
            packet3.flags = 10;
            packet3.x = lbl_1_rodata_5C3C;
            packet3.y = lbl_1_rodata_5C40;
            packet3.scale_x = packet3.scale_y = lbl_1_rodata_5CFC + lbl_1_rodata_5E90 * t;
            packet3.alpha = lbl_1_rodata_5CFC - t;
            fn_1_4F734(&packet3);
        } else {
            packet3.flags = 10;
            packet3.x = lbl_1_rodata_5C3C;
            packet3.y = lbl_1_rodata_5C40;
            fn_1_4F734(&packet3);
        }
    }

    if ((FLAGS[fn_1_5910()] >> 1) & 1) {
        rec = fn_1_3F0D8(fn_1_8623C(), &out1, &out2);
        fn_1_49410();
        fn_1_494DC(5);
        fn_1_495B0(0x80000000);
        fn_1_495C8(2);
        fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5C3C);
        color = lbl_1_rodata_5FC8;
        fn_1_49514(&color);
        fn_1_49590(lbl_1_rodata_5CB0);
        fn_1_4955C(lbl_1_rodata_5F98, lbl_1_rodata_5F98);
        fn_1_4AE0C("CLEAR TIME");
        fn_1_49410();
        fn_1_494DC(5);
        fn_1_4955C(lbl_1_rodata_5F98, lbl_1_rodata_5F98);
        fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5C3C);
        fn_1_4AE0C("%2d'%02d\"%03d\n", rec->min, rec->sec, rec->ms);
    }

    if ((FLAGS[fn_1_5910()] >> 4) & 1) {
        packet = lbl_1_rodata_26F8;
        packet.image = 0xBA01;
        packet.x = lbl_1_rodata_5C3C;
        packet.y = lbl_1_rodata_5C40;
        packet.flags = 10;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_CEB38 */

/* fzgx:begin fn_1_CF5B0 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u32 fn_1_5910(void *);
extern void fn_1_3EF14(void *);
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_495A0(f32);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 lbl_1_rodata_5FF0;
extern u32 lbl_1_rodata_5FF4;
extern f32 lbl_1_rodata_26F8[22];
extern const f32 lbl_1_rodata_5C3C;
extern const f32 lbl_1_rodata_5CB0;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D68;
extern const f32 lbl_1_rodata_5F7C;
extern const f32 lbl_1_rodata_5FF8;
extern const f32 lbl_1_rodata_5FFC;
extern const f32 lbl_1_rodata_6000;
extern const f32 lbl_1_rodata_6004;
extern const f32 lbl_1_rodata_6008;
extern const f32 lbl_1_rodata_600C;

void fn_1_CF5B0(void *self) {
    FontDrawPacket loc_10;
    u32 spC;
    u32 sp8;
    s32 var_r30;
    s32 var_r31;
    s32 temp_r0;

    if (((((u32 *)&lbl_1_data_3D544)[fn_1_5910(self)]) >> 17) & 1) {
        fn_1_3EF14(&lbl_1_bss_3C30);
        if (lbl_1_bss_3C30.unk_0 & 0x40000) {
            var_r30 = 0;
            var_r31 = ((lbl_1_bss_3C30.unk_A4 + 0x3B) / 60 < 0) ? 0
                      : (((lbl_1_bss_3C30.unk_A4 + 0x3B) / 60 > 0x3E7) ? 0x3E7 : (lbl_1_bss_3C30.unk_A4 + 0x3B) / 60);
            if (var_r31 < 0xA) {
                var_r30 = 1;
            }
            fn_1_49410();
            if (var_r30 != 0) {
                spC = lbl_1_rodata_5FF0;
                fn_1_49514(&spC);
            }
            fn_1_494DC(0x10);
            fn_1_495C8(9);
            if (var_r31 > 0x63) {
                fn_1_4955C(lbl_1_rodata_5FF8, lbl_1_rodata_5CFC);
                fn_1_496FC(lbl_1_rodata_5FFC, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 / 100);
                fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, (var_r31 / 10) % 10);
                fn_1_496FC(lbl_1_rodata_6000, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 % 10);
            } else {
                fn_1_496FC(lbl_1_rodata_6004, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 / 10);
                fn_1_496FC(lbl_1_rodata_6008, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 % 10);
            }
            fn_1_49410();
            fn_1_494DC(0x11);
            fn_1_495C8(9);
            sp8 = lbl_1_rodata_5FF4;
            fn_1_49514(&sp8);
            fn_1_495A0(lbl_1_rodata_5CB0);
            if (var_r31 > 0x63) {
                fn_1_4955C(lbl_1_rodata_5FF8, lbl_1_rodata_5CFC);
                fn_1_496FC(lbl_1_rodata_5FFC, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 / 100);
                fn_1_496FC(lbl_1_rodata_5C3C, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, (var_r31 / 10) % 10);
                fn_1_496FC(lbl_1_rodata_6000, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 % 10);
            } else {
                fn_1_496FC(lbl_1_rodata_6004, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 / 10);
                fn_1_496FC(lbl_1_rodata_6008, lbl_1_rodata_5F7C);
                fn_1_4AE0C((const char *)&lbl_1_data_3D570, var_r31 % 10);
            }
            loc_10 = *(const FontDrawPacket *)lbl_1_rodata_26F8;
            loc_10.image = 0x940A;
            loc_10.x = lbl_1_rodata_600C;
            loc_10.y = lbl_1_rodata_5D68;
            fn_1_4F734(&loc_10);
        }
    }
}
/* fzgx:end fn_1_CF5B0 */

/* fzgx:begin fn_1_CFA0C noprologue */
#include "types.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u32 fn_1_5910(void);

u32 fn_1_CFA0C(void) {
    u32 bit = (((u32 *)&lbl_1_data_3D544)[fn_1_5910()] >> 16) & 1;
    return bit ? 0 : 0;
}
/* fzgx:end fn_1_CFA0C */

/* fzgx:begin fn_1_CFA4C noprologue */
#include "types.h"
#include "font.h"

extern f32 lbl_1_rodata_26F8[22];

struct fn_1_CFA4C_Copy88 { u32 a[22]; };

extern f32 lbl_1_rodata_6010;


extern int fn_1_4F734(FontDrawPacket *);


extern void fn_1_52070(u32);
extern void fn_1_520A0(void);
extern void fn_1_520CC(void);

void fn_1_CFA4C(u32 arg0, u32 arg1) {
    f32 v0;
    u32 v1;
    f32 v2;
    FontDrawPacket loc_8;
    /* frame */
    fn_1_520A0();
    fn_1_52070(640);
    loc_8 = *(FontDrawPacket *)&(*(u32 *)&lbl_1_rodata_26F8);
    v0 = (f32)(s32)(arg0 + 304);
    v1 = (0x10000 - 27620);
    loc_8.image = v1;
    v2 = (f32)(s32)(arg1 - 11);
    loc_8.x = v0;
    loc_8.y = v2;
    loc_8.z = lbl_1_rodata_6010;
    loc_8.flags = 7;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    fn_1_520CC();
}
/* fzgx:end fn_1_CFA4C */

/* fzgx:begin fn_1_CFB28 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u32 lbl_1_rodata_26F8;
extern const f32 lbl_1_rodata_6020;
extern const f64 lbl_1_rodata_6018;
extern const f32 lbl_1_rodata_6024;
extern const f32 lbl_1_rodata_5CFC;
extern u16 fn_1_48690(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

void fn_1_CFB28(f32 value) {
    s32 index;
    f64 cur;
    f64 d;
    FontDrawPacket packet;

    switch (lbl_1_data_2A7E0.unk_0) {
    case 0:
        break;
    case 1:
    case 17:
    case 18:
        index = 0;
        break;
    case 2:
    case 3:
        index = 1;
        break;
    case 4:
    case 5:
        index = 2;
        break;
    case 6:
    case 7:
        index = 3;
        break;
    case 8:
    case 9:
        index = 4;
        break;
    case 10:
        index = 5;
        break;
    case 11:
    case 12:
        index = 6;
        break;
    case 13:
        index = 7;
        break;
    case 14:
        index = 8;
        break;
    case 15:
        index = 9;
        break;
    case 16:
        index = 10;
        break;
    case 19:
        index = 11;
        break;
    }

    packet = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    packet.image = (0x10000 - 0x4500);
    fn_1_51678(&packet, packet.image, 0, (s16)(36 * index), (s16)fn_1_48690(packet.image), 36);

    d = (lbl_1_rodata_6020 - lbl_1_data_3D554) * lbl_1_rodata_6018;
    cur = lbl_1_data_3D554 + d;
    /* byte-offset stores, in this order: named members (y, alpha, z, flags, x) reschedule the
     * fadd ahead of the stores and cost a register swap */
    *(f32 *)((u8 *)&packet + 0x8) = lbl_1_rodata_6024;
    *(f32 *)((u8 *)&packet + 0x2C) = value;
    *(f32 *)((u8 *)&packet + 0xC) = lbl_1_rodata_5CFC;
    *(u32 *)((u8 *)&packet + 0x30) = 10;
    lbl_1_data_3D554 = cur;
    *(f32 *)((u8 *)&packet + 0x4) = lbl_1_data_3D554;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_CFB28 */

/* fzgx:begin fn_1_CFCA4 noprologue */
#include "types.h"

struct fn_1_CFCA4_lbl_1_rodata_5FD8 { f32 unk_0; };
struct fn_1_CFCA4_lbl_1_rodata_603C { f32 unk_0; };
struct fn_1_CFCA4_lbl_1_rodata_5C88 { f32 unk_0; };
struct fn_1_CFCA4_lbl_1_rodata_602C { u32 unk_0; };
struct fn_1_CFCA4_lbl_1_rodata_6030 { u32 unk_0; };
struct fn_1_CFCA4_lbl_1_rodata_6050 { f32 unk_0; };
struct fn_1_CFCA4_lbl_1_rodata_5CD4 { f32 unk_0; };
struct fn_1_CFCA4_lbl_1_rodata_6038 { u32 unk_0; };
struct fn_1_CFCA4_Copy88 { u32 a[22]; };
extern f32 lbl_1_rodata_5D90;
extern f32 lbl_1_rodata_5DCC;
extern f32 lbl_1_rodata_6040;
extern f32 lbl_1_rodata_6044;
extern f32 lbl_1_rodata_6048;
extern f32 lbl_1_rodata_604C;
extern f32 lbl_1_rodata_6054;
extern f32 lbl_1_rodata_5CFC;
extern struct fn_1_CFCA4_lbl_1_rodata_5C88 lbl_1_rodata_5C88;
extern struct fn_1_CFCA4_lbl_1_rodata_5CD4 lbl_1_rodata_5CD4;
extern struct fn_1_CFCA4_lbl_1_rodata_5FD8 lbl_1_rodata_5FD8;
extern struct fn_1_CFCA4_lbl_1_rodata_602C lbl_1_rodata_602C;
extern struct fn_1_CFCA4_lbl_1_rodata_6030 lbl_1_rodata_6030;
extern struct fn_1_CFCA4_lbl_1_rodata_6038 lbl_1_rodata_6038;
extern struct fn_1_CFCA4_lbl_1_rodata_603C lbl_1_rodata_603C;
extern struct fn_1_CFCA4_lbl_1_rodata_6050 lbl_1_rodata_6050;
extern u32 fn_1_52968(u32, u32, const char *, f32, ...);
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_6034;
extern u32 lbl_801A66B4;
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_49748(f32);
extern void fn_1_51914(const struct fn_1_CFCA4_Copy88 *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_527B4(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *, ...);

void fn_1_CFCA4(const char *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 v0;
    f32 v1;
    f32 v9;
    s32 v4;
    s32 v5;
    struct fn_1_CFCA4_Copy88 packet;
    struct fn_1_CFCA4_lbl_1_rodata_602C color0;
    struct fn_1_CFCA4_lbl_1_rodata_6030 color1;
    struct fn_1_CFCA4_lbl_1_rodata_602C color2;
    struct fn_1_CFCA4_lbl_1_rodata_6038 color3;
    u32 loc_14;
    u32 loc_10;
    u32 loc_C;
    u32 loc_8;
    v0 = lbl_1_rodata_5FD8.unk_0 * arg3;
    color0 = lbl_1_rodata_602C;
    v1 = lbl_1_rodata_603C.unk_0 * arg3;
    color1 = lbl_1_rodata_6030;
    v9 = lbl_1_rodata_5C88.unk_0 * arg3;
    color2 = *(struct fn_1_CFCA4_lbl_1_rodata_602C *)&lbl_1_rodata_6034;
    fn_1_49410();
    fn_1_495C8(1);
    fn_1_495B0(0x10000);
    fn_1_4955C(lbl_1_rodata_6040, lbl_1_rodata_6040);
    if ((s32)lbl_801A66B4 == 5) {
        fn_1_4966C(lbl_1_rodata_6044, lbl_1_rodata_5D90);
    } else {
        fn_1_495B0(0x80000000);
    }
    loc_14 = color0.unk_0;
    fn_1_49514(&loc_14);
    fn_1_49748(lbl_1_rodata_6048);
    fn_1_495A0(v0);
    v4 = (s32)arg1;
    v5 = (s32)arg2;
    fn_1_52968(v4, v5, arg0, lbl_1_rodata_5DCC);
    loc_10 = color1.unk_0;
    fn_1_49514(&loc_10);
    fn_1_49748(lbl_1_rodata_604C);
    fn_1_495A0(v1);
    fn_1_52968(v4, v5, arg0, lbl_1_rodata_6050.unk_0);
    loc_C = color2.unk_0;
    fn_1_49514(&loc_C);
    fn_1_49748(lbl_1_rodata_6054);
    fn_1_495A0(v9);
    fn_1_52968(v4, v5, arg0, lbl_1_rodata_5CD4.unk_0);
    color3 = lbl_1_rodata_6038;
    packet = *(struct fn_1_CFCA4_Copy88 *)lbl_1_rodata_26F8;
    packet.a[0] = 5;
    *(s16 *)&packet.a[10] = -0x4000;
    *(f32 *)&packet.a[2] = lbl_1_rodata_5CFC;
    fn_1_51914(&packet);
    loc_8 = color3.unk_0;
    fn_1_49514(&loc_8);
    fn_1_49748(lbl_1_rodata_5D90);
    fn_1_495A0(arg3);
    fn_1_495B0(0x80000000);
    fn_1_496FC(arg1, arg2);
    fn_1_49738(fn_1_527B4);
    fn_1_4954C(lbl_1_rodata_5CFC);
    fn_1_4AE0C(arg0);
}
/* fzgx:end fn_1_CFCA4 */

/* fzgx:begin fn_1_CFF94 noprologue */
#include "types.h"
#include "font.h"

struct fn_1_CFF94_Copy88 { u32 a[22]; };

extern const f32 lbl_1_rodata_5DCC;
extern const f32 lbl_1_rodata_6050;
extern const f64 lbl_1_rodata_5C00;
extern int fn_1_4F734(FontDrawPacket *);
extern u32 lbl_1_bss_3C30;
extern char lbl_1_data_3D630[];
extern f32 lbl_1_rodata_26F8[22];
extern u32 lbl_801A66B4;
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

#pragma opt_strength_reduction off
#pragma opt_common_subs off
void fn_1_CFF94(u32 arg0, s16 arg1, f32 arg2) {
    s32 v6;
    s16 v6s;
    s32 v7;
    s32 v8;
    FontDrawPacket loc_8;

    arg0 = arg0;
    if (arg1 == 0) {
        return;
    }
    v6 = 28;
    if (*(u8 *)((u8 *)&lbl_1_bss_3C30 + 5) != 2) {
        v6 = 60;
    }
    if ((s32)lbl_801A66B4 == 5) {
        if (arg1 >= 10) {
            v7 = 50;
        } else {
            v7 = 0;
        }
    } else {
        if (arg1 >= 10) {
            v7 = -25;
        } else {
            v7 = -29;
        }
    }
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = 0xBB01;
    ((f32 *)&loc_8)[0xB] = arg2;
    ((u32 *)&loc_8)[0xC] = 10;
    loc_8.x = (f32)(s32)(529 - (s16)v7);
    v6s = (s16)v6;
    loc_8.y = (f32)(s32)(((360) + (v6s)));
    loc_8.z = (3.0f);
    fn_1_4F734((FontDrawPacket *)&loc_8);
    if ((s32)lbl_801A66B4 == 5) {
        if (arg1 >= 10) {
            v8 = 27;
        } else {
            v8 = 0;
        }
    } else {
        if (arg1 >= 10) {
            v8 = 133;
        } else {
            v8 = 106;
        }
    }
    fn_1_49410();
    fn_1_494DC(0x28);
    fn_1_496FC((f32)(s32)(590 - (s16)v8), (f32)(s32)(((355) + (v6s))));
    fn_1_495C8(9);
    fn_1_4954C((4.0f));
    fn_1_495A0(arg2);
    fn_1_4AE0C(lbl_1_data_3D630, arg1);
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset
/* fzgx:end fn_1_CFF94 */

/* fzgx:begin fn_1_D01B0 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/enemy_ctrl.h"

extern u32 lbl_1_rodata_26F8[22];
extern u32 lbl_1_rodata_6058;
extern const f32 lbl_1_rodata_5CD4;
extern const f32 lbl_1_rodata_5D3C;
extern const f32 lbl_1_rodata_5DCC;
extern const f32 lbl_1_rodata_6004;
extern const f32 lbl_1_rodata_6050;
extern const f32 lbl_1_rodata_605C;
extern const f32 lbl_1_rodata_6060;
extern const f32 lbl_1_rodata_6064;
extern const f32 lbl_1_rodata_6068;
extern s32 fn_1_156218(u32, void *, void *, void *);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_1_51564(s16, s16, s16, s16, s16, s16);
extern u32 fn_1_5158C(FontDrawPacket *, u32, u32, u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495A0(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_495FC(void);
extern void fn_1_4AE0C(const char *, ...);

void fn_1_D01B0(f32 farg0) {
    FontDrawPacket loc_B8;
    u32 sp80[14];
    u32 sp48[14];
    u32 sp10[14];
    u32 sp8[2];
    u32 flags;
    s16 temp_r30;
    s16 temp_r30_2;

    fn_1_156218((u32) lbl_1_bss_3C30.unk_6, (void *) sp80, (void *) sp48, (void *) sp10);
    flags = sp80[0];
    loc_B8 = *(const FontDrawPacket *) lbl_1_rodata_26F8;
    loc_B8.image = 0xBB03;
    temp_r30 = (s16) (fn_1_486C4(0xBB03U) / 3);
    fn_1_51564(0, 0, fn_1_48690(loc_B8.image), temp_r30, 1, 3);
    fn_1_5158C(&loc_B8, loc_B8.image, 0U, 0U);
    loc_B8.alpha = farg0;
    loc_B8.x = lbl_1_rodata_6004;
    loc_B8.y = lbl_1_rodata_605C;
    loc_B8.z = lbl_1_rodata_5CD4;
    fn_1_4F734(&loc_B8);
    loc_B8 = *(const FontDrawPacket *) lbl_1_rodata_26F8;
    loc_B8.image = 0xBB03;
    temp_r30_2 = (s16) (fn_1_486C4(0xBB03U) / 3);
    fn_1_51564(0, 0, fn_1_48690(loc_B8.image), temp_r30_2, 1, 3);
    fn_1_5158C(&loc_B8, loc_B8.image, 0U, 2U);
    loc_B8.alpha = farg0;
    loc_B8.x = lbl_1_rodata_6060;
    loc_B8.y = lbl_1_rodata_605C;
    loc_B8.z = lbl_1_rodata_6050;
    fn_1_4F734(&loc_B8);
    fn_1_49410();
    fn_1_494DC(0x29);
    fn_1_495B0(0x80000000U);
    fn_1_4955C(lbl_1_rodata_5D3C, lbl_1_rodata_5D3C);
    fn_1_496FC(lbl_1_rodata_6064, lbl_1_rodata_6068);
    fn_1_4954C(lbl_1_rodata_5DCC);
    fn_1_495A0(farg0);
    sp8[0] = lbl_1_rodata_6058;
    fn_1_49514(sp8);
    fn_1_495FC();
    fn_1_4AE0C((const char *) lbl_1_data_3D634, (u8) (flags >> 0x14U), (u8) (flags >> 0xCU), flags & 0xFFF);
}
/* fzgx:end fn_1_D01B0 */

/* fzgx:begin fn_1_D0428 */
/* the race-setup block as fn_1_3EF14 copies it to the stack (0x14B8 bytes; globals.h's 0x14BC-byte
 * Obj_1_bss_3C30 moves the frame); fields as globals.h names them */
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[0x145D];
    u32 unk_1464;
    u8 pad_1468[0x50];
} fn_1_D0428_Setup;

/* fn_1_128E8C's output: a time as minutes, seconds, milliseconds */
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u16 unk_2;
    u8 pad_4[0x14];
    u16 unk_18;
} fn_1_D0428_Record;

extern s32 fn_1_3F7D0(void);
extern s32 fn_1_101C0(void);
extern void fn_1_3EF14(void *);
extern u32 fn_1_3F114(void);
extern void fn_1_12EF80(u8, s16 *, s16 *);
extern void fn_1_128E8C(u8, fn_1_D0428_Record *);
extern void fn_1_52070(int);
extern void fn_1_52088(void);
/* retail passes these extra arguments; the callees' own units declare fewer */
extern void fn_1_CFB28(s16, f32);
/* same registers as fn_1_CFCA4(const char *, f32, f32, f32); this order evaluates the floats first, as retail */
extern void fn_1_CFCA4(f32, f32, const char *, f32);
extern void fn_1_CFF94(u32, u8, f32);
extern void fn_1_D01B0(u32, s16, f32);
extern s16 fn_1_7B054(void);
extern u32 lbl_801A66B4;
extern u8 lbl_1_data_2BD54[0xA68];
extern const f32 lbl_1_rodata_5C38;
extern const f32 lbl_1_rodata_5CCC;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5D90;
extern const f64 lbl_1_rodata_6018;
extern const f32 lbl_1_rodata_6020;
extern const f32 lbl_1_rodata_6028;

#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))

static inline s32 in_range(s32 x, s32 lo, s32 hi) {
    if (x > hi) {
        return 0;
    }
    return x >= lo;
}

void fn_1_D0428(void) {
    s32 now;
    s32 start;
    u32 value;
    u32 flag;
    s32 best;
    s32 cur;
    u32 time;
    f32 alpha;
    f64 d;
    s32 course;
    s16 a;
    s16 b;
    fn_1_D0428_Record rec;
    fn_1_D0428_Setup setup;

    now = fn_1_3F7D0();
    start = fn_1_101C0();
    if (!in_range(now, 20, start)) {
        return;
    }
    fn_1_3EF14(&setup);
    value = fn_1_3F114();
    fn_1_12EF80(setup.unk_6, &a, &b);
    flag = 0;
    fn_1_128E8C((u8)b, &rec);
    time = setup.unk_1464;
    best = rec.unk_1 * 1000 + rec.unk_0 * 60000 + rec.unk_2;
    cur = ((time >> 12) & 0xFF) * 1000 + ((time >> 20) & 0xFF) * 60000 + (time & 0xFFF);
    if (rec.unk_18 == 0 || best == 0x7FFFF) {
        flag = 1;
    }
    if (best > cur) {
        flag = 1;
    }
    if (in_range(now, start - 120, start)) {
        alpha = (f32)(start - now) / lbl_1_rodata_5C38;
    } else if (in_range(now, 10, 40)) {
        alpha = lbl_1_rodata_5CFC - (f32)(40 - now) / lbl_1_rodata_5CCC;
    } else if (now < 10) {
        alpha = lbl_1_rodata_5D90;
    } else {
        alpha = lbl_1_rodata_5CFC;
    }
    fn_1_52070(0x60);
    fn_1_CFB28(now, alpha);
    /* the f64 step keeps retail's separate fmul and fadd */
    d = (lbl_1_rodata_6020 - lbl_1_data_3D558.unk_0) * lbl_1_rodata_6018;
    lbl_1_data_3D558.unk_0 = lbl_1_data_3D558.unk_0 + d;
    course = CLAMP(fn_1_7B054(), 0, 110); /* 111 courses x 6 languages of name pointers */
    fn_1_CFCA4(lbl_1_data_3D558.unk_0, lbl_1_rodata_6028,
               ((const char **)(lbl_1_data_2BD54 + course * 0x18))[lbl_801A66B4], alpha);
    fn_1_52070(0x220);
    fn_1_CFF94(flag, (u8)value, alpha);
    if (setup.unk_5 == 2) {
        fn_1_D01B0(flag, b, alpha);
    }
    fn_1_52088();
}
/* fzgx:end fn_1_D0428 */

/* fzgx:begin fn_1_D0728 */
#pragma opt_propagation off
void fn_1_D0728(u32 arg0, u32 arg1) {
    u32 *data;
    u32 *state;
    u32 value;

    value = 0xfffb8004;
    data = (u32 *)&lbl_1_data_3D544;
    state = (u32 *)&lbl_1_bss_7ACA0;

    data[0] = value;
    state[0] = 0;
    state[1] = 0;
    ((u8 *)state)[0x8] = 0;
    ((u8 *)state)[0x9] = 0;
    data[1] = value;
    state[3] = 0;
    state[4] = 0;
    ((u8 *)state)[0x14] = 0;
    ((u8 *)state)[0x15] = 0;
    data[2] = value;
    state[6] = 0;
    state[7] = 0;
    ((u8 *)state)[0x20] = 0;
    ((u8 *)state)[0x21] = 0;
    data[3] = value;
    state[9] = 0;
    state[10] = 0;
    ((u8 *)state)[0x2c] = 0;
    ((u8 *)state)[0x2d] = 0;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_D0728 */

/* fzgx:begin fn_1_D0790 */
void fn_1_D0790(void) {
    u32 *p = (u32 *)&lbl_1_data_3D544;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
}
/* fzgx:end fn_1_D0790 */

/* fzgx:begin fn_1_D07AC */
// Stores a value in the indexed enemy-control slot.
void fn_1_D07AC(u32 index, u32 value) {
    u32* slots = &lbl_1_bss_7ACA0.unk_0;
    slots[(index & 0xff) * 3] = value;
}
/* fzgx:end fn_1_D07AC */

/* fzgx:begin fn_1_D07C4 noprologue */
#include "types.h"

struct fn_1_D07C4_lbl_1_bss_7ACA0_0_E12 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x4];
};
struct fn_1_D07C4_lbl_1_bss_7ACA0 {
    struct fn_1_D07C4_lbl_1_bss_7ACA0_0_E12 unk_0[1];
};

extern struct fn_1_D07C4_lbl_1_bss_7ACA0 lbl_1_bss_7ACA0;

void fn_1_D07C4(u32 arg0, u32 arg1) {
    lbl_1_bss_7ACA0.unk_0[(arg0 & 0xFF)].unk_4 = arg1;
}
/* fzgx:end fn_1_D07C4 */

/* fzgx:begin fn_1_D07E0 noprologue */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;
typedef double f64;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


typedef struct {
u32 unk_0;
u8 unk_4;
u8 unk_5;
u8 unk_6;
u8 unk_7;
u8 unk_8;
u8 unk_9;
u8 pad_A[0x3];
u8 unk_D;
u8 unk_E;
u8 unk_F;
u8 pad_10[0x1C];
u32 unk_2C;
u8 pad_30[0x74];
u16 unk_A4;
u8 unk_A6;
u8 unk_A7;
u8 pad_A8[0x2C];
u32 unk_D4;
u16 unk_D8;
u16 unk_DA;
u8 unk_DC;
u8 unk_DD;
u8 unk_DE;
u8 unk_DF;
u8 unk_E0;
u8 unk_E1;
u8 unk_E2;
u8 pad_E3[0x4];
u8 unk_E7;
u8 pad_E8[0x4];
u16 unk_EC;
u8 pad_EE[0xA];
u32 unk_F8;
u8 pad_FC[0x10];
u32 unk_10C;
u8 pad_110[0x10];
u16 unk_120;
u16 unk_122;
u16 unk_124;
u16 unk_126;
u16 unk_128;
u8 pad_12A[0x2];
u32 unk_12C;
u8 pad_130[0x1C];
u32 unk_14C;
u8 pad_150[0x4];
u8 unk_154;
u8 unk_155;
u8 unk_156;
u8 unk_157;
u8 pad_158[0x1A];
u16 unk_172;
u8 pad_174[0x4];
u16 unk_178;
u8 pad_17A[0x1];
u8 unk_17B;
u8 unk_17C;
u8 pad_17D[0x7A];
u8 unk_1F7;
u8 pad_1F8[0x20];
u16 unk_218;
u8 pad_21A[0x2];
u8 unk_21C;
u8 pad_21D[0x7A];
u8 unk_297;
u8 pad_298[0x20];
u16 unk_2B8;
u8 pad_2BA[0x2];
u8 unk_2BC;
u8 pad_2BD[0x7A];
u8 unk_337;
u8 pad_338[0x20];
u16 unk_358;
u8 pad_35A[0x2];
u8 unk_35C;
u8 pad_35D[0x7A];
u8 unk_3D7;
u8 pad_3D8[0x20];
u16 unk_3F8;
u8 pad_3FA[0x2];
u8 unk_3FC;
u8 pad_3FD[0x7A];
u8 unk_477;
u8 pad_478[0xF1C];
u8 unk_1394;
u8 pad_1395[0x1F];
u32 unk_13B4;
u8 pad_13B8[0x1C];
u32 unk_13D4;
u8 pad_13D8[0x1C];
u8 unk_13F4;
u8 unk_13F5;
u8 unk_13F6;
u8 pad_13F7[0x1];
u16 unk_13F8;
u16 unk_13FA;
u16 unk_13FC;
u16 unk_13FE;
u16 unk_1400;
u8 unk_1402;
u8 pad_1403[0x2];
u8 unk_1405;
u8 pad_1406[0x5E];
u32 unk_1464;
u8 pad_1468[0x4];
u8 unk_146C;
u8 unk_146D;
u16 unk_146E;
u8 unk_1470;
u8 pad_1471[0x3];
u32 unk_1474;
u16 unk_1478;
u16 unk_147A;
u16 unk_147C;
u16 unk_147E;
u32 unk_1480;
u32 unk_1484;
u32 unk_1488;
u32 unk_148C;
u32 unk_1490;
u32 unk_1494;
u32 unk_1498;
u32 unk_149C;
u32 unk_14A0;
u32 unk_14A4;
u32 unk_14A8;
u8 pad_14AC[0x10];
} Obj_1_bss_3C30;
extern Obj_1_bss_3C30 lbl_1_bss_3C30;


typedef struct {
f32 x;
f32 y;
f32 z;
} Fn183D28Vec3;


typedef struct {
f32 value0;
f32 value1;
f32 value2;
} Sig_fn_8006F78C_Fn8006F78CData;


extern const f32 lbl_1_rodata_5CB0;


extern const f32 lbl_1_rodata_5DC8;
extern const f32 lbl_1_rodata_5E10;
extern const f32 lbl_1_rodata_5F50;
extern const f32 lbl_1_rodata_606C;
extern const f32 lbl_1_rodata_5CFC;
extern const f32 lbl_1_rodata_5DCC;


extern const f64 lbl_1_rodata_6070;
extern f32 lbl_8006D21C(u32);


extern int fn_1_4F734(FontDrawPacket *);
struct fn_1_D07E0_lbl_1_bss_7ACD0 { s32 unk_0; u32 unk_4; };
extern struct fn_1_D07E0_lbl_1_bss_7ACD0 lbl_1_bss_7ACD0;
extern FontDrawPacket lbl_1_rodata_26F8;
extern u32 fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern u32 lbl_801A66A0;
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_8006F78C(Fn183D28Vec3 *, Sig_fn_8006F78C_Fn8006F78CData *, f32);
extern Fn183D28Vec3 *fn_1_EB0D8(u32);
extern u32 fn_1_EB0B0(void);
void fn_1_D07E0(f32 arg0, f32 arg1, f32 arg2) {
struct { f32 *value; } p_lbl_1_rodata_26F8;
Obj_1_bss_3C30 *p_lbl_1_bss_3C30;
u8 v0;
s32 v1;
s32 v2;
u32 v3;
u32 v4;
s32 v7;
u32 v6;
u32 v5;
Fn183D28Vec3 *v8;
u32 v9;
f32 v10;
u32 v11;
u32 v12;
f32 v13;
s32 v14;
s32 v15;
f32 v16;
u32 v17;
u32 v18;
u32 v19;
int v20;
FontDrawPacket loc_20;
Sig_fn_8006F78C_Fn8006F78CData loc_14;
Sig_fn_8006F78C_Fn8006F78CData loc_8;
Fn183D28Vec3 *point;
f32 phase;
f32 t0;
int t5;
t0 = lbl_8006D21C((s32)(f32)(lbl_1_rodata_606C * (f32)(lbl_1_rodata_5CB0 * arg0)));
loc_20 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
loc_20.image = (0x10000 - 27611);
fn_1_51564(0, 0, 16, 14, 2, 5);
p_lbl_1_bss_3C30 = &lbl_1_bss_3C30;
v0 = p_lbl_1_bss_3C30->unk_1405;
v5 = 0;
for (v1 = 0; v1 < 5; v1++) {
if (v0 & (1 << v1)) v5++;
}
if ((s32)v5 == 0) {
lbl_1_bss_7ACD0.unk_0 = 0;
} else {
if (lbl_1_bss_7ACD0.unk_0 < 60) {
lbl_1_bss_7ACD0.unk_0++;
}
}
v7 = 0;
v8 = (Fn183D28Vec3 *)&lbl_1_bss_3C30;
do {
if ((p_lbl_1_bss_3C30->unk_1405 & (1 << v7)) != 0) {
loc_20 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v9 = lbl_801A66A0 >> 5;
v12 = v7 + (v5 - v9 % v5);
loc_20.image = 0x9425;
v16 = lbl_1_rodata_5CFC - (f32)lbl_1_bss_7ACD0.unk_0 / lbl_1_rodata_5E10;
loc_20.color_add[0] = 255.0f * v16;
loc_20.color_add[1] = 255.0f * v16;
loc_20.color_add[2] = 255.0f * v16;
loc_20.color_add[3] = 0;
loc_20.z = (lbl_1_rodata_26F8.z - lbl_1_rodata_5F50) + (f32)(lbl_1_rodata_5DC8 * (f32)(s32)(v12 % v5));
fn_8006F78C((Fn183D28Vec3 *)((u8 *)&lbl_1_bss_3C30 + v7 * 12 + 5128), &loc_14, t0);
v16 = (f32)(arg1 + loc_14.value0);
loc_20.flags = 10;
loc_20.x = v16;
loc_20.y = (f32)(arg2 + loc_14.value1);
if (v7 == 4) {
fn_1_5158C(&loc_20, loc_20.image, 1, 4);
} else {
v17 = ((u32)v7 >> 31);
fn_1_5158C(&loc_20, loc_20.image, (s16)(v7 % 2), (s16)(v7 / 2));
}
t5 = fn_1_4F734(&loc_20);
}
v7++;
v8 = (Fn183D28Vec3 *)v8 + 1;
} while ((s32)v7 < 5);
v18 = 0;
v19 = 0;
v20 = t5;
while (v18 < fn_1_EB0B0()) {
point = fn_1_EB0D8(v18);
if (point) {
phase = (f32)((lbl_801A66A0 - ((v18 * 60U) >> 1)) % ((fn_1_EB0B0() * 60U) >> 1));
phase /= (f32)((fn_1_EB0B0() * 60U) >> 1);
phase = phase * lbl_1_rodata_6070;
fn_1_51564(0, 0, 8, 14, 4, 5);
loc_20 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
loc_20.image = (0x10000 - 27611);
fn_1_5158C(&loc_20, loc_20.image, 2, 2);
loc_20.z = lbl_1_rodata_26F8.z - phase;
fn_8006F78C(point, &loc_8, t0);
loc_20.x = (arg1 + loc_8.value0) - lbl_1_rodata_5DCC;
loc_20.y = arg2 + loc_8.value1;
loc_20.flags = 10;
fn_1_4F734(&loc_20);
loc_20 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
v11 = v18 + 3;
loc_20.image = (0x10000 - 27611);
v14 = v11 & 3;
v15 = (v11 >> 2) + 2;
fn_1_5158C(&loc_20, loc_20.image, v14, (s16)v15);
loc_20.z = lbl_1_rodata_26F8.z - phase;
fn_8006F78C(point, &loc_8, t0);
loc_20.x = lbl_1_rodata_5DCC + (arg1 + loc_8.value0);
loc_20.y = arg2 + loc_8.value1;
loc_20.flags = 10;
fn_1_4F734(&loc_20);
}
v19 += 60;
v18++;
}
}
/* fzgx:end fn_1_D07E0 */

/* fzgx:begin fn_1_D0D68 */
void fn_1_D0D68(void) {
    fn_1_C8DC0();
}
/* fzgx:end fn_1_D0D68 */

/* fzgx:begin fn_1_D0D88 */
u32 fn_1_D0D88(void) {
    return lbl_1_data_3D648.unk_0;
}
/* fzgx:end fn_1_D0D88 */

/* fzgx:begin fn_1_D0D98 */
u16* fn_1_D0D98(void) {
    return &lbl_1_data_3D648.unk_4;
}
/* fzgx:end fn_1_D0D98 */

/* fzgx:begin fn_1_D0DA8 */
// Return the address of the object's 16-bit field at offset 0x6.
u8* fn_1_D0DA8(void) {
    return (u8*)&lbl_1_data_3D648.unk_6;
}
/* fzgx:end fn_1_D0DA8 */

/* fzgx:begin fn_1_D0DB8 */
// Returns the byte address of the object's field at offset 0x8.
u8* fn_1_D0DB8(void) {
    return (u8*)&lbl_1_data_3D648.unk_8;
}
/* fzgx:end fn_1_D0DB8 */

/* fzgx:begin fn_1_D0DC8 */
u8* fn_1_D0DC8(void) {
    return (u8*)&lbl_1_data_3D648 + 0xc;
}
/* fzgx:end fn_1_D0DC8 */

/* fzgx:begin fn_1_D0DD8 */
// Return the address of the enemy-control value at offset 0x10.
u8* fn_1_D0DD8(void) {
    return (u8*)&lbl_1_data_3D648.unk_10;
}
/* fzgx:end fn_1_D0DD8 */

/* fzgx:begin fn_1_D0DE8 */
// Return the address of the object's field at offset 0x12.
u8* fn_1_D0DE8(void) {
    return (u8*)&lbl_1_data_3D648.unk_12;
}
/* fzgx:end fn_1_D0DE8 */

/* fzgx:begin fn_1_D0DF8 */
// Return the enemy-control field at offset 0x14.
u16* fn_1_D0DF8(void) {
    return &lbl_1_data_3D648.unk_14;
}
/* fzgx:end fn_1_D0DF8 */

/* fzgx:begin fn_1_D0E08 */
// Return the address of the enemy-control field at offset 0x16.
u8* fn_1_D0E08(void) {
    return (u8*)&lbl_1_data_3D648.unk_16;
}
/* fzgx:end fn_1_D0E08 */

/* fzgx:begin fn_1_D0E18 */
// Return the address of the enemy-control field at offset 0x18.
u16* fn_1_D0E18(void) {
    return &lbl_1_data_3D648.unk_18;
}
/* fzgx:end fn_1_D0E18 */

/* fzgx:begin fn_1_D0E28 */
// Return the enemy-control data block.
Obj_1_data_3D648* fn_1_D0E28(void) {
    return &lbl_1_data_3D648;
}
/* fzgx:end fn_1_D0E28 */

/* fzgx:begin fn_1_D0E34 */
// Returns the status-byte array beginning at the shared enemy data block.
u8* fn_1_D0E34(void) {
    return &lbl_1_data_3D648.unk_20;
}
/* fzgx:end fn_1_D0E34 */

/* fzgx:begin fn_1_D0E44 */
// Return the address of the enemy controller's status byte.
u8* fn_1_D0E44(void) {
    return &lbl_1_data_3D648.unk_21;
}
/* fzgx:end fn_1_D0E44 */

/* fzgx:begin fn_1_D0E54 */
// Returns the address of this object's byte flag.
u8* fn_1_D0E54(void) {
    return &lbl_1_data_3D648.unk_22;
}
/* fzgx:end fn_1_D0E54 */

/* fzgx:begin fn_1_D0E64 */
// Returns the address of the enemy-control byte at offset 0x23.
u8* fn_1_D0E64(void) {
    return &lbl_1_data_3D648.unk_23;
}
/* fzgx:end fn_1_D0E64 */

/* fzgx:begin fn_1_D0E74 */
#include "types.h"

struct Sig_fn_8003432C_fn_8003432C_Arg2 {
    u32 unk_0;
};

struct Sig_GXPeekZ_GXPeekZ_Arg2 {
    u32 unk_0;
};

struct fn_1_D0E74_lbl_1_data_3D648 {
    u8 pad_0[0x4];
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u8 pad_A[0x16];
    u8 unk_20;
    u8 unk_21;
    u8 unk_22;
    u8 unk_23;
};
struct fn_1_D0E74_lbl_1_rodata_6080 {
    f64 unk_0;
};
extern f32 lbl_1_rodata_6078;


extern struct fn_1_D0E74_lbl_1_rodata_6080 lbl_1_rodata_6080;
extern void GXPokeAlphaRead(u32);
extern u32 fn_8003432C(u32, u32, struct Sig_fn_8003432C_fn_8003432C_Arg2 *);
extern u32 GXPeekZ(u32, u32, struct Sig_GXPeekZ_GXPeekZ_Arg2 *);
extern u16 fn_1_A5DB0(void);


void fn_1_D0E74(void) {
    GXPokeAlphaRead((u32)(2U));
    fn_8003432C((u32)((u32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_4), (u32)((u32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_6), (struct Sig_fn_8003432C_fn_8003432C_Arg2 *)((struct Sig_fn_8003432C_fn_8003432C_Arg2 *) ((u8 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28))));
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_20 = (u8) ((u32) (*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)) >> 0x18U);
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_21 = (u8) ((u32) (*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)) >> 0x10U);
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_22 = (u8) ((u32) (*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28)) >> 8U);
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_23 = (u8) (*(u32 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 28));
    GXPeekZ((u32)((u32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_4), (u32)((u32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_6), (struct Sig_GXPeekZ_GXPeekZ_Arg2 *)((struct Sig_GXPeekZ_GXPeekZ_Arg2 *) ((u8 *)((u8 *)(&(*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648)) + 12))));
    (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_8 = (u16) (s32) (((*(f32 *)((u8 *)(&lbl_1_rodata_6078) + 0)) * (f32) (*(struct fn_1_D0E74_lbl_1_data_3D648 *)&lbl_1_data_3D648).unk_6) / (f32) fn_1_A5DB0());
}
/* fzgx:end fn_1_D0E74 */

/* fzgx:begin fn_1_D0F60 */
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} GXColor;

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(volatile f64 *d, volatile f32 *f) {  /* fzgx-allow: S2 pool primer sinks */
    *f = 480.0f;
    *d = 4503599627370496.0;
}
#pragma section code_type ".text"

extern void fn_1_A9868(void);
extern u16 fn_1_A5DB0(void);
extern void fn_1_A9FFC(s16 x, s16 y, s16 w, s16 h, GXColor color);
extern void fn_1_A9B70(s16 x, s16 y, s16 w, s16 h, GXColor color);
extern void fn_1_AA538(void);
extern void fn_8003432C(u16 x, u16 y, u32 *color);

/* Debug EFB magnifier: reads the (cols+1) x (rows+1) framebuffer pixels around (unk_4, unk_6)
 * with GXPeekARGB (fn_8003432C) and draws each as a cell_w x cell_h square at (x0, y0), outlining
 * the centre cell and the sampled area in white. Off-screen pixels are skipped. */
void fn_1_D0F60(void) {
    s32 cell_w;
    s32 cell_h;
    s32 i;
    s32 j;
    s32 x0;
    s32 y0;
    s32 cols;
    s32 rows;
    s32 hw;
    s32 hh;
    s32 y;
    u32 argb;
    GXColor c;

    cols = lbl_1_data_3D648.unk_10;
    rows = lbl_1_data_3D648.unk_12;
    x0 = lbl_1_data_3D648.unk_16;
    y0 = lbl_1_data_3D648.unk_18;
    cell_w = lbl_1_data_3D648.unk_14;
    cell_h = lbl_1_data_3D648.unk_14;
    hw = cols / 2;
    hh = rows / 2;
    fn_1_A9868();
    for (i = -hw; i <= hw; i++) {
        for (j = -hh; j <= hh; j++) {
            if (((lbl_1_data_3D648.unk_4 + i) > 639.0f ? 0 : (lbl_1_data_3D648.unk_4 + i) >= 0)
                && ((y = lbl_1_data_3D648.unk_6 + j) > fn_1_A5DB0() - 1 ? 0 : y >= 0)) {
                fn_8003432C(lbl_1_data_3D648.unk_4 + i, y, &argb);
                c.a = (argb & 0xFF000000) >> 24;
                c.r = (argb & 0xFF0000) >> 16;
                c.g = (argb & 0xFF00) >> 8;
                c.b = argb & 0xFF;
                fn_1_A9FFC(x0 + i * cell_w + 1, y0 + j * cell_h + 1, cell_w - 1, cell_h - 1, c);
                if (i == 0 && j == 0) {
                    static const GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
                    fn_1_A9B70(x0 - 1, y0 - 1, cell_w + 2, cell_h + 2, white);
                }
            }
        }
    }
    {
        static const GXColor white = {0xFF, 0xFF, 0xFF, 0xFF};
        fn_1_A9B70(lbl_1_data_3D648.unk_4 - hw - 1,
                   480.0f * (lbl_1_data_3D648.unk_6 - hh - 1) / fn_1_A5DB0(),
                   cols + 2,
                   480.0f * (rows + 2) / fn_1_A5DB0(),
                   white);
    }
    fn_1_AA538();
}
/* fzgx:end fn_1_D0F60 */

/* fzgx:begin fn_1_D123C */
typedef struct {
    u32 flags;
    s32 unk_4;
    u32 unk_8;
    u32 unk_C;
} LoadEntry;
typedef struct {
    u32 unk_0;
    u8 pad_4[0x48];
    LoadEntry entry;
} LoadResult;

extern u32 lbl_1_bss_7ACE0;
extern u32 lbl_1_bss_7ACDC;
extern void *lbl_801A6410;
extern void fn_80006E10(u32);
extern s8 fn_1_86690(s8);
extern s16 fn_1_12C7B8(s16);
extern void *fn_1_868C0(s8);
extern u32 fn_1_12C930(u32);
extern int fn_1_45730(void *, LoadResult *);
extern void fn_1_45850(void *);
extern u32 fn_1_45B2C(void *);
extern u32 fn_1_45D0(u32, u32, void *, u32);
extern void fn_1_458A0(void *, void *, void *, u32);
extern void DCInvalidateRange(void *, void *);
extern u32 fn_80071100(void *, u32, void *);
extern int sprintf(char *, const char *, ...);
extern void OSReport(const char *, ...);

s32 fn_1_D123C(u32 arg0) {
    u8 *base = (u8 *)&lbl_1_data_3D670;
    char buf[0x78];
    LoadResult res;
    s32 sid;
    void *ptr;
    s16 f;
    u32 v4;
    u8 v1;
    u8 v5;
    u32 *entry;
    u32 *aligned;
    u32 size;
    u32 *aligned2;
    u32 size2;
    u32 *entry2;

    fn_80006E10((u32)(base + 0x2BC));
    sid = (s8)arg0;
    v1 = (u8)fn_1_12C7B8(fn_1_86690(sid));
    ptr = fn_1_868C0(sid);
    v4 = ((u32 *)lbl_1_data_20D1C)[(s16)fn_1_12C930(v1)];
    f = *(s16 *)((u8 *)ptr + 0x3B8);
    v5 = (u8)f;
    v5 %= 4;
    if (v5 != 0 && v5 != 4) {
        sprintf(buf, (const char *)(base + 0x2C4), v4, v5);
        if (fn_1_45730(buf, &res) == 0) {
            sprintf(buf, (const char *)(base + 0x2D8), v4);
            OSReport((const char *)(base + 0x2E4), v1, v5);
        }
        fn_1_45850(&res);
    } else {
        sprintf(buf, (const char *)(base + 0x2D8), v4);
    }
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        switch ((s8)lbl_1_bss_9C) {
        case 3:
            if (v1 == 6) sprintf(buf, (const char *)(base + 0x318));
            break;
        case 5:
            if (v1 == 6) sprintf(buf, (const char *)(base + 0x32C));
            break;
        case 4:
            if (v1 == 0x17 && v5 != 0) {
                switch ((s32)(u8)arg0 % 5) {
                case 0: sprintf(buf, (const char *)(base + 0x340)); break;
                case 1: sprintf(buf, (const char *)(base + 0x358)); break;
                case 2: sprintf(buf, (const char *)(base + 0x370)); break;
                case 3: sprintf(buf, (const char *)(base + 0x388)); break;
                default: sprintf(buf, (const char *)(base + 0x3A0)); break;
                }
            }
            break;
        }
    }
    if (fn_1_45730(buf, &res) == 0) {
        fn_80006E10((u32)(base + 0x3B8));
        return 0;
    }
    size = fn_1_45B2C(&res);
    if ((*(u32 **)&lbl_1_bss_7ACE0)[(u8)arg0] != 0) {
        entry = (u32 *)(*(u32 **)&lbl_1_bss_7ACE0)[(u8)arg0];
    } else {
        entry = (u32 *)fn_1_45D0(*(u32 *)&lbl_801A6410,
                             (((size + 0x1F) & ~0x1F) + 0x20),
                             base + 0x3BC, 0xD2);
    }
    aligned = (u32 *)(((u32)entry + 0x3F) & ~0x1F);
    DCInvalidateRange(aligned, (void *)size);
    fn_1_458A0(&res, aligned, (void *)size, 0);
    entry[0] = aligned[0];
    entry[1] = (u32)&aligned[1];
    entry[2] = (u32)aligned;
    entry[3] = 0;
    (*(u32 **)&lbl_1_bss_7ACE0)[(u8)arg0] = (u32)entry;
    sprintf(buf, (const char *)(base + 0x3C4), v4);
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        switch ((s8)lbl_1_bss_9C) {
        case 3:
            if (v1 == 6) sprintf(buf, (const char *)(base + 0x3D0));
            break;
        case 5:
            if (v1 == 6) sprintf(buf, (const char *)(base + 0x3E4));
            break;
        case 4:
            if (v1 == 0x17 && v5 != 0) {
                switch ((s32)(u8)arg0 % 5) {
                case 0: sprintf(buf, (const char *)(base + 0x3F8)); break;
                case 1: sprintf(buf, (const char *)(base + 0x410)); break;
                case 2: sprintf(buf, (const char *)(base + 0x428)); break;
                case 3: sprintf(buf, (const char *)(base + 0x440)); break;
                default: sprintf(buf, (const char *)(base + 0x458)); break;
                }
            }
            break;
        }
    }
    if (fn_1_45730(buf, &res) == 0) {
        fn_80006E10((u32)(base + 0x3B8));
        return 0;
    }
    size2 = fn_1_45B2C(&res);
    if ((*(u32 **)&lbl_1_bss_7ACDC)[(u8)arg0] != 0) {
        entry2 = (u32 *)(*(u32 **)&lbl_1_bss_7ACDC)[(u8)arg0];
    } else {
        entry2 = (u32 *)fn_1_45D0(*(u32 *)&lbl_801A6410,
                             (((size2 + 0x1F) & ~0x1F) + 0x20),
                             base + 0x3BC, 0x121);
    }
    aligned2 = (u32 *)((u8 *)entry2 + 0x20);
    DCInvalidateRange(aligned2, (void *)size2);
    fn_1_458A0(&res, aligned2, (void *)size2, 0);
    fn_80071100(aligned2, (u32)entry2,
                (void *)(*(u32 **)&lbl_1_bss_7ACE0)[(u8)arg0]);
    entry2[4] &= ~1;
    (*(u32 **)&lbl_1_bss_7ACDC)[(u8)arg0] = (u32)entry2;
    fn_80006E10((u32)(base + 0x3B8));
    return 1;
}
/* fzgx:end fn_1_D123C */
