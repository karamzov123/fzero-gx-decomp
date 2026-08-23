typedef int BOOL;
typedef signed char s8;
typedef short s16;
typedef long long s64;
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
#pragma push
#pragma force_active on

extern BOOL OSDisableInterrupts(void);
extern u64 __OSGetSystemTime(void);
extern void __OSMaskInterrupts(u32 mask);
extern void OSRestoreInterrupts(BOOL enabled);
extern s64 __div2i(s64 a, s64 b);

asm void __OSResetSWInterruptHandler(register int exception, register void* context)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x28(r1)
    stw	r31, 0x24(r1)
    stw	r30, 0x20(r1)
    stw	r29, 0x1c(r1)
    bl      __OSGetSystemTime
    lis	r5, -0x8000
    stw	r4, -0x7bcc(r13)
    lwz	r0, 0xf8(r5)
    lis	r4, 0x431c
    addi	r4, r4, -0x217d
    stw	r3, -0x7bd0(r13)
    srwi	r0, r0, 2
    mulhwu	r0, r4, r0
    srwi	r0, r0, 0xf
    mulli	r0, r0, 0x64
    srwi	r29, r0, 3
    li	r30, 0
    lis	r31, -0x3400
_8000f2b4:
    bl      __OSGetSystemTime
    lwz	r6, -0x7bcc(r13)
    xoris	r5, r30, 0x8000
    lwz	r0, -0x7bd0(r13)
    subfc	r4, r6, r4
    subfe	r0, r0, r3
    xoris	r3, r0, 0x8000
    subfc	r0, r29, r4
    subfe	r5, r5, r3
    subfe	r5, r3, r3
    neg.	r5, r5
    beq     _8000f2f0
    lwz	r0, 0x3000(r31)
    rlwinm.	r0, r0, 0, 0xf, 0xf
    beq     _8000f2b4
_8000f2f0:
    lis	r3, -0x3400
    lwz	r0, 0x3000(r3)
    rlwinm.	r0, r0, 0, 0xf, 0xf
    bne     _8000f330
    li	r0, 1
    stw	r0, -0x7be4(r13)
    li	r3, 0x200
    stw	r0, -0x7be0(r13)
    bl      __OSMaskInterrupts
    lwz	r12, -0x7be8(r13)
    cmplwi	r12, 0
    beq     _8000f330
    li	r0, 0
    mtlr	r12
    stw	r0, -0x7be8(r13)
    blrl	
_8000f330:
    li	r0, 2
    lis	r3, -0x3400
    stw	r0, 0x3000(r3)
    lwz	r0, 0x2c(r1)
    lwz	r31, 0x24(r1)
    lwz	r30, 0x20(r1)
    lwz	r29, 0x1c(r1)
    addi	r1, r1, 0x28
    mtlr	r0
    blr	
}

