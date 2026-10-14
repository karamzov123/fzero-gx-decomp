/* Non-matching: best partial attempt (37.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"

extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern const f64 lbl_1_rodata_4AD8;
extern const f32 lbl_1_rodata_4AD4;
extern f32 lbl_1_rodata_4AC4[4];

// Push one coloured quad (x, y, x + w, y + h) as four vertices into the FIFO port.
void fn_1_AA188(s16 x, s16 y, s16 w, s16 h, u8 *c0, u8 *c1, u8 *c2, u8 *c3) {
    if ((s32)lbl_1_bss_71690.unk_0 != 0) {
        fn_8003462C(0x80, 0, 4);

        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + (f32)(s32)x;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + (f32)(s32)y;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4[0];
        *(volatile u8 *)0xCC008000 = c0[0];
        *(volatile u8 *)0xCC008000 = c0[1];
        *(volatile u8 *)0xCC008000 = c0[2];
        *(volatile u8 *)0xCC008000 = c0[3];

        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + (f32)(s32)(x + w);
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + (f32)(s32)y;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4[0];
        *(volatile u8 *)0xCC008000 = c1[0];
        *(volatile u8 *)0xCC008000 = c1[1];
        *(volatile u8 *)0xCC008000 = c1[2];
        *(volatile u8 *)0xCC008000 = c1[3];

        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + (f32)(s32)(x + w);
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + (f32)(s32)(y + h);
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4[0];
        *(volatile u8 *)0xCC008000 = c2[0];
        *(volatile u8 *)0xCC008000 = c2[1];
        *(volatile u8 *)0xCC008000 = c2[2];
        *(volatile u8 *)0xCC008000 = c2[3];

        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + (f32)(s32)x;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AD4 + (f32)(s32)(y + h);
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4[0];
        *(volatile u8 *)0xCC008000 = c3[0];
        *(volatile u8 *)0xCC008000 = c3[1];
        *(volatile u8 *)0xCC008000 = c3[2];
        *(volatile u8 *)0xCC008000 = c3[3];
    }
}
