// provenance: original
#pragma push
#pragma force_active on


asm void UARTByteEngine(void)
{
    nofralloc
    stwu	r1, -0x48(r1)
    cmplwi	r5, 0
    stmw	r22, 0x20(r1)
    beq     _8008fd80
    li	r29, 0
    cmpw	r29, r4
    li	r30, 0
    bge     _8008fd78
    cmpwi	r4, 8
    addi	r6, r4, -8
    ble     _8008fec0
    addi	r0, r6, 7
    srwi	r0, r0, 3
    cmpwi	r6, 0
    mtctr	r0
    addi	r31, r3, 0
    ble     _8008fec0
_8008fc80:
    subfic	r6, r29, 3
    lbz	r12, 0(r31)
    addi	r0, r29, 1
    lbz	r11, 1(r31)
    slwi	r10, r6, 3
    lbz	r9, 2(r31)
    subfic	r8, r0, 3
    lbz	r7, 3(r31)
    addi	r6, r29, 2
    lbz	r0, 4(r31)
    slw	r12, r12, r10
    lbz	r23, 5(r31)
    slwi	r10, r8, 3
    lbz	r25, 6(r31)
    subfic	r6, r6, 3
    lbz	r27, 7(r31)
    slwi	r8, r6, 3
    neg	r6, r29
    addi	r22, r29, 4
    slwi	r6, r6, 3
    subfic	r22, r22, 3
    addi	r24, r29, 5
    slwi	r22, r22, 3
    subfic	r24, r24, 3
    addi	r26, r29, 6
    slwi	r24, r24, 3
    subfic	r26, r26, 3
    addi	r28, r29, 7
    slwi	r26, r26, 3
    subfic	r28, r28, 3
    slwi	r28, r28, 3
    or	r30, r30, r12
    slw	r10, r11, r10
    or	r30, r30, r10
    slw	r8, r9, r8
    or	r30, r30, r8
    slw	r6, r7, r6
    or	r30, r30, r6
    slw	r0, r0, r22
    or	r30, r30, r0
    slw	r0, r23, r24
    or	r30, r30, r0
    slw	r0, r25, r26
    or	r30, r30, r0
    slw	r0, r27, r28
    or	r30, r30, r0
    addi	r31, r31, 8
    addi	r29, r29, 8
    bdnz    _8008fc80
    b       _8008fec0
_8008fd48:
    subf	r0, r29, r4
    cmpw	r29, r4
    mtctr	r0
    bge     _8008fd78
_8008fd58:
    subfic	r0, r29, 3
    lbz	r6, 0(r7)
    slwi	r0, r0, 3
    slw	r0, r6, r0
    or	r30, r30, r0
    addi	r7, r7, 1
    addi	r29, r29, 1
    bdnz    _8008fd58
_8008fd78:
    lis	r6, -0x3400
    stw	r30, 0x6838(r6)
_8008fd80:
    addi	r0, r4, -1
    lis	r6, -0x3400
    slwi	r7, r5, 2
    addi	r8, r6, 0x6800
    ori	r6, r7, 1
    slwi	r0, r0, 4
    or	r0, r6, r0
    stwu	r0, 0x34(r8)
_8008fda0:
    lwz	r0, 0(r8)
    clrlwi.	r0, r0, 0x1f
    bne     _8008fda0
    cmplwi	r5, 0
    bne     _8008feb8
    li	r5, 0
    lis	r6, -0x3400
    cmpw	r5, r4
    lwz	r0, 0x6838(r6)
    bge     _8008feb8
    cmpwi	r4, 8
    addi	r7, r4, -8
    ble     _8008fe8c
    addi	r6, r7, 7
    srwi	r6, r6, 3
    cmpwi	r7, 0
    mtctr	r6
    ble     _8008fe8c
_8008fde8:
    subfic	r6, r5, 3
    slwi	r7, r6, 3
    addi	r6, r5, 1
    srw	r8, r0, r7
    subfic	r6, r6, 3
    stb	r8, 0(r3)
    slwi	r7, r6, 3
    addi	r6, r5, 2
    srw	r12, r0, r7
    subfic	r6, r6, 3
    stb	r12, 1(r3)
    slwi	r6, r6, 3
    srw	r11, r0, r6
    neg	r6, r5
    stb	r11, 2(r3)
    slwi	r7, r6, 3
    addi	r6, r5, 4
    srw	r10, r0, r7
    subfic	r6, r6, 3
    stb	r10, 3(r3)
    slwi	r7, r6, 3
    addi	r6, r5, 5
    srw	r9, r0, r7
    subfic	r6, r6, 3
    stb	r9, 4(r3)
    slwi	r7, r6, 3
    srw	r8, r0, r7
    addi	r6, r5, 6
    stb	r8, 5(r3)
    subfic	r7, r6, 3
    addi	r6, r5, 7
    slwi	r7, r7, 3
    srw	r7, r0, r7
    subfic	r6, r6, 3
    stb	r7, 6(r3)
    slwi	r6, r6, 3
    srw	r6, r0, r6
    stb	r6, 7(r3)
    addi	r3, r3, 8
    addi	r5, r5, 8
    bdnz    _8008fde8
_8008fe8c:
    subf	r6, r5, r4
    cmpw	r5, r4
    mtctr	r6
    bge     _8008feb8
_8008fe9c:
    subfic	r4, r5, 3
    slwi	r4, r4, 3
    srw	r4, r0, r4
    stb	r4, 0(r3)
    addi	r3, r3, 1
    addi	r5, r5, 1
    bdnz    _8008fe9c
_8008feb8:
    li	r3, 1
    b       _8008fec8
_8008fec0:
    add	r7, r3, r29
    b       _8008fd48
_8008fec8:
    lmw	r22, 0x20(r1)
    addi	r1, r1, 0x48
    blr	
}

// provenance: original
int AMC_IsStub(void)
{
    return 0;
}

// provenance: original
int Hu_IsStub(void)
{
    return 0;
}

#pragma pop
