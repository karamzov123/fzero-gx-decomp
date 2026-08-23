#pragma push
#pragma force_active on

extern void fn_8004559C(void);
extern void fn_8004550C(void);
extern void fn_80045514(void);
extern void fn_800453A4(void);
extern void fn_8004538C(void);
extern void fn_80045588(void);
extern void fn_80057DB0(void);
extern void fn_800455A4(void);
extern void fn_800455B8(void);
extern void fn_80047464(void);
extern void memcpy(void);
extern void fn_800589BC(void);
extern void fn_80045354(void);
extern void fn_800433D0(void);
extern void fn_800433F4(void);
extern void fn_80045D3C(void);
extern void fn_80046738(void);
extern void memset(void);
extern void fn_80046718(void);
extern void fn_80057DA8(void);
extern void fn_80057DA0(void);
extern void fn_80045D90(void);
extern void fn_800455AC(void);

asm void fn_80041BF8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    stw	r28, 0x10(r1)
    lwz	r3, 0x3c(r3)
    lwz	r31, 4(r29)
    cmpwi	r3, 0
    lwz	r30, 8(r29)
    blt     _80041c50
    lwz	r0, 0x40(r29)
    cmpw	r0, r3
    blt     _80041c50
    lwz	r12, 0x48(r29)
    cmplwi	r12, 0
    beq     _80041c50
    lwz	r3, 0x4c(r29)
    mtctr	r12
    bctrl	
_80041c50:
    lbz	r0, 3(r29)
    cmpwi	r0, 1
    bne     _80041c88
    lwz	r5, 0(r30)
    mr	r3, r30
    li	r4, 1
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    cmpwi	r3, 0
    bne     _80041c88
    li	r0, 3
    stb	r0, 1(r29)
    b       _80041de0
_80041c88:
    lwz	r4, 0(r30)
    lis	r5, -0x8000
    mr	r3, r30
    addi	r6, r29, 0x14
    lwz	r12, 0x18(r4)
    addi	r5, r5, -1
    li	r4, 1
    mtctr	r12
    bctrl	
    mr	r3, r31
    bl      fn_8004559C
    cmpwi	r3, 0
    bne     _80041d04
    lwz	r0, 0x18(r29)
    cmpwi	r0, 2
    blt     _80041d04
    lwz	r3, 0x14(r29)
    lha	r0, 0(r3)
    clrlwi	r0, r0, 0x10
    cmplwi	r0, 0x8001
    bne     _80041d04
    li	r0, 3
    mr	r3, r30
    stb	r0, 1(r29)
    addi	r5, r29, 0x14
    li	r4, 1
    lwz	r6, 0(r30)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _80041de0
_80041d04:
    lwz	r3, 4(r29)
    bl      fn_8004550C
    lwz	r0, 0x34(r29)
    cmpw	r0, r3
    blt     _80041d40
    li	r0, 3
    mr	r3, r30
    stb	r0, 1(r29)
    addi	r5, r29, 0x14
    li	r4, 1
    lwz	r6, 0(r30)
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _80041de0
_80041d40:
    lwz	r3, 4(r29)
    bl      fn_80045514
    lwz	r6, 0xc(r29)
    mr	r28, r3
    li	r4, 0
    lwz	r5, 0(r6)
    mr	r3, r6
    lwz	r12, 0x24(r5)
    mtctr	r12
    bctrl	
    srwi	r0, r3, 0x1f
    add	r0, r0, r3
    srawi	r0, r0, 1
    cmpw	r0, r28
    bge     _80041d9c
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r29, 0x14
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _80041de0
_80041d9c:
    mr	r3, r31
    bl      fn_8004559C
    cmpwi	r3, 0xa
    bne     _80041dc8
    lwz	r6, 0(r30)
    mr	r3, r30
    addi	r5, r29, 0x14
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
_80041dc8:
    lwz	r4, 0x14(r29)
    mr	r3, r31
    lwz	r5, 0x18(r29)
    bl      fn_800453A4
    mr	r3, r31
    bl      fn_8004538C
