#pragma push
#pragma force_active on

extern unsigned char __global_destructor_chain[4];
extern unsigned char lbl_80094E30[16];
asm void memcpy_fast(void)
{
    nofralloc
    srawi.  r0, r5, 4
    mr      r6, r0
    ble     _800795cc
    rlwinm. r0, r0, 0x1e, 2, 0x1f
    mtctr   r0
    beq     _8007959c
_80079508:
    lwz     r0, 0(r4)
    stw     r0, 0(r3)
    lwz     r0, 4(r4)
    stw     r0, 4(r3)
    lwz     r0, 8(r4)
    stw     r0, 8(r3)
    lwz     r0, 0xc(r4)
    stw     r0, 0xc(r3)
    lwz     r0, 0x10(r4)
    stw     r0, 0x10(r3)
    lwz     r0, 0x14(r4)
    stw     r0, 0x14(r3)
    lwz     r0, 0x18(r4)
    stw     r0, 0x18(r3)
    lwz     r0, 0x1c(r4)
    stw     r0, 0x1c(r3)
    lwz     r0, 0x20(r4)
    stw     r0, 0x20(r3)
    lwz     r0, 0x24(r4)
    stw     r0, 0x24(r3)
    lwz     r0, 0x28(r4)
    stw     r0, 0x28(r3)
    lwz     r0, 0x2c(r4)
    stw     r0, 0x2c(r3)
    lwz     r0, 0x30(r4)
    stw     r0, 0x30(r3)
    lwz     r0, 0x34(r4)
    stw     r0, 0x34(r3)
    lwz     r0, 0x38(r4)
    stw     r0, 0x38(r3)
    lwz     r0, 0x3c(r4)
    addi    r4, r4, 0x40
    stw     r0, 0x3c(r3)
    addi    r3, r3, 0x40
    bdnz    _80079508
    andi.   r6, r6, 3
    beq     _800795cc
_8007959c:
    mtctr   r6
_800795a0:
    lwz     r0, 0(r4)
    stw     r0, 0(r3)
    lwz     r0, 4(r4)
    stw     r0, 4(r3)
    lwz     r0, 8(r4)
    stw     r0, 8(r3)
    lwz     r0, 0xc(r4)
    addi    r4, r4, 0x10
    stw     r0, 0xc(r3)
    addi    r3, r3, 0x10
    bdnz    _800795a0
_800795cc:
    clrlwi. r0, r5, 0x1c
    mr      r5, r0
    blelr
    rlwinm. r0, r0, 0x1d, 3, 0x1f
    mtctr   r0
    beq     _80079638
_800795e4:
    lbz     r0, 0(r4)
    stb     r0, 0(r3)
    lbz     r0, 1(r4)
    stb     r0, 1(r3)
    lbz     r0, 2(r4)
    stb     r0, 2(r3)
    lbz     r0, 3(r4)
    stb     r0, 3(r3)
    lbz     r0, 4(r4)
    stb     r0, 4(r3)
    lbz     r0, 5(r4)
    stb     r0, 5(r3)
    lbz     r0, 6(r4)
    stb     r0, 6(r3)
    lbz     r0, 7(r4)
    addi    r4, r4, 8
    stb     r0, 7(r3)
    addi    r3, r3, 8
    bdnz    _800795e4
    andi.   r5, r5, 7
    beqlr
_80079638:
    mtctr   r5
_8007963c:
    lbz     r0, 0(r4)
    addi    r4, r4, 1
    stb     r0, 0(r3)
    addi    r3, r3, 1
    bdnz    _8007963c
    blr
}

asm void __va_arg(void)
{
    nofralloc
    lbz     r7, 0(r3)
    cmpwi   r4, 3
    mr      r6, r3
    li      r0, 8
    li      r8, 4
    extsb   r7, r7
    li      r9, 1
    li      r5, 0
    li      r10, 0
    li      r11, 4
    bne     _80079698
    lbz     r7, 1(r3)
    addi    r6, r3, 1
    li      r8, 8
    li      r10, 0x20
    extsb   r7, r7
    li      r11, 8
_80079698:
    cmpwi   r4, 2
    bne     _800796b8
    clrlwi. r0, r7, 0x1f
    li      r8, 8
    li      r0, 7
    beq     _800796b4
    li      r5, 1
_800796b4:
    li      r9, 2
_800796b8:
    cmpw    r7, r0
    bge     _800796e0
    add     r7, r7, r5
    lwz     r5, 8(r3)
    mullw   r3, r7, r11
    add     r0, r7, r9
    stb     r0, 0(r6)
    add     r6, r10, r3
    add     r6, r5, r6
    b       _80079708
_800796e0:
    li      r5, 8
    addi    r0, r8, -1
    stb     r5, 0(r6)
    nor     r6, r0, r0
    lwz     r0, 4(r3)
    add     r5, r8, r0
    addi    r0, r5, -1
    and     r6, r6, r0
    add     r0, r6, r8
    stw     r0, 4(r3)
_80079708:
    cmpwi   r4, 0
    bne     _80079714
    lwz     r6, 0(r6)
_80079714:
    mr      r3, r6
    blr
}

asm void __destroy_global_chain(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    mflr    r0
    stw     r0, 0x14(r1)
    b       _80079748
_8007972c:
    lwz     r0, 0(r3)
    li      r4, -1
    stw	r0, __global_destructor_chain
    lwz     r12, 4(r3)
    lwz     r3, 8(r3)
    mtctr   r12
    bctrl
_80079748:
    lwz	r3, __global_destructor_chain
    cmplwi  r3, 0
    bne     _8007972c
    lwz     r0, 0x14(r1)
    mtlr    r0
    addi    r1, r1, 0x10
    blr
}

asm void __cvt_fp2unsigned(void)
{
    nofralloc
    stwu    r1, -0x10(r1)
    lis     r4, lbl_80094E30@h
    ori     r4, r4, lbl_80094E30@l
    li      r3, 0
    lfd     f0, 0(r4)
    lfd     f3, 8(r4)
    lfd     f4, 0x10(r4)
    fcmpu   cr0, f1, f0
    fcmpu   cr6, f1, f3
    blt     _800797b8
    addi    r3, r3, -1
    bge     cr6, _800797b8
    fcmpu   cr7, f1, f4
    fmr     f2, f1
    blt     cr7, _800797a4
    fsub    f2, f1, f4
_800797a4:
    fctiwz  f2, f2
    stfd    f2, 8(r1)
    lwz     r3, 0xc(r1)
    blt     cr7, _800797b8
    addis   r3, r3, -0x8000
_800797b8:
    addi    r1, r1, 0x10
    blr
}

#pragma pop
