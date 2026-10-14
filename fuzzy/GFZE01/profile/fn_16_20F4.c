/* Non-matching: best partial attempt (95.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 240.0f;
    s = 0.0010000000474974513f;
    s = 0.009999999776482582f;
    s = 0.5f;
    s = 480.0f;
    s = 2.0f;
    s = 0.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -4.5f;
    s = -17.5f;
    s = -2.9000000953674316f;
    s = 30.0f;
    s = 0.8784313797950745f;
    s = -11.0f;
    s = 1.0f;
    s = 0.625f;
    s = -30.0f;
    s = -6.0f;
}
#pragma section code_type ".text"
struct fn_16_20F4_9F8 {
    u16 unk_0;
    u8 pad_2[0x6];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[0x6];
    u16 unk_12;
};
struct fn_16_20F4_8B614 {
    u8 pad_0[0x8];
    s16 unk_8;
    u8 pad_A[0xE];
    f32 unk_18;
    u8 pad_1C[0xC];
    s16 unk_28;
    s16 unk_2A;
    u32 unk_2C;
    s16 unk_30;
};
struct fn_16_20F4_A48 {
    s8 unk_0;
    s8 unk_1;
    u8 pad_2[0xE];
};
struct fn_16_20F4_BF0 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x10];
};
extern struct fn_16_20F4_8B614 lbl_1_bss_8B614;
extern struct fn_16_20F4_9F8 lbl_1_bss_9F8[];
extern struct fn_16_20F4_A48 lbl_1_bss_A48[];
extern struct fn_16_20F4_BF0 lbl_1_bss_BF0[];
extern const f32 lbl_16_rodata_0[22];
extern void fn_1_A2D84(u32);
#pragma opt_propagation off
#pragma opt_common_subs on
s32 fn_16_20F4(void) {
    struct { volatile u16 *value; } p; /* Controller flags are read on each test. */
    volatile u16 *q;
    s32 idx = lbl_1_bss_8B614.unk_8;
    s16 flag = 0;
    s32 a;
    s32 b;
    s32 t;
    f32 v;
    u32 c;
    a = lbl_1_bss_8B614.unk_2A + lbl_1_bss_A48[idx].unk_0 / 20;
    a = (a > 0x168) ? 0 : (a < 0 ? 0x168 : a);
    lbl_1_bss_8B614.unk_2A = a;
    b = lbl_1_bss_8B614.unk_28 + lbl_1_bss_A48[idx].unk_1 / 20;
    b = (b > 0x168) ? 0 : (b < 0 ? 0x168 : b);
    lbl_1_bss_8B614.unk_28 = b;
    v = lbl_1_bss_8B614.unk_18 + (f32)(lbl_1_bss_BF0[idx].unk_C * 0.5f);
    v = (v < (-30.0f)) ? (-30.0f)
      : (v > (-6.0f) ? (-6.0f) : v);
    lbl_1_bss_8B614.unk_18 = v;
    {
    s32 offset = idx * 20;
    p.value = (u16 *)((u8 *)lbl_1_bss_9F8 + offset);
    p.value += 4;
    if ((*p.value >> 4) & 1) {
        fn_1_A2D84(0xA9010000);
        c = lbl_1_bss_8B614.unk_2C;
        (void) c;
        lbl_1_bss_8B614.unk_2C = ((u32)(1 - c) | (c - 1)) >> 31;
    }
    q = (u16 *)((u32)lbl_1_bss_9F8 + offset + 18);
    }
    if ((*q >> 8) & 1) {
        flag = 1;
    }
    if ((*q >> 9) & 1) {
        flag--;
    }
    if (flag != 0) {
        t = lbl_1_bss_8B614.unk_30 + flag;
        t = (t > 3) ? 0 : (t < 0 ? 3 : t);
        lbl_1_bss_8B614.unk_30 = t;
        fn_1_A2D84(0xA9010000);
    }
    if ((*p.value >> 9) & 1) {
        fn_1_A2D84(0xA9010000 + 0x200);
        return -1;
    }
    return 0;
}
#pragma opt_propagation reset

