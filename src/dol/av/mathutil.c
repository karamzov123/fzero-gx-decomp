#include "types.h"
#include "game/vec3.h"

/* Engine math library (mathutil.c, shared with the Monkey Ball engine). Most routines are
 * CodeWarrior asm functions in the original: they work on the locked-cache matrix stack with
 * psq_l/psq_st and paired-single arithmetic, return through shared entry labels and have no
 * compiler frames; the remaining routines are C. */

typedef struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    Vec3 pos;
    Vec3 dir;
} VecPair;

typedef struct {
    Vec3 dir;
    Vec3 up;
} DirUp;

typedef struct {
    s16 angle_y;
    s16 angle_x;
    s16 angle_z;
} EulerAngles;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
} Mat34;

extern const f32 lbl_801A73D0;
extern const f32 lbl_801A73D4;
extern const f32 lbl_801A73D8;
extern const f32 lbl_801A73DC;
extern const f32 lbl_801A73E0;
extern const f32 lbl_801A73E4;
extern const f64 lbl_801A73E8;
extern const f32 lbl_801A73F0;
extern const f32 lbl_801A73F4;
extern const f32 lbl_801A73F8;
extern f32 lbl_801A73FC;
extern const f64 lbl_801A7400;
extern const f32 lbl_801A7408;
extern const f32 lbl_801A740C;
extern u32 lbl_80094E10[4];
extern f32 (*lbl_801A6D00)[4];
extern f32 lbl_801A6618;
extern f32 lbl_801A661C;

extern f32 lbl_80132820[];
extern f32 lbl_80142840[];
extern f32 lbl_80152860[];
extern void lbl_8006E0C8(Vec3 *value);
extern void lbl_8006E1C0(void *, void *);
extern void fn_8006E2B0(void *, void *);
extern f64 fn_800883E8(f64);
extern f64 fn_80088538(f64);
extern s16 lbl_8006D2AC(f32);
void _return_zero(void);
void _return_inf(void);
void _sqrt_return_special(void);
void _rsqrt_return_special(void);
void lbl_8006D1BC(void);
void lbl_8006D1C4(void);
void lbl_8006D7F4(void);
void lbl_8006D848(void);
void lbl_8006D860(void);
void lbl_8006D89C(void);
void lbl_8006D8E4(void);
void lbl_8006D9E8(void);
void lbl_8006DFD8(void);
void lbl_8006DFE8(void);
void lbl_8006DFFC(void);
void lbl_8006E0B4(void);
void lbl_8006E0D8(void);
void lbl_8006E14C(void);
void lbl_8006E15C(void);
void lbl_8006E1D8(void);
void lbl_8006E1F0(void);
void fn_8006E200(void);
void fn_8006E294(void);
void lbl_8006E2C0(void);
void lbl_8006E2D0(void);
void fn_8006E2D8(void);
void mathutil_mtxA_rotate_z_s_c(void);

asm void mathutil_init(void) {
    nofralloc
    li r3, 0x0
    mtspr GQR0, r3
    li r3, 0x4
    oris r3, r3, 0x4
    mtspr GQR2, r3
    li r3, 0x5
    oris r3, r3, 0x5
    mtspr GQR3, r3
    li r3, 0x6
    oris r3, r3, 0x6
    mtspr GQR4, r3
    li r3, 0x7
    oris r3, r3, 0x7
    mtspr GQR5, r3
    li r3, 0x0
    mtspr GQR6, r3
    li r3, 0x0
    mtspr GQR7, r3
    blr
}

asm void float_return_values(void) {
    nofralloc
    lis r0, 0x7fff
    b L_8006D060
entry _return_zero
    li r0, 0x0
    b L_8006D060
entry _return_inf
    lis r0, 0x7f80
    b L_8006D060
    lis r0, 0xff80
L_8006D060:
    stwu r0, -0x10(r1)
    lfs f1, 0x0(r1)
    addi r1, r1, 0x10
    blr
entry _sqrt_return_special
    bgt cr1, _return_inf
    blt cr1, _return_zero
    b float_return_values
entry _rsqrt_return_special
    bgt cr1, _return_zero
    blt cr1, _return_inf
    b float_return_values
}

asm void approx_rsqrt(void) {
    nofralloc
    fmuls f4, f2, f1
    fadds f3, f2, f2
    frsqrte f1, f1
    fadds f3, f3, f2
    fmuls f5, f1, f1
    fnmsubs f5, f5, f4, f3
    fmuls f1, f1, f5
    fmuls f5, f1, f1
    fnmsubs f5, f5, f4, f3
    fmuls f1, f1, f5
    blr
}

asm f32 lbl_8006D0B4(register f32 p0) {
    nofralloc
    frsp f0, f1
    lis r4, 0xe000
    mcrfs cr1, 4
    mcrfs cr0, 3
    lfs f2, 0x1a0(r4)
    bso cr1, _sqrt_return_special
    bso _return_zero
    ble cr1, _return_zero
    mflr r3
    bl approx_rsqrt
    mtlr r3
    fmuls f1, f1, f0
    blr
}

asm f32 lbl_8006D0E8(register f32 p0) {
    nofralloc
    frsp f1, f1
    lis r4, 0xe000
    mcrfs cr1, 4
    mcrfs cr0, 3
    lfs f2, 0x1a0(r4)
    bso cr1, _rsqrt_return_special
    bso _return_inf
    ble cr1, _return_inf
    mflr r3
    bl approx_rsqrt
    mtlr r3
    blr
}

asm void lbl_8006D118(void) {
    nofralloc
    frsp f0, f1
    lis r4, 0xe000
    mcrfs cr1, 4
    mcrfs cr0, 3
    lfs f2, 0x1a0(r4)
    bso cr1, L_8006D150
    bso L_8006D164
    ble cr1, L_8006D164
    mflr r5
    bl approx_rsqrt
    mtlr r5
    fmuls f0, f1, f0
    stfs f0, 0x0(r3)
    blr
L_8006D150:
    bgt+ cr1, L_8006D164
    blt+ cr1, L_8006D170
    lis r5, 0x7fff
    lis r6, 0x7fff
    b L_8006D178
L_8006D164:
    li r5, 0x0
    lis r6, 0x7f80
    b L_8006D178
L_8006D170:
    lis r5, 0x7f80
    li r6, 0x0
L_8006D178:
    stw r5, 0x0(r3)
    stw r6, 0x98(r4)
    lfs f1, 0x98(r4)
    blr
}

asm f32 lbl_8006D188(register s16 p0) {
    nofralloc
    andi. r5, r3, 0x4000
    clrlwi r4, r3, 18
    beq L_8006D198
    subfic r4, r4, 0x4000
L_8006D198:
    lis r6, lbl_80132820@h
    slwi r4, r4, 2
    ori r6, r6, lbl_80132820@l
    andi. r5, r3, 0x8000
    lfsx f1, r6, r4
    beqlr
    fneg f1, f1
    blr
}

asm void lbl_8006D1B8(void) {
    nofralloc
    addi r5, r4, 0x4
entry lbl_8006D1BC
    crclr 6
    b L_8006D1C8
entry lbl_8006D1C4
    crset 6
L_8006D1C8:
    extlwi r8, r3, 2, 16
    clrlwi r6, r3, 18
    mtcrf 128, r8
    crxor eq, lt, gt
    ble L_8006D1E0
    subfic r6, r6, 0x4000
L_8006D1E0:
    subfic r7, r6, 0x4000
    lis r8, lbl_80132820@h
    slwi r6, r6, 2
    ori r8, r8, lbl_80132820@l
    slwi r7, r7, 2
    lfsx f1, r8, r6
    lfsx f2, r8, r7
    bge L_8006D204
    fnabs f1, f1
L_8006D204:
    bne L_8006D20C
    fnabs f2, f2
L_8006D20C:
    beqlr cr1
    stfs f1, 0x0(r4)
    stfs f2, 0x0(r5)
    blr
}

asm void lbl_8006D21C(void) {
    nofralloc
    lis r4, lbl_80142840@h
    andi. r6, r3, 0x4000
    clrlslwi r5, r3, 18, 2
    ori r4, r4, lbl_80142840@l
    beq L_8006D244
    addis r4, r4, 0x1
    neg r5, r5
    lfsx f1, r5, r4
    fnabs f1, f1
    blr
L_8006D244:
    lfsx f1, r5, r4
    blr
}

asm s32 lbl_8006D24C(register f32 p0, register f32 p1) {
    nofralloc
    mfcr r6
    frsp f2, f2
    mcrfs cr7, 4
    mcrfs cr6, 3
    frsp f1, f1
    bso cr7, L_8006D360
    mcrfs cr5, 4
    mcrfs cr4, 3
    bso cr5, L_8006D368
    bne+ cr7, L_8006D27C
    bne+ cr5, L_8006D27C
    b L_8006D3AC
L_8006D27C:
    crxor 12, 20, 28
    fabs f3, f2
    fabs f4, f1
    fcmpu cr0, f3, f4
    beq L_8006D3B4
    bgt L_8006D29C
    fabs f3, f1
    fabs f4, f2
L_8006D29C:
    crmove 15, lt
    lis r7, 0xe000
    fdivs f5, f4, f3
    b L_8006D2F0
entry lbl_8006D2AC
    frsp f1, f1
    lis r7, 0xe000
    mcrfs cr5, 4
    mcrfs cr4, 3
    bns+ cr5, L_8006D2CC
    crand 9, 19, 23
    bgt cr2, L_8006D3AC
    b L_8006D388
L_8006D2CC:
    beq cr5, L_8006D3AC
    lfs f3, 0x19c(r7)
    fabs f5, f1
    crmove 12, 20
    fcmpu cr0, f5, f3
    beq L_8006D3B4
    blt L_8006D2EC
    fdivs f5, f3, f5
L_8006D2EC:
    crmove 15, gt
L_8006D2F0:
    stfs f5, 0x98(r7)
    lwz r3, 0x98(r7)
    clrlwi r5, r3, 9
    oris r5, r5, 0x80
    extrwi r4, r3, 8, 1
    subfic r4, r4, 0x87
    clrrwi. r0, r4, 5
    beq L_8006D314
    ori r4, r4, 0x20
L_8006D314:
    srw r4, r5, r4
    rlwinm r4, r4, 0, 17, 28
    addis r4, r4, lbl_80152860@ha
    addi r4, r4, lbl_80152860@l
    lfs f3, 0x0(r4)
    lfs f4, 0x4(r4)
    fmadds f5, f5, f3, f4
    fctiw f5, f5
    stfd f5, 0x98(r7)
    lwz r3, 0x9c(r7)
    bns cr3, L_8006D344
    subfic r3, r3, 0x4000
L_8006D344:
    bge cr3, L_8006D354
    neg r3, r3
    addi r3, r3, -0x8000
    addis r3, r3, 0x1
L_8006D354:
    bge cr5, L_8006D3C4
    addi r3, r3, -0x8000
    b L_8006D3C4
L_8006D360:
    mcrfs cr5, 4
    mcrfs cr4, 3
L_8006D368:
    crand 8, 27, 31
    blt cr2, L_8006D3AC
    crand 9, 19, 23
    bgt cr2, L_8006D3AC
    bns cr7, L_8006D388
    bns cr5, L_8006D39C
    crxor 12, 20, 28
    b L_8006D3B4
L_8006D388:
    crxor 12, 20, 28
    mfcr r3
    rlwinm r3, r3, 28, 16, 16
    ori r3, r3, 0x4000
    b L_8006D3C4
L_8006D39C:
    crxor 12, 20, 28
    mfcr r3
    rlwinm r3, r3, 28, 16, 16
    b L_8006D3C4
L_8006D3AC:
    li r3, 0x0
    b L_8006D3C8
L_8006D3B4:
    crmove 21, 12
    mfcr r3
    rlwinm r3, r3, 4, 16, 17
    ori r3, r3, 0x2000
L_8006D3C4:
    extsh r3, r3
L_8006D3C8:
    mtcrf 255, r6
    blr
}

