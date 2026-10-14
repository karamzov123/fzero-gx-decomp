/* Non-matching: best partial attempt (65.53% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/emblem.h"

struct Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

extern struct Color fn_3_149AC(void *, s16, s16);
extern void *memset(void *, int, u32);

#define RGB565(r, g, b) ((((g) << 3) & 0x7E0) | (((r) << 8) & 0xF800) | (((b) >> 3) & 0x1F))
#define RGB5A3(color, a) \
    ((a) >= 224 ? ((((color).g << 2) & 0x3E0) | (((color).r << 7) & 0x7C00) | (((color).b >> 3) & 0x1F) | 0x8000) \
                : ((((color).g >> 4) << 4) | (((color).r << 4) & 0xF00) | (((color).b >> 4) & 0xF) | (((a) << 7) & 0x7000)))

static inline void draw_pixel(void *arg0, s16 x, s16 y, struct Color color) {
    switch (lbl_3_bss_A23E0) {
    case 4: {
        s16 block_idx = (x / 4) + (y / 4) * (lbl_3_bss_A23D8 >> 2);
        s16 offset = (block_idx << 5) + (((x % 4) + ((y % 4) * 4)) << 1);
        u16 rgb565 = RGB565(color.r, color.g, color.b);
        memset((u8 *)arg0 + offset, rgb565 >> 8, 1);
        memset((u8 *)arg0 + offset + 1, rgb565, 1);
        break;
    }
    case 5: {
        u8 a = color.a;
        s16 block_idx = (x >> 2) + (s16)(y >> 2) * (s16)((s16)lbl_3_bss_A23D8 >> 2);
        s16 offset = (((x & 3) + ((y & 3) << 2)) << 1) + (block_idx << 5);
        ((u8 *)arg0)[offset] = (u16)RGB5A3(color, a) >> 8;
        ((u8 *)arg0)[offset + 1] = RGB5A3(color, a);
        break;
    }
    }
}

void fn_3_14E18(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    struct Color c1 = fn_3_149AC(arg0, arg1, arg2);
    struct Color c2 = fn_3_149AC(arg0, arg3, arg4);

    draw_pixel(arg0, arg1, arg2, c2);
    draw_pixel(arg0, arg3, arg4, c1);
}
