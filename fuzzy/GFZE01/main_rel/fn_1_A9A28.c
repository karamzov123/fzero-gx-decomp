/* Non-matching: best partial attempt (67.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"

extern const f32 lbl_1_rodata_4AD4;
extern const f32 lbl_1_rodata_4AC4;
extern void fn_8003462C(u32, u32, u32);

void fn_1_A9A28(s16 a0, s16 a1, s16 a2, s16 a3, u8 *color) {
    if ((s32)lbl_1_bss_71690.unk_0 != 0) {
        u8 c0, c1, c2, c3;

        fn_8003462C(0xA8, 0, 2);
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + a0;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + a1;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4;
        c0 = color[0];
        c1 = color[1];
        c2 = color[2];
        c3 = color[3];
        *(volatile u8 *)0xCC008000 = c0;
        *(volatile u8 *)0xCC008000 = c1;
        *(volatile u8 *)0xCC008000 = c2;
        *(volatile u8 *)0xCC008000 = c3;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + a2;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + a3;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4;
        *(volatile u8 *)0xCC008000 = c0;
        *(volatile u8 *)0xCC008000 = c1;
        *(volatile u8 *)0xCC008000 = c2;
        *(volatile u8 *)0xCC008000 = c3;
    }
}
