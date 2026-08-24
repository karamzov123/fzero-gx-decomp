#pragma push
#pragma force_active on

extern asm void avload_AssertPanic(void);
extern asm void fn_80078DA8(void);
extern asm void _savegpr_27(void);
extern asm void __msl_strstr(void);
extern asm void _restgpr_27(void);
extern unsigned char lbl_8015AB70[80];
extern unsigned char lbl_8015ABCC[12];

asm void fn_80071100(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    mr	r30, r5
    stw	r29, 0x14(r1)
    or.	r29, r4, r4
    stw	r28, 0x10(r1)
    mr	r28, r3
    bne	_80071160
    lwz	r12, -0x76b4(r13)
    li	r3, 0x20
    mtctr	r12
    bctrl	
    or.	r29, r3, r3
    bne	_8007115c
    lis     r3, lbl_8015AB70@ha
    lis     r4, lbl_8015ABCC@ha
    addi	r3, r3, lbl_8015AB70@l
    addi	r4, r4, lbl_8015ABCC@l
    bl      avload_AssertPanic
_8007115c:
    li	r31, 1
_80071160:
    mr	r3, r29
    mr	r4, r28
    mr	r5, r30
    bl      fn_80078DA8
    cmpwi	r31, 0
    bne	_80071184
    lwz	r0, 0x10(r29)
    ori	r0, r0, 1
    stw	r0, 0x10(r29)
_80071184:
    lwz	r0, 0x24(r1)
    mr	r3, r29
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_800711A8(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    li	r31, 0
    stw	r30, 0x18(r1)
    li	r30, 0
    stw	r29, 0x14(r1)
    mr	r29, r3
    b	_8007120c
_800711d0:
    lwz	r0, 0x14(r29)
    lwz	r3, 8(r29)
    cmplwi	r0, 0
    lwzx	r3, r3, r31
    bne	_80071204
    cmplwi	r3, 0
    beq	_80071204
    lwz	r3, 0x24(r3)
    cmplwi	r3, 0
    beq	_80071204
    lwz	r12, -0x76b8(r13)
    mtctr	r12
    bctrl	
_80071204:
    addi	r31, r31, 8
    addi	r30, r30, 1
_8007120c:
    lwz	r0, 0(r29)
    cmpw	r30, r0
    blt	_800711d0
    lwz	r3, 0x14(r29)
    cmplwi	r3, 0
    beq	_80071230
    lwz	r12, -0x76b8(r13)
    mtctr	r12
    bctrl	
_80071230:
    lwz	r0, 0x10(r29)
    clrlwi.	r0, r0, 0x1f
    bne	_8007124c
    lwz	r12, -0x76b8(r13)
    mr	r3, r29
    mtctr	r12
    bctrl	
_8007124c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80071268(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r11, r1, 0x20
    bl      _savegpr_27
    mr	r27, r3
    mr	r28, r4
    li	r30, 0
    li	r31, 0
    b	_800712bc
_80071290:
    lwz	r0, 8(r27)
    mr	r4, r28
    add	r29, r0, r31
    lwz	r3, 4(r29)
    bl      __msl_strstr
    cmplwi	r3, 0
    beq	_800712b4
    lwz	r3, 0(r29)
    b	_800712cc
_800712b4:
    addi	r31, r31, 8
    addi	r30, r30, 1
_800712bc:
    lwz	r0, 0(r27)
    cmpw	r30, r0
    blt	_80071290
    li	r3, 0
_800712cc:
    addi	r11, r1, 0x20
    bl      _restgpr_27
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