#pragma fp_contract off
s16 lbl_8006D3D0(f32 x) {
    f32 c;

    if (__fabs(x) > 1.0) {
        if (x > 0.0f) {
            return 0x4000;
        }
        return -0x4000;
    }
    c = lbl_8006D0B4(1.0f - x * x);
    if (c > 1.1920929e-07f) {
        return lbl_8006D2AC(x / c);
    }
    if (x > 0.0f) {
        return 0x4000;
    }
    return -0x4000;
}

s16 lbl_8006D46C(f32 x) {
    s16 angle;
    f32 c;

    if (__fabs(x) > 1.0) {
        if (x > 0.0f) {
            return 0;
        }
        return -0x8000;
    }
    if (__fabs(x) > 1.0) {
        if (x > 0.0f) {
            angle = 0x4000;
        } else {
            angle = -0x4000;
        }
    } else {
        c = lbl_8006D0B4(1.0f - x * x);
        if (c > 1.1920929e-07f) {
            angle = lbl_8006D2AC(x / c);
        } else if (x > 0.0f) {
            angle = 0x4000;
        } else {
            angle = -0x4000;
        }
    }
    return (0x4000 - angle) & 0xFFFF;
}
#pragma fp_contract reset

asm void lbl_8006D534(void) {
    nofralloc
    lfs f1, 0x0(r3)
    lfs f2, 0x4(r3)
    lfs f3, 0x8(r3)
    lfs f4, 0x0(r4)
    lfs f5, 0x4(r4)
    lfs f6, 0x8(r4)
    lis r6, 0xe000
    fmuls f8, f1, f1
    fmuls f9, f4, f4
    fmuls f7, f1, f4
    fmadds f8, f2, f2, f8
    fmadds f9, f5, f5, f9
    fmadds f7, f2, f5, f7
    fmadds f8, f3, f3, f8
    fmadds f9, f6, f6, f9
    fmadds f7, f3, f6, f7
    fmuls f1, f8, f9
    mcrfs cr1, 4
    mcrfs cr0, 3
    lfs f2, 0x1a0(r6)
    bso cr1, _sqrt_return_special
    bso _return_zero
    ble cr1, _return_zero
    mflr r5
    bl approx_rsqrt
    mtlr r5
    fmuls f1, f1, f7
    blr
}

#pragma fp_contract off
void lbl_8006D5A4(Vec3 *a, Vec3 *b, Vec3 *out, f32 t) {
    out->x = a->x + t * (b->x - a->x);
    out->y = a->y + t * (b->y - a->y);
    out->z = a->z + t * (b->z - a->z);
}
#pragma fp_contract reset

asm void lbl_8006D5F0(void) {
    nofralloc
    lis r6, 0xe000
    fmr f0, f1
    lfs f6, 0x0(r3)
    lfs f7, 0x4(r3)
    lfs f8, 0x8(r3)
    fmuls f1, f6, f6
    fmadds f1, f7, f7, f1
    fmadds f1, f8, f8, f1
    mcrfs cr1, 4
    mcrfs cr0, 3
    lfs f2, 0x1a0(r6)
    bso cr1, L_8006D654
    bso L_8006D654
    ble cr1, L_8006D654
    mflr r5
    bl approx_rsqrt
    mtlr r5
    fmuls f1, f1, f0
    fmuls f6, f6, f1
    stfs f6, 0x0(r4)
    fmuls f7, f7, f1
    stfs f7, 0x4(r4)
    fmuls f8, f8, f1
    stfs f8, 0x8(r4)
    blr
L_8006D654:
    lfs f6, 0x198(r6)
    stfs f6, 0x0(r4)
    stfs f6, 0x4(r4)
    stfs f6, 0x8(r4)
    blr
}

asm f32 lbl_8006D668(register void *p0) {
    nofralloc
    lis r5, 0xe000
    lfs f6, 0x0(r3)
    lfs f7, 0x4(r3)
    fmuls f1, f6, f6
    lfs f8, 0x8(r3)
    fmadds f1, f7, f7, f1
    fmadds f1, f8, f8, f1
    lfs f2, 0x1a0(r5)
    mcrfs cr1, 4
    mcrfs cr0, 3
    bso cr1, L_8006D6E8
    ble cr1, L_8006D6E8
    bso L_8006D6E8
    fmr f0, f1
    fmuls f4, f2, f1
    fadds f3, f2, f2
    frsqrte f1, f1
    fadds f3, f3, f2
    fmuls f5, f1, f1
    fnmsubs f5, f5, f4, f3
    fmuls f1, f1, f5
    fmuls f5, f1, f1
    fnmsubs f5, f5, f4, f3
    fmuls f1, f1, f5
    fmuls f6, f6, f1
    stfs f6, 0x0(r3)
    fmuls f7, f7, f1
    stfs f7, 0x4(r3)
    fmuls f8, f8, f1
    stfs f8, 0x8(r3)
    fmuls f1, f1, f0
    blr
L_8006D6E8:
    lfs f1, 0x198(r5)
    stfs f1, 0x0(r3)
    stfs f1, 0x4(r3)
    stfs f1, 0x8(r3)
    blr
}

asm void lbl_8006D6FC(void) {
    nofralloc
    lis r5, 0xe000
    lfs f6, 0x0(r3)
    lfs f9, 0x0(r4)
    fmuls f12, f6, f6
    lfs f7, 0x4(r3)
    fmuls f13, f9, f9
    lfs f10, 0x4(r4)
    fmuls f0, f6, f9
    lfs f8, 0x8(r3)
    fmadds f12, f7, f7, f12
    lfs f11, 0x8(r4)
    fmadds f13, f10, f10, f13
    fmadds f0, f7, f10, f0
    fmadds f12, f8, f8, f12
    fmadds f13, f11, f11, f13
    fmadds f0, f8, f11, f0
    lfs f2, 0x1a0(r5)
    fmuls f1, f12, f13
    mflr r6
    bl approx_rsqrt
    mtlr r6
    fmuls f1, f1, f0
    blr
}

asm void lbl_8006D758(void) {
    nofralloc
    lis r3, 0xe000
    psq_l f1, 0x1ac(r3), 0, 2
    psq_l f2, 0x1ae(r3), 0, 2
    ps_sub f0, f1, f1
    psq_st f2, 0x0(r3), 0, 0
    psq_st f0, 0x8(r3), 0, 0
    psq_st f1, 0x10(r3), 0, 0
    psq_st f0, 0x18(r3), 0, 0
    psq_st f0, 0x20(r3), 0, 0
    psq_st f2, 0x28(r3), 0, 0
    blr
}

asm void lbl_8006D784(void) {
    nofralloc
    lis r4, 0xe000
    psq_l f1, 0x1ac(r4), 0, 2
    psq_l f2, 0x1ae(r4), 0, 2
    ps_sub f0, f1, f1
    psq_st f2, 0x0(r3), 0, 0
    psq_st f0, 0x8(r3), 0, 0
    psq_st f1, 0x10(r3), 0, 0
    psq_st f0, 0x18(r3), 0, 0
    psq_st f0, 0x20(r3), 0, 0
    psq_st f2, 0x28(r3), 0, 0
    blr
}

asm void lbl_8006D7B0(void) {
    nofralloc
    lis r3, 0xe000
    psq_l f1, 0x1ac(r3), 0, 2
    psq_l f2, 0x1ae(r3), 0, 2
    ps_sub f0, f1, f1
    psq_st f2, 0x0(r3), 0, 0
    psq_st f0, 0x8(r3), 1, 0
    psq_st f1, 0x10(r3), 0, 0
    psq_st f0, 0x18(r3), 1, 0
    psq_st f0, 0x20(r3), 0, 0
    psq_st f2, 0x28(r3), 1, 0
    blr
}

asm void lbl_8006D7DC(register void *p0) {
    nofralloc
    lis r4, 0xe000
    psq_l f1, 0x0(r3), 0, 0
    lfs f4, 0x198(r4)
    lfs f3, 0x8(r3)
    ps_merge01 f9, f4, f1
    b L_8006D800
entry lbl_8006D7F4
    lis r4, 0xe000
    lfs f4, 0x198(r4)
    ps_merge00 f9, f4, f2
L_8006D800:
    lfs f7, 0x19c(r4)
    ps_merge00 f8, f4, f1
    ps_merge00 f10, f7, f3
    psq_l f5, 0x1ac(r4), 0, 2
    psq_l f6, 0x1ae(r4), 0, 2
    psq_st f4, 0x20(r4), 0, 0
    psq_st f8, 0x8(r4), 0, 0
    psq_st f9, 0x18(r4), 0, 0
    psq_st f10, 0x28(r4), 0, 0
    psq_st f5, 0x10(r4), 0, 0
    psq_st f6, 0x0(r4), 0, 0
    blr
}

