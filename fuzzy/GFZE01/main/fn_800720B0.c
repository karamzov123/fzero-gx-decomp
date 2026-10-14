/* Non-matching: best partial attempt (96.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 gx;

typedef struct State {
    u8 pad0[0x0c];
    u32 count;
    u8 pad1[0x14];
    u32 value;
    u8 pad2[4];
    u32 flags;
} State;

extern State lbl_8019E250;

void fn_800720B0(s32 enable) {
    State *state;
    u32 value;

    if (enable) {
        state = &lbl_8019E250;
        if (state->flags & 1)
            return;
        state->flags |= 1;
        value = state->value;
        if (((value >> 21) & 7) == state->count)
            return;
        value = (value & 0xFF1FFFFF) | (state->count << 21);
        state->value = value;
        // GX FIFO is a memory-mapped hardware register.
        *(volatile u16 *)((u8 *)gx + 2) = 0;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile u32 *)0xCC008000 = value;
    } else {
        state = &lbl_8019E250;
        if (!(state->flags & 1))
            return;
        state->flags &= ~1u;
        value = state->value;
        if (!((value >> 21) & 7))
            return;
        value &= 0xFF1FFFFF;
        state->value = value;
        // GX FIFO is a memory-mapped hardware register.
        *(volatile u16 *)((u8 *)gx + 2) = 0;
        *(volatile u8 *)0xCC008000 = 0x61;
        *(volatile u32 *)0xCC008000 = value;
    }
}
