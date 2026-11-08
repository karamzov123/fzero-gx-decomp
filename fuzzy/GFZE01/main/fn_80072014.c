/* Non-matching: best partial attempt (97.90% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/gx.h"
#include "types.h"

typedef struct fn_80072014_GXColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_80072014_GXColor;

struct fn_80072014_lbl_8019E250 {
    u8 pad_0[0x20];
    u8 fog_r;
    u8 fog_g;
    u8 fog_b;
    u8 fog_a;
    u32 unk_24;
    u32 fog_reg;
};

struct fn_80072014_gx {
    u8 pad_0[2];
    u16 unk_2;
};

extern struct fn_80072014_lbl_8019E250 lbl_8019E250[];
extern struct fn_80072014_gx *const gx;

#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
void fn_80072014(fn_80072014_GXColor color) {
    struct fn_80072014_lbl_8019E250 *p;
    u32 g;
    u32 b;
    u32 r;
    u32 reg;
    r = color.r;
    p = lbl_8019E250;
    if (p->fog_b == r && p->fog_g == color.g && p->fog_r == color.b) {
        return;
    }
    b = color.b;
    g = color.g;
    lbl_8019E250[0].fog_r = b;
    reg = __rlwinm(b, 0, 24, 15) | (g << 8);
    reg = __rlwinm(reg, 0, 16, 7) | ((u32)color.r << 16);
    p->fog_b = r;
    lbl_8019E250[0].fog_g = g;
    reg = (reg & 0xFFFFFF) | 0xF2000000;
    lbl_8019E250[0].fog_reg = reg;
    gx->unk_2 = 0;
    GX_WRITE_RAS_REG(reg);
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
