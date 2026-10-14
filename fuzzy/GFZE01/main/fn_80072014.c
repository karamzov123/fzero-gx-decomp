/* Non-matching: best partial attempt (67.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct FogState { u8 pad[0x20]; u8 r, g, b, a; u32 unk24; u32 color; };
extern struct FogState lbl_8019E250[];
extern u32 gx;

void fn_80072014(u8 *arg0) {
    u32 reg;
    u32 b;
    u32 g;
    u32 r;
    if (lbl_8019E250[0].r == arg0[0] && lbl_8019E250[0].g == arg0[1] && lbl_8019E250[0].b == arg0[2]) return;
    b = arg0[2];
    g = arg0[1];
    r = arg0[0];
    reg = b;
    reg = (reg & 0xFFFF00FF) | ((g << 8) & 0xFF00);
    reg = (reg & 0xFF00FFFF) | ((r << 16) & 0xFF0000);
    lbl_8019E250[0].r = arg0[0];
    lbl_8019E250[0].g = g;
    lbl_8019E250[0].b = b;
    reg = (reg & 0xFFFFFF) | 0xF2000000;
    lbl_8019E250[0].color = reg;
    *(u16 *)(gx + 2) = 0;
    *(volatile u8 *)0xCC008000 = 0x61;
    *(volatile u32 *)0xCC008000 = reg;
}
