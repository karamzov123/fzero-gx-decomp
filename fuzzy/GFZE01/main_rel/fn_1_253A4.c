/* Non-matching: best partial attempt (98.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

extern f32 lbl_1_rodata_840[3];

typedef struct {
    u32 flags;
    u8 pad4[0x10];
    f32 base;
    f32 scale;
    u8 pad1c[0x88];
    f32 velocity;
    u8 pada8[0x150];
    f32 factor;
    f32 force;
    u8 pad200[0xc];
    f32 previous_force;
    u8 pad210[0x34];
    u32 flags244;
    u8 pad248[0x58];
    u32 flags2a0;
    u8 pad2a4[0x58];
    u32 flags2fc;
    u8 pad300[0x58];
    u32 flags358;
} ForceState;

#define POOL_F(off) (*(f32 *)((u8 *)lbl_1_rodata_840 + (off)))
#define POOL_D(off) (*(f32 *)((u8 *)lbl_1_rodata_840 + (off)))

static inline f32 fn_1_253A4_operand(f32 right, f32 left) { left *= right; return left; }
static inline f32 fn_1_253A4_operand_(f32 right, f32 left) { return left * right; }
f32 fn_1_253A4(ForceState *state)
{
    int i;
    f32 product;
    f32 negative_force;
    f32 result;
    struct {
    u8 lab_pad[4]; f32 value; } strength;
    const u8 *pool = (const u8 *)lbl_1_rodata_840;
    u32 flags = state->flags;
#undef POOL_F
#undef POOL_D
#define POOL_F(off) (*(const f32 *)(pool + (off)))
#define POOL_D(off) (*(const f64 *)(pool + (off)))
    if (!(flags & 0x400)) {
        return POOL_F(0xc);
    }
    strength.value = POOL_F(0x14);
    {
        f32 decrement = POOL_F(0x60);
        for (i = 0; i < 4; i++) {
            if (*(u32 *)((u8 *)state + 0x244 + i * 0x5c) & 4)
                strength.value -= decrement;
        }
    }
{
    f32 force;
    force = state->force;
    negative_force = -force;
    product = fn_1_253A4_operand_((force), (state->factor));
    product = state->scale * product;
    strength.value = strength.value * product;
    result = fn_1_253A4_operand((negative_force), ((state->base + strength.value)));
    if (flags & 0x20000) result *= POOL_F(0x130);
    {
        f32 delta = POOL_F(0x84) * result;
        f64 threshold = POOL_D(0x180);
        state->velocity = state->velocity + delta;
        if (__fabs(state->velocity) < threshold) state->velocity = POOL_F(0xc);
    }
    state->previous_force = state->force;
}
    return result;
}
