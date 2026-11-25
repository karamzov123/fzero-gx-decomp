#include "types.h"

typedef struct AXFXChorusSrc {
    u32 *unk_0;
    u32 *unk_4;
    u32 *unk_8;
} AXFXChorusSrc;

typedef struct AXFXChorus {
    s32 *lastLeft[3];
    s32 *lastRight[3];
    s32 *lastSur[3];
    u8 currentLast;
    u8 pad_25[3];
    s32 oldLeft[4];
    s32 oldRight[4];
    s32 oldSur[4];
    u32 unk_58;
    u32 unk_5c;
    s32 unk_60;
    u32 unk_64;
    u32 unk_68;
    u32 *unk_6c;
    u32 *unk_70;
    void *unk_74;
    u32 unk_78;
    u32 unk_7c;
    u32 unk_80;
    s32 unk_84;
    u32 trigger;
    u32 target;
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
} AXFXChorus;

extern void *(*lbl_801A64F8)(u32);
extern u32 (*lbl_801A64FC)(void *);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern const f64 lbl_801A6FF8;
extern f32 lbl_80128190[];

/* Dolphin SDK axfx/chorus.c: the two delay-line resampling kernels are CodeWarrior asm
 * functions in the original (hand-scheduled FPR code with their own frames and the 2^52
 * int-to-float bias); the rest is C. */
asm void fn_80024E6C(register void *info) {
    nofralloc
    stwu r1, -0x40(r1)
    stmw r26, 0x28(r1)
    lwz r4, 0xc(r3)
    lwz r5, 0x10(r3)
    lwz r6, 0x14(r3)
    lwz r8, 0x1c(r3)
    lwz r7, 0x20(r3)
    lwz r31, 0x4(r3)
    lwz r30, 0x0(r3)
    lwz r9, 0x8(r3)
    lis r10, 0x4330
    stw r10, 0x8(r1)
    stw r10, 0x10(r1)
    stw r10, 0x18(r1)
    stw r10, 0x20(r1)
    lis r10, lbl_801A6FF8@ha
    lfd f9, lbl_801A6FF8@l(r10)
    slwi r10, r5, 2
    lwz r11, 0x0(r9)
    lwz r29, 0x4(r9)
    lwz r28, 0x8(r9)
    lwzx r27, r31, r10
    xoris r11, r11, 0x8000
    xoris r29, r29, 0x8000
    stw r11, 0xc(r1)
    xoris r28, r28, 0x8000
    stw r29, 0x14(r1)
    xoris r27, r27, 0x8000
    stw r28, 0x1c(r1)
    lfd f1, 0x8(r1)
    stw r27, 0x24(r1)
    lfd f2, 0x10(r1)
    fsubs f1, f1, f9
    lfd f3, 0x18(r1)
    fsubs f2, f2, f9
    lfd f4, 0x20(r1)
    fsubs f3, f3, f9
    fsubs f4, f4, f9
    li r26, -0x4
    lis r12, lbl_80128190@ha
    addi r12, r12, lbl_80128190@l
    li r9, 0xa0
    mtctr r9
L_80024F18:
    rlwinm r10, r4, 7, 21, 27
    addc r4, r4, r6
    add r10, r10, r12
    mcrxr cr0
    lfs f5, 0x0(r10)
    beq L_80024F60
    lfs f6, 0x4(r10)
    fmuls f10, f1, f5
    lfs f7, 0x8(r10)
    fmadds f10, f2, f6, f10
    lfs f8, 0xc(r10)
    fmadds f10, f3, f7, f10
    addi r30, r30, 0x4
    fmadds f10, f4, f8, f10
    fctiwz f10, f10
    stfiwx f10, r26, r30
    bdnz L_80024F18
    b L_80024FCC
L_80024F60:
    addi r5, r5, 0x1
    lfs f6, 0x4(r10)
    fmuls f10, f1, f5
    cmpw r5, r8
    fmr f1, f2
    lfs f7, 0x8(r10)
    fmadds f10, f2, f6, f10
    fmr f2, f3
    lfs f8, 0xc(r10)
    fmadds f10, f3, f7, f10
    addi r30, r30, 0x4
    fmr f3, f4
    bne+ L_80024F98
    mr r5, r7
L_80024F98:
    fmadds f10, f4, f8, f10
    slwi r9, r5, 2
    bdz L_80024FC4
    lwzx r10, r9, r31
    fctiwz f10, f10
    xoris r10, r10, 0x8000
    stw r10, 0xc(r1)
    stfiwx f10, r26, r30
    lfd f4, 0x8(r1)
    fsubs f4, f4, f9
    b L_80024F18
L_80024FC4:
    fctiwz f10, f10
    stfiwx f10, r26, r30
L_80024FCC:
    lwz r9, 0x8(r3)
    fctiwz f1, f1
    fctiwz f2, f2
    fctiwz f3, f3
    stfiwx f1, r0, r9
    addi r10, r9, 0x4
    stfiwx f2, r0, r10
    addi r10, r9, 0x8
    stfiwx f3, r0, r10
    stw r4, 0xc(r3)
    stw r5, 0x10(r3)
    lmw r26, 0x28(r1)
    addi r1, r1, 0x40
    blr
}

