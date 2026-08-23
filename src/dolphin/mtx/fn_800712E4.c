#pragma push
#pragma force_active on

extern asm void _savegpr_23(void);
extern asm void fn_800718BC(void);
extern asm void _restgpr_23(void);
extern asm void _savegpr_25(void);
extern asm void fn_80071C04(void);
extern asm void _restgpr_25(void);
extern asm void fn_8007174C(void);

asm void fn_800712E4(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    addi	r11, r1, 0x30
    bl      _savegpr_23
    mr	r23, r3
    mr	r24, r4
    mr	r25, r5
    li	r28, 0
    li	r29, 0
    b	_800713bc
_80071310:
    lwz	r3, 8(r23)
    lwzx	r26, r3, r29
    cmplwi	r26, 0
    beq	_800713b4
    addi	r31, r26, 0x40
    li	r27, 0
    li	r30, 0
    b	_800713a8
_80071330:
    lwz	r0, 0(r31)
    rlwinm.	r0, r0, 0, 0xa, 0xa
    beq	_8007139c
    lhz	r5, 4(r31)
    mr	r3, r25
    li	r4, 0
    b	_8007136c
_8007134c:
    cmplw	r5, r0
    bne	_80071364
    slwi	r3, r4, 2
    addi	r0, r3, 2
    lhzx	r5, r25, r0
    b	_80071378
_80071364:
    addi	r3, r3, 4
    addi	r4, r4, 1
_8007136c:
    lhz	r0, 0(r3)
    cmplwi	r0, 0xffff
    bne	_8007134c
_80071378:
    lwz	r4, 0x24(r26)
    rlwinm	r0, r5, 4, 0xc, 0x1b
    mr	r3, r31
    mr	r5, r24
    add	r4, r4, r30
    stw	r4, 8(r31)
    lwz	r4, 4(r24)
    add	r4, r4, r0
    bl      fn_800718BC
_8007139c:
    addi	r31, r31, 0x20
    addi	r30, r30, 0x20
    addi	r27, r27, 1
_800713a8:
    lhz	r0, 0x18(r26)
    cmpw	r27, r0
    blt	_80071330
_800713b4:
    addi	r29, r29, 8
    addi	r28, r28, 1
_800713bc:
    lwz	r0, 0(r23)
    cmpw	r28, r0
    blt	_80071310
    addi	r11, r1, 0x30
    bl      _restgpr_23
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_800713E0(void)
{
    nofralloc
    stwu	r1, -0x30(r1)
    mflr	r0
    stw	r0, 0x34(r1)
    addi	r11, r1, 0x30
    bl      _savegpr_25
    mr	r25, r3
    mr	r26, r4
    li	r29, 0
    li	r30, 0
    b	_8007144c
_80071408:
    lwz	r3, 8(r25)
    lwzx	r27, r3, r30
    cmplwi	r27, 0
    beq	_80071444
    addi	r31, r27, 0x40
    li	r28, 0
    b	_80071438
_80071424:
    mr	r3, r31
    mr	r4, r26
    bl      fn_80071C04
    addi	r31, r31, 0x20
    addi	r28, r28, 1
_80071438:
    lhz	r0, 0x18(r27)
    cmpw	r28, r0
    blt	_80071424
_80071444:
    addi	r30, r30, 8
    addi	r29, r29, 1
_8007144c:
    lwz	r0, 0(r25)
    cmpw	r29, r0
    blt	_80071408
    addi	r11, r1, 0x30
    bl      _restgpr_25
    lwz	r0, 0x34(r1)
    mtlr	r0
    addi	r1, r1, 0x30
    blr	
}

asm void fn_80071470(void)
{
    nofralloc
    slwi	r0, r4, 4
    add	r4, r3, r0
    lwz	r0, 8(r4)
    add	r3, r3, r0
    blr	
}

asm void fn_80071484(void)
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
    lwz	r12, -0x769c(r13)
    mtctr	r12
    bctrl	
    lwz	r12, -0x76a0(r13)
    mr	r28, r3
    mr	r3, r29
    mr	r4, r28
    mtctr	r12
    bctrl	
    cmpwi	r3, 0
    bne	_800714d8
    li	r3, 0
    b	_80071580
_800714d8:
    lwz	r12, -0x76a4(r13)
    mr	r3, r28
    mtctr	r12
    bctrl	
    mr	r31, r3
    lwz	r12, -0x76b4(r13)
    addi	r0, r31, 0x1f
    rlwinm	r3, r0, 0, 0, 0x1a
    addi	r3, r3, 0x20
    mtctr	r12
    bctrl	
    or.	r30, r3, r3
    bne	_8007151c
    lis	r3, -0x7fea
    mr	r4, r29
    addi	r3, r3, -0x5428
    bl      fn_8007174C
_8007151c:
    addi	r0, r30, 0x3f
    lwz	r12, -0x76a8(r13)
    rlwinm	r29, r0, 0, 0, 0x1a
    mr	r3, r28
    mr	r4, r29
    mr	r5, r31
    li	r6, 0
    mtctr	r12
    bctrl	
    lwz	r12, -0x76ac(r13)
    mr	r3, r28
    mtctr	r12
    bctrl	
    lwz	r12, -0x76b0(r13)
    mr	r3, r28
    mtctr	r12
    bctrl	
    lwz	r5, 0(r29)
    addi	r4, r29, 4
    li	r0, 0
    mr	r3, r30
    stw	r5, 0(r30)
    stw	r4, 4(r30)
    stw	r29, 8(r30)
    stw	r0, 0xc(r30)
_80071580:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
