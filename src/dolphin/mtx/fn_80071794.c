#pragma push
#pragma force_active on

extern asm void OSReport(void);
extern asm void GXInitTexObj(void);
extern asm void fn_80035EC4(void);
extern unsigned char lbl_8015AC08[18];
extern unsigned char lbl_8015AC1C[69];

asm void fn_80071794(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r12, -0x76b4(r13)
    mtctr	r12
    bctrl	
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800717BC(void)
{
    nofralloc
    li	r0, 2
    li	r9, 0
    li	r8, 0
    li	r7, 0
    li	r5, 1
    mtctr	r0
_800717d4:
    slw	r6, r5, r7
    and.	r0, r3, r6
    beq	_800717e4
    addi	r8, r8, 1
_800717e4:
    and.	r0, r4, r6
    beq	_800717f0
    addi	r9, r9, 1
_800717f0:
    addi	r7, r7, 1
    slw	r6, r5, r7
    and.	r0, r3, r6
    beq	_80071804
    addi	r8, r8, 1
_80071804:
    and.	r0, r4, r6
    beq	_80071810
    addi	r9, r9, 1
_80071810:
    addi	r7, r7, 1
    slw	r6, r5, r7
    and.	r0, r3, r6
    beq	_80071824
    addi	r8, r8, 1
_80071824:
    and.	r0, r4, r6
    beq	_80071830
    addi	r9, r9, 1
_80071830:
    addi	r7, r7, 1
    slw	r6, r5, r7
    and.	r0, r3, r6
    beq	_80071844
    addi	r8, r8, 1
_80071844:
    and.	r0, r4, r6
    beq	_80071850
    addi	r9, r9, 1
_80071850:
    addi	r7, r7, 1
    slw	r6, r5, r7
    and.	r0, r3, r6
    beq	_80071864
    addi	r8, r8, 1
_80071864:
    and.	r0, r4, r6
    beq	_80071870
    addi	r9, r9, 1
_80071870:
    addi	r7, r7, 1
    bdnz	_800717d4
    cmpwi	r8, 1
    bgt	_80071888
    cmpwi	r9, 1
    ble	_80071890
_80071888:
    li	r3, -1
    blr	
_80071890:
    cmpw	r3, r4
    ble	_8007189c
    mr	r3, r4
_8007189c:
    li	r4, 0
    b	_800718ac
_800718a4:
    srawi	r3, r3, 1
    addi	r4, r4, 1
_800718ac:
    cmpwi	r3, 4
    bgt	_800718a4
    mr	r3, r4
    blr	
}

asm void fn_800718BC(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stw	r31, 0x2c(r1)
    stw	r30, 0x28(r1)
    stw	r29, 0x24(r1)
    mr	r29, r4
    stw	r28, 0x20(r1)
    mr	r28, r3
    lwz	r0, 0(r29)
    lwz	r4, 8(r5)
    lwz	r3, 4(r29)
    rlwinm.	r0, r0, 0, 0x17, 0x17
    add	r30, r4, r3
    beq	_80071914
    lis     r3, lbl_8015AC08@ha
    addi	r3, r3, lbl_8015AC08@l
    crxor	6, 6, 6
    bl      OSReport
    li	r0, 0
    stw	r0, 8(r28)
    b	_80071be4
_80071914:
    lwz	r3, 0(r28)
    rlwinm	r0, r3, 0x1e, 0x1e, 0x1f
    cmpwi	r0, 2
    beq	_80071934
    bge	_80071944
    cmpwi	r0, 1
    bge	_8007193c
    b	_80071944
_80071934:
    li	r8, 2
    b	_80071948
_8007193c:
    li	r8, 1
    b	_80071948
_80071944:
    li	r8, 0
_80071948:
    rlwinm	r0, r3, 0x1c, 0x1e, 0x1f
    cmpwi	r0, 2
    beq	_80071964
    bge	_80071974
    cmpwi	r0, 1
    bge	_8007196c
    b	_80071974
_80071964:
    li	r9, 2
    b	_80071978
_8007196c:
    li	r9, 1
    b	_80071978
_80071974:
    li	r9, 0
_80071978:
    lhz	r4, 8(r29)
    rlwinm	r3, r3, 0x19, 0x1c, 0x1f
    li	r6, 0
    li	r0, 2
    mr	r31, r3
    lhz	r5, 0xa(r29)
    mr	r11, r4
    mr	r10, r6
    li	r7, 0
    li	r3, 1
    mtctr	r0
_800719a4:
    slw	r12, r3, r10
    and.	r0, r11, r12
    beq	_800719b4
    addi	r7, r7, 1
_800719b4:
    and.	r0, r5, r12
    beq	_800719c0
    addi	r6, r6, 1
_800719c0:
    addi	r10, r10, 1
    slw	r12, r3, r10
    and.	r0, r11, r12
    beq	_800719d4
    addi	r7, r7, 1
_800719d4:
    and.	r0, r5, r12
    beq	_800719e0
    addi	r6, r6, 1
_800719e0:
    addi	r10, r10, 1
    slw	r12, r3, r10
    and.	r0, r11, r12
    beq	_800719f4
    addi	r7, r7, 1
_800719f4:
    and.	r0, r5, r12
    beq	_80071a00
    addi	r6, r6, 1
_80071a00:
    addi	r10, r10, 1
    slw	r12, r3, r10
    and.	r0, r11, r12
    beq	_80071a14
    addi	r7, r7, 1
_80071a14:
    and.	r0, r5, r12
    beq	_80071a20
    addi	r6, r6, 1
_80071a20:
    addi	r10, r10, 1
    slw	r12, r3, r10
    and.	r0, r11, r12
    beq	_80071a34
    addi	r7, r7, 1
_80071a34:
    and.	r0, r5, r12
    beq	_80071a40
    addi	r6, r6, 1
_80071a40:
    addi	r10, r10, 1
    bdnz	_800719a4
    cmpwi	r7, 1
    bgt	_80071a58
    cmpwi	r6, 1
    ble	_80071a60
_80071a58:
    li	r3, -1
    b	_80071a84
_80071a60:
    cmpw	r11, r5
    ble	_80071a6c
    mr	r11, r5
_80071a6c:
    li	r3, 0
    b	_80071a7c
_80071a74:
    srawi	r11, r11, 1
    addi	r3, r3, 1
_80071a7c:
    cmpwi	r11, 4
    bgt	_80071a74
_80071a84:
    clrlwi	r3, r3, 0x18
    cmplwi	r3, 0xff
    bne	_80071ac0
    cmpwi	r9, 0
    bne	_80071aa0
    cmpwi	r8, 0
    beq	_80071ab0
_80071aa0:
    lis     r3, lbl_8015AC1C@ha
    addi	r3, r3, lbl_8015AC1C@l
    crxor	6, 6, 6
    bl      OSReport
_80071ab0:
    li	r8, 0
    li	r9, 0
    li	r31, 0
    b	_80071ad8
_80071ac0:
    clrlwi	r0, r31, 0x18
    cmplwi	r0, 0xf
    beq	_80071ad4
    cmplw	r3, r0
    bge	_80071ad8
_80071ad4:
    mr	r31, r3
_80071ad8:
    lhz	r3, 0xc(r29)
    cmpwi	r3, -1
    beq	_80071af4
    clrlwi	r0, r31, 0x18
    cmpw	r3, r0
    bge	_80071af4
    clrlwi	r31, r3, 0x18
_80071af4:
    lwz	r0, 0(r29)
    clrlwi	r7, r0, 0x1b
    cmpwi	r7, 0xe
    beq	_80071b14
    bge	_80071b20
    cmpwi	r7, 0
    beq	_80071b14
    b	_80071b20
_80071b14:
    clrlwi.	r0, r31, 0x18
    beq	_80071b20
    addi	r31, r31, -1
_80071b20:
    clrlwi	r4, r31, 0x18
    lwz	r3, 8(r28)
    neg	r0, r4
    lhz	r5, 8(r29)
    or	r0, r0, r4
    lhz	r6, 0xa(r29)
    srwi	r10, r0, 0x1f
    mr	r4, r30
    bl      GXInitTexObj
    stw	r30, 0x14(r28)
    lwz	r7, 0(r28)
    rlwinm.	r0, r7, 0, 0x14, 0x14
    beq	_80071b70
    clrlwi.	r0, r31, 0x18
    li	r5, 0
    beq	_80071b68
    li	r4, 4
    b	_80071b88
_80071b68:
    li	r4, 2
    b	_80071b88
_80071b70:
    clrlwi.	r0, r31, 0x18
    li	r5, 1
    beq	_80071b84
    li	r4, 5
    b	_80071b88
_80071b84:
    li	r4, 3
_80071b88:
    lbz	r0, 6(r28)
    lis	r3, 0x4330
    clrlwi	r6, r31, 0x18
    stw	r3, 0x10(r1)
    extsb	r0, r0
    lfd	f2, -0x7a00(r2)
    xoris	r0, r0, 0x8000
    stw	r6, 0xc(r1)
    lfs	f0, -0x7a08(r2)
    rlwinm	r7, r7, 0x1a, 0x1f, 0x1f
    stw	r0, 0x14(r1)
    li	r6, 0
    lbz	r8, 7(r28)
    lfd	f1, 0x10(r1)
    stw	r3, 8(r1)
    fsubs	f1, f1, f2
    lfd	f2, -0x7a10(r2)
    lwz	r3, 8(r28)
    fdivs	f3, f1, f0
    lfd	f0, 8(r1)
    lfs	f1, -0x7a18(r2)
    fsubs	f2, f0, f2
    bl      fn_80035EC4
_80071be4:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    lwz	r28, 0x20(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

#pragma pop
