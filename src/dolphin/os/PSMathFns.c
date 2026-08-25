#define qr0 0

typedef float f32;

extern void fn_800885DC(void);

/*
 * sdata2 constants are referenced through the r2 small-data anchor with
 * hand-resolved displacements (.sdata2 base 0x801A6E40 + 0x8000 = r2).
 */

#pragma push
#pragma force_active on
extern unsigned char lbl_801A6F4C[4];
extern unsigned char lbl_801A6F48[4];
extern unsigned char lbl_801A6F54[4];
extern unsigned char lbl_801A6F58[4];
extern unsigned char lbl_801A6F50[4];
extern unsigned char lbl_801A6F5C[4];
extern unsigned char lbl_801A6F60[4];
extern unsigned char lbl_801A6F64[4];
extern unsigned char lbl_801A6F68[4];
extern unsigned char lbl_801A6F6C[4];
extern unsigned char lbl_801A6F70[4];
extern unsigned char lbl_801A6F74[4];

asm void psq_st_pair(register f32* m)
{
    nofralloc
    lfs f0, lbl_801A6F4C(r2)
    lfs f1, lbl_801A6F48(r2)
    psq_st  f0, 0x8(m), 0, qr0
    ps_merge01 f2, f0, f1
    psq_st  f0, 0x18(m), 0, qr0
    ps_merge10 f1, f1, f0
    psq_st  f0, 0x20(m), 0, qr0
    psq_st  f2, 0x10(m), 0, qr0
    psq_st  f1, 0x0(m), 0, qr0
    psq_st  f1, 0x28(m), 0, qr0
    blr
}

asm void psq_l_pair(register f32* m, register f32 a, register f32 b, register f32 c)
{
    nofralloc
    lfs f0, lbl_801A6F4C(r2)
    stfs    f1, 0x0(m)
    psq_st  f0, 0x4(m), 0, qr0
    psq_st  f0, 0xc(m), 0, qr0
    stfs    f2, 0x14(m)
    psq_st  f0, 0x18(m), 0, qr0
    psq_st  f0, 0x20(m), 0, qr0
    stfs    f3, 0x28(m)
    stfs    f0, 0x2c(m)
    blr
}

asm void PSMTXMultVecPair(register void* out, register const void* in)
{
    nofralloc
    lfs f1, lbl_801A6F48(r2)
    psq_l   f4, 0x0(in), 0, qr0
    psq_l   f5, 0x8(in), 0, qr0
    fsubs   f0, f1, f1
    fadds   f2, f1, f1
    ps_mul  f6, f4, f4
    ps_merge10 f9, f4, f4
    ps_madd f8, f5, f5, f6
    ps_mul  f7, f5, f5
    ps_sum0 f3, f8, f8, f8
    ps_muls1 f10, f9, f5
    fres    f11, f3
    ps_sum1 f8, f7, f8, f6
    ps_nmsub f3, f3, f11, f2
    ps_muls1 f7, f5, f5
    ps_mul  f3, f11, f3
    ps_sum0 f6, f6, f6, f6
    fmuls   f3, f3, f2
    ps_madd f11, f4, f9, f7
    ps_msub f7, f4, f9, f7
    psq_st  f0, 0xc(out), 1, qr0
    ps_nmsub f6, f6, f3, f1
    ps_nmsub f8, f8, f3, f1
    psq_st  f0, 0x2c(out), 1, qr0
    ps_mul  f11, f11, f3
    ps_mul  f7, f7, f3
    psq_st  f6, 0x28(out), 1, qr0
    ps_madds0 f9, f4, f5, f10
    ps_merge00 f5, f11, f8
    ps_nmsub f10, f10, f2, f9
    ps_merge10 f4, f8, f7
    psq_st  f5, 0x10(out), 0, qr0
    ps_mul  f9, f9, f3
    ps_mul  f10, f10, f3
    psq_st  f4, 0x0(out), 0, qr0
    psq_st  f9, 0x8(out), 1, qr0
    ps_merge10 f7, f10, f0
    ps_merge01 f11, f10, f9
    psq_st  f7, 0x18(out), 0, qr0
    psq_st  f11, 0x20(out), 0, qr0
    blr
}

