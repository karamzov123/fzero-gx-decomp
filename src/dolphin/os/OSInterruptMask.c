typedef unsigned int u32;
typedef int BOOL;

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);
extern u32 SetInterruptMask(u32 mask, u32 current);
extern void OSLoadContext(void* context);
extern u32 OSGetTime(void);
extern void OSDisableScheduler(void);
extern void OSEnableScheduler(void);
extern void __OSReschedule(void);

extern void _8000d8b8(void);
extern void _8000d904(void);
extern void _8000d908(void);
extern void _8000d98c(void);
extern void _8000d990(void);
extern void _8000dc68(void);
extern void _8000dc6c(void);

#pragma push
#pragma force_active on

asm u32 SetInterruptMask(register u32 mask, register u32 current)
{
    nofralloc
    cntlzw	r0, r3
    cmpwi	r0, 0xc
    bge     _8000d610
    cmpwi	r0, 8
    beq     _8000d6f0
    bge     _8000d720
    cmpwi	r0, 5
    bge     _8000d69c
    cmpwi	r0, 0
    bge     _8000d630
    b       _8000d8b8
_8000d610:
    cmpwi	r0, 0x11
    bge     _8000d624
    cmpwi	r0, 0xf
    bge     _8000d7c4
    b       _8000d770
_8000d624:
    cmpwi	r0, 0x1b
    bge     _8000d8b8
    b       _8000d804
_8000d630:
    rlwinm	r0, r4, 0, 0, 0
    cmplwi	r0, 0
    li	r5, 0
    bne     _8000d644
    ori	r5, r5, 1
_8000d644:
    rlwinm	r0, r4, 0, 1, 1
    cmplwi	r0, 0
    bne     _8000d654
    ori	r5, r5, 2
_8000d654:
    rlwinm	r0, r4, 0, 2, 2
    cmplwi	r0, 0
    bne     _8000d664
    ori	r5, r5, 4
_8000d664:
    rlwinm	r0, r4, 0, 3, 3
    cmplwi	r0, 0
    bne     _8000d674
    ori	r5, r5, 8
_8000d674:
    rlwinm	r0, r4, 0, 4, 4
    cmplwi	r0, 0
    bne     _8000d684
    ori	r5, r5, 0x10
_8000d684:
    lis	r4, -0x3400
    clrlwi	r0, r5, 0x10
    addi	r4, r4, 0x4000
    sth	r0, 0x1c(r4)
    clrlwi	r3, r3, 5
    b       _8000d8b8
_8000d69c:
    lis	r5, -0x3400
    addi	r5, r5, 0x5000
    addi	r5, r5, 0xa
    rlwinm	r0, r4, 0, 5, 5
    lhz	r6, 0(r5)
    cmplwi	r0, 0
    rlwinm	r6, r6, 0, 0x1d, 0x16
    bne     _8000d6c0
    ori	r6, r6, 0x10
_8000d6c0:
    rlwinm	r0, r4, 0, 6, 6
    cmplwi	r0, 0
    bne     _8000d6d0
    ori	r6, r6, 0x40
_8000d6d0:
    rlwinm	r0, r4, 0, 7, 7
    cmplwi	r0, 0
    bne     _8000d6e0
    ori	r6, r6, 0x100
_8000d6e0:
    clrlwi	r0, r6, 0x10
    sth	r0, 0(r5)
    rlwinm	r3, r3, 0, 8, 4
    b       _8000d8b8
_8000d6f0:
    rlwinm	r0, r4, 0, 8, 8
    lis	r4, -0x3400
    cmplwi	r0, 0
    lwz	r5, 0x6c00(r4)
    li	r0, -0x2d
    and	r5, r5, r0
    bne     _8000d710
    ori	r5, r5, 4
_8000d710:
    lis	r4, -0x3400
    stw	r5, 0x6c00(r4)
    rlwinm	r3, r3, 0, 9, 7
    b       _8000d8b8
_8000d720:
    rlwinm	r0, r4, 0, 9, 9
    lis	r5, -0x3400
    cmplwi	r0, 0
    lwz	r5, 0x6800(r5)
    li	r0, -0x2c10
    and	r5, r5, r0
    bne     _8000d740
    ori	r5, r5, 1
_8000d740:
    rlwinm	r0, r4, 0, 0xa, 0xa
    cmplwi	r0, 0
    bne     _8000d750
    ori	r5, r5, 4
_8000d750:
    rlwinm	r0, r4, 0, 0xb, 0xb
    cmplwi	r0, 0
    bne     _8000d760
    ori	r5, r5, 0x400
_8000d760:
    lis	r4, -0x3400
    stw	r5, 0x6800(r4)
    rlwinm	r3, r3, 0, 0xc, 8
    b       _8000d8b8
_8000d770:
    lis	r5, -0x3400
    addi	r6, r5, 0x6800
    addi	r6, r6, 0x14
    rlwinm	r0, r4, 0, 0xc, 0xc
    lwz	r7, 0(r6)
    li	r5, -0xc10
    cmplwi	r0, 0
    and	r7, r7, r5
    bne     _8000d798
    ori	r7, r7, 1
_8000d798:
    rlwinm	r0, r4, 0, 0xd, 0xd
    cmplwi	r0, 0
    bne     _8000d7a8
    ori	r7, r7, 4
_8000d7a8:
    rlwinm	r0, r4, 0, 0xe, 0xe
    cmplwi	r0, 0
    bne     _8000d7b8
    ori	r7, r7, 0x400
_8000d7b8:
    stw	r7, 0(r6)
    rlwinm	r3, r3, 0, 0xf, 0xb
    b       _8000d8b8
_8000d7c4:
    lis	r5, -0x3400
    addi	r5, r5, 0x6800
    addi	r5, r5, 0x28
    rlwinm	r0, r4, 0, 0xf, 0xf
    lwz	r6, 0(r5)
    cmplwi	r0, 0
    rlwinm	r6, r6, 0, 0, 0x1b
    bne     _8000d7e8
    ori	r6, r6, 1
_8000d7e8:
    rlwinm	r0, r4, 0, 0x10, 0x10
    cmplwi	r0, 0
    bne     _8000d7f8
    ori	r6, r6, 4
_8000d7f8:
    stw	r6, 0(r5)
    rlwinm	r3, r3, 0, 0x11, 0xe
    b       _8000d8b8
_8000d804:
    rlwinm	r0, r4, 0, 0x11, 0x11
    cmplwi	r0, 0
    li	r5, 0xf0
    bne     _8000d818
    ori	r5, r5, 0x800
_8000d818:
    rlwinm	r0, r4, 0, 0x14, 0x14
    cmplwi	r0, 0
    bne     _8000d828
    ori	r5, r5, 8
_8000d828:
    rlwinm	r0, r4, 0, 0x15, 0x15
    cmplwi	r0, 0
    bne     _8000d838
    ori	r5, r5, 4
_8000d838:
    rlwinm	r0, r4, 0, 0x16, 0x16
    cmplwi	r0, 0
    bne     _8000d848
    ori	r5, r5, 2
_8000d848:
    rlwinm	r0, r4, 0, 0x17, 0x17
    cmplwi	r0, 0
    bne     _8000d858
    ori	r5, r5, 1
_8000d858:
    rlwinm	r0, r4, 0, 0x18, 0x18
    cmplwi	r0, 0
    bne     _8000d868
    ori	r5, r5, 0x100
_8000d868:
    rlwinm	r0, r4, 0, 0x19, 0x19
    cmplwi	r0, 0
    bne     _8000d878
    ori	r5, r5, 0x1000
_8000d878:
    rlwinm	r0, r4, 0, 0x12, 0x12
    cmplwi	r0, 0
    bne     _8000d888
    ori	r5, r5, 0x200
_8000d888:
    rlwinm	r0, r4, 0, 0x13, 0x13
    cmplwi	r0, 0
    bne     _8000d898
    ori	r5, r5, 0x400
_8000d898:
    rlwinm	r0, r4, 0, 0x1a, 0x1a
    cmplwi	r0, 0
    bne     _8000d8a8
    ori	r5, r5, 0x2000
_8000d8a8:
    lis	r4, -0x3400
    addi	r4, r4, 0x3000
    stw	r5, 4(r4)
    rlwinm	r3, r3, 0, 0x1b, 0x10
    entry   _8000d8b8
    blr	
}