_80041de0:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80041E00(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    stmw	r24, 0x10(r1)
    mr	r31, r3
    mr	r24, r4
    mr	r29, r5
    mr	r30, r6
    mr	r28, r31
    mr	r27, r31
    li	r25, 0
    lwz	r26, 0xc(r3)
    b       _80041e60
_80041e34:
    lwz	r3, 0xc(r27)
    addi	r6, r28, 0x1c
    li	r4, 0
    li	r5, 0x4000
    lwz	r7, 0(r3)
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    addi	r28, r28, 8
    addi	r27, r27, 4
    addi	r25, r25, 1
_80041e60:
    lwz	r3, 4(r31)
    bl      fn_80045588
    cmpw	r25, r3
    blt     _80041e34
    mr	r3, r26
    bl      fn_80057DB0
    lwz	r0, 0x1c(r31)
    subf	r3, r3, r0
    srwi	r0, r3, 0x1f
    add	r0, r0, r3
    srawi	r0, r0, 1
    stw	r0, 0(r24)
    lwz	r3, 0x20(r31)
    lwz	r4, 0x38(r31)
    srwi	r0, r3, 0x1f
    add	r0, r0, r3
    srawi	r0, r0, 1
    cmpw	r0, r4
    bge     _80041eb0
    mr	r4, r0
_80041eb0:
    stw	r4, 0(r29)
    lwz	r3, 0x3c(r31)
    cmpwi	r3, 0
    blt     _80041ed0
    lwz	r0, 0x40(r31)
    subf	r0, r0, r3
    stw	r0, 0(r30)
    b       _80041edc
_80041ed0:
    lis	r3, 0x2000
    addi	r0, r3, -1
    stw	r0, 0(r30)
_80041edc:
    lwz	r3, 4(r31)
    bl      fn_800455A4
    lmw	r24, 0x10(r1)
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80041EF8(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    li	r4, 1
    li	r5, 0x1000
    stw	r0, 0x34(r1)
    addi	r6, r1, 0x10
    stw	r31, 0x2c(r1)
    mr	r31, r3
    stw	r30, 0x28(r1)
    stw	r29, 0x24(r1)
    stw	r28, 0x20(r1)
    lwz	r29, 8(r3)
    lwz	r30, 4(r3)
    lwz	r7, 0(r29)
    mr	r3, r29
    lwz	r12, 0x18(r7)
    mtctr	r12
    bctrl	
    lwz	r5, 0x14(r1)
    cmpwi	r5, 0x10
    bge     _80041f6c
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0x10
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _800420d4
_80041f6c:
    lwz	r4, 0x10(r1)
    mr	r3, r30
    bl      fn_800455B8
    or.	r28, r3, r3
    beq     _80041f8c
    lwz	r0, 0x14(r1)
    cmpw	r28, r0
    ble     _80041fac
_80041f8c:
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0x10
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _800420d4
_80041fac:
    cmpwi	r28, 0
    bge     _80041ff0
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0x10
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    lis	r3, -0x7ff7
    lis	r4, -0x7ff7
    addi	r3, r3, 0x18
    addi	r4, r4, 0x38
    bl      fn_80047464
    li	r0, 4
    stb	r0, 1(r31)
    b       _800420d4
_80041ff0:
    stw	r28, 0x98(r31)
    mr	r3, r30
    bl      fn_8004559C
    cmpwi	r3, 4
    bne     _8004200c
    li	r0, 1
    stb	r0, 3(r31)
_8004200c:
    mr	r3, r30
    bl      fn_8004559C
    cmpwi	r3, 2
    bne     _8004203c
    lwz	r5, 0x14(r1)
    addi	r3, r31, 0x58
    lwz	r4, 0x10(r1)
    cmpwi	r5, 0x40
    bge     _80042034
    b       _80042038
_80042034:
    li	r5, 0x40
_80042038:
    bl      memcpy
_8004203c:
    mr	r3, r30
    bl      fn_8004559C
    addi	r0, r3, -0xa
    cmplwi	r0, 1
    ble     _80042060
    cmpwi	r3, 0x14
    beq     _80042060
    cmpwi	r3, 0xf
    bne     _80042080
_80042060:
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0x10
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
    b       _800420cc
_80042080:
    addi	r3, r1, 0x10
    mr	r4, r28
    mr	r5, r3
    addi	r6, r1, 8
    bl      fn_800589BC
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 0x10
    li	r4, 0
    lwz	r12, 0x20(r6)
    mtctr	r12
    bctrl	
    lwz	r6, 0(r29)
    mr	r3, r29
    addi	r5, r1, 8
    li	r4, 1
    lwz	r12, 0x1c(r6)
    mtctr	r12
    bctrl	
_800420cc:
    li	r0, 2
    stb	r0, 1(r31)
_800420d4:
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    lwz	r30, 0x28(r1)
    lwz	r29, 0x24(r1)
    lwz	r28, 0x20(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_800420F4(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    lwz	r3, 4(r3)
    bl      fn_80045354
    li	r0, 0
    stb	r0, 1(r31)
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8004212C(void)
{
    nofralloc
    li	r6, 0
    lis	r4, -0x8000
    stw	r6, 0x98(r3)
    addi	r5, r4, -1
    li	r4, -1
    li	r0, 1
    stw	r6, 0x2c(r3)
    stw	r6, 0x30(r3)
    stw	r6, 0x34(r3)
    stw	r5, 0x38(r3)
    stw	r4, 0x3c(r3)
    stw	r6, 0x40(r3)
    stw	r6, 0x44(r3)
    stb	r6, 3(r3)
    stb	r0, 1(r3)
    blr	
}

asm void fn_8004216C(void)
{
    nofralloc
    blr	
}

asm void fn_80042170(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r4, 0x38(r3)
    lwz	r3, 4(r3)
    bl      fn_800433D0
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80042198(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r4, 8(r3)
    lwz	r3, 4(r3)
    bl      fn_800433F4
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_800421C0(void)
{
    nofralloc
    lbz	r3, 1(r3)
    extsb	r3, r3
    blr	
}

asm void fn_800421CC(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    or.	r31, r3, r3
    beq     _80042214
    lwz	r3, 4(r31)
    cmplwi	r3, 0
    beq     _800421fc
    li	r0, 0
    stw	r0, 4(r31)
    bl      fn_80045D3C
_800421fc:
    bl      fn_80046738
    mr	r3, r31
    li	r4, 0
    li	r5, 0x9c
    bl      memset
    bl      fn_80046718
_80042214:
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_80042228(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r6, -0x7fe8
    stw	r0, 0x24(r1)
    li	r0, 2
    stmw	r26, 8(r1)
    mr	r30, r5
    mr	r28, r3
    addi	r5, r6, -0x6740
    mr	r29, r4
    li	r3, 0
    lwz	r26, 0(r30)
    mtctr	r0
_8004225c:
    lbz	r0, 0(r5)
    extsb.	r0, r0
    beq     _80042300
    lbz	r0, 0x9c(r5)
    addi	r3, r3, 1
    addi	r5, r5, 0x9c
    extsb.	r0, r0
    beq     _80042300
    lbz	r0, 0x9c(r5)
    addi	r3, r3, 1
    addi	r5, r5, 0x9c
    extsb.	r0, r0
    beq     _80042300
    lbz	r0, 0x9c(r5)
    addi	r3, r3, 1
    addi	r5, r5, 0x9c
    extsb.	r0, r0
    beq     _80042300
    lbz	r0, 0x9c(r5)
    addi	r3, r3, 1
    addi	r5, r5, 0x9c
    extsb.	r0, r0
    beq     _80042300
    lbz	r0, 0x9c(r5)
    addi	r3, r3, 1
    addi	r5, r5, 0x9c
    extsb.	r0, r0
    beq     _80042300
    lbz	r0, 0x9c(r5)
    addi	r3, r3, 1
    addi	r5, r5, 0x9c
    extsb.	r0, r0
    beq     _80042300
    lbz	r0, 0x9c(r5)
    addi	r3, r3, 1
    addi	r5, r5, 0x9c
    extsb.	r0, r0
    beq     _80042300
    addi	r5, r5, 0x9c
    addi	r3, r3, 1
    bdnz    _8004225c
_80042300:
    cmpwi	r3, 0x10
    bne     _80042310
    li	r3, 0
    b       _800424a4
_80042310:
    mulli	r5, r3, 0x9c
    lis	r4, -0x7fe8
    mr	r3, r26
    addi	r0, r4, -0x6740
    add	r31, r0, r5
    bl      fn_80057DB0
    mr	r0, r3
    mr	r3, r26
    mr	r27, r0
    bl      fn_80057DA8
    srwi	r0, r3, 0x1f
    add	r0, r0, r3
    mr	r3, r26
    srawi	r26, r0, 1
    bl      fn_80057DA0
    srwi	r0, r3, 0x1f
    mr	r4, r27
    add	r0, r0, r3
    mr	r3, r29
    srawi	r0, r0, 1
    mr	r5, r26
    add	r6, r26, r0
    bl      fn_80045D90
    stw	r3, 4(r31)
    lwz	r3, 4(r31)
    cmplwi	r3, 0
    bne     _80042384
    li	r3, 0
    b       _800424a4
_80042384:
    lis	r4, -0x7ffc
    mr	r5, r31
    addi	r4, r4, 0x1e00
    bl      fn_800455AC
    stw	r28, 8(r31)
    cmpwi	r29, 0
    li	r6, 0
    stb	r29, 2(r31)
    ble     _80042450
    cmpwi	r29, 8
    addi	r3, r29, -8
    ble     _80042420
    addi	r0, r3, 7
    mr	r4, r30
    srwi	r0, r0, 3
    mr	r5, r31
    mtctr	r0
    cmpwi	r3, 0
    ble     _80042420
_800423d0:
    lwz	r0, 0(r4)
    addi	r6, r6, 8
    stw	r0, 0xc(r5)
    lwz	r0, 4(r4)
    stw	r0, 0x10(r5)
    lwz	r0, 8(r4)
    stw	r0, 0x14(r5)
    lwz	r0, 0xc(r4)
    stw	r0, 0x18(r5)
    lwz	r0, 0x10(r4)
    stw	r0, 0x1c(r5)
    lwz	r0, 0x14(r4)
    stw	r0, 0x20(r5)
    lwz	r0, 0x18(r4)
    stw	r0, 0x24(r5)
    lwz	r0, 0x1c(r4)
    addi	r4, r4, 0x20
    stw	r0, 0x28(r5)
    addi	r5, r5, 0x20
    bdnz    _800423d0
_80042420:
    slwi	r4, r6, 2
    subf	r0, r6, r29
    add	r3, r30, r4
    add	r4, r31, r4
    mtctr	r0
    cmpw	r6, r29
    bge     _80042450
_8004243c:
    lwz	r0, 0(r3)
    addi	r3, r3, 4
    stw	r0, 0xc(r4)
    addi	r4, r4, 4
    bdnz    _8004243c
_80042450:
    li	r6, 0
    lis	r3, -0x8000
    stb	r6, 1(r31)
    addi	r5, r3, -1
    li	r4, -1
    li	r0, 1
    stw	r6, 0x98(r31)
    mr	r3, r31
    stw	r6, 0x2c(r31)
    stw	r6, 0x30(r31)
    stw	r6, 0x34(r31)
    stw	r5, 0x38(r31)
    stw	r4, 0x3c(r31)
    stw	r6, 0x40(r31)
    stw	r6, 0x44(r31)
    stb	r6, 3(r31)
    stw	r6, 0x48(r31)
    stw	r6, 0x4c(r31)
    stw	r6, 0x50(r31)
    stw	r6, 0x54(r31)
    stb	r0, 0(r31)
_800424a4:
    lmw	r26, 8(r1)
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
