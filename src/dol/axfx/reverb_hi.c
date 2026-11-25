#include "types.h"
#include <dolphin/os.h>

typedef struct Delay {
    s32 wpos;
    s32 rpos;
    s32 size;
    s32 *buf;
    f32 val;
} Delay;

typedef struct Reverb {
    Delay comb[9];      /* 0x000 */
    Delay ap[9];        /* 0x0B4 */
    f32 room;           /* 0x168 */
    f32 gain[9];        /* 0x16C */
    f32 lp[3];          /* 0x190 */
    f32 mix;            /* 0x19C */
    f32 damp;           /* 0x1A0 */
    s32 preLen;         /* 0x1A4 */
    f32 width;          /* 0x1A8 */
    s32 *preBuf[3];     /* 0x1AC */
    s32 *prePos[3];     /* 0x1B8 */
} Reverb;

extern void *memset(void *, int, u32);
extern s32 lbl_80128160[8];
extern void *(*lbl_801A64F8)(u32);
extern f32 fn_800885B8(f32, f32);

static inline void delay_set(Delay *d, s32 n) {
    d->rpos = d->wpos - n * 4;
    while (d->rpos < 0) {
        d->rpos += d->size;
    }
}

static inline void delay_alloc(Delay *d, s32 n) {
    s32 * fzgx_live;
    d->size = n * 4;
    d->buf = lbl_801A64F8(n * 4);
    fzgx_live = d->buf;
    memset(fzgx_live, 0, n * 4);
    d->val = 0.0f;
    delay_set(d, n >> 1);
}

static inline void delay_init(Delay *d, s32 *len) {
    delay_alloc(d, *len + 2);
    d->wpos = 0;
    d->rpos = 0;
    delay_set(d, *len);
}

s32 fn_80023684(Reverb *r, f32 room, f32 time, f32 mix, f32 damp, f32 pre, f32 width) {
    u8 i;
    Reverb *self;
    u8 j;
    u8 k;
    f32 rate;

    if (room < 0.0f || room > 1.0f || time < 0.01f || time > 10.0f || mix < 0.0f || mix > 1.0f ||
        width < 0.0f || width > 1.0f || damp < 0.0f || damp > 1.0f || pre < 0.0f || pre > 0.1f) {
        return 0;
    }

    memset(r, 0, sizeof(Reverb));
    rate = 32000.0f * time;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            delay_init(&r->ap[i * 3 + j], &lbl_80128160[j]);
            r->gain[i * 3 + j] = fn_800885B8(10.0f, (lbl_80128160[j] * -3) / rate);
        }
        for (j = 0; j < 2; j++) {
            delay_init(&r->comb[i * 3 + j], &lbl_80128160[3 + j]);
        }
        delay_init(&r->comb[i * 3 + 2], &lbl_80128160[5 + i]);
        r->lp[i] = 0.0f;
    }

    r->room = room;
    r->mix = mix;
    r->width = width;
    r->damp = damp;
    if (r->damp < 0.05f) {
        r->damp = 0.05f;
    }
    r->damp = 1.0f - (0.05f + (f32)(0.8f * r->damp));

    if (0.0f != pre) {
        r->preLen = (32000.0f * pre);
        for (k = 0; k < 3; k++) {
            r->preBuf[k] = lbl_801A64F8(r->preLen * 4);
            memset(r->preBuf[k], 0, r->preLen * 4);
            r->prePos[k] = r->preBuf[k];
        }
    } else {
        r->preLen = 0;
        r->prePos[0] = 0;
        r->preBuf[0] = 0;
        r->prePos[1] = 0;
        r->preBuf[1] = 0;
        r->prePos[2] = 0;
        r->preBuf[2] = 0;
    }
    return 1;
}

struct ReverbHiParam {
    Reverb rv;
    u8 active;
    f32 coloration;
    f32 mix;
    f32 time;
    f32 damping;
    f32 predelay;
    f32 crosstalk_param;
};

