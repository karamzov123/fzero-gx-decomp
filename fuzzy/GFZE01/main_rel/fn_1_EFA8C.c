/* Non-matching: best partial attempt (67.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/ghost.h"

extern u32 lbl_801A6410;
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_F18C0(const u32 *, u32 *, u32 *, u32 *);
extern f32 fn_1_F1650(const u32 *);
extern int sprintf(char *, const char *, ...);
extern const f64 lbl_1_rodata_6B68;
extern const f32 lbl_1_rodata_6B60;

void fn_1_EFA8C(void) {
    u8 *bss = (u8 *)&lbl_1_bss_7B180;
    u8 *data = lbl_1_data_3E358;
    u32 i;
    u32 j;
    u8 name[0x100];
    u32 *inputs;
    u32 *out[11];
    u32 count;
    u32 *item;
    u32 *row;
    u32 vec0;
    u32 vec1;
    u32 vec2;
    f32 value;
    f32 accum;
    u32 *sizes;
    u32 *times;

    inputs = (u32 *)(bss + 0x1600);
    {
        u32 *p0 = (u32 *)(bss + 0x1600);
        u32 *p1 = (u32 *)(bss + 0x1614);
        u32 *p2 = (u32 *)(bss + 0x1628);
        u32 *p3 = (u32 *)(bss + 0x163c);
        u32 *p4 = (u32 *)(bss + 0x1650);
        u32 *p5 = (u32 *)(bss + 0x1664);
        u32 *p6 = (u32 *)(bss + 0x1678);
        u32 *p7 = (u32 *)(bss + 0x168c);
        u32 *p8 = (u32 *)(bss + 0x16a0);
        u32 *p9 = (u32 *)(bss + 0x16b4);
        for (i = 0; i < bss[0x1754]; i++) {
#define FREEONE(P, LINE) if (*P != 0) { fn_1_46B4(lbl_801A6410, *P, data + 0x2d4, LINE); *P = 0; }
            FREEONE(p0, 0xfa4);
            FREEONE(p1, 0xfa5);
            FREEONE(p2, 0xfa6);
            FREEONE(p3, 0xfa7);
            FREEONE(p4, 0xfa8);
            FREEONE(p5, 0xfa9);
            FREEONE(p6, 0xfaa);
            FREEONE(p7, 0xfab);
            FREEONE(p8, 0xfac);
            FREEONE(p9, 0xfad);
#undef FREEONE
            sprintf((char *)name, (char *)(data + 0x354), i);
            p0++; p1++; p2++; p3++; p4++; p5++; p6++; p7++; p8++; p9++;
        }
    }

    out[0] = (u32 *)(bss + 0x16b4);
    out[1] = (u32 *)(bss + 0x16a0);
    out[2] = (u32 *)(bss + 0x168c);
    out[3] = (u32 *)(bss + 0x1678);
    out[4] = (u32 *)(bss + 0x1664);
    out[5] = (u32 *)(bss + 0x1650);
    out[6] = (u32 *)(bss + 0x163c);
    out[7] = (u32 *)(bss + 0x1628);
    out[8] = (u32 *)(bss + 0x1614);
    out[9] = (u32 *)(bss + 0x1600);
    out[10] = (u32 *)(bss + 0x1824);
    for (i = 0; i < bss[0x1754]; i++) {
        item = *(u32 **)(bss + 0x1824 + i * 4);
        count = *(u16 *)((u8 *)item + 0x18);
        *out[0] = count;
        out[1][i] = fn_1_4630(lbl_801A6410, count * 4, data + 0x2d4, 0xfb9);
        out[2][i] = fn_1_4630(lbl_801A6410, count * 4, data + 0x2d4, 0xfba);
        out[3][i] = fn_1_4630(lbl_801A6410, count * 4, data + 0x2d4, 0xfbb);
        out[4][i] = fn_1_4630(lbl_801A6410, count * 4, data + 0x2d4, 0xfbc);
        out[5][i] = fn_1_4630(lbl_801A6410, count, data + 0x2d4, 0xfbd);
        out[6][i] = fn_1_4630(lbl_801A6410, count * 2, data + 0x2d4, 0xfbe);
        out[7][i] = fn_1_4630(lbl_801A6410, count, data + 0x2d4, 0xfbf);
        out[8][i] = fn_1_4630(lbl_801A6410, count * 2, data + 0x2d4, 0xfc0);
        sprintf((char *)name, (char *)(data + 0x354), i);
    }

    sizes = (u32 *)(bss + 0x1600);
    times = (u32 *)(bss + 0x180c);
    for (i = 0; i < bss[0x1754]; i++) {
        item = *(u32 **)(bss + 0x16b4 + i * 4);
        count = *(u32 *)(bss + 0x1824 + i * 4) - 1;
        accum = lbl_1_rodata_6B60;
        for (j = 0; j < count; j++) {
            row = (u32 *)((u8 *)item + 0x28 + j * 0x10);
            *(f32 *)((u8 *)sizes[i] + j * 4) = accum;
            fn_1_F18C0(row + 2, &vec0, &vec1, &vec2);
            ((f32 *)((u8 *)out[1][i]))[j] = fn_1_F1650(&vec0);
            ((f32 *)((u8 *)out[2][i]))[j] = fn_1_F1650(&vec1);
            ((f32 *)((u8 *)out[3][i]))[j] = fn_1_F1650(&vec2);
            ((u8 *)out[4][i])[j] = *((u8 *)row + 2);
            ((s16 *)out[5][i])[j] = *(s16 *)((u8 *)row + 4);
            ((u8 *)out[6][i])[j] = *((u8 *)row + 3);
            ((u8 *)out[7][i])[j] = *((u8 *)row + 1);
            ((u16 *)out[8][i])[j] = *(u16 *)((u8 *)row + 6);
            accum += (f32)(u32)*(u8 *)((u8 *)row + 0x10);
        }
        row = (u32 *)((u8 *)item + 0x28 + count * 0x10);
        ((f32 *)((u8 *)sizes[i]))[count] = accum;
        fn_1_F18C0(row + 2, &vec0, &vec1, &vec2);
        ((f32 *)((u8 *)out[1][i]))[count] = fn_1_F1650(&vec0);
        ((f32 *)((u8 *)out[2][i]))[count] = fn_1_F1650(&vec1);
        ((f32 *)((u8 *)out[3][i]))[count] = fn_1_F1650(&vec2);
        ((u8 *)out[4][i])[count] = *((u8 *)row + 2);
        ((s16 *)out[5][i])[count] = *(s16 *)((u8 *)row + 4);
        ((u8 *)out[6][i])[count] = *((u8 *)row + 3);
        ((u8 *)out[7][i])[count] = *((u8 *)row + 1);
        ((u16 *)out[8][i])[count] = *(u16 *)((u8 *)row + 6);
        item = *(u32 **)(bss + 0x16b4 + i * 4);
        times[i] = ((u32)*((u8 *)item + 0x24) * 0xfffffe60) +
                   *((u8 *)item + 0x26) + *((u8 *)item + 0x25) * 1000;
    }
    *(u32 *)(data + 0x1d4) = 0x10;
}
