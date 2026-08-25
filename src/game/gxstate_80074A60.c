typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void PSVecNormalize3(void);

#pragma push
#pragma force_active on

extern unsigned char lbl_801A6D40[4];
extern unsigned char lbl_801A6D58[4];
extern unsigned char lbl_801A6D5C[4];
extern unsigned char lbl_801A6D60[4];
extern unsigned char lbl_801A6D64[4];
extern unsigned char lbl_801A6D74[4];
extern unsigned char lbl_801A6D7C[4];
extern unsigned char lbl_801A6D80[4];
extern unsigned char lbl_801A6D84[4];
extern unsigned char lbl_801A6D88[8];
extern unsigned char lbl_801A7488[4];
extern unsigned char lbl_801A7484[4];
extern unsigned char lbl_801A7480[4];
extern unsigned char lbl_801A6D70[4];
extern unsigned char lbl_801A6D6C[4];
extern unsigned char lbl_801A6D68[4];

asm void fn_80074A60(register u32 a, register u32 b)
{
    nofralloc
    stw	r3, lbl_801A6D60
    stw	r4, lbl_801A6D5C
    blr
}

asm void fn_80074A6C(void)
{
    nofralloc
    li      r0, -1
    stw	r0, lbl_801A6D60
    stw	r0, lbl_801A6D5C
    blr
}

asm s32 fn_80074A7C(register s32 x)
{
    nofralloc
    lwz	r0, lbl_801A6D40
    stw	r3, lbl_801A6D40
    mr      r3, r0
    blr
}

asm void GXColorClampScale(register f32 r, register f32 g, register f32 b, register f32 a)
{
    nofralloc
    lfs f0, lbl_801A7488(r2)
    stwu    r1, -0x30(r1)
    fcmpu   cr0, f0, f1
    bne     _80074ab4
    fcmpu   cr0, f0, f2
    bne     _80074ab4
    fcmpu   cr0, f0, f3
    bne     _80074ab4
    fcmpu   cr0, f0, f4
    beq     _80074b18
_80074ab4:
    lfs f0, lbl_801A7484(r2)
    li      r0, 1
    addi    r4, r13, -0x7640
    stw	r0, lbl_801A6D88
    fmuls   f5, f0, f1
    fmuls   f2, f0, f2
    fmuls   f1, f0, f3
    fmuls   f0, f0, f4
    fctiwz  f3, f5
    fctiwz  f2, f2
    fctiwz  f1, f1
    fctiwz  f0, f0
    stfd    f3, 8(r1)
    stfd    f2, 0x10(r1)
    lwz     r6, 0xc(r1)
    stfd    f1, 0x18(r1)
    lwz     r5, 0x14(r1)
    stfd    f0, 0x20(r1)
    lwz     r3, 0x1c(r1)
    lwz     r0, 0x24(r1)
    stb	r6, lbl_801A6D80
    stb     r5, 1(r4)
    stb     r3, 2(r4)
    stb     r0, 3(r4)
    b       _80074b38
_80074b18:
    li      r4, 0
    li      r0, 0xff
    addi    r3, r13, -0x7640
    stw	r4, lbl_801A6D88
    stb	r0, lbl_801A6D80
    stb     r0, 1(r3)
    stb     r0, 2(r3)
    stb     r0, 3(r3)
_80074b38:
    addi    r1, r1, 0x30
    blr
}

asm void GXColorPack(register void* rgba)
{
    nofralloc
    lbz     r0, 0(r3)
    cmplwi  r0, 0xff
    bne     _80074b70
    lbz     r0, 1(r3)
    cmplwi  r0, 0xff
    bne     _80074b70
    lbz     r0, 2(r3)
    cmplwi  r0, 0xff
    bne     _80074b70
    lbz     r0, 3(r3)
    cmplwi  r0, 0xff
    beq     _80074ba0
_80074b70:
    li      r0, 1
    addi    r4, r13, -0x7640
    stw	r0, lbl_801A6D88
    lbz     r0, 0(r3)
    stb	r0, lbl_801A6D80
    lbz     r0, 1(r3)
    stb     r0, 1(r4)
    lbz     r0, 2(r3)
    stb     r0, 2(r4)
    lbz     r0, 3(r3)
    stb     r0, 3(r4)
    blr
_80074ba0:
    li      r4, 0
    li      r0, 0xff
    addi    r3, r13, -0x7640
    stw	r4, lbl_801A6D88
    stb	r0, lbl_801A6D80
    stb     r0, 1(r3)
    stb     r0, 2(r3)
    stb     r0, 3(r3)
    blr
}

