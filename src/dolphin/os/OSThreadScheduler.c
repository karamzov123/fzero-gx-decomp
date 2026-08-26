#pragma push
#pragma force_active on

extern int OSDisableInterrupts(void);
extern void OSEnableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern void OSSetCurrentContext(register void* context);
extern void OSLoadContext(register void* context);
extern void OSClearContext(register void* context);
extern void OSGetCurrentContext(void);
extern int OSSaveContext(register void* context);
extern void OSSwitchFiber(register void* context, register void* pc, register void* sp);
extern void __OSUnlockAllMutex(register void* thread);
extern void OSWakeupThread(register void* queue);
extern unsigned char __OSErrorTable[68];
extern unsigned char RunQueue_8015C018[];
extern unsigned char Reschedule[4];
extern unsigned char SwitchThreadCallback_801A6440[4];
extern unsigned char RunQueueHint_801A67FC[4];
extern unsigned char RunQueueBits[4];
extern unsigned char lbl_801A6430[4];
// provenance: original
void OSExitThread(void* val);

// provenance: original
void UnsetRun(register void* thread)
{
    asm
    {
    lwz     r4, 0x2e0(r3)
    lwz     r5, 0x2dc(r3)
    cmplwi  r4, 0
    lwz     r6, 0x2e4(r3)
    bne     L_80010388
    stw     r6, 4(r5)
    b       L_8001038c
L_80010388:
    stw     r6, 0x2e4(r4)
L_8001038c:
    cmplwi  r6, 0
    bne     L_8001039c
    stw     r4, 0(r5)
    b       L_800103a0
L_8001039c:
    stw     r4, 0x2e0(r6)
L_800103a0:
    lwz     r0, 0(r5)
    cmplwi  r0, 0
    bne     L_800103c8
    lwz     r0, 0x2d0(r3)
    li      r4, 1
    lwz     r5, RunQueueBits
    subfic  r0, r0, 31
    slw     r0, r4, r0
    andc    r0, r5, r0
    stw     r0, RunQueueBits
L_800103c8:
    li      r0, 0
    stw     r0, 0x2dc(r3)
    }
}

// provenance: original
int __OSGetEffectivePriority(register void* thread)
{
    register int ret;

    asm
    {
    lwz     r4, 0x2d4(r3)
    lwz     r5, 0x2f4(r3)
    b       L_80010400
L_800103e0:
    lwz     r3, 0(r5)
    cmplwi  r3, 0
    beq     L_800103fc
    lwz     r0, 0x2d0(r3)
    cmpw    r0, r4
    bge     L_800103fc
    mr      r4, r0
L_800103fc:
    lwz     r5, 16(r5)
L_80010400:
    cmplwi  r5, 0
    bne     L_800103e0
    mr      ret, r4
    }
    return ret;
}

asm void* SetEffectivePriority(register void* thread, register int priority)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    stw	r30, 0x10(r1)
    addi	r30, r4, 0
    lhz	r0, 0x2c8(r3)
    cmpwi	r0, 3
    beq     _800105b4
    bge     _8001044c
    cmpwi	r0, 1
    beq     _80010458
    bge     _800105a8
    b       _800105b4
_8001044c:
    cmpwi	r0, 5
    bge     _800105b4
    b       _800104d0
_80010458:
    mr	r3, r31
    bl      UnsetRun
    stw	r30, 0x2d0(r31)
    lis     r3, RunQueue_8015C018@ha
    addi	r0, r3, RunQueue_8015C018@l
    lwz	r3, 0x2d0(r31)
    slwi	r3, r3, 3
    add	r0, r0, r3
    stw	r0, 0x2dc(r31)
    lwz	r4, 0x2dc(r31)
    lwz	r3, 4(r4)
    cmplwi	r3, 0
    bne     _80010494
    stw	r31, 0(r4)
    b       _80010498
_80010494:
    stw	r31, 0x2e0(r3)
_80010498:
    stw	r3, 0x2e4(r31)
    li	r0, 0
    li	r3, 1
    stw	r0, 0x2e0(r31)
    lwz	r4, 0x2dc(r31)
    stw	r31, 4(r4)
    lwz	r0, 0x2d0(r31)
    lwz	r4, RunQueueBits
    subfic	r0, r0, 0x1f
    slw	r0, r3, r0
    or	r0, r4, r0
    stw	r0, RunQueueBits
    stw r3, RunQueueHint_801A67FC
    b       _800105b4
