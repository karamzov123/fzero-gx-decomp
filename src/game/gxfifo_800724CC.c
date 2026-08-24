typedef unsigned int u32;

#pragma push
#pragma force_active on
extern unsigned char lbl_8019E250[184];

asm void VIConfigureAndFlush(register void* xf, register u32 base)
{
    nofralloc
    mr      r5, r4
    add     r4, r4, r4
    add     r4, r4, r5
    li      r7, 0x10
    add     r5, r4, r4
    lis     r6, -0x3400
    add     r4, r5, r4
    ori     r6, r6, 0x8000
    add     r5, r5, r5
    addis   r5, r5, 0xb
    stb     r7, 0(r6)
    stw     r5, 0(r6)
    psq_l   f0, 0x0(r3), 0, 0
    psq_l   f1, 0x8(r3), 0, 0
    psq_l   f2, 0x10(r3), 0, 0
    psq_l   f3, 0x18(r3), 0, 0
    psq_l   f4, 0x20(r3), 0, 0
    psq_l   f5, 0x28(r3), 0, 0
    psq_st  f0, 0x0(r6), 0, 0
    psq_st  f1, 0x0(r6), 0, 0
    psq_st  f2, 0x0(r6), 0, 0
    psq_st  f3, 0x0(r6), 0, 0
    psq_st  f4, 0x0(r6), 0, 0
    psq_st  f5, 0x0(r6), 0, 0
    addis   r4, r4, 8
    addi    r4, r4, 0x400
    stb     r7, 0(r6)
    stw     r4, 0(r6)
    psq_st  f0, 0x0(r6), 0, 0
    psq_st  f1, 0x0(r6), 1, 0
    psq_st  f2, 0x0(r6), 0, 0
    psq_st  f3, 0x0(r6), 1, 0
    psq_st  f4, 0x0(r6), 0, 0
    psq_st  f5, 0x0(r6), 1, 0
    blr
}

asm void fn_80072558(register u32 a)
{
    nofralloc
    lis     r4, -0x2000
    xor     r3, r3, r3
    mr      r5, r3
    li      r7, 0x10
    lis     r6, -0x3400
    ori     r6, r6, 0x8000
    add     r5, r5, r5
    addis   r5, r5, 0xb
    stb     r7, 0(r6)
    stw     r5, 0(r6)
    psq_l   f0, 0x0(r4), 0, 0
    psq_l   f1, 0x8(r4), 0, 0
    psq_l   f2, 0x10(r4), 0, 0
    psq_l   f3, 0x18(r4), 0, 0
    psq_l   f4, 0x20(r4), 0, 0
    psq_l   f5, 0x28(r4), 0, 0
    psq_st  f0, 0x0(r6), 0, 0
    psq_st  f1, 0x0(r6), 0, 0
    psq_st  f2, 0x0(r6), 0, 0
    psq_st  f3, 0x0(r6), 0, 0
    psq_st  f4, 0x0(r6), 0, 0
    psq_st  f5, 0x0(r6), 0, 0
    addis   r3, r3, 8
    addi    r3, r3, 0x400
    stb     r7, 0(r6)
    stw     r3, 0(r6)
    psq_st  f0, 0x0(r6), 0, 0
    psq_st  f1, 0x0(r6), 1, 0
    psq_st  f2, 0x0(r6), 0, 0
    psq_st  f3, 0x0(r6), 1, 0
    psq_st  f4, 0x0(r6), 0, 0
    psq_st  f5, 0x0(r6), 1, 0
    blr
}

asm void fn_800725DC(register u32 val)
{
    nofralloc
    lis     r4, lbl_8019E250@ha
    lwz     r5, 0(r3)
    addi    r3, r4, lbl_8019E250@l
    lis     r4, -0x33ff
    lwz     r0, 0x30(r3)
    cmplw   r0, r5
    beqlr
    stw     r5, 0x30(r3)
    li      r3, 0x10
    li      r0, 0x100c
    stb     r3, -0x8000(r4)
    stw     r0, -0x8000(r4)
    stw     r5, -0x8000(r4)
    blr
}

asm void fn_80072614(register u32 val)
{
    nofralloc
    lis     r4, lbl_8019E250@ha
    lwz     r5, 0(r3)
    addi    r3, r4, lbl_8019E250@l
    lis     r4, -0x33ff
    lwz     r0, 0x34(r3)
    cmplw   r0, r5
    beqlr
    stw     r5, 0x34(r3)
    li      r3, 0x10
    li      r0, 0x100a
    stb     r3, -0x8000(r4)
    stw     r0, -0x8000(r4)
    stw     r5, -0x8000(r4)
    blr
}

#pragma pop
