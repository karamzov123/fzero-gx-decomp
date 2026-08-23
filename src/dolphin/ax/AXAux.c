#pragma push
#pragma force_active on

typedef unsigned int u32;
extern void DCInvalidateRange(register void* addr, register u32 nBytes);
extern void DCFlushRangeNoSync(register void* addr, register u32 nBytes);
extern unsigned char lbl_8015D200[5760];
extern unsigned char lbl_8015E880[5760];

asm void fn_80020D58(void)
{
    nofralloc
    li	r7, 0
    li	r6, 1
    stw	r7, -0x7900(r13)
    li	r5, 2
    lis     r4, lbl_8015D200@ha
    stw	r7, -0x78fc(r13)
    li	r0, 0x1e
    lis     r3, lbl_8015E880@ha
    mtctr	r0
    stw	r7, -0x78f8(r13)
    addi	r4, r4, lbl_8015D200@l
    addi	r0, r3, lbl_8015E880@l
    mr	r3, r4
    stw	r7, -0x78f4(r13)
    mr	r4, r0
    stw	r7, -0x78e0(r13)
    stw	r6, -0x78dc(r13)
    stw	r7, -0x78d8(r13)
    stw	r6, -0x78d4(r13)
    stw	r5, -0x78d0(r13)
_80020da8:
    li	r0, 0
    stw	r0, 0(r3)
    stw	r0, 0(r4)
    stw	r0, 4(r3)
    stw	r0, 4(r4)
    stw	r0, 8(r3)
    stw	r0, 8(r4)
    stw	r0, 0xc(r3)
    stw	r0, 0xc(r4)
    stw	r0, 0x10(r3)
    stw	r0, 0x10(r4)
    stw	r0, 0x14(r3)
    stw	r0, 0x14(r4)
    stw	r0, 0x18(r3)
    stw	r0, 0x18(r4)
    stw	r0, 0x1c(r3)
    stw	r0, 0x1c(r4)
    stw	r0, 0x20(r3)
    stw	r0, 0x20(r4)
    stw	r0, 0x24(r3)
    stw	r0, 0x24(r4)
    stw	r0, 0x28(r3)
    stw	r0, 0x28(r4)
    stw	r0, 0x2c(r3)
    stw	r0, 0x2c(r4)
    stw	r0, 0x30(r3)
    stw	r0, 0x30(r4)
    stw	r0, 0x34(r3)
    stw	r0, 0x34(r4)
    stw	r0, 0x38(r3)
    stw	r0, 0x38(r4)
    stw	r0, 0x3c(r3)
    addi	r3, r3, 0x40
    stw	r0, 0x3c(r4)
    addi	r4, r4, 0x40
    bdnz    _80020da8
    blr	
}

asm void fn_80020E3C(void)
{
    nofralloc
    li	r0, 0
    stw	r0, -0x7900(r13)
    stw	r0, -0x78fc(r13)
    blr	
}

