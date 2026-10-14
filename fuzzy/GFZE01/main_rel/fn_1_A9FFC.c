/* Non-matching: best partial attempt (69.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"

extern void fn_8003462C(u32 arg0, u32 arg1, u32 arg2);
extern const f32 lbl_1_rodata_4AD4;
extern f32 lbl_1_rodata_4AC4[4];

void fn_1_A9FFC(s16 x, s16 y, s16 w, s16 h, u8 *color) {
    if ((s32)lbl_1_bss_71690.unk_0 != 0) {
        f32 fx0;
        f32 fy0;
        f32 fx1;
        f32 fy1;
        u8 cr;
        u8 cg;
        u8 cb;
        u8 ca;

        fn_8003462C(0x80, 0, 4);
        fx0 = lbl_1_rodata_4AD4 + x;
        fy0 = lbl_1_rodata_4AD4 + y;
        fx1 = lbl_1_rodata_4AD4 + x + w;
        fy1 = lbl_1_rodata_4AD4 + y + h;
        cr = color[0];
        cg = color[1];
        cb = color[2];
        ca = color[3];
        *(volatile f32 *)0xCC008000 = fx0;
        *(volatile f32 *)0xCC008000 = fy0;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4[0];
        *(volatile u8 *)0xCC008000 = cr;
        *(volatile u8 *)0xCC008000 = cg;
        *(volatile u8 *)0xCC008000 = cb;
        *(volatile u8 *)0xCC008000 = ca;
        *(volatile f32 *)0xCC008000 = fx1;
        *(volatile f32 *)0xCC008000 = fy0;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4[0];
        *(volatile u8 *)0xCC008000 = cr;
        *(volatile u8 *)0xCC008000 = cg;
        *(volatile u8 *)0xCC008000 = cb;
        *(volatile u8 *)0xCC008000 = ca;
        *(volatile f32 *)0xCC008000 = fx1;
        *(volatile f32 *)0xCC008000 = fy1;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4[0];
        *(volatile u8 *)0xCC008000 = cr;
        *(volatile u8 *)0xCC008000 = cg;
        *(volatile u8 *)0xCC008000 = cb;
        *(volatile u8 *)0xCC008000 = ca;
        *(volatile f32 *)0xCC008000 = fx0;
        *(volatile f32 *)0xCC008000 = fy1;
        *(volatile f32 *)0xCC008000 = lbl_1_rodata_4AC4[0];
        *(volatile u8 *)0xCC008000 = cr;
        *(volatile u8 *)0xCC008000 = cg;
        *(volatile u8 *)0xCC008000 = cb;
        *(volatile u8 *)0xCC008000 = ca;
    }
}
