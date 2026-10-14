/* Non-matching: best partial attempt (98.24% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_8019E250[];
struct GXState { u16 pad; u16 bpSent; };
extern struct GXState *gx;

static inline u32 fn_80072168_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_propagation off
void fn_80072168(s32 arg0) {
    u32 fzgx_value_;
    u16 *fzgx_value;
    u32 value;
    u32 level;
    if (!(fn_80072168_array_read(lbl_8019E250, 11) & 1)) return;
    if (arg0) {
        value = fn_80072168_array_read(lbl_8019E250, 9);
        level = fn_80072168_array_read(lbl_8019E250, 3);
        if (((value >> 21) & 7) == level) return;
        value = (value & ~0x00E00000) | (level << 21);
        lbl_8019E250[9] = value;
        fzgx_value_ = (u16)(0);
        gx->bpSent = fzgx_value_;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile u32 *)0xCC008000 = value;
    } else {
        value = fn_80072168_array_read(lbl_8019E250, 9);
        if (!((value >> 21) & 7)) return;
        value &= ~0x00E00000;
        lbl_8019E250[9] = value;
        fzgx_value = &(gx->bpSent);
        *fzgx_value = 0;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile u32 *)0xCC008000 = value;
    }
}
#pragma opt_propagation reset

