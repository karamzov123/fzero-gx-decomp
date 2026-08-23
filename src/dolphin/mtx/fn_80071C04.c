#pragma push
#pragma force_active on

extern asm void fn_800718BC(void);
extern asm void OSAlloc(void);
extern asm void OSFree(void);
extern unsigned char lbl_8019E210[64];

asm void fn_80071C04(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r0, 0(r3)
    rlwinm.	r0, r0, 0, 0xa, 0xa
    beq	_80071c28
    li	r0, 0
    stw	r0, 8(r3)
    b	_80071c54
_80071c28:
    cmplwi	r4, 0
    bne	_80071c3c
    li	r0, 0
    stw	r0, 8(r3)
    b	_80071c54
_80071c3c:
    lhz	r0, 4(r3)
    mr	r5, r4
    lwz	r4, 4(r4)
    slwi	r0, r0, 4
    add	r4, r4, r0
    bl      fn_800718BC
_80071c54:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80071C64(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    mr	r4, r3
    stw	r0, 0x14(r1)
    lwz	r3, -0x7fb0(r13)
    bl      OSAlloc
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80071C8C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    mr	r4, r3
    stw	r0, 0x14(r1)
    lwz	r3, -0x7fb0(r13)
    bl      OSFree
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80071CB4(void)
{
    nofralloc
    lis     r3, lbl_8019E210@ha
    addi	r3, r3, lbl_8019E210@l
    blr	
}

#pragma pop