asm void fn_8006D830(void) {
    nofralloc
    lis r4, 0xe000
    psq_l f1, 0x0(r3), 0, 0
    lfs f4, 0x198(r4)
    lfs f3, 0x8(r3)
    ps_merge01 f6, f4, f1
    b L_8006D86C
entry lbl_8006D848
    lis r4, 0xe000
    fmr f3, f1
    lfs f4, 0x198(r4)
    ps_merge00 f1, f1, f1
    ps_merge01 f6, f4, f1
    b L_8006D86C
entry lbl_8006D860
    lis r4, 0xe000
    lfs f4, 0x198(r4)
    ps_merge00 f6, f4, f2
L_8006D86C:
    ps_merge00 f5, f1, f4
    ps_merge00 f7, f3, f4
    psq_st f4, 0x8(r4), 0, 0
    psq_st f4, 0x18(r4), 0, 0
    psq_st f4, 0x20(r4), 0, 0
    psq_st f5, 0x0(r4), 0, 0
    psq_st f6, 0x10(r4), 0, 0
    psq_st f7, 0x28(r4), 0, 0
    blr
}

asm void lbl_8006D890(register s16 angle) {
    nofralloc
    mflr r4
    bl lbl_8006D1C4
    mtlr r4
entry lbl_8006D89C
    lis r4, 0xe000
    fneg f3, f1
    psq_l f4, 0x1ae(r4), 0, 2
    ps_merge11 f6, f4, f4
    ps_merge10 f7, f4, f2
    ps_merge01 f8, f3, f4
    ps_merge10 f9, f4, f1
    ps_merge01 f10, f2, f4
    psq_st f4, 0x0(r4), 0, 0
    psq_st f6, 0x8(r4), 0, 0
    psq_st f8, 0x18(r4), 0, 0
    psq_st f7, 0x10(r4), 0, 0
    psq_st f9, 0x20(r4), 0, 0
    psq_st f10, 0x28(r4), 0, 0
    blr
}

asm void lbl_8006D8D8() {
    nofralloc
    mflr r4
    bl lbl_8006D1C4
    mtlr r4
entry lbl_8006D8E4
    lis r4, 0xe000
    fneg f3, f1
    psq_l f4, 0x1ac(r4), 0, 2
    ps_merge00 f5, f2, f4
    ps_merge00 f6, f1, f4
    ps_merge00 f8, f4, f4
    ps_merge00 f9, f3, f4
    psq_st f5, 0x0(r4), 0, 0
    psq_st f6, 0x8(r4), 0, 0
    psq_st f4, 0x10(r4), 0, 0
    psq_st f8, 0x18(r4), 0, 0
    psq_st f9, 0x20(r4), 0, 0
    psq_st f5, 0x28(r4), 0, 0
    blr
}

asm void lbl_8006D91C(register s16 angle) {
    nofralloc
    mflr r4
    bl lbl_8006D1C4
    mtlr r4
    lis r4, 0xe000
    fneg f3, f1
    psq_l f4, 0x1ae(r4), 0, 2
    ps_merge00 f5, f2, f3
    ps_merge11 f6, f4, f4
    ps_merge00 f7, f1, f2
    psq_st f5, 0x0(r4), 0, 0
    psq_st f6, 0x8(r4), 0, 0
    psq_st f7, 0x10(r4), 0, 0
    psq_st f6, 0x18(r4), 0, 0
    psq_st f6, 0x20(r4), 0, 0
    psq_st f4, 0x28(r4), 0, 0
    blr
}

asm void lbl_8006D95C(void) {
    nofralloc
    mflr r4
    bl lbl_8006D1C4
    mtlr r4
    lis r4, 0xe000
    fneg f3, f1
    psq_l f4, 0x1ac(r4), 0, 2
    ps_merge00 f5, f2, f4
    ps_merge00 f6, f3, f4
    psq_st f5, 0x0(r4), 0, 0
    stfs f1, 0x8(r4)
    psq_st f4, 0x10(r4), 0, 0
    psq_st f4, 0x18(r4), 1, 0
    psq_st f6, 0x20(r4), 0, 0
    stfs f2, 0x28(r4)
    blr
}

asm void lbl_8006D998(void) {
    nofralloc
    mflr r4
    bl lbl_8006D1C4
    mtlr r4
    lis r4, 0xe000
    psq_l f4, 0x1ae(r4), 0, 2
    fneg f3, f1
    ps_merge00 f6, f1, f2
    ps_merge00 f5, f2, f3
    ps_merge11 f7, f4, f4
    psq_st f6, 0x10(r4), 0, 0
    psq_st f5, 0x0(r4), 0, 0
    psq_st f7, 0x8(r4), 1, 0
    psq_st f7, 0x18(r4), 1, 0
    psq_st f7, 0x20(r4), 0, 0
    psq_st f4, 0x28(r4), 1, 0
    blr
}

asm void lbl_8006D9D8(void) {
    nofralloc
    lis r4, 0xe000
    psq_l f1, 0x0(r3), 0, 0
    psq_l f3, 0x8(r3), 1, 0
    b L_8006D9F8
entry lbl_8006D9E8
    lis r4, 0xe000
    lfs f4, 0x19c(r4)
    ps_merge00 f1, f1, f2
    ps_merge00 f3, f3, f4
L_8006D9F8:
    psq_l f4, 0x30(r4), 0, 0
    psq_st f4, 0x0(r4), 0, 0
    ps_mul f4, f4, f1
    psq_l f6, 0x40(r4), 0, 0
    psq_st f6, 0x10(r4), 0, 0
    ps_mul f6, f6, f1
    psq_l f8, 0x50(r4), 0, 0
    psq_st f8, 0x20(r4), 0, 0
    ps_mul f8, f8, f1
    psq_l f5, 0x38(r4), 0, 0
    ps_madd f4, f5, f3, f4
    psq_l f7, 0x48(r4), 0, 0
    ps_madd f6, f7, f3, f6
    psq_l f9, 0x58(r4), 0, 0
    ps_madd f8, f9, f3, f8
    ps_sum1 f5, f4, f5, f4
    psq_st f5, 0x8(r4), 0, 0
    ps_sum1 f7, f6, f7, f6
    psq_st f7, 0x18(r4), 0, 0
    ps_sum1 f9, f8, f9, f8
    psq_st f9, 0x28(r4), 0, 0
    blr
}

asm void lbl_8006DA50(void) {
    nofralloc
    lis r3, 0xe000
    mflr r4
    lfs f2, 0x1a0(r3)
    psq_l f6, 0x0(r3), 0, 0
    lfs f7, 0x8(r3)
    ps_mul f12, f6, f6
    psq_l f8, 0x10(r3), 0, 0
    fmuls f13, f7, f7
    lfs f9, 0x18(r3)
    ps_madd f12, f8, f8, f12
    psq_l f10, 0x20(r3), 0, 0
    fmadds f13, f9, f9, f13
    lfs f11, 0x28(r3)
    ps_madd f12, f10, f10, f12
    fmadds f13, f11, f11, f13
    fmr f1, f12
    bl approx_rsqrt
    frsp f1, f1
    ps_merge01 f12, f1, f12
    ps_merge11 f1, f12, f12
    bl approx_rsqrt
    frsp f1, f1
    ps_merge00 f1, f12, f1
    ps_mul f6, f6, f1
    psq_st f6, 0x0(r3), 0, 0
    ps_mul f8, f8, f1
    psq_st f8, 0x10(r3), 0, 0
    ps_mul f10, f10, f1
    psq_st f10, 0x20(r3), 0, 0
    fmr f1, f13
    bl approx_rsqrt
    mtlr r4
    fmuls f7, f7, f1
    stfs f7, 0x8(r3)
    fmuls f9, f9, f1
    stfs f9, 0x18(r3)
    fmuls f11, f11, f1
    stfs f11, 0x28(r3)
    blr
}

asm void lbl_8006DAEC() {
    nofralloc
    lis r3, 0xe000
    lwz r4, 0x94(r3)
    psq_l f0, 0x0(r3), 0, 0
    psq_l f1, 0x8(r3), 0, 0
    psq_l f2, 0x10(r3), 0, 0
    subi r4, r4, 0x30
    psq_l f3, 0x18(r3), 0, 0
    psq_l f4, 0x20(r3), 0, 0
    psq_l f5, 0x28(r3), 0, 0
    psq_st f0, 0x0(r4), 0, 0
    psq_st f1, 0x8(r4), 0, 0
    psq_st f2, 0x10(r4), 0, 0
    psq_st f3, 0x18(r4), 0, 0
    psq_st f4, 0x20(r4), 0, 0
    psq_st f5, 0x28(r4), 0, 0
    stw r4, 0x94(r3)
    blr
}

asm void lbl_8006DB30(void) {
    nofralloc
    lis r3, 0xe000
    lwz r4, 0x94(r3)
    psq_l f0, 0x0(r4), 0, 0
    psq_l f1, 0x8(r4), 0, 0
    psq_l f2, 0x10(r4), 0, 0
    psq_l f3, 0x18(r4), 0, 0
    psq_l f4, 0x20(r4), 0, 0
    psq_l f5, 0x28(r4), 0, 0
    addi r4, r4, 0x30
    psq_st f0, 0x0(r3), 0, 0
    psq_st f1, 0x8(r3), 0, 0
    psq_st f2, 0x10(r3), 0, 0
    psq_st f3, 0x18(r3), 0, 0
    psq_st f4, 0x20(r3), 0, 0
    psq_st f5, 0x28(r3), 0, 0
    stw r4, 0x94(r3)
    blr
}

asm void lbl_8006DB74(void) {
    nofralloc
    lis r4, 0xe000
    psq_l f0, 0x0(r4), 0, 0
    psq_l f1, 0x8(r4), 0, 0
    psq_l f2, 0x10(r4), 0, 0
    psq_l f3, 0x18(r4), 0, 0
    psq_l f4, 0x20(r4), 0, 0
    psq_l f5, 0x28(r4), 0, 0
    psq_st f0, 0x0(r3), 0, 0
    psq_st f1, 0x8(r3), 0, 0
    psq_st f2, 0x10(r3), 0, 0
    psq_st f3, 0x18(r3), 0, 0
    psq_st f4, 0x20(r3), 0, 0
    psq_st f5, 0x28(r3), 0, 0
    blr
}

asm void lbl_8006DBAC(register void *p0) {
    nofralloc
    lis r4, 0xe000
    psq_l f0, 0x0(r3), 0, 0
    psq_l f1, 0x8(r3), 0, 0
    psq_l f2, 0x10(r3), 0, 0
    psq_l f3, 0x18(r3), 0, 0
    psq_l f4, 0x20(r3), 0, 0
    psq_l f5, 0x28(r3), 0, 0
    psq_st f0, 0x0(r4), 0, 0
    psq_st f1, 0x8(r4), 0, 0
    psq_st f2, 0x10(r4), 0, 0
    psq_st f3, 0x18(r4), 0, 0
    psq_st f4, 0x20(r4), 0, 0
    psq_st f5, 0x28(r4), 0, 0
    blr
}

