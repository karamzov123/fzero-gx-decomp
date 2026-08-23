#pragma push
#pragma force_active on

extern asm void OSGetArenaHi(void);
extern asm void OSSetArenaHi(void);
extern asm void OSGetArenaLo(void);
extern asm void OSSetArenaLo(void);

asm void fn_80070CF8(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    addi	r3, r3, 0x1f
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    rlwinm	r30, r3, 0, 0, 0x1a
    lbz	r0, -0x7da0(r13)
    cmplwi	r0, 0
    beq	_80070d34
    bl      OSGetArenaHi
    subf	r31, r30, r3
    mr	r3, r31
    bl      OSSetArenaHi
    b	_80070d44
_80070d34:
    bl      OSGetArenaLo
    mr	r31, r3
    add	r3, r31, r30
    bl      OSSetArenaLo
_80070d44:
    lwz	r0, 0x14(r1)
    mr	r3, r31
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80070D60(void)
{
    nofralloc
    lwz	r0, 0(r3)
    stw	r0, -0x769c(r13)
    lwz	r0, 4(r3)
    stw	r0, -0x76a0(r13)
    lwz	r0, 8(r3)
    stw	r0, -0x76a4(r13)
    lwz	r0, 0xc(r3)
    stw	r0, -0x76a8(r13)
    lwz	r0, 0x10(r3)
    stw	r0, -0x76ac(r13)
    lwz	r0, 0x14(r3)
    stw	r0, -0x76b0(r13)
    blr	
}

asm void fn_80070D94(void)
{
    nofralloc
    lis	r8, -0x7ff9
    lis	r7, -0x7ff9
    lis	r6, -0x7ff9
    lis	r5, -0x7ff9
    lis	r4, -0x7ff9
    lis	r3, -0x7ff9
    addi	r8, r8, 0x1cb4
    addi	r7, r7, 0x1cc0
    addi	r6, r6, 0x1ce0
    addi	r5, r5, 0x1ce8
    addi	r4, r4, 0x1d0c
    addi	r0, r3, 0x1d2c
    stw	r8, -0x769c(r13)
    stw	r7, -0x76a0(r13)
    stw	r6, -0x76a4(r13)
    stw	r5, -0x76a8(r13)
    stw	r4, -0x76ac(r13)
    stw	r0, -0x76b0(r13)
    blr	
}

asm void fn_80070DE0(void)
{
    nofralloc
    lwz	r0, -0x76b4(r13)
    stw	r3, -0x76b4(r13)
    mr	r3, r0
    blr	
}

asm void fn_80070DF0(void)
{
    nofralloc
    lwz	r0, -0x76b8(r13)
    stw	r3, -0x76b8(r13)
    mr	r3, r0
    blr	
}

asm void fn_80070E00(void)
{
    nofralloc
    lis	r4, -0x7ff9
    lis	r3, -0x7ff9
    addi	r4, r4, 0x1c64
    addi	r0, r3, 0x1c8c
    stw	r4, -0x76b4(r13)
    stw	r0, -0x76b8(r13)
    blr	
}

#pragma pop