asm void fn_80015C1C(register f32* m, register f32 a, register f32 b,
                     register f32 c, register f32 d, register f32 e,
                     register f32 f, register f32 g)
{
    nofralloc
    stwu    r1, -0x30(r1)
    lfs     f12, 0x38(r1)
    fsubs   f10, f4, f3
    lfs f11, lbl_801A6F48(r2)
    fsubs   f0, f1, f2
    lfs f9, lbl_801A6F54(r2)
    fadds   f3, f4, f3
    fdivs   f10, f11, f10
    fmuls   f5, f9, f5
    fdivs   f9, f11, f0
    fmuls   f4, f5, f10
    fmuls   f3, f10, f3
    fadds   f0, f1, f2
    fmuls   f1, f6, f4
    fmuls   f2, f6, f3
    fmuls   f0, f9, f0
    stfs    f1, 0x0(m)
    fmuls   f1, f5, f9
    fsubs   f2, f2, f8
    lfs f3, lbl_801A6F4C(r2)
    fmuls   f0, f7, f0
    stfs    f3, 0x4(m)
    fmuls   f1, f7, f1
    stfs    f2, 0x8(m)
    fsubs   f0, f0, f12
    stfs    f3, 0xc(m)
    stfs    f3, 0x10(m)
    stfs    f1, 0x14(m)
    stfs    f0, 0x18(m)
    stfs    f3, 0x1c(m)
    stfs    f3, 0x20(m)
    stfs    f3, 0x24(m)
    lfs f0, lbl_801A6F58(r2)
    stfs    f0, 0x28(m)
    stfs    f3, 0x2c(m)
    addi    r1, r1, 0x30
    blr
}

asm void fn_80015CB0(register f32* m, register f32 fov, register f32 aspect,
                     register f32 nearz, register f32 farz, register f32 unused)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x58(r1)
    stfd    f31, 0x50(r1)
    stfd    f30, 0x48(r1)
    stfd    f29, 0x40(r1)
    stfd    f28, 0x38(r1)
    stfd    f27, 0x30(r1)
    stw     r31, 0x2c(r1)
    fmr     f27, f2
    mr      r31, r3
    fmr     f28, f3
    fmr     f29, f4
    fmr     f30, f5
    fmr     f31, f6
    lfs f2, lbl_801A6F50(r2)
    lfs f0, lbl_801A6F5C(r2)
    fmuls   f1, f2, f1
    fmuls   f1, f0, f1
    bl      fn_800885DC
    lfs f3, lbl_801A6F48(r2)
    fneg    f2, f30
    fneg    f0, f31
    fdivs   f4, f3, f1
    fdivs   f1, f4, f27
    fmuls   f3, f28, f1
    fmuls   f1, f4, f29
    stfs    f3, 0x0(r31)
    lfs f3, lbl_801A6F4C(r2)
    stfs    f3, 0x4(r31)
    stfs    f2, 0x8(r31)
    stfs    f3, 0xc(r31)
    stfs    f3, 0x10(r31)
    stfs    f1, 0x14(r31)
    stfs    f0, 0x18(r31)
    stfs    f3, 0x1c(r31)
    stfs    f3, 0x20(r31)
    stfs    f3, 0x24(r31)
    lfs f0, lbl_801A6F58(r2)
    stfs    f0, 0x28(r31)
    stfs    f3, 0x2c(r31)
    lwz     r0, 0x5c(r1)
    lfd     f31, 0x50(r1)
    lfd     f30, 0x48(r1)
    lfd     f29, 0x40(r1)
    lfd     f28, 0x38(r1)
    lfd     f27, 0x30(r1)
    lwz     r31, 0x2c(r1)
    addi    r1, r1, 0x58
    mtlr    r0
    blr
}

asm void fn_80015D7C(register f32* m, register f32 l, register f32 t,
                     register f32 r, register f32 b, register f32 n,
                     register f32 f)
{
    nofralloc
    fsubs   f9, f4, f3
    lfs f10, lbl_801A6F60(r2)
    fsubs   f0, f1, f2
    lfs f8, lbl_801A6F64(r2)
    fsubs   f7, f6, f5
    fdivs   f11, f10, f9
    fmuls   f8, f8, f5
    fdivs   f9, f10, f0
    fmuls   f0, f8, f11
    fadds   f3, f4, f3
    fadds   f2, f1, f2
    stfs    f0, 0x0(m)
    fmuls   f0, f6, f5
    fdivs   f6, f10, f7
    lfs f4, lbl_801A6F68(r2)
    stfs    f4, 0x4(m)
    fmuls   f3, f11, f3
    fneg    f1, f5
    fneg    f0, f0
    stfs    f3, 0x8(m)
    fmuls   f3, f8, f9
    fmuls   f2, f9, f2
    stfs    f4, 0xc(m)
    fmuls   f1, f1, f6
    stfs    f4, 0x10(m)
    fmuls   f0, f6, f0
    stfs    f3, 0x14(m)
    stfs    f2, 0x18(m)
    stfs    f4, 0x1c(m)
    stfs    f4, 0x20(m)
    stfs    f4, 0x24(m)
    stfs    f1, 0x28(m)
    stfs    f0, 0x2c(m)
    stfs    f4, 0x30(m)
    stfs    f4, 0x34(m)
    lfs f0, lbl_801A6F6C(r2)
    stfs    f0, 0x38(m)
    stfs    f4, 0x3c(m)
    blr
}