struct ReverbHiBuf {
    u32 left;
    s32 right;
    u32 surround;
};

extern void (*lbl_801A64FC)(void *);
extern const f64 lbl_801A6FA8;
extern const f32 lbl_801A6FB0;
extern const f32 lbl_801A6FB4;
extern const f32 lbl_801A6FB8;

/* Dolphin SDK axfx/reverb_hi.c: the cross-talk and reverb kernels are CodeWarrior asm
 * functions in the original (hand-scheduled FPR code with their own frames and the 2^52
 * int-to-float bias); the rest is C. */
asm void fn_80023B70(register u32 left, register u32 right, register f32 a, register f32 b) {
    nofralloc
    stwu r1, -0x30(r1)
    stfd f14, 0x28(r1)
    lis r5, lbl_801A6FA8@ha
    lfd f0, lbl_801A6FA8@l(r5)
    lis r5, 0x4330
    stw r5, 0x8(r1)
    stw r5, 0x10(r1)
    stw r5, 0x18(r1)
    stw r5, 0x20(r1)
    ps_merge00 f3, f2, f1
    ps_merge00 f4, f1, f2
    lis r5, lbl_801A6FB0@ha
    lfs f5, lbl_801A6FB0@l(r5)
    li r5, 0x4f
    mtctr r5
    li r10, -0x8
    li r11, -0x4
    ps_muls0 f4, f4, f5
    lwz r6, 0x0(r3)
    lwz r7, 0x0(r4)
    xoris r6, r6, 0x8000
    lwz r8, 0x4(r3)
    xoris r7, r7, 0x8000
    lwz r9, 0x4(r4)
    xoris r8, r8, 0x8000
    stw r6, 0xc(r1)
    xoris r9, r9, 0x8000
    stw r7, 0x14(r1)
    stw r8, 0x1c(r1)
    stw r9, 0x24(r1)
    lfd f5, 0x8(r1)
    lfd f6, 0x10(r1)
    fsubs f5, f5, f0
    lfd f7, 0x18(r1)
    fsubs f6, f6, f0
    lfd f8, 0x20(r1)
    fsubs f7, f7, f0
    fsubs f8, f8, f0
L_80023C08:
    ps_merge00 f9, f5, f6
    lwzu r6, 0x8(r3)
    ps_merge00 f10, f7, f8
    lwzu r7, 0x8(r4)
    xoris r6, r6, 0x8000
    lwz r8, 0x4(r3)
    ps_mul f11, f9, f3
    xoris r7, r7, 0x8000
    ps_mul f12, f9, f4
    lwz r9, 0x4(r4)
    ps_mul f13, f10, f3
    xoris r8, r8, 0x8000
    ps_mul f14, f10, f4
    stw r6, 0xc(r1)
    ps_sum0 f11, f11, f11, f11
    xoris r9, r9, 0x8000
    ps_sum0 f12, f12, f12, f12
    stw r7, 0x14(r1)
    ps_sum0 f13, f13, f13, f13
    stw r8, 0x1c(r1)
    ps_sum0 f14, f14, f14, f14
    stw r9, 0x24(r1)
    fctiw f11, f11
    lfd f5, 0x8(r1)
    fctiw f12, f12
    lfd f6, 0x10(r1)
    fctiw f13, f13
    fsubs f5, f5, f0
    fctiw f14, f14
    lfd f7, 0x18(r1)
    stfiwx f11, r10, r3
    fsubs f6, f6, f0
    stfiwx f12, r10, r4
    lfd f8, 0x20(r1)
    stfiwx f13, r11, r3
    fsubs f7, f7, f0
    stfiwx f14, r11, r4
    fsubs f8, f8, f0
    bdnz L_80023C08
    ps_merge00 f9, f5, f6
    addi r3, r3, 0x8
    ps_merge00 f10, f7, f8
    addi r4, r4, 0x8
    ps_mul f11, f9, f3
    ps_mul f12, f9, f4
    ps_mul f13, f10, f3
    ps_mul f14, f10, f4
    ps_sum0 f11, f11, f11, f11
    ps_sum0 f12, f12, f12, f12
    ps_sum0 f13, f13, f13, f13
    ps_sum0 f14, f14, f14, f14
    fctiw f11, f11
    fctiw f12, f12
    fctiw f13, f13
    fctiw f14, f14
    stfiwx f11, r10, r3
    stfiwx f12, r10, r4
    stfiwx f13, r11, r3
    stfiwx f14, r11, r4
    lfd f14, 0x28(r1)
    addi r1, r1, 0x30
    blr
}

