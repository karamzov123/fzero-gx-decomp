#pragma push
#pragma force_active on
extern unsigned char lbl_801A6398[24];

asm void memset(register void* a, register void* b, register void* c, register void* d);
asm void OSDisableInterrupts(register void* a, register void* b, register void* c, register void* d);
asm void OSRestoreInterrupts(register void* a, register void* b, register void* c, register void* d);
asm void __OSSetInterruptHandler(register void* a, register void* b, register void* c, register void* d);
asm void __OSMaskInterrupts(register void* a, register void* b, register void* c, register void* d);
asm void __OSUnmaskInterrupts(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008EB4C(register void* a, register void* b, register void* c, register void* d);

asm void TRKReleaseMutex_Interrupt(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    lwz	r3, 0(r3)
    bl      OSRestoreInterrupts
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void TRKAcquireMutex_Interrupt(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    stw	r31, 0xc(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    stw	r3, 0(r31)
    lwz	r0, 0x14(r1)
    lwz	r31, 0xc(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void fn_8008E76C(void)
{
    nofralloc
    blr	
}

asm void EXI2_SetupTransfer(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x50(r1)
    stmw	r21, 0x24(r1)
    addi	r28, r3, 0
    addi	r29, r4, 0
    addi	r30, r5, 0
    addi	r22, r6, 0
    li	r21, 2
    bl      OSDisableInterrupts
    lwz	r4, -0x7d48(r13)
    addi	r31, r3, 0
    lwz	r0, 0xc(r4)
    addi	r3, r4, 0xc
    clrlwi.	r0, r0, 0x1e
    bne     _8008e7bc
    lwz	r0, 0(r3)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    bne     _8008e7cc
_8008e7bc:
    mr	r3, r31
    bl      OSRestoreInterrupts
    li	r3, 0
    b       _8008e9a0
_8008e7cc:
    stw	r22, 4(r4)
    lwz	r3, -0x7d48(r13)
    lwz	r0, 4(r3)
    cmplwi	r0, 0
    beq     _8008e7fc
    li	r3, 0
    li	r4, 1
    bl      fn_8008EB4C
    mulli	r0, r21, 3
    lis	r3, 0x20
    srw	r3, r3, r0
    bl      __OSUnmaskInterrupts
_8008e7fc:
    lwz	r3, -0x7d48(r13)
    cmplwi	r30, 0
    lwz	r0, 0xc(r3)
    ori	r0, r0, 2
    stw	r0, 0xc(r3)
    beq     _8008e948
    li	r12, 0
    cmpw	r12, r29
    li	r11, 0
    bge     _8008e940
    cmpwi	r29, 8
    addi	r3, r29, -8
    ble     _8008e998
    addi	r0, r3, 7
    srwi	r0, r0, 3
    cmpwi	r3, 0
    mtctr	r0
    addi	r10, r28, 0
    ble     _8008e998
_8008e848:
    subfic	r3, r12, 3
    lbz	r9, 0(r10)
    addi	r0, r12, 1
    lbz	r8, 1(r10)
    slwi	r7, r3, 3
    lbz	r6, 2(r10)
    subfic	r5, r0, 3
    lbz	r4, 3(r10)
    addi	r3, r12, 2
    lbz	r0, 4(r10)
    slw	r9, r9, r7
    lbz	r22, 5(r10)
    slwi	r7, r5, 3
    lbz	r24, 6(r10)
    subfic	r3, r3, 3
    lbz	r26, 7(r10)
    slwi	r5, r3, 3
    neg	r3, r12
    addi	r21, r12, 4
    slwi	r3, r3, 3
    subfic	r21, r21, 3
    addi	r23, r12, 5
    slwi	r21, r21, 3
    subfic	r23, r23, 3
    addi	r25, r12, 6
    slwi	r23, r23, 3
    subfic	r25, r25, 3
    addi	r27, r12, 7
    slwi	r25, r25, 3
    subfic	r27, r27, 3
    slwi	r27, r27, 3
    or	r11, r11, r9
    slw	r7, r8, r7
    or	r11, r11, r7
    slw	r5, r6, r5
    or	r11, r11, r5
    slw	r3, r4, r3
    or	r11, r11, r3
    slw	r0, r0, r21
    or	r11, r11, r0
    slw	r0, r22, r23
    or	r11, r11, r0
    slw	r0, r24, r25
    or	r11, r11, r0
    slw	r0, r26, r27
    or	r11, r11, r0
    addi	r10, r10, 8
    addi	r12, r12, 8
    bdnz    _8008e848
    b       _8008e998
_8008e910:
    subf	r0, r12, r29
    cmpw	r12, r29
    mtctr	r0
    bge     _8008e940
_8008e920:
    subfic	r0, r12, 3
    lbz	r3, 0(r4)
    slwi	r0, r0, 3
    slw	r0, r3, r0
    or	r11, r11, r0
    addi	r4, r4, 1
    addi	r12, r12, 1
    bdnz    _8008e920
_8008e940:
    lis	r3, -0x3400
    stw	r11, 0x6838(r3)
_8008e948:
    lwz	r3, -0x7d48(r13)
    cmplwi	r30, 1
    stw	r28, 0x14(r3)
    beq     _8008e960
    mr	r6, r29
    b       _8008e964
_8008e960:
    li	r6, 0
_8008e964:
    lwz	r5, -0x7d48(r13)
    slwi	r4, r30, 2
    addi	r0, r29, -1
    stw	r6, 0x10(r5)
    ori	r4, r4, 1
    slwi	r0, r0, 4
    lis	r3, -0x3400
    or	r0, r4, r0
    stw	r0, 0x6834(r3)
    mr	r3, r31
    bl      OSRestoreInterrupts
    li	r3, 1
    b       _8008e9a0
_8008e998:
    add	r4, r28, r12
    b       _8008e910
_8008e9a0:
    lmw	r21, 0x24(r1)
    lwz	r0, 0x54(r1)
    addi	r1, r1, 0x50
    mtlr	r0
    blr	
}

asm void EXI2_ExecuteTransfer(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    lwz	r4, -0x7d48(r13)
    b       _8008eb24
_8008e9cc:
    lwz	r0, 0x34(r3)
    clrlwi.	r0, r0, 0x1f
    bne     _8008eb2c
    bl      OSDisableInterrupts
    lwz	r6, -0x7d48(r13)
    lwz	r0, 0xc(r6)
    addi	r4, r6, 0xc
    clrlwi.	r0, r0, 0x1e
    beq     _8008eb1c
    lwz	r0, 0(r4)
    rlwinm.	r0, r0, 0, 0x1e, 0x1e
    beq     _8008eb0c
    lwz	r4, 0x10(r6)
    cmpwi	r4, 0
    beq     _8008eb0c
    lis	r5, -0x3400
    lwz	r7, 0x14(r6)
    lwz	r6, 0x6838(r5)
    li	r5, 0
    ble     _8008eb0c
    cmpwi	r4, 8
    addi	r8, r4, -8
    ble     _8008eae0
    addi	r0, r8, 7
    srwi	r0, r0, 3
    cmpwi	r8, 0
    mtctr	r0
    ble     _8008eae0
_8008ea3c:
    subfic	r0, r5, 3
    slwi	r8, r0, 3
    addi	r0, r5, 1
    srw	r8, r6, r8
    subfic	r0, r0, 3
    stb	r8, 0(r7)
    slwi	r0, r0, 3
    addi	r8, r5, 2
    srw	r0, r6, r0
    subfic	r8, r8, 3
    stb	r0, 1(r7)
    slwi	r8, r8, 3
    srw	r31, r6, r8
    neg	r8, r5
    stb	r31, 2(r7)
    slwi	r9, r8, 3
    addi	r8, r5, 4
    srw	r12, r6, r9
    subfic	r8, r8, 3
    stb	r12, 3(r7)
    slwi	r9, r8, 3
    addi	r8, r5, 5
    srw	r11, r6, r9
    subfic	r8, r8, 3
    stb	r11, 4(r7)
    slwi	r9, r8, 3
    srw	r10, r6, r9
    addi	r8, r5, 6
    stb	r10, 5(r7)
    subfic	r9, r8, 3
    addi	r8, r5, 7
    slwi	r9, r9, 3
    srw	r9, r6, r9
    subfic	r8, r8, 3
    stb	r9, 6(r7)
    slwi	r8, r8, 3
    srw	r8, r6, r8
    stb	r8, 7(r7)
    addi	r7, r7, 8
    addi	r5, r5, 8
    bdnz    _8008ea3c
_8008eae0:
    subf	r0, r5, r4
    cmpw	r5, r4
    mtctr	r0
    bge     _8008eb0c
_8008eaf0:
    subfic	r0, r5, 3
    slwi	r0, r0, 3
    srw	r0, r6, r0
    stb	r0, 0(r7)
    addi	r7, r7, 1
    addi	r5, r5, 1
    bdnz    _8008eaf0
_8008eb0c:
    lwz	r4, -0x7d48(r13)
    lwz	r0, 0xc(r4)
    rlwinm	r0, r0, 0, 0, 0x1d
    stw	r0, 0xc(r4)
_8008eb1c:
    bl      OSRestoreInterrupts
    b       _8008eb38
_8008eb24:
    lis	r3, -0x3400
    addi	r3, r3, 0x6800
_8008eb2c:
    lwz	r0, 0xc(r4)
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    bne     _8008e9cc
_8008eb38:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_8008EB4C(register void* a, register void* b, register void* c, register void* d) // forward-declared
{
    nofralloc
    cmpwi	r3, 0
    beq     _8008eb68
    lis	r3, -0x3400
    lwz	r0, 0x3000(r3)
    rlwinm	r0, r0, 0, 0x13, 0x13
    ori	r0, r0, 0x1000
    stw	r0, 0x3000(r3)
_8008eb68:
    cmpwi	r4, 0
    beqlr	
    lis	r3, -0x3400
    addi	r3, r3, 0x6800
    lwz	r0, 0x28(r3)
    andi.	r0, r0, 0x7f5
    ori	r0, r0, 8
    stw	r0, 0x28(r3)
    blr	
}

asm void fn_8008EB8C(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    mr	r30, r3
    bl      OSDisableInterrupts
    cmplwi	r30, 0
    addi	r31, r3, 0
    beq     _8008ebc0
    li	r3, 0x40
    bl      __OSUnmaskInterrupts
    b       _8008ebc8
_8008ebc0:
    li	r3, 0x40
    bl      __OSMaskInterrupts
_8008ebc8:
    lwz	r4, -0x7d48(r13)
    mr	r3, r31
    lwz	r31, 0(r4)
    stw	r30, 0(r4)
    bl      OSRestoreInterrupts
    lwz	r0, 0x1c(r1)
    mr	r3, r31
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x18
    blr	
}

asm void fn_8008EBF8(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    lwz	r4, -0x7d48(r13)
    lwz	r0, 0xc(r4)
    addi	r5, r4, 0xc
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    beq     _8008ec30
    bl      OSRestoreInterrupts
    li	r3, 0
    b       _8008ec64
_8008ec30:
    lwz	r0, 0(r5)
    lis	r4, -0x3400
    addi	r4, r4, 0x6800
    ori	r0, r0, 4
    stw	r0, 0(r5)
    slwi	r0, r31, 4
    ori	r0, r0, 0x80
    lwz	r5, 0x28(r4)
    andi.	r5, r5, 0x405
    or	r5, r5, r0
    stw	r5, 0x28(r4)
    bl      OSRestoreInterrupts
    li	r3, 1
_8008ec64:
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm void fn_8008EC78(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    bl      OSDisableInterrupts
    lwz	r4, -0x7d48(r13)
    lwz	r0, 0xc(r4)
    addi	r5, r4, 0xc
    rlwinm.	r0, r0, 0, 0x1d, 0x1d
    bne     _8008eca8
    bl      OSRestoreInterrupts
    li	r3, 0
    b       _8008ecd0
_8008eca8:
    lwz	r0, 0(r5)
    lis	r4, -0x3400
    addi	r4, r4, 0x6800
    rlwinm	r0, r0, 0, 0x1e, 0x1c
    stw	r0, 0(r5)
    lwz	r0, 0x28(r4)
    andi.	r0, r0, 0x405
    stw	r0, 0x28(r4)
    bl      OSRestoreInterrupts
    li	r3, 1
_8008ecd0:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_8008ECE0(void)
{
    nofralloc
    mflr	r0
    lis	r5, -0x3400
    stw	r0, 4(r1)
    lwz	r0, 0x3000(r5)
    stwu	r1, -8(r1)
    rlwinm	r0, r0, 0, 0x13, 0x13
    lwz	r3, -0x7d48(r13)
    ori	r0, r0, 0x1000
    stw	r0, 0x3000(r5)
    lwz	r3, 0(r3)
    cmplwi	r3, 0
    mr	r12, r3
    beq     _8008ed20
    mtlr	r12
    li	r3, 2
    blrl	
_8008ed20:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void EXI2_SetInterruptHandler(void)
{
    nofralloc
    mflr	r0
    lis	r3, 1
    stw	r0, 4(r1)
    addi	r3, r3, -0x8000
    stwu	r1, -8(r1)
    bl      __OSMaskInterrupts
    lis     r3, fn_8008ECE0@ha
    addi	r4, r3, fn_8008ECE0@l
    li	r3, 0x19
    bl      __OSSetInterruptHandler
    li	r3, 0x40
    bl      __OSUnmaskInterrupts
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void EXI2_BufferInit(void)
{
    nofralloc
    mflr	r0
    lis     r3, lbl_801A6398@ha
    stw	r0, 4(r1)
    addi	r3, r3, lbl_801A6398@l
    li	r4, 0
    stwu	r1, -8(r1)
    li	r5, 0x18
    bl      memset
    lis	r4, -0x3400
    li	r0, 0
    stw	r0, 0x6828(r4)
    stw	r0, 0x643c(r4)
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_8008EDB0(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    li	r0, 1
    stwu	r1, -8(r1)
    lwz	r3, -0x7d40(r13)
    stb	r0, 0(r3)
    lwz	r12, -0x75a0(r13)
    cmplwi	r12, 0
    beq     _8008ede0
    mtlr	r12
    li	r3, 0
    blrl	
_8008ede0:
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void EXI2_InitSequence(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x30(r1)
    stw	r31, 0x2c(r1)
    mr	r31, r4
    lwz	r0, -0x7d40(r13)
    stw	r0, 0(r3)
    bl      OSDisableInterrupts
    stw	r31, -0x75a0(r13)
    bl      OSRestoreInterrupts
    bl      EXI2_BufferInit
    lis	r4, 0x100
    li	r3, 0
    addi	r0, r4, 3
    stw	r3, 0x20(r1)
    stw	r0, 0x1c(r1)
    b       _8008ee3c
_8008ee34:
    li	r3, 5
    bl      fn_8008EBF8
_8008ee3c:
    cmpwi	r3, 0
    beq     _8008ee34
    lis	r0, -0x8000
    stw	r0, 0x10(r1)
    addi	r3, r1, 0x10
    li	r4, 2
    li	r5, 1
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    addi	r3, r1, 0x1c
    li	r4, 4
    li	r5, 1
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    addi	r3, r1, 0x20
    li	r4, 4
    li	r5, 1
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    bl      fn_8008EC78
    lwz	r0, 0x34(r1)
    lwz	r31, 0x2c(r1)
    addi	r1, r1, 0x30
    mtlr	r0
    blr	
}

#pragma pop
