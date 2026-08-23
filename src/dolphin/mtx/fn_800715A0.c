#pragma push
#pragma force_active on

extern asm void fn_8007174C(void);
extern asm void DCInvalidateRange(void);
extern asm void AIGetDSPInterruptEnable(void);
extern asm void ARStartDMA(void);
extern asm void sprintf(void);
extern asm void OSPanic(void);
extern unsigned char lbl_8015ABC0[10];
extern unsigned char lbl_8015ABCC[12];
extern unsigned char lbl_8015ABD8[35];
extern unsigned char lbl_8015ABFC[9];

asm void fn_800715A0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r4
    addi	r0, r29, 0x1f
    stw	r28, 0x10(r1)
    rlwinm	r31, r0, 0, 0, 0x1a
    mr	r28, r3
    lwz	r12, -0x76b4(r13)
    addi	r3, r31, 0x20
    mtctr	r12
    bctrl	
    or.	r30, r3, r3
    bne	_800715f8
    lis     r3, lbl_8015ABD8@ha
    lis     r4, lbl_8015ABC0@ha
    addi	r3, r3, lbl_8015ABD8@l
    addi	r4, r4, lbl_8015ABC0@l
    bl      fn_8007174C
_800715f8:
    addi	r0, r30, 0x3f
    mr	r4, r31
    rlwinm	r31, r0, 0, 0, 0x1a
    mr	r3, r31
    bl      DCInvalidateRange
_8007160c:
    bl      AIGetDSPInterruptEnable
    cmplwi	r3, 0
    bne	_8007160c
    mr	r4, r31
    mr	r5, r28
    mr	r6, r29
    li	r3, 1
    bl      ARStartDMA
_8007162c:
    bl      AIGetDSPInterruptEnable
    cmplwi	r3, 0
    bne	_8007162c
    lwz	r5, 0(r31)
    addi	r4, r31, 4
    li	r0, 0
    mr	r3, r30
    stw	r5, 0(r30)
    stw	r4, 4(r30)
    stw	r31, 8(r30)
    stw	r0, 0xc(r30)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80071678(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r4, r4
    li	r4, 0
    stw	r30, 8(r1)
    mr	r30, r3
    bne	_800716cc
    lwz	r12, -0x76b4(r13)
    li	r3, 0x20
    mtctr	r12
    bctrl	
    or.	r31, r3, r3
    bne	_800716c8
    lis     r3, lbl_8015ABD8@ha
    lis     r4, lbl_8015ABCC@ha
    addi	r3, r3, lbl_8015ABD8@l
    addi	r4, r4, lbl_8015ABCC@l
    bl      fn_8007174C
_800716c8:
    li	r4, 1
_800716cc:
    lwz	r3, 0(r30)
    addi	r0, r30, 4
    cmpwi	r4, 0
    stw	r3, 0(r31)
    stw	r0, 4(r31)
    stw	r30, 8(r31)
    bne	_800716f4
    li	r0, 1
    stw	r0, 0xc(r31)
    b	_800716fc
_800716f4:
    li	r0, 0
    stw	r0, 0xc(r31)
_800716fc:
    lwz	r0, 0x14(r1)
    mr	r3, r31
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80071718(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r0, 0xc(r3)
    clrlwi.	r0, r0, 0x1f
    bne	_8007173c
    lwz	r12, -0x76b8(r13)
    mtctr	r12
    bctrl	
_8007173c:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8007174C(void)
{
    nofralloc
    stwu	r1, -0x410(r1)
    mflr	r0
    mr	r5, r4
    mr	r4, r3
    stw	r0, 0x414(r1)
    addi	r3, r1, 8
    crxor	6, 6, 6
    bl      sprintf
    lis     r3, lbl_8015ABFC@ha
    addi	r5, r1, 8
    addi	r3, r3, lbl_8015ABFC@l
    li	r4, 0x1f2
    crxor	6, 6, 6
    bl      OSPanic
    lwz	r0, 0x414(r1)
    mtlr	r0
    addi	r1, r1, 0x410
    blr	
}

#pragma pop