_800104d0:
    lwz	r4, 0x2e0(r31)
    lwz	r5, 0x2e4(r31)
    cmplwi	r4, 0
    bne     _800104ec
    lwz	r3, 0x2dc(r31)
    stw	r5, 4(r3)
    b       _800104f0
_800104ec:
    stw	r5, 0x2e4(r4)
_800104f0:
    cmplwi	r5, 0
    bne     _80010504
    lwz	r3, 0x2dc(r31)
    stw	r4, 0(r3)
    b       _80010508
_80010504:
    stw	r4, 0x2e0(r5)
_80010508:
    stw	r30, 0x2d0(r31)
    lwz	r4, 0x2dc(r31)
    lwz	r5, 0(r4)
    b       _8001051c
_80010518:
    lwz	r5, 0x2e0(r5)
_8001051c:
    cmplwi	r5, 0
    beq     _80010534
    lwz	r3, 0x2d0(r5)
    lwz	r0, 0x2d0(r31)
    cmpw	r3, r0
    ble     _80010518
_80010534:
    cmplwi	r5, 0
    bne     _8001056c
    lwz	r3, 4(r4)
    cmplwi	r3, 0
    bne     _80010550
    stw	r31, 0(r4)
    b       _80010554
_80010550:
    stw	r31, 0x2e0(r3)
_80010554:
    stw	r3, 0x2e4(r31)
    li	r0, 0
    stw	r0, 0x2e0(r31)
    lwz	r3, 0x2dc(r31)
    stw	r31, 4(r3)
    b       _80010594
_8001056c:
    stw	r5, 0x2e0(r31)
    lwz	r3, 0x2e4(r5)
    stw	r31, 0x2e4(r5)
    cmplwi	r3, 0
    stw	r3, 0x2e4(r31)
    bne     _80010590
    lwz	r3, 0x2dc(r31)
    stw	r31, 0(r3)
    b       _80010594
_80010590:
    stw	r31, 0x2e0(r3)
_80010594:
    lwz	r3, 0x2f0(r31)
    cmplwi	r3, 0
    beq     _800105b4
    lwz	r3, 8(r3)
    b       _800105b8
_800105a8:
    li	r0, 1
    stw r0, RunQueueHint_801A67FC
    stw	r30, 0x2d0(r31)
_800105b4:
    li	r3, 0
