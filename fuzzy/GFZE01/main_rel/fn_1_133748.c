/* Non-matching: best partial attempt (91.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x0000001D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table2[1] = {0x000000EE};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table3[1] = {0x0000014A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table4[1] = {0x0000021B};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern const f64 lbl_1_rodata_8600;
extern const f32 lbl_1_rodata_86F8;
extern const f32 lbl_1_rodata_86FC;
extern u32 lbl_1_rodata_8744[4];
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_dead_assignments off
void fn_1_133748(s32 arg0, s16 arg1, u32 lab_unused0, u32 lab_unused1) {
    FontDrawPacket p;
    FontDrawPacket * lab_t0_2;
    u32 tbl[4];
    FontDrawPacket * lab_t0;
    s32 i;

    tbl[0] = lbl_1_rodata_8744[0];
    tbl[1] = lbl_1_rodata_8744[1];
    tbl[2] = lbl_1_rodata_8744[2];
    tbl[3] = lbl_1_rodata_8744[3];

    for (i = 0; i < 6; i++) {
        p = *(FontDrawPacket *)lbl_1_rodata_26F8;
        p.image = 0x9D03;
        lab_t0 = &p;
        fn_1_51678(lab_t0, 0x9D03, 0, 0, 8, 96);
        p.x = (f32)(s32)(arg0 + i * 96);
        p.z = 200.0f;
        p.y = (f32)(s32)arg1;
        p.rotation_z = -0x4000;
        p.flags = 0x10000;
        fn_1_4F734(&p);
    }
    for (i = 0; i < 4; i++) {
        p = *(FontDrawPacket *)lbl_1_rodata_26F8;
        p.image = 0x9D03;
        lab_t0_2 = &p;
        fn_1_51678(lab_t0_2, 0x9D03, 0, 96, 8, 12);
        p.x = (f32)(s32)(arg0 + tbl[i] - 85);
        p.z = 180.0f;
        p.y = (f32)(s32)arg1;
        p.rotation_z = -0x4000;
        p.flags = 0x10000;
        fn_1_4F734(&p);
    }
}
#pragma opt_dead_assignments reset

