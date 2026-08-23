typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void fn_8006D668(void);

#pragma push
#pragma force_active on

asm void fn_80074A60(register u32 a, register u32 b)
{
    nofralloc
    stw     r3, -0x7660(r13)
    stw     r4, -0x7664(r13)
    blr
}

asm void fn_80074A6C(void)
{
    nofralloc
    li      r0, -1
    stw     r0, -0x7660(r13)
    stw     r0, -0x7664(r13)
    blr
}

asm s32 fn_80074A7C(register s32 x)
{
    nofralloc
    lwz     r0, -0x7680(r13)
    stw     r3, -0x7680(r13)
    mr      r3, r0
    blr
}

asm void fn_80074A8C(register f32 r, register f32 g, register f32 b, register f32 a)
{
    nofralloc
    lfs     f0, -0x79b8(r2)
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
    lfs     f0, -0x79bc(r2)
    li      r0, 1
    addi    r4, r13, -0x7640
    stw     r0, -0x7638(r13)
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
    stb     r6, -0x7640(r13)
    stb     r5, 1(r4)
    stb     r3, 2(r4)
    stb     r0, 3(r4)
    b       _80074b38
_80074b18:
    li      r4, 0
    li      r0, 0xff
    addi    r3, r13, -0x7640
    stw     r4, -0x7638(r13)
    stb     r0, -0x7640(r13)
    stb     r0, 1(r3)
    stb     r0, 2(r3)
    stb     r0, 3(r3)
_80074b38:
    addi    r1, r1, 0x30
    blr
}

asm void fn_80074B40(register void* rgba)
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
    stw     r0, -0x7638(r13)
    lbz     r0, 0(r3)
    stb     r0, -0x7640(r13)
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
    stw     r4, -0x7638(r13)
    stb     r0, -0x7640(r13)
    stb     r0, 1(r3)
    stb     r0, 2(r3)
    stb     r0, 3(r3)
    blr
}

asm void fn_80074BC4(register f32 r, register f32 g, register f32 b, register f32 a)
{
    nofralloc
    lfs     f0, -0x79c0(r2)
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
    lfs     f0, -0x79bc(r2)
    li      r0, 1
    addi    r4, r13, -0x7644
    stw     r0, -0x763c(r13)
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
    stb     r6, -0x7644(r13)
    stb     r5, 1(r4)
    stb     r3, 2(r4)
    stb     r0, 3(r4)
    b       _80074c6c
_80074c50:
    li      r0, 0
    addi    r3, r13, -0x7644
    stw     r0, -0x763c(r13)
    stb     r0, -0x7644(r13)
    stb     r0, 1(r3)
    stb     r0, 2(r3)
    stb     r0, 3(r3)
_80074c6c:
    addi    r1, r1, 0x30
    blr
}

asm void fn_80074C74(register void* rgba)
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
    stw     r0, -0x763c(r13)
    lbz     r0, 0(r3)
    stb     r0, -0x7644(r13)
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
    stw     r0, -0x763c(r13)
    stb     r0, -0x7644(r13)
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
    lwz     r0, -0x764c(r13)
    stw     r3, -0x764c(r13)
    mr      r3, r0
    blr
}

asm void fn_80074D18(register s32 x)
{
    nofralloc
    cntlzw  r0, r3
    srwi    r0, r0, 5
    stw     r0, -0x765c(r13)
    blr
}

asm void fn_80074D28(register void* mtx)
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
    bl      fn_8006D668
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void fn_80074D68(register f32 x, register f32 y, register f32 z)
{
    nofralloc
    stfs    f1, -0x7650(r13)
    stfs    f2, -0x7654(r13)
    stfs    f3, -0x7658(r13)
    blr
}

asm void fn_80074D78(register s32 x)
{
    nofralloc
    cntlzw  r0, r3
    srwi    r0, r0, 5
    stw     r0, -0x7668(r13)
    blr
}

#pragma pop