asm void fn_80025004(register void *info) {
    nofralloc
    stwu r1, -0x40(r1)
    stmw r26, 0x28(r1)
    lwz r4, 0xc(r3)
    lwz r5, 0x10(r3)
    lwz r6, 0x14(r3)
    lwz r8, 0x1c(r3)
    lwz r7, 0x20(r3)
    lwz r31, 0x4(r3)
    lwz r30, 0x0(r3)
    lwz r9, 0x8(r3)
    lis r10, 0x4330
    stw r10, 0x8(r1)
    stw r10, 0x10(r1)
    stw r10, 0x18(r1)
    stw r10, 0x20(r1)
    lis r10, lbl_801A6FF8@ha
    lfd f9, lbl_801A6FF8@l(r10)
    slwi r10, r5, 2
    lwz r11, 0x0(r9)
    lwz r29, 0x4(r9)
    lwz r28, 0x8(r9)
    lwzx r27, r31, r10
    xoris r11, r11, 0x8000
    xoris r29, r29, 0x8000
    stw r11, 0xc(r1)
    xoris r28, r28, 0x8000
    stw r29, 0x14(r1)
    xoris r27, r27, 0x8000
    stw r28, 0x1c(r1)
    lfd f1, 0x8(r1)
    stw r27, 0x24(r1)
    lfd f2, 0x10(r1)
    fsubs f1, f1, f9
    lfd f3, 0x18(r1)
    fsubs f2, f2, f9
    lfd f4, 0x20(r1)
    fsubs f3, f3, f9
    fsubs f4, f4, f9
    li r26, -0x4
    lis r12, lbl_80128190@ha
    addi r12, r12, lbl_80128190@l
    li r9, 0xa0
    mtctr r9
L_800250B0:
    rlwinm r10, r4, 7, 21, 27
    addc r4, r4, r6
    add r10, r10, r12
    mcrxr cr0
    addi r5, r5, 0x1
    lfs f5, 0x0(r10)
    beq L_8002512C
    lfs f6, 0x4(r10)
    fmuls f10, f1, f5
    cmpw r5, r8
    fmr f1, f2
    lfs f7, 0x8(r10)
    fmadds f10, f2, f6, f10
    fmr f2, f3
    lfs f8, 0xc(r10)
    fmadds f10, f3, f7, f10
    addi r30, r30, 0x4
    fmr f3, f4
    bne+ L_80025100
    mr r5, r7
L_80025100:
    fmadds f10, f4, f8, f10
    slwi r9, r5, 2
    bdz L_800251B0
    lwzx r10, r9, r31
    fctiwz f10, f10
    xoris r10, r10, 0x8000
    stw r10, 0xc(r1)
    stfiwx f10, r26, r30
    lfd f4, 0x8(r1)
    fsubs f4, f4, f9
    b L_800250B0
L_8002512C:
    cmpw r5, r8
    lfs f6, 0x4(r10)
    bne+ L_8002513C
    mr r5, r7
L_8002513C:
    slwi r11, r5, 2
    addi r5, r5, 0x1
    lwzx r29, r11, r31
    fmuls f10, f1, f5
    cmpw r5, r8
    xoris r29, r29, 0x8000
    fmr f1, f3
    lfs f7, 0x8(r10)
    stw r29, 0xc(r1)
    fmadds f10, f2, f6, f10
    lfs f8, 0xc(r10)
    fmadds f10, f3, f7, f10
    lfd f3, 0x8(r1)
    fmr f2, f4
    addi r30, r30, 0x4
    fsubs f3, f3, f9
    bne+ L_80025184
    mr r5, r7
L_80025184:
    fmadds f10, f4, f8, f10
    slwi r9, r5, 2
    bdz L_800251B0
    lwzx r10, r9, r31
    fctiwz f10, f10
    xoris r10, r10, 0x8000
    stw r10, 0xc(r1)
    stfiwx f10, r26, r30
    lfd f4, 0x8(r1)
    fsubs f4, f4, f9
    b L_800250B0
L_800251B0:
    fctiwz f10, f10
    stfiwx f10, r26, r30
    lwz r9, 0x8(r3)
    fctiwz f1, f1
    fctiwz f2, f2
    fctiwz f3, f3
    stfiwx f1, r0, r9
    addi r10, r9, 0x4
    stfiwx f2, r0, r10
    addi r10, r9, 0x8
    stfiwx f3, r0, r10
    stw r4, 0xc(r3)
    stw r5, 0x10(r3)
    lmw r26, 0x28(r1)
    addi r1, r1, 0x40
    blr
}

u32 fn_80025440(AXFXChorus *arg0);

