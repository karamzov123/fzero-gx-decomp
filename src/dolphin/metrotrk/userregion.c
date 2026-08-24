#pragma push
#pragma force_active on
extern void fn_8008EDB0(void);
extern unsigned char lbl_8015B900[25];
extern void fn_8008EDB0(void);

asm void fn_8008088C(register void* a, register void* b, register void* c, register void* d);
asm void EXI2_SetupTransfer(register void* a, register void* b, register void* c, register void* d);
asm void EXI2_ExecuteTransfer(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008EB8C(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008EBF8(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008EC78(register void* a, register void* b, register void* c, register void* d);
asm void EXI2_SetInterruptHandler(register void* a, register void* b, register void* c, register void* d);

asm void fn_8008EEAC(void)
{
    nofralloc
    mflr	r0
    lis     r3, fn_8008EDB0@ha
    stw	r0, 4(r1)
    addi	r3, r3, fn_8008EDB0@l
    stwu	r1, -8(r1)
    bl      fn_8008EB8C
    bl      EXI2_SetInterruptHandler
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

asm void fn_8008EED8(void)
{
    nofralloc
    mflr	r0
    lis	r3, -0x3400
    stw	r0, 4(r1)
    lwz	r0, 0x3000(r3)
    stwu	r1, -0x20(r1)
    rlwinm.	r0, r0, 0, 0x13, 0x13
    bne     _8008ef10
    lwz	r3, -0x7d40(r13)
    lbz	r0, 0(r3)
    cmplwi	r0, 0
    bne     _8008ef10
    li	r0, 0
    stw	r0, 0x18(r1)
    b       _8008efcc
_8008ef10:
    lwz	r0, -0x75a4(r13)
    cmpwi	r0, 0
    bne     _8008ef8c
    li	r3, 0
    b       _8008ef2c
_8008ef24:
    li	r3, 5
    bl      fn_8008EBF8
_8008ef2c:
    cmpwi	r3, 0
    beq     _8008ef24
    bne     _8008ef4c
    lis     r3, lbl_8015B900@ha
    crxor	6, 6, 6
    addi	r3, r3, lbl_8015B900@l
    bl      fn_8008088C
    b       _8008ef8c
_8008ef4c:
    li	r3, 1
    li	r0, 0
    stw	r3, -0x75a4(r13)
    addi	r3, r1, 8
    stw	r0, 8(r1)
    li	r4, 2
    li	r5, 1
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    addi	r3, r1, 0x14
    li	r4, 2
    li	r5, 0
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
_8008ef8c:
    addi	r3, r1, 0x18
    li	r4, 4
    li	r5, 0
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    lwz	r5, -0x7d40(r13)
    lbz	r0, 0(r5)
    cmplwi	r0, 0
    bne     _8008efcc
    lis	r4, -0x3400
    lwz	r3, 0x3000(r4)
    li	r0, 1
    stb	r0, 0(r5)
    rlwinm	r0, r3, 0, 0x13, 0x13
    stw	r0, 0x3000(r4)
_8008efcc:
    lwz	r0, 0x24(r1)
    lwz	r3, 0x18(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void fn_8008EFE0(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x48(r1)
    stmw	r25, 0x2c(r1)
    addi	r25, r3, 0
    addi	r26, r4, 0
    lwz	r0, -0x75a4(r13)
    cmpwi	r0, 0
    beq     _8008f00c
    li	r27, 1
    b       _8008f084
_8008f00c:
    li	r3, 0
    b       _8008f01c
_8008f014:
    li	r3, 5
    bl      fn_8008EBF8
_8008f01c:
    cmpwi	r3, 0
    beq     _8008f014
    mr	r27, r3
    bne     _8008f044
    lis     r3, lbl_8015B900@ha
    crxor	6, 6, 6
    addi	r3, r3, lbl_8015B900@l
    bl      fn_8008088C
    li	r27, 0
    b       _8008f084
_8008f044:
    li	r3, 1
    li	r0, 0
    stw	r3, -0x75a4(r13)
    addi	r3, r1, 0x14
    stw	r0, 0x14(r1)
    li	r4, 2
    li	r5, 1
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    addi	r3, r1, 0x1c
    li	r4, 2
    li	r5, 0
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
_8008f084:
    cmpwi	r27, 0
    bne     _8008f094
    li	r3, 1
    b       _8008f288
_8008f094:
    clrlwi.	r4, r26, 0x1e
    beq     _8008f0a4
    li	r3, 1
    b       _8008f0a8
_8008f0a4:
    li	r3, 0
_8008f0a8:
    srawi	r28, r26, 2
    srwi	r0, r26, 2
    addze	r28, r28
    add	r3, r0, r3
    clrlwi	r0, r26, 0x1f
    slwi	r28, r28, 2
    add	r29, r4, r0
    subfc	r28, r28, r26
    addi	r31, r3, -1
    li	r27, 0
    li	r30, 0
    b       _8008f258
_8008f0d8:
    cmplw	r30, r31
    bge     _8008f0e8
    li	r4, 4
    b       _8008f0fc
_8008f0e8:
    cmplwi	r29, 2
    bne     _8008f0f8
    li	r4, 2
    b       _8008f0fc
_8008f0f8:
    li	r4, 4
_8008f0fc:
    addi	r3, r1, 0x20
    li	r5, 0
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    subf	r0, r27, r26
    cmplwi	r0, 4
    blt     _8008f124
    li	r5, 4
    b       _8008f128
_8008f124:
    mr	r5, r28
_8008f128:
    cmpwi	r5, 0
    li	r4, 0
    ble     _8008f250
    cmpwi	r5, 8
    addi	r3, r5, -8
    ble     _8008f27c
    addi	r0, r3, 7
    srwi	r0, r0, 3
    cmpwi	r3, 0
    mtctr	r0
    add	r3, r25, r27
    ble     _8008f27c
_8008f158:
    subfic	r0, r4, 3
    lwz	r6, 0x20(r1)
    slwi	r0, r0, 3
    srw	r0, r6, r0
    stb	r0, 0(r3)
    addi	r0, r4, 1
    subfic	r0, r0, 3
    lwz	r7, 0x20(r1)
    slwi	r6, r0, 3
    addi	r0, r4, 2
    srw	r6, r7, r6
    stb	r6, 1(r3)
    subfic	r0, r0, 3
    slwi	r7, r0, 3
    lwz	r8, 0x20(r1)
    neg	r6, r4
    addi	r0, r4, 4
    srw	r7, r8, r7
    stb	r7, 2(r3)
    subfic	r8, r0, 3
    addi	r0, r4, 5
    lwz	r9, 0x20(r1)
    subfic	r7, r0, 3
    slwi	r6, r6, 3
    srw	r0, r9, r6
    stb	r0, 3(r3)
    addi	r0, r4, 6
    subfic	r6, r0, 3
    lwz	r9, 0x20(r1)
    addi	r0, r4, 7
    slwi	r8, r8, 3
    srw	r8, r9, r8
    stb	r8, 4(r3)
    subfic	r0, r0, 3
    slwi	r7, r7, 3
    lwz	r8, 0x20(r1)
    slwi	r6, r6, 3
    slwi	r0, r0, 3
    srw	r7, r8, r7
    stb	r7, 5(r3)
    addi	r4, r4, 8
    lwz	r7, 0x20(r1)
    srw	r6, r7, r6
    stb	r6, 6(r3)
    lwz	r6, 0x20(r1)
    srw	r0, r6, r0
    stb	r0, 7(r3)
    addi	r3, r3, 8
    bdnz    _8008f158
    b       _8008f27c
_8008f220:
    subf	r0, r4, r5
    cmpw	r4, r5
    mtctr	r0
    bge     _8008f250
_8008f230:
    subfic	r0, r4, 3
    lwz	r3, 0x20(r1)
    slwi	r0, r0, 3
    srw	r0, r3, r0
    stb	r0, 0(r6)
    addi	r6, r6, 1
    addi	r4, r4, 1
    bdnz    _8008f230
_8008f250:
    addi	r30, r30, 1
    addi	r27, r27, 4
_8008f258:
    cmplw	r27, r26
    blt     _8008f0d8
    bl      fn_8008EC78
    li	r0, 0
    lwz	r4, -0x7d40(r13)
    stw	r0, -0x75a4(r13)
    li	r3, 0
    stb	r0, 0(r4)
    b       _8008f288
_8008f27c:
    add	r6, r27, r4
    add	r6, r25, r6
    b       _8008f220
_8008f288:
    lmw	r25, 0x2c(r1)
    lwz	r0, 0x4c(r1)
    addi	r1, r1, 0x48
    mtlr	r0
    blr	
}

asm void fn_8008F29C(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x40(r1)
    stw	r31, 0x3c(r1)
    stw	r30, 0x38(r1)
    stw	r29, 0x34(r1)
    addi	r29, r3, 0
    li	r3, 0
    stw	r28, 0x30(r1)
    stw	r4, 0x28(r1)
    b       _8008f2d0
_8008f2c8:
    li	r3, 5
    bl      fn_8008EBF8
_8008f2d0:
    cmpwi	r3, 0
    beq     _8008f2c8
    bne     _8008f2e4
    li	r3, 1
    b       _8008f42c
_8008f2e4:
    lis	r0, -0x8000
    stw	r0, 0x18(r1)
    addi	r3, r1, 0x18
    li	r4, 2
    li	r5, 1
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    addi	r3, r1, 0x28
    li	r4, 4
    li	r5, 1
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    lwz	r4, 0x28(r1)
    clrlwi.	r0, r4, 0x1e
    beq     _8008f330
    li	r3, 1
    b       _8008f334
_8008f330:
    li	r3, 0
_8008f334:
    srwi	r0, r4, 2
    add	r28, r0, r3
    addi	r31, r28, -1
    li	r30, 0
    b       _8008f398
_8008f348:
    cmplw	r30, r31
    bge     _8008f358
    li	r4, 4
    b       _8008f37c
_8008f358:
    lwz	r0, 0x28(r1)
    clrlwi	r3, r0, 0x1e
    clrlwi	r0, r0, 0x1f
    add	r0, r3, r0
    cmplwi	r0, 2
    bne     _8008f378
    li	r4, 2
    b       _8008f37c
_8008f378:
    li	r4, 4
_8008f37c:
    addi	r3, r29, 0
    li	r5, 1
    li	r6, 0
    addi	r29, r29, 4
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    addi	r30, r30, 1
_8008f398:
    cmplw	r30, r28
    blt     _8008f348
    bl      fn_8008EC78
    li	r3, 0
    b       _8008f3b4
_8008f3ac:
    li	r3, 5
    bl      fn_8008EBF8
_8008f3b4:
    cmpwi	r3, 0
    beq     _8008f3ac
    bne     _8008f3c8
    li	r3, 1
    b       _8008f42c
_8008f3c8:
    lis	r0, 1
    stw	r0, 0x10(r1)
    addi	r3, r1, 0x10
    li	r4, 2
    li	r5, 1
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    addi	r3, r1, 0x24
    li	r4, 2
    li	r5, 0
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
_8008f400:
    addi	r3, r1, 0x24
    li	r4, 2
    li	r5, 0
    li	r6, 0
    bl      EXI2_SetupTransfer
    bl      EXI2_ExecuteTransfer
    lwz	r0, 0x24(r1)
    rlwinm.	r0, r0, 0x10, 0x1f, 0x1f
    beq     _8008f400
    bl      fn_8008EC78
    li	r3, 0
_8008f42c:
    lwz	r0, 0x44(r1)
    lwz	r31, 0x3c(r1)
    lwz	r30, 0x38(r1)
    mtlr	r0
    lwz	r29, 0x34(r1)
    lwz	r28, 0x30(r1)
    addi	r1, r1, 0x40
    blr	
}

#pragma pop