asm void lbl_8006DBE4(void) {
    nofralloc
    lis r3, 0xe000
    lwz r4, 0x94(r3)
    psq_l f0, 0x0(r4), 0, 0
    psq_l f1, 0x8(r4), 0, 0
    psq_l f2, 0x10(r4), 0, 0
    psq_l f3, 0x18(r4), 0, 0
    psq_l f4, 0x20(r4), 0, 0
    psq_l f5, 0x28(r4), 0, 0
    psq_st f0, 0x0(r3), 0, 0
    psq_st f1, 0x8(r3), 0, 0
    psq_st f2, 0x10(r3), 0, 0
    psq_st f3, 0x18(r3), 0, 0
    psq_st f4, 0x20(r3), 0, 0
    psq_st f5, 0x28(r3), 0, 0
    blr
}

asm void lbl_8006DC20(void) {
    nofralloc
    lis r3, 0xe000
    lwz r4, 0x94(r3)
    addi r4, r4, 0x30
    stw r4, 0x94(r3)
    blr
}

asm u32 lbl_8006DC34(register u32 p0) {
    nofralloc
    lis r4, 0xe000
    psq_l f0, 0x0(r4), 0, 0
    lfs f1, 0x8(r4)
    psq_l f2, 0x10(r4), 0, 0
    lfs f3, 0x18(r4)
    psq_l f4, 0x20(r4), 0, 0
    lfs f5, 0x28(r4)
    psq_st f0, 0x0(r3), 0, 0
    stfs f1, 0x8(r3)
    psq_st f2, 0x10(r3), 0, 0
    stfs f3, 0x18(r3)
    psq_st f4, 0x20(r3), 0, 0
    stfs f5, 0x28(r3)
    blr
}

asm void lbl_8006DC6C(void) {
    nofralloc
    lis r4, 0xe000
    psq_l f0, 0x0(r3), 0, 0
    lfs f1, 0x8(r3)
    psq_l f2, 0x10(r3), 0, 0
    lfs f3, 0x18(r3)
    psq_l f4, 0x20(r3), 0, 0
    lfs f5, 0x28(r3)
    psq_st f0, 0x0(r4), 0, 0
    stfs f1, 0x8(r4)
    psq_st f2, 0x10(r4), 0, 0
    stfs f3, 0x18(r4)
    psq_st f4, 0x20(r4), 0, 0
    stfs f5, 0x28(r4)
    blr
}

asm void lbl_8006DCA4(void) {
    nofralloc
    lis r3, 0xe000
    psq_l f0, 0x30(r3), 0, 0
    psq_l f1, 0x38(r3), 0, 0
    psq_l f2, 0x40(r3), 0, 0
    psq_l f3, 0x48(r3), 0, 0
    psq_l f4, 0x50(r3), 0, 0
    psq_l f5, 0x58(r3), 0, 0
    psq_st f0, 0x0(r3), 0, 0
    psq_st f1, 0x8(r3), 0, 0
    psq_st f2, 0x10(r3), 0, 0
    psq_st f3, 0x18(r3), 0, 0
    psq_st f4, 0x20(r3), 0, 0
    psq_st f5, 0x28(r3), 0, 0
    blr
}

asm void lbl_8006DCDC(void) {
    nofralloc
    lis r3, 0xe000
    psq_l f0, 0x0(r3), 0, 0
    psq_l f1, 0x8(r3), 0, 0
    psq_l f2, 0x10(r3), 0, 0
    psq_l f3, 0x18(r3), 0, 0
    psq_l f4, 0x20(r3), 0, 0
    psq_l f5, 0x28(r3), 0, 0
    psq_st f0, 0x30(r3), 0, 0
    psq_st f1, 0x38(r3), 0, 0
    psq_st f2, 0x40(r3), 0, 0
    psq_st f3, 0x48(r3), 0, 0
    psq_st f4, 0x50(r3), 0, 0
    psq_st f5, 0x58(r3), 0, 0
    blr
}

asm void lbl_8006DD14(void) {
    nofralloc
    psq_l f0, 0x0(r3), 0, 0
    psq_l f1, 0x8(r3), 0, 0
    psq_l f2, 0x10(r3), 0, 0
    psq_l f3, 0x18(r3), 0, 0
    psq_l f4, 0x20(r3), 0, 0
    psq_l f5, 0x28(r3), 0, 0
    psq_st f0, 0x0(r4), 0, 0
    psq_st f1, 0x8(r4), 0, 0
    psq_st f2, 0x10(r4), 0, 0
    psq_st f3, 0x18(r4), 0, 0
    psq_st f4, 0x20(r4), 0, 0
    psq_st f5, 0x28(r4), 0, 0
    blr
}

asm void lbl_8006DD48(void) {
    nofralloc
    psq_l f0, 0x0(r3), 0, 0
    lfs f1, 0x8(r3)
    psq_l f2, 0x10(r3), 0, 0
    lfs f3, 0x18(r3)
    psq_l f4, 0x20(r3), 0, 0
    lfs f5, 0x28(r3)
    psq_st f0, 0x0(r4), 0, 0
    stfs f1, 0x8(r4)
    psq_st f2, 0x10(r4), 0, 0
    stfs f3, 0x18(r4)
    psq_st f4, 0x20(r4), 0, 0
    stfs f5, 0x28(r4)
    blr
}

asm void lbl_8006DD7C(void) {
    nofralloc
    lis r3, 0xe000
    stfd f14, 0x98(r3)
    stfd f15, 0xa0(r3)
    stfd f16, 0xa8(r3)
    stfd f17, 0xb0(r3)
    stfd f18, 0xb8(r3)
    stfd f19, 0xc0(r3)
    stfd f20, 0xc8(r3)
    stfd f21, 0xd0(r3)
    stfd f22, 0xd8(r3)
    stfd f23, 0xe0(r3)
    stfd f24, 0xe8(r3)
    psq_st f14, 0xf0(r3), 0, 0
    psq_st f15, 0xf8(r3), 0, 0
    psq_st f16, 0x100(r3), 0, 0
    psq_st f17, 0x108(r3), 0, 0
    psq_st f18, 0x110(r3), 0, 0
    psq_st f19, 0x118(r3), 0, 0
    psq_st f20, 0x120(r3), 0, 0
    psq_st f21, 0x128(r3), 0, 0
    psq_st f22, 0x130(r3), 0, 0
    psq_st f23, 0x138(r3), 0, 0
    psq_st f24, 0x140(r3), 0, 0
    lfs f10, 0x24(r3)
    lfs f7, 0x18(r3)
    fmuls f13, f10, f7
    lfs f2, 0x4(r3)
    lfs f11, 0x28(r3)
    fmuls f14, f2, f11
    lfs f6, 0x14(r3)
    lfs f3, 0x8(r3)
    fmuls f15, f6, f3
    lfs f5, 0x10(r3)
    fmuls f17, f11, f5
    fmuls f23, f5, f2
    lfs f9, 0x20(r3)
    fmuls f18, f3, f9
    fmuls f21, f9, f6
    lfs f1, 0x0(r3)
    fmuls f19, f7, f1
    fmuls f22, f1, f10
    lfs f4, 0xc(r3)
    fmsubs f13, f6, f11, f13
    lfs f8, 0x1c(r3)
    fmsubs f14, f10, f3, f14
    lfs f12, 0x2c(r3)
    fmsubs f15, f2, f7, f15
    fmsubs f17, f7, f9, f17
    fmsubs f18, f11, f1, f18
    fmsubs f19, f3, f5, f19
    fmsubs f21, f5, f10, f21
    fmsubs f22, f9, f2, f22
    fmsubs f23, f1, f6, f23
    fmuls f0, f1, f13
    lfs f1, 0x19c(r3)
    fmuls f16, f4, f13
    fmuls f20, f4, f17
    fmadds f0, f5, f14, f0
    fmuls f24, f4, f21
    fmadds f16, f8, f14, f16
    fmadds f0, f9, f15, f0
    fmadds f20, f8, f18, f20
    fmadds f24, f8, f22, f24
    fdivs f0, f1, f0
    fnmadds f16, f12, f15, f16
    fnmadds f20, f12, f19, f20
    fnmadds f24, f12, f23, f24
    fmuls f1, f13, f0
    stfs f1, 0x0(r3)
    fmuls f2, f14, f0
    stfs f2, 0x4(r3)
    fmuls f3, f15, f0
    stfs f3, 0x8(r3)
    fmuls f4, f16, f0
    stfs f4, 0xc(r3)
    fmuls f5, f17, f0
    stfs f5, 0x10(r3)
    fmuls f6, f18, f0
    stfs f6, 0x14(r3)
    fmuls f7, f19, f0
    stfs f7, 0x18(r3)
    fmuls f8, f20, f0
    stfs f8, 0x1c(r3)
    fmuls f9, f21, f0
    stfs f9, 0x20(r3)
    fmuls f10, f22, f0
    stfs f10, 0x24(r3)
    fmuls f11, f23, f0
    stfs f11, 0x28(r3)
    fmuls f12, f24, f0
    stfs f12, 0x2c(r3)
    psq_l f14, 0xf0(r3), 0, 0
    psq_l f15, 0xf8(r3), 0, 0
    psq_l f16, 0x100(r3), 0, 0
    psq_l f17, 0x108(r3), 0, 0
    psq_l f18, 0x110(r3), 0, 0
    psq_l f19, 0x118(r3), 0, 0
    psq_l f20, 0x120(r3), 0, 0
    psq_l f21, 0x128(r3), 0, 0
    psq_l f22, 0x130(r3), 0, 0
    psq_l f23, 0x138(r3), 0, 0
    psq_l f24, 0x140(r3), 0, 0
    lfd f14, 0x98(r3)
    lfd f15, 0xa0(r3)
    lfd f16, 0xa8(r3)
    lfd f17, 0xb0(r3)
    lfd f18, 0xb8(r3)
    lfd f19, 0xc0(r3)
    lfd f20, 0xc8(r3)
    lfd f21, 0xd0(r3)
    lfd f22, 0xd8(r3)
    lfd f23, 0xe0(r3)
    lfd f24, 0xe8(r3)
    blr
}

