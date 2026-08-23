#pragma push
#pragma force_active on

extern void memcpy(void);
extern void memset(void);
extern void fn_8004A068(void);
extern void fn_80049E34(void);
extern void fn_80049BF4(void);

asm void fn_80049728(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    mflr	r0
    stw	r0, 0x44(r1)
    stw	r31, 0x3c(r1)
    stw	r30, 0x38(r1)
    stw	r29, 0x34(r1)
    stw	r28, 0x30(r1)
    lwz	r0, 0x6c(r3)
    lwz	r29, 0xc(r3)
    cmpwi	r0, 0
    lwz	r4, 0x2c(r3)
    bgt     _80049760
    lwz	r30, 0x50(r3)
    b       _8004977c
_80049760:
    lwz	r3, 0x50(r3)
    addi	r0, r3, 0x7ff
    add	r0, r4, r0
    srawi	r0, r0, 0xb
    addze	r0, r0
    slwi	r0, r0, 0xb
    subf	r30, r4, r0
_8004977c:
    lwz	r5, 0(r29)
    mr	r3, r29
    addi	r31, r30, -4
    li	r4, 0
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    cmpw	r3, r30
    bge     _800497a8
    li	r3, 0
    b       _80049938
_800497a8:
    lwz	r4, 0(r29)
    lis	r3, 1
    addi	r0, r3, -0x7fff
    mr	r3, r29
    lwz	r12, 0x18(r4)
    addi	r6, r1, 0x1c
    sth	r0, 0xa(r1)
    li	r4, 0
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x20(r1)
    cmpwi	r0, 2
    bge     _80049800
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0x1c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _80049828
_80049800:
    lwz	r6, 0x1c(r1)
    mr	r3, r29
    lha	r0, 0xa(r1)
    addi	r5, r1, 0x1c
    li	r4, 1
    sth	r0, 0(r6)
    lwz	r6, 0(r29)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
_80049828:
    lwz	r4, 0(r29)
    mr	r3, r29
    sth	r31, 0xa(r1)
    addi	r6, r1, 0x14
    lwz	r12, 0x18(r4)
    li	r4, 0
    li	r5, 2
    mtctr	r12
    bctrl	
    lwz	r0, 0x18(r1)
    cmpwi	r0, 2
    bge     _80049878
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0x14
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _800498a0
_80049878:
    lwz	r6, 0x14(r1)
    extsh	r0, r31
    mr	r3, r29
    addi	r5, r1, 0x14
    sth	r0, 0(r6)
    li	r4, 1
    lwz	r6, 0(r29)
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
_800498a0:
    li	r0, 0
    li	r28, 0
    stb	r0, 8(r1)
    b       _8004992c
_800498b0:
    lwz	r5, 0(r29)
    mr	r3, r29
    addi	r6, r1, 0xc
    li	r4, 0
    lwz	r12, 0x18(r5)
    li	r5, 1
    mtctr	r12
    bctrl	
    lwz	r0, 0x10(r1)
    cmpwi	r0, 1
    bge     _800498fc
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0xc
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _80049928
_800498fc:
    lwz	r3, 0xc(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0xc
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
_80049928:
    addi	r28, r28, 1
_8004992c:
    cmpw	r28, r31
    blt     _800498b0
    mr	r3, r30
_80049938:
    lwz	r0, 0x44(r1)
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    lwz	r29, 0x34(r1)
    lwz	r28, 0x30(r1)
    mtlr	r0
    addi	r1, r1, 0x40
    blr	
}

asm void fn_80049958(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stmw	r19, 0x1c(r1)
    mr	r29, r3
    lis	r3, 0x38e4
    li	r31, 0
    addi	r26, r3, -0x71c7
    addi	r27, r29, 0x90
    addi	r28, r29, 0xd0
    addi	r24, r29, 4
    lwz	r30, 0xc(r29)
_80049988:
    lwz	r5, 0(r30)
    mr	r3, r30
    li	r4, 0
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    mulhw	r3, r26, r3
    lwz	r0, 0x58(r29)
    srawi	r3, r3, 2
    srwi	r4, r3, 0x1f
    add	r3, r3, r4
    divw.	r0, r3, r0
    ble     _80049bdc
    lwz	r3, 0x30(r29)
    lwz	r0, 0x3c(r29)
    lwz	r4, 0x44(r29)
    subf	r20, r3, r0
    stw	r27, 0x10(r1)
    cmpw	r4, r20
    stw	r28, 0x14(r1)
    bge     _800499e0
    mr	r20, r4
_800499e0:
    li	r25, 0
    mr	r21, r24
    mr	r19, r25
    b       _80049a24
_800499f0:
    lwz	r3, 0(r21)
    li	r4, 1
    lwz	r5, 0(r3)
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    srwi	r25, r3, 1
    cmpw	r25, r20
    bge     _80049a1c
    li	r25, 0
    b       _80049ad0
_80049a1c:
    addi	r21, r21, 4
    addi	r19, r19, 1
_80049a24:
    lwz	r0, 0x58(r29)
    cmpw	r19, r0
    blt     _800499f0
    slwi	r21, r20, 1
    mr	r23, r24
    addi	r22, r1, 0x10
    li	r19, 0
    b       _80049ac4
_80049a44:
    li	r25, 0
    b       _80049ab0
_80049a4c:
    lwz	r3, 0(r23)
    mr	r5, r21
    addi	r6, r1, 8
    li	r4, 1
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r3, 0(r22)
    slwi	r0, r25, 1
    lwz	r4, 8(r1)
    lwz	r5, 0xc(r1)
    add	r3, r3, r0
    bl      memcpy
    lwz	r3, 0(r23)
    addi	r5, r1, 8
    lwz	r0, 0xc(r1)
    li	r4, 0
    lwz	r6, 0(r3)
    srwi	r0, r0, 1
    lwz	r12, 0x20(r6)
    extsh	r0, r0
    add	r25, r25, r0
    mtctr	r12
    bctrl	
_80049ab0:
    cmpw	r25, r20
    blt     _80049a4c
    addi	r23, r23, 4
    addi	r22, r22, 4
    addi	r19, r19, 1
_80049ac4:
    lwz	r0, 0x58(r29)
    cmpw	r19, r0
    blt     _80049a44
_80049ad0:
    cmpwi	r25, 0
    bne     _80049ae0
    li	r0, 0
    b       _80049bb8
_80049ae0:
    lwz	r0, 0x44(r29)
    cmpw	r20, r0
    bge     _80049b34
    addi	r21, r1, 0x10
    slwi	r22, r20, 1
    li	r19, 0
    b       _80049b28
_80049afc:
    lwz	r3, 0(r21)
    cmplwi	r3, 0
    beq     _80049b20
    lwz	r0, 0x44(r29)
    add	r3, r3, r22
    li	r4, 0
    subf	r0, r20, r0
    slwi	r5, r0, 1
    bl      memset
_80049b20:
    addi	r21, r21, 4
    addi	r19, r19, 1
_80049b28:
    lwz	r0, 0x58(r29)
    cmpw	r19, r0
    blt     _80049afc
_80049b34:
    lwz	r3, 0x30(r29)
    mr	r21, r29
    lwz	r0, 0x44(r29)
    mr	r22, r29
    mr	r23, r29
    li	r25, 0
    add	r0, r3, r0
    stw	r0, 0x30(r29)
    b       _80049ba8
_80049b58:
    mr	r3, r29
    mr	r4, r25
    bl      fn_8004A068
    lwz	r6, 0x80(r21)
    mr	r3, r29
    mr	r4, r25
    lwz	r5, 0x88(r6)
    lha	r0, 0x7c(r6)
    sth	r0, 0x290(r22)
    lfd	f0, 0x80(r6)
    stfd	f0, 0x298(r23)
    lha	r6, 0xa(r5)
    lha	r0, 8(r5)
    sth	r0, 0x88(r22)
    sth	r6, 0x8c(r22)
    bl      fn_80049E34
    addi	r21, r21, 4
    addi	r22, r22, 2
    addi	r23, r23, 8
    addi	r25, r25, 1
_80049ba8:
    lwz	r0, 0x58(r29)
    cmpw	r25, r0
    blt     _80049b58
    lwz	r0, 0x44(r29)
_80049bb8:
    cmpwi	r0, 0
    beq     _80049bdc
    mr	r3, r29
    bl      fn_80049BF4
    lwz	r4, 0x30(r29)
    add	r31, r31, r3
    lwz	r0, 0x3c(r29)
    cmpw	r4, r0
    blt     _80049988
_80049bdc:
    mr	r3, r31
    lmw	r19, 0x1c(r1)
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void fn_80049BF4(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    stmw	r25, 0x34(r1)
    mr	r26, r3
    li	r29, 0
    li	r28, 0
    mr	r31, r26
    mr	r30, r26
    lwz	r27, 0xc(r3)
    b       _80049e10
_80049c20:
    lha	r5, 0x2d0(r26)
    lha	r0, 0x2d2(r26)
    lha	r4, 0x290(r31)
    mullw	r0, r5, r0
    lha	r3, 0x2d4(r26)
    addi	r4, r4, -1
    extsh	r4, r4
    add	r0, r3, r0
    xor	r3, r4, r5
    sth	r0, 0x2d0(r26)
    lha	r0, 0x2d0(r26)
    clrlwi	r0, r0, 0x11
    sth	r0, 0x2d0(r26)
    lwz	r0, 0x2a8(r30)
    cmpwi	r0, 0
    bne     _80049c88
    lwz	r0, 0x2ac(r30)
    cmpwi	r0, 0
    bne     _80049c88
    lwz	r0, 0x2b0(r30)
    cmpwi	r0, 0
    bne     _80049c88
    lwz	r0, 0x2b4(r30)
    cmpwi	r0, 0
    bne     _80049c88
    li	r3, 0
_80049c88:
    extsh	r25, r3
    mr	r3, r27
    srawi	r0, r25, 8
    addi	r6, r1, 0x1c
    stb	r0, 8(r1)
    li	r4, 0
    li	r5, 1
    lwz	r7, 0(r27)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0x20(r1)
    cmpwi	r0, 1
    bge     _80049ce0
    lwz	r6, 0(r27)
    mr	r3, r27
    addi	r5, r1, 0x1c
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _80049d0c
_80049ce0:
    lwz	r3, 0x1c(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r27)
    mr	r3, r27
    addi	r5, r1, 0x1c
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
_80049d0c:
    stb	r25, 8(r1)
    mr	r3, r27
    addi	r6, r1, 0x14
    li	r4, 0
    lwz	r7, 0(r27)
    li	r5, 1
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r0, 0x18(r1)
    cmpwi	r0, 1
    bge     _80049d5c
    lwz	r6, 0(r27)
    mr	r3, r27
    addi	r5, r1, 0x14
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _80049d88
_80049d5c:
    lwz	r3, 0x14(r1)
    addi	r4, r1, 8
    li	r5, 1
    bl      memcpy
    lwz	r6, 0(r27)
    mr	r3, r27
    addi	r5, r1, 0x14
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
_80049d88:
    lwz	r5, 0(r27)
    mr	r3, r27
    addi	r6, r1, 0xc
    li	r4, 0
    lwz	r12, 0x18(r5)
    li	r5, 0x10
    mtctr	r12
    bctrl	
    lwz	r0, 0x10(r1)
    cmpwi	r0, 0x10
    bge     _80049dd4
    lwz	r6, 0(r27)
    mr	r3, r27
    addi	r5, r1, 0xc
    li	r4, 0
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _80049e00
_80049dd4:
    lwz	r3, 0xc(r1)
    addi	r4, r30, 0x2a8
    li	r5, 0x10
    bl      memcpy
    lwz	r6, 0(r27)
    mr	r3, r27
    addi	r5, r1, 0xc
    li	r4, 1
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
_80049e00:
    addi	r28, r28, 0x12
    addi	r31, r31, 2
    addi	r30, r30, 0x10
    addi	r29, r29, 1
_80049e10:
    lwz	r0, 0x58(r26)
    cmpw	r29, r0
    blt     _80049c20
    mr	r3, r28
    lmw	r25, 0x34(r1)
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

asm void fn_80049E34(void)
{
    nofralloc
    stwu	r1, -0x40(r1)
    slwi	r7, r4, 6
    li	r6, 8
    slwi	r0, r4, 2
    stmw	r27, 0x2c(r1)
    add	r7, r3, r7
    li	r9, 0
    lwz	r5, 0x54(r3)
    divw	r10, r6, r5
    slwi	r6, r4, 4
    add	r5, r3, r0
    addi	r8, r6, 0x2a8
    lwz	r11, 0x80(r5)
    lis	r4, -0x7ff7
    addi	r0, r7, 0x110
    lfd	f2, 0x980(r4)
    add	r8, r3, r8
    addi	r6, r7, 0x190
    mr	r5, r0
    mr	r4, r11
    addi	r12, r8, -1
    addi	r7, r7, 0x210
    li	r8, 0
    lis	r0, 0x4330
    b       _8004a050
_80049e98:
    cmplwi	r11, 0
    bne     _80049ea8
    li	r29, 0
    b       _80049eac
_80049ea8:
    lha	r29, 0x18(r4)
_80049eac:
    sth	r29, 0(r5)
    li	r29, -0x8000
    lha	r30, 0(r5)
    stw	r0, 8(r1)
    xoris	r30, r30, 0x8000
    lfd	f1, 0x80(r11)
    stw	r30, 0xc(r1)
    lfd	f0, 8(r1)
    fsub	f0, f0, f2
    fmul	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r27, 0x14(r1)
    cmpwi	r27, -0x8000
    blt     _80049eec
    mr	r29, r27
_80049eec:
    cmpwi	r29, 0x7fff
    ble     _80049efc
    li	r30, 0x7fff
    b       _80049f0c
_80049efc:
    cmpwi	r27, -0x8000
    li	r30, -0x8000
    blt     _80049f0c
    mr	r30, r27
_80049f0c:
    sth	r30, 0(r6)
    lha	r29, 0(r6)
    cmpwi	r29, 0
    bge     _80049f3c
    lis	r29, 0x3800
    addi	r30, r30, -0x924
    addi	r29, r29, 0x7001
    mulhw	r29, r29, r30
    srawi	r29, r29, 0xa
    srwi	r30, r29, 0x1f
    add	r27, r29, r30
    b       _80049f58
_80049f3c:
    lis	r29, 0x3800
    addi	r30, r30, 0x924
    addi	r29, r29, 0x7001
    mulhw	r29, r29, r30
    srawi	r29, r29, 0xa
    srwi	r30, r29, 0x1f
    add	r27, r29, r30
_80049f58:
    cmpwi	r27, -8
    li	r29, -8
    blt     _80049f68
    mr	r29, r27
_80049f68:
    cmpwi	r29, 7
    bge     _80049f84
    cmpwi	r27, -8
    li	r28, -8
    blt     _80049f88
    mr	r28, r27
    b       _80049f88
_80049f84:
    li	r28, 7
_80049f88:
    lha	r30, 0x7c(r11)
    li	r29, -0x8000
    stw	r0, 0x18(r1)
    mullw	r30, r28, r30
    lfd	f1, 0x80(r11)
    xoris	r30, r30, 0x8000
    stw	r30, 0x1c(r1)
    lfd	f0, 0x18(r1)
    fsub	f0, f0, f2
    fmul	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x20(r1)
    lwz	r27, 0x24(r1)
    cmpwi	r27, -0x8000
    blt     _80049fc8
    mr	r29, r27
_80049fc8:
    cmpwi	r29, 0x7fff
    ble     _80049fd8
    li	r30, 0x7fff
    b       _80049fe8
_80049fd8:
    cmpwi	r27, -0x8000
    li	r30, -0x8000
    blt     _80049fe8
    mr	r30, r27
_80049fe8:
    divw	r29, r8, r10
    sth	r30, 0(r7)
    mullw	r29, r29, r10
    subf.	r29, r29, r8
    bne     _8004a008
    li	r29, 0
    li	r9, 1
    stbu	r29, 1(r12)
_8004a008:
    lwz	r30, 0x54(r3)
    subf	r31, r9, r10
    lbz	r29, 0(r12)
    addi	r9, r9, 1
    mullw	r31, r30, r31
    subfic	r27, r30, 8
    addi	r4, r4, 2
    slw	r30, r28, r27
    addi	r5, r5, 2
    clrlwi	r30, r30, 0x18
    sraw	r30, r30, r27
    addi	r6, r6, 2
    slw	r31, r30, r31
    addi	r7, r7, 2
    extsb	r31, r31
    addi	r8, r8, 1
    or	r31, r29, r31
    stb	r31, 0(r12)
_8004a050:
    lwz	r31, 0x44(r3)
    cmpw	r8, r31
    blt     _80049e98
    lmw	r27, 0x2c(r1)
    addi	r1, r1, 0x40
    blr	
}

asm void fn_8004A068(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    slwi	r0, r4, 2
    slwi	r6, r4, 1
    slwi	r4, r4, 6
    stw	r31, 0x2c(r1)
    addi	r7, r4, 0x90
    add	r7, r3, r7
    add	r5, r3, r0
    stw	r30, 0x28(r1)
    add	r6, r3, r6
    mr	r4, r7
    li	r8, 0
    stw	r29, 0x24(r1)
    lwz	r9, 0x80(r5)
    lha	r11, 0x8c(r6)
    lwz	r10, 0x88(r9)
    mr	r5, r9
    lha	r0, 0x88(r6)
    sth	r0, 8(r9)
    sth	r11, 0xa(r9)
    b       _8004a1a0
_8004a0bc:
    cmpwi	r8, 0
    lha	r0, 0(r4)
    bne     _8004a0f8
    li	r29, 0
    mr	r30, r9
    mr	r12, r29
    b       _8004a0e4
_8004a0d8:
    sth	r12, 0x18(r30)
    addi	r30, r30, 2
    addi	r29, r29, 1
_8004a0e4:
    lwz	r11, 0x14(r9)
    cmpw	r29, r11
    blt     _8004a0d8
    li	r11, 0
    stw	r11, 0x78(r9)
_8004a0f8:
    cmplwi	r9, 0
    beq     _8004a194
    lha	r29, 6(r9)
    li	r11, -0x8000
    lha	r31, 0xa(r9)
    lha	r30, 4(r9)
    lha	r12, 8(r9)
    mullw	r31, r29, r31
    mullw	r12, r30, r12
    srawi	r30, r31, 0xc
    srawi	r12, r12, 0xc
    subf	r12, r12, r0
    subf	r12, r30, r12
    cmpwi	r12, -0x8000
    blt     _8004a138
    mr	r11, r12
_8004a138:
    cmpwi	r11, 0x7fff
    ble     _8004a148
    li	r11, 0x7fff
    b       _8004a158
_8004a148:
    cmpwi	r12, -0x8000
    li	r11, -0x8000
    blt     _8004a158
    mr	r11, r12
_8004a158:
    sth	r11, 0x18(r5)
    extsh	r29, r11
    srawi	r30, r29, 0x1f
    xor	r12, r30, r29
    lwz	r11, 0x78(r9)
    subf	r12, r30, r12
    cmpw	r12, r11
    ble     _8004a188
    srawi	r12, r29, 0x1f
    xor	r11, r12, r29
    subf	r11, r12, r11
    stw	r11, 0x78(r9)
_8004a188:
    lha	r11, 8(r9)
    sth	r11, 0xa(r9)
    sth	r0, 8(r9)
_8004a194:
    addi	r4, r4, 2
    addi	r5, r5, 2
    addi	r8, r8, 1
_8004a1a0:
    lwz	r0, 0x44(r3)
    cmpw	r8, r0
    blt     _8004a0bc
    lwz	r8, 0x78(r9)
    lis	r5, -0x6db7
    lis	r4, -0x7fed
    addi	r8, r8, -1
    addi	r0, r5, 0x2493
    mulhw	r5, r0, r8
    lwz	r11, -0x4708(r4)
    mr	r0, r11
    add	r4, r5, r8
    srawi	r4, r4, 2
    srwi	r5, r4, 0x1f
    add	r4, r4, r5
    addi	r4, r4, 1
    cmpw	r4, r11
    bge     _8004a1ec
    mr	r0, r4
_8004a1ec:
    cmpwi	r0, 1
    ble     _8004a204
    cmpw	r4, r11
    bge     _8004a208
    mr	r11, r4
    b       _8004a208
_8004a204:
    li	r11, 1
_8004a208:
    sth	r11, 0x7c(r9)
    lwz	r0, 0x78(r9)
    cmpwi	r0, 0
    bne     _8004a228
    lis	r4, -0x7ff7
    lfd	f0, 0x988(r4)
    stfd	f0, 0x80(r9)
    b       _8004a25c
_8004a228:
    xoris	r4, r0, 0x8000
    lis	r0, 0x4330
    lis	r5, -0x7ff7
    stw	r4, 0xc(r1)
    addi	r4, r5, 0x980
    stw	r0, 8(r1)
    lis	r5, -0x7ff7
    lfd	f1, 0(r4)
    lfd	f0, 8(r1)
    lfd	f2, 0x988(r5)
    fsub	f0, f0, f1
    fdiv	f0, f2, f0
    stfd	f0, 0x80(r9)
_8004a25c:
    lha	r11, 0x8c(r6)
    lis	r4, -0x7ff7
    lwz	r8, 0x88(r9)
    li	r5, 0
    lha	r0, 0x88(r6)
    lfd	f2, 0x980(r4)
    mr	r4, r9
    sth	r0, 8(r8)
    lis	r0, 0x4330
    sth	r11, 0xa(r8)
    b       _8004a50c
_8004a288:
    lha	r6, 0(r7)
    cmpwi	r5, 0
    lha	r11, 0xa(r10)
    lha	r8, 8(r10)
    sth	r8, 8(r9)
    sth	r11, 0xa(r9)
    bne     _8004a2d4
    li	r12, 0
    mr	r29, r9
    mr	r11, r12
    b       _8004a2c0
_8004a2b4:
    sth	r11, 0x18(r29)
    addi	r29, r29, 2
    addi	r12, r12, 1
_8004a2c0:
    lwz	r8, 0x14(r9)
    cmpw	r12, r8
    blt     _8004a2b4
    li	r8, 0
    stw	r8, 0x78(r9)
_8004a2d4:
    cmplwi	r9, 0
    beq     _8004a370
    lha	r30, 6(r9)
    li	r8, -0x8000
    lha	r31, 0xa(r9)
    lha	r12, 4(r9)
    lha	r11, 8(r9)
    mullw	r31, r30, r31
    mullw	r11, r12, r11
    srawi	r12, r31, 0xc
    srawi	r11, r11, 0xc
    subf	r11, r11, r6
    subf	r11, r12, r11
    cmpwi	r11, -0x8000
    blt     _8004a314
    mr	r8, r11
_8004a314:
    cmpwi	r8, 0x7fff
    ble     _8004a324
    li	r8, 0x7fff
    b       _8004a334
_8004a324:
    cmpwi	r11, -0x8000
    li	r8, -0x8000
    blt     _8004a334
    mr	r8, r11
_8004a334:
    sth	r8, 0x18(r4)
    extsh	r29, r8
    srawi	r12, r29, 0x1f
    xor	r11, r12, r29
    lwz	r8, 0x78(r9)
    subf	r11, r12, r11
    cmpw	r11, r8
    ble     _8004a364
    srawi	r11, r29, 0x1f
    xor	r8, r11, r29
    subf	r8, r11, r8
    stw	r8, 0x78(r9)
_8004a364:
    lha	r8, 8(r9)
    sth	r8, 0xa(r9)
    sth	r6, 8(r9)
_8004a370:
    cmplwi	r9, 0
    bne     _8004a380
    li	r6, 0
    b       _8004a384
_8004a380:
    lha	r6, 0x18(r4)
_8004a384:
    extsh	r6, r6
    stw	r0, 8(r1)
    xoris	r6, r6, 0x8000
    lfd	f0, 0x80(r9)
    stw	r6, 0xc(r1)
    li	r6, -0x8000
    lfd	f1, 8(r1)
    fsub	f1, f1, f2
    fmul	f0, f1, f0
    fctiwz	f0, f0
    stfd	f0, 0x10(r1)
    lwz	r8, 0x14(r1)
    cmpwi	r8, -0x8000
    blt     _8004a3c0
    mr	r6, r8
_8004a3c0:
    cmpwi	r6, 0x7fff
    ble     _8004a3d0
    li	r6, 0x7fff
    b       _8004a3e0
_8004a3d0:
    cmpwi	r8, -0x8000
    li	r6, -0x8000
    blt     _8004a3e0
    mr	r6, r8
_8004a3e0:
    extsh.	r8, r6
    bge     _8004a408
    lis	r6, 0x3800
    addi	r8, r8, -0x924
    addi	r6, r6, 0x7001
    mulhw	r6, r6, r8
    srawi	r6, r6, 0xa
    srwi	r8, r6, 0x1f
    add	r8, r6, r8
    b       _8004a424
_8004a408:
    lis	r6, 0x3800
    addi	r8, r8, 0x924
    addi	r6, r6, 0x7001
    mulhw	r6, r6, r8
    srawi	r6, r6, 0xa
    srwi	r8, r6, 0x1f
    add	r8, r6, r8
_8004a424:
    cmpwi	r8, -8
    li	r6, -8
    blt     _8004a434
    mr	r6, r8
_8004a434:
    cmpwi	r6, 7
    bge     _8004a450
    cmpwi	r8, -8
    li	r11, -8
    blt     _8004a454
    mr	r11, r8
    b       _8004a454
_8004a450:
    li	r11, 7
_8004a454:
    addi	r6, r5, 0x58
    stbx	r11, r9, r6
    li	r6, -0x8000
    lha	r8, 0x7c(r9)
    mullw	r8, r11, r8
    cmpwi	r8, -0x8000
    blt     _8004a474
    mr	r6, r8
_8004a474:
    cmpwi	r6, 0x7fff
    ble     _8004a484
    li	r6, 0x7fff
    b       _8004a494
_8004a484:
    cmpwi	r8, -0x8000
    li	r6, -0x8000
    blt     _8004a494
    mr	r6, r8
_8004a494:
    lwz	r29, 0x88(r9)
    extsh	r31, r6
    cmplwi	r29, 0
    beq     _8004a500
    lha	r12, 4(r29)
    li	r6, -0x8000
    lha	r30, 8(r29)
    lha	r11, 6(r29)
    lha	r8, 0xa(r29)
    mullw	r12, r12, r30
    mullw	r8, r11, r8
    add	r8, r12, r8
    srawi	r8, r8, 0xc
    add	r8, r31, r8
    cmpwi	r8, -0x8000
    ble     _8004a4d8
    mr	r6, r8
_8004a4d8:
    cmpwi	r6, 0x7fff
    bge     _8004a4f4
    cmpwi	r8, -0x8000
    li	r6, -0x8000
    ble     _8004a4f8
    mr	r6, r8
    b       _8004a4f8
_8004a4f4:
    li	r6, 0x7fff
_8004a4f8:
    sth	r30, 0xa(r29)
    sth	r6, 8(r29)
_8004a500:
    addi	r7, r7, 2
    addi	r4, r4, 2
    addi	r5, r5, 1
_8004a50c:
    lwz	r6, 0x44(r3)
    cmpw	r5, r6
    blt     _8004a288
    lwz	r31, 0x2c(r1)
    li	r3, 0
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    addi	r1, r1, 0x30
    blr	
    lbz	r3, 2(r3)
    extsb	r3, r3
    blr	
    lwz	r3, 0x10(r3)
    blr	
    stw	r4, 0x28(r3)
    li	r3, 1
    blr	
}

asm void fn_8004A550(void)
{
    nofralloc
    stw	r4, 0x18(r3)
    stw	r5, 0x14(r3)
    li	r3, 1
    blr	
}

#pragma pop
