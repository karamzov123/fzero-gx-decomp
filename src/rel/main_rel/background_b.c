#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/background.h"

/* fzgx:begin fn_1_9DDA8 */
#include "dolphin/hw_regs.h"
#include "dolphin/hw_regs.h"

/* begin game/main_rel/background_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BACKGROUND_TYPES_H
#define GAME_MAIN_REL_BACKGROUND_TYPES_H

// Types (and the externs that name them) of background.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    s32 type;     /* 0: constant, 1: linear, else: hermite */
    f32 time;
    f32 value;
    f32 tanIn;
    f32 tanOut;
} CurveKey;


#endif  // GAME_MAIN_REL_BACKGROUND_TYPES_H

/* end game/main_rel/background_types.h */

/* Evaluate a keyframe curve at time t; derivative != 0 returns the slope. */
f32 fn_1_9DDA8(s32 count, BackgroundCurveKey *keys, s32 derivative, f32 t) {
    BackgroundCurveKey *p;
    s32 i;
    f32 a, dt, d, m0, m1, u, s, u2, u3, w, b, e;
    f64 lin;

    if (count < 2 || t <= keys[0].time) {
        if (derivative) {
            return keys[0].tanOut;
        }
        return keys[0].value;
    }
    if (t >= keys[count - 1].time) {
        if (derivative) {
            return keys[count - 1].tanIn;
        }
        return keys[count - 1].value;
    }

    count--;
    keys++;
    for (i = 1; i < count; i++) {
        if (keys->time > t) {
            break;
        }
        keys++;
    }
    p = keys - 1;

    if (derivative) {
        switch (p->type) {
        case 0:
            return 0.0f;
        case 1:
            return keys->value - p->value;
        default:
            a = t - p->time;
            dt = keys->time - p->time;
            d = p->value - keys->value;
            m0 = (dt * p->tanOut);
            u = a / dt;
            s = m0 + (dt * keys->tanIn);
            return m0 + (((u * u) * (((2.0f * d) + s) / 3.0f))
                         - (u * ((m0 + ((3.0f * d) + s)) / 2.0f)));
        }
    } else {
        switch (p->type) {
        case 0:
            return p->value;
        case 1:
            dt = keys->time - p->time;
            a = t - p->time;
            u = a / dt;
            lin = p->value * (1.0 - u);
            return lin + (keys->value * u);
        default:
            a = t - p->time;
            dt = keys->time - p->time;
            u = a / dt;
            u2 = (u * u);
            u3 = (u2 * u);
            w = u3 - u2;
            e = (2.0f * w) - u2;
            b = u + (w - u2);
            return (((1.0f + e) * p->value) - (e * keys->value))
                   + (dt * ((p->tanOut * b) + (w * keys->tanIn)));
        }
    }
}
/* fzgx:end fn_1_9DDA8 */

/* fzgx:begin fn_1_9DFB8 */
/* Original assembly (CodeWarrior asm function): cached keyframe curve evaluator over 20-byte
 * keys (docs/findings/gfze01-main-rel-assembly-frontier.md): static branch hints, self-XOR zeroing,
 * locked-cache constant loads through the clobbered derivative register and a dead duplicate branch
 * after the loop, none of which MWCC emits. */
asm f32 fn_1_9DFB8(register s32 count, register const BackgroundCurveKey *keys, register s32 *cursor, register s32 derivative, register f32 t) {
    nofralloc
    subic. r7, r3, 0x2
    blt L_0009E130
    lfs f2, 0x4(r4)
    fcmpo cr0, f1, f2
    ble L_0009E130
    mulli r8, r3, 0x14
    subi r8, r8, 0x14
    add r8, r4, r8
    lfs f2, 0x4(r8)
    fcmpo cr0, f1, f2
    bge L_0009E124
    lwz r9, 0x0(r5)
    cmpwi r9, 0x0
    bgt+ L_0009DFF8
    xor r9, r9, r9
    b L_0009E004
L_0009DFF8:
    cmpw r9, r7
    blt+ L_0009E004
    mr r9, r7
L_0009E004:
    mulli r8, r9, 0x14
    add r4, r4, r8
    lfs f2, 0x4(r4)
    fcmpo cr0, f2, f1
    bgt L_0009E05C
    subi r3, r3, 0x1
    b L_0009E02C
L_0009E020:
    lfs f2, 0x4(r4)
    fcmpo cr0, f2, f1
    bgt+ L_0009E03C
L_0009E02C:
    addi r4, r4, 0x14
    addi r9, r9, 0x1
    cmpw r9, r3
    blt L_0009E020
L_0009E03C:
    subi r7, r4, 0x14
    subi r9, r9, 0x1
    stw r9, 0x0(r5)
    b L_0009E074
    b L_0009E05C
L_0009E050:
    lfs f2, 0x4(r4)
    fcmpo cr0, f2, f1
    ble+ L_0009E068
L_0009E05C:
    subi r4, r4, 0x14
    subic. r9, r9, 0x1
    bge L_0009E050
L_0009E068:
    mr r7, r4
    addi r4, r4, 0x14
    stw r9, 0x0(r5)
L_0009E074:
    lis r6, 0xe000
    lwz r5, 0x0(r7)
    cmpwi r5, 0x0
    bne+ L_0009E08C
    lfs f1, 0x8(r7)
    blr
L_0009E08C:
    cmpwi r5, 0x1
    bne+ L_0009E0C4
    lfs f2, 0x4(r4)
    lfs f9, 0x4(r7)
    fsubs f2, f2, f9
    fsubs f3, f1, f9
    fdivs f3, f3, f2
    lfs f1, 0x8(r7)
    lfs f9, 0x19c(r6)
    fsubs f9, f9, f3
    lfs f4, 0x8(r4)
    fmuls f4, f4, f3
    fmadds f1, f1, f9, f4
    blr
L_0009E0C4:
    lfs f2, 0x4(r4)
    lfs f9, 0x4(r7)
    fsubs f2, f2, f9
    fsubs f1, f1, f9
    lfs f10, 0xc(r4)
    fdivs f3, f1, f2
    fmuls f4, f3, f3
    lfs f1, 0x8(r7)
    fmuls f5, f3, f4
    lfs f9, 0x19c(r6)
    fsubs f6, f5, f4
    fadds f5, f9, f9
    fmsubs f7, f5, f6, f4
    lfs f5, 0x8(r4)
    fmuls f5, f7, f5
    fadds f7, f7, f9
    fmsubs f1, f1, f7, f5
    fsubs f4, f6, f4
    fadds f4, f4, f3
    lfs f9, 0x10(r7)
    fmuls f6, f6, f10
    fmadds f9, f9, f4, f6
    fmadds f1, f9, f2, f1
    blr
L_0009E124:
    mr r4, r8
    lfs f1, 0xc(r4)
    b L_0009E138
L_0009E130:
    xor r7, r7, r7
    lfs f1, 0x10(r4)
L_0009E138:
    stw r7, 0x0(r5)
    cmpwi r6, 0x0
    bgtlr
    lfs f1, 0x8(r4)
    blr
}
/* fzgx:end fn_1_9DFB8 */
