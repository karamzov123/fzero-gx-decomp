#pragma push
#pragma force_active on

extern asm void fn_8006D24C(void);
extern asm void fn_8006DAEC(void);
extern asm void lbl_8006E1C0(void);
extern asm void fn_8006D0B4(void);
extern asm void fn_8006D8D8(void);
extern asm void fn_8006E324(void);
extern asm void PSMTXMultVecSS(void);
extern asm void fn_8006DB30(void);
extern asm void fn_8006D91C(void);
extern asm void fn_8006E398(void);

asm void fn_8006F394(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r3, -0x2000
    lfs	f3, -0x7a4c(r2)
    stw	r0, 0x24(r1)
    lfs	f1, 8(r3)
    lfs	f2, 0x28(r3)
    lfs	f0, 0x18(r3)
    fmuls	f1, f1, f3
    fmuls	f2, f2, f3
    fmuls	f0, f0, f3
    stfs	f1, 8(r1)
    stfs	f0, 0xc(r1)
    stfs	f2, 0x10(r1)
    bl      fn_8006D24C
    lwz	r0, 0x24(r1)
    clrlwi	r3, r3, 0x10
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_8006F3E4(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    mr	r31, r5
    stw	r30, 0x28(r1)
    mr	r30, r4
    stw	r29, 0x24(r1)
    mr	r29, r3
    bl      fn_8006DAEC
    lfs	f1, -0x7a50(r2)
    addi	r3, r1, 8
    lfs	f0, -0x7a4c(r2)
    lis	r5, -0x2000
    stfs	f1, 8(r1)
    mr	r4, r3
    lfs	f3, -0x7a48(r2)
    stfs	f0, 0xc(r1)
    stfs	f1, 0x10(r1)
    lfs	f2, 8(r5)
    lfs	f1, 0x18(r5)
    lfs	f0, 0x28(r5)
    fmuls	f2, f2, f3
    fmuls	f1, f1, f3
    fmuls	f0, f0, f3
    stfs	f2, 0x14(r1)
    stfs	f1, 0x18(r1)
    stfs	f0, 0x1c(r1)
    bl      lbl_8006E1C0
    lfs	f1, 0x14(r1)
    lfs	f0, 0x1c(r1)
    fmuls	f1, f1, f1
    fmadds	f1, f0, f0, f1
    bl      fn_8006D0B4
    fmr	f2, f1
    lfs	f1, 0x18(r1)
    bl      fn_8006D24C
    sth	r3, 0(r30)
    lfs	f1, 0x14(r1)
    lfs	f2, 0x1c(r1)
    bl      fn_8006D24C
    addi	r0, r3, -0x8000
    sth	r0, 0(r29)
    lha	r3, 0(r29)
    bl      fn_8006D8D8
    lha	r3, 0(r30)
    bl      fn_8006E324
    addi	r3, r1, 8
    mr	r4, r3
    bl      PSMTXMultVecSS
    lfs	f1, 8(r1)
    lfs	f2, 0xc(r1)
    bl      fn_8006D24C
    neg	r0, r3
    sth	r0, 0(r31)
    bl      fn_8006DB30
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8006F4E0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    mr	r31, r3
    bl      fn_8006DAEC
    lfs	f1, -0x7a50(r2)
    addi	r3, r1, 0x14
    lfs	f0, -0x7a4c(r2)
    lis	r5, -0x2000
    stfs	f1, 0x14(r1)
    mr	r4, r3
    lfs	f3, -0x7a48(r2)
    stfs	f0, 0x18(r1)
    stfs	f1, 0x1c(r1)
    lfs	f2, 8(r5)
    lfs	f1, 0x18(r5)
    lfs	f0, 0x28(r5)
    fmuls	f2, f2, f3
    fmuls	f1, f1, f3
    fmuls	f0, f0, f3
    stfs	f2, 8(r1)
    stfs	f1, 0xc(r1)
    stfs	f0, 0x10(r1)
    bl      lbl_8006E1C0
    lfs	f1, 8(r1)
    lfs	f0, 0x10(r1)
    fmuls	f1, f1, f1
    fmadds	f1, f0, f0, f1
    bl      fn_8006D0B4
    fmr	f2, f1
    lfs	f1, 0xc(r1)
    bl      fn_8006D24C
    sth	r3, 0(r31)
    lfs	f1, 8(r1)
    lfs	f2, 0x10(r1)
    bl      fn_8006D24C
    addi	r0, r3, -0x8000
    sth	r0, 2(r31)
    lha	r3, 2(r31)
    bl      fn_8006D8D8
    lha	r3, 0(r31)
    bl      fn_8006E324
    addi	r3, r1, 0x14
    mr	r4, r3
    bl      PSMTXMultVecSS
    lfs	f1, 0x14(r1)
    lfs	f2, 0x18(r1)
    bl      fn_8006D24C
    neg	r0, r3
    sth	r0, 4(r31)
    bl      fn_8006DB30
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_8006F5C4(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    mr	r31, r5
    stw	r30, 0x28(r1)
    mr	r30, r4
    stw	r29, 0x24(r1)
    mr	r29, r3
    bl      fn_8006DAEC
    lfs	f0, -0x7a50(r2)
    addi	r3, r1, 0x14
    lfs	f1, -0x7a4c(r2)
    mr	r4, r3
    stfs	f0, 0x18(r1)
    stfs	f1, 0x14(r1)
    stfs	f0, 0x1c(r1)
    stfs	f0, 8(r1)
    stfs	f1, 0xc(r1)
    stfs	f0, 0x10(r1)
    bl      lbl_8006E1C0
    addi	r3, r1, 8
    mr	r4, r3
    bl      lbl_8006E1C0
    lfs	f1, 0x18(r1)
    lfs	f2, 0x14(r1)
    bl      fn_8006D24C
    sth	r3, 0(r29)
    lfs	f1, 0x18(r1)
    lfs	f0, 0x14(r1)
    fmuls	f1, f1, f1
    fmadds	f1, f0, f0, f1
    bl      fn_8006D0B4
    fmr	f2, f1
    lfs	f1, 0x1c(r1)
    bl      fn_8006D24C
    neg	r0, r3
    sth	r0, 0(r30)
    lha	r3, 0(r29)
    bl      fn_8006D91C
    lha	r3, 0(r30)
    bl      fn_8006E398
    addi	r3, r1, 8
    mr	r4, r3
    bl      PSMTXMultVecSS
    lfs	f1, 0x10(r1)
    lfs	f2, 0xc(r1)
    bl      fn_8006D24C
    sth	r3, 0(r31)
    bl      fn_8006DB30
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
