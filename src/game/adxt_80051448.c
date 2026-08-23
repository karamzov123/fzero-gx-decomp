#pragma push
#pragma force_active on

extern void fn_80047464(void);
extern void ADXT_Stop(void);
extern void fn_8004EBB4(void);
extern void fn_8004EBD4(void);
extern void fn_800501F4(void);
extern void fn_800519B0(void);
extern void fn_80053A38(void);
extern void fn_80053A84(void);
extern void fn_80053BB4(void);
extern void fn_80053BFC(void);
extern void fn_80053EA0(void);
extern void fn_80053EA8(void);
extern void fn_80053EB0(void);
extern void fn_800541EC(void);
extern void fn_80054224(void);
extern void fn_800542BC(void);
extern void fn_800542C8(void);
extern void fn_80054354(void);
extern void fn_800545B0(void);
extern void fn_80054608(void);
extern void memset(void);
extern unsigned char E1052501_ADXT_AttachAHX_str[24];
extern unsigned char can_not_attach_AHX_str[20];
extern unsigned char lbl_80187110[4];
extern unsigned char lbl_80187130[512];
extern unsigned char lbl_80187330[64];

asm void fn_80051448(void)
{
    nofralloc
    stwu	r1, -0x60(r1)
    mflr	r0
    stw	r0, 0x64(r1)
    stw	r31, 0x5c(r1)
    mr	r31, r3
    stw	r30, 0x58(r1)
    stw	r29, 0x54(r1)
    stw	r28, 0x50(r1)
    lwz	r0, 0x34c(r3)
    cmplwi	r0, 0
    mr	r28, r0
    beq     _80051574
    addi	r3, r1, 0xc
    li	r4, 0
    li	r5, 0x40
    bl      memset
    li	r0, 0
    lis     r3, lbl_80187130@ha
    addi	r3, r3, lbl_80187130@l
    stw	r0, 8(r1)
    mr	r30, r3
    addi	r29, r3, 4
    b       _800514b8
_800514a4:
    mr	r3, r28
    li	r4, 8
    bl      fn_800501F4
    stb	r3, 0(r30)
    addi	r30, r30, 1
_800514b8:
    cmplw	r30, r29
    bne     _800514a4
    lis     r3, lbl_80187130@ha
    addi	r5, r1, 8
    addi	r3, r3, lbl_80187130@l
    li	r4, 4
    li	r6, 0
    bl      fn_800519B0
    lwz	r0, 8(r1)
    add	r29, r29, r0
    b       _800514f8
_800514e4:
    mr	r3, r28
    li	r4, 8
    bl      fn_800501F4
    stb	r3, 0(r30)
    addi	r30, r30, 1
_800514f8:
    cmplw	r30, r29
    bne     _800514e4
    lis     r3, lbl_80187130@ha
    addi	r5, r1, 8
    addi	r3, r3, lbl_80187130@l
    addi	r6, r1, 0xc
    li	r4, 0x200
    bl      fn_800519B0
    cmpwi	r3, 0
    blt     _80051574
    lbz	r3, 0xf(r1)
    li	r0, 1
    extsb	r3, r3
    stw	r3, 0x388(r31)
    lwz	r3, 0x10(r1)
    stw	r3, 0x38c(r31)
    lwz	r3, 0x14(r1)
    stw	r3, 0x390(r31)
    lwz	r4, 0x30(r1)
    lwz	r3, 0x34(r1)
    stw	r4, 0x3a0(r31)
    stw	r3, 0x3a4(r31)
    lwz	r3, 0x38(r1)
    stw	r3, 0x3a8(r31)
    lwz	r4, 0x3c(r1)
    lwz	r3, 0x40(r1)
    stw	r4, 0x3ac(r31)
    stw	r3, 0x3b0(r31)
    lwz	r3, 0x44(r1)
    stw	r3, 0x3b4(r31)
    stw	r0, 0x384(r31)
_80051574:
    lwz	r0, 0x64(r1)
    lwz	r31, 0x5c(r1)
    lwz	r30, 0x58(r1)
    lwz	r29, 0x54(r1)
    lwz	r28, 0x50(r1)
    mtlr	r0
    addi	r1, r1, 0x60
    blr	
}

