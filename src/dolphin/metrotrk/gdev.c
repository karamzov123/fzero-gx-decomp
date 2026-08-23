#pragma push
#pragma force_active on

asm void fn_8008E114(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008E21C(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008E324(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008E374(register void* a, register void* b, register void* c, register void* d);
asm void MWTRACE(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F454(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F458(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F45C(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F6BC(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F748(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F7E4(register void* a, register void* b, register void* c, register void* d);
asm void fn_8008F838(register void* a, register void* b, register void* c, register void* d);

asm void gdev_cc_initinterrupts(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8008F7E4
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void gdev_cc_peek(void)
{
    nofralloc
    stwu	r1, -0x510(r1)
    mflr	r0
    stw	r0, 0x514(r1)
    stw	r31, 0x50c(r1)
    bl      fn_8008F748
    or.	r31, r3, r3
    bgt     _8008e3c4
    li	r3, 0
    b       _8008e3fc
_8008e3c4:
    mr	r4, r31
    addi	r3, r1, 8
    bl      fn_8008F6BC
    cmpwi	r3, 0
    bne     _8008e3f0
    lis	r3, -0x7fe6
    mr	r5, r31
    addi	r3, r3, 0x6378
    addi	r4, r1, 8
    bl      fn_8008E21C
    b       _8008e3f8
_8008e3f0:
    li	r3, -0x2719
    b       _8008e3fc
_8008e3f8:
    mr	r3, r31
_8008e3fc:
    lwz	r0, 0x514(r1)
    lwz	r31, 0x50c(r1)
    mtlr	r0
    addi	r1, r1, 0x510
    blr	
}

asm void gdev_cc_post_stop(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8008F458
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void gdev_cc_pre_continue(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    stw	r0, 0x14(r1)
    bl      fn_8008F454
    lwz	r0, 0x14(r1)
    li	r3, 0
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

asm void gdev_cc_write(void)
{
    nofralloc
    stwu	r1, -0x20(r1)
    mflr	r0
    lis	r5, -0x7ff7
    stw	r0, 0x24(r1)
    stw	r31, 0x1c(r1)
    addi	r31, r5, 0x5db0
    stw	r30, 0x18(r1)
    mr	r30, r4
    stw	r29, 0x14(r1)
    mr	r29, r3
    lwz	r0, -0x75b0(r13)
    cmpwi	r0, 0
    bne     _8008e4a4
    addi	r4, r31, 0
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
    li	r3, -0x2711
    b       _8008e4fc
_8008e4a4:
    mr	r5, r3
    mr	r6, r4
    addi	r4, r31, 0x14
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
    b       _8008e4f0
_8008e4c0:
    mr	r5, r30
    addi	r4, r31, 0x40
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r29
    mr	r4, r30
    bl      fn_8008F45C
    cmpwi	r3, 0
    beq     _8008e4f8
    add	r29, r29, r3
    subf	r30, r3, r30
_8008e4f0:
    cmpwi	r30, 0
    bgt     _8008e4c0
_8008e4f8:
    li	r3, 0
_8008e4fc:
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    mtlr	r0
    addi	r1, r1, 0x20
    blr	
}

asm void gdev_cc_read(void)
{
    nofralloc
    stwu	r1, -0x520(r1)
    mflr	r0
    stw	r0, 0x524(r1)
    stmw	r26, 0x508(r1)
    mr	r26, r3
    mr	r27, r4
    li	r28, 0
    lwz	r0, -0x75b0(r13)
    cmpwi	r0, 0
    bne     _8008e548
    li	r3, -0x2711
    b       _8008e5f8
_8008e548:
    lis	r3, -0x7ff7
    mr	r5, r27
    addi	r4, r3, 0x5e0c
    mr	r6, r27
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    lis	r3, -0x7fe6
    mr	r29, r27
    addi	r31, r3, 0x6378
    mr	r30, r27
    b       _8008e5ac
_8008e578:
    li	r28, 0
    bl      fn_8008F748
    or.	r27, r3, r3
    beq     _8008e5ac
    mr	r4, r30
    addi	r3, r1, 8
    bl      fn_8008F6BC
    or.	r28, r3, r3
    bne     _8008e5ac
    mr	r3, r31
    mr	r5, r27
    addi	r4, r1, 8
    bl      fn_8008E21C
_8008e5ac:
    mr	r3, r31
    bl      fn_8008E374
    cmplw	r3, r30
    blt     _8008e578
    cmplwi	r28, 0
    bne     _8008e5dc
    lis	r3, -0x7fe6
    mr	r4, r26
    addi	r3, r3, 0x6378
    mr	r5, r29
    bl      fn_8008E114
    b       _8008e5f4
_8008e5dc:
    lis	r3, -0x7ff7
    mr	r5, r28
    addi	r4, r3, 0x5e34
    li	r3, 8
    crxor	6, 6, 6
    bl      MWTRACE
_8008e5f4:
    mr	r3, r28
_8008e5f8:
    lmw	r26, 0x508(r1)
    lwz	r0, 0x524(r1)
    mtlr	r0
    addi	r1, r1, 0x520
    blr	
}

asm void gdev_cc_close(void)
{
    nofralloc
    li	r3, 0
    blr	
}

asm void gdev_cc_open(void)
{
    nofralloc
    lwz	r0, -0x75b0(r13)
    cmpwi	r0, 0
    beq     _8008e628
    li	r3, -0x2715
    blr	
_8008e628:
    li	r0, 1
    li	r3, 0
    stw	r0, -0x75b0(r13)
    blr	
}

asm void gdev_cc_shutdown(void)
{
    nofralloc
    li	r3, 0
    blr	
}

asm void gdev_cc_initialize(void)
{
    nofralloc
    stwu	r1, -0x10(r1)
    mflr	r0
    lis	r5, -0x7ff7
    stw	r0, 0x14(r1)
    addi	r0, r5, 0x5e64
    stw	r31, 0xc(r1)
    mr	r31, r4
    mr	r4, r0
    stw	r30, 8(r1)
    mr	r30, r3
    li	r3, 1
    crxor	6, 6, 6
    bl      MWTRACE
    mr	r3, r30
    mr	r4, r31
    bl      fn_8008F838
    lis	r4, -0x7ff7
    li	r3, 1
    addi	r4, r4, 0x5e78
    crxor	6, 6, 6
    bl      MWTRACE
    lis	r3, -0x7fe6
    lis	r4, -0x7fe6
    addi	r3, r3, 0x6378
    li	r5, 0x500
    addi	r4, r4, 0x5e78
    bl      fn_8008E324
    lwz	r0, 0x14(r1)
    li	r3, 0
    lwz	r31, 0xc(r1)
    lwz	r30, 8(r1)
    mtlr	r0
    addi	r1, r1, 0x10
    blr	
}

#pragma pop