_800105b8:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void* SelectThread(register int yield)
{
    nofralloc
    mflr	r0
    lis     r4, RunQueue_8015C018@ha
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    addi	r31, r4, RunQueue_8015C018@l
    stw	r30, 0x10(r1)
    addi	r30, r3, 0
    lwz	r0, Reschedule
    cmpwi	r0, 0
    ble     _80010604
    li	r3, 0
    b       _800107e0
_80010604:
    bl      OSGetCurrentContext
    lis	r4, -0x8000
    lwz	r6, 0xe4(r4)
    cmplw	r3, r6
    addi	r3, r6, 0
    beq     _80010624
    li	r3, 0
    b       _800107e0
_80010624:
    cmplwi	r6, 0
    beq     _800106e4
    lhz	r0, 0x2c8(r6)
    cmplwi	r0, 2
    bne     _800106c4
    cmpwi	r30, 0
    bne     _8001065c
    lwz	r4, RunQueueBits
    lwz	r0, 0x2d0(r6)
    cntlzw	r4, r4
    cmpw	r0, r4
    bgt     _8001065c
    li	r3, 0
    b       _800107e0
_8001065c:
    li	r0, 1
    sth	r0, 0x2c8(r6)
    lwz	r0, 0x2d0(r6)
    slwi	r0, r0, 3
    add	r0, r31, r0
    stw	r0, 0x2dc(r6)
    lwz	r5, 0x2dc(r6)
    lwz	r4, 4(r5)
    cmplwi	r4, 0
    bne     _8001068c
    stw	r6, 0(r5)
    b       _80010690
_8001068c:
    stw	r6, 0x2e0(r4)
_80010690:
    stw	r4, 0x2e4(r6)
    li	r0, 0
    li	r4, 1
    stw	r0, 0x2e0(r6)
    lwz	r5, 0x2dc(r6)
    stw	r6, 4(r5)
    lwz	r0, 0x2d0(r6)
    lwz	r5, RunQueueBits
    subfic	r0, r0, 0x1f
    slw	r0, r4, r0
    or	r0, r5, r0
    stw	r0, RunQueueBits
    stw r4, RunQueueHint_801A67FC
_800106c4:
    lhz	r0, 0x1a2(r6)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bne     _800106e4
    bl      OSSaveContext
    cmplwi	r3, 0
    beq     _800106e4
    li	r3, 0
    b       _800107e0
_800106e4:
    lwz	r0, RunQueueBits
    cmplwi	r0, 0
    bne     _80010740
    lwz r12, SwitchThreadCallback_801A6440
    lis	r30, -0x8000
    lwz	r3, 0xe4(r30)
    li	r4, 0
    mtlr	r12
    blrl	
    li	r0, 0
    stw	r0, 0xe4(r30)
    addi	r3, r31, 0x730
    bl      OSSetCurrentContext
_80010718:
    bl      OSEnableInterrupts
_8001071c:
    lwz	r0, RunQueueBits
    cmplwi	r0, 0
    beq     _8001071c
    bl      OSDisableInterrupts
    lwz	r0, RunQueueBits
    cmplwi	r0, 0
    beq     _80010718
    addi	r3, r31, 0x730
    bl      OSClearContext
_80010740:
    li	r3, 0
    stw r3, RunQueueHint_801A67FC
    lwz	r0, RunQueueBits
    cntlzw	r7, r0
    slwi	r0, r7, 3
    add	r4, r31, r0
    lwz	r5, 0(r4)
    lwz	r6, 0x2e0(r5)
    addi	r30, r5, 0
    cmplwi	r6, 0
    bne     _80010774
    stw	r3, 4(r4)
    b       _80010778
_80010774:
    stw	r3, 0x2e4(r6)
_80010778:
    stw	r6, 0(r4)
    lwz	r0, 0(r4)
    cmplwi	r0, 0
    bne     _800107a0
    subfic	r0, r7, 0x1f
    lwz	r4, RunQueueBits
    li	r3, 1
    slw	r0, r3, r0
    andc	r0, r4, r0
    stw	r0, RunQueueBits
_800107a0:
    li	r0, 0
    stw	r0, 0x2dc(r30)
    li	r0, 2
    lis	r31, -0x8000
    sth	r0, 0x2c8(r30)
    mr	r4, r30
    lwz r12, SwitchThreadCallback_801A6440
    lwz	r3, 0xe4(r31)
    mtlr	r12
    blrl	
    stw	r30, 0xe4(r31)
    mr	r3, r30
    bl      OSSetCurrentContext
    mr	r3, r30
    bl      OSLoadContext
    mr	r3, r30
_800107e0:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void __OSReschedule(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    lwz r0, RunQueueHint_801A67FC
    cmpwi	r0, 0
    beq     _80010818
    li	r3, 0
    bl      SelectThread
_80010818:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm int OSCreateThread(register void* thread, register void* func, register void* param, register void* stack, register unsigned long stackSize, register int priority, register unsigned short attr)
{
    nofralloc
    mflr	r0
    cmpwi	r8, 0
    stw	r0, 4(r1)
    stwu	r1, -0x50(r1)
    stmw	r27, 0x3c(r1)
    addi	r31, r3, 0
    addi	r27, r5, 0
    addi	r28, r6, 0
    addi	r29, r7, 0
    blt     _80010858
    cmpwi	r8, 0x1f
    ble     _80010860
_80010858:
    li	r3, 0
    b       _800109fc
_80010860:
    li	r6, 1
    sth	r6, 0x2c8(r31)
    clrlwi	r0, r9, 0x1f
    rlwinm	r7, r28, 0, 0, 0x1c
    sth	r0, 0x2ca(r31)
    li	r0, -1
    li	r30, 0
    stw	r8, 0x2d4(r31)
    addi	r3, r31, 0
    addi	r5, r7, -8
    stw	r8, 0x2d0(r31)
    stw	r6, 0x2cc(r31)
    stw	r0, 0x2d8(r31)
    stw	r30, 0x2f0(r31)
    stw	r30, 0x2ec(r31)
    stw	r30, 0x2e8(r31)
    stw	r30, 0x2f8(r31)
    stw	r30, 0x2f4(r31)
    stw	r30, -8(r7)
    stw	r30, -4(r7)
    bl      OSSwitchFiber
    lis     r3, OSExitThread@ha
    addi	r0, r3, OSExitThread@l
    stw	r0, 0x84(r31)
    lis	r3, -0x2152
    subf	r4, r29, r28
    stw	r27, 0xc(r31)
    addi	r0, r3, -0x4542
    stw	r28, 0x304(r31)
    stw	r4, 0x308(r31)
    lwz	r3, 0x308(r31)
    stw	r0, 0(r3)
    stw	r30, 0x30c(r31)
    stw	r30, 0x310(r31)
    stw	r30, 0x314(r31)
    bl      OSDisableInterrupts
    lis     r4, __OSErrorTable@ha
    addi	r4, r4, __OSErrorTable@l
    lwz	r0, 0x40(r4)
    cmplwi	r0, 0
    beq     _800109c4
    lwz	r4, 0x19c(r31)
    li	r0, 4
    mtctr	r0
    addi	r5, r31, 0
    ori	r0, r4, 0x900
    stw	r0, 0x19c(r31)
    lhz	r0, 0x1a2(r31)
    ori	r0, r0, 1
    sth	r0, 0x1a2(r31)
    lwz	r0, lbl_801A6430
    rlwinm	r0, r0, 0, 0x18, 0x1c
    ori	r0, r0, 4
    stw	r0, 0x194(r31)
_80010938:
    li	r0, -1
    stw	r0, 0x94(r5)
    stw	r0, 0x90(r5)
    stw	r0, 0x1cc(r5)
    stw	r0, 0x1c8(r5)
    stw	r0, 0x9c(r5)
    stw	r0, 0x98(r5)
    stw	r0, 0x1d4(r5)
    stw	r0, 0x1d0(r5)
    stw	r0, 0xa4(r5)
    stw	r0, 0xa0(r5)
    stw	r0, 0x1dc(r5)
    stw	r0, 0x1d8(r5)
    stw	r0, 0xac(r5)
    stw	r0, 0xa8(r5)
    stw	r0, 0x1e4(r5)
    stw	r0, 0x1e0(r5)
    stw	r0, 0xb4(r5)
    stw	r0, 0xb0(r5)
    stw	r0, 0x1ec(r5)
    stw	r0, 0x1e8(r5)
    stw	r0, 0xbc(r5)
    stw	r0, 0xb8(r5)
    stw	r0, 0x1f4(r5)
    stw	r0, 0x1f0(r5)
    stw	r0, 0xc4(r5)
    stw	r0, 0xc0(r5)
    stw	r0, 0x1fc(r5)
    stw	r0, 0x1f8(r5)
    stw	r0, 0xcc(r5)
    stw	r0, 0xc8(r5)
    stw	r0, 0x204(r5)
    stw	r0, 0x200(r5)
    addi	r5, r5, 0x40
    bdnz    _80010938
_800109c4:
    lis	r4, -0x8000
    addi	r5, r4, 0xdc
    lwzu	r6, 4(r5)
    cmplwi	r6, 0
    bne     _800109e0
    stw	r31, 0xdc(r4)
    b       _800109e4
_800109e0:
    stw	r31, 0x2fc(r6)
_800109e4:
    stw	r6, 0x300(r31)
    li	r0, 0
    stw	r0, 0x2fc(r31)
    stw	r31, 0(r5)
    bl      OSRestoreInterrupts
    li	r3, 1
_800109fc:
    lmw	r27, 0x3c(r1)
    lwz	r0, 0x54(r1)
    addi	r1, r1, 0x50
    mtlr	r0
    blr	
}

asm void OSExitThread(register void* val)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    mr	r28, r3
    bl      OSDisableInterrupts
    lis	r31, -0x8000
    lwz	r30, 0xe4(r31)
    addi	r29, r3, 0
    addi	r3, r30, 0
    bl      OSClearContext
    lhz	r0, 0x2ca(r30)
    clrlwi.	r0, r0, 0x1f
    beq     _80010a94
    lwz	r4, 0x2fc(r30)
    lwz	r5, 0x300(r30)
    cmplwi	r4, 0
    bne     _80010a6c
    stw	r5, 0xe0(r31)
    b       _80010a70
_80010a6c:
    stw	r5, 0x300(r4)
_80010a70:
    cmplwi	r5, 0
    bne     _80010a84
    lis	r3, -0x8000
    stw	r4, 0xdc(r3)
    b       _80010a88
_80010a84:
    stw	r4, 0x2fc(r5)
_80010a88:
    li	r0, 0
    sth	r0, 0x2c8(r30)
    b       _80010aa0
_80010a94:
    li	r0, 8
    sth	r0, 0x2c8(r30)
    stw	r28, 0x2d8(r30)
_80010aa0:
    mr	r3, r30
    bl      __OSUnlockAllMutex
    addi	r3, r30, 0x2e8
    bl      OSWakeupThread
    li	r0, 1
    stw r0, RunQueueHint_801A67FC
    lwz r0, RunQueueHint_801A67FC
    cmpwi	r0, 0
    beq     _80010acc
    li	r3, 0
    bl      SelectThread
_80010acc:
    mr	r3, r29
    bl      OSRestoreInterrupts
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void OSCancelThread(register void* thread)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r29, 0x14(r1)
    bl      OSDisableInterrupts
    lhz	r0, 0x2c8(r30)
    addi	r31, r3, 0
    cmpwi	r0, 3
    beq     _80010bfc
    bge     _80010b38
    cmpwi	r0, 1
    beq     _80010b44
    bge     _80010b5c
    b       _80010bfc
_80010b38:
    cmpwi	r0, 5
    bge     _80010bfc
    b       _80010b68
_80010b44:
    lwz	r0, 0x2cc(r30)
    cmpwi	r0, 0
    bgt     _80010c08
    mr	r3, r30
    bl      UnsetRun
    b       _80010c08
_80010b5c:
    li	r0, 1
    stw r0, RunQueueHint_801A67FC
    b       _80010c08
_80010b68:
    lwz	r4, 0x2e0(r30)
    lwz	r5, 0x2e4(r30)
    cmplwi	r4, 0
    bne     _80010b84
    lwz	r3, 0x2dc(r30)
    stw	r5, 4(r3)
    b       _80010b88
_80010b84:
    stw	r5, 0x2e4(r4)
_80010b88:
    cmplwi	r5, 0
    bne     _80010b9c
    lwz	r3, 0x2dc(r30)
    stw	r4, 0(r3)
    b       _80010ba0
_80010b9c:
    stw	r4, 0x2e0(r5)
_80010ba0:
    li	r0, 0
    stw	r0, 0x2dc(r30)
    lwz	r0, 0x2cc(r30)
    cmpwi	r0, 0
    bgt     _80010c08
    lwz	r3, 0x2f0(r30)
    cmplwi	r3, 0
    beq     _80010c08
    lwz	r29, 8(r3)
_80010bc4:
    lwz	r0, 0x2cc(r29)
    cmpwi	r0, 0
    bgt     _80010c08
    mr	r3, r29
    bl      __OSGetEffectivePriority
    lwz	r0, 0x2d0(r29)
    addi	r4, r3, 0
    cmpw	r0, r4
    beq     _80010c08
    mr	r3, r29
    bl      SetEffectivePriority
    or.	r29, r3, r3
    bne     _80010bc4
    b       _80010c08
_80010bfc:
    mr	r3, r31
    bl      OSRestoreInterrupts
    b       _80010c94
_80010c08:
    mr	r3, r30
    bl      OSClearContext
    lhz	r0, 0x2ca(r30)
    clrlwi.	r0, r0, 0x1f
    beq     _80010c60
    lwz	r4, 0x2fc(r30)
    lwz	r5, 0x300(r30)
    cmplwi	r4, 0
    bne     _80010c38
    lis	r3, -0x8000
    stw	r5, 0xe0(r3)
    b       _80010c3c
_80010c38:
    stw	r5, 0x300(r4)
_80010c3c:
    cmplwi	r5, 0
    bne     _80010c50
    lis	r3, -0x8000
    stw	r4, 0xdc(r3)
    b       _80010c54
_80010c50:
    stw	r4, 0x2fc(r5)
_80010c54:
    li	r0, 0
    sth	r0, 0x2c8(r30)
    b       _80010c68
_80010c60:
    li	r0, 8
    sth	r0, 0x2c8(r30)
_80010c68:
    mr	r3, r30
    bl      __OSUnlockAllMutex
    addi	r3, r30, 0x2e8
    bl      OSWakeupThread
    lwz r0, RunQueueHint_801A67FC
    cmpwi	r0, 0
    beq     _80010c8c
    li	r3, 0
    bl      SelectThread
_80010c8c:
    mr	r3, r31
    bl      OSRestoreInterrupts
_80010c94:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm long OSResumeThread(register void* thread)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    stw	r29, 0x1c(r1)
    mr	r29, r3
    bl      OSDisableInterrupts
    lwz	r4, 0x2cc(r29)
    addi	r31, r3, 0
    addi	r0, r4, -1
    stw	r0, 0x2cc(r29)
    mr	r30, r4
    lwz	r0, 0x2cc(r29)
    cmpwi	r0, 0
    bge     _80010cfc
    li	r0, 0
    stw	r0, 0x2cc(r29)
    b       _80010f10
_80010cfc:
    bne     _80010f10
    lhz	r0, 0x2c8(r29)
    cmpwi	r0, 4
    beq     _80010dc0
    bge     _80010efc
    cmpwi	r0, 1
    beq     _80010d1c
    b       _80010efc
_80010d1c:
    lwz	r0, 0x2d4(r29)
    lwz	r3, 0x2f4(r29)
    b       _80010d48
_80010d28:
    lwz	r4, 0(r3)
    cmplwi	r4, 0
    beq     _80010d44
    lwz	r4, 0x2d0(r4)
    cmpw	r4, r0
    bge     _80010d44
    mr	r0, r4
_80010d44:
    lwz	r3, 0x10(r3)
_80010d48:
    cmplwi	r3, 0
    bne     _80010d28
    stw	r0, 0x2d0(r29)
    lis     r3, RunQueue_8015C018@ha
    addi	r0, r3, RunQueue_8015C018@l
    lwz	r3, 0x2d0(r29)
    slwi	r3, r3, 3
    add	r0, r0, r3
    stw	r0, 0x2dc(r29)
    lwz	r4, 0x2dc(r29)
    lwz	r3, 4(r4)
    cmplwi	r3, 0
    bne     _80010d84
    stw	r29, 0(r4)
    b       _80010d88
_80010d84:
    stw	r29, 0x2e0(r3)
_80010d88:
    stw	r3, 0x2e4(r29)
    li	r0, 0
    li	r3, 1
    stw	r0, 0x2e0(r29)
    lwz	r4, 0x2dc(r29)
    stw	r29, 4(r4)
    lwz	r0, 0x2d0(r29)
    lwz	r4, RunQueueBits
    subfic	r0, r0, 0x1f
    slw	r0, r3, r0
    or	r0, r4, r0
    stw	r0, RunQueueBits
    stw r3, RunQueueHint_801A67FC
    b       _80010efc
_80010dc0:
    lwz	r4, 0x2e0(r29)
    lwz	r5, 0x2e4(r29)
    cmplwi	r4, 0
    bne     _80010ddc
    lwz	r3, 0x2dc(r29)
    stw	r5, 4(r3)
    b       _80010de0
_80010ddc:
    stw	r5, 0x2e4(r4)
_80010de0:
    cmplwi	r5, 0
    bne     _80010df4
    lwz	r3, 0x2dc(r29)
    stw	r4, 0(r3)
    b       _80010df8
_80010df4:
    stw	r4, 0x2e0(r5)
_80010df8:
    lwz	r0, 0x2d4(r29)
    lwz	r3, 0x2f4(r29)
    b       _80010e24
_80010e04:
    lwz	r4, 0(r3)
    cmplwi	r4, 0
    beq     _80010e20
    lwz	r4, 0x2d0(r4)
    cmpw	r4, r0
    bge     _80010e20
    mr	r0, r4
_80010e20:
    lwz	r3, 0x10(r3)
_80010e24:
    cmplwi	r3, 0
    bne     _80010e04
    stw	r0, 0x2d0(r29)
    lwz	r4, 0x2dc(r29)
    lwz	r5, 0(r4)
    b       _80010e40
_80010e3c:
    lwz	r5, 0x2e0(r5)
_80010e40:
    cmplwi	r5, 0
    beq     _80010e58
    lwz	r3, 0x2d0(r5)
    lwz	r0, 0x2d0(r29)
    cmpw	r3, r0
    ble     _80010e3c
_80010e58:
    cmplwi	r5, 0
    bne     _80010e90
    lwz	r3, 4(r4)
    cmplwi	r3, 0
    bne     _80010e74
    stw	r29, 0(r4)
    b       _80010e78
_80010e74:
    stw	r29, 0x2e0(r3)
_80010e78:
    stw	r3, 0x2e4(r29)
    li	r0, 0
    stw	r0, 0x2e0(r29)
    lwz	r3, 0x2dc(r29)
    stw	r29, 4(r3)
    b       _80010eb8
_80010e90:
    stw	r5, 0x2e0(r29)
    lwz	r3, 0x2e4(r5)
    stw	r29, 0x2e4(r5)
    cmplwi	r3, 0
    stw	r3, 0x2e4(r29)
    bne     _80010eb4
    lwz	r3, 0x2dc(r29)
    stw	r29, 0(r3)
    b       _80010eb8
_80010eb4:
    stw	r29, 0x2e0(r3)
_80010eb8:
    lwz	r3, 0x2f0(r29)
    cmplwi	r3, 0
    beq     _80010efc
    lwz	r29, 8(r3)
_80010ec8:
    lwz	r0, 0x2cc(r29)
    cmpwi	r0, 0
    bgt     _80010efc
    mr	r3, r29
    bl      __OSGetEffectivePriority
    lwz	r0, 0x2d0(r29)
    addi	r4, r3, 0
    cmpw	r0, r4
    beq     _80010efc
    mr	r3, r29
    bl      SetEffectivePriority
    or.	r29, r3, r3
    bne     _80010ec8
_80010efc:
    lwz r0, RunQueueHint_801A67FC
    cmpwi	r0, 0
    beq     _80010f10
    li	r3, 0
    bl      SelectThread
_80010f10:
    mr	r3, r31
    bl      OSRestoreInterrupts
    mr	r3, r30
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm long OSSuspendThread(register void* thread)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r29, r3
    bl      OSDisableInterrupts
    lwz	r4, 0x2cc(r29)
    addi	r31, r3, 0
    addi	r0, r4, 1
    or.	r30, r4, r4
    stw	r0, 0x2cc(r29)
    bne     _80011080
    lhz	r0, 0x2c8(r29)
    cmpwi	r0, 3
    beq     _8001106c
    bge     _80010f90
    cmpwi	r0, 1
    beq     _80010fac
    bge     _80010f9c
    b       _8001106c
_80010f90:
    cmpwi	r0, 5
    bge     _8001106c
    b       _80010fb8
_80010f9c:
    li	r0, 1
    stw r0, RunQueueHint_801A67FC
    sth	r0, 0x2c8(r29)
    b       _8001106c
_80010fac:
    mr	r3, r29
    bl      UnsetRun
    b       _8001106c
_80010fb8:
    lwz	r4, 0x2e0(r29)
    lwz	r5, 0x2e4(r29)
    cmplwi	r4, 0
    bne     _80010fd4
    lwz	r3, 0x2dc(r29)
    stw	r5, 4(r3)
    b       _80010fd8
_80010fd4:
    stw	r5, 0x2e4(r4)
_80010fd8:
    cmplwi	r5, 0
    bne     _80010fec
    lwz	r3, 0x2dc(r29)
    stw	r4, 0(r3)
    b       _80010ff0
_80010fec:
    stw	r4, 0x2e0(r5)
_80010ff0:
    li	r0, 0x20
    stw	r0, 0x2d0(r29)
    lwz	r4, 0x2dc(r29)
    lwz	r3, 4(r4)
    cmplwi	r3, 0
    bne     _80011010
    stw	r29, 0(r4)
    b       _80011014
_80011010:
    stw	r29, 0x2e0(r3)
_80011014:
    stw	r3, 0x2e4(r29)
    li	r0, 0
    stw	r0, 0x2e0(r29)
    lwz	r3, 0x2dc(r29)
    stw	r29, 4(r3)
    lwz	r3, 0x2f0(r29)
    cmplwi	r3, 0
    beq     _8001106c
    lwz	r29, 8(r3)
_80011038:
    lwz	r0, 0x2cc(r29)
    cmpwi	r0, 0
    bgt     _8001106c
    mr	r3, r29
    bl      __OSGetEffectivePriority
    lwz	r0, 0x2d0(r29)
    addi	r4, r3, 0
    cmpw	r0, r4
    beq     _8001106c
    mr	r3, r29
    bl      SetEffectivePriority
    or.	r29, r3, r3
    bne     _80011038
_8001106c:
    lwz r0, RunQueueHint_801A67FC
    cmpwi	r0, 0
    beq     _80011080
    li	r3, 0
    bl      SelectThread
_80011080:
    mr	r3, r31
    bl      OSRestoreInterrupts
    mr	r3, r30
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void OSSleepThread(register void* queue)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    lis	r4, -0x8000
    lwz	r4, 0xe4(r4)
    li	r0, 4
    mr	r31, r3
    sth	r0, 0x2c8(r4)
    stw	r30, 0x2dc(r4)
    lwz	r5, 0(r30)
    b       _800110e8
_800110e4:
    lwz	r5, 0x2e0(r5)
_800110e8:
    cmplwi	r5, 0
    beq     _80011100
    lwz	r3, 0x2d0(r5)
    lwz	r0, 0x2d0(r4)
    cmpw	r3, r0
    ble     _800110e4
_80011100:
    cmplwi	r5, 0
    bne     _80011134
    lwz	r3, 4(r30)
    cmplwi	r3, 0
    bne     _8001111c
    stw	r4, 0(r30)
    b       _80011120
_8001111c:
    stw	r4, 0x2e0(r3)
_80011120:
    stw	r3, 0x2e4(r4)
    li	r0, 0
    stw	r0, 0x2e0(r4)
    stw	r4, 4(r30)
    b       _80011158
_80011134:
    stw	r5, 0x2e0(r4)
    lwz	r3, 0x2e4(r5)
    stw	r4, 0x2e4(r5)
    cmplwi	r3, 0
    stw	r3, 0x2e4(r4)
    bne     _80011154
    stw	r4, 0(r30)
    b       _80011158
_80011154:
    stw	r4, 0x2e0(r3)
_80011158:
    li	r0, 1
    stw r0, RunQueueHint_801A67FC
    lwz r0, RunQueueHint_801A67FC
    cmpwi	r0, 0
    beq     _80011174
    li	r3, 0
    bl      SelectThread
_80011174:
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void OSWakeupThread(register void* queue)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    lis     r4, RunQueue_8015C018@ha
    addi	r31, r3, 0
    addi	r5, r4, RunQueue_8015C018@l
    b       _80011258
_800111c0:
    lwz	r3, 0x2e0(r6)
    cmplwi	r3, 0
    bne     _800111d8
    li	r0, 0
    stw	r0, 4(r30)
    b       _800111e0
_800111d8:
    li	r0, 0
    stw	r0, 0x2e4(r3)
_800111e0:
    stw	r3, 0(r30)
    li	r0, 1
    sth	r0, 0x2c8(r6)
    lwz	r0, 0x2cc(r6)
    cmpwi	r0, 0
    bgt     _80011258
    lwz	r0, 0x2d0(r6)
    slwi	r0, r0, 3
    add	r0, r5, r0
    stw	r0, 0x2dc(r6)
    lwz	r4, 0x2dc(r6)
    lwz	r3, 4(r4)
    cmplwi	r3, 0
    bne     _80011220
    stw	r6, 0(r4)
    b       _80011224
_80011220:
    stw	r6, 0x2e0(r3)
_80011224:
    stw	r3, 0x2e4(r6)
    li	r0, 0
    li	r3, 1
    stw	r0, 0x2e0(r6)
    lwz	r4, 0x2dc(r6)
    stw	r6, 4(r4)
    lwz	r0, 0x2d0(r6)
    lwz	r4, RunQueueBits
    subfic	r0, r0, 0x1f
    slw	r0, r3, r0
    or	r0, r4, r0
    stw	r0, RunQueueBits
    stw r3, RunQueueHint_801A67FC
_80011258:
    lwz	r6, 0(r30)
    cmplwi	r6, 0
    bne     _800111c0
    lwz r0, RunQueueHint_801A67FC
    cmpwi	r0, 0
    beq     _80011278
    li	r3, 0
    bl      SelectThread
_80011278:
    mr	r3, r31
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm int OSSetThreadPriority(register void* thread, register int priority)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    or.	r31, r4, r4
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    addi	r29, r3, 0
    blt     _800112c4
    cmpwi	r31, 0x1f
    ble     _800112cc
_800112c4:
    li	r3, 0
    b       _8001133c
_800112cc:
    bl      OSDisableInterrupts
    lwz	r0, 0x2d4(r29)
    addi	r30, r3, 0
    cmpw	r0, r31
    beq     _80011330
    stw	r31, 0x2d4(r29)
    mr	r31, r29
_800112e8:
    lwz	r0, 0x2cc(r31)
    cmpwi	r0, 0
    bgt     _8001131c
    mr	r3, r31
    bl      __OSGetEffectivePriority
    lwz	r0, 0x2d0(r31)
    addi	r4, r3, 0
    cmpw	r0, r4
    beq     _8001131c
    mr	r3, r31
    bl      SetEffectivePriority
    or.	r31, r3, r3
    bne     _800112e8
_8001131c:
    lwz r0, RunQueueHint_801A67FC
    cmpwi	r0, 0
    beq     _80011330
    li	r3, 0
    bl      SelectThread
_80011330:
    mr	r3, r30
    bl      OSRestoreInterrupts
    li	r3, 1
_8001133c:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

#pragma pop
