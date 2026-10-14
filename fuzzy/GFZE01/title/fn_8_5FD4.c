/* Non-matching: best partial attempt (52.79% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/title/title.h"
#include "types.h"

extern u8 lbl_1_bss_7EFD8[];

typedef struct {
    u8 pad[0x40];
    u32 data;
} GlobalState;

typedef struct {
    u8 pad[0x110];
    u16 count;
} DataHead;

static f32 bits_f32(u32 bits) {
    union { u32 u; f32 f; } v;
    v.u = bits;
    return v.f;
}

void fn_8_5FD4(void) {
    u8 scratch[0x14A8];
    u8 *base;
    u8 *record;
    u8 *argp[9];
    u32 i, j, off;
    u32 v;
    fn_1_3EF14(scratch);
    fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 8);
    base = (u8 *)((GlobalState *)lbl_1_bss_7EFD8)->data;
    *(u16 *)(base + 0x10000 - 0x110) =
        (u16)fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 8);
    *(u8 *)(lbl_1_bss_7EFD8 + 0x18) = scratch[8];
    for (i = 0; i < *(u16 *)(base + 0x10000 - 0x110); i++) {
        record = base + 0x10000 + i * 0x80;
        v = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 14);
        *(u16 *)(record - 0xB4) = (*(u16 *)(record - 0xB4) & 1) | ((v << 1) & 0xFFFE);
        v = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 14);
        *(u16 *)(record - 0xB0) = (*(u16 *)(record - 0xB0) & 1) | ((v << 1) & 0xFFFE);
        v = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 4);
        *(u32 *)(record - 0xB4) = (*(u32 *)(record - 0xB4) & ~0x1C000) | ((v << 14) & 0x1C000);
        v = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 5);
        *(u8 *)(record - 0xB2) = (*(u8 *)(record - 0xB2) & ~0x3E) | ((v << 1) & 0x3E);
        v = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 5);
        *(u16 *)(record - 0xB2) = (*(u16 *)(record - 0xB2) & ~0x1F0) | ((v << 4) & 0x1F0);
        v = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 5);
        *(u32 *)(record - 0xB0) = (*(u32 *)(record - 0xB0) & ~0x1F000) | ((v << 12) & 0x1F000);
        v = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 5);
        *(u16 *)(record - 0xAE) = (*(u16 *)(record - 0xAE) & ~0xF80) | ((v << 7) & 0xF80);
        v = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 5);
        *(u8 *)(record - 0xAD) = (*(u8 *)(record - 0xAD) & ~0x7C) | ((v << 2) & 0x7C);
        for (j = 0, off = 0; j < *(u8 *)(lbl_1_bss_7EFD8 + 0x18); j++, off += 12) {
            *(f32 *)(record - 0xAC + off) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 32));
            *(f32 *)(record - 0xA8 + off) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 32));
            *(f32 *)(record - 0xA4 + off) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 32));
            *(f32 *)(record - 0x7C + off) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 32));
            *(f32 *)(record - 0x78 + off) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 32));
            *(f32 *)(record - 0x74 + off) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 32));
        }
        *(f32 *)(record - 0x4C) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 32));
        *(f32 *)(record - 0x48) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2AC, (void *)&lbl_8_bss_2AC, 32));
        *(f32 *)(record - 0x44) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2AC, (void *)&lbl_8_bss_2AC, 32));
        *(f32 *)(record - 0x40) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2AC, (void *)&lbl_8_bss_2AC, 32));
        *(f32 *)(record - 0x3C) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2AC, (void *)&lbl_8_bss_2AC, 32));
        *(f32 *)(record - 0x38) = bits_f32(fn_1_F453C((void *)lbl_8_bss_2AC, (void *)&lbl_8_bss_2AC, 32));
    }
    *(u16 *)(base + 0xA0) = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 13);
    for (i = 0; i <= *(u16 *)(base + 0xA0); i++) {
        off = i * 7;
        *(u8 *)(base + off + 0xA4) = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 8);
        *(u8 *)(base + off + 0xA7) = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 8);
        *(u8 *)(base + off + 0xA8) = fn_1_F453C((void *)lbl_8_bss_2B0, (void *)&lbl_8_bss_2AC, 7);
        *(u8 *)(base + off + 0xA9) = fn_1_F453C((void *)lbl_8_bss_2AC, (void *)&lbl_8_bss_2AC, 7);
        *(u8 *)(base + off + 0xAA) = fn_1_F453C((void *)lbl_8_bss_2AC, (void *)&lbl_8_bss_2AC, 8);
        *(u8 *)(base + off + 0xA5) = fn_1_F453C((void *)lbl_8_bss_2AC, (void *)&lbl_8_bss_2AC, 8);
        *(u8 *)(base + off + 0xA6) = fn_1_F453C((void *)lbl_8_bss_2AC, (void *)&lbl_8_bss_2AC, 8);
    }
    fn_1_F4794(0);
    *(u16 *)(base + 0xA0) = 0;
}