asm BOOL OSGetResetButtonState(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -0x18(r1)
    stw	r31, 0x14(r1)
    stw	r30, 0x10(r1)
    stw	r29, 0xc(r1)
    bl      OSDisableInterrupts
    mr	r30, r3
    bl      __OSGetSystemTime
    lis	r5, -0x3400
    lwz	r0, 0x3000(r5)
    rlwinm.	r0, r0, 0, 0xf, 0xf
    bne     _8000f464
    lwz	r0, -0x7be4(r13)
    cmpwi	r0, 0
    bne     _8000f3d4
    lwz	r0, -0x7bd8(r13)
    li	r6, 0
    lwz	r5, -0x7bd4(r13)
    li	r7, 1
    xor	r0, r0, r6
    xor	r5, r5, r6
    stw	r7, -0x7be4(r13)
    or.	r0, r5, r0
    beq     _8000f3c0
    b       _8000f3c4
_8000f3c0:
    mr	r7, r6
_8000f3c4:
    stw	r4, -0x7bcc(r13)
    mr	r29, r7
    stw	r3, -0x7bd0(r13)
    b       _8000f518
_8000f3d4:
    lwz	r0, -0x7bd8(r13)
    li	r9, 0
    lwz	r5, -0x7bd4(r13)
    li	r10, 1
    xor	r0, r0, r9
    xor	r5, r5, r9
    or.	r0, r5, r0
    bne     _8000f448
    lis	r6, -0x8000
    lwz	r5, -0x7bcc(r13)
    lwz	r7, 0xf8(r6)
    lis	r6, 0x431c
    addi	r8, r6, -0x217d
    lwz	r0, -0x7bd0(r13)
    srwi	r6, r7, 2
    mulhwu	r6, r8, r6
    srwi	r6, r6, 0xf
    mulli	r6, r6, 0x64
    subfc	r7, r5, r4
    subfe	r0, r0, r3
    srwi	r8, r6, 3
    xoris	r5, r0, 0x8000
    xoris	r6, r9, 0x8000
    subfc	r0, r7, r8
    subfe	r5, r5, r6
    subfe	r5, r6, r6
    neg.	r5, r5
    bne     _8000f448
    mr	r10, r9
_8000f448:
    cmpwi	r10, 0
    beq     _8000f458
    li	r0, 1
    b       _8000f45c
_8000f458:
    li	r0, 0
_8000f45c:
    mr	r29, r0
    b       _8000f518
_8000f464:
    lwz	r0, -0x7be4(r13)
    cmpwi	r0, 0
    beq     _8000f4a0
    lwz	r5, -0x7be0(r13)
    li	r0, 0
    stw	r0, -0x7be4(r13)
    cmpwi	r5, 0
    addi	r29, r5, 0
    beq     _8000f494
    stw	r4, -0x7bd4(r13)
    stw	r3, -0x7bd8(r13)
    b       _8000f518
_8000f494:
    stw	r0, -0x7bd4(r13)
    stw	r0, -0x7bd8(r13)
    b       _8000f518
_8000f4a0:
    lwz	r6, -0x7bd8(r13)
    li	r8, 0
    lwz	r7, -0x7bd4(r13)
    xor	r0, r6, r8
    xor	r5, r7, r8
    or.	r0, r5, r0
    beq     _8000f508
    lis	r5, -0x8000
    lwz	r0, 0xf8(r5)
    lis	r5, 0x1062
    addi	r5, r5, 0x4dd3
    srwi	r0, r0, 2
    mulhwu	r0, r5, r0
    srwi	r0, r0, 6
    mulli	r0, r0, 0x28
    subfc	r7, r7, r4
    subfe	r5, r6, r3
    xoris	r6, r5, 0x8000
    xoris	r5, r8, 0x8000
    subfc	r0, r0, r7
    subfe	r5, r5, r6
    subfe	r5, r6, r6
    neg.	r5, r5
    beq     _8000f508
    li	r29, 1
    b       _8000f518
_8000f508:
    li	r0, 0
    stw	r0, -0x7bd4(r13)
    li	r29, 0
    stw	r0, -0x7bd8(r13)
_8000f518:
    lis	r5, -0x8000
    stw	r29, -0x7be0(r13)
    lbz	r0, 0x30e3(r5)
    clrlwi.	r0, r0, 0x1a
    beq     _8000f5c8
    mulli	r10, r0, 0x3c
    lwz	r0, 0xf8(r5)
    lwz	r9, -0x7c3c(r13)
    lwz	r8, -0x7c40(r13)
    srwi	r6, r0, 2
    srawi	r0, r10, 0x1f
    mullw	r7, r0, r6
    mulhwu	r0, r10, r6
    mullw	r5, r10, r6
    addc	r9, r9, r5
    li	r31, 0
    add	r7, r7, r0
    mullw	r0, r10, r31
    add	r0, r7, r0
    adde	r8, r8, r0
    xoris	r7, r8, 0x8000
    xoris	r5, r3, 0x8000
    subfc	r0, r4, r9
    subfe	r5, r5, r7
    subfe	r5, r7, r7
    neg.	r5, r5
    beq     _8000f5c8
    subfc	r4, r9, r4
    subfe	r3, r8, r3
    li	r5, 0
    bl      __div2i
    li	r5, 0
    li	r6, 2
    bl      __div2i
    li	r0, 1
    and	r4, r4, r0
    and	r0, r3, r31
    xor	r3, r4, r31
    xor	r0, r0, r31
    or.	r0, r3, r0
    bne     _8000f5c4
    li	r29, 1
    b       _8000f5c8
_8000f5c4:
    li	r29, 0
_8000f5c8:
    mr	r3, r30
    bl      OSRestoreInterrupts
    mr	r3, r29
    lwz	r0, 0x1c(r1)
    lwz	r31, 0x14(r1)
    lwz	r30, 0x10(r1)
    lwz	r29, 0xc(r1)
    addi	r1, r1, 0x18
    mtlr	r0
    blr	
}

asm BOOL OSGetResetSwitchState(void)
{
    nofralloc
    mflr	r0
    stw	r0, 4(r1)
    stwu	r1, -8(r1)
    bl      OSGetResetButtonState
    lwz	r0, 0xc(r1)
    addi	r1, r1, 8
    mtlr	r0
    blr	
}

#pragma pop
