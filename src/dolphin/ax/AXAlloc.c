#pragma push
#pragma force_active on

typedef signed int s32;
typedef unsigned int u32;
typedef int BOOL;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern void fn_80022E68(register void* p);
extern unsigned char __AXStackHead[128];
extern unsigned char __AXStackTail[128];

extern unsigned char lbl_801A6AB8[8];
asm void __AXPushFreeStack(register void* p)
{
    nofralloc
    lis     r4, __AXStackHead@ha
    addi	r5, r4, __AXStackHead@l
    lwz	r4, 0(r5)
    li	r0, 0
    stw	r4, 0(r3)
    stw	r3, 0(r5)
    stw	r0, 0xc(r3)
    blr	
}

asm void __AXPushCallbackStack(register void* p)
{
    nofralloc
    lwz	r0, lbl_801A6AB8
    stw	r0, 8(r3)
    stw	r3, lbl_801A6AB8
    blr	
}

asm void* __AXPopCallbackStack(void)
{
    nofralloc
    lwz	r0, lbl_801A6AB8
    cmplwi	r0, 0
    mr	r3, r0
    beqlr	
    lwz	r0, 8(r3)
    stw	r0, lbl_801A6AB8
    blr	
}

asm void __AXRemoveFromStack(register void* p)
{
    nofralloc
    lwz	r0, 0xc(r3)
    lis     r5, __AXStackHead@ha
    lis     r4, __AXStackTail@ha
    slwi	r6, r0, 2
    addi	r5, r5, __AXStackHead@l
    addi	r0, r4, __AXStackTail@l
    add	r7, r5, r6
    add	r5, r0, r6
    lwz	r4, 0(r7)
    lwz	r0, 0(r5)
    cmplw	r4, r0
    bne     _80020a68
    li	r0, 0
    stw	r0, 0(r5)
    stw	r0, 0(r7)
    blr	
_80020a68:
    cmplw	r3, r4
    bne     _80020a88
    lwz	r3, 0(r3)
    li	r0, 0
    stw	r3, 0(r7)
    lwz	r3, 0(r7)
    stw	r0, 4(r3)
    blr	
_80020a88:
    cmplw	r3, r0
    bne     _80020aa8
    lwz	r3, 4(r3)
    li	r0, 0
    stw	r3, 0(r5)
    lwz	r3, 0(r5)
    stw	r0, 0(r3)
    blr	
_80020aa8:
    lwz	r4, 4(r3)
    lwz	r3, 0(r3)
    stw	r3, 0(r4)
    stw	r4, 4(r3)
    blr	
}

asm void AXFreeVoice(register void* p)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    addi	r31, r3, 0
    addi	r3, r30, 0
    bl      __AXRemoveFromStack
    lhz	r0, 0x146(r30)
    cmplwi	r0, 1
    bne     _80020af8
    li	r0, 1
    stw	r0, 0x20(r30)
_80020af8:
    mr	r3, r30
    bl      fn_80022E68
    lis     r3, __AXStackHead@ha
    addi	r5, r3, __AXStackHead@l
    lwz	r4, 0(r5)
    li	r0, 0
    addi	r3, r31, 0
    stw	r4, 0(r30)
    stw	r30, 0(r5)
    stw	r0, 0xc(r30)
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void* AXAcquireVoice(register u32 priority, register void* callback, register u32 userContext)
{
    nofralloc
    mflr	r0
    lis	r6, __AXStackHead@ha
    stw	r0, 4(r1)
    stwu	r1, -0x38(r1)
    stmw	r26, 0x20(r1)
    addi	r28, r3, 0
    addi	r29, r4, 0
    addi	r30, r5, 0
    addi	r27, r6, __AXStackHead@l
    bl      OSDisableInterrupts
    lwz	r4, 0(r27)
    addi	r31, r3, 0
    cmplwi	r4, 0
    beq     _80020b7c
    lwz	r0, 0(r4)
    stw	r0, 0(r27)
_80020b7c:
    cmplwi	r4, 0
    addi	r26, r4, 0
    bne     _80020c38
    addi	r0, r28, -1
    cmplwi	r28, 1
    mtctr	r0
    addi	r5, r27, 4
    addi	r6, r27, 0x84
    ble     _80020c38
_80020ba0:
    lwz	r3, 0(r5)
    li	r4, 0
    cmplwi	r3, 0
    beq     _80020bf0
    lwz	r7, 0(r6)
    cmplw	r3, r7
    bne     _80020bd0
    li	r0, 0
    stw	r0, 0(r6)
    mr	r4, r3
    stw	r0, 0(r5)
    b       _80020bf0
_80020bd0:
    cmplwi	r7, 0
    beq     _80020bf0
    lwz	r3, 4(r7)
    li	r0, 0
    addi	r4, r7, 0
    stw	r3, 0(r6)
    lwz	r3, 0(r6)
    stw	r0, 0(r3)
_80020bf0:
    cmplwi	r4, 0
    addi	r26, r4, 0
    beq     _80020c2c
    lhz	r0, 0x146(r4)
    cmplwi	r0, 1
    bne     _80020c10
    li	r0, 1
    stw	r0, 0x20(r4)
_80020c10:
    lwz	r12, 0x10(r4)
    cmplwi	r12, 0
    beq     _80020c38
    mtlr	r12
    addi	r3, r26, 0
    blrl	
    b       _80020c38
_80020c2c:
    addi	r5, r5, 4
    addi	r6, r6, 4
    bdnz    _80020ba0
_80020c38:
    cmplwi	r26, 0
    beq     _80020c90
    slwi	r0, r28, 2
    add	r4, r27, r0
    lwz	r3, 0(r4)
    li	r0, 0
    stw	r3, 0(r26)
    stw	r0, 4(r26)
    lwz	r0, 0(r26)
    cmplwi	r0, 0
    beq     _80020c74
    lwz	r3, 0(r4)
    stw	r26, 4(r3)
    stw	r26, 0(r4)
    b       _80020c7c
_80020c74:
    stw	r26, 0x80(r4)
    stw	r26, 0(r4)
_80020c7c:
    stw	r28, 0xc(r26)
    mr	r3, r26
    stw	r29, 0x10(r26)
    stw	r30, 0x14(r26)
    bl      fn_80022E68
_80020c90:
    mr	r3, r31
    bl      OSRestoreInterrupts
    mr	r3, r26
    lmw	r26, 0x20(r1)
    lwz	r0, 0x3c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

asm void AXSetVoicePriority(register void* p, register u32 priority)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    addi	r30, r4, 0
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    bl      OSDisableInterrupts
    addi	r31, r3, 0
    addi	r3, r29, 0
    bl      __AXRemoveFromStack
    lis     r3, __AXStackHead@ha
    slwi	r5, r30, 2
    addi	r0, r3, __AXStackHead@l
    add	r4, r0, r5
    lwz	r3, 0(r4)
    li	r0, 0
    stw	r3, 0(r29)
    stw	r0, 4(r29)
    lwz	r0, 0(r29)
    cmplwi	r0, 0
    beq     _80020d1c
    lwz	r3, 0(r4)
    stw	r29, 4(r3)
    stw	r29, 0(r4)
    b       _80020d30
_80020d1c:
    lis     r3, __AXStackTail@ha
    addi	r0, r3, __AXStackTail@l
    add	r3, r0, r5
    stw	r29, 0(r3)
    stw	r29, 0(r4)
_80020d30:
    stw	r30, 0xc(r29)
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

#pragma pop