asm void lbl_8006DF44(void) {
    nofralloc
    lis r3, 0xe000
    lfs f3, 0xc(r3)
    lfs f0, 0x0(r3)
    lfs f1, 0x4(r3)
    lfs f2, 0x8(r3)
    fmuls f12, f3, f0
    lfs f7, 0x1c(r3)
    fmuls f13, f3, f1
    lfs f4, 0x10(r3)
    fmuls f0, f3, f2
    lfs f5, 0x14(r3)
    lfs f6, 0x18(r3)
    fmadds f12, f7, f4, f12
    lfs f11, 0x2c(r3)
    lfs f8, 0x20(r3)
    fmadds f13, f7, f5, f13
    lfs f9, 0x24(r3)
    lfs f10, 0x28(r3)
    fmadds f0, f7, f6, f0
    stfs f1, 0x10(r3)
    stfs f2, 0x20(r3)
    fnmadds f12, f11, f8, f12
    stfs f6, 0x24(r3)
    stfs f4, 0x4(r3)
    fnmadds f13, f11, f9, f13
    stfs f8, 0x8(r3)
    stfs f9, 0x18(r3)
    fnmadds f0, f11, f10, f0
    stfs f12, 0xc(r3)
    stfs f13, 0x1c(r3)
    stfs f0, 0x2c(r3)
    blr
}

asm void lbl_8006DFC4(void) {
    nofralloc
    lis r6, 0xe000
    mr r4, r3
    addi r3, r6, 0x0
    addi r5, r6, 0x0
    b L_8006E000
entry lbl_8006DFD8
    lis r6, 0xe000
    addi r4, r6, 0x0
    addi r5, r6, 0x0
    b L_8006E000
entry lbl_8006DFE8
    lis r6, 0xe000
    mr r4, r3
    addi r3, r6, 0x30
    addi r5, r6, 0x0
    b L_8006E000
entry lbl_8006DFFC
    lis r6, 0xe000
L_8006E000:
    psq_l f0, 0x0(r4), 0, 0
    psq_l f11, 0x0(r3), 0, 0
    psq_l f1, 0x8(r4), 0, 0
    psq_l f12, 0x10(r3), 0, 0
    psq_l f2, 0x10(r4), 0, 0
    ps_muls0 f5, f0, f11
    psq_l f13, 0x20(r3), 0, 0
    ps_muls0 f7, f0, f12
    psq_l f3, 0x18(r4), 0, 0
    ps_muls0 f9, f0, f13
    ps_muls0 f6, f1, f11
    psq_l f4, 0x20(r4), 0, 0
    ps_muls0 f8, f1, f12
    ps_muls0 f10, f1, f13
    psq_l f0, 0x28(r4), 0, 0
    ps_madds1 f5, f2, f11, f5
    ps_madds1 f7, f2, f12, f7
    psq_l f1, 0x8(r3), 0, 0
    ps_madds1 f9, f2, f13, f9
    ps_madds1 f6, f3, f11, f6
    psq_l f2, 0x18(r3), 0, 0
    ps_madds1 f8, f3, f12, f8
    ps_madds1 f10, f3, f13, f10
    psq_l f3, 0x28(r3), 0, 0
    ps_madds0 f5, f4, f1, f5
    ps_madds0 f7, f4, f2, f7
    psq_l f11, 0x1ac(r6), 0, 2
    ps_madds0 f9, f4, f3, f9
    ps_madds0 f6, f0, f1, f6
    psq_st f5, 0x0(r5), 0, 0
    ps_madds0 f8, f0, f2, f8
    psq_st f7, 0x10(r5), 0, 0
    ps_madds0 f10, f0, f3, f10
    psq_st f9, 0x20(r5), 0, 0
    ps_madd f6, f11, f1, f6
    ps_madd f8, f11, f2, f8
    psq_st f6, 0x8(r5), 0, 0
    ps_madd f10, f11, f3, f10
    psq_st f8, 0x18(r5), 0, 0
    psq_st f10, 0x28(r5), 0, 0
    blr
}

asm void lbl_8006E0A4(void) {
    nofralloc
    lis r4, 0xe000
    psq_l f1, 0x0(r3), 0, 0
    psq_l f3, 0x8(r3), 1, 0
    b L_8006E0F0
entry lbl_8006E0B4
    lis r4, 0xe000
    ps_merge00 f1, f1, f2
    lfs f0, 0x19c(r4)
    ps_merge00 f3, f3, f0
    b L_8006E0F0
entry lbl_8006E0C8
    lis r4, 0xe000
    lfs f3, 0x8(r3)
    psq_l f1, 0x0(r3), 0, 0
    b L_8006E0E0
entry lbl_8006E0D8
    lis r4, 0xe000
    ps_merge00 f1, f1, f2
L_8006E0E0:
    lfs f0, 0x19c(r4)
    fneg f3, f3
    ps_neg f1, f1
    ps_merge00 f3, f3, f0
L_8006E0F0:
    psq_l f4, 0x0(r4), 0, 0
    psq_l f6, 0x10(r4), 0, 0
    psq_l f8, 0x20(r4), 0, 0
    ps_mul f4, f4, f1
    psq_l f5, 0x8(r4), 0, 0
    ps_mul f6, f6, f1
    psq_l f7, 0x18(r4), 0, 0
    ps_mul f8, f8, f1
    psq_l f9, 0x28(r4), 0, 0
    ps_madd f4, f5, f3, f4
    ps_madd f6, f7, f3, f6
    ps_madd f8, f9, f3, f8
    ps_sum0 f4, f4, f4, f4
    stfs f4, 0xc(r4)
    ps_sum0 f6, f6, f6, f6
    stfs f6, 0x1c(r4)
    ps_sum0 f8, f8, f8, f8
    stfs f8, 0x2c(r4)
    blr
}

asm void lbl_8006E13C(void) {
    nofralloc
    psq_l f1, 0x0(r3), 0, 0
    lis r4, 0xe000
    lfs f3, 0x8(r3)
    b L_8006E164
entry lbl_8006E14C
    lis r4, 0xe000
    fmr f3, f1
    ps_merge00 f1, f1, f1
    b L_8006E164
entry lbl_8006E15C
    lis r4, 0xe000
    ps_merge00 f1, f1, f2
L_8006E164:
    psq_l f0, 0x0(r4), 0, 0
    lfs f4, 0x8(r4)
    psq_l f5, 0x10(r4), 0, 0
    ps_mul f0, f0, f1
    lfs f6, 0x18(r4)
    fmuls f4, f4, f3
    psq_l f7, 0x20(r4), 0, 0
    lfs f8, 0x28(r4)
    ps_mul f5, f5, f1
    psq_st f0, 0x0(r4), 0, 0
    fmuls f6, f6, f3
    stfs f4, 0x8(r4)
    psq_st f5, 0x10(r4), 0, 0
    ps_mul f7, f7, f1
    stfs f6, 0x18(r4)
    psq_st f7, 0x20(r4), 0, 0
    fmuls f8, f8, f3
    stfs f8, 0x28(r4)
    blr
}

asm void lbl_8006E1B0(register void *p0, register void *p1) {
    nofralloc
    lis r5, 0xe000
    psq_l f1, 0x0(r3), 0, 0
    psq_l f3, 0x8(r3), 1, 0
    b L_8006E204
entry lbl_8006E1C0
    lis r5, 0xe000
    lfs f3, 0x8(r3)
    lfs f0, 0x198(r5)
    psq_l f1, 0x0(r3), 0, 0
    ps_merge00 f3, f3, f0
    b L_8006E204
entry lbl_8006E1D8
    lis r5, 0xe000
    ps_merge00 f1, f1, f2
    lfs f0, 0x19c(r5)
    mr r4, r3
    ps_merge00 f3, f3, f0
    b L_8006E204
entry lbl_8006E1F0
    lis r5, 0xe000
    ps_merge00 f1, f1, f2
    lfs f0, 0x198(r5)
    mr r4, r3
entry fn_8006E200
    ps_merge00 f3, f3, f0
L_8006E204:
    psq_l f4, 0x0(r5), 0, 0
    psq_l f6, 0x10(r5), 0, 0
    ps_mul f4, f4, f1
    psq_l f8, 0x20(r5), 0, 0
    ps_mul f6, f6, f1
    psq_l f5, 0x8(r5), 0, 0
    ps_mul f8, f8, f1
    psq_l f7, 0x18(r5), 0, 0
    ps_madd f4, f5, f3, f4
    psq_l f9, 0x28(r5), 0, 0
    ps_madd f6, f7, f3, f6
    ps_madd f8, f9, f3, f8
    ps_sum0 f4, f4, f4, f4
    stfs f4, 0x0(r4)
    ps_sum0 f6, f6, f6, f6
    stfs f6, 0x4(r4)
    ps_sum0 f8, f8, f8, f8
    stfs f8, 0x8(r4)
    blr
}

asm void fn_8006E250(void) {
    nofralloc
    lfs f1, 0x0(r3)
    lfs f2, 0x4(r3)
    lfs f3, 0x8(r3)
    b L_8006E270
    ps_merge00 f1, f1, f1
    ps_merge00 f2, f2, f2
    ps_merge00 f3, f3, f3
    mr r4, r3
L_8006E270:
    lis r5, 0xe000
    crclr eq
    lfs f10, 0xc(r5)
    lfs f11, 0x1c(r5)
    lfs f12, 0x2c(r5)
    fsubs f1, f1, f10
    fsubs f2, f2, f11
    fsubs f3, f3, f12
    b fn_8006E2D8
entry fn_8006E294
    lis r5, 0xe000
    mr r4, r3
    crset eq
    lfs f1, 0xc(r5)
    lfs f2, 0x1c(r5)
    lfs f3, 0x2c(r5)
    b fn_8006E2D8
entry fn_8006E2B0
    lfs f1, 0x0(r3)
    lfs f2, 0x4(r3)
    lfs f3, 0x8(r3)
    b lbl_8006E2D0
entry lbl_8006E2C0
    ps_merge00 f1, f1, f1
    ps_merge00 f2, f2, f2
    ps_merge00 f3, f3, f3
    mr r4, r3
entry lbl_8006E2D0
    lis r5, 0xe000
    crclr eq
entry fn_8006E2D8
    psq_l f4, 0x0(r5), 0, 0
    lfs f5, 0x8(r5)
    ps_mul f4, f4, f1
    psq_l f6, 0x10(r5), 0, 0
    fmuls f5, f5, f1
    lfs f7, 0x18(r5)
    ps_madd f4, f6, f2, f4
    psq_l f8, 0x20(r5), 0, 0
    fmadds f5, f7, f2, f5
    lfs f9, 0x28(r5)
    beq L_8006E310
    ps_madd f4, f8, f3, f4
    fmadds f5, f9, f3, f5
    b L_8006E318
L_8006E310:
    ps_nmadd f4, f8, f3, f4
    fnmadds f5, f9, f3, f5
L_8006E318:
    psq_st f4, 0x0(r4), 0, 0
    stfs f5, 0x8(r4)
    blr
}

