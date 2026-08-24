#pragma push
#pragma force_active on
void fn_8008F8B0(void);
void fn_8008F8F0(void);

asm void OSDisableInterrupts(register void* a, register void* b, register void* c, register void* d);
asm void OSRestoreInterrupts(register void* a, register void* b, register void* c, register void* d);
asm void __OSSetInterruptHandler(register void* a, register void* b, register void* c, register void* d);
asm void __OSMaskInterrupts(register void* a, register void* b, register void* c, register void* d);
asm void __OSUnmaskInterrupts(register void* a, register void* b, register void* c, register void* d);
asm void UARTByteEngine(register void* a, register void* b, register void* c, register void* d);
asm void UART_WriteN_IntDriven(register void* a, register void* b, register void* c, register void* d);
asm void UARTWriteFrame(register void* a, register void* b, register void* c, register void* d);
asm void UART_ReadN_IntDriven(register void* a, register void* b, register void* c, register void* d);
asm void UARTReadFrame(register void* a, register void* b, register void* c, register void* d);

asm void fn_8008F44C(void)
{
    nofralloc
    blr	
}

asm void fn_8008F450(void)
{
    nofralloc
    blr	
}

asm void fn_8008F454(void)
{
    nofralloc
    blr	
}

asm void fn_8008F458(void)
{
    nofralloc
    blr	
}

asm void InitializeUART_IntDriven(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x78(r1)
    stmw	r24, 0x58(r1)
    addi	r26, r3, 0
    addi	r27, r4, 0
    bl      OSDisableInterrupts
    addi	r28, r3, 0
    lis	r25, -0x3400
    lis	r31, 0x4000
_8008f484:
    lwz	r0, 0x6828(r25)
    addi	r30, r25, 0x6800
    addi	r3, r1, 0x50
    andi.	r0, r0, 0x405
    li	r4, 2
    li	r5, 1
    ori	r0, r0, 0xc0
    stwu	r0, 0x28(r30)
    stw	r31, 0x50(r1)
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r24, r0, 5
_8008f4b4:
    addi	r29, r25, 0x6800
    lwzu	r0, 0x34(r29)
    clrlwi.	r0, r0, 0x1f
    bne     _8008f4b4
    addi	r3, r1, 0x54
    li	r4, 4
    li	r5, 0
    bl      UARTByteEngine
_8008f4d4:
    lwz	r0, 0(r29)
    clrlwi.	r0, r0, 0x1f
    bne     _8008f4d4
    lwz	r0, 0(r30)
    andi.	r0, r0, 0x405
    stw	r0, 0(r30)
    lwz	r0, 0x54(r1)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bne     _8008f484
    lbz	r3, -0x7d38(r13)
    addi	r0, r3, 1
    stb	r0, -0x7d38(r13)
    lbz	r0, -0x7d38(r13)
    clrlwi.	r0, r0, 0x1f
    beq     _8008f518
    li	r3, 0x1000
    b       _8008f51c
_8008f518:
    li	r3, 0
_8008f51c:
    addi	r0, r27, 3
    oris	r25, r3, 1
    rlwinm	r24, r0, 0, 0, 0x1d
    ori	r25, r25, 0xc000
_8008f52c:
    addi	r3, r25, 0
    addi	r4, r26, 0
    addi	r5, r24, 0
    bl      UART_WriteN_IntDriven
    cmpwi	r3, 0
    beq     _8008f52c
    lis	r31, 0x4000
_8008f548:
    lwz	r0, 0(r30)
    addi	r3, r1, 0x4c
    li	r4, 2
    andi.	r0, r0, 0x405
    li	r5, 1
    ori	r0, r0, 0xc0
    stw	r0, 0(r30)
    stw	r31, 0x4c(r1)
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r26, r0, 5
_8008f574:
    lwz	r0, 0(r29)
    clrlwi.	r0, r0, 0x1f
    bne     _8008f574
    addi	r3, r1, 0x54
    li	r4, 4
    li	r5, 0
    bl      UARTByteEngine
_8008f590:
    lwz	r0, 0(r29)
    clrlwi.	r0, r0, 0x1f
    bne     _8008f590
    lwz	r0, 0(r30)
    andi.	r0, r0, 0x405
    stw	r0, 0(r30)
    lwz	r0, 0x54(r1)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bne     _8008f548
    lbz	r0, -0x7d38(r13)
    slwi	r0, r0, 0x10
    oris	r0, r0, 0x1f00
    or	r0, r0, r27
    clrlwi	r0, r0, 3
    oris	r24, r0, 0xc000
_8008f5cc:
    lwz	r0, 0(r30)
    addi	r3, r1, 0x44
    li	r4, 4
    andi.	r0, r0, 0x405
    li	r5, 1
    ori	r0, r0, 0xc0
    stw	r0, 0(r30)
    stw	r24, 0x44(r1)
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r3, r0, 5
_8008f5f8:
    lwz	r0, 0(r29)
    clrlwi.	r0, r0, 0x1f
    bne     _8008f5f8
    lwz	r0, 0(r30)
    andi.	r0, r0, 0x405
    cmpwi	r3, 0
    stw	r0, 0(r30)
    bne     _8008f5cc
    lis	r27, 0x4000
_8008f61c:
    lwz	r0, 0(r30)
    addi	r3, r1, 0x3c
    li	r4, 2
    andi.	r0, r0, 0x405
    li	r5, 1
    ori	r0, r0, 0xc0
    stw	r0, 0(r30)
    stw	r27, 0x3c(r1)
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r26, r0, 5
_8008f648:
    lwz	r0, 0(r29)
    clrlwi.	r0, r0, 0x1f
    bne     _8008f648
    addi	r3, r1, 0x54
    li	r4, 4
    li	r5, 0
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r3, r26, r0
_8008f670:
    lwz	r0, 0(r29)
    clrlwi.	r0, r0, 0x1f
    bne     _8008f670
    lwz	r0, 0(r30)
    andi.	r0, r0, 0x405
    cmpwi	r3, 0
    stw	r0, 0(r30)
    bne     _8008f61c
    lwz	r0, 0x54(r1)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    bne     _8008f61c
    mr	r3, r28
    bl      OSRestoreInterrupts
    lmw	r24, 0x58(r1)
    li	r3, 0
    lwz	r0, 0x7c(r1)
    addi	r1, r1, 0x78
    mtlr	r0
    blr	
}