asm void fn_80023D00(register u32 input, register u32 rv, register u32 channel) {
    nofralloc
    stwu r1, -0xc0(r1)
    stmw r14, 0x8(r1)
    stfd f14, 0x60(r1)
    stfd f15, 0x68(r1)
    stfd f16, 0x70(r1)
    stfd f17, 0x78(r1)
    stfd f18, 0x80(r1)
    stfd f19, 0x88(r1)
    stfd f20, 0x90(r1)
    stfd f21, 0x98(r1)
    stfd f22, 0xa0(r1)
    stfd f23, 0xa8(r1)
    stfd f24, 0xb0(r1)
    stfd f25, 0xb8(r1)
    stw r5, 0x50(r1)
    stw r4, 0x54(r1)
    lis r31, lbl_801A6FB4@ha
    lfs f6, lbl_801A6FB4@l(r31)
    lis r31, lbl_801A6FB8@ha
    lfs f9, lbl_801A6FB8@l(r31)
    lis r31, lbl_801A6FA8@ha
    lfd f5, lbl_801A6FA8@l(r31)
    lfs f2, 0x168(r4)
    lfs f15, 0x1a0(r4)
    lfs f8, 0x19c(r4)
    fmuls f3, f8, f9
    fsubs f4, f9, f3
    slwi r30, r5, 1
    add r30, r30, r5
    mulli r31, r30, 0x14
    addi r29, r4, 0xb4
    add r29, r29, r31
    addi r27, r4, 0x0
    add r27, r27, r31
    slwi r31, r30, 2
    add r31, r31, r4
    lfs f22, 0x16c(r31)
    lfs f23, 0x170(r31)
    lfs f24, 0x174(r31)
    slwi r31, r5, 2
    add r31, r31, r4
    lfs f25, 0x190(r31)
    lwz r31, 0x1a4(r4)
    lis r30, 0x4330
    stw r30, 0x58(r1)
    subi r22, r31, 0x1
    slwi r22, r22, 2
    slwi r28, r5, 2
    add r28, r28, r4
    cmpwi cr7, r31, 0x0
    lwz r21, 0x0(r29)
    lwz r20, 0x4(r29)
    lwz r19, 0x14(r29)
    lwz r18, 0x18(r29)
    lwz r17, 0x28(r29)
    lwz r16, 0x2c(r29)
    lfs f16, 0x10(r29)
    lfs f17, 0x24(r29)
    lfs f18, 0x38(r29)
    lwz r25, 0x8(r29)
    lwz r24, 0x1c(r29)
    lwz r23, 0x30(r29)
    lwz r4, 0xc(r29)
    lwz r5, 0x20(r29)
    lwz r6, 0x34(r29)
    lwz r12, 0x0(r27)
    lwz r11, 0x4(r27)
    lwz r10, 0x14(r27)
    lwz r9, 0x18(r27)
    lwz r8, 0x28(r27)
    lwz r7, 0x2c(r27)
    lfs f19, 0x10(r27)
    lfs f20, 0x24(r27)
    lfs f21, 0x38(r27)
    lwz r15, 0x8(r27)
    lwz r14, 0x1c(r27)
    lwz r30, 0x0(r3)
    xoris r30, r30, 0x8000
    stw r30, 0x5c(r1)
    lfd f12, 0x58(r1)
    fsubs f12, f12, f5
    li r31, 0x9f
    mtctr r31
L_80023E4C:
    fmr f13, f12
    beq cr7, L_80023E7C
    lwz r30, 0x1ac(r28)
    lwz r29, 0x1b8(r28)
    add r31, r22, r30
    addi r29, r29, 0x4
    lfs f13, -0x4(r29)
    cmpw r29, r31
    stfs f12, -0x4(r29)
    bne+ L_80023E78
    mr r29, r30
L_80023E78:
    stw r29, 0x1b8(r30)
L_80023E7C:
    fmadds f8, f22, f16, f13
    lwzu r29, 0x4(r3)
    fmadds f9, f23, f17, f13
    stfsx f8, r4, r21
    addi r21, r21, 0x4
    stfsx f9, r5, r19
    lfsx f14, r4, r20
    addi r20, r20, 0x4
    lfsx f17, r5, r18
    cmpw r21, r25
    cmpw cr1, r20, r25
    addi r19, r19, 0x4
    addi r18, r18, 0x4
    fmr f16, f14
    cmpw cr5, r19, r24
    fadds f14, f14, f17
    cmpw cr6, r18, r24
    bne+ L_80023EC8
    li r21, 0x0
L_80023EC8:
    fmadds f8, f24, f18, f13
    bne+ cr1, L_80023ED4
    li r20, 0x0
L_80023ED4:
    stfsx f8, r6, r17
    addi r17, r17, 0x4
    bne+ cr5, L_80023EE4
    li r19, 0x0
L_80023EE4:
    lfsx f18, r6, r16
    addi r16, r16, 0x4
    cmpw r17, r23
    bne+ cr6, L_80023EF8
    li r18, 0x0
L_80023EF8:
    fadds f14, f14, f18
    cmpw cr1, r16, r23
    lwz r26, 0xc(r27)
    fmadds f9, f2, f19, f14
    bne+ L_80023F10
    li r17, 0x0
L_80023F10:
    bne+ cr1, L_80023F18
    li r16, 0x0
L_80023F18:
    xoris r29, r29, 0x8000
    stfsx f9, r26, r12
    fnmsubs f14, f2, f9, f19
    addi r12, r12, 0x4
    lfsx f19, r26, r11
    cmpw cr5, r12, r15
    addi r11, r11, 0x4
    lwz r26, 0x20(r27)
    cmpw cr6, r11, r15
    fmadds f8, f2, f20, f14
    bne+ cr5, L_80023F48
    li r12, 0x0
L_80023F48:
    stw r29, 0x5c(r1)
    stfsx f8, r26, r10
    fnmsubs f14, f2, f8, f20
    addi r10, r10, 0x4
    bne+ cr6, L_80023F60
    li r11, 0x0
L_80023F60:
    lfsx f20, r26, r9
    cmpw r10, r14
    fmuls f14, f14, f6
    addi r9, r9, 0x4
    cmpw cr1, r9, r14
    lfd f10, 0x58(r1)
    fmadds f14, f15, f25, f14
    bne+ L_80023F84
    li r10, 0x0
L_80023F84:
    lwz r26, 0x34(r27)
    fmadds f9, f2, f21, f14
    fmr f25, f14
    bne+ cr1, L_80023F98
    li r9, 0x0
L_80023F98:
    stfsx f9, r26, r8
    fnmsubs f14, f2, f9, f21
    lwz r31, 0x30(r27)
    fmuls f8, f4, f12
    lfsx f21, r26, r7
    addi r8, r8, 0x4
    addi r7, r7, 0x4
    fmadds f14, f3, f14, f8
    cmpw cr5, r8, r31
    cmpw cr6, r7, r31
    fctiwz f14, f14
    bne+ cr5, L_80023FCC
    li r8, 0x0
L_80023FCC:
    bne+ cr6, L_80023FD4
    li r7, 0x0
L_80023FD4:
    li r31, -0x4
    fsubs f12, f10, f5
    stfiwx f14, r3, r31
    bdnz L_80023E4C
    fmr f13, f12
    beq cr7, L_80024014
    lwz r30, 0x1ac(r28)
    lwz r29, 0x1b8(r28)
    add r31, r22, r30
    addi r29, r29, 0x4
    lfs f13, -0x4(r29)
    cmpw r29, r31
    stfs f12, -0x4(r29)
    bne+ L_80024010
    mr r29, r30
L_80024010:
    stw r29, 0x1b8(r30)
L_80024014:
    fmadds f8, f22, f16, f13
    fmadds f9, f23, f17, f13
    stfsx f8, r4, r21
    addi r21, r21, 0x4
    stfsx f9, r5, r19
    lfsx f14, r4, r20
    addi r20, r20, 0x4
    lfsx f17, r5, r18
    cmpw r21, r25
    cmpw cr1, r20, r25
    addi r19, r19, 0x4
    addi r18, r18, 0x4
    fmr f16, f14
    cmpw cr5, r19, r24
    fadds f14, f14, f17
    cmpw cr6, r18, r24
    bne+ L_8002405C
    li r21, 0x0
L_8002405C:
    fmadds f8, f24, f18, f13
    bne+ cr1, L_80024068
    li r20, 0x0
L_80024068:
    stfsx f8, r6, r17
    addi r17, r17, 0x4
    bne+ cr5, L_80024078
    li r19, 0x0
L_80024078:
    lfsx f18, r6, r16
    addi r16, r16, 0x4
    cmpw r17, r23
    bne+ cr6, L_8002408C
    li r18, 0x0
L_8002408C:
    fadds f14, f14, f18
    cmpw cr1, r16, r23
    lwz r26, 0xc(r27)
    fmadds f9, f2, f19, f14
    bne+ L_800240A4
    li r17, 0x0
L_800240A4:
    bne+ cr1, L_800240AC
    li r16, 0x0
L_800240AC:
    stfsx f9, r26, r12
    fnmsubs f14, f2, f9, f19
    addi r12, r12, 0x4
    lfsx f19, r26, r11
    cmpw cr5, r12, r15
    addi r11, r11, 0x4
    lwz r26, 0x20(r27)
    cmpw cr6, r11, r15
    fmadds f8, f2, f20, f14
    bne+ cr5, L_800240D8
    li r12, 0x0
L_800240D8:
    stfsx f8, r26, r10
    fnmsubs f14, f2, f8, f20
    addi r10, r10, 0x4
    bne+ cr6, L_800240EC
    li r11, 0x0
L_800240EC:
    lfsx f20, r26, r9
    cmpw r10, r14
    fmuls f14, f14, f6
    addi r9, r9, 0x4
    cmpw cr1, r9, r14
    fmadds f14, f15, f25, f14
    bne+ L_8002410C
    li r10, 0x0
L_8002410C:
    lwz r26, 0x34(r27)
    lwz r5, 0x50(r1)
    lwz r4, 0x54(r1)
    fmadds f9, f2, f21, f14
    fmr f25, f14
    bne+ cr1, L_80024128
    li r9, 0x0
L_80024128:
    stfsx f9, r26, r8
    fnmsubs f14, f2, f9, f21
    lwz r29, 0x30(r27)
    fmuls f8, f4, f12
    lfsx f21, r26, r7
    addi r8, r8, 0x4
    addi r7, r7, 0x4
    fmadds f14, f3, f14, f8
    cmpw cr5, r8, r29
    cmpw cr6, r7, r29
    fctiwz f14, f14
    bne+ cr5, L_8002415C
    li r8, 0x0
L_8002415C:
    bne+ cr6, L_80024164
    li r7, 0x0
L_80024164:
    slwi r30, r5, 1
    add r30, r30, r5
    mulli r31, r30, 0x14
    stfiwx f14, r0, r3
    addi r29, r4, 0xb4
    add r29, r29, r31
    stw r21, 0x0(r29)
    stw r20, 0x4(r29)
    stw r19, 0x14(r29)
    stw r18, 0x18(r29)
    stw r17, 0x28(r29)
    stw r16, 0x2c(r29)
    stfs f16, 0x10(r29)
    stfs f17, 0x24(r29)
    stfs f18, 0x38(r29)
    stw r12, 0x0(r27)
    stw r11, 0x4(r27)
    stw r10, 0x14(r27)
    stw r9, 0x18(r27)
    stw r8, 0x28(r27)
    stw r7, 0x2c(r27)
    stfs f19, 0x10(r27)
    stfs f20, 0x24(r27)
    stfs f21, 0x38(r27)
    slwi r31, r5, 2
    add r31, r31, r4
    stfs f25, 0x190(r31)
    lfd f14, 0x60(r1)
    lfd f15, 0x68(r1)
    lfd f16, 0x70(r1)
    lfd f17, 0x78(r1)
    lfd f18, 0x80(r1)
    lfd f19, 0x88(r1)
    lfd f20, 0x90(r1)
    lfd f21, 0x98(r1)
    lfd f22, 0xa0(r1)
    lfd f23, 0xa8(r1)
    lfd f24, 0xb0(r1)
    lfd f25, 0xb8(r1)
    lmw r14, 0x8(r1)
    addi r1, r1, 0xc0
    blr
}