asm void mathutil_mtxA_rotate_x(register s16 p0) {
    nofralloc
    mflr r4
    bl lbl_8006D1C4
    mtlr r4
    lis r4, 0xe000
    ps_merge00 f0, f2, f1
    psq_l f3, 0x4(r4), 0, 0
    psq_l f4, 0x14(r4), 0, 0
    psq_l f5, 0x24(r4), 0, 0
    ps_mul f6, f3, f0
    ps_mul f7, f4, f0
    ps_mul f8, f5, f0
    fneg f1, f1
    ps_sum0 f6, f6, f6, f6
    ps_sum0 f7, f7, f7, f7
    ps_sum0 f8, f8, f8, f8
    ps_merge00 f0, f1, f2
    stfs f6, 0x4(r4)
    ps_mul f6, f3, f0
    stfs f7, 0x14(r4)
    ps_mul f7, f4, f0
    stfs f8, 0x24(r4)
    ps_mul f8, f5, f0
    ps_sum0 f6, f6, f6, f6
    stfs f6, 0x8(r4)
    ps_sum0 f7, f7, f7, f7
    stfs f7, 0x18(r4)
    ps_sum0 f8, f8, f8, f8
    stfs f8, 0x28(r4)
    blr
}

asm void mathutil_mtxA_rotate_y(register s16 angle) {
    nofralloc
    mflr r4
    bl lbl_8006D1C4
    mtlr r4
    lis r4, 0xe000
    ps_merge00 f0, f1, f2
    lfs f3, 0x0(r4)
    lfs f6, 0x8(r4)
    lfs f4, 0x10(r4)
    lfs f7, 0x18(r4)
    lfs f5, 0x20(r4)
    lfs f8, 0x28(r4)
    ps_merge00 f3, f3, f6
    ps_merge00 f4, f4, f7
    ps_merge00 f5, f5, f8
    ps_mul f6, f3, f0
    ps_mul f7, f4, f0
    ps_mul f8, f5, f0
    fneg f1, f1
    ps_sum0 f6, f6, f6, f6
    ps_sum0 f7, f7, f7, f7
    ps_sum0 f8, f8, f8, f8
    ps_merge00 f0, f2, f1
    stfs f6, 0x8(r4)
    ps_mul f6, f3, f0
    stfs f7, 0x18(r4)
    ps_mul f7, f4, f0
    stfs f8, 0x28(r4)
    ps_mul f8, f5, f0
    ps_sum0 f6, f6, f6, f6
    stfs f6, 0x0(r4)
    ps_sum0 f7, f7, f7, f7
    stfs f7, 0x10(r4)
    ps_sum0 f8, f8, f8, f8
    stfs f8, 0x20(r4)
    blr
}

asm void mathutil_mtxA_rotate_z(void) {
    nofralloc
    mflr r4
    bl lbl_8006D1C4
    mtlr r4
entry mathutil_mtxA_rotate_z_s_c
    lis r4, 0xe000
    ps_merge00 f0, f2, f1
    psq_l f3, 0x0(r4), 0, 0
    psq_l f4, 0x10(r4), 0, 0
    psq_l f5, 0x20(r4), 0, 0
    ps_mul f6, f3, f0
    ps_mul f7, f4, f0
    ps_mul f8, f5, f0
    fneg f1, f1
    ps_sum0 f6, f6, f6, f6
    ps_sum0 f7, f7, f7, f7
    ps_sum0 f8, f8, f8, f8
    ps_merge00 f0, f1, f2
    stfs f6, 0x0(r4)
    ps_mul f6, f3, f0
    stfs f7, 0x10(r4)
    ps_mul f7, f4, f0
    stfs f8, 0x20(r4)
    ps_mul f8, f5, f0
    ps_sum0 f6, f6, f6, f6
    stfs f6, 0x4(r4)
    ps_sum0 f7, f7, f7, f7
    stfs f7, 0x14(r4)
    ps_sum0 f8, f8, f8, f8
    stfs f8, 0x24(r4)
    blr
}

asm void mathutil_mtxA_from_quat(register void *p0) {
    nofralloc
    lis r4, 0xe000
    lfs f0, 0x0(r3)
    lfs f1, 0x4(r3)
    lfs f5, 0x19c(r4)
    lfs f2, 0x8(r3)
    fsubs f4, f5, f5
    lfs f3, 0xc(r3)
    fadds f6, f5, f5
    stfs f4, 0xc(r4)
    stfs f4, 0x1c(r4)
    stfs f4, 0x2c(r4)
    fmuls f9, f0, f0
    fmuls f7, f1, f1
    fmuls f8, f2, f2
    fmadds f9, f2, f2, f9
    fmadds f7, f0, f0, f7
    fmadds f8, f1, f1, f8
    fnmsubs f9, f9, f6, f5
    stfs f9, 0x14(r4)
    fnmsubs f7, f7, f6, f5
    stfs f7, 0x28(r4)
    fnmsubs f8, f8, f6, f5
    stfs f8, 0x0(r4)
    fadds f6, f0, f0
    fadds f4, f1, f1
    fadds f5, f2, f2
    fmuls f6, f3, f6
    fmuls f7, f3, f4
    fmuls f8, f3, f5
    fmsubs f9, f1, f5, f6
    stfs f9, 0x18(r4)
    fmadds f10, f1, f5, f6
    stfs f10, 0x24(r4)
    fmsubs f11, f0, f5, f7
    stfs f11, 0x20(r4)
    fmadds f12, f0, f5, f7
    stfs f12, 0x8(r4)
    fmsubs f13, f0, f4, f8
    stfs f13, 0x4(r4)
    fmadds f2, f0, f4, f8
    stfs f2, 0x10(r4)
    blr
}

asm void mathutil_quat_mult(void) {
    nofralloc
    lfs f4, 0x0(r4)
    lfs f5, 0x4(r4)
    lfs f6, 0x8(r4)
    lfs f7, 0xc(r4)
    lfs f8, 0x0(r5)
    lfs f9, 0x4(r5)
    lfs f10, 0x8(r5)
    lfs f11, 0xc(r5)
    fmul f0, f6, f9
    fmul f1, f4, f10
    fmul f2, f5, f8
    fmul f3, f6, f10
    fmsubs f0, f5, f10, f0
    fmsubs f1, f6, f8, f1
    fmsubs f2, f4, f9, f2
    fmadds f3, f5, f9, f3
    fmadds f0, f4, f11, f0
    fmadds f1, f5, f11, f1
    fmadds f2, f6, f11, f2
    fmadds f3, f4, f8, f3
    fmadds f0, f7, f8, f0
    fmadds f1, f7, f9, f1
    fmadds f2, f7, f10, f2
    fmsubs f3, f7, f11, f3
    stfs f0, 0x0(r3)
    stfs f1, 0x4(r3)
    stfs f2, 0x8(r3)
    stfs f3, 0xc(r3)
    blr
}

asm void func_80008378(void) {
    nofralloc
    ps_merge00 f0, f0, f1
    ps_merge00 f1, f2, f3
    b L_8006E5C8
    psq_l f0, 0x0(r3), 0, 0
    psq_l f1, 0x8(r3), 0, 0
L_8006E5C8:
    lis r5, 0xe000
    ps_mul f2, f0, f0
    ps_madd f2, f1, f1, f2
    ps_sum0 f2, f2, f2, f2
    lfs f4, 0x198(r5)
    fcmpu cr0, f2, f4
    blt L_8006E5F0
    ps_merge00 f2, f2, f2
    ps_mul f0, f0, f2
    ps_mul f1, f1, f2
L_8006E5F0:
    psq_st f0, 0x0(r3), 0, 0
    psq_st f1, 0x8(r3), 0, 0
    blr
}

void fn_8006E5FC(f32 *arg0) {
    f32 q[4];
    u32 order[3];
    f32 t;
    f32 s;
    s32 i;
    s32 j;
    s32 k;
    f32 f;

    order[0] = lbl_80094E10[0];
    order[1] = lbl_80094E10[1];
    order[2] = lbl_80094E10[2];
    t = lbl_801A6D00[0][0] + lbl_801A6D00[1][1] + lbl_801A6D00[2][2];

    if (t > lbl_801A73D4) {
        s = lbl_8006D0B4(lbl_801A73D8 + t);
        f = lbl_801A73DC / s;
        arg0[3] = lbl_801A73DC * s;
        arg0[0] = f * (lbl_801A6D00[2][1] - lbl_801A6D00[1][2]);
        arg0[1] = f * (lbl_801A6D00[0][2] - lbl_801A6D00[2][0]);
        arg0[2] = f * (lbl_801A6D00[1][0] - lbl_801A6D00[0][1]);
    } else {
        i = 0;
        if (lbl_801A6D00[1][1] > lbl_801A6D00[0][0]) {
            i = 1;
        }
        if (lbl_801A6D00[2][2] > lbl_801A6D00[i][i]) {
            i = 2;
        }
        j = order[i];
        k = order[j];
        s = lbl_8006D0B4(lbl_801A73D8 + (lbl_801A6D00[i][i] - (lbl_801A6D00[j][j] + lbl_801A6D00[k][k])));
        q[i] = lbl_801A73DC * s;
        if (lbl_801A73D4 != s) {
            s = lbl_801A73DC / s;
        }
        q[3] = s * (lbl_801A6D00[k][j] - lbl_801A6D00[j][k]);
        q[j] = s * (lbl_801A6D00[j][i] + lbl_801A6D00[i][j]);
        q[k] = s * (lbl_801A6D00[k][i] + lbl_801A6D00[i][k]);
        arg0[0] = q[0];
        arg0[1] = q[1];
        arg0[2] = q[2];
        arg0[3] = q[3];
    }
}

#pragma opt_common_subs off
void fn_8006E7E4(Vec4 *arg0, Vec3 *arg1, s32 arg2) {
    f32 length_squared = arg1->x * arg1->x;
    f32 scale;

    length_squared += arg1->y * arg1->y;
    length_squared += arg1->z * arg1->z;

    if (length_squared < lbl_801A73D0) {
        arg0->x = lbl_801A73D4;
        arg0->y = lbl_801A73D4;
        arg0->z = lbl_801A73D4;
        arg0->w = lbl_801A73D8;
    } else {
        s16 a = arg2;
        f32 s = lbl_8006D188(a >> 1);
        scale = lbl_8006D0E8(length_squared);
        scale *= s;
        arg0->x = arg1->x * scale;
        arg0->y = arg1->y * scale;
        arg0->z = arg1->z * scale;
        arg0->w = lbl_8006D188((s16)(a >> 1) + 0x4000);
    }
}
#pragma opt_common_subs reset

