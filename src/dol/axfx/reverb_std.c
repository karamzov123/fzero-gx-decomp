#include "types.h"
#include <dolphin/os.h>

typedef struct Fn800244C8_DelayLine {
    s32 in_point;
    s32 out_point;
    s32 length;
    f32 *inputs;
    f32 last_output;
} Fn800244C8_DelayLine;

typedef struct Fn800244C8_ReverbStd {
    Fn800244C8_DelayLine all_pass[6];
    Fn800244C8_DelayLine comb[6];
    f32 all_pass_coef;
    f32 comb_coef[6];
    f32 lp_last_out[3];
    f32 level;
    f32 damping;
    s32 pre_delay_time;
    f32 *pre_delay_line[3];
    f32 *pre_delay_ptr[3];
} Fn800244C8_ReverbStd;

extern void *memset(void *, int, u32);
extern void *(*lbl_801A64F8)(u32);
extern f32 fn_800885B8(f32 x, f32 y);
extern u32 lbl_80128180[4];

static inline void fn_800244C8_SetDelay(Fn800244C8_DelayLine *dl, s32 lag) {
    dl->out_point = dl->in_point - lag * sizeof(f32);
    while (dl->out_point < 0) {
        dl->out_point += dl->length;
    }
}

static inline void fn_800244C8_Create(Fn800244C8_DelayLine *dl, s32 len) {
    dl->length = len * sizeof(f32);
    dl->inputs = lbl_801A64F8(len * sizeof(f32));
    memset(dl->inputs, 0, len * sizeof(f32));
    dl->last_output = 0.0f;
    fn_800244C8_SetDelay(dl, len >> 1);
    dl->in_point = 0;
    dl->out_point = 0;
}

BOOL fn_800244C8(Fn800244C8_ReverbStd *rv, f32 coloration, f32 time, f32 mix, f32 damping, f32 predelay) {
    u8 i;
    u8 k;

    if (coloration < 0.0f || coloration > 1.0f || time < 0.01f || time > 10.0f || mix < 0.0f || mix > 1.0f ||
        damping < 0.0f || damping > 1.0f || predelay < 0.0f || predelay > 0.1f) {
        return FALSE;
    }

    memset(rv, 0, sizeof(Fn800244C8_ReverbStd));
    for (k = 0; k < 3; k++) {
        for (i = 0; i < 2; i++) {
            fn_800244C8_Create(&rv->comb[i + k * 2], lbl_80128180[i] + 2);
            fn_800244C8_SetDelay(&rv->comb[i + k * 2], lbl_80128180[i]);
            rv->comb_coef[i + k * 2] = fn_800885B8(10.0f, (s32)(lbl_80128180[i] * -3) / (32000.0f * time));
        }
        for (i = 0; i < 2; i++) {
            fn_800244C8_Create(&rv->all_pass[i + k * 2], lbl_80128180[i + 2] + 2);
            fn_800244C8_SetDelay(&rv->all_pass[i + k * 2], lbl_80128180[i + 2]);
        }
        rv->lp_last_out[k] = 0.0f;
    }

    rv->all_pass_coef = coloration;
    rv->level = mix;
    rv->damping = damping;
    if (rv->damping < 0.05f) {
        rv->damping = 0.05f;
    }
    rv->damping = 1.0f - (0.05f + 0.8f * rv->damping);

    if (predelay != 0.0f) {
        rv->pre_delay_time = 32000.0f * predelay;
        for (k = 0; k < 3; k++) {
            rv->pre_delay_line[k] = lbl_801A64F8(rv->pre_delay_time << 2);
            memset(rv->pre_delay_line[k], 0, rv->pre_delay_time << 2);
            rv->pre_delay_ptr[k] = rv->pre_delay_line[k];
        }
    } else {
        rv->pre_delay_time = 0;
        for (k = 0; k < 3; k++) {
            rv->pre_delay_ptr[k] = NULL;
            rv->pre_delay_line[k] = NULL;
        }
    }
    return TRUE;
}

typedef struct Fn80024D84_ReverbStdParam {
    Fn800244C8_ReverbStd rv;
    u8 active;
    f32 coloration;
    f32 mix;
    f32 time;
    f32 damping;
    f32 predelay;
} Fn80024D84_ReverbStdParam;

extern void (*lbl_801A64FC)(void *);
extern const f32 lbl_801A6FE8;
extern const f32 lbl_801A6FEC;
extern const f64 lbl_801A6FF0;

/* Dolphin SDK axfx/reverb_std.c: the per-frame reverb kernel is a CodeWarrior asm function
 * in the original (hand-scheduled FPR code with its own stmw/stfd frame and the 2^52
 * int-to-float bias); the rest is C. */