asm void fn_80015E18(register f32* m, register f32 t, register f32 b,
                     register f32 l, register f32 r)
{
    nofralloc
    mflr    r0
    stw     r0, 0x4(r1)
    stwu    r1, -0x40(r1)
    stfd    f31, 0x38(r1)
    fmr     f31, f4
    stfd    f30, 0x30(r1)
    fmr     f30, f3
    stfd    f29, 0x28(r1)
    fmr     f29, f2
    stw     r31, 0x24(r1)
    mr      r31, r3
    lfs f5, lbl_801A6F70(r2)
    lfs f0, lbl_801A6F74(r2)
    fmuls   f1, f5, f1
    fmuls   f1, f0, f1
    bl      fn_800885DC
    lfs f3, lbl_801A6F60(r2)
    fsubs   f2, f31, f30
    fmuls   f0, f31, f30
    fdivs   f4, f3, f1
    fdivs   f1, f4, f29
    stfs    f1, 0x0(r31)
    fdivs   f3, f3, f2
    lfs f2, lbl_801A6F68(r2)
    stfs    f2, 0x4(r31)
    stfs    f2, 0x8(r31)
    stfs    f2, 0xc(r31)
    stfs    f2, 0x10(r31)
    fneg    f1, f30
    fneg    f0, f0
    stfs    f4, 0x14(r31)
    fmuls   f1, f1, f3
    stfs    f2, 0x18(r31)
    fmuls   f0, f3, f0
    stfs    f2, 0x1c(r31)
    stfs    f2, 0x20(r31)
    stfs    f2, 0x24(r31)
    stfs    f1, 0x28(r31)
    stfs    f0, 0x2c(r31)
    stfs    f2, 0x30(r31)
    stfs    f2, 0x34(r31)
    lfs f0, lbl_801A6F6C(r2)
    stfs    f0, 0x38(r31)
    stfs    f2, 0x3c(r31)
    lwz     r0, 0x44(r1)
    lfd     f31, 0x38(r1)
    lfd     f30, 0x30(r1)
    lfd     f29, 0x28(r1)
    lwz     r31, 0x24(r1)
    addi    r1, r1, 0x40
    mtlr    r0
    blr
}

asm void MTXOrtho(register f32* m, register f32 l, register f32 t,
                     register f32 r, register f32 b, register f32 n,
                     register f32 f)
{
    nofralloc
    fsubs   f8, f4, f3
    lfs f9, lbl_801A6F60(r2)
    fsubs   f0, f1, f2
    lfs f7, lbl_801A6F64(r2)
    fadds   f3, f4, f3
    fdivs   f10, f9, f8
    fdivs   f8, f9, f0
    fmuls   f4, f7, f10
    fneg    f3, f3
    fsubs   f0, f6, f5
    stfs    f4, 0x0(m)
    fadds   f1, f1, f2
    fmuls   f2, f10, f3
    lfs f3, lbl_801A6F68(r2)
    fneg    f1, f1
    stfs    f3, 0x4(m)
    fdivs   f4, f9, f0
    stfs    f3, 0x8(m)
    stfs    f2, 0xc(m)
    stfs    f3, 0x10(m)
    fmuls   f2, f7, f8
    fneg    f0, f6
    fmuls   f1, f8, f1
    stfs    f2, 0x14(m)
    fmuls   f0, f0, f4
    stfs    f3, 0x18(m)
    stfs    f1, 0x1c(m)
    stfs    f3, 0x20(m)
    stfs    f3, 0x24(m)
    lfs f1, lbl_801A6F6C(r2)
    fmuls   f1, f1, f4
    stfs    f1, 0x28(m)
    stfs    f0, 0x2c(m)
    stfs    f3, 0x30(m)
    stfs    f3, 0x34(m)
    stfs    f3, 0x38(m)
    stfs    f9, 0x3c(m)
    blr
}
#pragma pop