asm void fn_8008F6BC(void)
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
    lwz	r0, -0x7590(r13)
    addi	r31, r3, 0
    rlwinm.	r0, r0, 0, 0xf, 0xf
    beq     _8008f6f8
    li	r3, 0x1000
    b       _8008f6fc
_8008f6f8:
    li	r3, 0
_8008f6fc:
    addis	r3, r3, 2
    addi	r0, r30, 3
    addi	r4, r29, 0
    rlwinm	r5, r0, 0, 0, 0x1d
    addi	r3, r3, -0x2000
    bl      UARTWriteFrame
    li	r0, 0
    stw	r0, -0x758c(r13)
    mr	r3, r31
    stb	r0, -0x7584(r13)
    bl      OSRestoreInterrupts
    lwz	r0, 0x24(r1)
    li	r3, 0
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_8008F748(void)
{
    nofralloc
    mflr	r0
    li	r3, 0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    lwz	r0, -0x758c(r13)
    stb	r3, -0x7584(r13)
    cmpwi	r0, 0
    bne     _8008f7cc
    bl      OSDisableInterrupts
    addi	r31, r3, 0
    addi	r3, r1, 8
    bl      UART_ReadN_IntDriven
    lwz	r0, 8(r1)
    clrlwi.	r0, r0, 0x1f
    beq     _8008f7c4
    addi	r3, r1, 8
    bl      UARTReadFrame
    lwz	r0, 8(r1)
    clrlwi	r0, r0, 3
    stw	r0, 8(r1)
    lwz	r4, 8(r1)
    rlwinm	r3, r4, 0, 3, 7
    addis	r0, r3, -0x1f00
    cmplwi	r0, 0
    bne     _8008f7c4
    clrlwi	r3, r4, 0x11
    stw	r4, -0x7590(r13)
    li	r0, 1
    stw	r3, -0x758c(r13)
    stb	r0, -0x7584(r13)
_8008f7c4:
    mr	r3, r31
    bl      OSRestoreInterrupts
_8008f7cc:
    lwz	r3, -0x758c(r13)
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void UART_InstallInterruptHandlers(void)
{
    nofralloc
    mflr	r0
    lis	r3, 2
    stw	r0, 4(r1)
    addi	r3, r3, -0x8000
    stwu	r1, -8(r1)
    bl      __OSMaskInterrupts
    li	r3, 0x40
    bl      __OSMaskInterrupts
    lis     r3, fn_8008F8F0@ha
    addi	r0, r3, fn_8008F8F0@l
    lis     r3, fn_8008F8B0@ha
    stw	r0, -0x7594(r13)
    addi	r4, r3, fn_8008F8B0@l
    li	r3, 0x19
    bl      __OSSetInterruptHandler
    li	r3, 0x40
    bl      __OSUnmaskInterrupts
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_8008F838(void)
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
    addi	r0, r13, -0x7584
    stw	r0, -0x7588(r13)
    lis	r4, 2
    addi	r31, r3, 0
    lwz	r0, -0x7588(r13)
    addi	r3, r4, -0x8000
    stw	r0, 0(r29)
    stw	r30, -0x7598(r13)
    bl      __OSMaskInterrupts
    lis	r3, -0x3400
    li	r0, 0
    stw	r0, 0x6828(r3)
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

asm void fn_8008F8B0(void)
{
    nofralloc
    mflr	r0
    lis	r5, -0x3400
    stw	r0, 4(r1)
    li	r0, 0x1000
    stwu	r1, -8(r1)
    lwz	r12, -0x7594(r13)
    stw	r0, 0x3000(r5)
    cmplwi	r12, 0
    beq     _8008f8e0
    mtlr	r12
    extsh	r3, r3
    blrl	
_8008f8e0:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_8008F8F0(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    li	r0, 1
    stwu	r1, -8(r1)
    lwz	r12, -0x7598(r13)
    stb	r0, -0x7584(r13)
    cmplwi	r12, 0
    beq     _8008f91c
    mtlr	r12
    li	r3, 0
    blrl	
_8008f91c:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void UART_ReadN_IntDriven(register void* a, register void* b, register void* c, register void* d) // forward-declared
{
    nofralloc
    mflr	r0
    li	r4, 2
    stw	r0, 4(r1)
    lis	r0, 0x4000
    stwu	r1, -0x38(r1)
    stmw	r27, 0x24(r1)
    lis	r30, -0x3400
    addi	r27, r3, 0
    addi	r29, r30, 0x6800
    addi	r3, r1, 0x18
    lwz	r5, 0x6828(r30)
    andi.	r5, r5, 0x405
    ori	r5, r5, 0xc0
    stwu	r5, 0x28(r29)
    li	r5, 1
    stw	r0, 0x18(r1)
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r31, r0, 5
_8008f978:
    addi	r28, r30, 0x6800
    lwzu	r0, 0x34(r28)
    clrlwi.	r0, r0, 0x1f
    bne     _8008f978
    addi	r3, r27, 0
    li	r4, 4
    li	r5, 0
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r3, r31, r0
_8008f9a4:
    lwz	r0, 0(r28)
    clrlwi.	r0, r0, 0x1f
    bne     _8008f9a4
    lwz	r4, 0(r29)
    cntlzw	r0, r3
    srwi	r3, r0, 5
    andi.	r0, r4, 0x405
    stw	r0, 0(r29)
    lmw	r27, 0x24(r1)
    lwz	r0, 0x3c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

asm void UART_WriteN_IntDriven(register void* a, register void* b, register void* c, register void* d) // forward-declared
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    rlwinm	r0, r3, 8, 7, 0x15
    oris	r0, r0, 0xa000
    stwu	r1, -0x40(r1)
    stmw	r26, 0x28(r1)
    lis	r29, -0x3400
    addi	r30, r5, 0
    addi	r26, r4, 0
    addi	r31, r29, 0x6800
    addi	r3, r1, 0x24
    li	r4, 4
    li	r5, 1
    lwz	r6, 0x6828(r29)
    andi.	r6, r6, 0x405
    ori	r6, r6, 0xc0
    stwu	r6, 0x28(r31)
    stw	r0, 0x24(r1)
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r0, r0, 5
    mr	r27, r0
_8008fa30:
    addi	r28, r29, 0x6800
    lwzu	r0, 0x34(r28)
    clrlwi.	r0, r0, 0x1f
    bne     _8008fa30
    b       _8008fa84
_8008fa44:
    lwz	r0, 0(r26)
    addi	r3, r1, 0x20
    li	r4, 4
    stw	r0, 0x20(r1)
    li	r5, 1
    addi	r26, r26, 4
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r27, r27, r0
_8008fa6c:
    lwz	r0, 0(r28)
    clrlwi.	r0, r0, 0x1f
    bne     _8008fa6c
    addic.	r30, r30, -4
    bge     _8008fa84
    li	r30, 0
_8008fa84:
    cmpwi	r30, 0
    bne     _8008fa44
    lwz	r4, 0(r31)
    cntlzw	r0, r27
    srwi	r3, r0, 5
    andi.	r0, r4, 0x405
    stw	r0, 0(r31)
    lmw	r26, 0x28(r1)
    lwz	r0, 0x44(r1)
    addi	r1, r1, 0x40
    mtlr	r0
    blr	
}

asm void UARTWriteFrame(register void* a, register void* b, register void* c, register void* d) // forward-declared
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    rlwinm	r0, r3, 8, 7, 0x15
    oris	r0, r0, 0x2000
    stwu	r1, -0x40(r1)
    stmw	r26, 0x28(r1)
    lis	r29, -0x3400
    addi	r30, r5, 0
    addi	r26, r4, 0
    addi	r31, r29, 0x6800
    addi	r3, r1, 0x24
    li	r4, 4
    li	r5, 1
    lwz	r6, 0x6828(r29)
    andi.	r6, r6, 0x405
    ori	r6, r6, 0xc0
    stwu	r6, 0x28(r31)
    stw	r0, 0x24(r1)
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r0, r0, 5
    mr	r27, r0
_8008fb0c:
    addi	r28, r29, 0x6800
    lwzu	r0, 0x34(r28)
    clrlwi.	r0, r0, 0x1f
    bne     _8008fb0c
    b       _8008fb60
_8008fb20:
    addi	r3, r1, 0x20
    li	r4, 4
    li	r5, 0
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r27, r27, r0
_8008fb3c:
    lwz	r0, 0(r28)
    clrlwi.	r0, r0, 0x1f
    bne     _8008fb3c
    lwz	r0, 0x20(r1)
    addic.	r30, r30, -4
    stw	r0, 0(r26)
    addi	r26, r26, 4
    bge     _8008fb60
    li	r30, 0
_8008fb60:
    cmpwi	r30, 0
    bne     _8008fb20
    lwz	r4, 0(r31)
    cntlzw	r0, r27
    srwi	r3, r0, 5
    andi.	r0, r4, 0x405
    stw	r0, 0(r31)
    lmw	r26, 0x28(r1)
    lwz	r0, 0x44(r1)
    addi	r1, r1, 0x40
    mtlr	r0
    blr	
}

asm void UARTReadFrame(register void* a, register void* b, register void* c, register void* d) // forward-declared
{
    nofralloc
    mflr	r0
    li	r4, 2
    stw	r0, 4(r1)
    lis	r0, 0x6000
    stwu	r1, -0x38(r1)
    stmw	r27, 0x24(r1)
    lis	r30, -0x3400
    addi	r27, r3, 0
    addi	r29, r30, 0x6800
    addi	r3, r1, 0x18
    lwz	r5, 0x6828(r30)
    andi.	r5, r5, 0x405
    ori	r5, r5, 0xc0
    stwu	r5, 0x28(r29)
    li	r5, 1
    stw	r0, 0x18(r1)
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r31, r0, 5
_8008fbdc:
    addi	r28, r30, 0x6800
    lwzu	r0, 0x34(r28)
    clrlwi.	r0, r0, 0x1f
    bne     _8008fbdc
    addi	r3, r27, 0
    li	r4, 4
    li	r5, 0
    bl      UARTByteEngine
    cntlzw	r0, r3
    srwi	r0, r0, 5
    or	r3, r31, r0
_8008fc08:
    lwz	r0, 0(r28)
    clrlwi.	r0, r0, 0x1f
    bne     _8008fc08
    lwz	r4, 0(r29)
    cntlzw	r0, r3
    srwi	r3, r0, 5
    andi.	r0, r4, 0x405
    stw	r0, 0(r29)
    lmw	r27, 0x24(r1)
    lwz	r0, 0x3c(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

#pragma pop
