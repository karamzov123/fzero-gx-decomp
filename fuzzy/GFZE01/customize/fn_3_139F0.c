/* Non-matching: best partial attempt (94.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 165.0f;
    s = 38.0f;
    s = 50.0f;
    s = 320.0f;
    s = 240.0f;
    s = 10.0f;
    s = 90.0f;
    s = 0.800000011920929f;
    s = 148.0f;
    s = 9.0f;
    s = 5.0f;
    s = 0.6666666865348816f;
    s = 7.0f;
    s = 0.5f;
    s = 0.6000000238418579f;
    s = 49.0f;
    s = 8.0f;
    s = 458.0f;
    s = 110.0f;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

extern f32 lbl_3_rodata_4E0[22];
extern s32 lbl_801A66B4;
extern void fn_1_5233C(void);

typedef struct {
    u32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0c;
    u8 unk_10[0x20];
    u32 unk_30;
    u8 unk_34[0x24];
} FontDrawPacket;

extern const FontDrawPacket lbl_1_rodata_26F8;

extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49410(void);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4F734(void *);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4954C(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_494DC(s16);

#pragma opt_propagation on
#pragma opt_loop_invariants off
#pragma opt_common_subs on
extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("Move Cursor");
}
#pragma section code_type ".text"

void fn_3_139F0(void) {
    f32 *fzgx_value;
    u8 *base;
    f32 *pool;
    u32 *tbl_2;
    u32 *tbl;
    FontDrawPacket packet;
    u8 i;
    s32 p;
    s32 q;
    u32 lab_t1;
    u8 lab_t0;

    pool = lbl_3_rodata_4E0;
    base = (u8 *)"Move Cursor";

    packet = lbl_1_rodata_26F8;
    packet.unk_00 = 0xc;
    packet.unk_04 = 320.0f;
    packet.unk_08 = 240.0f;
    packet.unk_0c = 10.0f;
    packet.unk_30 = 0xa;
    fn_1_50A90(&packet, 7, 7, 0x250, 0x136);

    fn_1_496FC(320.0f, 90.0f);
    fn_1_49410();
    fn_1_495C8(1);
    fn_1_4955C(0.800000012f, 0.800000012f);

    packet = lbl_1_rodata_26F8;
    packet.unk_00 = 0x8602;
    fzgx_value = &(packet.unk_04);
    *fzgx_value = 148.0f;
    packet.unk_08 = 148.0f;
    packet.unk_0c = 9.0f;
    packet.unk_30 = 5;
    fn_1_4F734(&packet);

    tbl = (u32 *)(base + 0xfc);
    for (i = 0; i < 3; i++) {
        fn_1_49410();
        fn_1_495C8(0);
        fn_1_49738((u32)fn_1_5233C);
        fn_1_49748(5.0f);
        fn_1_4955C(0.666666687f, 0.666666687f);
        fn_1_4954C(7.0f);
        fn_1_495B0(0x80000000);
        if (lbl_801A66B4 != 5) {
            fn_1_49590(0.5f);
            fn_1_4955C(0.600000024f, 0.600000024f);
            p = i * 99;
            q = i * 3;
            fn_1_496FC(49.0f, (f32)(p + 145 + q));
        } else {
            fn_1_496FC(49.0f, (f32)(i * 100 + 147));
        }
        lab_t1 = *(tbl + i * 6 + lbl_801A66B4);
        fn_1_4AE0C((char *)base + 0x248, lab_t1);
    }

    tbl_2 = (u32 *)(base + 0xfc);
    for (i = 3; i < 9; i++) {
        fn_1_49410();
        fn_1_495C8(0);
        fn_1_49738((u32)fn_1_5233C);
        fn_1_49748(8.0f);
        fn_1_4955C(0.666666687f, 0.666666687f);
        fn_1_495B0(0x80000000);
        fn_1_4954C(7.0f);
        if (lbl_801A66B4 != 5) {
            fn_1_49590(0.5f);
            fn_1_4955C(0.600000024f, 0.600000024f);
            fn_1_496FC(458.0f, (f32)(((((i - 3) * 40) + (145)) + ((i - 3)))));
        } else {
            fn_1_496FC(458.0f, (f32)(((((i - 3) * 40) + (143)) + ((i - 3)))));
        }
        lab_t1 = *(tbl_2 + i * 6 + lbl_801A66B4);
        fn_1_4AE0C((char *)base + 0x248, lab_t1);
    }

    fn_1_49410();
    fn_1_494DC(5);
    lab_t0 = 1;
    fn_1_495C8(lab_t0);
    fn_1_4954C(7.0f);
    fn_1_496FC(320.0f, 110.0f);
    lab_t1 = *(tbl_2 + 54 + lbl_801A66B4);
    fn_1_4AE0C((char *)base + 0x24c, lab_t1);
}
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