asm u32 __OSMaskInterrupts(register u32 global)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    lis	r4, -0x8000
    lwz	r29, 0xc4(r4)
    mr	r30, r3
    lwz	r5, 0xc8(r4)
    or	r0, r29, r5
    andc	r3, r31, r0
    or	r31, r31, r29
    stw	r31, 0xc4(r4)
    or	r31, r31, r5
    b       _8000d904
    entry   _8000d904
    b       _8000d908
    entry   _8000d908
    b       _8000d914
_8000d90c:
    mr	r4, r31
    bl      SetInterruptMask
_8000d914:
    cmplwi	r3, 0
    bne     _8000d90c
    mr	r3, r30
    bl      OSRestoreInterrupts
    mr	r3, r29
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm u32 __OSUnmaskInterrupts(register u32 global)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x20(r1)
    stw	r31, 0x1c(r1)
    stw	r30, 0x18(r1)
    stw	r29, 0x14(r1)
    mr	r31, r3
    bl      OSDisableInterrupts
    lis	r4, -0x8000
    lwz	r29, 0xc4(r4)
    mr	r30, r3
    lwz	r5, 0xc8(r4)
    or	r0, r29, r5
    and	r3, r31, r0
    andc	r31, r29, r31
    stw	r31, 0xc4(r4)
    or	r31, r31, r5
    b       _8000d98c
    entry   _8000d98c
    b       _8000d990
    entry   _8000d990
    b       _8000d99c