asm void fn_800248D4(register s32 *input, register Fn800244C8_ReverbStd *rv) {
    nofralloc
    stwu r1, -0x90(r1)
    stmw r17, 0x8(r1)
    stfd f14, 0x58(r1)
    stfd f15, 0x60(r1)
    stfd f16, 0x68(r1)
    stfd f17, 0x70(r1)
    stfd f18, 0x78(r1)
    stfd f19, 0x80(r1)
    stfd f20, 0x88(r1)
    lis r31, lbl_801A6FE8@ha
    lfs f6, lbl_801A6FE8@l(r31)
    lis r31, lbl_801A6FEC@ha
    lfs f9, lbl_801A6FEC@l(r31)
    lis r31, lbl_801A6FF0@ha
    lfd f5, lbl_801A6FF0@l(r31)
    lfs f2, 0xf0(r4)
    lfs f11, 0x11c(r4)
    lfs f8, 0x118(r4)
    fmuls f3, f8, f9
    fsubs f4, f9, f3
    lis r30, 0x4330
    stw r30, 0x50(r1)
    li r5, 0x0
L_80024930:
    slwi r31, r5, 3
    add r31, r31, r4
    lfs f19, 0xf4(r31)
    lfs f20, 0xf8(r31)
    slwi r31, r5, 2
    add r31, r31, r4
    lfs f7, 0x10c(r31)
    lwz r27, 0x124(r31)
    lwz r28, 0x130(r31)
    lwz r31, 0x120(r4)
    subi r22, r31, 0x1
    slwi r22, r22, 2
    add r22, r22, r27
    cmpwi cr7, r31, 0x0
    mulli r31, r5, 0x28
    addi r29, r4, 0x78
    add r29, r29, r31
    addi r30, r4, 0x0
    add r30, r30, r31
    lwz r21, 0x0(r29)
    lwz r20, 0x4(r29)
    lwz r19, 0x14(r29)
    lwz r18, 0x18(r29)
    lfs f15, 0x10(r29)
    lfs f16, 0x24(r29)
    lwz r26, 0x8(r29)
    lwz r25, 0x1c(r29)
    lwz r7, 0xc(r29)
    lwz r8, 0x20(r29)
    lwz r12, 0x0(r30)
    lwz r11, 0x4(r30)
    lwz r10, 0x14(r30)
    lwz r9, 0x18(r30)
    lfs f17, 0x10(r30)
    lfs f18, 0x24(r30)
    lwz r24, 0x8(r30)
    lwz r23, 0x1c(r30)
    lwz r17, 0xc(r30)
    lwz r6, 0x20(r30)
    lwz r30, 0x0(r3)
    xoris r30, r30, 0x8000
    stw r30, 0x54(r1)
    lfd f12, 0x50(r1)
    fsubs f12, f12, f5
    li r31, 0x9f
    mtctr r31
L_800249E8:
    fmr f13, f12
    beq cr7, L_80024A08
    lfs f13, 0x0(r28)
    addi r28, r28, 0x4
    cmpw r28, r22
    stfs f12, -0x4(r28)
    bne+ L_80024A08
    mr r28, r27
L_80024A08:
    fmadds f8, f19, f15, f13
    lwzu r29, 0x4(r3)
    fmadds f9, f20, f16, f13
    stfsx f8, r7, r21
    addi r21, r21, 0x4
    stfsx f9, r8, r19
    lfsx f14, r7, r20
    addi r20, r20, 0x4
    lfsx f16, r8, r18
    cmpw r21, r26
    cmpw cr1, r20, r26
    addi r19, r19, 0x4
    addi r18, r18, 0x4
    fmr f15, f14
    cmpw cr5, r19, r25
    fadds f14, f14, f16
    cmpw cr6, r18, r25
    bne+ L_80024A54
    li r21, 0x0
L_80024A54:
    xoris r29, r29, 0x8000
    fmadds f9, f2, f17, f14
    bne+ cr1, L_80024A64
    li r20, 0x0
L_80024A64:
    stw r29, 0x54(r1)
    bne+ cr5, L_80024A70
    li r19, 0x0
L_80024A70:
    stfsx f9, r17, r12
    fnmsubs f14, f2, f9, f17
    addi r12, r12, 0x4
    bne+ cr6, L_80024A84
    li r18, 0x0
L_80024A84:
    lfsx f17, r17, r11
    cmpw cr5, r12, r24
    addi r11, r11, 0x4
    cmpw cr6, r11, r24
    bne+ cr5, L_80024A9C
    li r12, 0x0
L_80024A9C:
    bne+ cr6, L_80024AA4
    li r11, 0x0
L_80024AA4:
    fmuls f14, f14, f6
    lfd f10, 0x50(r1)
    fmadds f14, f11, f7, f14
    fmadds f9, f2, f18, f14
    fmr f7, f14
    stfsx f9, r6, r10
    fnmsubs f14, f2, f9, f18
    fmuls f8, f4, f12
    lfsx f18, r6, r9
    addi r10, r10, 0x4
    addi r9, r9, 0x4
    fmadds f14, f3, f14, f8
    cmpw cr5, r10, r23
    cmpw cr6, r9, r23
    fctiwz f14, f14
    bne+ cr5, L_80024AE8
    li r10, 0x0
L_80024AE8:
    bne+ cr6, L_80024AF0
    li r9, 0x0
L_80024AF0:
    li r31, -0x4
    fsubs f12, f10, f5
    stfiwx f14, r3, r31
    bdnz L_800249E8
    fmr f13, f12
    beq cr7, L_80024B20
    lfs f13, 0x0(r28)
    addi r28, r28, 0x4
    cmpw r28, r22
    stfs f12, -0x4(r28)
    bne+ L_80024B20
    mr r28, r27
L_80024B20:
    fmadds f8, f19, f15, f13
    fmadds f9, f20, f16, f13
    stfsx f8, r7, r21
    addi r21, r21, 0x4
    stfsx f9, r8, r19
    lfsx f14, r7, r20
    addi r20, r20, 0x4
    lfsx f16, r8, r18
    cmpw r21, r26
    cmpw cr1, r20, r26
    addi r19, r19, 0x4
    addi r18, r18, 0x4
    fmr f15, f14
    cmpw cr5, r19, r25
    fadds f14, f14, f16
    cmpw cr6, r18, r25
    bne+ L_80024B68
    li r21, 0x0
L_80024B68:
    fmadds f9, f2, f17, f14
    bne+ cr1, L_80024B74
    li r20, 0x0
L_80024B74:
    bne+ cr5, L_80024B7C
    li r19, 0x0
L_80024B7C:
    stfsx f9, r17, r12
    fnmsubs f14, f2, f9, f17
    addi r12, r12, 0x4
    bne+ cr6, L_80024B90
    li r18, 0x0
L_80024B90:
    lfsx f17, r17, r11
    cmpw cr5, r12, r24
    addi r11, r11, 0x4
    cmpw cr6, r11, r24
    bne+ cr5, L_80024BA8
    li r12, 0x0
L_80024BA8:
    bne+ cr6, L_80024BB0
    li r11, 0x0
L_80024BB0:
    fmuls f14, f14, f6
    fmadds f14, f11, f7, f14
    mulli r31, r5, 0x28
    fmadds f9, f2, f18, f14
    fmr f7, f14
    addi r29, r4, 0x78
    add r29, r29, r31
    stfsx f9, r6, r10
    fnmsubs f14, f2, f9, f18
    fmuls f8, f4, f12
    lfsx f18, r6, r9
    addi r10, r10, 0x4
    addi r9, r9, 0x4
    fmadds f14, f3, f14, f8
    cmpw cr5, r10, r23
    cmpw cr6, r9, r23
    fctiwz f14, f14
    bne+ cr5, L_80024BFC
    li r10, 0x0
L_80024BFC:
    bne+ cr6, L_80024C04
    li r9, 0x0
L_80024C04:
    addi r30, r4, 0x0
    add r30, r30, r31
    stfiwx f14, r0, r3
    stw r21, 0x0(r29)
    stw r20, 0x4(r29)
    stw r19, 0x14(r29)
    stw r18, 0x18(r29)
    addi r3, r3, 0x4
    stfs f15, 0x10(r29)
    stfs f16, 0x24(r29)
    slwi r31, r5, 2
    add r31, r31, r4
    addi r5, r5, 0x1
    stw r12, 0x0(r30)
    stw r11, 0x4(r30)
    stw r10, 0x14(r30)
    stw r9, 0x18(r30)
    cmpwi r5, 0x3
    stfs f17, 0x10(r30)
    stfs f18, 0x24(r30)
    stfs f7, 0x10c(r31)
    stw r28, 0x130(r31)
    bne L_80024930
    lfd f14, 0x58(r1)
    lfd f15, 0x60(r1)
    lfd f16, 0x68(r1)
    lfd f17, 0x70(r1)
    lfd f18, 0x78(r1)
    lfd f19, 0x80(r1)
    lfd f20, 0x88(r1)
    lmw r17, 0x8(r1)
    addi r1, r1, 0x90
    blr
}

