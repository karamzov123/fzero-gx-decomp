#pragma push
#pragma force_active on

extern void fn_80051F38(void);
extern void memset(void);
extern unsigned char adxt_sincos_table[8320];
extern unsigned char jumptable_80130BC0[64];
extern unsigned char lbl_801319E0[2176];
extern unsigned char lbl_80187370[16];
extern unsigned char lbl_80187380[64];
extern unsigned char lbl_801873C0[24];

asm void fn_80053A30(void)
{
    nofralloc
    li	r3, 0
    blr	
}

asm void fn_80053A38(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r4, 0
    li	r5, 0x2014
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    lbz	r31, 1(r3)
    extsb	r31, r31
    bl      memset
    lis     r3, lbl_80187380@ha
    slwi	r0, r31, 2
    addi	r3, r3, lbl_80187380@l
    li	r4, 0
    stwx	r4, r3, r0
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80053A84(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis     r5, lbl_80187370@ha
    stw	r0, 0x24(r1)
    li	r0, 2
    stw	r31, 0x1c(r1)
    addi	r31, r5, lbl_80187370@l
    stw	r30, 0x18(r1)
    li	r30, 0
    stw	r29, 0x14(r1)
    mr	r29, r3
    addi	r3, r31, 0x10
    mtctr	r0
_80053ab8:
    lwz	r0, 0(r3)
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    lwzu	r0, 4(r3)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80053b40
    addi	r3, r3, 4
    addi	r30, r30, 1
    bdnz    _80053ab8
_80053b40:
    cmpwi	r30, 0x10
    bne     _80053b50
    li	r3, 0
    b       _80053b98
_80053b50:
    mr	r3, r29
    mr	r5, r4
    li	r4, 0
    bl      memset
    slwi	r3, r30, 2
    addi	r5, r31, 0x10
    stwx	r29, r5, r3
    li	r4, 0x40
    li	r0, 1
    lwzx	r3, r5, r3
    stb	r30, 1(r3)
    stw	r4, 8(r3)
    stw	r4, 4(r3)
    lwz	r4, 8(r31)
    stw	r4, 0x10(r3)
    lwz	r4, 0xc(r31)
    stw	r4, 0xc(r3)
    stb	r0, 0(r3)
_80053b98:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80053BB4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80187370@ha
    stw	r0, 0x14(r1)
    addi	r4, r3, lbl_80187370@l
    lwz	r3, 0(r4)
    addic.	r0, r3, -1
    stw	r0, 0(r4)
    bne     _80053bec
    lis     r3, lbl_80187380@ha
    li	r4, 0
    addi	r3, r3, lbl_80187380@l
    li	r5, 0x40
    bl      memset
_80053bec:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80053BFC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80187370@ha
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    addi	r31, r3, lbl_80187370@l
    lwz	r0, 0(r31)
    cmpwi	r0, 0
    bne     _80053d94
    addi	r3, r31, 0x10
    li	r4, 0
    li	r5, 0x40
    bl      memset
    lwz	r0, 4(r31)
    cmpwi	r0, 0
    bne     _80053d94
    lis     r3, lbl_801319E0@ha
    li	r0, 0x2ab
    addi	r4, r3, lbl_801319E0@l
    addi	r3, r4, 0x1f
    rlwinm	r3, r3, 0, 0, 0x1a
    addi	r4, r4, 0x800
    stw	r3, 8(r31)
    addi	r3, r3, 0x800
    mtctr	r0
_80053c60:
    lbz	r0, 0(r4)
    stb	r0, 0(r3)
    lbz	r0, -1(r4)
    stb	r0, -1(r3)
    lbz	r0, -2(r4)
    addi	r4, r4, -3
    stb	r0, -2(r3)
    addi	r3, r3, -3
    bdnz    _80053c60
    li	r10, 0
    cmpwi	r10, 0x200
    bge     _80053d44
    lis	r3, -0x7ff7
    li	r0, 0x40
    lfs	f1, 0x1350(r3)
    mtctr	r0
_80053ca0:
    lwz	r9, 8(r31)
    addi	r8, r10, 4
    addi	r7, r10, 8
    addi	r6, r10, 0xc
    lfsx	f0, r9, r10
    addi	r5, r10, 0x10
    addi	r4, r10, 0x14
    addi	r3, r10, 0x18
    fmuls	f0, f0, f1
    addi	r0, r10, 0x1c
    stfsx	f0, r9, r10
    addi	r10, r10, 0x20
    lwz	r9, 8(r31)
    lfsx	f0, r9, r8
    fmuls	f0, f0, f1
    stfsx	f0, r9, r8
    lwz	r8, 8(r31)
    lfsx	f0, r8, r7
    fmuls	f0, f0, f1
    stfsx	f0, r8, r7
    lwz	r7, 8(r31)
    lfsx	f0, r7, r6
    fmuls	f0, f0, f1
    stfsx	f0, r7, r6
    lwz	r6, 8(r31)
    lfsx	f0, r6, r5
    fmuls	f0, f0, f1
    stfsx	f0, r6, r5
    lwz	r5, 8(r31)
    lfsx	f0, r5, r4
    fmuls	f0, f0, f1
    stfsx	f0, r5, r4
    lwz	r4, 8(r31)
    lfsx	f0, r4, r3
    fmuls	f0, f0, f1
    stfsx	f0, r4, r3
    lwz	r3, 8(r31)
    lfsx	f0, r3, r0
    fmuls	f0, f0, f1
    stfsx	f0, r3, r0
    bdnz    _80053ca0
_80053d44:
    lis     r3, adxt_sincos_table@ha
    li	r0, 0xaab
    addi	r4, r3, adxt_sincos_table@l
    addi	r3, r4, 0x1f
    rlwinm	r3, r3, 0, 0, 0x1a
    addi	r4, r4, 0x2000
    stw	r3, 0xc(r31)
    addi	r3, r3, 0x2000
    mtctr	r0
_80053d68:
    lbz	r0, 0(r4)
    stb	r0, 0(r3)
    lbz	r0, -1(r4)
    stb	r0, -1(r3)
    lbz	r0, -2(r4)
    addi	r4, r4, -3
    stb	r0, -2(r3)
    addi	r3, r3, -3
    bdnz    _80053d68
    li	r0, 1
    stw	r0, 4(r31)
_80053d94:
    lwz	r3, 0(r31)
    addi	r0, r3, 1
    stw	r0, 0(r31)
    lwz	r31, 0xc(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80053DB4(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    slwi	r0, r5, 2
    stmw	r25, 0x14(r1)
    mr	r29, r3
    add	r27, r29, r0
    slwi	r0, r5, 0xc
    add	r31, r29, r0
    mr	r25, r4
    mr	r30, r6
    lwz	r3, 4(r27)
    addi	r0, r3, -0x40
    clrlwi	r0, r0, 0x16
    stw	r0, 4(r27)
    lwz	r0, 4(r27)
    lwz	r28, 0xc(r29)
    slwi	r3, r0, 2
    addi	r26, r3, 0x14
    add	r26, r31, r26
    bl      fn_80053A30
    lis	r4, -0x7fe8
    clrlwi.	r0, r25, 0x1b
    stw	r3, 0x73c0(r4)
    bne     _80053e20
    clrlwi.	r0, r28, 0x1b
    beq     _80053e24
_80053e20:
    b       _80053e20
_80053e24:
    mr	r3, r25
    mr	r4, r28
    mr	r5, r26
    bl      fn_80051F38
    bl      fn_80053A30
    lis     r4, lbl_801873C0@ha
    addi	r28, r4, lbl_801873C0@l
    stw	r3, 0x10(r28)
    lwz	r27, 4(r27)
    bl      fn_80053A30
    srawi	r0, r27, 6
    lis	r5, -0x7fe8
    stw	r3, 0x73c0(r5)
    lis     r4, jumptable_80130BC0@ha
    addi	r3, r4, jumptable_80130BC0@l
    slwi	r0, r0, 2
    lwzx	r12, r3, r0
    slwi	r6, r27, 2
    mr	r5, r30
    lwz	r4, 0x10(r29)
    add	r3, r31, r6
    mtctr	r12
    addi	r3, r3, 0x14
    bctrl	
    bl      fn_80053A30
    stw	r3, 0x10(r28)
    lmw	r25, 0x14(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