_8000d994:
    mr	r4, r31
    bl      SetInterruptMask
_8000d99c:
    cmplwi	r3, 0
    bne     _8000d994
    mr	r3, r30
    bl      OSRestoreInterrupts
    mr	r3, r29
    lwz	r0, 0x24(r1)
    lwz	r31, 0x1c(r1)
    lwz	r30, 0x18(r1)
    lwz	r29, 0x14(r1)
    addi	r1, r1, 0x20
    mtlr	r0
    blr	
}

asm void __OSDispatchInterrupt(register int exception, register void* context)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    stw	r29, 0x1c(r1)
    mr	r30, r4
    lis	r3, -0x3400
    lwz	r31, 0x3000(r3)
    rlwinm	r31, r31, 0, 0x10, 0xe
    cmplwi	r31, 0
    beq     _8000da10
    addi	r3, r3, 0x3000
    lwz	r0, 4(r3)
    and	r0, r31, r0
    cmplwi	r0, 0
    bne     _8000da18
_8000da10:
    mr	r3, r30
    bl      OSLoadContext
_8000da18:
    rlwinm	r0, r31, 0, 0x18, 0x18
    cmplwi	r0, 0
    li	r0, 0
    beq     _8000da84
    lis	r3, -0x3400
    addi	r3, r3, 0x4000
    lhz	r4, 0x1e(r3)
    clrlwi	r3, r4, 0x1f
    cmplwi	r3, 0
    beq     _8000da44
    oris	r0, r0, 0x8000
_8000da44:
    rlwinm	r3, r4, 0, 0x1e, 0x1e
    cmplwi	r3, 0
    beq     _8000da54
    oris	r0, r0, 0x4000
_8000da54:
    rlwinm	r3, r4, 0, 0x1d, 0x1d
    cmplwi	r3, 0
    beq     _8000da64
    oris	r0, r0, 0x2000
