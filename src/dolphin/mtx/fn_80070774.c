#pragma push
#pragma force_active on

extern asm void _savegpr_25(void);
extern asm void fn_80070CF8(void);
extern asm void DCFlushRange(void);
extern asm void GXInit(void);
extern asm void GXInitFifoBase(void);
extern asm void GXInitFifoPtrs(void);
extern asm void fn_80071D30(void);
extern asm void fn_80038EEC(void);
extern asm void fn_80074188(void);
extern asm void fn_8007423C(void);
extern asm void fn_800743C4(void);
extern asm void fn_80034D9C(void);
extern asm void GXSetCopyClear(void);
extern asm void fn_80037C2C(void);
extern asm void fn_80037D14(void);
extern asm void GXWriteLightAttn(void);
extern asm void ModelMatchCachedSlot_B20(void);
extern asm void fn_80035110(void);
extern asm void fn_800350F4(void);
extern asm void fn_8001B42C(void);
extern asm void fn_8001BD84(void);
extern asm void fn_8001BC54(void);
extern asm void VIWaitForRetrace(void);
extern asm void _restgpr_25(void);
extern unsigned char lbl_8019E18C[132];

asm void fn_80070774(void)
{
    nofralloc
    stwu	r1, -0x50(r1)
    mflr	r0
    stw	r0, 0x54(r1)
    addi	r11, r1, 0x50
    bl      _savegpr_25
    lwz	r6, -0x76cc(r13)
    mr	r27, r3
    mr	r28, r4
    mr	r29, r5
    lhz	r3, 4(r6)
    addi	r0, r3, 0xf
    rlwinm	r0, r0, 0, 0x10, 0x1b
    mulli	r0, r0, 0x210
    slwi	r25, r0, 1
    mr	r3, r25
    bl      fn_80070CF8
    addi	r0, r25, 0x1f
    mr	r31, r3
    rlwinm	r26, r0, 0, 0, 0x1a
    mr	r4, r26
    bl      DCFlushRange
    lwz	r0, -0x76e0(r13)
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    bne	_800707e8
    mr	r3, r25
    bl      fn_80070CF8
    mr	r4, r26
    mr	r30, r3
    bl      DCFlushRange
_800707e8:
    mr	r3, r28
    bl      fn_80070CF8
    stw	r28, -0x76dc(r13)
    mr	r4, r28
    bl      GXInit
    lwz	r4, -0x7690(r13)
    cmpwi	r27, 0
    stw	r3, 0x14(r4)
    beq	_8007085c
    lwz	r5, -0x76e0(r13)
    lis     r3, lbl_8019E18C@ha
    lwz	r4, -0x7690(r13)
    addi	r0, r3, lbl_8019E18C@l
    ori	r5, r5, 4
    mr	r3, r28
    stw	r5, -0x76e0(r13)
    stw	r0, 0x18(r4)
    bl      fn_80070CF8
    lis     r4, lbl_8019E18C@ha
    mr	r26, r3
    addi	r3, r4, lbl_8019E18C@l
    mr	r5, r28
    mr	r4, r26
    bl      GXInitFifoBase
    lis     r3, lbl_8019E18C@ha
    mr	r4, r26
    addi	r3, r3, lbl_8019E18C@l
    mr	r5, r26
    bl      GXInitFifoPtrs
_8007085c:
    lwz	r3, -0x7690(r13)
    stw	r31, 4(r3)
    lwz	r0, -0x76e0(r13)
    rlwinm.	r0, r0, 0, 0x1b, 0x1b
    beq	_8007087c
    lwz	r3, -0x7690(r13)
    stw	r31, 8(r3)
    b	_80070884
_8007087c:
    lwz	r3, -0x7690(r13)
    stw	r30, 8(r3)
_80070884:
    lwz	r4, -0x7690(r13)
    li	r0, 0
    lwz	r3, 8(r4)
    stw	r3, 0(r4)
    lwz	r3, -0x7690(r13)
    stw	r0, 0xc(r3)
    lwz	r3, -0x7690(r13)
    stw	r0, 0x10(r3)
    bl      fn_80071D30
    lwz	r5, -0x76cc(r13)
    lis	r3, 0x4330
    lfs	f1, -0x7a30(r2)
    lhz	r4, 4(r5)
    lhz	r0, 6(r5)
    fmr	f2, f1
    stw	r4, 0x14(r1)
    fmr	f5, f1
    lfd	f4, -0x7a28(r2)
    stw	r3, 0x10(r1)
    lfs	f6, -0x7a2c(r2)
    lfd	f0, 0x10(r1)
    stw	r0, 0x1c(r1)
    fsubs	f3, f0, f4
    stw	r3, 0x18(r1)
    lfd	f0, 0x18(r1)
    fsubs	f4, f0, f4
    bl      fn_80038EEC
    lwz	r6, -0x76cc(r13)
    li	r3, 0
    li	r4, 0
    lhz	r5, 4(r6)
    lhz	r6, 6(r6)
    bl      fn_80074188
    lwz	r6, -0x76cc(r13)
    li	r3, 0
    li	r4, 0
    lhz	r5, 4(r6)
    lhz	r6, 6(r6)
    bl      fn_8007423C
    lwz	r4, -0x76cc(r13)
    lhz	r3, 4(r4)
    lhz	r4, 8(r4)
    bl      fn_800743C4
    lwz	r5, -0x76cc(r13)
    lis	r3, 0x4330
    stw	r3, 0x20(r1)
    lhz	r4, 8(r5)
    lhz	r0, 6(r5)
    stw	r4, 0x24(r1)
    lfd	f2, -0x7a28(r2)
    lfd	f0, 0x20(r1)
    stw	r0, 0x2c(r1)
    fsubs	f1, f0, f2
    stw	r3, 0x28(r1)
    lfd	f0, 0x28(r1)
    fsubs	f0, f0, f2
    fdivs	f1, f1, f0
    bl      fn_80034D9C
    lwz	r6, -0x76cc(r13)
    li	r5, 1
    lbz	r3, 0x19(r6)
    addi	r4, r6, 0x1a
    addi	r6, r6, 0x32
    bl      GXSetCopyClear
    cmpwi	r29, 0
    beq	_800709b0
    li	r3, 1
    li	r4, 0
    bl      fn_80037C2C
    li	r3, 1
    bl      fn_80037D14
    li	r3, 1
    li	r4, 0
    bl      GXWriteLightAttn
    b	_800709c4
_800709b0:
    li	r3, 0
    li	r4, 0
    bl      fn_80037C2C
    li	r3, 0
    bl      fn_80037D14
_800709c4:
    lwz	r0, -0x7528(r2)
    lis	r4, 0x100
    addi	r3, r1, 8
    stw	r0, 8(r1)
    addi	r4, r4, -1
    bl      ModelMatchCachedSlot_B20
    lwz	r3, -0x7690(r13)
    li	r4, 1
    lwz	r3, 4(r3)
    bl      fn_80035110
    lwz	r3, -0x7690(r13)
    li	r4, 0
    lwz	r3, 8(r3)
    bl      fn_80035110
    lwz	r3, -0x7690(r13)
    li	r4, 0
    lwz	r3, 4(r3)
    bl      fn_80035110
    li	r3, 0
    bl      fn_800350F4
    lwz	r3, -0x76cc(r13)
    bl      fn_8001B42C
    mr	r3, r31
    bl      fn_8001BD84
    bl      fn_8001BC54
    bl      VIWaitForRetrace
    lwz	r3, -0x76cc(r13)
    lwz	r0, 0(r3)
    clrlwi.	r0, r0, 0x1f
    beq	_80070a40
    bl      VIWaitForRetrace
_80070a40:
    addi	r11, r1, 0x50
    bl      _restgpr_25
    lwz	r0, 0x54(r1)
    mtlr	r0
    addi	r1, r1, 0x50
    blr	
}

#pragma pop