#pragma peephole off
void fn_80024C88(Fn800244C8_ReverbStd *rv) {
    u8 i;

    for (i = 0; i < 6; i++) {
        lbl_801A64FC(rv->all_pass[i].inputs);
    }
    for (i = 0; i < 6; i++) {
        lbl_801A64FC(rv->comb[i].inputs);
    }
    if (rv->pre_delay_time != 0) {
        for (i = 0; i < 3; i++) {
            lbl_801A64FC(rv->pre_delay_line[i]);
        }
    }
}

BOOL fn_80024D84(Fn80024D84_ReverbStdParam *reverb) {
    BOOL result;
    BOOL old;

    old = OSDisableInterrupts();
    reverb->active = 0;
    result = fn_800244C8(&reverb->rv, reverb->coloration, reverb->time, reverb->mix, reverb->damping, reverb->predelay);
    OSRestoreInterrupts(old);
    return result;
}

BOOL fn_80024DF0(Fn80024D84_ReverbStdParam *reverb) {
    BOOL old;
    old = OSDisableInterrupts();
    fn_80024C88(&reverb->rv);
    OSRestoreInterrupts(old);
    return TRUE;
}
#pragma peephole reset

void fn_80024E3C(s32 **buffer, Fn80024D84_ReverbStdParam *reverb) {
    if (reverb->active == 0) {
        fn_800248D4(*buffer, &reverb->rv);
    }
}