_8000da64:
    rlwinm	r3, r4, 0, 0x1c, 0x1c
    cmplwi	r3, 0
    beq     _8000da74
    oris	r0, r0, 0x1000
_8000da74:
    rlwinm	r3, r4, 0, 0x1b, 0x1b
    cmplwi	r3, 0
    beq     _8000da84
    oris	r0, r0, 0x800
_8000da84:
    rlwinm	r3, r31, 0, 0x19, 0x19
    cmplwi	r3, 0
    beq     _8000dacc
    lis	r3, -0x3400
    addi	r3, r3, 0x5000
    lhz	r4, 0xa(r3)
    rlwinm	r3, r4, 0, 0x1c, 0x1c
    cmplwi	r3, 0
    beq     _8000daac
    oris	r0, r0, 0x400
_8000daac:
    rlwinm	r3, r4, 0, 0x1a, 0x1a
    cmplwi	r3, 0
    beq     _8000dabc
    oris	r0, r0, 0x200
_8000dabc:
    rlwinm	r3, r4, 0, 0x18, 0x18
    cmplwi	r3, 0
    beq     _8000dacc
    oris	r0, r0, 0x100
_8000dacc:
    rlwinm	r3, r31, 0, 0x1a, 0x1a
    cmplwi	r3, 0
    beq     _8000daf0
    lis	r3, -0x3400
    lwz	r3, 0x6c00(r3)
    rlwinm	r3, r3, 0, 0x1c, 0x1c
    cmplwi	r3, 0
    beq     _8000daf0
    oris	r0, r0, 0x80
_8000daf0:
    rlwinm	r3, r31, 0, 0x1b, 0x1b
    cmplwi	r3, 0
    beq     _8000db9c
    lis	r3, -0x3400
    lwz	r4, 0x6800(r3)
    rlwinm	r3, r4, 0, 0x1e, 0x1e
    cmplwi	r3, 0
    beq     _8000db14
    oris	r0, r0, 0x40
_8000db14:
    rlwinm	r3, r4, 0, 0x1c, 0x1c
    cmplwi	r3, 0
    beq     _8000db24
    oris	r0, r0, 0x20
_8000db24:
    rlwinm	r3, r4, 0, 0x14, 0x14
    cmplwi	r3, 0
    beq     _8000db34
    oris	r0, r0, 0x10
_8000db34:
    lis	r3, -0x3400
    addi	r3, r3, 0x6800
    lwz	r4, 0x14(r3)
    rlwinm	r3, r4, 0, 0x1e, 0x1e
    cmplwi	r3, 0
    beq     _8000db50
    oris	r0, r0, 8
_8000db50:
    rlwinm	r3, r4, 0, 0x1c, 0x1c
    cmplwi	r3, 0
    beq     _8000db60
    oris	r0, r0, 4
_8000db60:
    rlwinm	r3, r4, 0, 0x14, 0x14
    cmplwi	r3, 0
    beq     _8000db70
    oris	r0, r0, 2
_8000db70:
    lis	r3, -0x3400
    addi	r3, r3, 0x6800
    lwz	r4, 0x28(r3)
    rlwinm	r3, r4, 0, 0x1e, 0x1e
    cmplwi	r3, 0
    beq     _8000db8c
    oris	r0, r0, 1
_8000db8c:
    rlwinm	r3, r4, 0, 0x1c, 0x1c
    cmplwi	r3, 0
    beq     _8000db9c
    ori	r0, r0, 0x8000
_8000db9c:
    rlwinm	r3, r31, 0, 0x12, 0x12
    cmplwi	r3, 0
    beq     _8000dbac
    ori	r0, r0, 0x20
_8000dbac:
    rlwinm	r3, r31, 0, 0x13, 0x13
    cmplwi	r3, 0
    beq     _8000dbbc
    ori	r0, r0, 0x40
_8000dbbc:
    rlwinm	r3, r31, 0, 0x15, 0x15
    cmplwi	r3, 0
    beq     _8000dbcc
    ori	r0, r0, 0x1000