asm void fn_80051594(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    li	r5, 0x30
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r4
    li	r4, 0
    stw	r29, 0x14(r1)
    mr	r29, r3
    lwz	r31, 0x350(r3)
    addi	r3, r29, 0x354
    bl      memset
    addi	r3, r29, 0x384
    li	r4, 0
    li	r5, 0x34
    bl      memset
    addi	r3, r29, 0x3b8
    li	r4, 0
    li	r5, 0x100
    bl      memset
    addi	r3, r29, 0x4b8
    li	r4, 0
    li	r5, 0x100
    bl      memset
    addi	r3, r29, 0x5b8
    li	r4, 0
    li	r5, 0x300
    bl      memset
    lwz	r3, 0(r29)
    li	r4, 0
    li	r5, 0x300
    bl      memset
    addi	r3, r29, 0x8b8
    li	r4, 0
    li	r5, 0x300
    bl      memset
    li	r0, 0
    stb	r0, 0x345(r29)
    stw	r0, 0x348(r29)
    lwz	r3, 0x350(r29)
    cmplwi	r3, 0
    beq     _80051658
    stw	r0, 0x350(r29)
    bl      fn_80053A38
    mr	r3, r31
    li	r4, 0x2014
    bl      fn_80053A84
    stw	r3, 0x350(r29)
_80051658:
    stw	r30, 0x34c(r29)
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80051678(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    li	r4, 0
    li	r5, 0x30
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r30, r3
    lwz	r31, 0x350(r3)
    addi	r3, r30, 0x354
    bl      memset
    addi	r3, r30, 0x384
    li	r4, 0
    li	r5, 0x34
    bl      memset
    addi	r3, r30, 0x3b8
    li	r4, 0
    li	r5, 0x100
    bl      memset
    addi	r3, r30, 0x4b8
    li	r4, 0
    li	r5, 0x100
    bl      memset
    addi	r3, r30, 0x5b8
    li	r4, 0
    li	r5, 0x300
    bl      memset
    lwz	r3, 0(r30)
    li	r4, 0
    li	r5, 0x300
    bl      memset
    addi	r3, r30, 0x8b8
    li	r4, 0
    li	r5, 0x300
    bl      memset
    li	r0, 0
    stb	r0, 0x345(r30)
    stw	r0, 0x348(r30)
    lwz	r3, 0x350(r30)
    cmplwi	r3, 0
    beq     _80051734
    stw	r0, 0x350(r30)
    bl      fn_80053A38
    mr	r3, r31
    li	r4, 0x2014
    bl      fn_80053A84
    stw	r3, 0x350(r30)
_80051734:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005174C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r30, r3
    lwz	r3, 0x350(r3)
    lbz	r31, 0x346(r30)
    cmplwi	r3, 0
    extsb	r31, r31
    beq     _80051784
    li	r0, 0
    stw	r0, 0x350(r30)
    bl      fn_80053A38
_80051784:
    mr	r3, r30
    li	r4, 0
    li	r5, 0xbb8
    bl      memset
    lis     r3, lbl_80187330@ha
    slwi	r0, r31, 2
    addi	r3, r3, lbl_80187330@l
    li	r4, 0
    stwx	r4, r3, r0
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800517C0(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r5, lbl_80187330@ha
    stw	r0, 0x14(r1)
    li	r0, 2
    addi	r5, r5, lbl_80187330@l
    stw	r31, 0xc(r1)
    mr	r31, r3
    stw	r30, 8(r1)
    li	r30, 0
    mtctr	r0
_800517ec:
    lwz	r0, 0(r5)
    cmplwi	r0, 0
    beq     _80051874
    lwzu	r0, 4(r5)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80051874
    lwzu	r0, 4(r5)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80051874
    lwzu	r0, 4(r5)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80051874
    lwzu	r0, 4(r5)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80051874
    lwzu	r0, 4(r5)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80051874
    lwzu	r0, 4(r5)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80051874
    lwzu	r0, 4(r5)
    addi	r30, r30, 1
    cmplwi	r0, 0
    beq     _80051874
    addi	r5, r5, 4
    addi	r30, r30, 1
    bdnz    _800517ec
_80051874:
    cmpwi	r30, 0x10
    bne     _80051884
    li	r3, 0
    b       _800518f4
_80051884:
    mr	r3, r31
    mr	r5, r4
    li	r4, 0
    bl      memset
    lis     r3, lbl_80187330@ha
    slwi	r0, r30, 2
    addi	r3, r3, lbl_80187330@l
    li	r4, 0x2014
    stwx	r31, r3, r0
    lwzx	r31, r3, r0
    stb	r30, 0x346(r31)
    addi	r3, r31, 0xbb8
    bl      fn_80053A84
    cmplwi	r3, 0
    stw	r3, 0x350(r31)
    bne     _800518cc
    li	r3, 0
    b       _800518f4
_800518cc:
    addi	r0, r31, 0x23
    rlwinm	r0, r0, 0, 0, 0x1a
    stw	r0, 0(r31)
    lwz	r0, 0(r31)
    clrlwi.	r0, r0, 0x1b
    beq     _800518e8
_800518e4:
    b       _800518e4
_800518e8:
    li	r0, 1
    mr	r3, r31
    stb	r0, 0x344(r31)
_800518f4:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8005190C(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis     r3, lbl_80187110@ha
    stw	r0, 0x14(r1)
    addi	r4, r3, lbl_80187110@l
    lwz	r3, 0(r4)
    addic.	r0, r3, -1
    stw	r0, 0(r4)
    bne     _80051948
    lis     r3, lbl_80187330@ha
    li	r4, 0
    addi	r3, r3, lbl_80187330@l
    li	r5, 0x40
    bl      memset
    bl      fn_80053BB4
_80051948:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80051958(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r3, -0x7fe8
    stw	r0, 0x14(r1)
    lwz	r0, 0x7110(r3)
    cmpwi	r0, 0
    bne     _8005198c
    bl      fn_80053BFC
    lis     r3, lbl_80187330@ha
    li	r4, 0
    addi	r3, r3, lbl_80187330@l
    li	r5, 0x40
    bl      memset
_8005198c:
    lis     r3, lbl_80187110@ha
    addi	r4, r3, lbl_80187110@l
    lwz	r3, 0(r4)
    addi	r0, r3, 1
    stw	r0, 0(r4)
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800519B0(void)
{
    nofralloc
    cmplwi	r5, 0
    beq     _800519c0
    li	r0, 0
    stw	r0, 0(r5)
_800519c0:
    cmpwi	r4, 4
    bge     _800519d0
    li	r3, -1
    blr	
_800519d0:
    lbz	r7, 0(r3)
    lbz	r0, 1(r3)
    rlwimi	r0, r7, 8, 0x10, 0x17
    clrlwi	r0, r0, 0x10
    cmplwi	r0, 0x8000
    beq     _800519f0
    li	r3, -4
    blr	
_800519f0:
    lbz	r8, 2(r3)
    cmplwi	r5, 0
    lbz	r7, 3(r3)
    rlwimi	r7, r8, 8, 0x10, 0x17
    beq     _80051a08
    stw	r7, 0(r5)
_80051a08:
    cmplwi	r6, 0
    bne     _80051a18
    li	r3, 0
    blr	
_80051a18:
    addi	r0, r7, 4
    cmpw	r4, r0
    bge     _80051a2c
    li	r3, -2
    blr	
_80051a2c:
    addi	r7, r7, -6
    cmpwi	r7, 0x10
    bge     _80051a40
    li	r3, -2
    blr	
_80051a40:
    lbz	r0, 4(r3)
    addi	r7, r7, -0x10
    cmpwi	r7, 4
    stb	r0, 0(r6)
    lbz	r0, 5(r3)
    stb	r0, 1(r6)
    lbz	r0, 6(r3)
    stb	r0, 2(r6)
    lbz	r0, 7(r3)
    stb	r0, 3(r6)
    lbz	r0, 9(r3)
    lbz	r4, 8(r3)
    slwi	r0, r0, 0x10
    lbz	r5, 0xa(r3)
    rlwimi	r0, r4, 0x18, 0, 7
    lbz	r8, 0xb(r3)
    rlwimi	r0, r5, 8, 0x10, 0x17
    or	r0, r8, r0
    stw	r0, 4(r6)
    lbz	r0, 0xd(r3)
    lbz	r4, 0xc(r3)
    slwi	r0, r0, 0x10
    lbz	r5, 0xe(r3)
    rlwimi	r0, r4, 0x18, 0, 7
    lbz	r8, 0xf(r3)
    rlwimi	r0, r5, 8, 0x10, 0x17
    or	r0, r8, r0
    stw	r0, 8(r6)
    lbz	r4, 0x10(r3)
    lbz	r0, 0x11(r3)
    rlwimi	r0, r4, 8, 0x10, 0x17
    sth	r0, 0xc(r6)
    lbz	r0, 0x12(r3)
    stb	r0, 0x3c(r6)
    lbz	r0, 0x13(r3)
    stb	r0, 0x3d(r6)
    bge     _80051adc
    li	r3, -2
    blr	
_80051adc:
    lbz	r4, 0x16(r3)
    addi	r5, r3, 0x18
    lbz	r0, 0x17(r3)
    rlwimi	r0, r4, 8, 0x10, 0x17
    sth	r0, 0xe(r6)
    lha	r0, 0xe(r6)
    mulli	r0, r0, 0x14
    cmpw	r7, r0
    bge     _80051b08
    li	r3, -3
    blr	
_80051b08:
    mr	r3, r6
    li	r4, 0
    b       _80051bcc
_80051b14:
    lbz	r8, 0(r5)
    addi	r4, r4, 1
    lbz	r0, 1(r5)
    rlwimi	r0, r8, 8, 0x10, 0x17
    sth	r0, 0x10(r3)
    lbz	r8, 2(r5)
    lbz	r0, 3(r5)
    rlwimi	r0, r8, 8, 0x10, 0x17
    sth	r0, 0x12(r3)
    lbz	r0, 5(r5)
    lbz	r8, 4(r5)
    slwi	r0, r0, 0x10
    lbz	r9, 6(r5)
    rlwimi	r0, r8, 0x18, 0, 7
    lbz	r10, 7(r5)
    rlwimi	r0, r9, 8, 0x10, 0x17
    or	r0, r10, r0
    stw	r0, 0x14(r3)
    lbz	r0, 9(r5)
    lbz	r8, 8(r5)
    slwi	r0, r0, 0x10
    lbz	r9, 0xa(r5)
    rlwimi	r0, r8, 0x18, 0, 7
    lbz	r10, 0xb(r5)
    rlwimi	r0, r9, 8, 0x10, 0x17
    or	r0, r10, r0
    stw	r0, 0x18(r3)
    lbz	r0, 0xd(r5)
    lbz	r8, 0xc(r5)
    slwi	r0, r0, 0x10
    lbz	r9, 0xe(r5)
    rlwimi	r0, r8, 0x18, 0, 7
    lbz	r10, 0xf(r5)
    rlwimi	r0, r9, 8, 0x10, 0x17
    or	r0, r10, r0
    stw	r0, 0x1c(r3)
    lbz	r0, 0x11(r5)
    lbz	r8, 0x10(r5)
    slwi	r0, r0, 0x10
    lbz	r9, 0x12(r5)
    rlwimi	r0, r8, 0x18, 0, 7
    lbz	r10, 0x13(r5)
    rlwimi	r0, r9, 8, 0x10, 0x17
    or	r0, r10, r0
    stw	r0, 0x20(r3)
    addi	r3, r3, 0x14
_80051bcc:
    lha	r0, 0xe(r6)
    cmpw	r4, r0
    blt     _80051b14
    mulli	r0, r0, 0x14
    mr	r3, r6
    li	r4, 0
    subf	r7, r0, r7
    b       _80051ca8
_80051bec:
    cmpwi	r7, 0xc
    bge     _80051bfc
    li	r3, 0
    blr	
_80051bfc:
    lbz	r8, 0(r5)
    lbz	r0, 1(r5)
    rlwimi	r0, r8, 8, 0x10, 0x17
    sth	r0, 0x24(r3)
    lha	r0, 0x24(r3)
    cmpwi	r0, 0
    ble     _80051c28
    lbz	r8, 2(r5)
    lbz	r0, 3(r5)
    rlwimi	r0, r8, 8, 0x10, 0x17
    sth	r0, 0x26(r3)
_80051c28:
    lbz	r0, 4(r5)
    stb	r0, 0x28(r3)
    lbz	r0, 0x28(r3)
    extsb.	r0, r0
    ble     _80051c44
    lbz	r0, 5(r5)
    stb	r0, 0x29(r3)
_80051c44:
    lbz	r0, 6(r5)
    stb	r0, 0x2a(r3)
    lbz	r0, 0x2a(r3)
    extsb.	r0, r0
    ble     _80051c60
    lbz	r0, 7(r5)
    stb	r0, 0x2b(r3)
_80051c60:
    lbz	r0, 8(r5)
    stb	r0, 0x2c(r3)
    lbz	r0, 0x2c(r3)
    extsb.	r0, r0
    ble     _80051c7c
    lbz	r0, 9(r5)
    stb	r0, 0x2d(r3)
_80051c7c:
    lbz	r0, 0xa(r5)
    stb	r0, 0x2e(r3)
    lbz	r0, 0x2e(r3)
    extsb.	r0, r0
    ble     _80051c98
    lbz	r0, 0xb(r5)
    stb	r0, 0x2f(r3)
_80051c98:
    addi	r5, r5, 0xc
    addi	r7, r7, -0xc
    addi	r3, r3, 0xc
    addi	r4, r4, 1
_80051ca8:
    lbz	r0, 3(r6)
    extsb	r0, r0
    cmpw	r4, r0
    blt     _80051bec
    li	r3, 0
    blr	
}

asm void fn_80051CC0(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    bl      fn_8004EBD4
    lwz	r30, 0xb0(r29)
    mr	r3, r30
    bl      fn_800542BC
    cmpwi	r3, 0
    bne     _80051d04
    li	r0, 0
    mr	r3, r30
    stw	r0, 0x88(r29)
    bl      fn_800541EC
_80051d04:
    lwz	r0, 4(r29)
    cmpwi	r0, 1
    bne     _80051d2c
    li	r0, 0
    mr	r3, r30
    stw	r0, 0x88(r29)
    bl      fn_80054224
    li	r0, 2
    stw	r0, 4(r29)
    b       _80051da4
_80051d2c:
    cmpwi	r0, 2
    bne     _80051da4
    li	r31, 0
    b       _80051d48
_80051d3c:
    mr	r3, r30
    bl      fn_80053EB0
    addi	r31, r31, 1
_80051d48:
    lwz	r0, 0xb8(r29)
    cmpw	r31, r0
    blt     _80051d3c
    mr	r3, r30
    bl      fn_80053EA0
    lwz	r0, 0x88(r29)
    subf	r0, r0, r3
    mr	r3, r30
    stw	r0, 0x90(r29)
    lwz	r4, 0x88(r29)
    lwz	r0, 0x90(r29)
    add	r0, r4, r0
    stw	r0, 0x88(r29)
    bl      fn_80053EA8
    stw	r3, 0x94(r29)
    mr	r3, r30
    bl      fn_800542BC
    cmpwi	r3, 3
    bne     _80051da4
    mr	r3, r30
    bl      fn_800541EC
    li	r0, 0
    stw	r0, 4(r29)
_80051da4:
    bl      fn_8004EBB4
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80051DC4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    stw	r30, 8(r1)
    mr	r30, r3
    bl      ADXT_Stop
    lwz	r3, 4(r30)
    lwz	r31, 4(r3)
    lwz	r30, 0xb0(r31)
    cmplwi	r30, 0
    beq     _80051e18
    bl      fn_8004EBD4
    mr	r3, r30
    bl      fn_800541EC
    mr	r3, r30
    bl      fn_800542C8
    li	r0, 0
    stw	r0, 0xb0(r31)
    bl      fn_8004EBB4
    bl      fn_800545B0
_80051e18:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80051E30(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r4, -0x7fe8
    stw	r0, 0x14(r1)
    lwz	r12, -0x1a74(r4)
    cmplwi	r12, 0
    beq     _80051e54
    mtctr	r12
    bctrl	
_80051e54:
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void ADXT_AttachAHX(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stmw	r27, 0xc(r1)
    mr	r27, r3
    mr	r28, r4
    mr	r29, r5
    bl      ADXT_Stop
    lis	r3, -0x7fe8
    lwz	r12, -0x1a74(r3)
    cmplwi	r12, 0
    beq     _80051ea0
    mr	r3, r27
    mtctr	r12
    bctrl	
_80051ea0:
    bl      fn_80054608
    lwz	r3, 4(r27)
    lwz	r30, 0x10(r27)
    lwz	r31, 4(r3)
    bl      fn_8004EBD4
    mr	r3, r30
    mr	r6, r28
    mr	r7, r29
    addi	r5, r27, 0x18
    li	r4, 1
    bl      fn_80054354
    cmplwi	r3, 0
    bne     _80051eec
    lis     r3, E1052501_ADXT_AttachAHX_str@ha
    lis     r4, can_not_attach_AHX_str@ha
    addi	r3, r3, E1052501_ADXT_AttachAHX_str@l
    addi	r4, r4, can_not_attach_AHX_str@l
    bl      fn_80047464
    b       _80051f24
_80051eec:
    lis     r9, fn_80051DC4@ha
    lis     r7, fn_80051CC0@ha
    lis	r5, -0x7ffb
    stw	r3, 0xb0(r31)
    lis	r8, -0x7fe8
    addi	r9, r9, fn_80051DC4@l
    lis	r6, -0x7fe8
    addi	r7, r7, fn_80051CC0@l
    lis	r4, -0x7fe8
    addi	r0, r5, 0x42b4
    stw	r9, -0x1a74(r8)
    stw	r7, -0x5d80(r6)
    stw	r0, -0x5d7c(r4)
    bl      fn_8004EBB4
_80051f24:
    lmw	r27, 0xc(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