s32 fn_800251F0(AXFXChorus *c) {
    s32 *left;
    s32 *right;
    s32 *sur;
    u32 i;
    BOOL old;

    old = OSDisableInterrupts();
    c->lastLeft[0] = lbl_801A64F8(0x1680);
    if (c->lastLeft[0] != NULL) {
        c->lastRight[0] = c->lastLeft[0] + 480;
        c->lastSur[0] = c->lastRight[0] + 480;
        for (i = 1; i < 3; i++) {
            c->lastLeft[i] = c->lastLeft[0] + i * 160;
            c->lastRight[i] = c->lastRight[0] + i * 160;
            c->lastSur[i] = c->lastSur[0] + i * 160;
        }
        left = c->lastLeft[0];
        right = c->lastRight[0];
        sur = c->lastSur[0];
        for (i = 0; i < 320; i++) {
            *left++ = 0;
            *right++ = 0;
            *sur++ = 0;
        }
        c->currentLast = 1;
        c->oldLeft[0] = c->oldLeft[1] = c->oldLeft[2] = c->oldLeft[3] = 0;
        c->oldRight[0] = c->oldRight[1] = c->oldRight[2] = c->oldRight[3] = 0;
        c->oldSur[0] = c->oldSur[1] = c->oldSur[2] = c->oldSur[3] = 0;
        c->trigger = 480;
        c->target = 0;
        OSRestoreInterrupts(old);
        return fn_80025440(c);
    }
    OSRestoreInterrupts(old);
    return 0;
}

s32 fn_800253F0(AXFXChorus *arg0) {
    u32 t0;
    t0 = OSDisableInterrupts();
    lbl_801A64FC(arg0->lastLeft[0]);
    OSRestoreInterrupts(t0);
    return 1;
}

#pragma peephole off
u32 fn_80025440(AXFXChorus *arg0) {
    u32 t0;

    t0 = OSDisableInterrupts();
    arg0->unk_5c = 0x140 - ((arg0->unk_90 - 5) * 32);
    arg0->unk_58 = 0;
    arg0->unk_5c = (arg0->unk_5c + ((arg0->currentLast - 1) * 160)) % 480;
    arg0->unk_68 = (((arg0->unk_98 / 5) + 1) & ~1);
    arg0->unk_64 = arg0->unk_68 / 2;
    arg0->unk_60 = (arg0->unk_94 << 16) / (arg0->unk_68 * 5);
    OSRestoreInterrupts(t0);
    return 1;
}

#pragma opt_dead_assignments off
void fn_80025504(AXFXChorusSrc *arg0, AXFXChorus *arg1) {
    u32 v0;
    s32 v1;
    u8 v5;

    u32 *v12;
    u32 *v13;
    u32 *v14;
    u32 *v15;
    u32 *v16;
    u32 *v17;
    u32 v11;
    u32 v42;
    s32 v43;

    v1 = arg1->currentLast + 1;
    v15 = arg0->unk_0;
    v16 = arg0->unk_4;
    v17 = arg0->unk_8;
    v5 = v1 % 3;
    v12 = (u32 *)arg1->lastLeft[v5];
    v13 = (u32 *)arg1->lastRight[v5];
    v14 = (u32 *)arg1->lastSur[v5];
    for (v11 = 0; v11 < 160; v11++) {
        *v12++ = *v15++;
        *v13++ = *v16++;
        *v14++ = *v17++;
    }
    arg1->unk_84 = ((arg1->unk_60 >> 16) + 1);
    arg1->unk_80 = ((arg1->unk_60 & 0xFFFF) << 16);
    v42 = (arg1->unk_64 - 1);
    arg1->unk_64 = v42;
    if (v42 == 0) {
        arg1->unk_64 = arg1->unk_68;
        arg1->unk_60 = (-arg1->unk_60);
    }
    for (v43 = 0; (u32)v43 < 3; v43++) {
        arg1->unk_7c = arg1->unk_5c;
        arg1->unk_78 = arg1->unk_58;
        switch (v43) {
        case 0:
            arg1->unk_70 = (u32 *)arg1->lastLeft[0];
            arg1->unk_6c = arg0->unk_0;
            arg1->unk_74 = arg1->oldLeft;
            break;
        case 1:
            arg1->unk_70 = (u32 *)arg1->lastRight[0];
            arg1->unk_6c = arg0->unk_4;
            arg1->unk_74 = arg1->oldRight;
            break;
        case 2:
            arg1->unk_70 = (u32 *)arg1->lastSur[0];
            arg1->unk_6c = arg0->unk_8;
            arg1->unk_74 = arg1->oldSur;
            break;
        }
        switch (arg1->unk_84) {
        case 0:
            fn_80024E6C(&arg1->unk_6c);
            break;
        case 1:
            fn_80025004(&arg1->unk_6c);
            break;
        }
    }
    arg1->unk_5c = arg1->unk_7c % 480;
    arg1->unk_58 = arg1->unk_78;
    arg1->currentLast = v5;
}
#pragma opt_dead_assignments reset
#pragma peephole reset