_8000dbcc:
    rlwinm	r3, r31, 0, 0x16, 0x16
    cmplwi	r3, 0
    beq     _8000dbdc
    ori	r0, r0, 0x2000
_8000dbdc:
    rlwinm	r3, r31, 0, 0x17, 0x17
    cmplwi	r3, 0
    beq     _8000dbec
    ori	r0, r0, 0x80
_8000dbec:
    rlwinm	r3, r31, 0, 0x1c, 0x1c
    cmplwi	r3, 0
    beq     _8000dbfc
    ori	r0, r0, 0x800
_8000dbfc:
    rlwinm	r3, r31, 0, 0x1d, 0x1d
    cmplwi	r3, 0
    beq     _8000dc0c
    ori	r0, r0, 0x400
_8000dc0c:
    rlwinm	r3, r31, 0, 0x1e, 0x1e
    cmplwi	r3, 0
    beq     _8000dc1c
    ori	r0, r0, 0x200
_8000dc1c:
    rlwinm	r3, r31, 0, 0x14, 0x14
    cmplwi	r3, 0
    beq     _8000dc2c
    ori	r0, r0, 0x4000
_8000dc2c:
    clrlwi	r3, r31, 0x1f
    cmplwi	r3, 0
    beq     _8000dc3c
    ori	r0, r0, 0x100
_8000dc3c:
    lis	r3, -0x8000
    lwz	r4, 0xc4(r3)
    lwz	r3, 0xc8(r3)
    or	r3, r4, r3
    andc	r4, r0, r3
    cmplwi	r4, 0
    beq     _8000dcec
    lis	r3, -0x7fee
    addi	r0, r3, 0x3a60
    mr	r3, r0
    b       _8000dc68
    entry   _8000dc68
    b       _8000dc6c
    entry   _8000dc6c
    lwz	r0, 0(r3)
    and	r0, r4, r0
    cmplwi	r0, 0
    beq     _8000dc88
    cntlzw	r0, r0
    extsh	r29, r0
    b       _8000dc90
_8000dc88:
    addi	r3, r3, 4
    b       _8000dc6c
_8000dc90:
    lwz	r3, -0x7c18(r13)
    slwi	r0, r29, 2
    lwzx	r31, r3, r0
    cmplwi	r31, 0
    beq     _8000dcec
    cmpwi	r29, 4
    ble     _8000dcc4
    sth	r29, -0x7c10(r13)
    bl      OSGetTime
    stw	r4, -0x7c04(r13)
    stw	r3, -0x7c08(r13)
    lwz	r0, 0x198(r30)
    stw	r0, -0x7c14(r13)
_8000dcc4:
    bl      OSDisableScheduler
    mr	r3, r29
    mr	r4, r30
    mr	r12, r31
    mtlr	r12
    blrl	
    bl      OSEnableScheduler
    bl      __OSReschedule
    mr	r3, r30
    bl      OSLoadContext
_8000dcec:
    mr	r3, r30
    bl      OSLoadContext
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm void ExternalInterruptHandler(register int exception, register void* context)
{
    nofralloc
    stw	r0, 0(r4)
    stw	r1, 4(r4)
    stw	r2, 8(r4)
    stmw	r6, 0x18(r4)
    mfspr	r0, 0x391
    stw	r0, 0x1a8(r4)
    mfspr	r0, 0x392
    stw	r0, 0x1ac(r4)
    mfspr	r0, 0x393
    stw	r0, 0x1b0(r4)
    mfspr	r0, 0x394
    stw	r0, 0x1b4(r4)
    mfspr	r0, 0x395
    stw	r0, 0x1b8(r4)
    mfspr	r0, 0x396
    stw	r0, 0x1bc(r4)
    mfspr	r0, 0x397
    stw	r0, 0x1c0(r4)
    stwu	r1, -8(r1)
    b       __OSDispatchInterrupt
}

#pragma pop
