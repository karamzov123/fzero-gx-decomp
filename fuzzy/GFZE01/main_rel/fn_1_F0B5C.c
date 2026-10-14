/* Non-matching: best partial attempt (45.53% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Words3;

extern f32 fn_1_F4E3C(s32, f32 *, f32 *, f32 *, f32);
extern f64 lbl_1_rodata_6B68;
extern Words3 lbl_1_rodata_6D28;
extern u8 lbl_1_bss_7B180[];

s32 fn_1_F0B5C(s32 arg0, void *arg1) {
    u8 *p = (u8 *)&lbl_1_bss_7B180;
    u16 *ph = (u16 *)(p + 0x1800);
    s32 *pix = (s32 *)(p + 0x1824);
    f32 **pa = (f32 **)(p + 0x1600);
    Words3 c = lbl_1_rodata_6D28;
    f32 t0, t1, t2, t3, lim;
    s32 i = arg0;
    u32 i2 = (u32)i * 2;
    u32 i4 = (u32)i * 4;

    t0 = fn_1_F4E3C(*(s32 *)((u8 *)pix + i4), (f32 *)*(u32 *)((u8 *)pa + i4), (f32 *)*(u32 *)((u8 *)p + 0x1614 + i4), (f32 *)*(u32 *)((u8 *)p + 0x16ec + i4), (f32)ph[i2 / 2]);
    ((f32 *)arg1)[0] = t0;
    t1 = fn_1_F4E3C(*(s32 *)((u8 *)pix + i4), (f32 *)*(u32 *)((u8 *)pa + i4), (f32 *)*(u32 *)((u8 *)p + 0x1628 + i4), (f32 *)*(u32 *)((u8 *)p + 0x1700 + i4), (f32)ph[i2 / 2]);
    ((f32 *)arg1)[1] = t1;
    t2 = fn_1_F4E3C(*(s32 *)((u8 *)pix + i4), (f32 *)*(u32 *)((u8 *)pa + i4), (f32 *)*(u32 *)((u8 *)p + 0x163c + i4), (f32 *)*(u32 *)((u8 *)p + 0x1714 + i4), (f32)ph[i2 / 2]);
    ((f32 *)arg1)[2] = t2;
    t3 = (f32)ph[i2 / 2];
    lim = *(f32 *)((u8 *)(*(u32 *)((u8 *)pa + i4) + *(s32 *)((u8 *)pix + i4) * 4) - 4);
    if (t3 >= lim) {
        ((u32 *)arg1)[0] = c.x;
        ((u32 *)arg1)[1] = c.y;
        ((u32 *)arg1)[2] = c.z;
        return 0;
    }
    *(Words3 *)(p + 0x1758 + i4 + ((u32)i * 8)) = *(Words3 *)arg1;
    return 1;
}