asm void fn_80020E4C(void)
{
    nofralloc
    lwz	r0, -0x7900(r13)
    cmplwi	r0, 0
    beq     _80020e74
    lwz	r5, -0x78e0(r13)
    lis     r4, lbl_8015D200@ha
    addi	r0, r4, lbl_8015D200@l
    mulli	r4, r5, 0x780
    add	r0, r0, r4
    stw	r0, 0(r3)
    blr	
_80020e74:
    li	r0, 0
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020E80(void)
{
    nofralloc
    lwz	r5, -0x78e0(r13)
    lis     r4, lbl_8015E880@ha
    addi	r0, r4, lbl_8015E880@l
    mulli	r4, r5, 0x780
    add	r4, r0, r4
    addi	r0, r4, 0x500
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020EA0(void)
{
    nofralloc
    lwz	r5, -0x78dc(r13)
    lis     r4, lbl_8015D200@ha
    addi	r0, r4, lbl_8015D200@l
    mulli	r4, r5, 0x780
    add	r0, r0, r4
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020EBC(void)
{
    nofralloc
    lwz	r5, -0x78dc(r13)
    lis     r4, lbl_8015D200@ha
    addi	r0, r4, lbl_8015D200@l
    mulli	r4, r5, 0x780
    add	r4, r0, r4
    addi	r0, r4, 0x280
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020EDC(void)
{
    nofralloc
    lwz	r5, -0x78dc(r13)
    lis     r4, lbl_8015D200@ha
    addi	r0, r4, lbl_8015D200@l
    mulli	r4, r5, 0x780
    add	r4, r0, r4
    addi	r0, r4, 0x500
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020EFC(void)
{
    nofralloc
    lwz	r5, -0x78dc(r13)
    lis     r4, lbl_8015E880@ha
    addi	r0, r4, lbl_8015E880@l
    mulli	r4, r5, 0x780
    add	r4, r0, r4
    addi	r0, r4, 0x500
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020F1C(void)
{
    nofralloc
    lwz	r0, -0x78fc(r13)
    cmplwi	r0, 0
    beq     _80020f44
    lwz	r5, -0x78e0(r13)
    lis     r4, lbl_8015E880@ha
    addi	r0, r4, lbl_8015E880@l
    mulli	r4, r5, 0x780
    add	r0, r0, r4
    stw	r0, 0(r3)
    blr	
_80020f44:
    li	r0, 0
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020F50(void)
{
    nofralloc
    lwz	r5, -0x78dc(r13)
    lis     r4, lbl_8015E880@ha
    addi	r0, r4, lbl_8015E880@l
    mulli	r4, r5, 0x780
    add	r0, r0, r4
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020F6C(void)
{
    nofralloc
    lwz	r5, -0x78d8(r13)
    lis     r4, lbl_8015E880@ha
    addi	r0, r4, lbl_8015E880@l
    mulli	r4, r5, 0x780
    add	r0, r0, r4
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020F88(void)
{
    nofralloc
    lwz	r5, -0x78d4(r13)
    lis     r4, lbl_8015E880@ha
    addi	r0, r4, lbl_8015E880@l
    mulli	r4, r5, 0x780
    add	r0, r0, r4
    stw	r0, 0(r3)
    blr	
}

asm void fn_80020FA4(void)
{
    nofralloc
    mflr	r0
    lis     r4, lbl_8015D200@ha
    stw	r0, 4(r1)
    stwu	r1, -0x38(r1)
    stw	r31, 0x34(r1)
    addi	r31, r4, lbl_8015D200@l
    lwz	r0, -0x78e0(r13)
    lwz	r3, -0x78dc(r13)
    mulli	r4, r0, 0x780
    lwz	r0, -0x7900(r13)
    mulli	r3, r3, 0x780
    add	r4, r31, r4
    add	r3, r31, r3
    stw	r4, -0x78f0(r13)
    addi	r4, r4, 0x1680
    stw	r3, -0x78ec(r13)
    addi	r3, r3, 0x1680
    cmplwi	r0, 0
    stw	r4, -0x78e8(r13)
    stw	r3, -0x78e4(r13)
    beq     _800210c0
    lwz	r0, -0x78b8(r13)
    cmplwi	r0, 2
    bne     _80021074
    lwz	r0, -0x78d0(r13)
    li	r4, 0x780
    mulli	r0, r0, 0x780
    add	r5, r31, r0
    stw	r5, 0x20(r1)
    addi	r0, r5, 0x280
    addi	r3, r5, 0x500
    stw	r0, 0x24(r1)
    addi	r0, r5, 0x1b80
    stw	r3, 0x28(r1)
    stw	r0, 0x2c(r1)
    lwz	r3, 0x20(r1)
    bl      DCInvalidateRange
    lwz	r3, 0x2c(r1)
    li	r4, 0x280
    bl      DCInvalidateRange
    lwz	r12, -0x7900(r13)
    addi	r3, r1, 0x20
    lwz	r4, -0x78f8(r13)
    mtlr	r12
    blrl	
    lwz	r3, 0x20(r1)
    li	r4, 0x780
    bl      DCFlushRangeNoSync
    lwz	r3, 0x2c(r1)
    li	r4, 0x280
    bl      DCFlushRangeNoSync
    b       _800210c0
_80021074:
    lwz	r0, -0x78d0(r13)
    li	r4, 0x780
    mulli	r0, r0, 0x780
    add	r5, r31, r0
    stw	r5, 0x14(r1)
    addi	r3, r5, 0x280
    addi	r0, r5, 0x500
    stw	r3, 0x18(r1)
    stw	r0, 0x1c(r1)
    lwz	r3, 0x14(r1)
    bl      DCInvalidateRange
    lwz	r12, -0x7900(r13)
    addi	r3, r1, 0x14
    lwz	r4, -0x78f8(r13)
    mtlr	r12
    blrl	
    lwz	r3, 0x14(r1)
    li	r4, 0x780
    bl      DCFlushRangeNoSync
_800210c0:
    lwz	r0, -0x78fc(r13)
    cmplwi	r0, 0
    beq     _80021128
    lwz	r0, -0x78b8(r13)
    cmplwi	r0, 2
    beq     _80021128
    lwz	r0, -0x78d0(r13)
    li	r4, 0x780
    mulli	r0, r0, 0x780
    add	r5, r31, r0
    addi	r5, r5, 0x1680
    stw	r5, 8(r1)
    addi	r3, r5, 0x280
    addi	r0, r5, 0x500
    stw	r3, 0xc(r1)
    stw	r0, 0x10(r1)
    lwz	r3, 8(r1)
    bl      DCInvalidateRange
    lwz	r12, -0x78fc(r13)
    addi	r3, r1, 8
    lwz	r4, -0x78f4(r13)
    mtlr	r12
    blrl	
    lwz	r3, 8(r1)
    li	r4, 0x780
    bl      DCFlushRangeNoSync
_80021128:
    lwz	r4, -0x78e0(r13)
    lis	r3, -0x5555
    lwz	r5, -0x78dc(r13)
    addi	r8, r3, -0x5555
    lwz	r3, -0x78d0(r13)
    addi	r0, r4, 1
    lwz	r4, -0x78d8(r13)
    addi	r5, r5, 1
    stw	r0, -0x78e0(r13)
    addi	r0, r3, 1
    lwz	r3, -0x78d4(r13)
    stw	r5, -0x78dc(r13)
    addi	r5, r4, 1
    lwz	r10, -0x78e0(r13)
    addi	r4, r3, 1
    stw	r0, -0x78d0(r13)
    lwz	r7, -0x78dc(r13)
    mulhwu	r9, r8, r10
    lwz	r3, -0x78d0(r13)
    stw	r5, -0x78d8(r13)
    stw	r4, -0x78d4(r13)
    mulhwu	r6, r8, r7
    lwz	r5, -0x78d8(r13)
    lwz	r4, -0x78d4(r13)
    mulhwu	r0, r8, r3
    srwi	r9, r9, 1
    srwi	r6, r6, 1
    srwi	r0, r0, 1
    mulli	r8, r9, 3
    mulli	r6, r6, 3
    mulli	r0, r0, 3
    subf	r8, r8, r10
    subf	r6, r6, r7
    stw	r8, -0x78e0(r13)
    clrlwi	r5, r5, 0x1f
    clrlwi	r4, r4, 0x1f
    stw	r6, -0x78dc(r13)
    subf	r0, r0, r3
    stw	r5, -0x78d8(r13)
    stw	r4, -0x78d4(r13)
    stw	r0, -0x78d0(r13)
    lwz	r0, 0x3c(r1)
    lwz	r31, 0x34(r1)
    addi	r1, r1, 0x38
    mtlr	r0
    blr	
}

asm void fn_800211E0(void)
{
    nofralloc
    stw	r3, -0x7900(r13)
    stw	r4, -0x78f8(r13)
    blr	
}

asm void fn_800211EC(void)
{
    nofralloc
    stw	r3, -0x78fc(r13)
    stw	r4, -0x78f4(r13)
    blr	
}

asm void fn_800211F8(void)
{
    nofralloc
    lwz	r3, -0x78c0(r13)
    blr	
}

#pragma pop
