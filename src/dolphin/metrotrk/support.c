#pragma push
#pragma force_active on

asm void memcpy(register void* a, register void* b, register void* c, register void* d);
asm void TRKReleaseMutex_Interrupt(register void* a, register void* b, register void* c, register void* d);
asm void TRKAcquireMutex_Interrupt(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008E76C(register void* a, register void* b, register void* c, register void* d);

asm void EXI2_ReadN(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    mr	r28, r4
    lwz	r0, 0x10(r3)
    cmplw	r31, r0
    ble     _8008e150
    li	r3, -1
    b       _8008e1fc
_8008e150:
    addi	r3, r30, 0x18
    bl      TRKAcquireMutex_Interrupt
    lwz	r3, 8(r30)
    lwz	r4, 0(r30)
    lwz	r0, 0xc(r30)
    subf	r3, r3, r4
    subf	r29, r3, r0
    cmplw	r31, r29
    bge     _8008e190
    mr	r3, r28
    mr	r5, r31
    bl      memcpy
    lwz	r0, 0(r30)
    add	r0, r0, r31
    stw	r0, 0(r30)
    b       _8008e1bc
_8008e190:
    mr	r3, r28
    mr	r5, r29
    bl      memcpy
    lwz	r4, 8(r30)
    add	r3, r28, r29
    subf	r5, r29, r31
    bl      memcpy
    lwz	r0, 8(r30)
    add	r0, r0, r31
    subf	r0, r29, r0
    stw	r0, 0(r30)
_8008e1bc:
    lwz	r4, 8(r30)
    lwz	r0, 0(r30)
    lwz	r3, 0xc(r30)
    subf	r0, r4, r0
    cmplw	r3, r0
    bne     _8008e1d8
    stw	r4, 0(r30)
_8008e1d8:
    lwz	r0, 0x14(r30)
    addi	r3, r30, 0x18
    add	r0, r0, r31
    stw	r0, 0x14(r30)
    lwz	r0, 0x10(r30)
    subf	r0, r31, r0
    stw	r0, 0x10(r30)
    bl      TRKReleaseMutex_Interrupt
    li	r3, 0
_8008e1fc:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void EXI2_WriteN(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    mr	r31, r5
    stw	r30, 0x18(r1)
    mr	r30, r3
    stw	r29, 0x14(r1)
    stw	r28, 0x10(r1)
    mr	r28, r4
    lwz	r0, 0x14(r3)
    cmplw	r31, r0
    ble     _8008e258
    li	r3, -1
    b       _8008e304
_8008e258:
    addi	r3, r30, 0x18
    bl      TRKAcquireMutex_Interrupt
    lwz	r4, 8(r30)
    lwz	r3, 4(r30)
    lwz	r0, 0xc(r30)
    subf	r4, r4, r3
    subf	r29, r4, r0
    cmplw	r29, r31
    blt     _8008e298
    mr	r4, r28
    mr	r5, r31
    bl      memcpy
    lwz	r0, 4(r30)
    add	r0, r0, r31
    stw	r0, 4(r30)
    b       _8008e2c4
_8008e298:
    mr	r4, r28
    mr	r5, r29
    bl      memcpy
    lwz	r3, 8(r30)
    add	r4, r28, r29
    subf	r5, r29, r31
    bl      memcpy
    lwz	r0, 8(r30)
    add	r0, r0, r31
    subf	r0, r29, r0
    stw	r0, 4(r30)
_8008e2c4:
    lwz	r4, 8(r30)
    lwz	r0, 4(r30)
    lwz	r3, 0xc(r30)
    subf	r0, r4, r0
    cmplw	r3, r0
    bne     _8008e2e0
    stw	r4, 4(r30)
_8008e2e0:
    lwz	r0, 0x14(r30)
    addi	r3, r30, 0x18
    subf	r0, r31, r0
    stw	r0, 0x14(r30)
    lwz	r0, 0x10(r30)
    add	r0, r0, r31
    stw	r0, 0x10(r30)
    bl      TRKReleaseMutex_Interrupt
    li	r3, 0
_8008e304:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    lwz	r28, 0x10(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void EXI2_Init(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    mr	r6, r3
    stw	r0, 0x14(r1)
    li	r0, 0
    stw	r4, 8(r3)
    addi	r3, r6, 0x18
    stw	r5, 0xc(r6)
    lwz	r4, 8(r6)
    stw	r4, 0(r6)
    lwz	r4, 8(r6)
    stw	r4, 4(r6)
    stw	r0, 0x10(r6)
    lwz	r0, 0xc(r6)
    stw	r0, 0x14(r6)
    bl      fn_8008E76C
    lwz	r0, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void EXI2_Poll(void)
{
    nofralloc
    lwz	r3, 0x10(r3)
    blr	
}

#pragma pop
