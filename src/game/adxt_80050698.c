#pragma push
#pragma force_active on

extern void fn_800501F4(void);
extern unsigned char lbl_80130A48[];
extern unsigned char lbl_80130B98[];

asm void ADXF_Stop(void)
{
    nofralloc
    stwu	r1, -0x80(r1)
    mflr	r0
    stw	r0, 0x84(r1)
    stfd	f31, 0x70(r1)
    psq_st	f31, 0x78(r1), 0, 0
    stfd	f30, 0x60(r1)
    psq_st	f30, 0x68(r1), 0, 0
    stmw	r17, 0x24(r1)
    lwz	r25, 0x18(r4)
    mr	r18, r8
    lwz	r21, 4(r4)
    lis	r10, -0x7fe8
    slwi	r0, r7, 7
    lwz	r20, 0x10(r4)
    lwz	r19, 0x14(r4)
    li	r8, 0
    lis	r9, -0x7fe8
    mr	r17, r3
    stw	r8, 0x7114(r10)
    mr	r28, r5
    mr	r26, r18
    add	r27, r6, r0
    stw	r8, 0x6fa8(r9)
    li	r24, 0
    b       _80050b5c
_800506fc:
    mr	r31, r28
    mr	r30, r27
    mr	r29, r26
    li	r23, 0
    b       _80050b30
_80050710:
    lwz	r0, 0(r31)
    cmpwi	r0, 0
    beq     _80050ae4
    mulli	r5, r0, 0x18
    lwz	r0, 0(r30)
    lis     r3, lbl_80130A48@ha
    slwi	r4, r0, 2
    add	r5, r25, r5
    addi    r3, r3, lbl_80130A48@l
    lwz	r0, 8(r5)
    lfsx	f2, r3, r4
    lfs	f1, 0x10(r5)
    cmpwi	r0, 3
    lfs	f0, 0x14(r5)
    fmuls	f31, f1, f2
    fmuls	f30, f0, f2
    bne     _8005089c
    lwz	r22, 4(r5)
    cmpwi	r22, 8
    bgt     _800507f4
    add	r4, r22, r22
    mr	r3, r17
    add	r4, r22, r4
    bl      fn_800501F4
    lis     r6, lbl_80130B98@ha
    lis	r4, 0x4330
    slwi	r0, r22, 2
    lis	r5, -0x7ff7
    addi    r6, r6, lbl_80130B98@l
    sraw	r7, r3, r22
    lwzx	r0, r6, r0
    stw	r4, 8(r1)
    and	r3, r3, r0
    and	r0, r7, r0
    xoris	r3, r3, 0x8000
    lfd	f3, 0x12f8(r5)
    stw	r3, 0xc(r1)
    xoris	r3, r0, 0x8000
    sraw	r7, r7, r22
    lfd	f0, 8(r1)
    xoris	r0, r7, 0x8000
    stw	r3, 0x14(r1)
    fsubs	f1, f0, f3
    stw	r4, 0x10(r1)
    fmadds	f2, f31, f1, f30
    lfd	f0, 0x10(r1)
    stw	r0, 0x1c(r1)
    fsubs	f1, f0, f3
    stw	r4, 0x18(r1)
    lfd	f0, 0x18(r1)
    fmadds	f1, f31, f1, f30
    stfs	f2, 0x100(r29)
    fsubs	f0, f0, f3
    stfs	f1, 0x80(r29)
    fmadds	f0, f0, f31, f30
    stfs	f0, 0(r29)
    b       _80050af8
_800507f4:
    mr	r3, r17
    mr	r4, r22
    bl      fn_800501F4
    xoris	r3, r3, 0x8000
    lis	r0, 0x4330
    lis	r4, -0x7ff7
    stw	r3, 0x1c(r1)
    addi	r5, r4, 0x12f8
    mr	r3, r17
    stw	r0, 0x18(r1)
    mr	r4, r22
    lfd	f1, 0(r5)
    lfd	f0, 0x18(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0(r29)
    bl      fn_800501F4
    xoris	r3, r3, 0x8000
    lis	r0, 0x4330
    lis	r4, -0x7ff7
    stw	r3, 0x14(r1)
    addi	r5, r4, 0x12f8
    mr	r3, r17
    stw	r0, 0x10(r1)
    mr	r4, r22
    lfd	f1, 0(r5)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0x80(r29)
    bl      fn_800501F4
    xoris	r3, r3, 0x8000
    lis	r0, 0x4330
    stw	r3, 0xc(r1)
    lis	r4, -0x7ff7
    lfd	f1, 0x12f8(r4)
    stw	r0, 8(r1)
    lfd	f0, 8(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0x100(r29)
    b       _80050af8
_8005089c:
    lwz	r22, 0(r5)
    mr	r3, r17
    lwz	r4, 4(r5)
    bl      fn_800501F4
    cmpwi	r22, 3
    bne     _8005093c
    lis	r4, -0x7fed
    lis	r0, 0x4330
    addi	r5, r4, 0xc00
    stw	r0, 0x18(r1)
    add	r5, r5, r3
    lis	r4, -0x7ff7
    lbz	r6, 0(r5)
    lfd	f1, 0x12f8(r4)
    extsb	r6, r6
    stw	r0, 0x10(r1)
    xoris	r3, r6, 0x8000
    stw	r3, 0x1c(r1)
    lfd	f0, 0x18(r1)
    stw	r0, 8(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0(r29)
    lbz	r0, 0x20(r5)
    extsb	r0, r0
    xoris	r0, r0, 0x8000
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0x80(r29)
    lbz	r0, 0x40(r5)
    extsb	r0, r0
    xoris	r0, r0, 0x8000
    stw	r0, 0xc(r1)
    lfd	f0, 8(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0x100(r29)
    b       _80050af8
_8005093c:
    cmpwi	r22, 5
    bne     _800509cc
    lis	r4, -0x7fed
    lis	r0, 0x4330
    addi	r5, r4, 0xc60
    stw	r0, 0x18(r1)
    add	r5, r5, r3
    lis	r4, -0x7ff7
    lbz	r6, 0(r5)
    lfd	f1, 0x12f8(r4)
    extsb	r6, r6
    stw	r0, 0x10(r1)
    xoris	r3, r6, 0x8000
    stw	r3, 0x1c(r1)
    lfd	f0, 0x18(r1)
    stw	r0, 8(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0(r29)
    lbz	r0, 0x80(r5)
    extsb	r0, r0
    xoris	r0, r0, 0x8000
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0x80(r29)
    lbz	r0, 0x100(r5)
    extsb	r0, r0
    xoris	r0, r0, 0x8000
    stw	r0, 0xc(r1)
    lfd	f0, 8(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0x100(r29)
    b       _80050af8
_800509cc:
    cmpwi	r22, 9
    bne     _80050a5c
    lis	r4, -0x7fed
    lis	r0, 0x4330
    addi	r5, r4, 0xde0
    stw	r0, 0x18(r1)
    add	r5, r5, r3
    lis	r4, -0x7ff7
    lbz	r6, 0(r5)
    lfd	f1, 0x12f8(r4)
    extsb	r6, r6
    stw	r0, 0x10(r1)
    xoris	r3, r6, 0x8000
    stw	r3, 0x1c(r1)
    lfd	f0, 0x18(r1)
    stw	r0, 8(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0(r29)
    lbz	r0, 0x400(r5)
    extsb	r0, r0
    xoris	r0, r0, 0x8000
    stw	r0, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0x80(r29)
    lbz	r0, 0x800(r5)
    extsb	r0, r0
    xoris	r0, r0, 0x8000
    stw	r0, 0xc(r1)
    lfd	f0, 8(r1)
    fsubs	f0, f0, f1
    fmadds	f0, f0, f31, f30
    stfs	f0, 0x100(r29)
    b       _80050af8
_80050a5c:
    divw	r7, r3, r22
    lis	r0, 0x4330
    lis	r4, -0x7ff7
    stw	r0, 0x18(r1)
    lfd	f3, 0x12f8(r4)
    stw	r0, 0x10(r1)
    divw	r5, r7, r22
    stw	r0, 8(r1)
    divw	r0, r5, r22
    mullw	r6, r7, r22
    subf	r3, r6, r3
    mullw	r0, r0, r22
    xoris	r3, r3, 0x8000
    stw	r3, 0x1c(r1)
    lfd	f0, 0x18(r1)
    mullw	r4, r5, r22
    subf	r0, r0, r5
    fsubs	f1, f0, f3
    xoris	r0, r0, 0x8000
    fmadds	f2, f1, f31, f30
    stw	r0, 0xc(r1)
    subf	r3, r4, r7
    xoris	r3, r3, 0x8000
    stfs	f2, 0(r29)
    stw	r3, 0x14(r1)
    lfd	f0, 0x10(r1)
    fsubs	f1, f0, f3
    lfd	f0, 8(r1)
    fsubs	f0, f0, f3
    fmadds	f1, f1, f31, f30
    fmadds	f0, f0, f31, f30
    stfs	f1, 0x80(r29)
    stfs	f0, 0x100(r29)
    b       _80050af8
_80050ae4:
    lis	r3, -0x7ff7
    lfs	f0, 0x12f0(r3)
    stfs	f0, 0(r29)
    stfs	f0, 0x80(r29)
    stfs	f0, 0x100(r29)
_80050af8:
    cmpwi	r21, 2
    bne     _80050b20
    cmpw	r24, r19
    blt     _80050b20
    lfs	f0, 0(r26)
    stfs	f0, 0x180(r26)
    lfs	f0, 0x80(r26)
    stfs	f0, 0x200(r26)
    lfs	f0, 0x100(r26)
    stfs	f0, 0x280(r26)
_80050b20:
    addi	r31, r31, 0x80
    addi	r30, r30, 0x180
    addi	r29, r29, 0x180
    addi	r23, r23, 1
_80050b30:
    cmpw	r24, r19
    li	r0, 1
    bge     _80050b40
    mr	r0, r21
_80050b40:
    cmpw	r23, r0
    blt     _80050710
    addi	r28, r28, 4
    addi	r27, r27, 4
    addi	r26, r26, 4
    addi	r25, r25, 0x180
    addi	r24, r24, 1
_80050b5c:
    cmpw	r24, r20
    blt     _800506fc
    lis	r3, -0x7ff7
    slwi	r0, r20, 2
    lfs	f0, 0x12f0(r3)
    mr	r5, r20
    add	r4, r18, r0
    b       _80050ba8
_80050b7c:
    mr	r3, r4
    mtctr	r21
    cmpwi	r21, 0
    ble     _80050ba0
_80050b8c:
    stfs	f0, 0(r3)
    stfs	f0, 0x80(r3)
    stfs	f0, 0x100(r3)
    addi	r3, r3, 0x180
    bdnz    _80050b8c
_80050ba0:
    addi	r4, r4, 4
    addi	r5, r5, 1
_80050ba8:
    cmpwi	r5, 0x20
    blt     _80050b7c
    psq_l	f31, 0x78(r1), 0, 0
    lfd	f31, 0x70(r1)
    psq_l	f30, 0x68(r1), 0, 0
    lfd	f30, 0x60(r1)
    lmw	r17, 0x24(r1)
    lwz	r0, 0x84(r1)
    mtlr	r0
    addi	r1, r1, 0x80
    blr	
}

#pragma pop