#pragma peephole off
void fn_8002420C(Reverb *rv) {
    u8 i;

    for (i = 0; i < 9; i++) {
        lbl_801A64FC(rv->comb[i].buf);
    }

    for (i = 0; i < 9; i++) {
        lbl_801A64FC(rv->ap[i].buf);
    }

    if (rv->preLen != 0) {
        for (i = 0; i < 3; i++) {
            lbl_801A64FC(rv->preBuf[i]);
        }
    }
}

s32 fn_80024308(struct ReverbHiParam *arg0) {
    s32 v1;
    BOOL v0;

    v0 = OSDisableInterrupts();
    arg0->active = 0;
    v1 = fn_80023684(&arg0->rv, arg0->coloration, arg0->time, arg0->mix, arg0->damping, arg0->predelay, arg0->crosstalk_param);
    OSRestoreInterrupts(v0);
    return v1;
}

BOOL fn_80024378(struct ReverbHiParam *arg0) {
    BOOL t0;
    t0 = OSDisableInterrupts();
    fn_8002420C(&arg0->rv);
    OSRestoreInterrupts(t0);
    return 1;
}

#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_800243C4(struct ReverbHiBuf *arg0, struct ReverbHiParam *arg1) {
    u32 i;
    s32 v5;
    s32 v4;
    s32 v3;
    f64 v1;
    f64 v0;
    f64 v2;

    if (!arg1->active) {
        v3 = arg0->surround;
        v4 = arg0->right;
        v5 = arg0->left;

        v1 = (1.0f);
        v0 = (0.5f);
        v2 = (0.0f);
        i = 0;
        while ((((0xFF) & i)) < 3) {
            switch ((((0xFF) & i))) {
            case 0:
                if ((0.0f) != arg1->rv.width) {
                    f32 t = (0.5f) * arg1->rv.width;
                    fn_80023B70(v5, v4, t, (1.0f) - t);
                }
                fn_80023D00(v5, (u32)arg1, 0);
                break;
            case 1:
                fn_80023D00(v4, (u32)arg1, 1);
                break;
            case 2:
                fn_80023D00(v3, (u32)arg1, 2);
                break;
            }
            i++;
        }
    }
}
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
#pragma peephole reset