#pragma fp_contract off
void fn_8006E8DC(Vec4 *arg0) {
    f32 scale = lbl_801A73D4;
    f32 length_squared = (arg0->x * arg0->x) + (arg0->y * arg0->y) + (arg0->z * arg0->z) + (arg0->w * arg0->w);

    if (length_squared > scale) {
        scale = lbl_8006D0E8(length_squared);
    } else {
        scale = lbl_801A73D8;
    }

    arg0->x = arg0->x * scale;
    arg0->y = arg0->y * scale;
    arg0->z = arg0->z * scale;
    arg0->w = arg0->w * scale;
}

void fn_8006E978(f32 *arg0, Vec3 *arg1, Vec3 *arg2) {
    f32 cx;
    f32 cy;
    f32 cz;
    f32 dot;
    f32 ax;
    f32 ay;
    f32 az;
    f32 n;
    f32 s;

    dot = arg1->x * arg2->x + arg1->y * arg2->y + arg1->z * arg2->z;
    if (dot > lbl_801A73E0) {
        arg0[2] = lbl_801A73D4;
        arg0[1] = lbl_801A73D4;
        arg0[0] = lbl_801A73D4;
        arg0[3] = lbl_801A73D8;
    } else if (dot < lbl_801A73E4) {
        ay = arg1->x;
        az = -arg1->y;
        ax = lbl_801A73D4;
        if (lbl_8006D0B4(arg1->x * arg1->x + az * az) < lbl_801A73E8) {
            ax = -arg1->z;
            ay = lbl_801A73D4;
            az = arg1->x;
        }
        n = lbl_8006D0E8(ax * ax + ay * ay + az * az);
        ax = ax * n;
        ay = ay * n;
        az = az * n;
        arg0[0] = ax;
        arg0[1] = ay;
        arg0[2] = az;
        arg0[3] = lbl_801A73D4;
    } else {
        cx = arg1->y * arg2->z - arg1->z * arg2->y;
        cy = arg1->z * arg2->x - arg1->x * arg2->z;
        cz = arg1->x * arg2->y - arg1->y * arg2->x;
        n = lbl_8006D0E8(cx * cx + cy * cy + cz * cz);
        cx = cx * n;
        cy = cy * n;
        cz = cz * n;
        s = lbl_8006D0B4(lbl_801A73DC * (lbl_801A73D8 - dot));
        cx = cx * s;
        cy = cy * s;
        cz = cz * s;
        arg0[0] = cx;
        arg0[1] = cy;
        arg0[2] = cz;
        arg0[3] = lbl_8006D0B4(lbl_801A73DC * (lbl_801A73D8 + dot));
    }
}

void fn_8006EB4C(Vec4 *arg0, const Vec4 *arg1, const Vec4 *arg2, f32 arg3) {
    f32 bx;
    f32 by;
    f32 bz;
    f32 bw;
    f32 dot;
    f32 w0;
    f32 w1;
    f32 ang;
    f32 s;

    bx = arg2->x;
    dot = arg1->w * (bw = arg2->w) + (arg1->z * (bz = arg2->z) + (arg1->x * bx + arg1->y * (by = arg2->y)));
    if (dot < lbl_801A73D4) {
        dot = -dot;
        bx = -bx;
        by = -by;
        bz = -bz;
        bw = -bw;
    }
    if (lbl_801A73D8 - dot > lbl_801A73E8) {
        ang = fn_80088538(dot);
        s = fn_800883E8(ang);
        w0 = lbl_801A73D8 - arg3;
        w0 = fn_800883E8(w0 * ang) / s;
        w1 = fn_800883E8(arg3 * ang) / s;
    } else {
        w0 = lbl_801A73D8 - arg3;
        w1 = arg3;
    }
    arg0->x = w0 * arg1->x + w1 * bx;
    arg0->y = w0 * arg1->y + w1 * by;
    arg0->z = w0 * arg1->z + w1 * bz;
    arg0->w = w0 * arg1->w + w1 * bw;
}
#pragma fp_contract reset

void fn_8006ED0C(Vec3 *arg0, Vec3 *arg1, s16 *arg2) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sum;

    dx = arg0->x - arg1->x;
    dz = arg0->z - arg1->z;
    dy = arg1->y - arg0->y;
    sum = dx * dx;
    sum += dz * dz;
    arg2[0] = lbl_8006D24C(dy, lbl_8006D0B4(sum));
    arg2[1] = lbl_8006D24C(dx, dz);
    arg2[2] = 0;
}

void fn_8006EDBC(Vec3 *arg0, Vec3 *arg1, s16 *arg2, s16 *arg3) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;

    dx = arg0->x - arg1->x;
    dy = arg1->y - arg0->y;
    dz = arg0->z - arg1->z;
    dist = dx * dx;
    dist += dz * dz;
    *arg2 = lbl_8006D24C(dy, lbl_8006D0B4(dist));
    *arg3 = lbl_8006D24C(dx, dz);
}

void fn_8006EE70(const Vec3 *input, s16 *output) {
    s16 *dst;
    f32 x;
    f32 y;
    f32 z;
    f32 sum;

    dst = output;
    x = -input->x;
    y = input->y;
    z = -input->z;
    sum = x * x;
    sum += z * z;
    dst[0] = lbl_8006D24C(y, lbl_8006D0B4(sum));
    dst[1] = lbl_8006D24C(x, z);
    dst[2] = 0;
}

void fn_8006EF10(void *arg0, s16 *arg1, s16 *arg2) {
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_sum;

    temp_f31 = -(*(f32 *)((u8 *)(arg0)));
    temp_f30 = *(f32 *)((u8 *)(arg0) + 4);
    temp_f29 = -(*(f32 *)((u8 *)(arg0) + 8));
    temp_sum = temp_f31 * temp_f31;
    temp_sum += temp_f29 * temp_f29;
    (*arg1) = lbl_8006D24C(temp_f30, (lbl_8006D0B4(temp_sum)));
    (*arg2) = lbl_8006D24C(temp_f31, temp_f29);
}

f32 fn_8006EFB4(s16 *arg0, f32 arg1, f32 *arg2) {
    f32 *pool;
    f32 z;
    f32 y;
    f32 x;
    f32 v;

    lbl_8006D8D8(arg0[1], arg2, arg1);
    mathutil_mtxA_rotate_x(arg0[0]);
    pool = (f32 *)0xE0000000; /* fzgx-allow: A2 fixed float pool base */
    v = -arg1;
    x = pool[2];
    x *= v;
    y = pool[6];
    y *= v;
    z = pool[10];
    z *= v;
    arg2[0] = x;
    arg2[1] = y;
    arg2[2] = z;
    return y;
}

void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2) {
    f32 dz;
    f32 dy;
    f32 dx;
    f32 distance;
    s32 angle_x;
    s32 angle_y;

    dx = arg0->x - arg1->x;
    dy = arg1->y - arg0->y;
    dz = arg0->z - arg1->z;
    distance = dx * dx;
    distance += dz * dz;
    distance = lbl_8006D0B4(distance);
    angle_x = lbl_8006D24C(dy, distance);
    angle_y = lbl_8006D24C(dx, dz);
    lbl_8006D91C(-arg2);
    mathutil_mtxA_rotate_x(-angle_x);
    mathutil_mtxA_rotate_y(-angle_y);
    lbl_8006E0C8(arg0);
}

void fn_8006F120(Vec3 *arg0, Vec3 *arg1) {
    f32 dz;
    f32 dy;
    f32 dx;
    f32 distance;
    s32 angle_x;
    s32 angle_y;

    dx = arg0->x - arg1->x;
    dy = arg1->y - arg0->y;
    dz = arg0->z - arg1->z;
    distance = dx * dx;
    distance += dz * dz;
    distance = lbl_8006D0B4(distance);
    angle_x = lbl_8006D24C(dy, distance);
    angle_y = lbl_8006D24C(dx, dz);
    lbl_8006D890(-angle_x);
    mathutil_mtxA_rotate_y(-angle_y);
    lbl_8006E0C8(arg0);
}

static inline void mathutil_cross3(Vec3 *a, Vec3 *b, Vec3 *out) {
    f32 ax;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 bz = b->z;
    f32 by = b->y;
    f32 x;
    f32 y;
    f32 z;

    ax = a->x;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

#pragma opt_propagation off
void fn_8006F1F0(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2) {
    Vec3 w;
    Vec3 u;
    Vec3 v;
    Mat34 *p;

    v.x = arg0->x - arg2->x;
    v.y = arg0->y - arg2->y;
    v.z = arg0->z - arg2->z;
    if (lbl_801A73F0 == lbl_8006D668(&v)) {
        lbl_8006D7DC(arg0);
        return;
    }
    mathutil_cross3(arg1, &v, &w);
    if (lbl_801A73F0 == lbl_8006D668(&w)) {
        lbl_8006D7DC(arg0);
        return;
    }
    mathutil_cross3(&v, &w, &u);
    if (lbl_801A73F0 == lbl_8006D668(&u)) {
        lbl_8006D7DC(arg0);
        return;
    }
    p = (Mat34 *)lbl_801A6D00;
    p->unk_0 = w.x;
    p->unk_4 = u.x;
    p->unk_8 = v.x;
    p->unk_C = arg0->x;
    p->unk_10 = w.y;
    p->unk_14 = u.y;
    p->unk_18 = v.y;
    p->unk_1C = arg0->y;
    p->unk_20 = w.z;
    p->unk_24 = u.z;
    p->unk_28 = v.z;
    p->unk_2C = arg0->z;
    lbl_8006DF44();
}
#pragma opt_propagation reset

u16 fn_8006F394(void) {
    /* Preserve the three stack stores observed in retail, including unused y. */
    volatile Vec3 v;
    f32 a, b, c;
    f32 scale = lbl_801A73F4;
    a = *(f32 *)(0xE0000000 + 8);
    c = *(f32 *)(0xE0000000 + 0x28);
    b = *(f32 *)(0xE0000000 + 0x18);
    a *= scale;
    c *= scale;
    b *= scale;
    v.x = a;
    v.y = b;
    v.z = c;
    return lbl_8006D24C(a, c);
}

#pragma opt_propagation off
void fn_8006F3E4(s16 *arg0, s16 *arg1, s16 *arg2) {
    f32 sum;
    f32 mz;
    f32 my;
    f32 mx;
    VecPair vec;
    f32 z;
    f32 x;

    lbl_8006DAEC(arg0, arg1, arg2);

    vec.pos.x = lbl_801A73F0;
    vec.pos.y = lbl_801A73F4;
    vec.pos.z = lbl_801A73F0;

    mx = *(f32 *)(0xE0000000 + 0x08);
    my = *(f32 *)(0xE0000000 + 0x18);
    mz = *(f32 *)(0xE0000000 + 0x28);

    vec.dir.x = mx * lbl_801A73F8;
    vec.dir.y = my * lbl_801A73F8;
    vec.dir.z = mz * lbl_801A73F8;

    lbl_8006E1C0(&vec, &vec);

    x = vec.dir.x;
    z = vec.dir.z;
    sum = x * x;
    sum += z * z;
    *arg1 = lbl_8006D24C(vec.dir.y, lbl_8006D0B4(sum));
    *arg0 = lbl_8006D24C(vec.dir.x, (vec.dir.z)) + -32768;

    lbl_8006D8D8(*arg0);
    mathutil_mtxA_rotate_x(*arg1);

    fn_8006E2B0(&vec, &vec);
    *arg2 = -lbl_8006D24C(vec.pos.x, vec.pos.y);

    lbl_8006DB30();
}
#pragma opt_propagation reset

#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_8006F4E0(s16 *arg0) {
    DirUp v;
    lbl_8006DAEC();
    v.up.x = lbl_801A73F0;
    v.up.y = lbl_801A73F4;
    v.up.z = lbl_801A73F0;
    {
        f32 a, b, c;
        f32 scale = lbl_801A73F8;
        a = *(f32 *)(0xE0000000 + 0x08) * scale;
        b = *(f32 *)(0xE0000000 + 0x18) * scale;
        c = *(f32 *)(0xE0000000 + 0x28) * scale;
        v.dir.x = a;
        v.dir.y = b;
        v.dir.z = c;
    }
    lbl_8006E1C0(&v.up, &v.up);
    {
        f32 z;
        f32 x;
        f32 magnitude;
        x = v.dir.x;
        z = v.dir.z;
        magnitude = x * x;
        magnitude += z * z;
        arg0[0] = lbl_8006D24C(v.dir.y, lbl_8006D0B4(magnitude));
    }
    arg0[1] = lbl_8006D24C(v.dir.x, v.dir.z) - 0x8000;
    lbl_8006D8D8(arg0[1]);
    mathutil_mtxA_rotate_x(arg0[0]);
    fn_8006E2B0(&v.up, &v.up);
    arg0[2] = -lbl_8006D24C(v.up.x, v.up.y);
    lbl_8006DB30();
}
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset

#pragma opt_dead_assignments off
void fn_8006F5C4(s16 *arg0, s16 *arg1, s16 *arg2) {
    Vec3 vec0;
    Vec3 vec1;

    lbl_8006DAEC(arg0, arg1, arg2);

    vec0.y = lbl_801A73F0;
    vec0.x = lbl_801A73F4;
    vec0.z = lbl_801A73F0;
    vec1.x = lbl_801A73F0;
    vec1.y = lbl_801A73F4;
    vec1.z = lbl_801A73F0;

    lbl_8006E1C0(&vec0, &vec0);
    lbl_8006E1C0(&vec1, &vec1);

    *arg0 = lbl_8006D24C(vec0.y, vec0.x);
    {
        f32 y;
        f32 x;
        f32 magnitude;

        y = vec0.y;
        x = vec0.x;
        magnitude = y * y;
        magnitude += x * x;
        *arg1 = -lbl_8006D24C(vec0.z, lbl_8006D0B4(magnitude));
    }

    lbl_8006D91C(*arg0);
    mathutil_mtxA_rotate_y(*arg1);

    fn_8006E2B0(&vec1, &vec1);
    *arg2 = lbl_8006D24C(vec1.z, vec1.y);

    lbl_8006DB30();
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs off
void fn_8006F6A8(EulerAngles *self) {
    Vec3 vec_b;
    Vec3 vec_a;
    f32 zero;
    f32 one;
    f32 sum;

    lbl_8006DAEC();

    zero = lbl_801A73F0;
    one = lbl_801A73F4;

    vec_a.y = zero;
    vec_a.x = one;
    vec_a.z = zero;
    vec_b.x = zero;
    vec_b.y = one;
    vec_b.z = zero;

    lbl_8006E1C0(&vec_a, &vec_a);
    lbl_8006E1C0(&vec_b, &vec_b);

    self->angle_z = lbl_8006D24C(vec_a.y, vec_a.x);
    sum = vec_a.y;
    sum = sum * vec_a.y;
    self->angle_x = -lbl_8006D24C(vec_a.z, lbl_8006D0B4(sum + vec_a.x * vec_a.x));

    lbl_8006D91C(self->angle_z);
    mathutil_mtxA_rotate_y(self->angle_x);
    fn_8006E2B0(&vec_b, &vec_b);
    self->angle_y = lbl_8006D24C(vec_b.z, vec_b.y);

    lbl_8006DB30();
}
#pragma opt_common_subs reset

f32 fn_8006F774(f32 arg0, f32 arg1) {
    lbl_801A6618 = (arg0 * lbl_801A73FC);
    lbl_801A661C = (arg1 * lbl_801A73FC);
    return (arg0 * lbl_801A73FC);
}

void fn_8006F78C(void *arg0, Vec3 *arg1, f32 arg2) {
    f32 value0;
    f32 value1;
    f32 value2;
    f32 factor;

    lbl_8006E1B0(arg0, arg1);
    value2 = arg1->z;
    if (__fabsf(value2) > lbl_801A7400) {
        factor = lbl_801A661C / (value2 * arg2);
        value0 = -arg1->x * factor;
        arg1->x = lbl_801A6618 + value0;
        value1 = arg1->y * factor;
        arg1->y = lbl_801A661C + value1;
    } else {
        arg1->x = lbl_801A7408;
        arg1->y = lbl_801A7408;
    }
}

void fn_8006F828(void *arg0, Vec3 *arg1, f32 arg2) {
    f32 value0;
    f32 value1;
    f32 value2;
    f32 factor;
    f32 cur0;
    f32 cur1;

    lbl_8006E1B0(arg0, arg1);
    value2 = arg1->z;
    if (__fabsf(value2) > lbl_801A7400) {
        factor = lbl_801A661C / (value2 * arg2);
        value0 = -arg1->x * factor;
        arg1->x = lbl_801A6618 + value0;
        value1 = arg1->y * factor;
        arg1->y = lbl_801A661C + value1;
        cur0 = arg1->x;
        if (cur0 < lbl_801A740C * lbl_801A6618 && cur0 > lbl_801A73F0) {
            cur1 = arg1->y;
            if (cur1 < lbl_801A740C * lbl_801A661C && cur1 > lbl_801A73F0) {
                return;
            }
        }
    }
    arg1->x = lbl_801A7408;
    arg1->y = lbl_801A7408;
}

void fn_8006F900(void *arg0, Vec3 *arg1, f32 arg2) {
    f32 value8;
    f32 factor;

    lbl_8006E1B0(arg0, arg1);
    value8 = arg1->z;
    if (__fabsf(value8) > lbl_801A7400) {
        factor = lbl_801A73F8 / (value8 * arg2);
        arg1->x = factor * (arg1->x * (lbl_801A740C * lbl_801A661C / (lbl_801A740C * lbl_801A6618)));
        arg1->y = arg1->y * factor;
    } else {
        arg1->x = lbl_801A7408;
        arg1->y = lbl_801A7408;
    }
}

void fn_8006F9A4(f32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    Vec4 loc_28;
    Vec4 loc_18;
    Vec4 loc_8;

    lbl_8006DBAC((void *)arg1);
    fn_8006E5FC((f32 *)&loc_28);
    lbl_8006DBAC((void *)arg2);
    fn_8006E5FC((f32 *)&loc_18);
    fn_8006EB4C(&loc_8, &loc_28, &loc_18, arg0);
    mathutil_mtxA_from_quat(&loc_8);
    lbl_8006DC34(arg3);
}

static inline void mathutil_cross4(Vec4 *a, Vec4 *b, Vec4 *out) {
    f32 ax = a->x;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 bz = b->z;
    f32 by = b->y;
    f32 x;
    f32 y;
    f32 z;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

void fn_8006FA24(f32 arg0, Vec4 *arg1, Vec4 *arg2, Vec4 *arg3) {
    lbl_8006D5A4((Vec3 *)&arg1[0], (Vec3 *)&arg2[0], (Vec3 *)&arg3[0], arg0);
    lbl_8006D5A4((Vec3 *)&arg1[1], (Vec3 *)&arg2[1], (Vec3 *)&arg3[1], arg0);
    mathutil_cross4(&arg3[0], &arg3[1], &arg3[2]);
    mathutil_cross4(&arg3[2], &arg3[0], &arg3[1]);
    lbl_8006D668(&arg3[0]);
    lbl_8006D668(&arg3[1]);
    lbl_8006D668(&arg3[2]);
}

void fn_8006FB20(f32 arg0, u32 arg1) {
    Vec4 *const p = (Vec4 *)lbl_801A6D00;

    lbl_8006D5A4((Vec3 *)&p[0], (Vec3 *)arg1, (Vec3 *)&p[0], arg0);
    lbl_8006D5A4((Vec3 *)&p[1], (Vec3 *)(arg1 + 16), (Vec3 *)&p[1], arg0);
    mathutil_cross4(&p[0], &p[1], &p[2]);
    mathutil_cross4(&p[2], &p[0], &p[1]);
    lbl_8006D668(&p[0]);
    lbl_8006D668(&p[1]);
    lbl_8006D668(&p[2]);
}

asm void fn_8006FC1C(void) {
    nofralloc
    lbz r6, 0x0(r3)
    lbz r7, 0x0(r4)
    mr r5, r3
    cmpw r6, r7
    li r3, 0x0
    bnelr
L_8006FC34:
    lbzu r6, 0x1(r5)
    lbzu r7, 0x1(r4)
    cmpw r6, r7
    cmpwi cr1, r6, 0x0
    cmpwi cr5, r7, 0x0
    bnelr
    bne cr1, L_8006FC34
    bne cr5, L_8006FC34
    li r3, 0x1
    blr
}

asm void fn_8006FC5C(void) {
    nofralloc
    cmpwi r5, 0x0
    mr r6, r3
    li r3, 0x0
    beqlr
    lbz r7, 0x0(r6)
    lbz r8, 0x0(r4)
    cmpw cr1, r7, r8
    subic. r5, r5, 0x1
    bnelr cr1
    beq L_8006FCAC
L_8006FC84:
    lbzu r7, 0x1(r6)
    lbzu r8, 0x1(r4)
    subic. r5, r5, 0x1
    cmpw cr1, r7, r8
    cmpwi cr5, r7, 0x0
    cmpwi cr6, r8, 0x0
    bnelr cr1
    beq L_8006FCAC
    bne cr5, L_8006FC84
    bne cr6, L_8006FC84
L_8006FCAC:
    li r3, 0x1
    blr
}

