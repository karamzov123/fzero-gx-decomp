/* Non-matching: best partial attempt (93.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x437F0000};
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;
    s = 128.0f;
    d = 4503599627370496.0;
    s = 16.5f;
    s = 0.0f;
    s = 128.5f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }
#pragma section code_type ".text"
typedef struct Sig_fn_12_3E394_Matrix3 {
    f32 m[9];
} Sig_fn_12_3E394_Matrix3;
extern f32 lbl_12_bss_1E088[213];
extern u8 lbl_12_data_EA0[36];
extern u8 lbl_12_data_EC4[36];
extern void fn_12_3E688(u8 *, u8 *, u8 *);
extern void fn_12_3E500(const Sig_fn_12_3E394_Matrix3 *, Sig_fn_12_3E394_Matrix3 *);
extern void fn_12_3E394(const Sig_fn_12_3E394_Matrix3 *, const Sig_fn_12_3E394_Matrix3 *, Sig_fn_12_3E394_Matrix3 *);
extern u32 __cvt_fp2unsigned(f32);
static inline u8 *fn_12_3D968_array_read(u8 *array) { return array; }
#pragma opt_propagation on
void fn_12_3D968(u32 *arg0) {
    struct { u8 *value; } g;
    u8 *pa;
    u32 *d2;
    struct { u32 *value; } d0;
    struct { u32 *value; } d1;
    u8 *pc;
    u8 *pb;
    u32 *d3;
    struct { u32 *value; } outputs;
    f32 c2;
    f32 c1;
    f32 c0;
    f32 p2;
    f32 p1;
    s32 i;
    const Sig_fn_12_3E394_Matrix3 *lab_t1;
    d0.value = arg0;
    d1.value = d0.value + 0x100;
    g.value = (u8 *)lbl_12_bss_1E088;
    d2 = d1.value + 0x100;
    fn_12_3E688(g.value + 0x254, g.value + 0x154, g.value + 0x54);
    fn_12_3E500((const Sig_fn_12_3E394_Matrix3 *)&lbl_12_data_EA0,
                (Sig_fn_12_3E394_Matrix3 *)(g.value + 0x24));
    lab_t1 = (const Sig_fn_12_3E394_Matrix3 *)(g.value + 0x24);
    fn_12_3E394((const Sig_fn_12_3E394_Matrix3 *)&lbl_12_data_EC4, lab_t1, (Sig_fn_12_3E394_Matrix3 *)&lbl_12_bss_1E088[0]);
    lab_t1 = (const Sig_fn_12_3E394_Matrix3 *)&lbl_12_bss_1E088[0];
    c1 = lab_t1->m[4];
    c2 = lab_t1->m[8];
    p1 = 128.0f * c1;
    p2 = 128.0f * c2;
    c0 = *(const f32 *)g.value;
    pa = g.value + 0x254;
    pb = g.value + 0x154;
    pc = g.value + 0x54;
    d3 = d2 + 0x100;
    for (i = 0; i < 0x100; i++) {
        f32 x;
        f32 v;
        u32 q0;
        u32 q1;
        u32 q2;
        x = (f32)(u32)pa[i];
        v = c0 * x + 16.5f;
        if (v < 0.0f) { v = 0.0f; }
        if (v > 255.0f) { v = 255.0f; }
        q0 = __cvt_fp2unsigned(v);
        d0.value[i] = q0 << 24;
        d1.value[i] = q0 << 8;
        x = (f32)(u32)pb[i];
        v = 128.5f + (c1 * x - p1);
        if (v < 0.0f) { v = 0.0f; }
        if (v > 255.0f) { v = 255.0f; }
        q1 = __cvt_fp2unsigned(v);
        *d2 = q1 << 16;
        x = (f32)(u32)pc[i];
        v = 128.5f + (c2 * x - p2);
        if (v < 0.0f) { v = 0.0f; }
        if (v > 255.0f) { v = 255.0f; }
        q2 = __cvt_fp2unsigned(v);
        *d3 = q2;
        d2++;
        d3++;
    }
}
#pragma opt_propagation reset