asm void GXColorScale(register f32 r, register f32 g, register f32 b, register f32 a)
{
    nofralloc
    lfs f0, lbl_801A7480(r2)
    stwu    r1, -0x30(r1)
    fcmpu   cr0, f0, f1
    bne     _80074bec
    fcmpu   cr0, f0, f2
    bne     _80074bec
    fcmpu   cr0, f0, f3
    bne     _80074bec
    fcmpu   cr0, f0, f4
    beq     _80074c50
_80074bec:
    lfs f0, lbl_801A7484(r2)
    li      r0, 1
    addi    r4, r13, -0x7644
    stw	r0, lbl_801A6D84
    fmuls   f5, f0, f1
    fmuls   f2, f0, f2
    fmuls   f1, f0, f3
    fmuls   f0, f0, f4
    fctiwz  f3, f5
    fctiwz  f2, f2
    fctiwz  f1, f1
    fctiwz  f0, f0
    stfd    f3, 8(r1)
    stfd    f2, 0x10(r1)
    lwz     r6, 0xc(r1)
    stfd    f1, 0x18(r1)
    lwz     r5, 0x14(r1)
    stfd    f0, 0x20(r1)
    lwz     r3, 0x1c(r1)
    lwz     r0, 0x24(r1)
    stb	r6, lbl_801A6D7C
    stb     r5, 1(r4)
    stb     r3, 2(r4)
    stb     r0, 3(r4)
    b       _80074c6c
_80074c50:
    li      r0, 0
    addi    r3, r13, -0x7644
    stw	r0, lbl_801A6D84
    stb	r0, lbl_801A6D7C
    stb     r0, 1(r3)
    stb     r0, 2(r3)
    stb     r0, 3(r3)
_80074c6c:
    addi    r1, r1, 0x30
    blr
}

asm void GXColorZeroCheck(register void* rgba)
{
    nofralloc
    lbz     r0, 0(r3)
    cmplwi  r0, 0
    bne     _80074ca4
    lbz     r0, 1(r3)
    cmplwi  r0, 0
    bne     _80074ca4
    lbz     r0, 2(r3)
    cmplwi  r0, 0
    bne     _80074ca4
    lbz     r0, 3(r3)
    cmplwi  r0, 0
    beq     _80074cd4
_80074ca4:
    li      r0, 1
    addi    r4, r13, -0x7644
    stw	r0, lbl_801A6D84
    lbz     r0, 0(r3)
    stb	r0, lbl_801A6D7C
    lbz     r0, 1(r3)
    stb     r0, 1(r4)
    lbz     r0, 2(r3)
    stb     r0, 2(r4)
    lbz     r0, 3(r3)
    stb     r0, 3(r4)
    blr
_80074cd4:
    li      r0, 0
    addi    r3, r13, -0x7644
    stw	r0, lbl_801A6D84
    stb	r0, lbl_801A6D7C
    stb     r0, 1(r3)
    stb     r0, 2(r3)
    stb     r0, 3(r3)
    blr
}

asm void fn_80074CF4(register f32 x, register f32 y, register f32 z)
{
    nofralloc
    lis     r3, -0x7fe6
    stfsu   f1, -0xed0(r3)
    stfs    f2, 4(r3)
    stfs    f3, 8(r3)
    blr
}

asm s32 fn_80074D08(register s32 x)
{
    nofralloc
    lwz	r0, lbl_801A6D74
    stw	r3, lbl_801A6D74
    mr      r3, r0
    blr
}

asm void fn_80074D18(register s32 x)
{
    nofralloc
    cntlzw  r0, r3
    srwi    r0, r0, 5
    stw	r0, lbl_801A6D64
    blr
}

asm void GXProjectVec(register void* mtx)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    lis     r5, -0x7fe6
    stw     r0, 0x14(r1)
    lwz     r4, 0(r3)
    lwz     r0, 4(r3)
    stwu    r4, -0xeb4(r5)
    stw     r0, 4(r5)
    lwz     r0, 8(r3)
    mr      r3, r5
    stw     r0, 8(r5)
    bl      PSVecNormalize3
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_80074D68(register f32 x, register f32 y, register f32 z)
{
    nofralloc
    stfs f1, lbl_801A6D70(r13)
    stfs f2, lbl_801A6D6C(r13)
    stfs f3, lbl_801A6D68(r13)
    blr
}

asm void fn_80074D78(register s32 x)
{
    nofralloc
    cntlzw  r0, r3
    srwi    r0, r0, 5
    stw	r0, lbl_801A6D58
    blr
}

#pragma pop
