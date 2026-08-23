#pragma push
#pragma force_active on

extern asm void _savegpr_26(void);
extern asm void fn_8007174C(void);
extern asm void OSReport(void);
extern asm void fn_80078F0C(void);
extern asm void _restgpr_26(void);
extern asm void _savegpr_27(void);
extern asm void fn_80078DA8(void);
extern asm void _restgpr_27(void);
extern asm void DCInvalidateRange(void);
extern asm void AIGetDSPInterruptEnable(void);
extern asm void ARStartDMA(void);

asm void fn_80070E1C(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r11, r1, 0x20
    bl      _savegpr_26
    lwz	r12, -0x769c(r13)
    lis	r5, -0x7fea
    mr	r26, r3
    mr	r27, r4
    addi	r31, r5, -0x5490
    mtctr	r12
    bctrl	
    lwz	r12, -0x76a0(r13)
    mr	r28, r3
    mr	r3, r26
    mr	r4, r28
    mtctr	r12
    bctrl	
    cmpwi	r3, 0
    bne	_80070e74
    li	r3, 0
    b	_80070f2c
_80070e74:
    lwz	r12, -0x76a4(r13)
    mr	r3, r28
    mtctr	r12
    bctrl	
    mr	r29, r3
    lwz	r12, -0x76b4(r13)
    addi	r0, r29, 0x1f
    rlwinm	r3, r0, 0, 0, 0x1a
    mtctr	r12
    bctrl	
    or.	r30, r3, r3
    bne	_80070eb0
    mr	r4, r26
    addi	r3, r31, 0
    bl      fn_8007174C
_80070eb0:
    lwz	r12, -0x76a8(r13)
    mr	r3, r28
    mr	r4, r30
    mr	r5, r29
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
    lwz	r3, 0(r30)
    addis	r0, r3, -0x4743
    cmplwi	r0, 0x4d46
    beq	_80070f14
    mr	r4, r26
    addi	r3, r31, 0x20
    crxor	6, 6, 6
    bl      OSReport
    li	r3, 0
    b	_80070f2c
_80070f14:
    mr	r3, r30
    mr	r4, r27
    addi	r6, r31, 0x3c
    li	r5, 0
    bl      fn_80078F0C
    mr	r3, r30
_80070f2c:
    addi	r11, r1, 0x20
    bl      _restgpr_26
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80070F44(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r11, r1, 0x20
    bl      _savegpr_27
    lwz	r12, -0x769c(r13)
    mr	r31, r3
    mr	r27, r4
    mtctr	r12
    bctrl	
    lwz	r12, -0x76a0(r13)
    mr	r28, r3
    mr	r3, r31
    mr	r4, r28
    mtctr	r12
    bctrl	
    cmpwi	r3, 0
    bne	_80070f94
    li	r3, 0
    b	_8007102c
_80070f94:
    lwz	r12, -0x76a4(r13)
    mr	r3, r28
    mtctr	r12
    bctrl	
    mr	r30, r3
    lwz	r12, -0x76b4(r13)
    addi	r0, r30, 0x1f
    rlwinm	r3, r0, 0, 0, 0x1a
    addi	r3, r3, 0x20
    mtctr	r12
    bctrl	
    or.	r29, r3, r3
    bne	_80070fd8
    lis	r3, -0x7fea
    mr	r4, r31
    addi	r3, r3, -0x5490
    bl      fn_8007174C
_80070fd8:
    lwz	r12, -0x76a8(r13)
    addi	r31, r29, 0x20
    mr	r3, r28
    mr	r5, r30
    mr	r4, r31
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
    mr	r3, r29
    mr	r4, r31
    mr	r5, r27
    bl      fn_80078DA8
    mr	r3, r29
_8007102c:
    addi	r11, r1, 0x20
    bl      _restgpr_27
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void fn_80071044(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    addi	r11, r1, 0x20
    bl      _savegpr_26
    mr	r27, r4
    lwz	r12, -0x76b4(r13)
    addi	r0, r27, 0x1f
    mr	r26, r3
    rlwinm	r31, r0, 0, 0, 0x1a
    mr	r28, r5
    addi	r3, r31, 0x20
    mtctr	r12
    bctrl	
    or.	r30, r3, r3
    bne	_80071098
    lis	r3, -0x7fea
    lis	r4, -0x7fea
    addi	r3, r3, -0x5490
    addi	r4, r4, -0x5440
    bl      fn_8007174C
_80071098:
    addi	r29, r30, 0x20
    mr	r4, r31
    mr	r3, r29
    bl      DCInvalidateRange
_800710a8:
    bl      AIGetDSPInterruptEnable
    cmplwi	r3, 0
    bne	_800710a8
    mr	r4, r29
    mr	r5, r26
    mr	r6, r27
    li	r3, 1
    bl      ARStartDMA
_800710c8:
    bl      AIGetDSPInterruptEnable
    cmplwi	r3, 0
    bne	_800710c8
    mr	r3, r30
    mr	r4, r29
    mr	r5, r28
    bl      fn_80078DA8
    mr	r3, r30
    addi	r11, r1, 0x20
    bl      _restgpr_26
    lwz	r0, 0x24(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

#pragma pop
